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
// An export plugin to generate an CSV file containing a list of top
// level viewpoints
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;


namespace PluginCSVExportExample
{
   // Identify plugin with a suitable Guid and ProgId
   [ComVisible(true)]
   [Guid("3C306438-A1F1-40AC-8BF1-67BB16577CF2")]
   [ProgId("ADSK.CSVExportExamplePlugin")]

   // Plugin should be derived from "both" InwPlugin and InwExportPlugin
   public class CSVExportExamplePlugin : NavisworksIntegratedAPI21.InwPlugin,
                                   NavisworksIntegratedAPI21.InwExportPlugin
   {
      private NavisworksIntegratedAPI21.InwPlugin_Site m_plugin_site;


      //
      // InwPlugin methods
      //

      public virtual void AdviseSite(NavisworksIntegratedAPI21.InwPlugin_Site plugin_site)
      {
         m_plugin_site = plugin_site;
      }
      public virtual bool iActivate()
      {
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
         return "CSVExportExamplePlugin";
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
         get { return "CSVExportExamplePluginObject"; }
      }
      //
      // InwExportPlugin methods
      //
      public virtual void iBeginContext(NavisworksIntegratedAPI21.InwOpState p_state)
      {
      }
      public virtual bool iCanExport(NavisworksIntegratedAPI21.InwOpState p_state, int reason)
      {
         return true;
      }
      public virtual bool iDialog(NavisworksIntegratedAPI21.InwOpState p_state, int reason)
      {
         return true;
      }
      public virtual void iEndContext(NavisworksIntegratedAPI21.InwOpState p_state)
      {
      }
      public virtual NavisworksIntegratedAPI21.nwEExportStatus iExport(NavisworksIntegratedAPI21.InwOpState p_state, int reason, string filename, NavisworksIntegratedAPI21.InwOpProgress Progress)
      {
         if (Progress != null)
         {
            for (int pp = 0; pp < 10; pp++)
            {
               System.Threading.Thread.Sleep(1000);
               Progress.Progress((double)(10.0 / (double)pp));
            }
         }
         doCSVExport(p_state, Progress);

         return NavisworksIntegratedAPI21.nwEExportStatus.eExport_OK;
      }
      private void doCSVExport(NavisworksIntegratedAPI21.InwOpState p_state, NavisworksIntegratedAPI21.InwOpProgress Progress)
      {
         SaveFileDialog fileDialog = new SaveFileDialog();
         fileDialog.Filter = "CSV files|*.csv";
         fileDialog.Title = "Export CSV file";
         DialogResult result = fileDialog.ShowDialog();
         if (result == DialogResult.OK)
         {
            string filename = fileDialog.FileName;
            StreamWriter writer = new StreamWriter(filename);
            foreach (var sv in p_state.SavedViews())
            {
               NavisworksIntegratedAPI21.InwOpView op_view = sv as NavisworksIntegratedAPI21.InwOpView;
               if (op_view != null)
                  writer.WriteLine(String.Format("Viewpoint:{0}", op_view.name));
            }
            writer.Close();
         }


      }
      public virtual string iGetFormatName()
      {
         return "Com CSVExportplugin1 FN";
      }
      public virtual string iGetFormatSuffix()
      {
         return "Com CSVExportplugin1 FS";
      }
      public virtual string iGetUserString()
      {
         // This is the identifying string that will appear
         // in the context menu.
         return "ADSK Example - CSV Export";
      }
      public virtual bool iHelpExport()
      {
         return false;
      }
      public virtual void InitialisePlugin(ref int capbits, ref int ver)
      {
         // Identify the plugin as a plugin context menu item.
         NavisworksIntegratedAPI21.nwECaps cb = NavisworksIntegratedAPI21.nwECaps.eCap_EXPORT_EXPLICIT | NavisworksIntegratedAPI21.nwECaps.eCap_EXPORT_CONTEXT_ITEM;
         capbits = (int)cb;
      }
   }
}
