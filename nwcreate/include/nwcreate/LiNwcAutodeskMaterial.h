/**
 * \file
 *
 * Definition of an Autodesk rendering material. A material comprises a single asset.
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

#ifndef LINWCAUTODESKMATERIAL_HDR
#define LINWCAUTODESKMATERIAL_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a new Autodesk material.
 *
 * \return Newly created material or NULL on error
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcAutodeskMaterial LI_NWC_API
LiNwcAutodeskMaterialCreate();

/**
 * Destroy an Autodesk material.
 *
 * \param material material to destroy
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskMaterialDestroy(LtNwcAutodeskMaterial material);

/**
 * Sets the asset for the material.
 *
 * \param material material to set asset on.
 * \param asset asset to assign to material.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskMaterialSetMaterialAsset(LtNwcAutodeskMaterial material,
                                      LtNwcAutodeskAsset asset);
/**
 * Sets the json asset for the material.
 *
 * \param material material to set asset on.
 * \param json_asset json asset to assign to material.
 * \version 13.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskMaterialSetMaterialJsonAsset(LtNwcAutodeskMaterial material,
                                      LtNwcAutodeskJsonAsset json_asset);
#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcAutodeskMaterial API calls
 *
 * \see LiNwcAutodeskMaterial.h
 */
class LcNwcAutodeskMaterial : public LcNwcAttribute
{
public:
   LcNwcAutodeskMaterial() : LcNwcAttribute(LiNwcAutodeskMaterialCreate(), true) {}
   LcNwcAutodeskMaterial(LtNwcAutodeskMaterial handle) : LcNwcAttribute(handle) {}

   operator LtNwcAutodeskMaterial () const
   { return static_cast<LtNwcAutodeskMaterial>(LcNwcAttribute::GetHandle()); }
   LtNwcAutodeskMaterial GetHandle() const
   { return static_cast<LtNwcAutodeskMaterial>(LcNwcAttribute::GetHandle()); }

   void SetMaterialAsset(LtNwcAutodeskAsset asset)
   { LiNwcAutodeskMaterialSetMaterialAsset(GetHandle(), asset); }

   void SetMaterialJsonAsset(LtNwcAutodeskJsonAsset json_asset)
   { LiNwcAutodeskMaterialSetMaterialJsonAsset(GetHandle(), json_asset); }
};

#endif

#endif // LINWCAUTODESKMATERIAL_HDR
