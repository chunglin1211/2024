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

Gecko

Demonstrates:

- Use of NWcreate C++ wrapper API
- Use of NWcreate API in a standalone NavisWorks file exporter
- Creation of a node hierarchy with layers, instances, groups 
  and geometry
- Use of material, transform and text attributes
- Geometry creation by callback or direct
- Use of polygonal geometry stream primitives
- Use of saved view


Scenario:

Export of files from "SpaceCAD" space ship design system. SpaceCAD
assembles ships out of parts and then allows an assembly hierarchy of
ship instances to be created. Each ship has a description and armaments
property.


Usage:

- Solution and project for Microsoft Visual Studio 2012 supplied
- Build 'x64' configuration.
- Run
- Generates gecko.nwc in the root of the gecko  project directory.
- Open gecko.nwc in NavisWorks 2015
