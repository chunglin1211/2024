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
namespace AutoDriveExample
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
         this.toolStrip1 = new System.Windows.Forms.ToolStrip();
         this.launchButton = new System.Windows.Forms.ToolStripButton();
         this.openFileButton = new System.Windows.Forms.ToolStripButton();
         this.listBox = new System.Windows.Forms.ListBox();
         this.ExportBitmapButton = new System.Windows.Forms.Button();
         this.toolStrip1.SuspendLayout();
         this.SuspendLayout();
         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.launchButton,
            this.openFileButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(373, 25);
         this.toolStrip1.TabIndex = 3;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // launchButton
         // 
         this.launchButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.launchButton.Image = ((System.Drawing.Image)(resources.GetObject("launchButton.Image")));
         this.launchButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.launchButton.Name = "launchButton";
         this.launchButton.Size = new System.Drawing.Size(23, 22);
         this.launchButton.Text = "toolStripButton1";
         this.launchButton.Click += new System.EventHandler(this.launchButton_Click);
         // 
         // openFileButton
         // 
         this.openFileButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.openFileButton.Image = global::AutoDriveExample.Properties.Resources.open;
         this.openFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openFileButton.Name = "openFileButton";
         this.openFileButton.Size = new System.Drawing.Size(23, 22);
         this.openFileButton.Text = "toolStripButton1";
         this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
         // 
         // listBox
         // 
         this.listBox.FormattingEnabled = true;
         this.listBox.Location = new System.Drawing.Point(13, 85);
         this.listBox.Name = "listBox";
         this.listBox.Size = new System.Drawing.Size(348, 303);
         this.listBox.TabIndex = 4;
         // 
         // ExportBitmapButton
         // 
         this.ExportBitmapButton.Location = new System.Drawing.Point(13, 29);
         this.ExportBitmapButton.Name = "ExportBitmapButton";
         this.ExportBitmapButton.Size = new System.Drawing.Size(154, 23);
         this.ExportBitmapButton.TabIndex = 5;
         this.ExportBitmapButton.Text = "Export Bitmap";
         this.ExportBitmapButton.UseVisualStyleBackColor = true;
         this.ExportBitmapButton.Click += new System.EventHandler(this.ExportBitmapButton_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(373, 400);
         this.Controls.Add(this.ExportBitmapButton);
         this.Controls.Add(this.listBox);
         this.Controls.Add(this.toolStrip1);
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "Form1";
         this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
         this.Text = "Auto Drive IO Plugin";
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton launchButton;
      private System.Windows.Forms.ToolStripButton openFileButton;
      private System.Windows.Forms.ListBox listBox;
      private System.Windows.Forms.Button ExportBitmapButton;
   }
}

