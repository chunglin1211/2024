/**
 * \file
 *
 * Texture spaces for Autodesk Rendering
 */

 /*
  * Copyright Notice:
  *
  * Copyright 2022 Autodesk, Inc. All rights reserved.
  *
  * This computer source code and related instructions and
  * comments are the unpublished confidential and proprietary
  * information of Autodesk, Inc. and are protected under
  * United States and foreign intellectual property laws.
  * They may not be disclosed to, copied or used by any third
  * party without the prior written consent of Autodesk, Inc.
  *
  */

#ifndef LINWCAUTODESKTEXTURESPACE_HDR
#define LINWCAUTODESKTEXTURESPACE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Texture space class types
 */
typedef enum LtNwcAutodeskTextureSpaceClass__tag {
   LI_NWC_ADSK_TEX_SPACE_BOX,       // Box (no arguments)
   LI_NWC_ADSK_TEX_SPACE_PLANE,     // Plane
   LI_NWC_ADSK_TEX_SPACE_CYLINDER,  // Cylinder
   LI_NWC_ADSK_TEX_SPACE_SPHERE,    // Spherical
   LI_NWC_ADSK_TEX_SPACE_EXPLICIT,  // Explicit (no arguments)
} LtNwcAutodeskTextureSpaceClass;

/**
 * Create a new Autodesk material texture space
 *
 * \return Newly created texture space or NULL on error.
 * \version 20.1
 */
LI_NWC_PUBLIC LtNwcAutodeskTextureSpace LI_NWC_API
LiNwcAutodeskTextureSpaceCreate(LtNwcAutodeskTextureSpaceClass type);

/**
 * Set the transform part of the texture space mapping transform
 *
 * \param texture_space Texture space handle
 * \param x x coordinate of translation
 * \param y y coordinate of translation
 * \param z z coordinate of translation
 * \version 20.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskTextureSpaceSetTranslation(LtNwcAutodeskTextureSpace texture_space,
                                        LtFloat x,
                                        LtFloat y,
                                        LtFloat z);

/**
 * Set the scale part of the texture space mapping transform
 *
 * \param texture_space Texture space handle
 * \param x x value of the scale
 * \param y y value of the scale
 * \param z z value of the scale
 * \version 20.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskTextureSpaceSetScale(LtNwcAutodeskTextureSpace texture_space,
                                  LtFloat x,
                                  LtFloat y,
                                  LtFloat z);

/**
 * Set the rotation part of the texture space mapping transform
 * \param texture_space Texture space handle
 * \param a a component of the quaternion
 * \param b b component of the quaternion
 * \param c c component of the quaternion
 * \param d d component of the quaternion
 * \version 20.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskTextureSpaceSetRotation(LtNwcAutodeskTextureSpace texture_space,
                                     LtFloat a,
                                     LtFloat b,
                                     LtFloat c,
                                     LtFloat d);

/**
 * Destroy a Autodesk material texture space.
 *
 * \param texture_space Texture space to destroy
 * \version 20.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAutodeskTextureSpaceDestroy(LtNwcAutodeskTextureSpace texture_space);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcAutodeskTextureSpace API calls
 *
 * \see LiNwcAutodeskTextureSpace.h
 */
class LcNwcAutodeskTextureSpace
{
public:
   LcNwcAutodeskTextureSpace(LtNwcAutodeskTextureSpaceClass type)
      : m_handle(LiNwcAutodeskTextureSpaceCreate(type)), m_own(true)
   {}
   LcNwcAutodeskTextureSpace(LtNwcAutodeskTextureSpace handle)
      : m_handle(handle), m_own(false)
   {}
   ~LcNwcAutodeskTextureSpace()
   {
      if (m_own)
      {
         LiNwcAutodeskTextureSpaceDestroy(m_handle);
      }
   }

   operator LtNwcAutodeskTextureSpace () const
   { return m_handle; }

   LtNwcAutodeskTextureSpace GetHandle() const
   { return m_handle; }

   void SetTranslation(LtFloat x, LtFloat y, LtFloat z)
   { return LiNwcAutodeskTextureSpaceSetTranslation(GetHandle(), x, y, z); }
   void SetScale(LtFloat x, LtFloat y, LtFloat z)
   { return LiNwcAutodeskTextureSpaceSetScale(GetHandle(), x, y, z); }
   void SetRotation(LtFloat a, LtFloat b, LtFloat c, LtFloat d)
   { return LiNwcAutodeskTextureSpaceSetRotation(GetHandle(), a, b, c, d); }

private:

   LtNwcAutodeskTextureSpace m_handle;
   bool m_own;
};

#endif

#endif /* LINWCAUTODESKTEXTURESPACE_HDR */
