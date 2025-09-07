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
// Navisworks API : Example of using API automation drive IO Plugins
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace AutoDriveExample
{
   public partial class Form1 : Form
   {
      private NavisworksIntegratedAPI21.InwOpState10 m_state;
      private NavisworksAutomationAPI21.Document m_doc;

      public Form1()
      {
         InitializeComponent();
      }
      private void SetTextFromPropertyVec(ref NavisworksIntegratedAPI21.InwOaPropertyVec options)
      {
         listBox.Items.Clear();
          foreach (NavisworksIntegratedAPI21.InwOaProperty opt in options.Properties())
          {
               listBox.Items.Add(String.Format("{0}={1}", opt.name, opt.value));
          }
      }
      private void ExportBitmapButton_Click(object sender, EventArgs e)
      {
         //
         // Get the current options for the image export plugin.
         //
         NavisworksIntegratedAPI21.InwOaPropertyVec options = m_state.GetIOPluginOptions("lcodpimage");
         //
         // Update the text box.
         //
         SetTextFromPropertyVec(ref options);
         //
         // Look for the image format option, and set it to the Windows Bitmap
         // file format plugin.
         //
         foreach (NavisworksIntegratedAPI21.InwOaProperty opt in options.Properties())
         {
            if (opt.name == "export.image.format")
               opt.value = "lcodpodvbmp";
         }

         //
         //While we're here lets demonstate how to tweak some format specific options to some arbitary values.
         //As we're doing a bitmap export this don't actually effect the output.
         //
         foreach (NavisworksIntegratedAPI21.InwOaProperty opt in options.Properties())
         {
            if (opt.name == "export.image.jpg.smoothing")
               opt.value = 101;
            else if (opt.name == "export.image.jpg.compression")
               opt.value = 102;
            else if (opt.name == "export.image.png.interlaced")
               opt.value = true;
            else if (opt.name == "export.image.png.compression")
               opt.value = 103;
         }
         //
         // Execute the image export plugin with the modified options, outputting
         // the image to a file called "picture.bmp".
         //
         m_state.DriveIOPlugin("lcodpimage", "C:\\temp\\picture.bmp", options);
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
   }
}
