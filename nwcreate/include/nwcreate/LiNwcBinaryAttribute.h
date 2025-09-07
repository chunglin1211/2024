/**
 * \file
 *
 * An attribute that stores arbitrary binary data. The data, name and
 * class name of the attribute are visible in the NavisWorks properties
 * dialog and to NavisWorks plugins.
 * Data is displayed in the user interface in hexidecimal. Binary data is
 * usually intended for consumption by plugins and would normally be hidden
 * from the user by calling SetInternal(true) on the created attribute.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2005
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCBINARYATTRIBUTE_HDR
#define LINWCBINARYATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a binary attribute
 *
 * \return Newly created attribute or NULL on error
 * \version 4.1
 */
LI_NWC_PUBLIC LtNwcBinaryAttribute LI_NWC_API
LiNwcBinaryAttributeCreate();

/**
 * Set value of attribute. The data specified is copied into the attribute.
 *
 * \param attribute Attribute to set value of
 * \param data Pointer to binary data to store in attribute
 * \param length Number of bytes to store
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBinaryAttributeSetValue(LtNwcBinaryAttribute attribute, LtNat8* data, LtInt32 length);

/**
 * Destroy a name attribute
 *
 * \param attribute Attribute to destroy
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBinaryAttributeDestroy(LtNwcBinaryAttribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcBinaryAttribute API calls
 *
 * \see LiNwcBinaryAttribute.h
 */
class LcNwcBinaryAttribute : public LcNwcAttribute
{
public:
   LcNwcBinaryAttribute() : LcNwcAttribute(LiNwcBinaryAttributeCreate(), true) {}
   LcNwcBinaryAttribute(LtNwcBinaryAttribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcBinaryAttribute () const
   { return static_cast<LtNwcBinaryAttribute>(LcNwcAttribute::GetHandle()); }
   LtNwcBinaryAttribute GetHandle() const
   { return static_cast<LtNwcBinaryAttribute>(LcNwcAttribute::GetHandle()); }

   void SetValue(const LtNat8* data, LtInt32 length)
   { LiNwcBinaryAttributeSetValue(GetHandle(), const_cast<LtNat8*>(data), length); }
};

#endif

#endif /* LINWCBINARYATTRIBUTE_HDR */
