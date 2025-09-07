/**
 * \file
 *
 * A light positioned far away from the model that shines in
 * a given direction. For example, the sun as experienced by a model
 * on earth.
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

#ifndef LINWCDISTANTLIGHT_HDR
#define LINWCDISTANTLIGHT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcCommonLight.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a NavisWorks distant light
 *
 * \return Newly created distant light or NULL on error
 * \version 2.0
 */
LI_NWC_PUBLIC LtNwcDistantLight LI_NWC_API
LiNwcDistantLightCreate();

/**
 * Set direction light shines in.
 * \param light DistantLight direction is set for
 * \param x x coordinate of direction
 * \param y y coordinate of direction
 * \param z z coordinate of direction
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDistantLightSetDirection(LtNwcDistantLight light,
                              LtFloat x,
                              LtFloat y,
                              LtFloat z);

/**
 * Destroy a NavisWorks distant light
 *
 * \param light DistantLight to destroy
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcDistantLightDestroy(LtNwcDistantLight light);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcDistantLight API calls
 *
 * \see LiNwcDistantLight.h
 */
class LcNwcDistantLight : public LcNwcCommonLight
{
public:
   LcNwcDistantLight() : LcNwcCommonLight(LiNwcDistantLightCreate(), true) {}
   LcNwcDistantLight(LtNwcDistantLight handle) : LcNwcCommonLight(handle) {}

   operator LtNwcDistantLight () const
   { return static_cast<LtNwcDistantLight>(LcNwcCommonLight::GetHandle()); }
   LtNwcDistantLight GetHandle() const
   { return static_cast<LtNwcDistantLight>(LcNwcCommonLight::GetHandle()); }

   void SetDirection(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcDistantLightSetDirection(GetHandle(), x, y, z); }
};

#endif

#endif /* LINWCDISTANTLIGHT_HDR */
