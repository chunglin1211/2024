/**
 * \file
 *
 * An json asset used in the definition of Autodesk rendering materials.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2014 Autodesk, Inc.  All rights reserved.
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

#ifndef LINWCAUTODESKJSONASSET_HDR
#define LINWCAUTODESKJSONASSET_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a new Autodesk json asset.
 *
 * \return Newly created json asset or NULL on error
 * \version 13.0
 */
LI_NWC_PUBLIC LtNwcAutodeskJsonAsset LI_NWC_API
LiNwcAutodeskJsonAssetCreate();

/**
 * Destroy an Autodesk json asset.
 *
 * \param json_asset destroy the json asset.
 * \version 13.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskJsonAssetDestroy(LtNwcAutodeskJsonAsset json_asset);

/**
 * Update json asset with json string.
 *
 * \param json_asset json asset to set value on.
 * \param json_data json string.
 * \version 13.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskJsonAssetSetJsonData(LtNwcAutodeskJsonAsset json_asset, LtString json_data);

/**
 * Add a file reference to json asset.
 * Note: you can either pass in an absolute json_path which must resolve to a real file,
 * or can pass in a relative path to system library file which should have NULL as resolved_path.
 *
 * \param json_asset json asset to set value on.
 * \param json_path path to file used in the JSON data.
 * \param resolved_path path to current location of file.
 * \version 13.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskJsonAssetAddFileReference(LtNwcAutodeskJsonAsset json_asset, LtString json_path, LtString resolved_path);

/**
 * Add a embedded file reference to json asset.
 *
 * \param json_asset json asset to set value on.
 * \param json_path path to file used in the JSON data.
 * \param file_to_embed file which will be embedded.
 * \version 13.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskJsonAssetAddEmbeddedFileReference(LtNwcAutodeskJsonAsset json_asset, LtString json_path, LtString file_to_embed);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcAutodeskJsonAsset API calls
 *
 * \see LiNwcAutodeskJsonAsset.h
 */
class LcNwcAutodeskJsonAsset
{
public:
   LcNwcAutodeskJsonAsset() : m_handle(LiNwcAutodeskJsonAssetCreate()), m_own(true)  {}
   LcNwcAutodeskJsonAsset(LtNwcAutodeskJsonAsset handle) : m_handle(handle), m_own(false)  {}
   ~LcNwcAutodeskJsonAsset() {if(m_own) LiNwcAutodeskJsonAssetDestroy(m_handle);}

   void SetJsonData(LtString json_data)
   { LiNwcAutodeskJsonAssetSetJsonData(m_handle, json_data); }

   void AddFileReference(LtString json_path, LtString resolved_path)
   { LiNwcAutodeskJsonAssetAddFileReference(m_handle, json_path, resolved_path); }
   void AddEmbeddedFileReference(LtString json_path, LtString file_to_embed)
   { LiNwcAutodeskJsonAssetAddEmbeddedFileReference(m_handle, json_path, file_to_embed); }

   operator LtNwcAutodeskJsonAsset () const { return m_handle; }
   LtNwcAutodeskJsonAsset GetHandle() const { return m_handle; }

private:
   LtNwcAutodeskJsonAsset m_handle;
   bool m_own;
};

#endif

#endif // LINWCAUTODESKJSONASSET_HDR
