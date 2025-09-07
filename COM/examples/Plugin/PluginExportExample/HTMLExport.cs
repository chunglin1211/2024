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
// Navisworks API Exporter to send clash results to a HTML report
//------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;

namespace PluginExportExample
{
   // Identify plugin with a suitable Guid and ProgId
   [ComVisible(true)]
   [Guid("7686764F-D1EC-44D0-ABD8-453445768C6E")]
   [ProgId("ADSK.HTMLExportPlugin")]

   // Plugin should be derived from "both" InwPlugin and InwExportPlugin
   public class HTMLExportPlugin : NavisworksIntegratedAPI21.InwPlugin,
                                   NavisworksIntegratedAPI21.InwExportPlugin
   {
       public static class ImageUtilities
      {
         public static object ConvertFromIPicture(object image)
         {
            return ImageOLEConverter.Instance.ConvertFromIPicture(image);
         }

         private class ImageOLEConverter : AxHost
         {
            public static readonly ImageOLEConverter Instance = new
            ImageOLEConverter();

            private ImageOLEConverter()
               : base(Guid.Empty.ToString())
            {
            }

            public object ConvertFromIPicture(object image)
            {
               return AxHost.GetPictureFromIPicture(image);
            }
         }
      }

      private NavisworksIntegratedAPI21.InwPlugin_Site m_plugin_site;
      private NavisworksIntegratedAPI21.InwOpClashElement m_clash;


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
         return "HTMLExportPlugin";
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
         get { return "HTMLExportPluginObject"; }
      }
      //
      // InwExportPlugin methods
      //
      public virtual void iBeginContext(NavisworksIntegratedAPI21.InwOpState p_state)
      {
      }
      public virtual bool iCanExport(NavisworksIntegratedAPI21.InwOpState p_state, int reason)
      {
         foreach (dynamic d_plugin in p_state.Plugins())
         {
            m_clash = d_plugin as NavisworksIntegratedAPI21.InwOpClashElement;
            if (m_clash != null)
               break;
         }
         if (m_clash == null)
            throw new System.NullReferenceException("Clash Detective not found");

         return (m_clash.Tests().Count>0);
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
         doDatabaseExport(p_state, Progress);

         return NavisworksIntegratedAPI21.nwEExportStatus.eExport_OK;
      }
      private void doDatabaseExport(NavisworksIntegratedAPI21.InwOpState p_state, NavisworksIntegratedAPI21.InwOpProgress Progress)
      {
         foreach (dynamic d_plugin in p_state.Plugins())
         {
            m_clash = d_plugin as NavisworksIntegratedAPI21.InwOpClashElement;
            if (m_clash != null)
               break;
         }
         if (m_clash == null)
            throw new System.NullReferenceException("Clash Detective not found");
         if (Progress != null)
         {
            Progress.Progress(0);
         }
         SaveFileDialog fileDialog = new SaveFileDialog();
         fileDialog.Filter = "HTML files|*.html";
         fileDialog.Title = "Export HTML file";
         DialogResult result = fileDialog.ShowDialog();
         if (result == DialogResult.OK)
         {
            String filename = fileDialog.FileName;
            String directory = filename.Substring(0, filename.LastIndexOf("\\"));
            HTMLMaker html = new HTMLMaker();
            html.StartHTML();
            html.AddTitle(String.Format("Clashes detected in {0}", p_state.CurrentPartition.filename));
            OpenFileDialog styleSheetDlg = new OpenFileDialog();
            styleSheetDlg.Filter = "Cascading Stylesheet|*.css";
            styleSheetDlg.Title = "Open Cascading Stylesheet";
            DialogResult css_result = styleSheetDlg.ShowDialog();
            if (css_result == DialogResult.OK)
            {
               html.AddStyleSheet(styleSheetDlg.FileName);
               html.AddHeadline(String.Format("Clashes detected in {0}", p_state.CurrentPartition.filename));

               foreach(NavisworksIntegratedAPI21.InwOclClashTest test in m_clash.Tests())
               {
                  html.AddSubHeading(test.name);
                  html.AddParagraph(String.Format("Tolerance:{0}", test.Tolerance));
                  html.AddParagraph(String.Format("Clashes:{0}", test.results().Count));
                  html.AddParagraph(String.Format("New Clashes:{0}", test.NumNewResults));
                  foreach(NavisworksIntegratedAPI21.InwOclTestResult clash in test.results())
                  {
                     NavisworksIntegratedAPI21.InwNvViewPoint nv;
                     try
                     {
                        nv = clash.ViewPoint;
                     }
                     catch (System.Runtime.InteropServices.COMException)
                     {
                        nv = clash.GetSuitableViewPoint();
                     }
                     html.AddParagraphHeading(clash.name);
                     NavisworksIntegratedAPI21.InwOpAnonView anon = p_state.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOpAnonView) as NavisworksIntegratedAPI21.InwOpAnonView;
                     anon.ViewPoint = nv;
                     System.Drawing.Image pd = ImageUtilities.ConvertFromIPicture(p_state.CreatePicture(anon, Type.Missing, 320, 200) as object) as System.Drawing.Image;
                     String picturePath = String.Format("{0}\\{1}__{2}.bmp",directory, test.name, clash.name);
                     pd.Save(picturePath);
                     html.AddImage(picturePath,String.Format("view of {0}", clash.name));

                     html.AddParagraph(String.Format("Status: {0}",clash.status));
                     html.AddParagraph(String.Format("Distance: {0}", clash.distance));
                     html.AddParagraph(String.Format("Found: {0}", clash.CreatedTime as String));
                     if (clash.ApprovedBy.Length > 0)
                     {
                        html.AddParagraph(String.Format("Approved by: {0}", clash.ApprovedBy));
                        html.AddParagraph(String.Format("Approved time: {0}", clash.ApprovedTime as String));
                     }
                     foreach(NavisworksIntegratedAPI21.InwOpComment comment in clash.Comments())
                     {
                        html.AddParagraph(comment.Body);
                     }
                     html.AddParagraph(String.Format("Clash location: {0}, {1}, {2}", clash.Pt1.data1, clash.Pt1.data2, clash.Pt2.data3));

                     if (Progress != null)
                     {
                          
                     }
                  }
               }

               using (StreamWriter outfile = new StreamWriter(filename))
                 {
                     outfile.Write(html.GetHTML());
                 }
            }

         }


      }
      public virtual string iGetFormatName()
      {
         return "Com HTMLExportplugin1 FN";
      }
      public virtual string iGetFormatSuffix()
      {
         return "Com HTMLExportplugin1 FS";
      }
      public virtual string iGetUserString()
      {
         // This is the identifying string that will appear
         // in the context menu.
         return "ADSK Example - HTML Export";
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
