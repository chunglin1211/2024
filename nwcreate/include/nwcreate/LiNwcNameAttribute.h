/**
 * \file
 *
 * An attribute that just defines a name. The name and class name are
 * visible in the NavisWorks properties dialog and to NavisWorks plugins.
 * If SetStableId() is set to true, the attribute can be used to match
 * the same node across multiple versions of a file.
 *
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

#ifndef LINWCNAMEATTRIBUTE_HDR
#define LINWCNAMEATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a name attribute
 *
 * \return Newly created attribute or NULL on error
 */
LI_NWC_PUBLIC LtNwcNameAttribute LI_NWC_API
LiNwcNameAttributeCreate();

/**
 * Can this name be used as an identifier to help match nodes between
 * different versions of the same file? Set to true if different nodes
 * will have mainly different values and if a node keeps the same name
 * if it isn't altered. Default is false.
 *
 * \param attribute Attribute to set stable id property for
 * \param b true to mark attribute as stable id
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNameAttributeSetStableId(LtNwcNameAttribute attribute, bool b);

/**
 * Destroy a name attribute
 *
 * \param attribute Attribute to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNameAttributeDestroy(LtNwcNameAttribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcNameAttribute API calls
 *
 * \see LiNwcNameAttribute.h
 */
class LcNwcNameAttribute : public LcNwcAttribute
{
public:
   LcNwcNameAttribute() : LcNwcAttribute(LiNwcNameAttributeCreate(), true) {}
   LcNwcNameAttribute(LtNwcNameAttribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcNameAttribute () const
   { return static_cast<LtNwcNameAttribute>(LcNwcAttribute::GetHandle()); }
   LtNwcNameAttribute GetHandle() const
   { return static_cast<LtNwcNameAttribute>(LcNwcAttribute::GetHandle()); }

   void SetStableId(bool b)
   { LiNwcNameAttributeSetStableId(GetHandle(), b); }
};

#endif

#endif /* LINWCNAMEATTRIBUTE_HDR */
