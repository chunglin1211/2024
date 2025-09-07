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

#ifndef LINWCSCHEMA_HDR
#define LINWCSCHEMA_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a schema from a builder.
 * Schemas are managed internally and there is thus no CreateCopy or Destroy.
 *
 * \param builder Builder that will be destructively converted to a schema.
 * \return Newly created schema or NULL on error.
 * \version 11.0
 */
LI_NWC_PUBLIC LtNwcSchema LI_NWC_API
LiNwcSchemaCreate(LtNwcSchemaBuilder builder);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSchema API calls
 *
 * \see LiNwcSchema.h
 */
class LcNwcSchema
{
public:
   LcNwcSchema(LtNwcSchemaBuilder builder) : m_handle(LiNwcSchemaCreate(builder)) {}
   LcNwcSchema(LtNwcSchema handle) : m_handle(handle) {}

   LcNwcSchema(const LcNwcSchema &other) : m_handle(other.m_handle) {}

   LcNwcSchema& operator = (const LcNwcSchema &other)
   { m_handle = other.m_handle; return *this; }

   operator LtNwcSchema () const { return m_handle; }
   LtNwcSchema GetHandle() const { return m_handle; }

private:
   LtNwcSchema m_handle;
};

#endif

#endif /* LINWCSCHEMA_HDR */
