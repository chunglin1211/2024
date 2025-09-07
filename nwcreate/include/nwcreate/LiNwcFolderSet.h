/**
 * \file
 *
 * A saved set that can contain other saved sets. Allows you to create
 * a hierarchy of saved sets.
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

#ifndef LINWCFOLDERSET_HDR
#define LINWCFOLDERSET_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcSavedSet.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a new folder set.
 * \version 7.0
 */
LI_NWC_PUBLIC LtNwcFolderSet LI_NWC_API
LiNwcFolderSetCreate();

/**
 * Adds a saved set to a folder set.
 *
 * \param folder Folder to add set to.
 * \param set Set to add.
 * \version 7.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFolderSetAddSavedSet(LtNwcFolderSet folder,
                          LtNwcSavedSet set);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcFolderSet API calls
 *
 * \see LiNwcFolderSet.h
 */
class LcNwcFolderSet : public LcNwcSavedSet
{
public:
   LcNwcFolderSet() : LcNwcSavedSet(LiNwcFolderSetCreate(), true) {}
   LcNwcFolderSet(LtNwcFolderSet handle) : LcNwcSavedSet(handle, false) {}

   operator LtNwcFolderSet () const
   { return static_cast<LtNwcFolderSet>(LcNwcSavedSet::GetHandle()); }
   LtNwcFolderSet GetHandle() const
   { return static_cast<LtNwcFolderSet>(LcNwcSavedSet::GetHandle()); }

   void AddSavedSet(LtNwcSavedSet set)
   { LiNwcFolderSetAddSavedSet(GetHandle(), set); }

private:
   // Can't copy
   LcNwcFolderSet(const LcNwcFolderSet&);
   LcNwcFolderSet& operator= (const LcNwcFolderSet&);
};

#endif

#endif /* LINWCFOLDERSET_HDR */
