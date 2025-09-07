//------------------------------------------------------------------
// NavisWorks Sample code
//------------------------------------------------------------------
//
// (C) Copyright 2008 by Autodesk Inc.
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

Loader

Demonstrates:

- Use of NWcreate C++ wrapper API
- Use of NWcreate API in a NavisWorks file loader
- Use of loader configuration file (loader.cfg)
- Use of loader parameters
- Invoking a progress callback
- Geometry creation by callback or direct
- Use of facetted surface geometry stream primitives
- Use of scene completion callback


Scenario:

Reading parametric descriptions of "widgets" from *.lf files. Each *.lf
file describes a single widget that is designed to hold onto a cylinder
tightly. The rough outline of a widget is shown below. The widget is
parametized by inner radius, outer radius, arm length and thickness.

             |  Arm length
             +
              \
 inner radius  | outer radius
              /
             +
             |

The widget geometry is generated from the parameters using the facetted
surface primitives defined for geometry streams. The geometry stream
settings that control the facetting process are exposed as loader 
parameters, together with a boolean that controls whether an example
cylinder is displayed for the widget to grip.

To make things more interesting the widget also has an elliptical hole
drilled through it.


Usage:

- Solution and project for Microsoft Visual Studio 2012 supplied
- Build 'x64' configuration.

- You need to register the loader plugin with NavisWorks. To do this,
you need to modify the registry. For Navisworks Manage 2015, you would
add a String value containing the path to the DLL into the "NWcreate Loaders"
key,  in either of these locations:

Computer\HKEY_CURRENT_USER\Software\Autodesk\Navisworks Manage x64\12.0\NWcreate Loaders
Computer\HKEY_LOCAL_MACHINE\Software\Autodesk\Navisworks Manage x64\12.0\NWcreate Loaders


The name of the String value should be "navisworks_lf" (to reflect the keys used 
in the NameTable part of the config file), and the data of the value is the full 
path to the DLL, e.g.

C:\Program Files\Autodesk\Navisworks Manage 2015\api\nwcreate\bin\x64\loader.dll

- Run Navisworks 2015
- Open example.lf
- Change parameters in the global options and refresh the view
