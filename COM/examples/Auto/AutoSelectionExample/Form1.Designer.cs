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
// Navisworks API - AutoSelectionExample
// This application demonstrates how to keep track of objects selected 
// in the Navisworks interface and manipulate the selection. (e.g. making 
//  objects hidden or changing colour)
//------------------------------------------------------------------
namespace AutoSelectionExample
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
         this.toolStrip1 = new System.Windows.Forms.ToolStrip();
         this.launchButton = new System.Windows.Forms.ToolStripButton();
         this.openButton = new System.Windows.Forms.ToolStripButton();
         this.zoomButton = new System.Windows.Forms.ToolStripButton();
         this.paletteButton = new System.Windows.Forms.ToolStripButton();
         this.transparencyButton = new System.Windows.Forms.ToolStripButton();
         this.resetButton = new System.Windows.Forms.ToolStripButton();
         this.selectionList = new System.Windows.Forms.ListBox();
         this.updateButton = new System.Windows.Forms.Button();
         this.groupBox1 = new System.Windows.Forms.GroupBox();
         this.groupBox2 = new System.Windows.Forms.GroupBox();
         this.scaleRadio = new System.Windows.Forms.RadioButton();
         this.translateRadio = new System.Windows.Forms.RadioButton();
         this.downButton = new System.Windows.Forms.Button();
         this.rightButton = new System.Windows.Forms.Button();
         this.upButton = new System.Windows.Forms.Button();
         this.leftButton = new System.Windows.Forms.Button();
         this.toolStrip1.SuspendLayout();
         this.groupBox1.SuspendLayout();
         this.groupBox2.SuspendLayout();
         this.SuspendLayout();
         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.launchButton,
            this.openButton,
            this.zoomButton,
            this.paletteButton,
            this.transparencyButton,
            this.resetButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(215, 25);
         this.toolStrip1.TabIndex = 0;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // launchButton
         // 
         this.launchButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.launchButton.Image = global::AutoSelectionExample.Properties.Resources.ScripterPlayAnimation;
         this.launchButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.launchButton.Name = "launchButton";
         this.launchButton.Size = new System.Drawing.Size(23, 22);
         this.launchButton.Text = "Launch Navisworks";
         this.launchButton.Click += new System.EventHandler(this.launchButton_Click);
         // 
         // openButton
         // 
         this.openButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.openButton.Image = global::AutoSelectionExample.Properties.Resources.open;
         this.openButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openButton.Name = "openButton";
         this.openButton.Size = new System.Drawing.Size(23, 22);
         this.openButton.Text = "Open File";
         this.openButton.Click += new System.EventHandler(this.openButton_Click);
         // 
         // zoomButton
         // 
         this.zoomButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.zoomButton.Image = global::AutoSelectionExample.Properties.Resources.zoom;
         this.zoomButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.zoomButton.Name = "zoomButton";
         this.zoomButton.Size = new System.Drawing.Size(23, 22);
         this.zoomButton.Text = "Zoom";
         this.zoomButton.Click += new System.EventHandler(this.zoomButton_Click);
         // 
         // paletteButton
         // 
         this.paletteButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.paletteButton.Image = global::AutoSelectionExample.Properties.Resources.palette;
         this.paletteButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.paletteButton.Name = "paletteButton";
         this.paletteButton.Size = new System.Drawing.Size(23, 22);
         this.paletteButton.Text = "Selection Color";
         this.paletteButton.Click += new System.EventHandler(this.paletteButton_Click);
         // 
         // transparencyButton
         // 
         this.transparencyButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.transparencyButton.Image = global::AutoSelectionExample.Properties.Resources.transparency;
         this.transparencyButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.transparencyButton.Name = "transparencyButton";
         this.transparencyButton.Size = new System.Drawing.Size(23, 22);
         this.transparencyButton.Text = "Transparency";
         this.transparencyButton.Click += new System.EventHandler(this.transparencyButton_Click);
         // 
         // resetButton
         // 
         this.resetButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.resetButton.Image = global::AutoSelectionExample.Properties.Resources.reset;
         this.resetButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.resetButton.Name = "resetButton";
         this.resetButton.Size = new System.Drawing.Size(23, 22);
         this.resetButton.Text = "Reset Button";
         this.resetButton.Click += new System.EventHandler(this.resetButton_Click);
         // 
         // selectionList
         // 
         this.selectionList.FormattingEnabled = true;
         this.selectionList.Location = new System.Drawing.Point(13, 29);
         this.selectionList.Name = "selectionList";
         this.selectionList.Size = new System.Drawing.Size(187, 238);
         this.selectionList.TabIndex = 1;
         // 
         // Update
         // 
         this.updateButton.Location = new System.Drawing.Point(17, 274);
         this.updateButton.Name = "Update";
         this.updateButton.Size = new System.Drawing.Size(182, 23);
         this.updateButton.TabIndex = 6;
         this.updateButton.Text = "Update Selection";
         this.updateButton.UseVisualStyleBackColor = true;
         this.updateButton.Click += new System.EventHandler(this.Update_Click);
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.groupBox2);
         this.groupBox1.Controls.Add(this.downButton);
         this.groupBox1.Controls.Add(this.rightButton);
         this.groupBox1.Controls.Add(this.upButton);
         this.groupBox1.Controls.Add(this.leftButton);
         this.groupBox1.Location = new System.Drawing.Point(13, 304);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(186, 165);
         this.groupBox1.TabIndex = 7;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Manipulation";
         // 
         // groupBox2
         // 
         this.groupBox2.Controls.Add(this.scaleRadio);
         this.groupBox2.Controls.Add(this.translateRadio);
         this.groupBox2.Location = new System.Drawing.Point(102, 11);
         this.groupBox2.Name = "groupBox2";
         this.groupBox2.Size = new System.Drawing.Size(84, 49);
         this.groupBox2.TabIndex = 10;
         this.groupBox2.TabStop = false;
         // 
         // scaleRadio
         // 
         this.scaleRadio.AutoSize = true;
         this.scaleRadio.Location = new System.Drawing.Point(7, 26);
         this.scaleRadio.Name = "scaleRadio";
         this.scaleRadio.Size = new System.Drawing.Size(50, 17);
         this.scaleRadio.TabIndex = 1;
         this.scaleRadio.TabStop = true;
         this.scaleRadio.Text = "scale";
         this.scaleRadio.UseVisualStyleBackColor = true;
         // 
         // translateRadio
         // 
         this.translateRadio.AutoSize = true;
         this.translateRadio.Location = new System.Drawing.Point(7, 10);
         this.translateRadio.Name = "translateRadio";
         this.translateRadio.Size = new System.Drawing.Size(65, 17);
         this.translateRadio.TabIndex = 0;
         this.translateRadio.TabStop = true;
         this.translateRadio.Text = "translate";
         this.translateRadio.UseVisualStyleBackColor = true;
         // 
         // downButton
         // 
         this.downButton.Image = global::AutoSelectionExample.Properties.Resources.down;
         this.downButton.Location = new System.Drawing.Point(74, 126);
         this.downButton.Name = "downButton";
         this.downButton.Size = new System.Drawing.Size(37, 23);
         this.downButton.TabIndex = 9;
         this.downButton.UseVisualStyleBackColor = true;
         this.downButton.Click += new System.EventHandler(this.downButton_Click);
         // 
         // rightButton
         // 
         this.rightButton.Image = global::AutoSelectionExample.Properties.Resources.right;
         this.rightButton.Location = new System.Drawing.Point(123, 98);
         this.rightButton.Name = "rightButton";
         this.rightButton.Size = new System.Drawing.Size(37, 23);
         this.rightButton.TabIndex = 8;
         this.rightButton.UseVisualStyleBackColor = true;
         this.rightButton.Click += new System.EventHandler(this.rightButton_Click);
         // 
         // upButton
         // 
         this.upButton.Image = global::AutoSelectionExample.Properties.Resources.up;
         this.upButton.Location = new System.Drawing.Point(74, 73);
         this.upButton.Name = "upButton";
         this.upButton.Size = new System.Drawing.Size(37, 23);
         this.upButton.TabIndex = 7;
         this.upButton.UseVisualStyleBackColor = true;
         this.upButton.Click += new System.EventHandler(this.upButton_Click);
         // 
         // leftButton
         // 
         this.leftButton.Image = global::AutoSelectionExample.Properties.Resources.left;
         this.leftButton.Location = new System.Drawing.Point(27, 98);
         this.leftButton.Name = "leftButton";
         this.leftButton.Size = new System.Drawing.Size(37, 23);
         this.leftButton.TabIndex = 6;
         this.leftButton.UseVisualStyleBackColor = true;
         this.leftButton.Click += new System.EventHandler(this.leftButton_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(215, 480);
         this.Controls.Add(this.groupBox1);
         this.Controls.Add(this.updateButton);
         this.Controls.Add(this.selectionList);
         this.Controls.Add(this.toolStrip1);
         this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "Form1";
         this.Text = "SelectionExample";
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.groupBox1.ResumeLayout(false);
         this.groupBox2.ResumeLayout(false);
         this.groupBox2.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton launchButton;
      private System.Windows.Forms.ToolStripButton zoomButton;
      private System.Windows.Forms.ToolStripButton paletteButton;
      private System.Windows.Forms.ToolStripButton transparencyButton;
      private System.Windows.Forms.ToolStripButton resetButton;
      private System.Windows.Forms.ListBox selectionList;
      private System.Windows.Forms.ToolStripButton openButton;
      private System.Windows.Forms.Button updateButton;
      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.GroupBox groupBox2;
      private System.Windows.Forms.RadioButton scaleRadio;
      private System.Windows.Forms.RadioButton translateRadio;
      private System.Windows.Forms.Button downButton;
      private System.Windows.Forms.Button rightButton;
      private System.Windows.Forms.Button upButton;
      private System.Windows.Forms.Button leftButton;
   }
}

