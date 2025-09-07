//------------------------------------------------------------------
// NavisWorks Sample code
//------------------------------------------------------------------

// (C) Copyright 2010 by Autodesk Inc.

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
// Demonstrates one method in which, by way of .NET remoting, Navisworks
// can be started through Automation and data can be communicated back
// to the calling program.
//
//------------------------------------------------------------------
using System;
using System.Windows.Forms;
using Autodesk.Navisworks.Api.Resolver;

namespace MessageServer
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
         Application.EnableVisualStyles();
         Application.SetCompatibleTextRenderingDefault(false);
         Application.Run(new MessageServer());
      }
   }
}
