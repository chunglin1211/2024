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
// Navisworks API : A demonstration of automating the process of 
// running pre-defined clash tests in a model and generating a 
// report of the results
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AutoClashExample
{
   public partial class Form1 : Form
   {
      private NavisworksIntegratedAPI21.InwOpState10 m_state;
      private NavisworksAutomationAPI21.Document m_doc;
      private NavisworksIntegratedAPI21.InwOpClashElement m_clash;

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
         foreach (dynamic d_plugin in m_state.Plugins())
         {
            m_clash = d_plugin as NavisworksIntegratedAPI21.InwOpClashElement;
            if (m_clash != null)
               break;
         }
         if (m_clash == null)
            throw new System.NullReferenceException("Clash Detective not found");
      }

      private void clashButton_Click(object sender, EventArgs e)
      {
         if (m_clash == null)
            return;

         // Run all stored clash tests
         m_clash.RunAllTests();

         // Output results to listbox
         foreach (NavisworksIntegratedAPI21.InwOclClashTest clashTest in m_clash.Tests())
         {
            clashListBox.Items.Add(String.Format("CLASH TEST - {0}", clashTest.name));
            clashListBox.Items.Add(String.Format("New Results: {0}", clashTest.NumNewResults));
            foreach (NavisworksIntegratedAPI21.InwOclTestResult clashResult in clashTest.results())
            {
               clashListBox.Items.Add(String.Format("- Result [{0}] Status [{1}]", clashResult.name, clashResult.status)); 
            }
         }
          // NOTE: Not demonstrated here but the clash result object (InwOclTestResult) can
          // also be used to create viewpoints and images of individual clashes
      }
   }
}
