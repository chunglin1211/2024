/**
 * \file
 *
 * Attribute that describes the semantic priority of this node and
 * any children. The dynamic rendering priority of geometry is scaled
 * by the semantic priority. For example, geometry with a semantic
 * priority of 10, is 10 times more likely to be rendered than
 * equivalent geometry with a priority of 1.
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

#ifndef LINWCSEMANTICPRIORITY_HDR
#define LINWCSEMANTICPRIORITY_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a priority attribute
 *
 * \return Newly created attribute or NULL on error
 */
LI_NWC_PUBLIC LtNwcSemanticPriority LI_NWC_API
LiNwcSemanticPriorityCreate();

/**
 * Set priority
 *
 * \param attribute Attribute to set priority for
 * \param priority Priority to set. 1 is normal priority.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSemanticPrioritySetPriority(LtNwcSemanticPriority attribute,
                                 LtFloat priority);

/**
 * Destroy a priority attribute
 *
 * \param attribute Attribute to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSemanticPriorityDestroy(LtNwcSemanticPriority attribute);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSemanticPriority API calls
 *
 * \see LiNwcSemanticPriority.h
 */
class LcNwcSemanticPriority : public LcNwcAttribute
{
public:
   LcNwcSemanticPriority() : LcNwcAttribute(LiNwcSemanticPriorityCreate(), true) {}
   LcNwcSemanticPriority(LtNwcSemanticPriority handle) : LcNwcAttribute(handle) {}

   operator LtNwcSemanticPriority () const
   { return static_cast<LtNwcSemanticPriority>(LcNwcAttribute::GetHandle()); }
   LtNwcSemanticPriority GetHandle() const
   { return static_cast<LtNwcSemanticPriority>(LcNwcAttribute::GetHandle()); }

   void SetPriority(LtFloat priority)
   { LiNwcSemanticPrioritySetPriority(GetHandle(), priority); }
};

#endif

#endif /* LINWCSEMANTICPRIORITY_HDR */
