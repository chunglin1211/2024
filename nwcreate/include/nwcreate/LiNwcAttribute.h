/**
 * \file
 *
 * Base type for attributes of Attributes. Attributes are things like
 * transforms and materials that change the behaviour of Attributes. Attributes
 * are inherited down the logical structure from group to child.
 *
 * Attributes may be added to more than one node, allowing reuse of common
 * properties.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2001
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCATTRIBUTE_HDR
#define LINWCATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set the name of an attribute. Should
 * be the name that a CAD user would use to identify an attribute in the
 * original CAD system. e.g. "Red", "Brick".
 *
 * \param attribute attribute to set name of
 * \param name Name to give attribute
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAttributeSetName(LtNwcAttribute attribute, LtWideString name);

/**
 * Set the class of an attribute.
 * Should be the name that a CAD user would use to
 * identify what sort of thing an attribute is. e.g. "Material", "Texture Map".
 *
 * \param attribute attribute to set class of
 * \param user_name Name for user to see. Should be localized.
 * \param class_name Name used internally when writing NavisWorks plugins. Should not be localized.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAttributeSetClassName(LtNwcAttribute attribute, LtWideString user_name,
                      LtString class_name);

/**
 * Set whether an attribute should be considered as internal. Internal attributes are
 * not usually visible in the NavisWorks GUI.
 *
 * \param attribute attribute to set internal flag for
 * \param value Value to set internal flag to.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAttributeSetInternal(LtNwcAttribute attribute, bool value);

/**
 * Create a reference to a NavisWorks attribute of any type
 *
 * \param attribute attribute to reference
 * \return reference to attribute
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcAttribute LI_NWC_API
LiNwcAttributeCreateRef(LtNwcAttribute attribute);

/**
 * Destroy a NavisWorks attribute of any type
 *
 * \param attribute attribute to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAttributeDestroy(LtNwcAttribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcAttribute API calls
 *
 * \see LiNwcAttribute.h
 */
class LcNwcAttribute
{
public:
   LcNwcAttribute(LtNwcAttribute handle) : m_handle(LiNwcAttributeCreateRef(handle)) {}
   ~LcNwcAttribute() { LiNwcAttributeDestroy(m_handle); }

   LcNwcAttribute(const LcNwcAttribute &other) : m_handle(LiNwcAttributeCreateRef(other)) {}

   LcNwcAttribute& operator = (const LcNwcAttribute &other)
   {LiNwcAttributeDestroy(m_handle); m_handle = LiNwcAttributeCreateRef(other); return *this;}

   operator LtNwcAttribute () const { return m_handle; }
   LtNwcAttribute GetHandle() const { return m_handle; }

   void SetName(LtWideString name)
   { LiNwcAttributeSetName(m_handle, name); }

   void SetClassName(LtWideString user_name, const char* internal_name)
   { LiNwcAttributeSetClassName(m_handle, user_name, const_cast<LtString>(internal_name)); }

   void SetInternal(bool value)
   { LiNwcAttributeSetInternal(m_handle, value); }

protected:
   LcNwcAttribute(LtNwcAttribute handle, bool /*own*/)
      : m_handle(handle) {}

private:

   LtNwcAttribute m_handle;
};

#endif

#endif /* LINWCATTRIBUTE_HDR */
