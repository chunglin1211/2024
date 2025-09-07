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
// Navisworks API - Plugin Property Database Link Example
// Provides a plugin to NavisWorks that connects to an external 
// database and uses the name of the part to associate 
// fields in the database with the item's properties list.
//------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;


namespace PropertyDatabaseLinkPlugin
{

   // Identify plugin with a suitable Guid and ProgId
   [ComVisible(true)]
   [ProgId("ADSK.DatabaseLink")]
   // Plugin should be derived from "both" InwPlugin and InwPropertyPlugin2
   public class PropertyDatabaseLinkPlugin : NavisworksIntegratedAPI21.InwPlugin,
                                   NavisworksIntegratedAPI21.InwPropertyPlugin2
   {
      private NavisworksIntegratedAPI21.InwPlugin_Site m_plugin_site;
      private CADOLink m_dblink;

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
      {
         // On startup the application will ask for 
         // a suitable access database.
         m_dblink = new CADOLink();
         OpenFileDialog fileDialog = new OpenFileDialog();
         fileDialog.Filter = "MDB files|*.mdb";
         fileDialog.Title = "Access Database";
         DialogResult result = fileDialog.ShowDialog();
         if (result == DialogResult.OK)
         {
            string filename = fileDialog.FileName;
            m_dblink.connect(filename);  
         }

      }
      public virtual void iAppTerminating()
      {
         m_dblink.close();
      }
      public virtual bool iDeactivate()
      {
         return true;
      }
      public virtual void iDoCustomOption()
      { ;}
      public virtual String iGetDisplayName()
      {
         return "PropertyDatabaseLinkPlugin";
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
         get { return "PropertyDatabaseLinkPluginObject"; }
      }
      //
      // InwPropertyPlugin2 methods
      //
      public virtual bool iCanAdd(NavisworksIntegratedAPI21.InwOaPath path, NavisworksIntegratedAPI21.InwOpState State)
      {
         return true;
      }
      public virtual string iGetClassName()
      {
         return "propertyDB.CN";
      }
      public virtual string iGetClassUserName()
      {
         return "Access DB Link";
      }
      public virtual string iName(NavisworksIntegratedAPI21.InwOaAttribute attrib, NavisworksIntegratedAPI21.InwOaPath path, NavisworksIntegratedAPI21.InwOpState State)
      {
         return "DBLink";
      }
      public virtual void InitialisePlugin(ref int capbits, ref int ver)
      {
         // Identify the plugin as a plugin context menu item.
         NavisworksIntegratedAPI21.nwECaps cb = NavisworksIntegratedAPI21.nwECaps.eCap_PROPERTY2_CLASS | NavisworksIntegratedAPI21.nwECaps.eCap_PROPERTY2_PROPS | NavisworksIntegratedAPI21.nwECaps.eCap_PROPERTY2_ADD;
         capbits = (int)cb;
      }
      public virtual void iProps(NavisworksIntegratedAPI21.InwOaPropertyColl display_props, NavisworksIntegratedAPI21.InwOaAttribute attrib, NavisworksIntegratedAPI21.InwOaPath path, NavisworksIntegratedAPI21.InwOpState State)
      {
         // Add finish date and notes fields to the properties fields. 
         if ((path.Nodes().Last() as NavisworksIntegratedAPI21.InwOaNode).IsLayer)
         {
            NavisworksIntegratedAPI21.InwOaProperty prop1 = State.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOaProperty) as NavisworksIntegratedAPI21.InwOaProperty;
            NavisworksIntegratedAPI21.InwOaProperty prop2 = State.ObjectFactory(NavisworksIntegratedAPI21.nwEObjectType.eObjectType_nwOaProperty) as NavisworksIntegratedAPI21.InwOaProperty;
            prop1.name = "Prop1";
            prop1.UserName = "Finish Date";
            object linkVal = m_dblink.read("Finish", (path.Nodes().Last() as NavisworksIntegratedAPI21.InwOaNode).UserName);
            if (linkVal != null)
            {
               prop1.value = linkVal;
               display_props.Add(prop1);
            }

            prop2.name = "Prop2";
            prop2.UserName = "Notes";
            linkVal = m_dblink.read("Notes", (path.Nodes().Last() as NavisworksIntegratedAPI21.InwOaNode).UserName);
            if (linkVal != null)
            {
               prop2.value = linkVal;
               display_props.Add(prop2);
            }
         }
      }
   }
}
