//------------------------------------------------------------------
// Navisworks Sample code
//------------------------------------------------------------------
//
// (C) Copyright 2011 by Autodesk Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted,
// provided that the above copyright notice appears in all copies and
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS.
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//------------------------------------------------------------------
// Navisworks API - Example that outputs the text about the contents 
// of the loaded model into a list model
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using NavisworksIntegratedAPI21;


namespace ActiveXDumpStructureExample
{

   public partial class Form1 : Form
   {
      private NavisworksIntegratedAPI21.nwOpState m_state;
      private NavisworksIntegratedAPI21.nwControlMDI nwsControl;

      public Form1()
      {
         InitializeComponent();
      }

      private void Form1_Load(object sender, EventArgs e)
      {
         // Dynamically create the activex control.
         AxControl host = new AxControl(typeof(NavisworksIntegratedAPI21.nwControlMDIClass).GUID.ToString());
         groupBox1.Controls.Add(host);
         groupBox1.Controls.SetChildIndex(host,groupBox1.Controls.GetChildIndex(nwsPlaceholder));
         host.Location = nwsPlaceholder.Location;
         host.Size = nwsPlaceholder.Size;
         nwsControl = (NavisworksIntegratedAPI21.nwControlMDI)host.GetOcx();
         
         // hook up state.
         m_state = (NavisworksIntegratedAPI21.nwOpState) nwsControl.APIState;
         m_state.EventsEnabled = true;
      }

      private void openFileButton_Click(object sender, EventArgs e)
      {
         OpenFileDialog fileDialog = new OpenFileDialog();
         fileDialog.Filter = "NWD files|*.nwd";
         fileDialog.Title = "Open Navisworks Document";
         DialogResult result = fileDialog.ShowDialog();
         if (result == DialogResult.OK)
         {
            // Open file into activeX control
            string filename = fileDialog.FileName;
            nwsControl.SRC = filename;
            nwsControl.APIState.CurrentView.ViewPoint.Paradigm = nwEParadigm.eParadigm_APPLICATION;
            structureTreeView.Nodes.Clear();
         }
      }
      private void dumpAttribute(InwOaAttribute attrib, ref TreeNode geomNode)
      {
         // output the node
         TreeNode attrNode = new TreeNode(String.Format("Attribute CN={0} CUN={1} UN={2}", attrib.ClassName, attrib.ClassUserName, attrib.UserName));
         geomNode.Nodes.Add(attrNode);
         if (m_state.GetAttributeProperties(attrib).Properties().Count > 0)
         {
            foreach (InwOaProperty prop in m_state.GetAttributeProperties(attrib).Properties())
            {
               try 
               {
                  attrNode.Nodes.Add(String.Format("Property name={0} username={1} value={2}", prop.name, prop.UserName, prop.value));
               }
               catch (System.Runtime.InteropServices.COMException)
               { ; }
            }
         }
      }
      private void walkNode(InwOaNode node, bool bFoundFirst=false)
      {
         TreeNode geomNode = new TreeNode(String.Format("Node [{0}] CN = {1} CUN = {2} UN = {3}", node.ObjectName, node.ClassName, node.ClassUserName, node.UserName));
         structureTreeView.Nodes.Add(geomNode);
         geomNode.EnsureVisible();
         structureTreeView.Refresh();
         // Dump all the node's attributes' name/value pairs
         foreach (InwOaAttribute attrib in node.Attributes())
         {
            dumpAttribute(attrib, ref geomNode);
         }
         // If this is a group node then recurse into the structure
         if (node.IsGroup)
         {
            bool bThis = false;
            int count = 0;
            InwOaGroup group = node as InwOaGroup;
            foreach (InwOaNode newNode in group.Children())
            {
               if ((!bFoundFirst) && (group.Children().Count > 1))
               {
                  bThis = true;
                  bFoundFirst = true;
               }
               if (bThis == true)
               {
                  count++;
                  float childCount = (float)(group.Children().Count);
                  progressBar1.Value = (int)((((float)count / childCount)) * 100.0);
                  progressBar1.Refresh();
               }
               walkNode(newNode, bFoundFirst);
            }
         }
      }
      private void dumpFileButton_Click(object sender, EventArgs e)
      {
         progressBar1.Minimum = 0;
         progressBar1.Maximum = 100;
         progressBar1.Value = 0;

         structureTreeView.Nodes.Clear();

         walkNode(m_state.CurrentPartition);

      }
      private void generatePrims_Click(object sender, EventArgs e)
      {
         treeView1.Nodes.Clear();

         treeView1.Nodes.Add("Line");
         treeView1.Nodes.Add("Point");
         treeView1.Nodes.Add("SnapPoint");
         treeView1.Nodes.Add("Triangle");

         CallbackGeomListener callbkListener = new CallbackGeomListener();
         callbkListener.getParentNodes(treeView1);

         foreach (InwOaPath3 path in m_state.CurrentSelection.Paths())
         {
            foreach (InwOaFragment3 frag in path.Fragments())
            {
               frag.GenerateSimplePrimitives(nwEVertexProperty.eNORMAL, callbkListener);
            }
         }
      }


      class CallbackGeomListener : InwSimplePrimitivesCB
      {
         private TreeView oTreeView;
         string ostr;
         List<TreeNode> oParentNodes;

         Array arrayFloat_1;
         Array arrayFloat_2;
         Array arrayFloat_3;
         public CallbackGeomListener()
         {
            int[] myLengthsArray = new int[1] { 3 };
            int[] myBoundsArray = new int[1] { 1 };
            arrayFloat_1 = Array.CreateInstance(typeof(float), myLengthsArray, myBoundsArray);
            arrayFloat_2 = Array.CreateInstance(typeof(float), myLengthsArray, myBoundsArray);
            arrayFloat_3 = Array.CreateInstance(typeof(float), myLengthsArray, myBoundsArray);
         }

         public void getParentNodes(TreeView oView)
         {
            oTreeView = oView;
            oParentNodes = new List<TreeNode>();
            oParentNodes.Add(oTreeView.Nodes[0]);
            oParentNodes.Add(oTreeView.Nodes[1]);
            oParentNodes.Add(oTreeView.Nodes[2]);
            oParentNodes.Add(oTreeView.Nodes[3]);
         }

         #region InwSimplePrimitivesCB Members

         public void Line(InwSimpleVertex v1, InwSimpleVertex v2)
         {
            arrayFloat_1 = (Array)(object)v1.coord;
            arrayFloat_2 = (Array)(object)v2.coord;


            ostr = string.Format(" <{0},{1},{2}]] , [{3},{4},{5} >",
                         arrayFloat_1.GetValue(1), arrayFloat_1.GetValue(2), arrayFloat_1.GetValue(2),
                         arrayFloat_2.GetValue(1), arrayFloat_2.GetValue(2), arrayFloat_2.GetValue(2));

            oParentNodes[0].Nodes.Add(ostr);

         }

         public void Point(InwSimpleVertex v1)
         {
            arrayFloat_1 = (Array)(object)v1.coord;


            ostr = string.Format(" [{0},{1},{2}]]",
                         arrayFloat_1.GetValue(1), arrayFloat_1.GetValue(2), arrayFloat_1.GetValue(2)
                         );

            oParentNodes[1].Nodes.Add(ostr);
         }

         public void SnapPoint(InwSimpleVertex v1)
         {
            arrayFloat_1 = (Array)(object)v1.coord;


            ostr = string.Format(" [{0},{1},{2}]]",
                         arrayFloat_1.GetValue(1), arrayFloat_1.GetValue(2), arrayFloat_1.GetValue(2)
                         );

            oParentNodes[2].Nodes.Add(ostr);
         }

         public void Triangle(InwSimpleVertex v1, InwSimpleVertex v2, InwSimpleVertex v3)
         {
            arrayFloat_1 = (Array)(object)v1.coord;
            arrayFloat_2 = (Array)(object)v2.coord;
            arrayFloat_3 = (Array)(object)v3.coord;

            ostr = string.Format(" < [{0},{1},{2}]  ,[{3},{4},{5}],[{6},{7},{8}]  >",
                         arrayFloat_1.GetValue(1), arrayFloat_1.GetValue(2), arrayFloat_1.GetValue(2),
                         arrayFloat_2.GetValue(1), arrayFloat_2.GetValue(2), arrayFloat_2.GetValue(2),
                         arrayFloat_3.GetValue(1), arrayFloat_3.GetValue(2), arrayFloat_3.GetValue(2));

            oParentNodes[3].Nodes.Add(ostr);
         }


         #endregion
      }
   }

   public class AxControl : AxHost
   {
      public AxControl(string strCLSID)
         : base(strCLSID)
      {
      }
   }

}
