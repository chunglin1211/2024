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
// Navisworks API - Example that outputs the text about the contents 
// of the loaded model into a list model
//------------------------------------------------------------------
namespace ActiveXDumpStructureExample
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
         this.nwsPlaceholder = new System.Windows.Forms.Label();
         this.groupBox2 = new System.Windows.Forms.GroupBox();
         this.structureTreeView = new System.Windows.Forms.TreeView();
         this.label1 = new System.Windows.Forms.Label();
         this.progressBar1 = new System.Windows.Forms.ProgressBar();
         this.dumpFileButton = new System.Windows.Forms.Button();
         this.toolStrip1 = new System.Windows.Forms.ToolStrip();
         this.openFileButton = new System.Windows.Forms.ToolStripButton();
         this.groupBox3 = new System.Windows.Forms.GroupBox();
         this.treeView1 = new System.Windows.Forms.TreeView();
         this.label2 = new System.Windows.Forms.Label();
         this.button1 = new System.Windows.Forms.Button();
         this.groupBox1.SuspendLayout();
         this.groupBox2.SuspendLayout();
         this.toolStrip1.SuspendLayout();
         this.groupBox3.SuspendLayout();
         this.SuspendLayout();
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.nwsPlaceholder);
         this.groupBox1.Location = new System.Drawing.Point(13, 28);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(479, 250);
         this.groupBox1.TabIndex = 0;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Navisworks ActiveX Window";
         // 
         // nwsPlaceholder
         // 
         this.nwsPlaceholder.Enabled = true;
         this.nwsPlaceholder.Location = new System.Drawing.Point(7, 20);
         this.nwsPlaceholder.Name = "nwsPlaceholder";
         this.nwsPlaceholder.Size = new System.Drawing.Size(466, 224);
         this.nwsPlaceholder.TabIndex = 0;
         // 
         // groupBox2
         // 
         this.groupBox2.Controls.Add(this.structureTreeView);
         this.groupBox2.Controls.Add(this.label1);
         this.groupBox2.Controls.Add(this.progressBar1);
         this.groupBox2.Controls.Add(this.dumpFileButton);
         this.groupBox2.Location = new System.Drawing.Point(13, 284);
         this.groupBox2.Name = "groupBox2";
         this.groupBox2.Size = new System.Drawing.Size(479, 228);
         this.groupBox2.TabIndex = 1;
         this.groupBox2.TabStop = false;
         this.groupBox2.Text = "File Dump Control";
         // 
         // structureTreeView
         // 
         this.structureTreeView.Location = new System.Drawing.Point(7, 80);
         this.structureTreeView.Name = "structureTreeView";
         this.structureTreeView.Size = new System.Drawing.Size(466, 142);
         this.structureTreeView.TabIndex = 3;
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(16, 64);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(39, 13);
         this.label1.TabIndex = 2;
         this.label1.Text = "Output";
         // 
         // progressBar1
         // 
         this.progressBar1.Location = new System.Drawing.Point(101, 29);
         this.progressBar1.Name = "progressBar1";
         this.progressBar1.Size = new System.Drawing.Size(359, 23);
         this.progressBar1.Step = 1;
         this.progressBar1.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
         this.progressBar1.TabIndex = 1;
         // 
         // dumpFileButton
         // 
         this.dumpFileButton.Location = new System.Drawing.Point(7, 30);
         this.dumpFileButton.Name = "dumpFileButton";
         this.dumpFileButton.Size = new System.Drawing.Size(75, 23);
         this.dumpFileButton.TabIndex = 0;
         this.dumpFileButton.Text = "&Dump File";
         this.dumpFileButton.UseVisualStyleBackColor = true;
         this.dumpFileButton.Click += new System.EventHandler(this.dumpFileButton_Click);
         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openFileButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(504, 25);
         this.toolStrip1.TabIndex = 2;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // openFileButton
         // 
         this.openFileButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.openFileButton.Image = global::ActiveXDumpStructureExample.Properties.Resources.open;
         this.openFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openFileButton.Name = "openFileButton";
         this.openFileButton.Size = new System.Drawing.Size(23, 22);
         this.openFileButton.Text = "toolStripButton1";
         this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
         // 
         // groupBox3
         // 
         this.groupBox3.Controls.Add(this.treeView1);
         this.groupBox3.Controls.Add(this.label2);
         this.groupBox3.Controls.Add(this.button1);
         this.groupBox3.Location = new System.Drawing.Point(13, 520);
         this.groupBox3.Name = "groupBox3";
         this.groupBox3.Size = new System.Drawing.Size(479, 228);
         this.groupBox3.TabIndex = 3;
         this.groupBox3.TabStop = false;
         this.groupBox3.Text = "Dump Primitives";
         // 
         // treeView1
         // 
         this.treeView1.Location = new System.Drawing.Point(7, 80);
         this.treeView1.Name = "treeView1";
         this.treeView1.Size = new System.Drawing.Size(466, 142);
         this.treeView1.TabIndex = 3;
         // 
         // label2
         // 
         this.label2.AutoSize = true;
         this.label2.Location = new System.Drawing.Point(16, 64);
         this.label2.Name = "label2";
         this.label2.Size = new System.Drawing.Size(39, 13);
         this.label2.TabIndex = 2;
         this.label2.Text = "Output";
         // 
         // button1
         // 
         this.button1.Location = new System.Drawing.Point(7, 30);
         this.button1.Name = "button1";
         this.button1.Size = new System.Drawing.Size(453, 23);
         this.button1.TabIndex = 0;
         this.button1.Text = "&Generate Primitives of Selected Objects";
         this.button1.UseVisualStyleBackColor = true;
         this.button1.Click += new System.EventHandler(this.generatePrims_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(504, 767);
         this.Controls.Add(this.groupBox3);
         this.Controls.Add(this.toolStrip1);
         this.Controls.Add(this.groupBox2);
         this.Controls.Add(this.groupBox1);
         this.Name = "Form1";
         this.Text = "Form1";
         this.Load += new System.EventHandler(this.Form1_Load);
         this.groupBox1.ResumeLayout(false);
         this.groupBox2.ResumeLayout(false);
         this.groupBox2.PerformLayout();
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.groupBox3.ResumeLayout(false);
         this.groupBox3.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.Label nwsPlaceholder;
      private System.Windows.Forms.GroupBox groupBox2;
      private System.Windows.Forms.Label label1;
      private System.Windows.Forms.ProgressBar progressBar1;
      private System.Windows.Forms.Button dumpFileButton;
      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton openFileButton;
      private System.Windows.Forms.TreeView structureTreeView;
      private System.Windows.Forms.GroupBox groupBox3;
      private System.Windows.Forms.TreeView treeView1;
      private System.Windows.Forms.Label label2;
      private System.Windows.Forms.Button button1;
   }
}

