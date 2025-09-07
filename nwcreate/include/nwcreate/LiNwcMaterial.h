/**
 * \file
 *
 * An attribute that defines a material. The lowest material on the path
 * to geometry is the one used for that geometry. The material model is
 * based on that used by OpenGL and VRML and supports a Phong lighting
 * model with specular highlights and transparency. Where only a simple
 * color is required, set both ambient and diffuse color to this color and
 * leave all other settings at their defaults.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2001
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCMATERIAL_HDR
#define LINWCMATERIAL_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a material.
 *
 * \return Newly created material or NULL on error
 */
LI_NWC_PUBLIC LtNwcMaterial LI_NWC_API
LiNwcMaterialCreate();

/**
 * Set the material's diffuse color
 *
 * \param material Material whose diffuse color is to be set
 * \param r Red component of color (in range 0 to 1)
 * \param g Green component of color (in range 0 to 1)
 * \param b Blue component of color (in range 0 to 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcMaterialSetDiffuseColor(LtNwcMaterial material,
                             LtFloat r, LtFloat g, LtFloat b);


/**
 * Set the material's ambient color
 *
 * \param material Material whose ambient color is to be set
 * \param r Red component of color (in range 0 to 1)
 * \param g Green component of color (in range 0 to 1)
 * \param b Blue component of color (in range 0 to 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcMaterialSetAmbientColor(LtNwcMaterial material,
                             LtFloat r, LtFloat g, LtFloat b);


/**
 * Set the material's specular color
 *
 * \param material Material whose specular color is to be set
 * \param r Red component of color (in range 0 to 1)
 * \param g Green component of color (in range 0 to 1)
 * \param b Blue component of color (in range 0 to 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcMaterialSetSpecularColor(LtNwcMaterial material,
                              LtFloat r, LtFloat g, LtFloat b);

/**
 * Set the material's emissive color
 *
 * \param material Material whose emissive color is to be set
 * \param r Red component of color (in range 0 to 1)
 * \param g Green component of color (in range 0 to 1)
 * \param b Blue component of color (in range 0 to 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcMaterialSetEmissiveColor(LtNwcMaterial material,
                              LtFloat r, LtFloat g, LtFloat b);


/**
 * Set the material's shininess
 *
 * \param material Material whose shininess is to be set
 * \param t Shininess (in range 0 to 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcMaterialSetShininess(LtNwcMaterial material,
                          LtFloat t);

/**
 * Set the material's transparency
 *
 * \param material Material whose transparency is to be set
 * \param t Transparency (in range 0 to 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcMaterialSetTransparency(LtNwcMaterial material,
                             LtFloat t);

/**
 * Destroy a NavisWorks material.
 *
 * \param material Material to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcMaterialDestroy(LtNwcMaterial material);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcMaterial API calls
 *
 * \see LiNwcMaterial.h
 */
class LcNwcMaterial : public LcNwcAttribute
{
public:
   LcNwcMaterial() : LcNwcAttribute(LiNwcMaterialCreate(), true) {}
   LcNwcMaterial(LtNwcMaterial handle) : LcNwcAttribute(handle) {}

   operator LtNwcMaterial () const
   { return static_cast<LtNwcMaterial>(LcNwcAttribute::GetHandle()); }
   LtNwcMaterial GetHandle() const
   { return static_cast<LtNwcMaterial>(LcNwcAttribute::GetHandle()); }

   void SetDiffuseColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcMaterialSetDiffuseColor(GetHandle(), r, g, b); }

   void SetAmbientColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcMaterialSetAmbientColor(GetHandle(), r, g, b); }

   void SetSpecularColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcMaterialSetSpecularColor(GetHandle(), r, g, b); }

   void SetEmissiveColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcMaterialSetEmissiveColor(GetHandle(), r, g, b); }

   void SetShininess(LtFloat t)
   { LiNwcMaterialSetShininess(GetHandle(), t); }

   void SetTransparency(LtFloat t)
   { LiNwcMaterialSetTransparency(GetHandle(), t); }
};

#endif

#endif /* LINWCMATERIAL_HDR */
