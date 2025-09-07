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
namespace ActiveXSnapshotExample
{
   partial class Form1
   {
      /// <summary>
      /// Required designer variable.
      /// </summary>
      private System.ComponentModel.IContainer components = null;

      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
      protected override void Dispose(bool disposing)
      {
         if (disposing && (components != null))
         {
            components.Dispose();
         }
         base.Dispose(disposing);
      }

      #region Windows Form Designer generated code

      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      private void InitializeComponent()
      {
         System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
         this.groupBox1 = new System.Windows.Forms.GroupBox();
         this.groupBox2 = new System.Windows.Forms.GroupBox();
         this.toolStrip1 = new System.Windows.Forms.ToolStrip();
         this.openFileButton = new System.Windows.Forms.ToolStripButton();
         this.snapShotButton = new System.Windows.Forms.ToolStripButton();
         this.saveSnapshotButton = new System.Windows.Forms.ToolStripButton();
         this.snapShotImageBox = new System.Windows.Forms.PictureBox();
         this.nwsPlaceholder = new System.Windows.Forms.Label();
         this.groupBox1.SuspendLayout();
         this.groupBox2.SuspendLayout();
         this.toolStrip1.SuspendLayout();
         ((System.ComponentModel.ISupportInitialize)(this.snapShotImageBox)).BeginInit();
         this.SuspendLayout();
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.nwsPlaceholder);
         this.groupBox1.Location = new System.Drawing.Point(13, 40);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(294, 273);
         this.groupBox1.TabIndex = 0;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Navisworks ActiveX Window";
         // 
         // groupBox2
         // 
         this.groupBox2.Controls.Add(this.snapShotImageBox);
         this.groupBox2.Location = new System.Drawing.Point(313, 39);
         this.groupBox2.Name = "groupBox2";
         this.groupBox2.Size = new System.Drawing.Size(301, 274);
         this.groupBox2.TabIndex = 1;
         this.groupBox2.TabStop = false;
         this.groupBox2.Text = "Snapshot Image";
         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openFileButton,
            this.snapShotButton,
            this.saveSnapshotButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(627, 25);
         this.toolStrip1.TabIndex = 2;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // openFileButton
         // 
         this.openFileButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.openFileButton.Image = global::ActiveXSnapshotExample.Properties.Resources.open;
         this.openFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openFileButton.Name = "openFileButton";
         this.openFileButton.Size = new System.Drawing.Size(23, 22);
         this.openFileButton.Text = "toolStripButton1";
         this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
         // 
         // snapShotButton
         // 
         this.snapShotButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.snapShotButton.Image = global::ActiveXSnapshotExample.Properties.Resources.camera;
         this.snapShotButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.snapShotButton.Name = "snapShotButton";
         this.snapShotButton.Size = new System.Drawing.Size(23, 22);
         this.snapShotButton.Text = "toolStripButton2";
         this.snapShotButton.Click += new System.EventHandler(this.snapShotButton_Click);
         // 
         // saveSnapshotButton
         // 
         this.saveSnapshotButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.saveSnapshotButton.Image = global::ActiveXSnapshotExample.Properties.Resources.SavedItem_Folder;
         this.saveSnapshotButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.saveSnapshotButton.Name = "saveSnapshotButton";
         this.saveSnapshotButton.Size = new System.Drawing.Size(23, 22);
         this.saveSnapshotButton.Text = "toolStripButton3";
         this.saveSnapshotButton.Click += new System.EventHandler(this.saveSnapshotButton_Click);
         // 
         // snapShotImageBox
         // 
         this.snapShotImageBox.Location = new System.Drawing.Point(7, 20);
         this.snapShotImageBox.Name = "snapShotImageBox";
         this.snapShotImageBox.Size = new System.Drawing.Size(288, 248);
         this.snapShotImageBox.TabIndex = 0;
         this.snapShotImageBox.TabStop = false;
         // 
         // nwsPlaceholder
         // 
         this.nwsPlaceholder.Enabled = true;
         this.nwsPlaceholder.Location = new System.Drawing.Point(7, 20);
         this.nwsPlaceholder.Name = "nwsPlaceholder";
         this.nwsPlaceholder.Size = new System.Drawing.Size(281, 247);
         this.nwsPlaceholder.TabIndex = 0;
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(627, 331);
         this.Controls.Add(this.toolStrip1);
         this.Controls.Add(this.groupBox2);
         this.Controls.Add(this.groupBox1);
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "Form1";
         this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
         this.Text = "ActiveX Snapshot Example";
         this.Load += new System.EventHandler(this.Form1_Load);
         this.groupBox1.ResumeLayout(false);
         this.groupBox2.ResumeLayout(false);
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         ((System.ComponentModel.ISupportInitialize)(this.snapShotImageBox)).EndInit();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.GroupBox groupBox2;
      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton openFileButton;
      private System.Windows.Forms.ToolStripButton snapShotButton;
      private System.Windows.Forms.ToolStripButton saveSnapshotButton;
      private System.Windows.Forms.PictureBox snapShotImageBox;
      private System.Windows.Forms.Label nwsPlaceholder;
   }
}

