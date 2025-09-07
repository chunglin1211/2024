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
namespace ActiveXLocaleSwitcherExample
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
         this.japaneseButton = new System.Windows.Forms.Button();
         this.germanButton = new System.Windows.Forms.Button();
         this.englishButton = new System.Windows.Forms.Button();
         this.toolStrip1 = new System.Windows.Forms.ToolStrip();
         this.openFileButton = new System.Windows.Forms.ToolStripButton();
         this.groupBox1.SuspendLayout();
         this.groupBox2.SuspendLayout();
         this.toolStrip1.SuspendLayout();
         this.SuspendLayout();
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.nwsPlaceholder);
         this.groupBox1.Location = new System.Drawing.Point(13, 30);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(476, 263);
         this.groupBox1.TabIndex = 0;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Navisworks ActiveX Window";
         // 
         // nwsPlaceholder
         // 
         this.nwsPlaceholder.Enabled = true;
         this.nwsPlaceholder.Location = new System.Drawing.Point(6, 16);
         this.nwsPlaceholder.Name = "nwsPlaceholder";
         this.nwsPlaceholder.Size = new System.Drawing.Size(463, 237);
         this.nwsPlaceholder.TabIndex = 0;
         // 
         // groupBox2
         // 
         this.groupBox2.Controls.Add(this.japaneseButton);
         this.groupBox2.Controls.Add(this.germanButton);
         this.groupBox2.Controls.Add(this.englishButton);
         this.groupBox2.Location = new System.Drawing.Point(13, 300);
         this.groupBox2.Name = "groupBox2";
         this.groupBox2.Size = new System.Drawing.Size(476, 59);
         this.groupBox2.TabIndex = 1;
         this.groupBox2.TabStop = false;
         this.groupBox2.Text = "Animation Controls";
         // 
         // japaneseButton
         // 
         this.japaneseButton.Location = new System.Drawing.Point(377, 25);
         this.japaneseButton.Name = "japaneseButton";
         this.japaneseButton.Size = new System.Drawing.Size(75, 23);
         this.japaneseButton.TabIndex = 2;
         this.japaneseButton.Text = "&Japanese";
         this.japaneseButton.UseVisualStyleBackColor = true;
         this.japaneseButton.Click += new System.EventHandler(this.japaneseButton_Click);
         // 
         // germanButton
         // 
         this.germanButton.Location = new System.Drawing.Point(196, 25);
         this.germanButton.Name = "germanButton";
         this.germanButton.Size = new System.Drawing.Size(75, 23);
         this.germanButton.TabIndex = 1;
         this.germanButton.Text = "&German";
         this.germanButton.UseVisualStyleBackColor = true;
         this.germanButton.Click += new System.EventHandler(this.germanButton_Click);
         // 
         // englishButton
         // 
         this.englishButton.Location = new System.Drawing.Point(36, 25);
         this.englishButton.Name = "englishButton";
         this.englishButton.Size = new System.Drawing.Size(75, 23);
         this.englishButton.TabIndex = 0;
         this.englishButton.Text = "&English";
         this.englishButton.UseVisualStyleBackColor = true;
         this.englishButton.Click += new System.EventHandler(this.englishButton_Click);
         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openFileButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(501, 25);
         this.toolStrip1.TabIndex = 2;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // openFileButton
         // 
         this.openFileButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.openFileButton.Image = global::ActiveXLocaleSwitcherExample.Properties.Resources.open;
         this.openFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openFileButton.Name = "openFileButton";
         this.openFileButton.Size = new System.Drawing.Size(23, 22);
         this.openFileButton.Text = "toolStripButton1";
         this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(501, 365);
         this.Controls.Add(this.toolStrip1);
         this.Controls.Add(this.groupBox2);
         this.Controls.Add(this.groupBox1);
         this.Name = "Form1";
         this.Text = "Form1";
         this.Load += new System.EventHandler(this.Form1_Load);
         this.groupBox1.ResumeLayout(false);
         this.groupBox2.ResumeLayout(false);
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.GroupBox groupBox2;
      private System.Windows.Forms.Button japaneseButton;
      private System.Windows.Forms.Button germanButton;
      private System.Windows.Forms.Button englishButton;
      private System.Windows.Forms.Label nwsPlaceholder;
      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton openFileButton;
   }
}

