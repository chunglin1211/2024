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
// Example of a clash detective rules plugin
//------------------------------------------------------------------
namespace PluginClashRuleExample
{
   partial class clashIgnoreResultsForm
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
         this.groupBox2 = new System.Windows.Forms.GroupBox();
         this.clashListBox = new System.Windows.Forms.ListBox();
         this.clashesRejectedTB = new System.Windows.Forms.TextBox();
         this.clashesAcceptedTB = new System.Windows.Forms.TextBox();
         this.clashesExaminedTB = new System.Windows.Forms.TextBox();
         this.label4 = new System.Windows.Forms.Label();
         this.label3 = new System.Windows.Forms.Label();
         this.label2 = new System.Windows.Forms.Label();
         this.label1 = new System.Windows.Forms.Label();
         this.label5 = new System.Windows.Forms.Label();
         this.layer2tb = new System.Windows.Forms.TextBox();
         this.layer1tb = new System.Windows.Forms.TextBox();
         this.groupBox2.SuspendLayout();
         this.SuspendLayout();
         // 
         // groupBox2
         // 
         this.groupBox2.Controls.Add(this.layer1tb);
         this.groupBox2.Controls.Add(this.layer2tb);
         this.groupBox2.Controls.Add(this.label5);
         this.groupBox2.Controls.Add(this.label1);
         this.groupBox2.Controls.Add(this.clashListBox);
         this.groupBox2.Controls.Add(this.clashesRejectedTB);
         this.groupBox2.Controls.Add(this.clashesAcceptedTB);
         this.groupBox2.Controls.Add(this.clashesExaminedTB);
         this.groupBox2.Controls.Add(this.label4);
         this.groupBox2.Controls.Add(this.label3);
         this.groupBox2.Controls.Add(this.label2);
         this.groupBox2.Location = new System.Drawing.Point(12, 12);
         this.groupBox2.Name = "groupBox2";
         this.groupBox2.Size = new System.Drawing.Size(450, 137);
         this.groupBox2.TabIndex = 2;
         this.groupBox2.TabStop = false;
         this.groupBox2.Text = "Status";
         // 
         // clashListBox
         // 
         this.clashListBox.FormattingEnabled = true;
         this.clashListBox.Location = new System.Drawing.Point(235, 23);
         this.clashListBox.Name = "clashListBox";
         this.clashListBox.Size = new System.Drawing.Size(201, 95);
         this.clashListBox.TabIndex = 6;
         // 
         // clashesRejectedTB
         // 
         this.clashesRejectedTB.Location = new System.Drawing.Point(120, 101);
         this.clashesRejectedTB.Name = "clashesRejectedTB";
         this.clashesRejectedTB.ReadOnly = true;
         this.clashesRejectedTB.Size = new System.Drawing.Size(100, 20);
         this.clashesRejectedTB.TabIndex = 5;
         // 
         // clashesAcceptedTB
         // 
         this.clashesAcceptedTB.Location = new System.Drawing.Point(120, 80);
         this.clashesAcceptedTB.Name = "clashesAcceptedTB";
         this.clashesAcceptedTB.ReadOnly = true;
         this.clashesAcceptedTB.Size = new System.Drawing.Size(100, 20);
         this.clashesAcceptedTB.TabIndex = 4;
         // 
         // clashesExaminedTB
         // 
         this.clashesExaminedTB.Location = new System.Drawing.Point(120, 58);
         this.clashesExaminedTB.Name = "clashesExaminedTB";
         this.clashesExaminedTB.ReadOnly = true;
         this.clashesExaminedTB.Size = new System.Drawing.Size(100, 20);
         this.clashesExaminedTB.TabIndex = 3;
         // 
         // label4
         // 
         this.label4.AutoSize = true;
         this.label4.Location = new System.Drawing.Point(21, 105);
         this.label4.Name = "label4";
         this.label4.Size = new System.Drawing.Size(85, 13);
         this.label4.TabIndex = 2;
         this.label4.Text = "Clashes rejected";
         // 
         // label3
         // 
         this.label3.AutoSize = true;
         this.label3.Location = new System.Drawing.Point(21, 84);
         this.label3.Name = "label3";
         this.label3.Size = new System.Drawing.Size(92, 13);
         this.label3.TabIndex = 1;
         this.label3.Text = "Clashes accepted";
         // 
         // label2
         // 
         this.label2.AutoSize = true;
         this.label2.Location = new System.Drawing.Point(21, 62);
         this.label2.Name = "label2";
         this.label2.Size = new System.Drawing.Size(92, 13);
         this.label2.TabIndex = 0;
         this.label2.Text = "Clashes examined";
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(21, 24);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(39, 13);
         this.label1.TabIndex = 7;
         this.label1.Text = "Layer1";
         // 
         // label5
         // 
         this.label5.AutoSize = true;
         this.label5.Location = new System.Drawing.Point(21, 43);
         this.label5.Name = "label5";
         this.label5.Size = new System.Drawing.Size(39, 13);
         this.label5.TabIndex = 8;
         this.label5.Text = "Layer2";
         // 
         // layer2tb
         // 
         this.layer2tb.Location = new System.Drawing.Point(120, 38);
         this.layer2tb.Name = "layer2tb";
         this.layer2tb.ReadOnly = true;
         this.layer2tb.Size = new System.Drawing.Size(100, 20);
         this.layer2tb.TabIndex = 9;
         // 
         // layer1tb
         // 
         this.layer1tb.Location = new System.Drawing.Point(120, 19);
         this.layer1tb.Name = "layer1tb";
         this.layer1tb.ReadOnly = true;
         this.layer1tb.Size = new System.Drawing.Size(100, 20);
         this.layer1tb.TabIndex = 10;
         // 
         // clashIgnoreResultsForm
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(470, 153);
         this.Controls.Add(this.groupBox2);
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "clashIgnoreResultsForm";
         this.Text = "Navisworks API  Clash Rule Example : Results";
         this.groupBox2.ResumeLayout(false);
         this.groupBox2.PerformLayout();
         this.ResumeLayout(false);

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox2;
      internal System.Windows.Forms.ListBox clashListBox;
      internal System.Windows.Forms.TextBox clashesRejectedTB;
      internal System.Windows.Forms.TextBox clashesAcceptedTB;
      internal System.Windows.Forms.TextBox clashesExaminedTB;
      private System.Windows.Forms.Label label4;
      private System.Windows.Forms.Label label3;
      private System.Windows.Forms.Label label2;
      internal System.Windows.Forms.TextBox layer1tb;
      internal System.Windows.Forms.TextBox layer2tb;
      private System.Windows.Forms.Label label5;
      private System.Windows.Forms.Label label1;
   }
}
