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
' Navisworks API - AutoPublishScriptExample - Script Automation
' Example of using the Publish API with VB script file
' Takes an input file and creates an expiring published output file
'------------------------------------------------------------------
'Usage:
'AutoPublishScriptExample.vbs <input_filename> <output_filename> <title> <password> <expiry date: dd/mm/yyyy>
'example:
'AutoPublishScriptExample.vbs "c:\temp\in.nwc" "c:\temp\out.nwd" "title" "password" "28/07/2013"
'------------------------------------------------------------------

option explicit

dim roamer
dim attrib
dim ndx
dim arg_in
dim arg_out
dim arg_title
dim arg_password 
dim flags
dim arg_expiry
dim expiry
dim count

count=WScript.Arguments.Count

arg_in=WScript.Arguments(0)
arg_out=WScript.Arguments(1)
arg_title=WScript.Arguments(2)
arg_password=WScript.Arguments(3)
arg_expiry=WScript.Arguments(4)

expiry=CDate(arg_expiry)

'create roamer via automation
set roamer=createobject("navisWorks.document")	

'open input file
roamer.openfile arg_in

'create publishing attribute
ndx=roamer.state.getenum("eObjectType_nwOaPublishAttribute")
set attrib=roamer.state.objectFactory(ndx)

'set publishing properties
attrib.title=arg_title
attrib.password=arg_password
attrib.expirydate=expiry

flags=attrib.flags
ndx=roamer.state.getenum("ePublishFlag_DISPLAY_ON_OPEN")
flags=flags or ndx
attrib.flags=flags


'write output file
roamer.publishfile arg_out,attrib


  
