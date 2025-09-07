'------------------------------------------------------------------
' Navisworks Sample code
'------------------------------------------------------------------
'
' (C) Copyright 2008 by Autodesk Inc.
'
' Permission to use, copy, modify, and distribute this software in
' object code form for any purpose and without fee is hereby granted, 
' provided that the above copyright notice appears in all copies and 
' that both that copyright notice and the limited warranty and
' restricted rights notice below appear in all supporting 
' documentation.
'
' AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
' AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
' MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK 
' DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
' UNINTERRUPTED OR ERROR FREE.
'------------------------------------------------------------------
' Navisworks API - AutoSimpleScriptExample - Script Automation
' Example of using the Navisworks API with VB script file
'------------------------------------------------------------------

'TODO: The filename needs setting to a suitable .nwd file.

'create new document
set navis_doc=CreateObject("Navisworks.Document")	

'make sure it's visible	
navis_doc.visible=true	

'open document
navis_doc.OpenFile("C:\Program Files\Autodesk\Navisworks Manage 2024\API\COM\examples\gatehouse.nwd")

'set current view to first saved view
navis_doc.state.currentview=navis_doc.state.savedviews(1).anonview

'make sure app stays open with no refs
navis_doc.stayopen

  
