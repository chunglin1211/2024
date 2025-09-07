//------------------------------------------------------------------
// NavisWorks Sample code
//------------------------------------------------------------------

// (C) Copyright 2009 by Autodesk Inc.

// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted,
// provided that the above copyright notice appears in all copies and
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting
// documentation.

// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS.
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//------------------------------------------------------------------
//
// This sample demonstrates a basic Viewer for Navisworks files using
// the Controls part of the API
//
//------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using Autodesk.Navisworks.Api.Controls;

namespace Viewer
{
    public partial class Viewer : Form
    {
        public Viewer()
        {
            InitializeComponent();

            // Dynamically create the Navisworks Viewer Control.
            this.viewControl = new Autodesk.Navisworks.Api.Controls.ViewControl();
            this.documentControl = new Autodesk.Navisworks.Api.Controls.DocumentControl(this.components);
            this.viewControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.viewControl.DocumentControl = this.documentControl;
            this.viewControl.Location = new System.Drawing.Point(0, 24);
            this.viewControl.Name = "viewControl";
            this.viewControl.Size = new System.Drawing.Size(745, 496);
            this.viewControl.TabIndex = 1;
            this.viewControl.Text = "viewControl";
            this.Controls.Add(this.viewControl);
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
           LoadDocument();
        }

        private void LoadDocument()
        {
           #region DocumentControlDocumentTryOpenFile
           //Dialog for selecting the Location of the file toolStripMenuItem1 open
           OpenFileDialog dlg = new OpenFileDialog();

           //Ask user for file location
           if (dlg.ShowDialog() == DialogResult.OK)
           {
              //If the user has selected a valid location, then tell DocumentControl to open the file
              //As DocumentCtrl is linked to ViewControl
              documentControl.Document.TryOpenFile(dlg.FileName);
           }
           #endregion
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private Autodesk.Navisworks.Api.Controls.ViewControl viewControl;
        private Autodesk.Navisworks.Api.Controls.DocumentControl documentControl;
    }
}
