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
namespace AutoUserPropsExample
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
         this.PropertyListBox = new System.Windows.Forms.ListBox();
         this.DumpCurrentButton = new System.Windows.Forms.Button();
         this.RemoveCurrentSelectionUDPButton = new System.Windows.Forms.Button();
         this.AddUDPToCurrentSelectionButton = new System.Windows.Forms.Button();
         this.AddUDPButton = new System.Windows.Forms.Button();
         this.EditUDPButton = new System.Windows.Forms.Button();
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
         this.toolStrip1.Size = new System.Drawing.Size(441, 25);
         this.toolStrip1.TabIndex = 2;
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
         this.openFileButton.Image = global::AutoUserPropsExample.Properties.Resources.open;
         this.openFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openFileButton.Name = "openFileButton";
         this.openFileButton.Size = new System.Drawing.Size(23, 22);
         this.openFileButton.Text = "toolStripButton1";
         this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
         // 
         // PropertyListBox
         // 
         this.PropertyListBox.FormattingEnabled = true;
         this.PropertyListBox.Location = new System.Drawing.Point(12, 90);
         this.PropertyListBox.Name = "PropertyListBox";
         this.PropertyListBox.Size = new System.Drawing.Size(417, 225);
         this.PropertyListBox.TabIndex = 3;
         // 
         // DumpCurrentButton
         // 
         this.DumpCurrentButton.Location = new System.Drawing.Point(118, 28);
         this.DumpCurrentButton.Name = "DumpCurrentButton";
         this.DumpCurrentButton.Size = new System.Drawing.Size(187, 23);
         this.DumpCurrentButton.TabIndex = 4;
         this.DumpCurrentButton.Text = "Dump Current Slection Properties";
         this.DumpCurrentButton.UseVisualStyleBackColor = true;
         this.DumpCurrentButton.Click += new System.EventHandler(this.DumpCurrentButton_Click);
         // 
         // RemoveCurrentSelectionUDPButton
         // 
         this.RemoveCurrentSelectionUDPButton.Location = new System.Drawing.Point(12, 321);
         this.RemoveCurrentSelectionUDPButton.Name = "RemoveCurrentSelectionUDPButton";
         this.RemoveCurrentSelectionUDPButton.Size = new System.Drawing.Size(194, 35);
         this.RemoveCurrentSelectionUDPButton.TabIndex = 5;
         this.RemoveCurrentSelectionUDPButton.Text = "Remove Current Selection UserDefined Properties";
         this.RemoveCurrentSelectionUDPButton.UseVisualStyleBackColor = true;
         this.RemoveCurrentSelectionUDPButton.Click += new System.EventHandler(this.RemoveCurrentSelectionUDPButton_Click);
         // 
         // AddUDPToCurrentSelectionButton
         // 
         this.AddUDPToCurrentSelectionButton.Location = new System.Drawing.Point(238, 321);
         this.AddUDPToCurrentSelectionButton.Name = "AddUDPToCurrentSelectionButton";
         this.AddUDPToCurrentSelectionButton.Size = new System.Drawing.Size(191, 35);
         this.AddUDPToCurrentSelectionButton.TabIndex = 6;
         this.AddUDPToCurrentSelectionButton.Text = "Add UserDefined Propertiees to Current Selection";
         this.AddUDPToCurrentSelectionButton.UseVisualStyleBackColor = true;
         this.AddUDPToCurrentSelectionButton.Click += new System.EventHandler(this.AddUDPToCurrentSelectionButton_Click);
         // 
         // AddUDPButton
         // 
         this.AddUDPButton.Location = new System.Drawing.Point(12, 58);
         this.AddUDPButton.Name = "AddUDPButton";
         this.AddUDPButton.Size = new System.Drawing.Size(194, 23);
         this.AddUDPButton.TabIndex = 7;
         this.AddUDPButton.Text = "Add UserDefined Property";
         this.AddUDPButton.UseVisualStyleBackColor = true;
         this.AddUDPButton.Click += new System.EventHandler(this.AddUDPButton_Click);
         // 
         // EditUDPButton
         // 
         this.EditUDPButton.Location = new System.Drawing.Point(238, 58);
         this.EditUDPButton.Name = "EditUDPButton";
         this.EditUDPButton.Size = new System.Drawing.Size(191, 23);
         this.EditUDPButton.TabIndex = 8;
         this.EditUDPButton.Text = "Edit UserDefined Property";
         this.EditUDPButton.UseVisualStyleBackColor = true;
         this.EditUDPButton.Click += new System.EventHandler(this.EditUDPButton_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(441, 366);
         this.Controls.Add(this.EditUDPButton);
         this.Controls.Add(this.AddUDPButton);
         this.Controls.Add(this.AddUDPToCurrentSelectionButton);
         this.Controls.Add(this.RemoveCurrentSelectionUDPButton);
         this.Controls.Add(this.DumpCurrentButton);
         this.Controls.Add(this.PropertyListBox);
         this.Controls.Add(this.toolStrip1);
         this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "Form1";
         this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
         this.Text = "Auto User Properties Examples";
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton launchButton;
      private System.Windows.Forms.ToolStripButton openFileButton;
      private System.Windows.Forms.ListBox PropertyListBox;
      private System.Windows.Forms.Button DumpCurrentButton;
      private System.Windows.Forms.Button RemoveCurrentSelectionUDPButton;
      private System.Windows.Forms.Button AddUDPToCurrentSelectionButton;
      private System.Windows.Forms.Button AddUDPButton;
      private System.Windows.Forms.Button EditUDPButton;
   }
}

