/**
 * \file
 *
 * Base type for objects that represent lights. CommonLights are
 * used only as a common base type and cannot be created or destroyed.
 *
 * Light functionality matches that defined in OpenGL. A "normal" light
 * will have identical diffuse and ambient colors and a
 * specular color of (1,1,1).
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

#ifndef LINWCCOMMONLIGHT_HDR
#define LINWCCOMMONLIGHT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set the light's diffuse color
 *
 * \param light CommonLight whose diffuse color is to be set
 * \param r Red component of color (in range 0 to 1)
 * \param g Green component of color (in range 0 to 1)
 * \param b Blue component of color (in range 0 to 1)
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightSetDiffuseColor(LtNwcCommonLight light,
                             LtFloat r, LtFloat g, LtFloat b);


/**
 * Set the light's ambient color
 *
 * \param light CommonLight whose ambient color is to be set
 * \param r Red component of color (in range 0 to 1)
 * \param g Green component of color (in range 0 to 1)
 * \param b Blue component of color (in range 0 to 1)
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightSetAmbientColor(LtNwcCommonLight light,
                             LtFloat r, LtFloat g, LtFloat b);


/**
 * Set the light's specular color
 *
 * \param light CommonLight whose specular color is to be set
 * \param r Red component of color (in range 0 to 1)
 * \param g Green component of color (in range 0 to 1)
 * \param b Blue component of color (in range 0 to 1)
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightSetSpecularColor(LtNwcCommonLight light,
                              LtFloat r, LtFloat g, LtFloat b);

/**
 * Define if light is on
 *
 * \param light CommonLight to set on status for
 * \param b true to turn on, false to turn off
 * \version 2.2
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightSetOn(LtNwcCommonLight light, bool b);

/**
 * Define the light in eye space (light moves with the camera) rather than
 * the default of world space (light is fixed relative to model).
 *
 * \param light CommonLight to set eye for
 * \param b true to define in eye space, false for default of world space
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightSetEye(LtNwcCommonLight light, bool b);

/**
 * Create a reference to a NavisWorks light of any type
 *
 * \param light CommonLight to reference
 * \return reference to light
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcCommonLight LI_NWC_API
LiNwcCommonLightCreateRef(LtNwcCommonLight light);

/**
 * Destroy a NavisWorks light of any type
 *
 * \param light CommonLight to destroy
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightDestroy(LtNwcCommonLight light);

/**
 * Set a Autodesk light
 *
 * \param light CommonLight to set the Autodesk light to.
 * \param asset Autodesk light
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightSetAutodeskLight(LtNwcCommonLight light, LtNwcAutodeskAsset asset);

/**
 * Set a Autodesk json light
 *
 * \param light CommonLight to set the Autodesk json light to.
 * \param json_asset Autodesk json light
 * \version 13.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCommonLightSetAutodeskJsonLight(LtNwcCommonLight light, LtNwcAutodeskJsonAsset json_asset);
#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcCommonLight API calls
 *
 * \see LiNwcCommonLight.h
 */
class LcNwcCommonLight
{
public:
   LcNwcCommonLight(LtNwcCommonLight handle) : m_handle(LiNwcCommonLightCreateRef(handle)) {}
   ~LcNwcCommonLight() { LiNwcCommonLightDestroy(m_handle); }

   LcNwcCommonLight(const LcNwcCommonLight &other) : m_handle(LiNwcCommonLightCreateRef(other)) {}

   LcNwcCommonLight& operator = (const LcNwcCommonLight &other)
   {LiNwcCommonLightDestroy(m_handle); m_handle = LiNwcCommonLightCreateRef(other); return *this;}

   operator LtNwcCommonLight () const { return m_handle; }
   LtNwcCommonLight GetHandle() const { return m_handle; }

   void SetDiffuseColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcCommonLightSetDiffuseColor(GetHandle(), r, g, b); }

   void SetAmbientColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcCommonLightSetAmbientColor(GetHandle(), r, g, b); }

   void SetSpecularColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcCommonLightSetSpecularColor(GetHandle(), r, g, b); }

   void SetEye(bool b)
   { LiNwcCommonLightSetEye(GetHandle(), b); }

   void SetOn(bool b)
   { LiNwcCommonLightSetOn(GetHandle(), b); }

   void SetAutodeskLight(LtNwcAutodeskAsset lasset)
   { LiNwcCommonLightSetAutodeskLight(GetHandle(), lasset); }

protected:
   LcNwcCommonLight(LtNwcCommonLight handle, bool /*own*/)
      : m_handle(handle) {}

private:

   LtNwcCommonLight m_handle;
};

#endif

#endif /* LINWCCOMMONLIGHT_HDR */
