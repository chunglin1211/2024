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
// Navisworks API - Simple example. This example shows you 
// How to create, store and play back animations.
//------------------------------------------------------------------
namespace ActiveXSimpleExample
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
         this.OpenFileButton = new System.Windows.Forms.ToolStripButton();
         this.beginButton = new System.Windows.Forms.ToolStripButton();
         this.playBackwardsButton = new System.Windows.Forms.ToolStripButton();
         this.pauseButton = new System.Windows.Forms.ToolStripButton();
         this.stopButton = new System.Windows.Forms.ToolStripButton();
         this.playForwardsButton = new System.Windows.Forms.ToolStripButton();
         this.endButton = new System.Windows.Forms.ToolStripButton();
         this.recordButton = new System.Windows.Forms.ToolStripButton();
         this.addButton = new System.Windows.Forms.ToolStripButton();
         this.savedAnimationsListBox = new System.Windows.Forms.ListBox();
         this.nwsPlaceholder = new System.Windows.Forms.Label();
         this.toolStrip1.SuspendLayout();
         this.SuspendLayout();

         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.OpenFileButton,
            this.beginButton,
            this.playBackwardsButton,
            this.pauseButton,
            this.stopButton,
            this.playForwardsButton,
            this.endButton,
            this.recordButton,
            this.addButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(573, 25);
         this.toolStrip1.TabIndex = 4;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // OpenFileButton
         // 
         this.OpenFileButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.OpenFileButton.Image = global::ActiveXSimpleExample.Properties.Resources.open;
         this.OpenFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.OpenFileButton.Name = "OpenFileButton";
         this.OpenFileButton.Size = new System.Drawing.Size(23, 22);
         this.OpenFileButton.Text = "Open File Button";
         this.OpenFileButton.Click += new System.EventHandler(this.OpenFileButton_Click);
         // 
         // beginButton
         // 
         this.beginButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.beginButton.Image = global::ActiveXSimpleExample.Properties.Resources.SheetNavigationBarFirst;
         this.beginButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.beginButton.Name = "beginButton";
         this.beginButton.Size = new System.Drawing.Size(23, 22);
         this.beginButton.Text = "toolStripButton1";
         this.beginButton.Click += new System.EventHandler(this.beginButton_Click);
         // 
         // playBackwardsButton
         // 
         this.playBackwardsButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.playBackwardsButton.Image = global::ActiveXSimpleExample.Properties.Resources.SheetNavigationBarPrevious;
         this.playBackwardsButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.playBackwardsButton.Name = "playBackwardsButton";
         this.playBackwardsButton.Size = new System.Drawing.Size(23, 22);
         this.playBackwardsButton.Text = "toolStripButton2";
         this.playBackwardsButton.Click += new System.EventHandler(this.playBackwardsButton_Click);
         // 
         // pauseButton
         // 
         this.pauseButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.pauseButton.Image = global::ActiveXSimpleExample.Properties.Resources.pause;
         this.pauseButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.pauseButton.Name = "pauseButton";
         this.pauseButton.Size = new System.Drawing.Size(23, 22);
         this.pauseButton.Text = "toolStripButton3";
         this.pauseButton.Click += new System.EventHandler(this.pauseButton_Click);
         // 
         // stopButton
         // 
         this.stopButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.stopButton.Image = global::ActiveXSimpleExample.Properties.Resources.Stopf;
         this.stopButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.stopButton.Name = "stopButton";
         this.stopButton.Size = new System.Drawing.Size(23, 22);
         this.stopButton.Text = "toolStripButton6";
         this.stopButton.Click += new System.EventHandler(this.stopButton_Click);
         // 
         // playForwardsButton
         // 
         this.playForwardsButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.playForwardsButton.Image = global::ActiveXSimpleExample.Properties.Resources.SheetNavigationBarNext;
         this.playForwardsButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.playForwardsButton.Name = "playForwardsButton";
         this.playForwardsButton.Size = new System.Drawing.Size(23, 22);
         this.playForwardsButton.Text = "toolStripButton4";
         this.playForwardsButton.Click += new System.EventHandler(this.playForwardsButton_Click);
         // 
         // endButton
         // 
         this.endButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.endButton.Image = global::ActiveXSimpleExample.Properties.Resources.SheetNavigationBarLast;
         this.endButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.endButton.Name = "endButton";
         this.endButton.Size = new System.Drawing.Size(23, 22);
         this.endButton.Text = "toolStripButton5";
         this.endButton.Click += new System.EventHandler(this.endButton_Click);
         // 
         // recordButton
         // 
         this.recordButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.recordButton.Image = global::ActiveXSimpleExample.Properties.Resources.Record1;
         this.recordButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.recordButton.Name = "recordButton";
         this.recordButton.Size = new System.Drawing.Size(23, 22);
         this.recordButton.Text = "toolStripButton7";
         this.recordButton.Click += new System.EventHandler(this.recordButton_Click);
         // 
         // addButton
         // 
         this.addButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.addButton.Image = global::ActiveXSimpleExample.Properties.Resources.ListAdd;
         this.addButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.addButton.Name = "addButton";
         this.addButton.Size = new System.Drawing.Size(23, 22);
         this.addButton.Text = "toolStripButton8";
         this.addButton.Click += new System.EventHandler(this.addButton_Click);
         // 
         // savedAnimationsListBox
         // 
         this.savedAnimationsListBox.FormattingEnabled = true;
         this.savedAnimationsListBox.Location = new System.Drawing.Point(12, 257);
         this.savedAnimationsListBox.Name = "savedAnimationsListBox";
         this.savedAnimationsListBox.Size = new System.Drawing.Size(549, 264);
         this.savedAnimationsListBox.TabIndex = 5;
         this.savedAnimationsListBox.Click += new System.EventHandler(this.savedAnimationsListBox_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(573, 536);
         this.Controls.Add(this.savedAnimationsListBox);
         this.Controls.Add(this.toolStrip1);
         this.Controls.Add(nwsPlaceholder);
         this.Name = "Form1";
         this.Text = "ActiveX Animation Example";
         this.Load += new System.EventHandler(this.Form1_Load);
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();
         // 
         // nwsPlaceholder
         // 
         this.nwsPlaceholder.Location = new System.Drawing.Point(16, 35);
         this.nwsPlaceholder.Name = "nwsPlaceholder";
         this.nwsPlaceholder.Size = new System.Drawing.Size(544, 210);
         this.nwsPlaceholder.TabIndex = 6;
         this.nwsPlaceholder.Text = "nwsPlaceholder";

      }

      #endregion

      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton OpenFileButton;
      private System.Windows.Forms.ToolStripButton beginButton;
      private System.Windows.Forms.ToolStripButton playBackwardsButton;
      private System.Windows.Forms.ToolStripButton pauseButton;
      private System.Windows.Forms.ToolStripButton playForwardsButton;
      private System.Windows.Forms.ToolStripButton endButton;
      private System.Windows.Forms.ToolStripButton stopButton;
      private System.Windows.Forms.ToolStripButton recordButton;
      private System.Windows.Forms.ToolStripButton addButton;
      private System.Windows.Forms.ListBox savedAnimationsListBox;
      private System.Windows.Forms.Label nwsPlaceholder;
   }
}

