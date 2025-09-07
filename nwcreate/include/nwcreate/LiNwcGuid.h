/**
 * \file
 *
 * A representation of a GUID.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2010 Autodesk, Inc.  All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 *
 */

//----------------------------------------

#ifndef LINWCGUID_HDR
#define LINWCGUID_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a copy of a Guid.
 *
 * \param guid Guid to copy.
 * \return the handle of the created Guid
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateCopy(LtNwcGuid guid);

/**
 * Create a Guid from the raw data directly
 *
 * \param data1 the first 32 bytes
 * \param data2 the second 16 bytes
 * \param data3 the third 16 bytes
 * \param data4 an array of 8 byte values, 64 bytes in total
 * \return the handle of the created Guid
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromRawData(LtNat32 data1, LtNat16 data2, LtNat16 data3, LtNat8 data4[8]);

/**
 * Create a Guid from a Guid-formatted string
 *
 * \param guid the Guid-formatted string
 * \return the handle of the created Guid, or NULL if the format is wrong
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromGuidString(LtWideString guid);

/**
 * Create a Guid from a Base64 formatted string
 *
 * \param base64_string the Base64 formatted string
 * \param base64_conversion_table the Base64 conversion table which defines the character set to use. If this parameter is NULL, it takes "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_$" as the character set.
 * \return the handle of the created Guid, or NULL if the format is wrong
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromBase64(LtWideString base64_string, LtWideString base64_conversion_table);

/**
 * Create  a  GUID based on the provided name space and a guid
 *
 * \param name_space the name space guid
 * \param data the data
 * \return the handle of the created guid
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromGuidHash(LtNwcGuid name_space, LtNwcGuid data);

/**
 * Create  a  GUID based on the hash generated from the provided name space and a wide string
 *
 * \param name_space the name space guid
 * \param data the wide string
 * \return the handle of the created guid
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromWideStringHash(LtNwcGuid name_space, LtWideString data);


/**
 * Create  a  GUID based on the hash generated from the provided name space and a string
 *
 * \param name_space the name space guid
 * \param data the string
 * \return the handle of the created guid
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromStringHash(LtNwcGuid name_space, LtString data);

/**
 * Create  a  GUID based on the provided name space and a LtNat8 array
 *
 * \param name_space the name space guid
 * \param data the unsigned char array
 * \param num the number of the unsigned char
 * \return the handle of the created guid
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromNat8ArrayHash(LtNwcGuid name_space, const LtNat8* data, LtNat32 num);

/**
 * Create  a  GUID based on the provided name space and a LtNat64 data
 *
 * \param name_space the name space guid
 * \param data the unsigned int64
 * \return the handle of the created guid
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromNat64Hash(LtNwcGuid name_space, LtNat64 data);

/**
 * Create  a  GUID based on the provided name space and a LtNat32 data
 *
 * \param name_space the name space guid
 * \param data the unsigned int32
 * \return the handle of the created guid
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGuid LI_NWC_API
LiNwcGuidCreateFromNat32Hash(LtNwcGuid name_space, LtNat32 data);


/**
 * Destroys a Guid.
 *
 * \param guid the handle of the existing Guid
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGuidDestroy(LtNwcGuid guid);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcGuid API calls
 *
 * \see LiNwcGuid.h
 */
class LcNwcGuid
{
public:
   LcNwcGuid(LtNwcGuid   handle): m_handle(LiNwcGuidCreateCopy(handle)){}
   ~LcNwcGuid(){ LiNwcGuidDestroy(m_handle); }

   LcNwcGuid(const LcNwcGuid &other) : m_handle(LiNwcGuidCreateCopy(other)) {}

   LcNwcGuid& operator = (const LcNwcGuid &other)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateCopy(other); return *this; }

   operator LtNwcGuid () const { return m_handle; }
   LtNwcGuid GetHandle() const { return m_handle; }

   LcNwcGuid& operator = (LtNwcGuid handle)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateCopy(handle); return *this; }


   void CreateFromRawData(LtNat32 data1, LtNat16 data2, LtNat16 data3, LtNat8 data4[8])
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromRawData(data1,data2,data3,data4); }

   void CreateFromGuidString(LtWideString guid)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromGuidString(guid); }

   void CreateFromBase64String(LtWideString base64_string, LtWideString base64_conversion_table)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromBase64(base64_string,base64_conversion_table); }

   void CreateFromGuidHash(LtNwcGuid name_space, LtNwcGuid data)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromGuidHash(name_space, data); }

   void CreateFromWideStringHash(LtNwcGuid name_space, LtWideString data)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromWideStringHash(name_space, data); }

   void CreateFromStringHash(LtNwcGuid name_space, LtString data)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromStringHash(name_space, data); }

   void CreateFromNat8ArrayHash(LtNwcGuid name_space, const LtNat8* data, LtNat32 num)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromNat8ArrayHash(name_space, data, num); }

   void CreateFromNat64Hash(LtNwcGuid name_space, LtNat64 data)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromNat64Hash(name_space, data); }

   void CreateFromNat32Hash(LtNwcGuid name_space, LtNat32 data)
   { LiNwcGuidDestroy(m_handle); m_handle = LiNwcGuidCreateFromNat32Hash(name_space, data); }

protected:
   LcNwcGuid(LtNwcGuid handle, bool /*own*/)
      : m_handle(handle) {}

private:
   LtNwcGuid   m_handle;
};

#endif

#endif /* LINWCGUID_HDR */
