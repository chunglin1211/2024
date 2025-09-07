/**
 * \file
 *
 * Represents information about a single sheet in a multi-sheet
 * file.
 *
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
 *
 */

#ifndef LINWCSHEETINFO_HDR
#define LINWCSHEETINFO_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a sheet info.
 *
 * \return Newly created sheet info or NULL on error
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcSheetInfo LI_NWC_API
LiNwcSheetInfoCreate();

/**
 * Destroy a sheetInfo
 *
 * \param sheet Sheet info to destroy
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSheetInfoDestroy(LtNwcSheetInfo sheet);

/**
 * Set the ID of a sheet info.
 *
 * \param sheet sheet to set id of
 * \param sheet_id id to give sheet
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSheetInfoSetId(LtNwcSheetInfo sheet, LtWideString sheet_id);


/**
 * Set the name of a sheet.
 *
 * \param sheet sheet to set user name of
 * \param user_name user_ame to give sheet
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSheetInfoSetUserName(LtNwcSheetInfo sheet, LtWideString user_name);

/**
 * Set the thumbnail file name of a sheet.
 *
 * \param sheet sheet to set thumbnail file name of
 * \param thumbnail_path Thumbnail file name to give sheet
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSheetInfoSetThumbnailFilename(LtNwcSheetInfo sheet, LtWideString thumbnail_path);

/**
 * Add a property of a sheet.
 *
 * \param sheet Sheet to add property to
 * \param attribute The property attribute
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSheetInfoAddPropertyAttribute(LtNwcSheetInfo sheet, LtNwcPropertyAttribute attribute);

/**
 * Defines Sheet type
 */
typedef enum LtNwcSheetType__tag {
   LI_NWC_SHEET_3D,        /** 3D sheet */
   LI_NWC_SHEET_2D,        /** 2D sheet */
} LtNwcSheetType;

/**
 * Set the type of a sheet.
 *
 * \param sheet sheet to set type of
 * \param type Type to give sheet
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSheetInfoSetType(LtNwcSheetInfo sheet, LtNwcSheetType type);


/**
 * Set the guid of a sheet.
 *
 * \param sheet sheet to set guid of
 * \param guid guid to give sheet
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSheetInfoSetGuid(LtNwcSheetInfo sheet, LtNwcGuid guid);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSheetInfo API calls
 *
 * \see LiNwcSheetInfo.h
 */
class LcNwcSheetInfo
{
public:
   //
   // here set default parameter own = false: why?
   // The loader will create a temp thumbnail and will be deleted in LcOpSheet destruction,
   // so here set default parameter own to false, when LcNwcSheetInfo destroy, the m_handle will
   // not be deleted.
   // It look like we should add a reference count to LcOpSheetInfo class, then LiNwcSheetInfoDestroy
   // will not delete the sheet_info, only need to call unref like other classes in this project.
   //
   LcNwcSheetInfo(bool own = false ) : m_handle(LiNwcSheetInfoCreate() ), m_own(own) {}
   ~LcNwcSheetInfo() { if (m_own) LiNwcSheetInfoDestroy(m_handle); }

   operator LtNwcSheetInfo () const { return m_handle; }
   LtNwcSheetInfo GetHandle() const { return m_handle; }

   void SetId(LtWideString id)
   {
      LiNwcSheetInfoSetId(m_handle, id);
   }

   void SetDisplayName(LtWideString name)
   {
      LiNwcSheetInfoSetUserName(m_handle, name);
   }

   void SetThumbnailFilename(LtWideString thumbnail_path)
   {
      LiNwcSheetInfoSetThumbnailFilename(m_handle, thumbnail_path);
   }

   void AddPropertyAttribute(LtNwcPropertyAttribute attribute)
   {
      LiNwcSheetInfoAddPropertyAttribute(m_handle, attribute);
   }

   void SetSheetType(LtNwcSheetType  type)
   {
      LiNwcSheetInfoSetType( m_handle, type);
   }

   void SetGuid(LtNwcGuid guid)
   {
      LiNwcSheetInfoSetGuid( m_handle, guid);
   }

private:
   // Can't copy
   LcNwcSheetInfo(const LcNwcSheetInfo &);
   LcNwcSheetInfo& operator= (const LcNwcSheetInfo &);

   LtNwcSheetInfo m_handle;
   bool m_own;
};

#endif /*__cplusplus*/

#endif /* LINWCSHEETINFO_HDR */
