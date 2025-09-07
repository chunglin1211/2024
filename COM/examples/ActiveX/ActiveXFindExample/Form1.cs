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
// Navisworks API  - Example usage of the complex but powerful find 
// tool
//------------------------------------------------------------------
//------------------------------------------------------------------
//Overview
//------------------------------------------------------------------
//The find code allows fast complex search though the model node structure,
//including the attributes (and their properties) attached to the these nodes
//
//A Node's properties and attached attributes properties are all displayed as
//a PROPERTY=VALUE format.
//e.g. "door"="left side door"
//Internaly PROPERTY is actualy represented a more specific non localised internal name.
//e.g "LcUnkownReaderTypeDoor"="left side door"

//Note: The internal names are specific to the particular file exporter / reader.
//Thus we could search for "door"="XXX" but we would be normaly be better searching
//for "LcUnkownReaderTypeDoor"="XXX" as this would work in different locales.
//
//------------------------------------------------------------------
// SetAttributeNames(internal_name,[optional] user_name)
//------------------------------------------------------------------
//Defines which attribute we are looking for on a node
//(normaly just specify internal name)
//If we call SetAttributeNames "" then we are stating that SetPropertyNames refers
//to the properties on the actual node.
//
//------------------------------------------------------------------
//SetPropertyNames(internal_name,[optional] user_name)
//------------------------------------------------------------------
//Defines which property (within the above attribute) we are looking for
//(normaly just specify internal name)
//
//------------------------------------------------------------------
//Predefined enumerated internal names
//------------------------------------------------------------------
//These can be used to search for fixed internal properties that are
//not file exporter / reader specific.
//
//eSTANDARD_USER_NAME
//eSTANDARD_CLASS_USER_NAME
//eSTANDARD_CLASS_NAME
//eSTANDARD_CLASS_NODE
//eSTANDARD_CLASS_MATERIAL
//eSTANDARD_CLASS_TRANSFORM
//eSTANDARD_CLASS_URL
//eSTANDARD_TEXT_TEXT
//eSTANDARD_PARTITION_FILENAME
//
//------------------------------------------------------------------
//Model structure
//------------------------------------------------------------------
//To successfuly use the find API you must know the internal names you are looking for.
//Note: The internal names are specific to the particular file exporter / reader.


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;

namespace ActiveXFindExample
{
   public partial class Form1 : Form
   {
      private NavisworksIntegratedAPI21.nwOpState m_state;
      private NavisworksIntegratedAPI21.nwControlMDI nwsControl;
      private Hashtable m_conditionTable;

      public Form1()
      {
         InitializeComponent();
         conditionTB.SelectedIndex = 1;
         m_conditionTable = new Hashtable();
         // Add the various find conditions to the query dropdown 
         m_conditionTable.Add(1, NavisworksIntegratedAPI21.nwEFindCondition.eFind_CONTAINS);
         m_conditionTable.Add(2, NavisworksIntegratedAPI21.nwEFindCondition.eFind_EQUAL);
         m_conditionTable.Add(3, NavisworksIntegratedAPI21.nwEFindCondition.eFind_FIND_NEVER);
         m_conditionTable.Add(4, NavisworksIntegratedAPI21.nwEFindCondition.eFind_GE);
         m_conditionTable.Add(5, NavisworksIntegratedAPI21.nwEFindCondition.eFind_GT);
         m_conditionTable.Add(6, NavisworksIntegratedAPI21.nwEFindCondition.eFind_HAS_ATTRIB);
         m_conditionTable.Add(7, NavisworksIntegratedAPI21.nwEFindCondition.eFind_HAS_NO_ATTRIB);
         m_conditionTable.Add(8, NavisworksIntegratedAPI21.nwEFindCondition.eFind_HAS_NO_PROP);
         m_conditionTable.Add(9, NavisworksIntegratedAPI21.nwEFindCondition.eFind_HAS_PROP);
         m_conditionTable.Add(10, NavisworksIntegratedAPI21.nwEFindCondition.eFind_LE);
         m_conditionTable.Add(11, NavisworksIntegratedAPI21.nwEFindCondition.eFind_LT);
         m_conditionTable.Add(12, NavisworksIntegratedAPI21.nwEFindCondition.eFind_NOT_EQUAL);
         m_conditionTable.Add(13, NavisworksIntegratedAPI21.nwEFindCondition.eFind_SAME_TYPE);
         m_conditionTable.Add(14, NavisworksIntegratedAPI21.nwEFindCondition.eFind_WILDCARD);
         m_conditionTable.Add(15, NavisworksIntegratedAPI21.nwEFindCondition.eFind_WITHIN_DAY);
         m_conditionTable.Add(16, NavisworksIntegratedAPI21.nwEFindCondition.eFind_WITHIN_WEEK);
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
            string filename = fileDialog.FileName;
            nwsControl.SRC = filename;
            nwsControl.APIState.CurrentView.ViewPoint.Paradigm = NavisworksIntegratedAPI21.nwEParadigm.eParadigm_APPLICATION;
         }
      }

      private void findButton_Click(object sender, EventArgs e)
      {
         resultsListBox.Items.Clear();
         // Create the various components of the search using object factories
         NavisworksIntegratedAPI21.InwOpFind find = m_state.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOpFind) as NavisworksIntegratedAPI21.InwOpFind;
         NavisworksIntegratedAPI21.InwOpFindSpec findSpec = m_state.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOpFindSpec) as NavisworksIntegratedAPI21.InwOpFindSpec;
         NavisworksIntegratedAPI21.InwOpFindCondition findCondition = m_state.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOpFindCondition) as NavisworksIntegratedAPI21.InwOpFindCondition;

         findCondition.Condition = (NavisworksIntegratedAPI21.nwEFindCondition)m_conditionTable[conditionTB.SelectedIndex+1];
         findCondition.SetAttributeNames(attibuteTB.Text);
         findCondition.SetPropertyNames((propertyTB.Text.Equals("") ? m_state.StdName(NavisworksIntegratedAPI21.nwEStdName.eStdName_CLASS_USER_NAME, false) : propertyTB.Text ));
         findCondition.value = valueTB.Text;
         findSpec.selection = null;
         findSpec.Conditions().Add(findCondition);
         find.FindSpec = findSpec;
         bool bFirst=true;
         object match_data = Type.Missing;
         bool finished = false;
         // Populate the results table with the found items.
         do 
         {
            NavisworksIntegratedAPI21.InwOaPath path =  find.Find(bFirst, ref match_data);
            bFirst = false;
            if (path != null)
            {
               NavisworksIntegratedAPI21.InwOaNode node = path.Nodes().Last() as NavisworksIntegratedAPI21.InwOaNode;
               resultsListBox.Items.Add(String.Format("Matching node {0} = {1} = {2}", node.ClassName, node.ClassUserName, node.ObjectName));
            }
            else
               finished = true;
         }while(finished != true);
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
