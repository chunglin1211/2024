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
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;


namespace PluginClashRuleExample
{
    // Identify plugin with a suitable Guid and ProgId
   [ComVisible(true)]
   [ProgId("ADSK.ClashRuleUIPlugin")]
   // Plugin should be derived from "both" InwPlugin and InwExportPlugin
   public class ClashRuleUIPlugin : NavisworksIntegratedAPI21.InwPlugin,
                                   NavisworksIntegratedAPI21.InwClashPlugin
   {
      private NavisworksIntegratedAPI21.InwPlugin_Site m_plugin_site;
      private clashIgnoreForm m_clashIForm;
      private clashIgnoreResultsForm m_clashResultsIForm;
      private int m_clashesExamined;
      private int m_clashesRejected;
      private int m_clashesAccepted;
      private String m_ignore1;
      private String m_ignore2;
      //
      // InwPlugin methods
      //

      public virtual void AdviseSite(NavisworksIntegratedAPI21.InwPlugin_Site plugin_site)
      {
         m_plugin_site = plugin_site;
      }
      public virtual bool iActivate()
      {
         m_clashIForm = new clashIgnoreForm();
         m_clashIForm.layer1tb.Text = "EQUIPMENT";
         m_clashIForm.layer2tb.Text = "CYLINDER36";
         m_clashesExamined = 0;
         m_clashesAccepted = 0;
         m_clashesRejected = 0;
         m_clashIForm.ShowDialog();
         m_ignore1 = m_clashIForm.layer1tb.Text;
         m_ignore2 = m_clashIForm.layer2tb.Text;
         m_clashResultsIForm = new clashIgnoreResultsForm();
         m_clashResultsIForm.Show();
         return true;
      }
      public virtual void iAppInitialising()
      { ;}
      public virtual void iAppTerminating()
      { ;}
      public virtual bool iDeactivate()
      {
         return true;
      }
      public virtual void iDoCustomOption()
      { ;}
      public virtual String iGetDisplayName()
      {
         return "ClashRuleUIPlugin";
      }
      public virtual int iGetNumParameters()
      {
         return 0;
      }
      public virtual String iGetParameter(int ndx, ref object pData)
      {
         return null;
      }
      public virtual bool iSetParameter(int ndx, object newVal)
      {
         return false;
      }
      public virtual object iXtension(object vIn)
      {
         return null;
      }
      public virtual string ObjectName
      {
         get { return "ClashRuleObject"; }
      }
      //
      // InwClashPlugin methods
      //
      public virtual void iBeginTest(ref object data)
      {
      }
      public virtual void iEndTest(ref object data)
      {
      }
      public virtual bool iGetIgnoreDescription(ref string description)
      {
         description = "Clash Ignore Rule Plugin";
         return false;
      }
      public virtual bool iIgnore(NavisworksIntegratedAPI21.InwOaFragment frag1, NavisworksIntegratedAPI21.InwOaFragment frag2, NavisworksIntegratedAPI21.InwOpState p_state)
      {
         String sLayer1 = "";
         String sLayer2="";
         NavisworksIntegratedAPI21.InwOaNode layer1=null;
         NavisworksIntegratedAPI21.InwOaNode layer2 = null;
         NavisworksIntegratedAPI21.InwOaNode node1 = null;
         NavisworksIntegratedAPI21.InwOaNode node2 = null;

         m_clashResultsIForm.clashesExaminedTB.Text = String.Format("{0}", ++m_clashesExamined);
         m_clashResultsIForm.layer1tb.Text = m_ignore1;
         m_clashResultsIForm.layer2tb.Text = m_ignore2;

         foreach (NavisworksIntegratedAPI21.InwOaNode node in frag1.path.Nodes())
         {
            if (node.IsLayer)
            {
               sLayer1 = node.UserName;
               layer1 = node;
               break;
            }
         }
         foreach (NavisworksIntegratedAPI21.InwOaNode node in frag2.path.Nodes())
         {
            if (node.IsLayer)

            {
               sLayer2 = node.UserName;
               layer2 = node;
               break;
            }
         }
         if ((sLayer1.Equals(m_ignore1) && sLayer2.Equals(m_ignore2)) ||
            (sLayer1.Equals(m_ignore2) && sLayer2.Equals(m_ignore1)))
         {
            m_clashResultsIForm.clashesRejectedTB.Text = String.Format("{0}", ++m_clashesRejected);
            node1 = frag1.path.Nodes().Last();
            node2 = frag2.path.Nodes().Last();
            m_clashResultsIForm.clashListBox.Items.Add("CLASH");
            m_clashResultsIForm.clashListBox.Items.Add(String.Format("\t Layer={0}:{1}:{2}", layer1.ClassName, layer1.ClassUserName, layer1.UserName));
            m_clashResultsIForm.clashListBox.Items.Add(String.Format("\t \t Node={0}:{1}:{2}", node1.ClassName, node1.ClassUserName, node1.UserName));
            m_clashResultsIForm.clashListBox.Items.Add(String.Format("\t Layer={0}:{1}:{2}", layer2.ClassName, layer2.ClassUserName, layer2.UserName));
            m_clashResultsIForm.clashListBox.Items.Add(String.Format("\t \t Node={0}:{1}:{2}", node2.ClassName, node2.ClassUserName, node2.UserName));
            m_clashResultsIForm.clashListBox.Refresh();
            return true;
         }
         else
         {
            m_clashResultsIForm.clashesAcceptedTB.Text = String.Format("{0}", ++m_clashesAccepted);
            return false;
         }
      }
      public virtual void InitialisePlugin(ref int capbits, ref int ver)
      {
         capbits = (int)(NavisworksIntegratedAPI21.nwECaps.eCap_CLASH_IGNORE | NavisworksIntegratedAPI21.nwECaps.eCap_CLASH_IGNORE_SLOW);
         ver = 1;
      }
   }
}
