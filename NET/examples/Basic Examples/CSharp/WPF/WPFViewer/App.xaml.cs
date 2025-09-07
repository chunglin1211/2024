using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Windows;
using Autodesk.Navisworks.Api.Resolver;

namespace WPFViewer
{
   /// <summary>
   /// Interaction logic for App.xaml
   /// </summary>
   public partial class App : Application
   {
     
   }

   public class EntryPoint
   {
      /// <summary>
      /// Application Entry Point.
      /// </summary>
      [System.STAThreadAttribute()]
      [System.Diagnostics.DebuggerNonUserCodeAttribute()]
      [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
      public static void Main()
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
      
      public static void XMain()
      {
         WPFViewer.App app = new WPFViewer.App();
         app.InitializeComponent();
         app.Run();
      }
   }
}
