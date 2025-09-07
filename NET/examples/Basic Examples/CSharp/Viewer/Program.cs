//------------------------------------------------------------------
// NavisWorks Sample code
//------------------------------------------------------------------

// (C) Copyright 2009 by Autodesk Inc.

// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted,
// provided that the above copyright notice appears in all copies and
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting
// documentation.

// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS.
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//------------------------------------------------------------------
//
// This sample demonstrates a basic Viewer for Navisworks files using
// the Controls part of the API
//
//------------------------------------------------------------------
#region Viewer
using System;
using System.Windows.Forms;
using Autodesk.Navisworks.Api.Controls;
using Autodesk.Navisworks.Api.Resolver;

namespace Viewer
{
   static class Program
   {
      /// <summary>
      /// The main entry point for the application.
      /// </summary>
      [STAThread]
      static void Main()
      {
         // The "Navisworks.Autodesk.Resolver" assembly should be included in your installation.
         // Other Navisworks.Autodesk.*" assemblies will be resolved at runtime,
         // and thus should not be included.
         // Autodesk.Navisworks.Controls controls usage inside the VS Designer is deprecated, and instead they should be created dynamically.
         String runtimeName = Resolver.TryBindToRuntime(RuntimeNames.Any);
         if (String.IsNullOrEmpty(runtimeName))
         {
            throw new Exception("Failed to bind to Navisworks runtime");
         }
         XMain();
      }

      static void XMain()
      {
         //Set to single document mode
         Autodesk.Navisworks.Api.Controls.ApplicationControl.ApplicationType = ApplicationType.SingleDocument;

         //Initialise the api
         Autodesk.Navisworks.Api.Controls.ApplicationControl.Initialize();

         Application.EnableVisualStyles();
         Application.SetCompatibleTextRenderingDefault(false);
         Application.Run(new Viewer());

         //Finish use of the API.
         Autodesk.Navisworks.Api.Controls.ApplicationControl.Terminate();
      }

   }
}
#endregion
