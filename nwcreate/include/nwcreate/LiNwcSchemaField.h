/**
 * \file
 * Field data for use with schemas. A given field represents a single identifiable component.
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

#ifndef LINWCSCHEMAFIELD_HDR
#define LINWCSCHEMAFIELD_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Unit group types.
 */
typedef enum LtNwcSchemaUnitGroup__tag
{
   LI_NWC_SCHEMA_UNIT_GROUP_NONE = 0,              /** No group */
   LI_NWC_SCHEMA_UNIT_GROUP_LENGTH = (0x02 << 12), /** Length type */
   LI_NWC_SCHEMA_UNIT_GROUP_AREA = (0x03 << 12),   /** Area type */
   LI_NWC_SCHEMA_UNIT_GROUP_VOLUME = (0x04 << 12), /** Volume type */
   LI_NWC_SCHEMA_UNIT_GROUP_ANGLE = (0x08 << 12),  /** Angle type */
} LtNwcSchemaUnitGroup;

/**
 * Create a copy of a given schema field.
 *
 * \param field Schema field to copy.
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaField LI_NWC_API
LiNwcSchemaFieldCreateCopy(LtNwcSchemaField field);

/**
 * Destroy a schema field.
 *
 * \param field Schema field to destroy.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaFieldDestroy(LtNwcSchemaField field);

/**
 * Set a field's ID. Intended for internal programmatic reference.
 *
 * \param field Schema field to receive the ID.
 * \param id The id to be set.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaFieldSetId(LtNwcSchemaField field, LtString id);

/**
 * Set a field's display name ID. Intended for looking up the localized display name.
 *
 * \param field Schema field to receive the display name ID.
 * \param display_name_id The internal ID used to look up the localized display name.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaFieldSetDisplayNameId(LtNwcSchemaField field, LtString display_name_id);

/**
 * Adds a metadata concept string onto a field. This identifies some capability/semantics that the field has.
 *
 * \param field Schema field to receive the concept.
 * \param concept The concept to be set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaFieldAddConcept(LtNwcSchemaField field, LtWideString concept);

/**
 * Create an schema field that represents a double.
 *
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaDoubleField LI_NWC_API
LiNwcSchemaDoubleFieldCreate();

/**
 * Set the default value for the double schema field.
 * \param field Schema field to receive the default value.
 * \param default_value The default value to set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaDoubleFieldSetDefaultValue(LtNwcSchemaDoubleField field, double default_value);

/**
 * Set the unit group for the double schema field.
 * \param field Schema field to receive the unit group.
 * \param unit_group The unit group to set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaDoubleFieldSetUnitGroup(LtNwcSchemaDoubleField field, LtNwcSchemaUnitGroup unit_group);

/**
 * Create an schema field that represents a struct.
 *
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaStructField LI_NWC_API
LiNwcSchemaStructFieldCreate();

/**
 * Add a field into a schema struct.
 *
 * \param structure Schema struct to receive the field.
 * \param field The field to be added.
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSchemaStructFieldAddField(LtNwcSchemaStructField structure, LtNwcSchemaField field);

/**
 * Collection types.
 */
typedef enum LtNwcSchemaVectorFieldCollectionType__tag
{
   LI_NWC_SCHEMA_VECTOR_FIELD_UNORDERED,        /** Unordered bag (allows duplicates). */
   LI_NWC_SCHEMA_VECTOR_FIELD_ORDERED,          /** Ordered bag (allows duplicates). */
   LI_NWC_SCHEMA_VECTOR_FIELD_UNORDERED_UNIQUE, /** Unordered set (no duplicates). */
   LI_NWC_SCHEMA_VECTOR_FIELD_ORDERED_UNIQUE,   /** Ordered set (no duplicates). */
} LtNwcSchemaVectorFieldCollectionType;

/**
 * Create an schema field that represents a vector.
 *
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaVectorField LI_NWC_API
LiNwcSchemaVectorFieldCreate(LtNwcSchemaField value_type);

/**
 * Set the collection type for the schema vector field.
 * \param field Schema field to receive the collection type.
 * \param collection_type The collection type to set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaVectorFieldSetCollectionType(LtNwcSchemaVectorField field, LtNwcSchemaVectorFieldCollectionType collection_type);

/**
 * Field ownership type.
 */
typedef enum LtNwcSchemaGuidFieldOwnership__tag {
   LI_NWC_SCHEMA_GUID_FIELD_OWNERSHIP_GENERIC,            /** Generic */
   LI_NWC_SCHEMA_GUID_FIELD_OWNERSHIP_IDENTIFIER,         /** Identifier */
   LI_NWC_SCHEMA_GUID_FIELD_OWNERSHIP_UNIQUE_REFERENCE,   /** Unique */
   LI_NWC_SCHEMA_GUID_FIELD_OWNERSHIP_SHARED_REFERENCE,   /** Shared */
   LI_NWC_SCHEMA_GUID_FIELD_OWNERSHIP_WEAK_REFERENCE,     /** Weak */
   LI_NWC_SCHEMA_GUID_FIELD_OWNERSHIP_OWNER_REFERENCE,    /** Owner */
   LI_NWC_SCHEMA_GUID_FIELD_OWNERSHIP_EXTERNAL_REFERENCE, /** External */
} LtNwcSchemaGuidFieldOwnership;

/**
 * Create an schema field that represents a GUID.
 *
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaGuidField LI_NWC_API
LiNwcSchemaGuidFieldCreate(LtNwcSchemaGuidFieldOwnership semantics);

/**
 * Set the default value for the GUID schema field.
 * \param field Schema field to receive the default value.
 * \param default_value The default value to set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaGuidFieldSetDefaultValue(LtNwcSchemaGuidField field, LtNwcGuid default_value);

/**
 * Set the ownership semantics for a given GUID field.
 *
 * \param guid Schema guid field to alter.
 * \param semantics The semantics to apply.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaGuidFieldSetOwnershipSemantics(LtNwcSchemaGuidField guid, LtNwcSchemaGuidFieldOwnership semantics);

/**
 * Set the target concept for a given GUID field.
 *
 * \param guid Schema guid field to alter.
 * \param target_concept The target concept to apply.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaGuidFieldSetTargetConcept(LtNwcSchemaGuidField guid, LtWideString target_concept);

/**
 * Create an schema field that represents an Int32.
 *
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaInt32Field LI_NWC_API
LiNwcSchemaInt32FieldCreate();

/**
 * Set the default value for the Int32 schema field.
 * \param field Schema field to receive the default value.
 * \param default_value The default value to set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaInt32FieldSetDefaultValue(LtNwcSchemaInt32Field field, LtInt32 default_value);

/**
 * Create an schema field that represents a boolean.
 *
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaBooleanField LI_NWC_API
LiNwcSchemaBooleanFieldCreate();

/**
 * Set the default value for the boolean schema field.
 * \param field Schema field to receive the default value.
 * \param default_value The default value to set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaBooleanFieldSetDefaultValue(LtNwcSchemaBooleanField field, bool default_value);

/**
 * Create an schema field that represents a wide string.
 *
 * \return Newly created field or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaWideStringField LI_NWC_API
LiNwcSchemaWideStringFieldCreate();

/**
 * Set the default value for the wide string schema field.
 * \param field Schema field to receive the default value.
 * \param default_value The default value to set.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaWideStringFieldSetDefaultValue(LtNwcSchemaWideStringField field, LtWideString default_value);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSchemaField API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaField
{
public:
   LcNwcSchemaField(LtNwcSchemaField handle) : m_handle(handle), m_own(false) {}
   ~LcNwcSchemaField() { if (m_own) LiNwcSchemaFieldDestroy(m_handle); }

   LcNwcSchemaField(const LcNwcSchemaField &other) : m_handle(LiNwcSchemaFieldCreateCopy(other)), m_own(true) {}

   LcNwcSchemaField& operator = (const LcNwcSchemaField &other)
   { if(m_own) LiNwcSchemaFieldDestroy(m_handle); m_handle = LiNwcSchemaFieldCreateCopy(other); m_own = true; return *this; }

   operator LtNwcSchemaField () const { return m_handle; }
   LtNwcSchemaField GetHandle() const { return m_handle; }

   bool SetID(LtString id)
   { return LiNwcSchemaFieldSetId(GetHandle(), id); }

   void SetDisplayNameId(LtString display_name_id)
   { LiNwcSchemaFieldSetDisplayNameId(GetHandle(), display_name_id);}

   void AddConcept(LtWideString name)
   { LiNwcSchemaFieldAddConcept(GetHandle(), name); }

protected:
   LcNwcSchemaField(LtNwcSchemaField handle, bool own)
      : m_handle(handle), m_own(own) {}

private:
   LtNwcSchemaField m_handle;
   bool m_own;
};

/**
 * C++ wrapper around LtNwcSchemaDoubleField API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaDoubleField : public LcNwcSchemaField
{
public:
   LcNwcSchemaDoubleField() : LcNwcSchemaField(LiNwcSchemaDoubleFieldCreate(), true) {}
   LcNwcSchemaDoubleField(LtString id) : LcNwcSchemaField(LiNwcSchemaDoubleFieldCreate(), true) { SetID(id); }
   LcNwcSchemaDoubleField(LtNwcSchemaDoubleField handle) : LcNwcSchemaField(handle) {}

   operator LtNwcSchemaDoubleField () const
   { return static_cast<LtNwcSchemaDoubleField>(LcNwcSchemaField::GetHandle()); }
   LtNwcSchemaDoubleField GetHandle() const
   { return static_cast<LtNwcSchemaDoubleField>(LcNwcSchemaField::GetHandle()); }

   void SetDefaultValue(double default_value)
   { LiNwcSchemaDoubleFieldSetDefaultValue(GetHandle(), default_value); }

   void SetUnitGroup(LtNwcSchemaUnitGroup unit_group)
   { LiNwcSchemaDoubleFieldSetUnitGroup(GetHandle(), unit_group); }
};

/**
 * C++ wrapper around LtNwcSchemaStructField API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaStructField : public LcNwcSchemaField
{
public:
   LcNwcSchemaStructField() : LcNwcSchemaField(LiNwcSchemaStructFieldCreate(), true) {}
   LcNwcSchemaStructField(LtString id) : LcNwcSchemaField(LiNwcSchemaStructFieldCreate(), true) { SetID(id); }
   LcNwcSchemaStructField(LtNwcSchemaStructField handle) : LcNwcSchemaField(handle) {}

   operator LtNwcSchemaStructField () const
   { return static_cast<LtNwcSchemaStructField>(LcNwcSchemaField::GetHandle()); }
   LtNwcSchemaStructField GetHandle() const
   { return static_cast<LtNwcSchemaStructField>(LcNwcSchemaField::GetHandle()); }

   bool AddField(LtNwcSchemaField field)
   { return LiNwcSchemaStructFieldAddField(GetHandle(), field); }
};

/**
 * C++ wrapper around LtNwcSchemaVectorField API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaVectorField : public LcNwcSchemaField
{
public:
   explicit LcNwcSchemaVectorField(LtNwcSchemaField value_type) : LcNwcSchemaField(LiNwcSchemaVectorFieldCreate(value_type), true) {}
   LcNwcSchemaVectorField(LtNwcSchemaField value_type, LtString id) : LcNwcSchemaField(LiNwcSchemaVectorFieldCreate(value_type), true) { SetID(id); }
   LcNwcSchemaVectorField(LtNwcSchemaVectorField handle) : LcNwcSchemaField(handle) {}

   operator LtNwcSchemaVectorField () const
   { return static_cast<LtNwcSchemaVectorField>(LcNwcSchemaField::GetHandle()); }
   LtNwcSchemaVectorField GetHandle() const
   { return static_cast<LtNwcSchemaVectorField>(LcNwcSchemaField::GetHandle()); }

   void SetCollectionType(LtNwcSchemaVectorFieldCollectionType collection_type)
   { LiNwcSchemaVectorFieldSetCollectionType(GetHandle(), collection_type); }
};

/**
 * C++ wrapper around LtNwcSchemaGuidField API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaGuidField : public LcNwcSchemaField
{
public:
   LcNwcSchemaGuidField(LtNwcSchemaGuidFieldOwnership ownership) : LcNwcSchemaField(LiNwcSchemaGuidFieldCreate(ownership), true) {}
   LcNwcSchemaGuidField(LtNwcSchemaGuidFieldOwnership ownership, LtString id) : LcNwcSchemaField(LiNwcSchemaGuidFieldCreate(ownership), true) { SetID(id); }
   LcNwcSchemaGuidField(LtNwcSchemaGuidField handle) : LcNwcSchemaField(handle) {}

   operator LtNwcSchemaGuidField () const
   { return static_cast<LtNwcSchemaGuidField>(LcNwcSchemaField::GetHandle()); }
   LtNwcSchemaGuidField GetHandle() const
   { return static_cast<LtNwcSchemaGuidField>(LcNwcSchemaField::GetHandle()); }

   void SetDefaultValue(LtNwcGuid default_value)
   { LiNwcSchemaGuidFieldSetDefaultValue(GetHandle(), default_value); }

   void SetOwnershipSemantics(LtNwcSchemaGuidFieldOwnership semantics)
   { LiNwcSchemaGuidFieldSetOwnershipSemantics(GetHandle(), semantics); }

   void SetTargetConcept(LtWideString target_concept)
   { LiNwcSchemaGuidFieldSetTargetConcept(GetHandle(), target_concept); }
};

/**
 * C++ wrapper around LtNwcSchemaInt32Field API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaInt32Field : public LcNwcSchemaField
{
public:
   LcNwcSchemaInt32Field() : LcNwcSchemaField(LiNwcSchemaInt32FieldCreate(), true) {}
   LcNwcSchemaInt32Field(LtString id) : LcNwcSchemaField(LiNwcSchemaInt32FieldCreate(), true) { SetID(id); }
   LcNwcSchemaInt32Field(LtNwcSchemaInt32Field handle) : LcNwcSchemaField(handle) {}

   operator LtNwcSchemaInt32Field () const
   { return static_cast<LtNwcSchemaInt32Field>(LcNwcSchemaField::GetHandle()); }
   LtNwcSchemaInt32Field GetHandle() const
   { return static_cast<LtNwcSchemaInt32Field>(LcNwcSchemaField::GetHandle()); }

   void SetDefaultValue(LtInt32 default_value)
   { LiNwcSchemaInt32FieldSetDefaultValue(GetHandle(), default_value); }
};

/**
 * C++ wrapper around LtNwcSchemaBooleanField API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaBooleanField : public LcNwcSchemaField
{
public:
   LcNwcSchemaBooleanField() : LcNwcSchemaField(LiNwcSchemaBooleanFieldCreate(), true) {}
   LcNwcSchemaBooleanField(LtString id) : LcNwcSchemaField(LiNwcSchemaBooleanFieldCreate(), true) { SetID(id); }
   LcNwcSchemaBooleanField(LtNwcSchemaBooleanField handle) : LcNwcSchemaField(handle) {}

   operator LtNwcSchemaBooleanField () const
   { return static_cast<LtNwcSchemaBooleanField>(LcNwcSchemaField::GetHandle()); }
   LtNwcSchemaBooleanField GetHandle() const
   { return static_cast<LtNwcSchemaBooleanField>(LcNwcSchemaField::GetHandle()); }

   void SetDefaultValue(bool default_value)
   { LiNwcSchemaBooleanFieldSetDefaultValue(GetHandle(), default_value); }
};

/**
 * C++ wrapper around LtNwcSchemaWideStringField API calls
 *
 * \see LiNwcSchemaField.h
 */
class LcNwcSchemaWideStringField : public LcNwcSchemaField
{
public:
   LcNwcSchemaWideStringField() : LcNwcSchemaField(LiNwcSchemaWideStringFieldCreate(), true) {}
   LcNwcSchemaWideStringField(LtString id) : LcNwcSchemaField(LiNwcSchemaWideStringFieldCreate(), true) { SetID(id); }
   LcNwcSchemaWideStringField(LtNwcSchemaWideStringField handle) : LcNwcSchemaField(handle) {}

   operator LtNwcSchemaWideStringField () const
   { return static_cast<LtNwcSchemaWideStringField>(LcNwcSchemaField::GetHandle()); }
   LtNwcSchemaWideStringField GetHandle() const
   { return static_cast<LtNwcSchemaWideStringField>(LcNwcSchemaField::GetHandle()); }

   void SetDefaultValue(LtWideString default_value)
   { LiNwcSchemaWideStringFieldSetDefaultValue(GetHandle(), default_value); }
};

#endif

#endif /* LINWCSCHEMAFIELD_HDR */
