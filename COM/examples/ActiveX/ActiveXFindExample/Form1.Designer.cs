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
// Navisworks API  - Example usage of the complex but powerful find 
// tool
//------------------------------------------------------------------
namespace ActiveXFindExample
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
         this.findControlGroup = new System.Windows.Forms.GroupBox();
         this.conditionTB = new System.Windows.Forms.ComboBox();
         this.findButton = new System.Windows.Forms.Button();
         this.Results = new System.Windows.Forms.Label();
         this.resultsListBox = new System.Windows.Forms.ListBox();
         this.nwsPlaceholder = new System.Windows.Forms.Label();
         this.toolStrip1 = new System.Windows.Forms.ToolStrip();
         this.openFileButton = new System.Windows.Forms.ToolStripButton();
         this.attibuteTB = new System.Windows.Forms.TextBox();
         this.propertyTB = new System.Windows.Forms.TextBox();
         this.label1 = new System.Windows.Forms.Label();
         this.valueTB = new System.Windows.Forms.TextBox();
         this.label2 = new System.Windows.Forms.Label();
         this.label3 = new System.Windows.Forms.Label();
         this.label4 = new System.Windows.Forms.Label();
         this.groupBox1.SuspendLayout();
         this.findControlGroup.SuspendLayout();
         this.toolStrip1.SuspendLayout();
         this.SuspendLayout();
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.nwsPlaceholder);
         this.groupBox1.Location = new System.Drawing.Point(13, 25);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(569, 263);
         this.groupBox1.TabIndex = 0;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Navisworks ActiveX Window";
         // 
         // findControlGroup
         // 
         this.findControlGroup.Controls.Add(this.label4);
         this.findControlGroup.Controls.Add(this.label3);
         this.findControlGroup.Controls.Add(this.label2);
         this.findControlGroup.Controls.Add(this.valueTB);
         this.findControlGroup.Controls.Add(this.label1);
         this.findControlGroup.Controls.Add(this.propertyTB);
         this.findControlGroup.Controls.Add(this.attibuteTB);
         this.findControlGroup.Controls.Add(this.resultsListBox);
         this.findControlGroup.Controls.Add(this.Results);
         this.findControlGroup.Controls.Add(this.findButton);
         this.findControlGroup.Controls.Add(this.conditionTB);
         this.findControlGroup.Location = new System.Drawing.Point(13, 295);
         this.findControlGroup.Name = "findControlGroup";
         this.findControlGroup.Size = new System.Drawing.Size(569, 202);
         this.findControlGroup.TabIndex = 1;
         this.findControlGroup.TabStop = false;
         this.findControlGroup.Text = "Find Controls";
         // 
         // conditionTB
         // 
         this.conditionTB.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
         this.conditionTB.FormattingEnabled = true;
         this.conditionTB.Items.AddRange(new object[] {
            "Contains",
            "Equals",
            "Find Never",
            "GE",
            "GT",
            "Has Attrib",
            "Has No Attrib",
            "Has No Prop",
            "Has Prop",
            "LE",
            "LT",
            "Not Equal",
            "Same Type",
            "Wildcard",
            "Within Day",
            "Within Week"});
         this.conditionTB.Location = new System.Drawing.Point(368, 33);
         this.conditionTB.Name = "conditionTB";
         this.conditionTB.Size = new System.Drawing.Size(110, 21);
         this.conditionTB.TabIndex = 1;
         // 
         // findButton
         // 
         this.findButton.Location = new System.Drawing.Point(484, 31);
         this.findButton.Name = "findButton";
         this.findButton.Size = new System.Drawing.Size(75, 23);
         this.findButton.TabIndex = 2;
         this.findButton.Text = "&Find";
         this.findButton.UseVisualStyleBackColor = true;
         this.findButton.Click += new System.EventHandler(this.findButton_Click);
         // 
         // Results
         // 
         this.Results.AutoSize = true;
         this.Results.Location = new System.Drawing.Point(6, 59);
         this.Results.Name = "Results";
         this.Results.Size = new System.Drawing.Size(42, 13);
         this.Results.TabIndex = 3;
         this.Results.Text = "Results";
         // 
         // resultsListBox
         // 
         this.resultsListBox.FormattingEnabled = true;
         this.resultsListBox.Location = new System.Drawing.Point(6, 73);
         this.resultsListBox.Name = "resultsListBox";
         this.resultsListBox.Size = new System.Drawing.Size(553, 121);
         this.resultsListBox.TabIndex = 4;
         // 
         // nwsPlaceholder
         // 
         this.nwsPlaceholder.Enabled = true;
         this.nwsPlaceholder.Location = new System.Drawing.Point(7, 20);
         this.nwsPlaceholder.Name = "nwsPlaceholder";
         this.nwsPlaceholder.Size = new System.Drawing.Size(552, 237);
         this.nwsPlaceholder.TabIndex = 0;
         // 
         // toolStrip1
         // 
         this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openFileButton});
         this.toolStrip1.Location = new System.Drawing.Point(0, 0);
         this.toolStrip1.Name = "toolStrip1";
         this.toolStrip1.Size = new System.Drawing.Size(594, 25);
         this.toolStrip1.TabIndex = 2;
         this.toolStrip1.Text = "toolStrip1";
         // 
         // openFileButton
         // 
         this.openFileButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
         this.openFileButton.Image = global::ActiveXFindExample.Properties.Resources.open;
         this.openFileButton.ImageTransparentColor = System.Drawing.Color.Magenta;
         this.openFileButton.Name = "openFileButton";
         this.openFileButton.Size = new System.Drawing.Size(23, 22);
         this.openFileButton.Text = "toolStripButton1";
         this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
         // 
         // attibuteTB
         // 
         this.attibuteTB.Location = new System.Drawing.Point(10, 33);
         this.attibuteTB.Name = "attibuteTB";
         this.attibuteTB.Size = new System.Drawing.Size(115, 20);
         this.attibuteTB.TabIndex = 5;
         // 
         // propertyTB
         // 
         this.propertyTB.Location = new System.Drawing.Point(131, 33);
         this.propertyTB.Name = "propertyTB";
         this.propertyTB.Size = new System.Drawing.Size(115, 20);
         this.propertyTB.TabIndex = 6;
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(10, 17);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(46, 13);
         this.label1.TabIndex = 7;
         this.label1.Text = "Attribute";
         // 
         // valueTB
         // 
         this.valueTB.Location = new System.Drawing.Point(250, 33);
         this.valueTB.Name = "valueTB";
         this.valueTB.Size = new System.Drawing.Size(115, 20);
         this.valueTB.TabIndex = 8;
         // 
         // label2
         // 
         this.label2.AutoSize = true;
         this.label2.Location = new System.Drawing.Point(131, 17);
         this.label2.Name = "label2";
         this.label2.Size = new System.Drawing.Size(46, 13);
         this.label2.TabIndex = 9;
         this.label2.Text = "Property";
         // 
         // label3
         // 
         this.label3.AutoSize = true;
         this.label3.Location = new System.Drawing.Point(249, 17);
         this.label3.Name = "label3";
         this.label3.Size = new System.Drawing.Size(34, 13);
         this.label3.TabIndex = 10;
         this.label3.Text = "Value";
         // 
         // label4
         // 
         this.label4.AutoSize = true;
         this.label4.Location = new System.Drawing.Point(368, 17);
         this.label4.Name = "label4";
         this.label4.Size = new System.Drawing.Size(51, 13);
         this.label4.TabIndex = 11;
         this.label4.Text = "Condition";
         // 
         // Form1
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(594, 503);
         this.Controls.Add(this.toolStrip1);
         this.Controls.Add(this.findControlGroup);
         this.Controls.Add(this.groupBox1);
         this.Name = "Form1";
         this.ShowIcon = false;
         this.ShowInTaskbar = false;
         this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
         this.Text = "Navisworks ActiveX Window";
         this.Load += new System.EventHandler(this.Form1_Load);
         this.groupBox1.ResumeLayout(false);
         this.findControlGroup.ResumeLayout(false);
         this.findControlGroup.PerformLayout();
         this.toolStrip1.ResumeLayout(false);
         this.toolStrip1.PerformLayout();
         this.ResumeLayout(false);
         this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.Label nwsPlaceholder;
      private System.Windows.Forms.GroupBox findControlGroup;
      private System.Windows.Forms.ListBox resultsListBox;
      private System.Windows.Forms.Label Results;
      private System.Windows.Forms.Button findButton;
      private System.Windows.Forms.ComboBox conditionTB;
      private System.Windows.Forms.ToolStrip toolStrip1;
      private System.Windows.Forms.ToolStripButton openFileButton;
      private System.Windows.Forms.Label label4;
      private System.Windows.Forms.Label label3;
      private System.Windows.Forms.Label label2;
      private System.Windows.Forms.TextBox valueTB;
      private System.Windows.Forms.Label label1;
      private System.Windows.Forms.TextBox propertyTB;
      private System.Windows.Forms.TextBox attibuteTB;
   }
}

