/**
 * \file
 *
 * An attribute that defines some arbitrary text. The text, name and
 * class text are visible in the NavisWorks properties dialog and to
 * NavisWorks plugins.
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

#ifndef LINWCTEXTATTRIBUTE_HDR
#define LINWCTEXTATTRIBUTE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a text attribute
 *
 * \return Newly created attribute or NULL on error
 */
LI_NWC_PUBLIC LtNwcTextAttribute LI_NWC_API
LiNwcTextAttributeCreate();

/**
 * Set the text to be stored in the attribute.
 *
 * \param attribute Attribute to set text for
 * \param text Text to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextAttributeSetText(LtNwcTextAttribute attribute, LtWideString text);

/**
 * Destroy a text attribute
 *
 * \param attribute Attribute to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextAttributeDestroy(LtNwcTextAttribute attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcTextAttribute API calls
 *
 * \see LiNwcTextAttribute.h
 */
class LcNwcTextAttribute : public LcNwcAttribute
{
public:
   LcNwcTextAttribute() : LcNwcAttribute(LiNwcTextAttributeCreate(), true) {}
   LcNwcTextAttribute(LtNwcTextAttribute handle) : LcNwcAttribute(handle) {}

   operator LtNwcTextAttribute () const
   { return static_cast<LtNwcTextAttribute>(LcNwcAttribute::GetHandle()); }
   LtNwcTextAttribute GetHandle() const
   { return static_cast<LtNwcTextAttribute>(LcNwcAttribute::GetHandle()); }

   void SetText(LtWideString text)
   { LiNwcTextAttributeSetText(GetHandle(), text); }
};

#endif

#endif /* LINWCTEXTATTRIBUTE_HDR */
