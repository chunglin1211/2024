/**
 * \file
 *
 * An attribute that just defines a 64 bit unsigned integer. The value,
 * name and class name of the attribute are
 * visible in the NavisWorks properties dialog and to NavisWorks plugins.
 * If SetStableId() is set to true, the value can be used to match
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

#ifndef LINWCNAT64ATTRIBUTE_HDR
#define LINWCNAT64ATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a Nat64 attribute
 *
 * \return Newly created attribute or NULL on error
 */
LI_NWC_PUBLIC LtNwcNat64Attribute LI_NWC_API
LiNwcNat64AttributeCreate();

/**
 * Set value of attribute
 *
 * \param attribute Attribute to set value of
 * \param value Value to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNat64AttributeSetValue(LtNwcNat64Attribute attribute, LtNat64 value);

/**
 * Can this value be used as an identifier to help match nodes between
 * different versions of the same file? Set to true if different nodes
 * will have mainly different values and if a node keeps the same name
 * if it isn't altered. Default is false.
 *
 * \param attribute Attribute to set stable id property for
 * \param b true to mark attribute as stable id
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNat64AttributeSetStableId(LtNwcNat64Attribute attribute, bool b);

/**
 * Values for formatting a Nat64Attribute.
 */
typedef enum LtNwcNat64AttributeFormat__tag {
   LI_NWC_NAT64_FORMAT_DECIMAL,      /** Display value as decimal */
   LI_NWC_NAT64_FORMAT_HEXADECIMAL,  /** Display value as hexadecimal */
} LtNwcNat64AttributeFormat;

/**
 * Set display format for the attribute. Default is decimal.
 *
 * \param attribute Attribute to set format for
 * \param format Format for value
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNat64AttributeSetDisplayFormat(LtNwcNat64Attribute attribute, LtNwcNat64AttributeFormat format);

/**
 * Destroy a name attribute
 *
 * \param attribute Attribute to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNat64AttributeDestroy(LtNwcNat64Attribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcNat64Attribute API calls
 *
 * \see LiNwcNat64Attribute.h
 */
class LcNwcNat64Attribute : public LcNwcAttribute
{
public:
   LcNwcNat64Attribute() : LcNwcAttribute(LiNwcNat64AttributeCreate(), true) {}
   LcNwcNat64Attribute(LtNwcNat64Attribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcNat64Attribute () const
   { return static_cast<LtNwcNat64Attribute>(LcNwcAttribute::GetHandle()); }
   LtNwcNat64Attribute GetHandle() const
   { return static_cast<LtNwcNat64Attribute>(LcNwcAttribute::GetHandle()); }

   void SetValue(LtNat64 value)
   { LiNwcNat64AttributeSetValue(GetHandle(), value); }

   void SetStableId(bool b)
   { LiNwcNat64AttributeSetStableId(GetHandle(), b); }

   void SetDisplayFormat(LtNwcNat64AttributeFormat format)
   {
      LiNwcNat64AttributeSetDisplayFormat(GetHandle(), format);
   }
};

#endif

#endif /* LINWCNAT64ATTRIBUTE_HDR */
