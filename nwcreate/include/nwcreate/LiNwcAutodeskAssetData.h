/**
 * \file
 *
 * Represents data that is used with an Autodesk rendering material asset.
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

#ifndef LINWCAUTODESKASSETDATA_HDR
#define LINWCAUTODESKASSETDATA_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a new Autodesk asset data.
 *
 * \return Newly created asset data or NULL on error
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcAutodeskAssetData LI_NWC_API
LiNwcAutodeskAssetDataCreate();

/**
 * Create a new Autodesk asset data.
 *
 * \return Newly created asset data or NULL on error
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcAutodeskAssetData LI_NWC_API
LiNwcAutodeskAssetDataCreateCopy(LtNwcAutodeskAssetData data);

/**
 * Destroy an Autodesk asset data.
 *
 * \param data data to destroy
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataDestroy(LtNwcAutodeskAssetData data);


/**
 * Sets identifier of data.
 *
 * \param data data to set identifier on.
 * \param id identifier for data.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetIdentifier(LtNwcAutodeskAssetData data,
                                    LtWideString id);

/**
 * Sets the linear units of the data.
 *
 * \param data data to set units on.
 * \param units linear units to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetLinearUnits(LtNwcAutodeskAssetData data,
                                     LtNwcLinearUnits units);

/**
 * Sets the units of the data to some arbitary value.
 *
 * \param data data to set units on.
/? \param units units to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetUnits(LtNwcAutodeskAssetData data,
                               LtNat32 units);

/**
 * Sets binary data on data.
 *
 * \param data data to set data on.
 * \param blob pointer to binary data. Must not be NULL.
 * \param size size of data blob in bytes.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetBinary(LtNwcAutodeskAssetData data,
                                LtNat8 *blob,
                                LtNat32 size);

/**
 * Sets boolean value on data.
 *
 * \param data data to set value on.
 * \param value boolean value.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetBoolean(LtNwcAutodeskAssetData data,
                                 bool value);

/**
 * Sets integer value on data.
 *
 * \param data data to set value on.
 * \param value 32-bit signed value.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetInteger(LtNwcAutodeskAssetData data,
                                 LtInt32 value);

/**
 * Sets integer array on data.
 *
 * \param data data to set array on.
 * \param values start of array of 32-bit signed integer values. If NULL, will just set the size of the array.
 * \param count number of values in array.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetIntegerArray(LtNwcAutodeskAssetData data,
                                      LtInt32 *values,
                                      LtNat32 count);

/**
 * Sets a value of an integer array.
 *
 * \param data data to set value on.
 * \param index index of value to set.
 * \param value value to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetIntegerAtIndex(LtNwcAutodeskAssetData data,
                                        LtNat32 index,
                                        LtInt32 value);

/**
 * Sets a scalar value on data.
 *
 * \param data data to set value on
 * \param value value to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetScalar(LtNwcAutodeskAssetData data,
                                LtFloat value);

/**
 * Sets an array of scalar values on data.
 *
 * \param data data to set array on.
 * \param values start of array of values. If NULL, will just set the size of the array.
 * \param count number of values in array.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetScalarArray(LtNwcAutodeskAssetData data,
                                     LtFloat *values,
                                     LtNat32 count);

/**
 * Sets scalar value in array.
 *
 * \param data data to set value in.
 * \param index index of value to set.
 * \param value value to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetScalarAtIndex(LtNwcAutodeskAssetData data,
                                       LtNat32 index,
                                       LtFloat value);

/**
 * Sets string value on data.
 *
 * \param data data to set value on.
 * \param value string value to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetString(LtNwcAutodeskAssetData data,
                                LtWideString value);

/**
 * Sets date/time value on data.
 *
 * Date/time values are formatted as strings in ISO 8601 format, which is
 * "YYYY-MM-DD hh:mm:ss"
 *
 * \param data data to set value on.
 * \param value value to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetDateTime(LtNwcAutodeskAssetData data,
                                  LtWideString value);

/**
 * Sets an array of RGB colors on the data.
 *
 * Each color is represented as three scalar values, representing red, green and
 * blue respectively, where each component is in the range 0.0 to 1.0.
 *
 * \param data data to set values on.
 * \param values start of array of components for each color. Must contain at least count * 3 values. Use NULL to just set the size of the array.
 * \param count number of colors in array.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetRGBColorArray(LtNwcAutodeskAssetData data,
                                       LtFloat *values,
                                       LtNat32 count);

/**
 * Sets an RGB value of a color array at a given index.
 *
 * \param data data to set value on.
 * \param index index of value to set.
 * \param value pointer to RGB components, as represented as array of three scalar values.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetRGBColorAtIndex(LtNwcAutodeskAssetData data,
                                         LtNat32 index,
                                         LtFloat *value);

/**
 * Sets an array of RGBA colors on the data.
 *
 * Each color is represented as four scalar values, representing red, green, blue,
 * and alpha respectively, where each component is in the range 0.0 to 1.0.
 *
 * \param data data to set values on.
 * \param values start of array of components for each color. Must contain at least count * 4 values. Use NULL to just set the size of the array.
 * \param count number of colors in array.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetRGBAColorArray(LtNwcAutodeskAssetData data,
                                        LtFloat *values,
                                        LtNat32 count);

/**
 * Sets an RGBA value of a color array at a given index.
 *
 * \param data data to set value on.
 * \param index index of value to set.
 * \param value pointer to RGBA components, as represented as array of four scalar values.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetRGBAColorAtIndex(LtNwcAutodeskAssetData data,
                                          LtNat32 index,
                                          LtFloat *value);

/**
 * Sets a URI value on the data.
 *
 * \param data data to set value on.
 * \param uri uri value to set.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetURI(LtNwcAutodeskAssetData data,
                             LtWideString uri);

/**
 * Sets the data to represent a texture. You also need to specify
 * one or more connected asset that represents the texture.
 *
 * \param data data to set value on.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetTexture(LtNwcAutodeskAssetData data);

/**
 * Sets a connected asset on the data.
 * This function is deprecated and you should use
 * LiNwcAutodeskAssetDataAddConnectedAsset instead
 *
 * \param data data to set asset on.
 * \param asset asset to connect to data.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetConnectedAsset(LtNwcAutodeskAssetData data,
                                        LtNwcAutodeskAsset asset);

/**
 * Add a connected asset on the data, and can add multiple assets.
 *
 * \param data data to set asset on.
 * \param asset asset to connect to data.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataAddConnectedAsset(LtNwcAutodeskAssetData data,
                                        LtNwcAutodeskAsset asset);

/**
 * Sets the enabled/disable flag for any connected asset on this data.
 *
 * \param data data to set flag on.
 * \param enabled enabled/disabled flag.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetConnectedAssetEnabled(LtNwcAutodeskAssetData data,
                                               bool enabled);

/**
 * Set a uuid value on the data
 *
 * \param data data to set uuid on.
 * \param uuid uuid value to set.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetUuid(LtNwcAutodeskAssetData data,
                              LtWideString uuid);

/**
 * Set the choice list size, this should be called before set
 * any specific choice and default choice value.
 *
 * \param data data to set the choice list size on
 * \param size the size of choice list
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetChoiceListSize(LtNwcAutodeskAssetData data,
                                        LtNat32 size);

/**
 * Set an choice value at given index, a choice consist of
 * one identifier and a value. NOTE: different choice should
 * have both different id and value, and LiNwcAutodeskAssetDataSetChoiceListSize
 * should already be called before set any choice.
 *
 * \param data data to set choice on
 * \param index index of choice to set
 * \param id the choice identifier
 * \param value the choice value
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetChoiceAtIndex(LtNwcAutodeskAssetData data,
                                       LtNat32 index,
                                       LtWideString id,
                                       LtInt32 value);

/**
 * Set the default choice value. NOTE: default value should between
 * the values of the set choices, and LiNwcAutodeskAssetDataSetChoiceListSize
 * should already be called before set default choice value.
 *
 * \param data data to set choice on
 * \param value the default choice value to be set
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetChoiceDefaultValue(LtNwcAutodeskAssetData data,
                                            LtInt32 value);
/**
 * Sets the data to represent a reference. You also need to specify
 * one or more connected assets that represents the reference.
 *
 * \param data data to set value on.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDataSetReference(LtNwcAutodeskAssetData data);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcAutodeskAssetData API calls
 *
 * \see LiNwcAutodeskAssetData.h
 */
class LcNwcAutodeskAssetData
{
public:
   LcNwcAutodeskAssetData() : m_handle(LiNwcAutodeskAssetDataCreate()), m_own(true) {}
   LcNwcAutodeskAssetData(LtNwcAutodeskAssetData handle) : m_handle(handle), m_own(false) {}
   ~LcNwcAutodeskAssetData() { if (m_own) LiNwcAutodeskAssetDataDestroy(m_handle); }

   LcNwcAutodeskAssetData(const LcNwcAutodeskAssetData &other) : m_handle(LiNwcAutodeskAssetDataCreateCopy(other)), m_own(true) {}

   LcNwcAutodeskAssetData& operator = (const LcNwcAutodeskAssetData &other)
   { if(m_own) LiNwcAutodeskAssetDataDestroy(m_handle); m_handle = LiNwcAutodeskAssetDataCreateCopy(other); m_own = true; return *this; }

   operator LtNwcAutodeskAssetData () const { return m_handle; }
   LtNwcAutodeskAssetData GetHandle() const { return m_handle; }

   void SetIdentifier(LtWideString id)
   { LiNwcAutodeskAssetDataSetIdentifier(m_handle, id); }

   void SetLinearUnits(LtNwcLinearUnits units)
   { LiNwcAutodeskAssetDataSetLinearUnits(m_handle, units); }

   void SetUnits(LtNat32 units)
   { LiNwcAutodeskAssetDataSetUnits(m_handle, units); }

   void SetBinary(LtNat8 *blob, LtNat32 size)
   { LiNwcAutodeskAssetDataSetBinary(m_handle, blob, size); }

   void SetBoolean(bool value)
   { LiNwcAutodeskAssetDataSetBoolean(m_handle, value); }

   void SetInteger(LtInt32 value)
   { LiNwcAutodeskAssetDataSetInteger(m_handle, value); }

   void SetIntegerArray(LtInt32 *values, LtNat32 count)
   { LiNwcAutodeskAssetDataSetIntegerArray(m_handle, values, count); }

   void SetIntegerAtIndex(LtNat32 index, LtInt32 value)
   { LiNwcAutodeskAssetDataSetIntegerAtIndex(m_handle, index, value); }

   void SetScalar(LtFloat value)
   { LiNwcAutodeskAssetDataSetScalar(m_handle, value); }

   void SetScalarArray(LtFloat *values, LtNat32 count)
   { LiNwcAutodeskAssetDataSetScalarArray(m_handle, values, count); }

   void SetScalarAtIndex(LtNat32 index, LtFloat value)
   { LiNwcAutodeskAssetDataSetScalarAtIndex(m_handle, index, value); }

   void SetString(LtWideString value)
   { LiNwcAutodeskAssetDataSetString(m_handle, value); }

   void SetDateTime(LtWideString value)
   { LiNwcAutodeskAssetDataSetDateTime(m_handle, value); }

   void SetRGBColorArray(LtFloat *values, LtNat32 count)
   { LiNwcAutodeskAssetDataSetRGBColorArray(m_handle, values, count); }

   void SetRGBColorAtIndex(LtNat32 index, LtFloat *value)
   { LiNwcAutodeskAssetDataSetRGBColorAtIndex(m_handle, index, value); }

   void SetRGBAColorArray(LtFloat *values, LtNat32 count)
   { LiNwcAutodeskAssetDataSetRGBAColorArray(m_handle, values, count); }

   void SetRGBAColorAtIndex(LtNat32 index, LtFloat *value)
   { LiNwcAutodeskAssetDataSetRGBAColorAtIndex(m_handle, index, value); }

   void SetURI(LtWideString uri)
   { LiNwcAutodeskAssetDataSetURI(m_handle, uri); }

   void SetTexture()
   { LiNwcAutodeskAssetDataSetTexture(m_handle); }

   void SetConnectedAsset(LtNwcAutodeskAsset asset)
   { LiNwcAutodeskAssetDataSetConnectedAsset(m_handle, asset); }

   void AddConnectedAsset(LtNwcAutodeskAsset asset)
   { LiNwcAutodeskAssetDataAddConnectedAsset(m_handle, asset); }

   void SetConnectedAssetEnabled(bool enabled)
   { LiNwcAutodeskAssetDataSetConnectedAssetEnabled(m_handle, enabled); }

   void SetUuid(LtWideString uuid)
   { LiNwcAutodeskAssetDataSetUuid(m_handle, uuid); }

   void SetChoiceListSize(LtNat32 size)
   { LiNwcAutodeskAssetDataSetChoiceListSize(m_handle, size); }

   void SetChoiceListAtIndex(LtNat32 index, LtWideString id, LtInt32 value)
   { LiNwcAutodeskAssetDataSetChoiceAtIndex(m_handle, index, id, value); }

   void SetChoiceDefaultValue(LtInt32 value)
   { LiNwcAutodeskAssetDataSetChoiceDefaultValue(m_handle, value); }

   void SetReference()
   { LiNwcAutodeskAssetDataSetReference(m_handle); }

private:

   LtNwcAutodeskAssetData m_handle;
   bool m_own;
};

#endif

#endif // LINWCAUTODESKASSETDATA_HDR
