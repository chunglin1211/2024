/**
 * \file
 *
 * An attribute that defines an xref attribute. The value,
 * name and class name of the attribute are
 * visible in the NavisWorks properties dialog and to NavisWorks plugins.
 * If SetStableId() is set to true, the value can be used to match
 * the same node across multiple versions of a file.
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

#ifndef LINWCXREFATTRIBUTE_HDR
#define LINWCXREFATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an XRef attribute.
 *
 * \param path Path to XRef.
 * \return Newly created attribute or NULL on error.
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcXRefAttribute LI_NWC_API
LiNwcXRefAttributeCreate(LtWideString path);

/**
 * Add a property to be stored in the attribute.
 *
 * \param attribute Attribute to add property to.
 * \param user_name User visible name of property.
 * \param internal_name Internal name of property.
 * \param value The property's data.
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcXRefAttributeAddProperty(LtNwcXRefAttribute attribute,
                              LtWideString user_name,
                              LtString internal_name,
                              LtNwcData value);

/**
 * Get the size of an XRef attribute.
 *
 * \param attribute Attribute get the size of.
 * \return Number of data values in the XRef attribute.
 * \version 5.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcXRefAttributeSize(LtNwcXRefAttribute attribute);

/**
 * Destroy an XRef attribute.
 *
 * \param attribute Attribute to destroy.
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcXRefAttributeDestroy(LtNwcXRefAttribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcXRefAttribute API calls
 *
 * \see LiNwcXRefAttribute.h
 */
class LcNwcXRefAttribute : public LcNwcAttribute
{
public:
   LcNwcXRefAttribute(LtWideString path) : LcNwcAttribute(LiNwcXRefAttributeCreate(path), true) {}
   LcNwcXRefAttribute(LtNwcXRefAttribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcXRefAttribute () const
   { return static_cast<LtNwcXRefAttribute>(LcNwcAttribute::GetHandle()); }
   LtNwcXRefAttribute GetHandle() const
   { return static_cast<LtNwcXRefAttribute>(LcNwcAttribute::GetHandle()); }

   void AddProperty(LtWideString user_name, const char* internal_name, LtNwcData property)
   { LiNwcXRefAttributeAddProperty(GetHandle(), user_name, const_cast<LtString>(internal_name), property); }

   LtInt32 Size() const
   { return LiNwcXRefAttributeSize(GetHandle()); }
};

#endif

#endif /* LINWCXREFATTRIBUTE_HDR */
