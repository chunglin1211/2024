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
// Navisworks API - Demonstration of using create picture command 
// and adding custom context menu items
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ActiveXSnapshotExample
{

   public partial class Form1 : Form
   {
      public static class ImageUtilities
      {
         public static object ConvertFromIPicture(object image)
         {
            return ImageOLEConverter.Instance.ConvertFromIPicture(image);
         }

         private class ImageOLEConverter : AxHost
         {
            public static readonly ImageOLEConverter Instance = new
            ImageOLEConverter();

            private ImageOLEConverter()
               : base(Guid.Empty.ToString())
            {
            }

            public object ConvertFromIPicture(object image)
            {
               return AxHost.GetPictureFromIPicture(image);
            }
         }
      }

      private NavisworksIntegratedAPI21.nwOpState m_state;
      private NavisworksIntegratedAPI21.nwControlMDI nwsControl;
      private Image m_image;

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
            string filename = fileDialog.FileName;
            nwsControl.SRC = filename;
            nwsControl.APIState.CurrentView.ViewPoint.Paradigm = NavisworksIntegratedAPI21.nwEParadigm.eParadigm_APPLICATION;
         }
      }

      private void snapShotButton_Click(object sender, EventArgs e)
      {
         // Call the create picture command based on the current view and store the result in m_image
         m_image = ImageUtilities.ConvertFromIPicture(m_state.CreatePicture(nwsControl.APIState.CurrentView)) as Image;
         snapShotImageBox.Image = m_image;
      }

      private void saveSnapshotButton_Click(object sender, EventArgs e)
      {
         if (m_image != null)
         {
            SaveFileDialog fileDialog = new SaveFileDialog();
            fileDialog.Filter = "JPEG files|*.jpg|All files|*.*";
            fileDialog.Title = "Save Image file";
            DialogResult result = fileDialog.ShowDialog();
            if (result == DialogResult.OK)
            {
               m_image.Save(fileDialog.FileName);
            }
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
