/**
 * \file
 *
 * A light placed at a fixed position, shining equally in all positions.
 * For example, a light bulb.
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

#ifndef LINWCPOINTLIGHT_HDR
#define LINWCPOINTLIGHT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcCommonLight.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a NavisWorks point light
 *
 * \return Newly created point light or NULL on error
 * \version 2.0
 */
LI_NWC_PUBLIC LtNwcPointLight LI_NWC_API
LiNwcPointLightCreate();

/**
 * Set position of light.
 * \param light PointLight position is set for
 * \param x x coordinate of position
 * \param y y coordinate of position
 * \param z z coordinate of position
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPointLightSetPosition(LtNwcPointLight light,
                              LtFloat x,
                              LtFloat y,
                              LtFloat z);

/**
 * Set attentuation of light. Specifies how the intensity of the light
 * reduces with distance from it. The intensity of the light is scaled
 * by 1/(Kc + Kl*d + Kq*d*d) where d is the distance from the light
 * and Kc, Kl, Kq are constants.
 * Default: Constant intensity (Kc=1,Kl=0,Kq=0).
 * \param light PointLight attentuation is set for
 * \param Kc Constant attentuation factor
 * \param Kl Linear attentuation factor
 * \param Kq Quadratic attentuation factor
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPointLightSetAttenuation(LtNwcPointLight light,
                               LtFloat Kc,
                               LtFloat Kl,
                               LtFloat Kq);

/**
 * Destroy a NavisWorks point light
 *
 * \param light PointLight to destroy
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPointLightDestroy(LtNwcPointLight light);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPointLight API calls
 *
 * \see LiNwcPointLight.h
 */
class LcNwcPointLight : public LcNwcCommonLight
{
public:
   LcNwcPointLight() : LcNwcCommonLight(LiNwcPointLightCreate(), true) {}
   LcNwcPointLight(LtNwcPointLight handle) : LcNwcCommonLight(handle) {}

   operator LtNwcPointLight () const
   { return static_cast<LtNwcPointLight>(LcNwcCommonLight::GetHandle()); }
   LtNwcPointLight GetHandle() const
   { return static_cast<LtNwcPointLight>(LcNwcCommonLight::GetHandle()); }

   void SetPosition(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcPointLightSetPosition(GetHandle(), x, y, z); }

   void SetAttenuation(LtFloat Kc, LtFloat Kl, LtFloat Kq)
   { LiNwcPointLightSetAttenuation(GetHandle(), Kc, Kl, Kq); }
};

#endif

#endif /* LINWCPOINTLIGHT_HDR */
