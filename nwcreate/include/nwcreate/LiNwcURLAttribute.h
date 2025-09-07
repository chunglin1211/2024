/**
 * \file
 *
 * An attribute that defines a set of named URLs (hyperlinks).
 * The name and URL are visible in the NavisWorks properties dialog. The
 * link can be followed from the properties dialog or using hyperlink mode.
 *
 * In NavisWorks 2 only one hyperlink per attribute is supported. Multiple
 * links per attribute are supported from NavisWorks 3 onwards.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2001-2002
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCURLATTRIBUTE_HDR
#define LINWCURLATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a URL attribute
 *
 * \return Newly created attribute or NULL on error
 * \version 2.0
 */
LI_NWC_PUBLIC LtNwcURLAttribute LI_NWC_API
LiNwcURLAttributeCreate();

/**
 * Add a named url to the set stored in the attribute. The last URL added
 * will be the default. The URL will be assigned to the "Hyperlink" category
 * by default. If url is NULL or an empty string, the URL will be assigned to
 * the "Tag" category.
 *
 * \param attribute Attribute to add URL for
 * \param name Descriptive name for URL
 * \param url URL
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcURLAttributeAddURL(LtNwcURLAttribute attribute,
                        LtWideString name,
                        LtWideString url);

/**
 * Add a named url and category to the set stored in the attribute.
 * The last URL added will be the default. There are 3 internal
 * category names which have a special meaning for NavisWorks:
 * "LcOaURLCategoryHyperlink" is the predefined "Hyperlink" category,
 * "LcOaURLCategoryTag" is the predefined "Tag" category,
 * "LcOaUserDefURLCategoryInternalName" is the internal name given
 * to all categories defined by the user through the GUI.
 *
 * \param attribute Attribute to add URL for
 * \param name Descriptive name for URL
 * \param url URL
 * \param category_user_name User name of category to assign link to
 * \param category_internal_name Internal name of category to assign link to
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcURLAttributeAddURLEx(LtNwcURLAttribute attribute,
                          LtWideString name,
                          LtWideString url,
                          LtWideString category_user_name,
                          LtString category_internal_name);

/**
 * Adds an attachment point to the last URL added to the attribute.
 *
 * \param attribute Attribute to add attachment point to
 * \param x X component of attachment point.
 * \param y Y component of attachment point.
 * \param z Z component of attachment point.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcURLAttributeAddAttachmentPoint(LtNwcURLAttribute attribute,
                                    LtFloat x,
                                    LtFloat y,
                                    LtFloat z);

/**
 * Destroy a URL attribute
 *
 * \param attribute Attribute to destroy
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcURLAttributeDestroy(LtNwcURLAttribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcURLAttribute API calls
 *
 * \see LiNwcURLAttribute.h
 */
class LcNwcURLAttribute : public LcNwcAttribute
{
public:
   LcNwcURLAttribute() : LcNwcAttribute(LiNwcURLAttributeCreate(), true) {}
   LcNwcURLAttribute(LtNwcURLAttribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcURLAttribute () const
   { return static_cast<LtNwcURLAttribute>(LcNwcAttribute::GetHandle()); }
   LtNwcURLAttribute GetHandle() const
   { return static_cast<LtNwcURLAttribute>(LcNwcAttribute::GetHandle()); }

   void AddURL(LtWideString name, LtWideString url)
   { LiNwcURLAttributeAddURL(GetHandle(), name, url); }

   void AddURLEx(LtWideString name, LtWideString url,
      LtWideString category_user_name, const char* category_internal_name)
   { LiNwcURLAttributeAddURLEx(GetHandle(), name, url,
                               category_user_name, const_cast<LtString>(category_internal_name)); }

   void AddAttachmentPoint(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcURLAttributeAddAttachmentPoint(GetHandle(), x, y, z); }
};

#endif

#endif /* LINWCURLATTRIBUTE_HDR */
