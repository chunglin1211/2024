//------------------------------------------------------------------
// NavisWorks Sample code
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

Multisheet Loader

Demonstrates:

- Advanced capabilities of the NWcreate C++ wrapper API
- Invoking callbacks to make a multisheet file.
- Making a 3D sheet and a 2D sheet.
- Adding a GUID to a geometry node to uniquely identify that node.
- Use of a BrepProfileBuilder to assist the creation of complex 3D geometry.
- 2D geometry creation.
- Adding a grid to allow visualization of important levels in the model.


Scenario:

Reading parametric descriptions of steel columns from *.mlf files. Each
*.mlf file describes one or more columns in a CSV format. The column is
parametized by its height, a point representing the center of the base
and a GUID which uniquely identifies that column.

The columns can have a circular profile, a square profile, or an I profile. 
The profile can be set in the global options and sets the profile of all 
columns in the file.

The Navisworks model has a 2D sheet and a 3D sheet, so the columns can be
viewed as a 3D model or a 2D plan. The 3D model also has a grid to make it 
easy to visualise important levels, like the height of the columns.

As the geometry depends on whether the columns are being viewed in 2D or 3D, 
and which of the 3 column profiles are chosen in the global options, there 
are a total of 6 different ways in which the column geometry can be created.

2D geometry requires a completely separate set of methods and streams, which 
are demonstrated here. The more complex 3D geometry for the I-shaped column 
uses a BrepProfileProfileBuiler to construct a face which is then extruded 
to form the column.


Usage:

- Solution and project for Microsoft Visual Studio 2012 supplied
- Build 'x64' configuration.

- You need to register the loader plugin with NavisWorks. To do this,
you need to modify the registry. For Navisworks Manage 2015, you would
add a String value containing the path to the DLL into the "NWcreate Loaders"
key, in either of these locations:

Computer\HKEY_CURRENT_USER\Software\Autodesk\Navisworks Manage x64\12.0\NWcreate Loaders
Computer\HKEY_LOCAL_MACHINE\Software\Autodesk\Navisworks Manage x64\12.0\NWcreate Loaders

The name of the String value should be "navisworks_mlf" (to reflect the keys used 
in the NameTable part of the config file), and the data of the value is the full 
path to the DLL, e.g.

C:\Program Files\Autodesk\Navisworks Manage 2015\api\nwcreate\bin\x64\multisheetloader.dll

- Run Navisworks 2015
- Open example.mlf
- Change parameters in the global options and refresh the view
