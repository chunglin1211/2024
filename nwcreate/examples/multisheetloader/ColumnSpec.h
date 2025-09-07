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

#ifndef COLUMN_HDR
#define COLUMN_HDR
#pragma once

#include <vector>
#include <fstream>
#include <sstream>

#include <nwcreate/LiNwcAll.h>

enum ColumnProfile
{
   eCIRCLE,
   eSQUARE,
   eIBEAM
};

class ColumnSpec
{
public:
   ColumnSpec() {}
   ColumnSpec(LtFloat height, LtPoint base, std::wstring guid) 
   {
      m_height = height;
      for (int i = 0; i < 3; i++)
         m_base[i] = base[i];
      m_guid = guid;
   }

   LtFloat GetHeight() 
   {
      return m_height;
   }
   void GetCenter(LtPoint &ret)
   {
      for (int i = 0; i < 3; i++)
         ret[i] = m_base[i];
   }
   std::wstring GetGuid() 
   {
      return m_guid;
   }

   static ColumnProfile m_profile;
   static LtNwcLoadStatus LoadFromFile(LtWideString pathname, std::vector<ColumnSpec> &columns);
private:
   LtFloat m_height;
   LtPoint m_base;
   std::wstring m_guid;
};

#endif // COLUMN_HDR
