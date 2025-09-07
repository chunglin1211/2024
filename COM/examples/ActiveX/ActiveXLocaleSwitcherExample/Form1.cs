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
// Navisworks API - Local Switcher
// Simple example of how to manually switch the ActiveX GUI language
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ActiveXLocaleSwitcherExample
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
      private void englishButton_Click(object sender, EventArgs e)
      {
         nwsControl.LocalisationCode = (nwsControl.LocalisationCode == "eng") ? "" : "eng"; 
      }

      private void germanButton_Click(object sender, EventArgs e)
      {
         nwsControl.LocalisationCode = (nwsControl.LocalisationCode == "deu") ? "" : "deu"; 
      }

      private void japaneseButton_Click(object sender, EventArgs e)
      {
         nwsControl.LocalisationCode = (nwsControl.LocalisationCode == "jpn") ? "" : "jpn"; 
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
   }

   public class AxControl : AxHost
   {
      public AxControl(string strCLSID)
         : base(strCLSID)
      {
      }
   }

}
