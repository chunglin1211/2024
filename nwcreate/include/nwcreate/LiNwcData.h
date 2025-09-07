/**
 * \file
 * Type that can store multiple different types of data.
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

#ifndef LINWCDATA_HDR
#define LINWCDATA_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an empty NavisWorks data property.
 *
 * \return Newly created data or NULL on error
 * \version 2.0
 */
LI_NWC_PUBLIC LtNwcData LI_NWC_API
LiNwcDataCreate();

/**
 * Create a copy of a NavisWorks data property.
 *
 * \param data data to copy
 * \return copied data or NULL on error
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcData LI_NWC_API
LiNwcDataCreateCopy(LtNwcData data);

/**
 * Destroy a NavisWorks data property
 *
 * \param data data to destroy
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataDestroy(LtNwcData data);

/**
 * Set a float value as the contents of a data handle.
 *
 * \param data Data to set
 * \param value Value to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetFloat(LtNwcData data, LtFloat value);

/**
 * Set an angular float value as the contents of a data handle.
 * The angle should be defined in radians.
 *
 * \param data Data to set
 * \param value Value to set
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetAngularFloat(LtNwcData data, LtFloat value);

/**
 * Set a linear float value (length) as the contents of a data handle.
 * When used to define a property (LiNwcPropertyAttributeAddProperty),
 * the value should be defined in the same units as the scene (LiNwcSceneSetLinearUnits).
 * When used to define a loader parameter (LtNwcParameterCallback), the value should
 * be defined in meters.
 *
 * \param data Data to set
 * \param value Value to set
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetLinearFloat(LtNwcData data, LtFloat value);

/**
 * Set a float value that represents an area as the contents of a data handle.
 * When used to define a property (LiNwcPropertyAttributeAddProperty),
 * the value should be defined in the same units as the scene (LiNwcSceneSetLinearUnits).
 *
 * \param data Data to set
 * \param value Value to set
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetAreaFloat(LtNwcData data, LtFloat value);

/**
 * Set a float value that represents an volume as the contents of a data handle.
 * When used to define a property (LiNwcPropertyAttributeAddProperty),
 * the value should be defined in the same units as the scene (LiNwcSceneSetLinearUnits).
 *
 * \param data Data to set
 * \param value Value to set
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetVolumeFloat(LtNwcData data, LtFloat value);

/**
 * Set a boolean value as the contents of a data handle.
 *
 * \param data Data to set
 * \param value Value to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetBoolean(LtNwcData data, bool value);

/**
 * Set an integer value as the contents of a data handle.
 *
 * \param data Data to set
 * \param value Value to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetInt32(LtNwcData data, LtInt32 value);

/**
 * Set an integer value as the contents of a data handle.
 * For file versions that do not support storing of LtInt64 data, the value is
 * stored as an LtInt32, if fits into this, otherwise it will be stored as a string.
 *
 * \param data Data to set
 * \param value Value to set
 * \version 21.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetInt64(LtNwcData data, LtInt64 value);

/**
 * Set a name value as the contents of a data handle.
 *
 * \param data Data to set
 * \param user_name Name for user to see. Should be localized.
 * \param internal_name Name used internally when writing NavisWorks plugins. Should not be localized.
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetName(LtNwcData data,
                 LtWideString user_name,
                 LtString internal_name);

/**
 * Set an enum encoded as a name value as the contents of a data handle.
 * The end user will see the user_name as the value of the property. COM API users
 * will be able to access the type_name and value. Enums save space for common
 * strings - each enum definition is stored once and reused.
 *
 * If "type_name:value=user_name" for each enum is entered into a name table within
 * the loaders .cfg file, then the enum user_names can be localized so that the correct
 * language version is displayed irrespective of the language in use when an NWD file was
 * created.
 *
 * \param data Data to set
 * \param user_name Name for user to see. Should be localized.
 * \param type_name Name of enum type. Should not be localized.
 * \param value Value of enum
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetNameEnum(LtNwcData data,
                     LtWideString user_name,
                     LtString type_name,
                     LtInt32 value);

/**
 * Set a wide string value as the contents of a data handle.
 *
 * \param data Data to set
 * \param value Value to set
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetWideString(LtNwcData data, LtWideString value);

/**
 * Set a time value as the contents of a data handle.
 *
 * \param data Data to set
 * \param value Value to set
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetTime(LtNwcData data, LtTime_t value);

/**
 * Set a point 3D as the contents of the data handle.
 *
 * \param data Data to set
 * \param x X component of 3D point
 * \param y Y component of 3D point
 * \param z Z component of 3D point
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDataSetPoint3D(LtNwcData data,
                    LtFloat x,
                    LtFloat y,
                    LtFloat z);

/**
 * Data types that can be stored in an LtNwcData handle.
 */
typedef enum LtNwcDataType__tag {
   LI_NWC_DATA_NONE,          /** No data has been set */
   LI_NWC_DATA_FLOAT,         /** LtFloat */
   LI_NWC_DATA_INT32,         /** LtInt32 */
   LI_NWC_DATA_BOOLEAN,       /** bool */
   LI_NWC_DATA_WIDESTRING,    /** LtWideString */
   LI_NWC_DATA_TIME,          /** LtTime_t */
   LI_NWC_DATA_LINEAR_FLOAT,  /** LtFloat */
   LI_NWC_DATA_ANGULAR_FLOAT, /** LtFloat */
   LI_NWC_DATA_NAME,          /** LtWideString/LtString pair */
   LI_NWC_DATA_STRING,        /** LtString */
   LI_NWC_DATA_AREA_FLOAT,    /** LtFloat */
   LI_NWC_DATA_VOLUME_FLOAT,  /** LtFloat */
   LI_NWC_DATA_POINT3D,       /** LtFloat[3] */
} LtNwcDataType;

/**
 * Get the type of data stored in a data handle.
 *
 * \param data Data to get type from
 * \return Type of data stored in handle
 */
LI_NWC_PUBLIC LtNwcDataType LI_NWC_API
LiNwcDataGetType(LtNwcData data);

/**
 * Get the generic float value from a data handle
 *
 * \param data Data to get float value from
 * \return Float value stored in handle, or 0.0 if not a generic float type
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcDataGetFloat(LtNwcData data);

/**
 * Get the linear float value from a data handle
 *
 * \param data Data to get float value from
 * \return Float value stored in handle, or 0.0 if not a linear float type
 * \version 3.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcDataGetLinearFloat(LtNwcData data);

/**
 * Get the area float value from a data handle
 *
 * \param data Data to get float value from
 * \return Float value stored in handle, or 0.0 if not an area float type
 * \version 9.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcDataGetAreaFloat(LtNwcData data);

/**
 * Get the volume float value from a data handle
 *
 * \param data Data to get float value from
 * \return Float value stored in handle, or 0.0 if not a volume float type
 * \version 9.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcDataGetVolumeFloat(LtNwcData data);

/**
 * Get an angular float value from a data handle
 *
 * \param data Data to get float value from
 * \return Float value stored in handle, or 0.0 if not an angular float type
 * \version 3.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcDataGetAngularFloat(LtNwcData data);

/**
 * Get a boolean value from a data handle
 *
 * \param data Data to get boolean value from
 * \return Boolean value stored in handle, or false if not a boolean type
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcDataGetBoolean(LtNwcData data);

/**
 * Get an integer value from a data handle
 *
 * \param data Data to get integer value from
 * \return Integer value stored in handle, or 0 if not an integer type
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcDataGetInt32(LtNwcData data);

/**
 * Get a wide string value from a data handle
 *
 * \param data Data to get wide string value from
 * \return Wide string value stored in handle, or NULL if not a wide string type
 * \version 2.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcDataGetWideString(LtNwcData data);

/**
 * Get an LtTime_t value from a data handle
 *
 * \param data Data to get time value from
 * \return Time value stored in handle, or (LtTime_t)0 if not a time type
 * \version 2.0
 */
LI_NWC_PUBLIC LtTime_t LI_NWC_API
LiNwcDataGetTime(LtNwcData data);

/**
 * Get a name value from a data handle
 *
 * \param data Data to get name value from
 * \param user_name Pointer to LtWideString which will be set to user name part of value stored in handle, or NULL if not a name type
 * \return Internal name part of value stored in handle, NULL if not a name type
 * \version 3.0
 */
LI_NWC_PUBLIC LtString LI_NWC_API
LiNwcDataGetName(LtNwcData data, LtWideString* user_name);

/**
 * Get an enum encoded as a name value from a data handle
 *
 * \param data Data to get enum encoded as name value from
 * \param user_name Pointer to LtWideString which will be set to user name part of value stored in handle, or NULL if not a name type
 * \param type_name Expected type for enum
 * \param value Pointer to LtInt32 which will be set to value part of encoded enum stored in handle, or 0 on error.
 * \return true if data contains an encoded enum of the correct type
 * \version 3.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcDataGetNameEnum(LtNwcData data, LtString type_name, LtWideString* user_name, LtInt32* value);

/**
 * Get 3D point value from a data handle
 *
 * \param data Data to get point value from.
 * \return pointer to array of 3 floats that represent the X, Y, Z components of the point.
 * \version 3.0
 */
LI_NWC_PUBLIC LtFloat* LI_NWC_API
LiNwcDataGetPoint3D(LtNwcData data);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcData API calls
 *
 * \see LiNwcData.h
 */
class LcNwcData
{
public:
   LcNwcData() : m_handle(LiNwcDataCreate()), m_own(true) {}
   LcNwcData(LtNwcData handle) : m_handle(handle), m_own(false) {}
   ~LcNwcData() { if (m_own) LiNwcDataDestroy(m_handle); }

   LcNwcData(const LcNwcData &other) : m_handle(LiNwcDataCreateCopy(other)), m_own(true) {}

   LcNwcData& operator = (const LcNwcData &other)
   { if(m_own) LiNwcDataDestroy(m_handle); m_handle = LiNwcDataCreateCopy(other); m_own = true; return *this; }

   operator LtNwcData () const { return m_handle; }
   LtNwcData GetHandle() const { return m_handle; }

   void SetFloat(LtFloat value)
   { LiNwcDataSetFloat(m_handle, value); }

   void SetLinearFloat(LtFloat value)
   { LiNwcDataSetLinearFloat(m_handle, value); }

   void SetAreaFloat(LtFloat value)
   { LiNwcDataSetAreaFloat(m_handle, value); }

   void SetVolumeFloat(LtFloat value)
   { LiNwcDataSetVolumeFloat(m_handle, value); }

   void SetAngularFloat(LtFloat value)
   { LiNwcDataSetAngularFloat(m_handle, value); }

   void SetBoolean(bool value)
   { LiNwcDataSetBoolean(m_handle, value); }

   void SetInt32(LtInt32 value)
   { LiNwcDataSetInt32(m_handle, value); }

   void SetInt64(LtInt64 value)
   { LiNwcDataSetInt64(m_handle, value); }

   void SetWideString(LtWideString value)
   { LiNwcDataSetWideString(m_handle, value); }

   void SetTime(LtTime_t value)
   { LiNwcDataSetTime(m_handle, value); }

   void SetName(LtWideString user_name, const char *internal_name)
   { LiNwcDataSetName(m_handle, user_name, const_cast<LtString>(internal_name)); }

   void SetNameEnum(LtWideString user_name, const char* type_name, LtInt32 value)
   { LiNwcDataSetNameEnum(m_handle, user_name, const_cast<LtString>(type_name), value); }

   void SetPoint3D(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcDataSetPoint3D(m_handle, x, y, z); }

   LtNwcDataType GetType() const
   { return LiNwcDataGetType(m_handle); }

   LtFloat GetFloat() const
   { return LiNwcDataGetFloat(m_handle); }

   LtFloat GetLinearFloat() const
   { return LiNwcDataGetLinearFloat(m_handle); }

   LtFloat GetAreaFloat() const
   { return LiNwcDataGetAreaFloat(m_handle); }

   LtFloat GetVolumeFloat() const
   { return LiNwcDataGetVolumeFloat(m_handle); }

   LtFloat GetAngularFloat() const
   { return LiNwcDataGetAngularFloat(m_handle); }

   bool GetBoolean() const
   { return LiNwcDataGetBoolean(m_handle); }

   LtInt32 GetInt32() const
   { return LiNwcDataGetInt32(m_handle); }

   LtWideString GetWideString() const
   { return LiNwcDataGetWideString(m_handle); }

   LtTime_t GetTime() const
   { return LiNwcDataGetTime(m_handle); }

   /*
   // Deprecated. Please use LtString GetName(LtWideString* user_name) const
   // instead.
   */
   LtString GetName(LtNwcData /*data*/, LtWideString* user_name) const
   { return LiNwcDataGetName(m_handle, user_name); }

   LtString GetName(LtWideString* user_name) const
   { return LiNwcDataGetName(m_handle, user_name); }

   bool GetNameEnum(const char* type_name, LtWideString* user_name, LtInt32* value)
   { return LiNwcDataGetNameEnum(m_handle, const_cast<LtString>(type_name), user_name, value); }

   const LtFloat* GetPoint3D() const
   { return LiNwcDataGetPoint3D(m_handle); }

private:

   LtNwcData m_handle;
   bool m_own;
};

#endif

#endif /* LINWCDATA_HDR */
