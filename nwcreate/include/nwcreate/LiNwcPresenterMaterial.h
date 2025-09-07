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

#ifndef LINWCPRESENTERMATERIAL_HDR
#define LINWCPRESENTERMATERIAL_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>
#include <nwcreate/LiNwcPresenterData.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * OBSOLETE: Presenter Material Shader class types
 */
typedef enum LtNwcShaderClass__tag {
   LI_NWC_SHADER_CLASS_COLOR,           /** Color Shader Class */
   LI_NWC_SHADER_CLASS_DISPLACEMENT,    /** Displacement ShaderClass */
   LI_NWC_SHADER_CLASS_REFLECTANCE,     /** Reflectance Shader Class */
   LI_NWC_SHADER_CLASS_TEXTURE_SPACE,   /** TextureSpace ShaderClass  */
   LI_NWC_SHADER_CLASS_TRANSPARENCY     /** Transparency Shader Class */
} LtNwcShaderClass;


/**
 * OBSOLETE: Returns null;
 *
 * Create a new NavisWorks Presenter material.
 *
 * \return Newly created material or NULL on error
 * \version 2.2
 */
LI_NWC_PUBLIC LtNwcPresenterMaterial LI_NWC_API
LiNwcPresenterMaterialCreate();

/**
 * OBSOLETE: Does nothing.
 *
 * Set the material's name
 *
 * \return true on success, false on error.
 * \param material Material whose diffuse color is to be set
 * \param name Name to be given to the material
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterMaterialSetName(LtNwcPresenterMaterial material,LtWideString name);


/**
 * OBSOLETE: Does nothing.
 *
 * Set any of the material's shader's to a named shader type
 *
 * \return true on success, false on error.
 * \param material Material whose shader type is to be set
 * \param shader_class Any of the predefined shader class's
 * \param shader_name A valid shader name
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterMaterialSetShader(LtNwcPresenterMaterial material,
                       LtNwcShaderClass shader_class,
                       LtWideString shader_name);

/**
 * OBSOLETE: Does nothing.
 *
 * Set any of the material's shader's arguments
 *
 * \return true on success, false on error.
 * \param material Material whose shader argument is to be set
 * \param shader_class Any of the predefined shader class's
 * \param arg_name A valid argument name for this shader
 * \param arg Argument data to set
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPresenterMaterialSetShaderArg(LtNwcPresenterMaterial material,
                       LtNwcShaderClass shader_class,
                       LtWideString arg_name,
                       LtNwcPresenterData arg);

/**
 * OBSOLETE: Does nothing.
 *
 * Destroy a NavisWorks Presenter material.
 *
 * \param material material to destroy
 * \version 2.2
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPresenterMaterialDestroy(LtNwcPresenterMaterial material);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPresenterMaterial API calls
 *
 * \see LiNwcPresenterMaterial.h
 */
class LcNwcPresenterMaterial : public LcNwcAttribute
{
public:
   LcNwcPresenterMaterial() : LcNwcAttribute(LiNwcPresenterMaterialCreate(), true) {}
   LcNwcPresenterMaterial(LtNwcPresenterMaterial handle) : LcNwcAttribute(handle) {}

   operator LtNwcPresenterMaterial () const
   { return static_cast<LtNwcPresenterMaterial>(LcNwcAttribute::GetHandle()); }
   LtNwcPresenterMaterial GetHandle() const
   { return static_cast<LtNwcPresenterMaterial>(LcNwcAttribute::GetHandle()); }

   bool SetName(LtWideString name)
   {return LiNwcPresenterMaterialSetName(GetHandle(),name);}

   bool SetShader(LtNwcShaderClass shader_class,LtWideString shader_name)
   {return LiNwcPresenterMaterialSetShader(GetHandle(),shader_class,shader_name);}

   bool SetShaderArg(LtNwcShaderClass shader_class,
                               LtWideString arg_name,LtNwcPresenterData arg)
   {return LiNwcPresenterMaterialSetShaderArg(GetHandle(),shader_class,arg_name,arg);}
};

#endif

#endif /* LINWCPRESENTERMATERIAL_HDR */
