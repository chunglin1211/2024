/**
 * \file
 * Application of a given schema onto an object as an attribute.
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

#ifndef LINWCSCHEMAPROPERTYATTRIBUTE_HDR
#define LINWCSCHEMAPROPERTYATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an empty schema property attribute. Represents data to be applied to a given node described by a schema.
 *
 * \param schema The schema to be set.
 * \return Newly created attribute or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaPropertyAttribute LI_NWC_API
LiNwcSchemaPropertyAttributeCreate(LtNwcSchema schema);

/**
 * Set a property attribute's value as a double at a given path of IDs.
 *
 * \param attribute Schema property attribute to receive the value.
 * \param path Period ('.') separated path of field IDs to the value.
 * \param value Value to set.
 * \return true if the value's path is successfully found & set, false otherwise.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaPropertyAttributeSetDouble(LtNwcSchemaPropertyAttribute attribute, LtString path, LtFloat value);

/**
 * Set a property attribute's value as a vector count at a given path of IDs.
 *
 * \param attribute Schema property attribute to receive the value.
 * \param path Period ('.') separated path of field IDs to the value.
 * \param value Value to set.
 * \return true if the value's path is successfully found & set, false otherwise.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaPropertyAttributeSetCount(LtNwcSchemaPropertyAttribute attribute, LtString path, LtNat32 value);

/**
 * Set a property attribute's value as a GUID at a given path of IDs.
 *
 * \param attribute Schema property attribute to receive the value.
 * \param path Period ('.') separated path of field IDs to the value.
 * \param value Value to set.
 * \return true if the value's path is successfully found & set, false otherwise.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaPropertyAttributeSetGuid(LtNwcSchemaPropertyAttribute attribute, LtString path, LtNwcGuid value);

/**
 * Set a property attribute's value as an int32 at a given path of IDs.
 *
 * \param attribute Schema property attribute to receive the value.
 * \param path Period ('.') separated path of field IDs to the value.
 * \param value Value to set.
 * \return true if the value's path is successfully found & set, false otherwise.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaPropertyAttributeSetInt32(LtNwcSchemaPropertyAttribute attribute, LtString path, LtInt32 value);

/**
 * Set a property attribute's value as a boolean at a given path of IDs.
 *
 * \param attribute Schema property attribute to receive the value.
 * \param path Period ('.') separated path of field IDs to the value.
 * \param value Value to set.
 * \return true if the value's path is successfully found & set, false otherwise.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaPropertyAttributeSetBoolean(LtNwcSchemaPropertyAttribute attribute, LtString path, bool value);

/**
 * Set a property attribute's value as an wide string at a given path of IDs.
 *
 * \param attribute Schema property attribute to receive the value.
 * \param path Period ('.') separated path of field IDs to the value.
 * \param value Value to set.
 * \return true if the value's path is successfully found & set, false otherwise.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaPropertyAttributeSetWideString(LtNwcSchemaPropertyAttribute attribute, LtString path, LtWideString value);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSchemaPropertyAttribute API calls
 *
 * \see LiNwcSchemaPropertyAttribute.h
 */
class LcNwcSchemaPropertyAttribute : public LcNwcAttribute
{
public:
   LcNwcSchemaPropertyAttribute(LtNwcSchema schema) : LcNwcAttribute(LiNwcSchemaPropertyAttributeCreate(schema), true) {}
   LcNwcSchemaPropertyAttribute(LtNwcSchemaPropertyAttribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcSchemaPropertyAttribute () const
   { return static_cast<LtNwcSchemaPropertyAttribute>(LcNwcAttribute::GetHandle()); }
   LtNwcSchemaPropertyAttribute GetHandle() const
   { return static_cast<LtNwcSchemaPropertyAttribute>(LcNwcAttribute::GetHandle()); }

   bool SetDouble(const LtString path, LtFloat value)
   { return LiNwcSchemaPropertyAttributeSetDouble(GetHandle(), path, value); }

   bool SetCount(const LtString path, LtNat32 value)
   { return LiNwcSchemaPropertyAttributeSetCount(GetHandle(), path, value); }

   bool SetGuid(const LtString path, LtNwcGuid value)
   { return LiNwcSchemaPropertyAttributeSetGuid(GetHandle(), path, value); }

   bool SetInt32(const LtString path, LtInt32 value)
   { return LiNwcSchemaPropertyAttributeSetInt32(GetHandle(), path, value); }

   bool SetBoolean(const LtString path, bool value)
   { return LiNwcSchemaPropertyAttributeSetBoolean(GetHandle(), path, value); }

   bool SetWideString(const LtString path, LtWideString value)
   { return LiNwcSchemaPropertyAttributeSetWideString(GetHandle(), path, value); }
};

#endif

#endif /* LINWCSCHEMAPROPERTYATTRIBUTE_HDR */
