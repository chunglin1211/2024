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

#include "ColumnSpec.h"

LtNwcLoadStatus ColumnSpec::LoadFromFile(LtWideString pathname, std::vector<ColumnSpec> &columns)
{
   std::wstring height_str;
   std::wstring x_str;
   std::wstring y_str;
   std::wstring z_str;
   std::wstring guid;

   std::wifstream file(pathname);

   if (!file.is_open())
      return LI_NWC_LOAD_CANT_OPEN;

   while(file.good())
   {
      std::getline(file, height_str, L',');
      std::getline(file, x_str, L',');
      std::getline(file, y_str, L',');
      std::getline(file, z_str, L',');
      std::getline(file, guid);

      LtFloat height = wcstod(height_str.c_str(), NULL);

      LtPoint base = {
         wcstod(x_str.c_str(), NULL),
         wcstod(y_str.c_str(), NULL),
         wcstod(z_str.c_str(), NULL) };

      ColumnSpec col = ColumnSpec(height, base, guid);
      columns.push_back(col);
   }

   file.close();

   return LI_NWC_LOAD_OK;
}