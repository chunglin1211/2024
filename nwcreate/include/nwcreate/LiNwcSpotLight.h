/**
 * \file
 *
 * A light placed at a fixed position that shines in a given direction.
 * The light produced is defined by a cone whose apex is at the light's
 * position and whose axis is defined by the light's direction.
 *
 * For example, a torch or spotlight.
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
 */

#ifndef LINWCSPOTLIGHT_HDR
#define LINWCSPOTLIGHT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcCommonLight.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a NavisWorks spotlight
 *
 * \return Newly created spotlight or NULL on error
 * \version 2.0
 */
LI_NWC_PUBLIC LtNwcSpotLight LI_NWC_API
LiNwcSpotLightCreate();

/**
 * Set direction light shines in.
 *
 * \param light SpotLight direction is set for
 * \param x x coordinate of direction
 * \param y y coordinate of direction
 * \param z z coordinate of direction
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSpotLightSetDirection(LtNwcSpotLight light,
                              LtFloat x,
                              LtFloat y,
                              LtFloat z);

/**
 * Set position of light.
 *
 * \param light SpotLight position is set for
 * \param x x coordinate of position
 * \param y y coordinate of position
 * \param z z coordinate of position
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSpotLightSetPosition(LtNwcSpotLight light,
                              LtFloat x,
                              LtFloat y,
                              LtFloat z);

/**
 * Set attentuation of light.
 *
 * Specifies how the intensity of the light
 * reduces with distance from it. The intensity of the light is scaled
 * by 1/(Kc + Kl*d + Kq*d*d) where d is the distance from the light
 * and Kc, Kl, Kq are constants.
 * Default: Constant intensity (Kc=1,Kl=0,Kq=0).
 *
 * \param light SpotLight attentuation is set for
 * \param Kc Constant attentuation factor
 * \param Kl Linear attentuation factor
 * \param Kq Quadratic attentuation factor
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSpotLightSetAttenuation(LtNwcSpotLight light,
                               LtFloat Kc,
                               LtFloat Kl,
                               LtFloat Kq);

/**
 * Set rate at which intensity drops off away from center of cone.
 *
 * 0 is constant intensity, 1 is very sharp drop off.
 * Default: 0
 *
 * \param light SpotLight drop off rate is set for
 * \param rate Drop off rate to set
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSpotLightSetDropOffRate(LtNwcSpotLight light,
                             LtFloat rate);

/**
 * Set angle at which beam cuts off measured between center and edge of
 * spotlight cone.
 *
 * Default: PI/4 (45 degrees)
 *
 * \param light SpotLight cut off angle is set for
 * \param angle Cut off angle in radians
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSpotLightSetCutOffAngle(LtNwcSpotLight light,
                            LtFloat angle);

/**
 * Destroy a NavisWorks spot light
 *
 * \param light SpotLight to destroy
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSpotLightDestroy(LtNwcSpotLight light);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSpotLight API calls
 *
 * \see LiNwcSpotLight.h
 */
class LcNwcSpotLight : public LcNwcCommonLight
{
public:
   LcNwcSpotLight() : LcNwcCommonLight(LiNwcSpotLightCreate(), true) {}
   LcNwcSpotLight(LtNwcSpotLight handle) : LcNwcCommonLight(handle) {}

   operator LtNwcSpotLight () const
   { return static_cast<LtNwcSpotLight>(LcNwcCommonLight::GetHandle()); }
   LtNwcSpotLight GetHandle() const
   { return static_cast<LtNwcSpotLight>(LcNwcCommonLight::GetHandle()); }

   void SetDirection(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcSpotLightSetDirection(GetHandle(), x, y, z); }

   void SetPosition(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcSpotLightSetPosition(GetHandle(), x, y, z); }

   void SetAttenuation(LtFloat Kc, LtFloat Kl, LtFloat Kq)
   { LiNwcSpotLightSetAttenuation(GetHandle(), Kc, Kl, Kq); }

   void SetDropOffRate(LtFloat rate)
   { LiNwcSpotLightSetDropOffRate(GetHandle(), rate); }
   void SetCutOffAngle(LtFloat radians)
   { LiNwcSpotLightSetCutOffAngle(GetHandle(), radians); }
};

#endif

#endif /** LINWCSPOTLIGHT_HDR */
