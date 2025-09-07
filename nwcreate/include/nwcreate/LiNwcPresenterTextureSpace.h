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

#ifndef LINWCPRESENTERTEXTURESPACE_HDR
#define LINWCPRESENTERTEXTURESPACE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>
#include <nwcreate/LiNwcData.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Texture space class types
 */
typedef enum LtNwcPresenterTextureSpaceClass__tag {
   LI_NWC_TEX_SPACE_BOX,       // Box (no arguments)
   LI_NWC_TEX_SPACE_PLANE,     // Plane
   LI_NWC_TEX_SPACE_CYLINDER,  // Cylinder
   LI_NWC_TEX_SPACE_SPHERE,    // Spherical
   LI_NWC_TEX_SPACE_EXPLICIT,  // Explicit (no arguments)
} LtNwcPresenterTextureSpaceClass;

/**
 * OBSOLETE: Returns null.
 *
 * Create a new NavisWorks texture space
 *
 * \return Newly created texture space or NULL on error.
 * \version 3.2
 */
LI_NWC_PUBLIC LtNwcPresenterTextureSpace LI_NWC_API
LiNwcPresenterTextureSpaceCreate(LtNwcPresenterTextureSpaceClass type);

/**
 * OBSOLETE: Does nothing.
 *
 * Set any of the texture space shader's arguments
 *
 * \return true on success, false on error.
 * \param texture_space Texture space whose argument is to be set
 * \param arg_name A valid argument name for this shader
 * \param arg Argument data to set
 * \version 3.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterTextureSpaceSetShaderArg(LtNwcPresenterTextureSpace texture_space,
                                       LtWideString arg_name,
                                       LtNwcPresenterData arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Destroy a NavisWorks texture space.
 *
 * \param texture_space Texture space to destroy
 * \version 3.2
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPresenterTextureSpaceDestroy(LtNwcPresenterTextureSpace texture_space);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPresenterTextureSpace API calls
 *
 * \see LiNwcPresenterTextureSpace.h
 */
class LcNwcPresenterTextureSpace : public LcNwcAttribute
{
public:
   LcNwcPresenterTextureSpace(LtNwcPresenterTextureSpaceClass type)
      : LcNwcAttribute(LiNwcPresenterTextureSpaceCreate(type), true)
   {}

   LcNwcPresenterTextureSpace(LtNwcPresenterTextureSpace handle)
      : LcNwcAttribute(handle)
   {}

   operator LtNwcPresenterTextureSpace () const
   { return static_cast<LtNwcPresenterTextureSpace>(LcNwcAttribute::GetHandle()); }

   LtNwcPresenterTextureSpace GetHandle() const
   { return static_cast<LtNwcPresenterTextureSpace>(LcNwcAttribute::GetHandle()); }

   bool SetShaderArg(LtWideString arg_name, LtNwcPresenterData arg)
   { return LiNwcPresenterTextureSpaceSetShaderArg(GetHandle(),
                                                   arg_name,
                                                   arg); }
};

#endif

#endif /* LINWCPRESENTERTEXTURESPACE_HDR */
