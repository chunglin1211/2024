/**
 * \file
 *
 * A saved set containing model nodes. Use these to create pre-defined
 * selections of items to be added to the scene.
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

#ifndef LINWCSELECTIONSET_HDR
#define LINWCSELECTIONSET_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcSavedSet.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a new selection set.
 * \version 7.0
 */
LI_NWC_PUBLIC LtNwcSelectionSet LI_NWC_API
LiNwcSelectionSetCreate();

/**
 * Adds a node to a selection set.
 *
 * \param set Set to add node to.
 * \param node Node to add.
 * \version 7.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSelectionSetAddNode(LtNwcSelectionSet set,
                         LtNwcNode node);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSelectionSet API calls
 *
 * \see LiNwcSelectionSet.h
 */
class LcNwcSelectionSet : public LcNwcSavedSet
{
public:
   LcNwcSelectionSet() : LcNwcSavedSet(LiNwcSelectionSetCreate(), true) {}
   LcNwcSelectionSet(LtNwcSelectionSet handle) : LcNwcSavedSet(handle, false) {}

   operator LtNwcSelectionSet () const
   { return static_cast<LtNwcSelectionSet>(LcNwcSavedSet::GetHandle()); }
   LtNwcSelectionSet GetHandle() const
   { return static_cast<LtNwcSelectionSet>(LcNwcSavedSet::GetHandle()); }

   void AddNode(LtNwcNode node)
   { LiNwcSelectionSetAddNode(GetHandle(), node); }

private:
   // Can't copy
   LcNwcSelectionSet(const LcNwcSelectionSet&);
   LcNwcSelectionSet& operator= (const LcNwcSelectionSet&);
};

#endif

#endif /* LINWCSELECTIONSET_HDR */
