/**
 * \file
 *
 * An attribute that defines some arbitrary Property. The Property, name and
 * class Property are visible in the NavisWorks properties dialog and to
 * NavisWorks plugins.
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

#ifndef LINWCPROPERTYATTRIBUTE_HDR
#define LINWCPROPERTYATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a property attribute
 *
 * \return Newly created attribute or NULL on error
 * \version 2.0
 */
LI_NWC_PUBLIC LtNwcPropertyAttribute LI_NWC_API
LiNwcPropertyAttributeCreate();

/**
 * Add a property to be stored in the attribute.
 *
 * \param attribute Attribute to add property to
 * \param user_name User visible name of property
 * \param internal_name Internal name of property
 * \param value The property's data
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPropertyAttributeAddProperty(LtNwcPropertyAttribute attribute,
                                    LtWideString user_name,
                                    LtString internal_name,
                                    LtNwcData value);

/**
 * Get the size of a property attribute.
 *
 * \param attribute Attribute to add property to
 * \return Number of data values in the property attribute.
 * \version 3.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcPropertyAttributeSize(LtNwcPropertyAttribute attribute);

/**
 * Destroy a property attribute
 *
 * \param attribute Attribute to destroy
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPropertyAttributeDestroy(LtNwcPropertyAttribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPropertyAttribute API calls
 *
 * \see LiNwcPropertyAttribute.h
 */
class LcNwcPropertyAttribute : public LcNwcAttribute
{
public:
   LcNwcPropertyAttribute() : LcNwcAttribute(LiNwcPropertyAttributeCreate(), true) {}
   LcNwcPropertyAttribute(LtNwcPropertyAttribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcPropertyAttribute () const
   { return static_cast<LtNwcPropertyAttribute>(LcNwcAttribute::GetHandle()); }
   LtNwcPropertyAttribute GetHandle() const
   { return static_cast<LtNwcPropertyAttribute>(LcNwcAttribute::GetHandle()); }

   void AddProperty(LtWideString user_name, const char* internal_name,
                     LtNwcData property)
   { LiNwcPropertyAttributeAddProperty(GetHandle(), user_name, const_cast<LtString>(internal_name),
                                          property); }

   LtInt32 Size() const
   { return LiNwcPropertyAttributeSize(GetHandle()); }
};

#endif

#endif /* LINWCPropertyATTRIBUTE_HDR */
