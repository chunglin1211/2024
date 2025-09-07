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
namespace AutoClashExample
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
         this.clashListBox = new System.Windows.Forms.ListBox();
         this.groupBox1 = new System.Windows.Forms.GroupBox();
         this.label1 = new System.Windows.Forms.Label();
         this.label2 = new System.Windows.Forms.Label();
         this.label3 = new System.Windows.Forms.Label();
         this.label4 = new System.Windows.Forms.Label();
         this.launchButton = new System.Windows.Forms.ToolStripButton();
         this.openFileButton = new System.Windows.Forms.ToolStripButton();
         this.clashButton = new System.Windows.Forms.ToolStripButton();
         this.toolStrip1.SuspendLayout();
         this.groupBox1.SuspendLayout();
         this.SuspendLayout();
         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.launchButton,
            this.openFileButton,
            this.clashButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(432, 25);
         this.toolStrip1.TabIndex = 1;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // clashListBox
         // 
         this.clashListBox.FormattingEnabled = true;
         this.clashListBox.Location = new System.Drawing.Point(12, 27);
         this.clashListBox.Name = "clashListBox";
         this.clashListBox.Size = new System.Drawing.Size(304, 212);
         this.clashListBox.TabIndex = 3;
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.label4);
         this.groupBox1.Controls.Add(this.label3);
         this.groupBox1.Controls.Add(this.label2);
         this.groupBox1.Controls.Add(this.label1);
         this.groupBox1.Location = new System.Drawing.Point(322, 146);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(98, 93);
         this.groupBox1.TabIndex = 4;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Status";
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(10, 20);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(41, 13);
         this.label1.TabIndex = 0;
         this.label1.Text = "0 -New";
         // 
         // label2
         // 
         this.label2.AutoSize = true;
         this.label2.Location = new System.Drawing.Point(10, 37);
         this.label2.Name = "label2";
         this.label2.Size = new System.Drawing.Size(46, 13);
         this.label2.TabIndex = 1;
         this.label2.Text = "1-Active";
         // 
         // label3
         // 
         this.label3.AutoSize = true;
         this.label3.Location = new System.Drawing.Point(10, 54);
         this.label3.Name = "label3";
         this.label3.Size = new System.Drawing.Size(65, 13);
         this.label3.TabIndex = 2;
         this.label3.Text = "2 -Approved";
         // 
         // label4
         // 
         this.label4.AutoSize = true;
         this.label4.Location = new System.Drawing.Point(10, 71);
         this.label4.Name = "label4";
         this.label4.Size = new System.Drawing.Size(61, 13);
         this.label4.TabIndex = 3;
         this.label4.Text = "3-Resolved";
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
         this.openFileButton.Image = global::AutoClashExample.Properties.Resources.open;
         this.openFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openFileButton.Name = "openFileButton";
         this.openFileButton.Size = new System.Drawing.Size(23, 22);
         this.openFileButton.Text = "toolStripButton1";
         this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
         // 
         // clashButton
         // 
         this.clashButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.clashButton.Image = global::AutoClashExample.Properties.Resources.Ribbon_ClashDetective_32;
         this.clashButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.clashButton.Name = "clashButton";
         this.clashButton.Size = new System.Drawing.Size(23, 22);
         this.clashButton.Text = "clash button";
         this.clashButton.Click += new System.EventHandler(this.clashButton_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(432, 252);
         this.Controls.Add(this.groupBox1);
         this.Controls.Add(this.clashListBox);
         this.Controls.Add(this.toolStrip1);
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "Form1";
         this.Text = "AutoClashExample";
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.groupBox1.ResumeLayout(false);
         this.groupBox1.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton launchButton;
      private System.Windows.Forms.ToolStripButton openFileButton;
      private System.Windows.Forms.ListBox clashListBox;
      private System.Windows.Forms.ToolStripButton clashButton;
      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.Label label4;
      private System.Windows.Forms.Label label3;
      private System.Windows.Forms.Label label2;
      private System.Windows.Forms.Label label1;
   }
}

