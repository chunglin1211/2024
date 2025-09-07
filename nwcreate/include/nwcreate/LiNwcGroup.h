/**
 * \file
 *
 * A node that contains other nodes. Used to create a logical
 * hierarchy that defines structure of a model.
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

#ifndef LINWCGROUP_HDR
#define LINWCGROUP_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcNode.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an empty NavisWorks group
 *
 * \return Newly created group or NULL on error
 */
LI_NWC_PUBLIC LtNwcGroup LI_NWC_API
LiNwcGroupCreate();

/**
 * Add a node to a group
 *
 * \param group Group to add node too
 * \param node Node to add
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGroupAddNode(LtNwcGroup group, LtNwcNode node);

/**
 * Destroy a NavisWorks group.
 *
 * \param group Group to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGroupDestroy(LtNwcGroup group);

/**
 * Mark a group as an insert.
 * Will use the insert icon in the NavisWorks tree view.
 *
 * As of version 10.0, this function now behaves differently. You can
 * only set a single type for a group. Possible options are:
 *
 * * Group (default)
 * * Insert
 * * Composite
 * * Collection
 * * Layer
 *
 * The last call that sets the type wins. See also LiNwcGroupSetLayer,
 * LiNwcGroupSetComposite, LiNwcGroupSetCollection.
 *
 * \param group Group to mark as insert
 * \param b if true, will set the group type to "Insert", otherwise function does nothing.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGroupSetInsert(LtNwcGroup group, bool b);

/**
 * Mark a group as a layer. Will use the layer icon in the NavisWorks tree view.
 *
 * As of version 10.0, this function behaves differently. See LiNwcGroupSetInsert for details.
 *
 * \param group Group to mark as layer
 * \param b if true, will set the group type to "Layer", otherwise function does nothing.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGroupSetLayer(LtNwcGroup group, bool b);

/**
 * Mark a group as a composite object. When using "Last Object" selection
 * behaviour in NavisWorks will stop selection at composite.
 *
 * As of version 10.0, this function behaves differently. See LiNwcGroupSetInsert for details.
 *
 * \param group Group to mark as composite
 * \param b if true, will set the group type to "Composite", otherwise function does nothing.
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGroupSetComposite(LtNwcGroup group, bool b);

/**
 * Mark a group as an abstract collection of objects. When using
 * "First Object" selection behaviour in NavisWorks will select
 * first non-collection descendent of group.
 *
 * \param group Group to mark as a collection
 * \param b if true, will set the group type to "Collection", otherwise function does nothing.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGroupSetCollection(LtNwcGroup group, bool b);

/**
 * Test a node handle to see if its actually a group.
 *
 * \param node Node whose type is to be tested
 * \return true if node is a group, false otherwise.
 * \version 3.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcGroupIsA(LtNwcNode node);

/**
 * Get the number of children nodes in a group.
 *
 * \param group Group to get number of children on.
 * \return Number of children nodes.
 * \version 3.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcGroupGetNumChildren(LtNwcGroup group);

/**
 * Get a child node of the group, using the index.
 *
 * \param group Group to get the child from.
 * \param pos Index position of the child to get.
 * \return A node representing the child node.
 * \version 3.0
 */
LI_NWC_PUBLIC LtNwcNode LI_NWC_API
LiNwcGroupGetChild(LtNwcGroup group, LtInt32 pos);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcGroup API calls
 *
 * \see LiNwcGroup.h
 */
class LcNwcGroup : public LcNwcNode
{
public:
   LcNwcGroup() : LcNwcNode(LiNwcGroupCreate(), true) {}
   LcNwcGroup(LtNwcGroup handle) : LcNwcNode(handle) {}

   operator LtNwcGroup () const
   { return static_cast<LtNwcGroup>(LcNwcNode::GetHandle()); }
   LtNwcGroup GetHandle() const
   { return static_cast<LtNwcGroup>(LcNwcNode::GetHandle()); }

   void SetInsert(bool b)
   { LiNwcGroupSetInsert(GetHandle(), b); }

   void SetLayer(bool b)
   { LiNwcGroupSetLayer(GetHandle(), b); }

   void SetComposite(bool b)
   { LiNwcGroupSetComposite(GetHandle(), b); }

   void SetCollection(bool b)
   { LiNwcGroupSetCollection(GetHandle(), b); }

   void AddNode(LtNwcNode node)
   { LiNwcGroupAddNode(GetHandle(), node); }

   LtInt32 GetNumChildren() const
   { return LiNwcGroupGetNumChildren(GetHandle()); }

   LtNwcNode GetChild(LtInt32 pos)
   { return LiNwcGroupGetChild(GetHandle(), pos); }
};

#endif

#endif /* LINWCGROUP_HDR */
