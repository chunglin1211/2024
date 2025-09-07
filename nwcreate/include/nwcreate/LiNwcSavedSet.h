/**
 * \file
 *
 * Base type for saved sets. SavedSets are
 * used only as a common base type and cannot be created directly.
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

#ifndef LINWCSAVEDSET_HDR
#define LINWCSAVEDSET_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set the name of a saved set.
 *
 * \param set Saved set to set name of.
 * \param name Name to give set.
 * \version 7.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSavedSetSetName(LtNwcSavedSet set,
                     LtWideString name);

/**
 * Set the guid of a saved set.
 *
 * \param set Saved set to set name of.
 * \param guid guid to give set.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSavedSetSetGuid(LtNwcSavedSet set,
                     LtNwcGuid guid);

/**
 * Destroy a NavisWorks saved set of any type.
 *
 * \param set Saved set to destroy.
 * \version 7.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSavedSetDestroy(LtNwcSavedSet set);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSavedSet API calls
 *
 * \see LiNwcSavedSet.h
 */
class LcNwcSavedSet
{
public:
   LcNwcSavedSet(LtNwcSavedSet handle) : m_handle(handle), m_own(false) {}
   virtual ~LcNwcSavedSet() { if (m_own) LiNwcSavedSetDestroy(m_handle); }

   operator LtNwcSavedSet () const { return m_handle; }
   LtNwcSavedSet GetHandle() const { return m_handle; }

   void SetName(LtWideString name)
   { LiNwcSavedSetSetName(m_handle, name); }

   void SetGuid(LtNwcGuid guid)
   { LiNwcSavedSetSetGuid(m_handle, guid);  }

protected:
   LcNwcSavedSet(LtNwcSavedSet handle, bool own)
      : m_handle(handle), m_own(own) {}

private:
   // Can't copy
   LcNwcSavedSet(const LcNwcSavedSet&);
   LcNwcSavedSet& operator= (const LcNwcSavedSet&);

   LtNwcSavedSet m_handle;
   bool m_own;
};

#endif

#endif /* LINWCSAVEDSET_HDR */
