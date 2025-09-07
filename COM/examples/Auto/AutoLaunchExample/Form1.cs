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
// Navisworks API - AutoLaunchExample
// This is a simple example showing how to launch Navisworks and
// perform some basic functions
//------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using Microsoft.Win32;

namespace AutoLaunchExample
{
   public partial class Form1 : Form
   {
      private NavisworksIntegratedAPI21.InwOpState10 m_state;
      private NavisworksAutomationAPI21.Document m_doc;

      public Form1()
      {
         InitializeComponent();
      }

      private void LaunchButton_Click(object sender, EventArgs e)
      {
         // Create a new Navisworks Document, this will launch Navisworks
         m_doc = new NavisworksAutomationAPI21.Document();
         // Read the state from the new Navisworks Document
         m_state = m_doc.State();
         // Tell Navisworks to be visible
         m_doc.Visible = true;
         // Get the product info from the state.
         ProductInfoLabel.Text = "Product = " + m_state.GetProductInfo();
         // If check box ticked tell Navisworks to stay open when API application is closed
         if (leaveCBox.Checked) m_doc.StayOpen();

         // Navisworks has started so we can enable the open file button
         OpenFileButton.Enabled = true;

      }

      private void OpenFileButton_Click(object sender, EventArgs e)
      {
         OpenFileDialog fileDialog = new OpenFileDialog();
         fileDialog.Filter = "NWD files|*.nwd";
         fileDialog.Title = "Open Navisworks Document";
         DialogResult result = fileDialog.ShowDialog();
         if (result == DialogResult.OK)
         {
            string filename = fileDialog.FileName;
            m_doc.OpenFile(filename);

            // Check to see that the file was loaded
            if (m_state.LoadedFileCount > 0)
            {
               // If we have any saved views then enable the show a saved view button
               if (m_state.SavedViews().Count > 0)
                  ShowASavedViewButton.Enabled = true;
               // Enable other model related buttons.
               ViewAllButton.Enabled = true;
               TurntableNavigationButton.Enabled = true;
            }
         }
      }

      private void ViewAllButton_Click(object sender, EventArgs e)
      {
         // Call the command to view the whole model
         m_state.ViewAll();
      }

      private void ShowASavedViewButton_Click(object sender, EventArgs e)
      {
         NavisworksIntegratedAPI21.InwSavedViewsColl savedViews = m_state.SavedViews();
         // Apply one of the saved views as the current viewpoint
         if (savedViews.Count > 0)
            m_state.ApplyView(savedViews[1]);
      }

      private void TurntableNavigationButton_Click(object sender, EventArgs e)
      {
         // Switch the navigation mode paradigm to turntable
         m_state.CurrentView.ViewPoint.Paradigm = NavisworksIntegratedAPI21.nwEParadigm.eParadigm_TURNTABLE;
      }
   }
}
