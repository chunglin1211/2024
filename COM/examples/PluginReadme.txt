 To install Navisworks plug-ins, they need to be registered as COM objects
and added to the Navisworks COM plugins list in the registry.

-----------------------------------------------------------------------------

1) To register the plugin as a COM object you must either:

a) Compile the plugin DLL in Visual Studio and this will automatically register the DLL in it's current location.
(So it's vital not to move a registered DLL to a different folder)

or

b) Run nwregasm.bat followed by the name of the plugin DLL to register it.
(e.g. Select "Start" > "Run" and type: nwregasm.bat "c:\program files\Autodesk\Navisworks Manage 2024\api\com\examples\Plugin\PluginSimpleExample\bin\Debug\PluginSimpleExample.dll")


-----------------------------------------------------------------------------

2) To add the plugin to the list of Navisworks com plugins you must manually edit the registry.
Open the key HKLM\SOFTWARE\Autodesk\Navisworks Manage\21.0\COM Plugins and add a string with the
COM progId of the plugin as the name, and no value. For C# plugins this progID can be found specified as an attribute in the code e.g.   [ProgId("ADSK.ClashRuleUIPlugin")]. 

