/**
 * \file
 * Definition of stored data on objects
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

#ifndef LINWCSCHEMABUILDER_HDR
#define LINWCSCHEMABUILDER_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an empty schema builder.
 *
 * \return Newly created builder or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaBuilder LI_NWC_API
LiNwcSchemaBuilderCreate();

/**
 * Create a copy of a schema builder.
 *
 * \param builder Schema builder to copy.
 * \return Copied schema or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchemaBuilder LI_NWC_API
LiNwcSchemaBuilderCreateCopy(LtNwcSchemaBuilder builder);

/**
 * Destroy a schema builder.
 *
 * \param builder Schema builder to destroy.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaBuilderDestroy(LtNwcSchemaBuilder builder);

/**
 * Add a field into a schema builder.
 *
 * \param builder Schema builder to receive the field.
 * \param field The field to be added.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaBuilderAddField(LtNwcSchemaBuilder builder, LtNwcSchemaField field);

/**
 * Add a concept into a schema builder.
 *
 * \param builder Schema builder to receive the concept.
 * \param concept The concept to be added.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSchemaBuilderAddConcept(LtNwcSchemaBuilder builder, LtWideString concept);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSchemaBuilder API calls
 *
 * \see LiNwcSchemaBuilder.h
 */
class LcNwcSchemaBuilder
{
public:
   LcNwcSchemaBuilder() : m_handle(LiNwcSchemaBuilderCreate()), m_own(true) {}
   LcNwcSchemaBuilder(LtNwcSchemaBuilder handle) : m_handle(handle), m_own(false) {}
   ~LcNwcSchemaBuilder() { if (m_own) LiNwcSchemaBuilderDestroy(m_handle); }

   LcNwcSchemaBuilder(const LcNwcSchemaBuilder &other) : m_handle(LiNwcSchemaBuilderCreateCopy(other)), m_own(true) {}

   LcNwcSchemaBuilder& operator = (const LcNwcSchemaBuilder &other)
   { if(m_own) LiNwcSchemaBuilderDestroy(m_handle); m_handle = LiNwcSchemaBuilderCreateCopy(other); m_own = true; return *this; }

   operator LtNwcSchemaBuilder () const { return m_handle; }
   LtNwcSchemaBuilder GetHandle() const { return m_handle; }

   void AddField(LtNwcSchemaField field)
   { LiNwcSchemaBuilderAddField(GetHandle(), field); }

   void AddConcept(LtWideString concept)
   { LiNwcSchemaBuilderAddConcept(GetHandle(), concept); }

private:
   LtNwcSchemaBuilder m_handle;
   bool m_own;
};

#endif

#endif /* LINWCSCHEMABUILDER_HDR */
