/**
 * \file
 *
 * Represents information about a multi-sheet file.
 *
 * Contains attributes about the file as a whole, as well as
 * information on each sheet in the file.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2010 Autodesk, Inc.  All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 */

#ifndef LINWCFILEINFO_HDR
#define LINWCFILEINFO_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Add a property of a file info.
 *
 * \param file_info File Info to add property to
 * \param attribute The property attribute
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFileInfoAddPropertyAttribute(LtNwcFileInfo file_info, LtNwcPropertyAttribute attribute);


/**
 * Add a sheet info to file info.
 *
 * \param file_info File Info
 * \param sheet_info Sheet info
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFileInfoAddSheetInfo(LtNwcFileInfo file_info, LtNwcSheetInfo sheet_info);


/**
 * Set the current sheet id to file info.
 *
 * \param file_info File info to set current sheet id
 * \param sheet_id current sheet id to file info
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFileInfoSetCurrentSheetId(LtNwcFileInfo file_info, LtWideString sheet_id);

/**
 * Set the guid to file info.
 *
 * \param file_info File info to set guid
 * \param guid guid to file info
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFileInfoSetGuid(LtNwcFileInfo file_info, LtNwcGuid guid);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcFileInfo API calls
 *
 * \see LiNwcFileInfo.h
 */
class LcNwcFileInfo
{
public:
   LcNwcFileInfo(LtNwcFileInfo handle)
      : m_handle(handle) { }

   operator LtNwcFileInfo () const { return m_handle; }
   LtNwcFileInfo GetHandle() const { return m_handle; }

   void AddSheet(LtNwcSheetInfo sheet)
   {
      LiNwcFileInfoAddSheetInfo(m_handle, sheet);
   }

   void AddPropertyAttribute(LtNwcPropertyAttribute attribute)
   {
      LiNwcFileInfoAddPropertyAttribute(m_handle, attribute);
   }

   void SetCurrentSheetId(LtWideString sheet_id)
   {
      LiNwcFileInfoSetCurrentSheetId(m_handle, sheet_id);
   }

   void SetGuid(LtNwcGuid guid)
   {
      LiNwcFileInfoSetGuid(m_handle, guid);
   }


private:
   // Can't copy
   LcNwcFileInfo(const LcNwcFileInfo &);
   LcNwcFileInfo& operator= (const LcNwcFileInfo &);

   LtNwcFileInfo m_handle;
};

#endif /*__cplusplus*/

#endif /* LINWCFILEINFO_HDR */
