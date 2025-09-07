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
   partial class clashIgnoreForm
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
         this.label1 = new System.Windows.Forms.Label();
         this.layer1tb = new System.Windows.Forms.TextBox();
         this.layer2tb = new System.Windows.Forms.TextBox();
         this.groupBox1.SuspendLayout();
         this.SuspendLayout();
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.layer2tb);
         this.groupBox1.Controls.Add(this.layer1tb);
         this.groupBox1.Controls.Add(this.label1);
         this.groupBox1.Location = new System.Drawing.Point(13, 13);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(450, 79);
         this.groupBox1.TabIndex = 0;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Configure";
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(39, 20);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(188, 13);
         this.label1.TabIndex = 0;
         this.label1.Text = "Ignore clashes between named layers:";
         // 
         // layer1tb
         // 
         this.layer1tb.Location = new System.Drawing.Point(42, 47);
         this.layer1tb.Name = "layer1tb";
         this.layer1tb.Size = new System.Drawing.Size(185, 20);
         this.layer1tb.TabIndex = 1;
         // 
         // layer2tb
         // 
         this.layer2tb.Location = new System.Drawing.Point(251, 47);
         this.layer2tb.Name = "layer2tb";
         this.layer2tb.Size = new System.Drawing.Size(185, 20);
         this.layer2tb.TabIndex = 2;
         // 
         // clashIgnoreForm
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.ClientSize = new System.Drawing.Size(469, 99);
         this.Controls.Add(this.groupBox1);
         this.MaximizeBox = false;
         this.MinimizeBox = false;
         this.Name = "clashIgnoreForm";
         this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
         this.Text = "Navisworks API - Clash Ignore Rule Plugin Example";
         this.groupBox1.ResumeLayout(false);
         this.groupBox1.PerformLayout();
         this.ResumeLayout(false);

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.Label label1;
      internal System.Windows.Forms.TextBox layer1tb;
      internal System.Windows.Forms.TextBox layer2tb;
   }
}
