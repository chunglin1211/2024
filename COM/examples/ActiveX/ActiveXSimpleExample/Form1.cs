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
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace ActiveXSimpleExample
{

   public partial class Form1 : Form
   {
      private NavisworksIntegratedAPI21.nwOpState m_state;
      private NavisworksIntegratedAPI21.nwControlMDI nwsControl;

      public Form1()
      {
         InitializeComponent();
      }

      private void Form1_Load(object sender, EventArgs e)
      {
         // Dynamically create the activex control.
         AxControl host = new AxControl(typeof(NavisworksIntegratedAPI21.nwControlMDIClass).GUID.ToString());
         this.Controls.Add(host);
         this.Controls.SetChildIndex(host,this.Controls.GetChildIndex(nwsPlaceholder));
         host.Location = nwsPlaceholder.Location;
         host.Size = nwsPlaceholder.Size;
         nwsControl = (NavisworksIntegratedAPI21.nwControlMDI)host.GetOcx();
         
         // hook up state.
         m_state = (NavisworksIntegratedAPI21.nwOpState) nwsControl.APIState;
         m_state.EventsEnabled = true;
      }
 
      private void OpenFileButton_Click(object sender, EventArgs e)
      {
         OpenFileDialog fileDialog = new OpenFileDialog();
         fileDialog.Filter = "NWD files|*.nwd";
         fileDialog.Title = "Open Navisworks Document";
         DialogResult result = fileDialog.ShowDialog();
         if (result == DialogResult.OK)
         {
            string filename = fileDialog.FileName;
            nwsControl.SRC = filename;
            nwsControl.APIState.CurrentView.ViewPoint.Paradigm = NavisworksIntegratedAPI21.nwEParadigm.eParadigm_APPLICATION;
            updateAnimList();
         }
      }

      private void beginButton_Click(object sender, EventArgs e)
      {
         nwsControl.AnimationCommand(NavisworksIntegratedAPI21.nwEAnimationCmd.eCmd_Rewind);
      }

      private void playBackwardsButton_Click(object sender, EventArgs e)
      {
         nwsControl.AnimationCommand(NavisworksIntegratedAPI21.nwEAnimationCmd.eCmd_ReversePlay);
      }

      private void pauseButton_Click(object sender, EventArgs e)
      {
         nwsControl.AnimationCommand(NavisworksIntegratedAPI21.nwEAnimationCmd.eCmd_Pause);

      }

      private void stopButton_Click(object sender, EventArgs e)
      {
         nwsControl.AnimationCommand(NavisworksIntegratedAPI21.nwEAnimationCmd.eCmd_Stop);
      }

      private void playForwardsButton_Click(object sender, EventArgs e)
      {
         nwsControl.AnimationCommand(NavisworksIntegratedAPI21.nwEAnimationCmd.eCmd_Play);
      }

      private void endButton_Click(object sender, EventArgs e)
      {
         nwsControl.AnimationCommand(NavisworksIntegratedAPI21.nwEAnimationCmd.eCmd_FForward);
      }

      private void recordButton_Click(object sender, EventArgs e)
      {
         nwsControl.AnimationCommand(NavisworksIntegratedAPI21.nwEAnimationCmd.eCmd_Record);
      }
      private void updateAnimList()
      {
         savedAnimationsListBox.Items.Clear();
         foreach (NavisworksIntegratedAPI21.InwOpSavedView savedView in m_state.SavedViews())
         {
            if (savedView.ObjectName.Equals("nwOpAnimView"))
            {
               savedAnimationsListBox.Items.Add(savedView.name);
            }
         }
      }
      private void addButton_Click(object sender, EventArgs e)
      {
         NavisworksIntegratedAPI21.InwOpAnimView anim = m_state.CurrentAnimation.Copy() as NavisworksIntegratedAPI21.InwOpAnimView;
         Form form = new Form();
         Label label = new Label();
         TextBox textBox = new TextBox();
         Button buttonOk = new Button();
         Button buttonCancel = new Button();

         form.Text = "Add Animation";
         label.Text = "Enter name for new animation";
         textBox.Text = "";

         buttonOk.Text = "OK";
         buttonCancel.Text = "Cancel";
         buttonOk.DialogResult = DialogResult.OK;
         buttonCancel.DialogResult = DialogResult.Cancel;

         label.SetBounds(9, 20, 372, 13);
         textBox.SetBounds(12, 36, 372, 20);
         buttonOk.SetBounds(228, 72, 75, 23);
         buttonCancel.SetBounds(309, 72, 75, 23);

         label.AutoSize = true;
         textBox.Anchor = textBox.Anchor | AnchorStyles.Right;
         buttonOk.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
         buttonCancel.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;

         form.ClientSize = new Size(396, 107);
         form.Controls.AddRange(new Control[] { label, textBox, buttonOk, buttonCancel });
         form.ClientSize = new Size(Math.Max(300, label.Right + 10), form.ClientSize.Height);
         form.FormBorderStyle = FormBorderStyle.FixedDialog;
         form.StartPosition = FormStartPosition.CenterScreen;
         form.MinimizeBox = false;
         form.MaximizeBox = false;
         form.AcceptButton = buttonOk;
         form.CancelButton = buttonCancel;

         DialogResult dialogResult = form.ShowDialog();
         anim.name = textBox.Text;
         // The animations are stored in saved views. 
         m_state.SavedViews().Add(anim);
         updateAnimList();
      }

      // Retreieve the saved view and set current animation
      private void savedAnimationsListBox_Click(object sender, EventArgs e)
      {
         int idx = savedAnimationsListBox.SelectedIndex;
         if (idx >= 0)
         {
            int animIdx = 0;
            int sIdx = 0;
            bool finished = false;
            do
            {
               NavisworksIntegratedAPI21.InwOpSavedView sView = m_state.SavedViews()[sIdx+1] as NavisworksIntegratedAPI21.InwOpSavedView;
               if (sView.ObjectName.Equals("nwOpAnimView"))
               {
                  if (animIdx == idx)
                  {
                     NavisworksIntegratedAPI21.InwOpAnimView animView = sView.Copy() as NavisworksIntegratedAPI21.InwOpAnimView;
                     m_state.CurrentAnimation = animView;
                     finished = true;
                  }
                  else
                     animIdx++;
               }
               sIdx++;
            } while (!finished);
         }
      }
   }

   public class AxControl : AxHost
   {
      public AxControl(string strCLSID)
         : base(strCLSID)
      {
      }
   }

}
