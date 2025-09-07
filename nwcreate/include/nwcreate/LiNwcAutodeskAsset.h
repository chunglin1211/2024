/**
 * \file
 *
 * An asset used in the definition of Autodesk rendering materials.
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

#ifndef LINWCAUTODESKASSET_HDR
#define LINWCAUTODESKASSET_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a new Autodesk asset.
 *
 * \return Newly created asset or NULL on error
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcAutodeskAsset LI_NWC_API
LiNwcAutodeskAssetCreate();

/**
 * Destroy an Autodesk asset.
 *
 * \param asset asset to destroy
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetDestroy(LtNwcAutodeskAsset asset);

/**
 * Sets the library identifier for the asset.
 *
 * \param asset asset to set identifier on.
 * \param library_id identifier of library.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetSetLibraryIdentifier(LtNwcAutodeskAsset asset,
                                       LtWideString library_id);

/**
 * Sets the definition identifier for the asset.
 *
 * \param asset asset to set identifier on.
 * \param definition_id identifier of definition.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetSetDefinitionIdentifier(LtNwcAutodeskAsset asset,
                                          LtWideString definition_id);

/**
 * Adds asset data to the asset.
 *
 * \param asset asset to set identifier on.
 * \param data asset data to add.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskAssetAddData(LtNwcAutodeskAsset asset,
                          LtNwcAutodeskAssetData data);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcAutodeskAsset API calls
 *
 * \see LiNwcAutodeskAsset.h
 */
class LcNwcAutodeskAsset
{
public:
   LcNwcAutodeskAsset() : m_handle(LiNwcAutodeskAssetCreate()), m_own(true) {}
   LcNwcAutodeskAsset(LtNwcAutodeskAsset handle) : m_handle(handle), m_own(false) {}
   ~LcNwcAutodeskAsset() {if(m_own) LiNwcAutodeskAssetDestroy(m_handle);}

   operator LtNwcAutodeskAsset () const { return m_handle; }
   LtNwcAutodeskAsset GetHandle() const { return m_handle; }

   void AddData(LtNwcAutodeskAssetData data)
   { LiNwcAutodeskAssetAddData(m_handle, data); }

   void SetLibraryIdentifier(LtWideString library_id)
   { LiNwcAutodeskAssetSetLibraryIdentifier(m_handle, library_id); }

   void SetDefinitionIdentifier(LtWideString definition_id)
   { LiNwcAutodeskAssetSetDefinitionIdentifier(m_handle, definition_id); }

private:

   LtNwcAutodeskAsset m_handle;
   bool m_own;
};

#endif

#endif // LINWCAUTODESKASSET_HDR
