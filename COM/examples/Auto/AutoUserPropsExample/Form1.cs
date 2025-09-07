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
// Navisworks API 
// This example demonstrates manipulation  of user defined fields
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AutoUserPropsExample
{
   public partial class Form1 : Form
   {
      private NavisworksIntegratedAPI21.InwOpState10 m_state;
      private NavisworksAutomationAPI21.Document m_doc;

      public Form1()
      {
         InitializeComponent();
      }

      private void launchButton_Click(object sender, EventArgs e)
      {
         // Create a new Navisworks Document, this will launch Navisworks
         m_doc = new NavisworksAutomationAPI21.Document();
         // Read the state from the new Navisworks Document
         m_state = m_doc.State();
         // Tell Navisworks to be visible
         m_doc.Visible = true;
      }

      private void openFileButton_Click(object sender, EventArgs e)
      {
         OpenFileDialog fileDialog = new OpenFileDialog();
         fileDialog.Filter = "NWD files|*.nwd";
         fileDialog.Title = "Open Navisworks Document";
         DialogResult result = fileDialog.ShowDialog();
         if (result == DialogResult.OK)
         {
            string filename = fileDialog.FileName;
            m_doc.OpenFile(filename);
         }
      }

      private void DumpCurrentButton_Click(object sender, EventArgs e)
      {
         PropertyListBox.Items.Clear();
         NavisworksIntegratedAPI21.InwOpSelection2 sel = m_state.CurrentSelection as NavisworksIntegratedAPI21.InwOpSelection2;
         if (sel.Paths().Count >0)
         {
            NavisworksIntegratedAPI21.InwGUIPropertyNode2 propn = m_state.GetGUIPropertyNode(sel.Paths()[1], true) as NavisworksIntegratedAPI21.InwGUIPropertyNode2;
            foreach (NavisworksIntegratedAPI21.InwGUIAttribute2 guiattrib in propn.GUIAttributes())
            {
               PropertyListBox.Items.Add(".........................................");
               PropertyListBox.Items.Add(String.Format("ClassName={0} ClassUserName={1} UserDefined={2}", guiattrib.ClassName, guiattrib.ClassUserName, guiattrib.UserDefined));
               foreach (NavisworksIntegratedAPI21.InwOaProperty prop in guiattrib.Properties())
               {
                  PropertyListBox.Items.Add(String.Format("\t {0}:{1} = {2}", prop.UserName, prop.name, prop.value));
               }
            }
         }
      }

      private void AddUserDefined(int ndx, string userx, string internalx, string sx)
      {
         NavisworksIntegratedAPI21.InwOpSelection2 sel = m_state.CurrentSelection as NavisworksIntegratedAPI21.InwOpSelection2;
         if (sel.Paths().Count > 0)
         {
            NavisworksIntegratedAPI21.InwGUIPropertyNode2 propn = m_state.GetGUIPropertyNode(sel.Paths()[1], true) as NavisworksIntegratedAPI21.InwGUIPropertyNode2;
            NavisworksIntegratedAPI21.InwOaPropertyVec propvec = m_state.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOaPropertyVec);
            NavisworksIntegratedAPI21.InwOaProperty prop1 = m_state.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOaProperty);
            NavisworksIntegratedAPI21.InwOaProperty prop2 = m_state.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOaProperty);
            prop1.name = "APIprop1";
            prop1.UserName = "APIprop1";
            prop1.value = sx;
            prop2.name = "APIprop2";
            prop2.UserName = "APIprop2";
            prop2.value = sx;
            propvec.Properties().Add(prop1);
            propvec.Properties().Add(prop2);
            propn.SetUserDefined(ndx, userx, internalx, propvec);
         }
      }
      private void AddUDPButton_Click(object sender, EventArgs e)
      {
         AddUserDefined(0, "U5", "I5", "new5");
      }

      private void EditUDPButton_Click(object sender, EventArgs e)
      {
         AddUserDefined(0, "U5", "I5", "modified5");
      }

      private void RemoveCurrentSelectionUDPButton_Click(object sender, EventArgs e)
      {
         NavisworksIntegratedAPI21.InwOpSelection2 sel = m_state.CurrentSelection as NavisworksIntegratedAPI21.InwOpSelection2;
         if (sel.Paths().Count > 0)
         {
            NavisworksIntegratedAPI21.InwGUIPropertyNode2 propn = m_state.GetGUIPropertyNode(sel.Paths()[1], true) as NavisworksIntegratedAPI21.InwGUIPropertyNode2;
            propn.RemoveUserDefined(0);
         }
      }

      private void AddUDPToCurrentSelectionButton_Click(object sender, EventArgs e)
      {
         AddUserDefined(0, "U1", "I1", "new1");
         AddUserDefined(0, "U2", "I2", "new2");
         AddUserDefined(0, "U3", "I3", "new3");
         AddUserDefined(0, "U4", "I4", "new4");
      }
   }
}
