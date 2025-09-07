/**
 * \file
 *
 * OBSOLETE: Presenter functionality is no longer supported.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2002
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCPRESENTERDATA_HDR
#define LINWCPRESENTERDATA_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * OBSOLETE: Returns NULL.
 *
 * Create a new NavisWorks Presenter data object .
 *
 * \return Newly created data object or NULL on error
 * \version 2.2
 */
LI_NWC_PUBLIC LtNwcPresenterData LI_NWC_API
LiNwcPresenterDataCreate();

/**
 * OBSOLETE: Returns NULL.
 *
 * Create a copy of a NavisWorks Presenter data object.
 *
 * \param data data object to copy
 * \return Copied data object or NULL on error
 * \version 2.2
 */
LI_NWC_PUBLIC LtNwcPresenterData LI_NWC_API
LiNwcPresenterDataCreateCopy(LtNwcPresenterData data);

/**
 * OBSOLETE: Does nothing.
 *
 * Destroy a NavisWorks Presenter data object
 *
 * \param data data object to destroy
 * \version 2.2
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPresenterDataDestroy(LtNwcPresenterData data);


/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a floating point value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetFloat(LtNwcPresenterData data, LtFloat arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as integer value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetInt32(LtNwcPresenterData data, LtInt32 arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as unsigned integer value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 3.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetNat32(LtNwcPresenterData data, LtNat32 arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a enumerated value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetEnum(LtNwcPresenterData data, LtInt32 arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a bitfield value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 3.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetBitfield(LtNwcPresenterData data, LtInt32 arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a string value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetString(LtNwcPresenterData data, LtWideString arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a boolean value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetBoolean(LtNwcPresenterData data, bool arg);



/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a point value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetPoint(LtNwcPresenterData data, LtPoint arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a vector value
 *
 * \param data Data object
 * \param arg Value to be given to data object
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetVector(LtNwcPresenterData data, LtVector arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Set the data object as a color value
 *
 * \param data Data object
 * \param r red
 * \param g green
 * \param b blue
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterDataSetColor(LtNwcPresenterData data,LtFloat r,LtFloat g,LtFloat b);




#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPresenterData API calls
 *
 * \see LiNwcPresenterData.h
 */
class LcNwcPresenterData
{
public:
   LcNwcPresenterData() : m_handle(LiNwcPresenterDataCreate()), m_own(true) {}
   LcNwcPresenterData(LtNwcPresenterData handle) : m_handle(handle), m_own(false) {}
   ~LcNwcPresenterData() { if (m_own) LiNwcPresenterDataDestroy(m_handle); }

   LcNwcPresenterData(const LcNwcPresenterData &other) : m_handle(LiNwcPresenterDataCreateCopy(other)), m_own(true) {}

   LcNwcPresenterData& operator = (const LcNwcPresenterData &other)
   { if(m_own) LiNwcPresenterDataDestroy(m_handle); m_handle = LiNwcPresenterDataCreateCopy(other); m_own = true; return *this; }

   operator LtNwcPresenterData () const { return m_handle; }
   LtNwcPresenterData GetHandle() const { return m_handle; }

   bool SetFloat(LtFloat arg)
   {return LiNwcPresenterDataSetFloat(GetHandle(),arg);}

   bool SetInt32(LtInt32 arg)
   {return LiNwcPresenterDataSetInt32(GetHandle(),arg);}

   bool SetNat32(LtNat32 arg)
   {return LiNwcPresenterDataSetNat32(GetHandle(),arg);}

   bool SetEnum(LtInt32 arg)
   {return LiNwcPresenterDataSetEnum(GetHandle(),arg);}

   bool SetBitfield(LtInt32 arg)
   {return LiNwcPresenterDataSetBitfield(GetHandle(),arg);}

   bool SetString(LtWideString arg)
   {return LiNwcPresenterDataSetString(GetHandle(),arg);}

   bool SetBoolean(bool arg)
   {return LiNwcPresenterDataSetBoolean(GetHandle(),arg);}

   bool SetPoint(LtPoint arg)
   {return LiNwcPresenterDataSetPoint(GetHandle(),arg);}

   bool SetVector(LtVector arg)
   {return LiNwcPresenterDataSetVector(GetHandle(),arg);}

   bool SetColor(LtFloat r,LtFloat g,LtFloat b)
   {return LiNwcPresenterDataSetColor(GetHandle(),r,g,b);}

private:

   LtNwcPresenterData m_handle;
   bool m_own;
};

#endif

#endif /* LINWCPRESENTERDATA_HDR */
