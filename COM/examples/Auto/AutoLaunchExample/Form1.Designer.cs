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
// Navisworks API - AutoLaunchExample
// This is a simple example showing how to launch Navisworks and
// perform some basic functions
//------------------------------------------------------------------
namespace AutoLaunchExample
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
         this.groupBox1 = new System.Windows.Forms.GroupBox();
         this.ProductInfoLabel = new System.Windows.Forms.Label();
         this.LaunchButton = new System.Windows.Forms.Button();
         this.leaveCBox = new System.Windows.Forms.CheckBox();
         this.groupBox2 = new System.Windows.Forms.GroupBox();
         this.TurntableNavigationButton = new System.Windows.Forms.Button();
         this.ShowASavedViewButton = new System.Windows.Forms.Button();
         this.ViewAllButton = new System.Windows.Forms.Button();
         this.OpenFileButton = new System.Windows.Forms.Button();
         this.groupBox1.SuspendLayout();
         this.groupBox2.SuspendLayout();
         this.SuspendLayout();
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.ProductInfoLabel);
         this.groupBox1.Controls.Add(this.LaunchButton);
         this.groupBox1.Controls.Add(this.leaveCBox);
         this.groupBox1.Location = new System.Drawing.Point(13, 13);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(404, 121);
         this.groupBox1.TabIndex = 0;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Start up";
         // 
         // ProductInfoLabel
         // 
         this.ProductInfoLabel.AutoSize = true;
         this.ProductInfoLabel.Location = new System.Drawing.Point(179, 69);
         this.ProductInfoLabel.Name = "ProductInfoLabel";
         this.ProductInfoLabel.Size = new System.Drawing.Size(89, 13);
         this.ProductInfoLabel.TabIndex = 2;
         this.ProductInfoLabel.Text = "<<Product Info>>";
         // 
         // LaunchButton
         // 
         this.LaunchButton.Location = new System.Drawing.Point(7, 55);
         this.LaunchButton.Name = "LaunchButton";
         this.LaunchButton.Size = new System.Drawing.Size(146, 40);
         this.LaunchButton.TabIndex = 1;
         this.LaunchButton.Text = "&Launch Navisworks";
         this.LaunchButton.UseVisualStyleBackColor = true;
         this.LaunchButton.Click += new System.EventHandler(this.LaunchButton_Click);
         // 
         // leaveCBox
         // 
         this.leaveCBox.AutoSize = true;
         this.leaveCBox.Location = new System.Drawing.Point(89, 20);
         this.leaveCBox.Name = "leaveCBox";
         this.leaveCBox.Size = new System.Drawing.Size(277, 17);
         this.leaveCBox.TabIndex = 0;
         this.leaveCBox.Text = "Leave Navisworks open when API application closes";
         this.leaveCBox.UseVisualStyleBackColor = true;
         // 
         // groupBox2
         // 
         this.groupBox2.Controls.Add(this.TurntableNavigationButton);
         this.groupBox2.Controls.Add(this.ShowASavedViewButton);
         this.groupBox2.Controls.Add(this.ViewAllButton);
         this.groupBox2.Controls.Add(this.OpenFileButton);
         this.groupBox2.Location = new System.Drawing.Point(12, 152);
         this.groupBox2.Name = "groupBox2";
         this.groupBox2.Size = new System.Drawing.Size(404, 141);
         this.groupBox2.TabIndex = 1;
         this.groupBox2.TabStop = false;
         this.groupBox2.Text = "Automation Control";
         // 
         // TurntableNavigationButton
         // 
         this.TurntableNavigationButton.Enabled = false;
         this.TurntableNavigationButton.Location = new System.Drawing.Point(239, 93);
         this.TurntableNavigationButton.Name = "TurntableNavigationButton";
         this.TurntableNavigationButton.Size = new System.Drawing.Size(115, 30);
         this.TurntableNavigationButton.TabIndex = 3;
         this.TurntableNavigationButton.Text = "&Turntable Navigation";
         this.TurntableNavigationButton.UseVisualStyleBackColor = true;
         this.TurntableNavigationButton.Click += new System.EventHandler(this.TurntableNavigationButton_Click);
         // 
         // ShowASavedViewButton
         // 
         this.ShowASavedViewButton.Enabled = false;
         this.ShowASavedViewButton.Location = new System.Drawing.Point(47, 93);
         this.ShowASavedViewButton.Name = "ShowASavedViewButton";
         this.ShowASavedViewButton.Size = new System.Drawing.Size(115, 30);
         this.ShowASavedViewButton.TabIndex = 2;
         this.ShowASavedViewButton.Text = "&Show A Saved View";
         this.ShowASavedViewButton.UseVisualStyleBackColor = true;
         this.ShowASavedViewButton.Click += new System.EventHandler(this.ShowASavedViewButton_Click);
         // 
         // ViewAllButton
         // 
         this.ViewAllButton.Enabled = false;
         this.ViewAllButton.Location = new System.Drawing.Point(239, 33);
         this.ViewAllButton.Name = "ViewAllButton";
         this.ViewAllButton.Size = new System.Drawing.Size(115, 30);
         this.ViewAllButton.TabIndex = 1;
         this.ViewAllButton.Text = "&View All";
         this.ViewAllButton.UseVisualStyleBackColor = true;
         this.ViewAllButton.Click += new System.EventHandler(this.ViewAllButton_Click);
         // 
         // OpenFileButton
         // 
         this.OpenFileButton.Enabled = false;
         this.OpenFileButton.Location = new System.Drawing.Point(47, 33);
         this.OpenFileButton.Name = "OpenFileButton";
         this.OpenFileButton.Size = new System.Drawing.Size(115, 30);
         this.OpenFileButton.TabIndex = 0;
         this.OpenFileButton.Text = "&Open File";
         this.OpenFileButton.UseVisualStyleBackColor = true;
         this.OpenFileButton.Click += new System.EventHandler(this.OpenFileButton_Click);
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(429, 304);
         this.Controls.Add(this.groupBox2);
         this.Controls.Add(this.groupBox1);
         this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "Form1";
         this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
         this.Text = "Navisworks API - AutoLaunchExample - Basic Automation";
         this.groupBox1.ResumeLayout(false);
         this.groupBox1.PerformLayout();
         this.groupBox2.ResumeLayout(false);
         this.ResumeLayout(false);

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.Label ProductInfoLabel;
      private System.Windows.Forms.Button LaunchButton;
      private System.Windows.Forms.CheckBox leaveCBox;
      private System.Windows.Forms.GroupBox groupBox2;
      private System.Windows.Forms.Button TurntableNavigationButton;
      private System.Windows.Forms.Button ShowASavedViewButton;
      private System.Windows.Forms.Button ViewAllButton;
      private System.Windows.Forms.Button OpenFileButton;
   }
}

