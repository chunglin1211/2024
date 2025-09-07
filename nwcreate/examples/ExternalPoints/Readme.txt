Autodesk NavisWorks NWcreate API - ExternalPoints Example
=========================================================

This example demonstrates how to connect Navisworks to an external point cloud engine. The example generates a points
in a cube on demand. In a real implementation the points would be loaded from a file or other location by the external
engine.

1. Build
--------

Load the "ExternalPoints.sln" solution into Visual Studio 2012 and build. You will normaly want to do an x64 build.


2. Register
-----------

You need to register the loader plugin with NavisWorks. To do this,
you need to modify the registry. For Navisworks Manage 2015 you would
add a String value containing the path to the DLL into the "NWcreate Loaders"
key, which is stored at:

Computer\HKEY\Software\Autodesk\Navisworks Manage x64\12.0\NWcreate Loaders

where HKEY is either HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE.

The name of the String value should be "ExternalPoints", and
the data of the value is the full path to the DLL, e.g.

C:\Program Files\Autodesk\Navisworks Manage 2015\api\nwcreate\bin\x64\ExternalPoints.dll


3. Use
------

You should then be able to start up Navisworks, and from the File | Open
dialog box select "External Points" and load the Example.externalpoints file.
