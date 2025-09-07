/**
 * \file
 *
 * Base type for objects that define logical structure of model. Nodes are
 * used only as a common base type and cannot be created or destroyed.
 *
 * The logical structure of the model is a directed acyclic graph. Nodes
 * may be added to more than one parent allowing multiple instancing.
 *
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

#ifndef LINWCNODE_HDR
#define LINWCNODE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set the name of a node. Appears in bold in NavisWorks tree view. Should
 * be the name that a CAD user would use to identify an object in the original
 * CAD system. e.g. Wall3, Bedroom Window.
 *
 * \param node Node to set name of
 * \param name Name to give node
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeSetName(LtNwcNode node, LtWideString name);

/**
 * Returns the name of a node. It will return NULL if no
 * name has been set on the node.
 *
 * \param node Node to get name of
 * \return name of node
 * \version 5.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcNodeGetName(LtNwcNode node);

/**
 * Set the class of a node. Appears in normal type in NavisWorks tree view
 * if the node has no name. Should be the name that a CAD user would use to
 * identify what sort of thing an object is. e.g. Wall, Window.
 *
 * \param node Node to set class of
 * \param user_name Name for user to see. Should be localized.
 * \param internal_name Name used internally when writing NavisWorks plugins. Should not be localized.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeSetClassName(LtNwcNode node, LtWideString user_name,
                      LtString internal_name);

/**
 * Make the node (and any children) hidden.
 *
 * \param node Node to hide
 * \param b true to hide, false for default
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeSetHidden(LtNwcNode node, bool b);

/**
 * Make the node (and any children) required. The node will never be dropped
 * out as detail.
 *
 * \param node Node to require
 * \param b true to require, false for default
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeSetRequired(LtNwcNode node, bool b);

/**
 * Make the node (and any children) two sided. Both sides of geometry will be
 * rendered. Default is to render only the front side.
 * In 4.0 and later all geometry defaults to two sided unless solid. This call
 * is ignored.
 *
 * \param node Node to make two sided
 * \param b true to render two sided, false for default
 * \version Before 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeSetTwoSided(LtNwcNode node, bool b);

/**
 * Set the auto merge state on the node.
 * When auto merge is enabled, composite nodes' children are collapsed.
 * When auto merge is disabled, the node's children are not collapsed.
 *
 * \param node Node to set the enable auto merge state on
 * \param enable_auto_merge The enable auto merge state, true by default
 * \version 21.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeSetEnableAutoMerge(LtNwcNode node, bool enable_auto_merge);

/**
 * Add an attribute to a node
 *
 * \param node Node to add attribute to
 * \param attribute Attribute to add
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeAddAttribute(LtNwcNode node, LtNwcAttribute attribute);

/**
 * Create a reference to a NavisWorks node of any type
 *
 * \param node Node to reference
 * \return reference to node
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcNode LI_NWC_API
LiNwcNodeCreateRef(LtNwcNode node);

/**
 * Set the GUID of the node
 *
 * \param node Node to set GUID of
 * \param guid GUID to give node
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeSetGuid(LtNwcNode node, LtNwcGuid  guid);

/**
 * Destroy a NavisWorks node of any type
 *
 * \param node Node to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcNodeDestroy(LtNwcNode node);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcNode API calls
 *
 * \see LiNwcNode.h
 */
class LcNwcNode
{
public:
   LcNwcNode(LtNwcNode handle) : m_handle(LiNwcNodeCreateRef(handle)) {}
   ~LcNwcNode() { LiNwcNodeDestroy(m_handle); }

   LcNwcNode(const LcNwcNode &other) : m_handle(LiNwcNodeCreateRef(other)) {}

   LcNwcNode& operator = (const LcNwcNode &other)
   { LiNwcNodeDestroy(m_handle); m_handle = LiNwcNodeCreateRef(other); return *this; }

   operator LtNwcNode () const { return m_handle; }
   LtNwcNode GetHandle() const { return m_handle; }

   LcNwcNode& operator = (LtNwcNode handle)
   { LiNwcNodeDestroy(m_handle); m_handle = LiNwcNodeCreateRef(handle); return *this; }

   void SetName(LtWideString name)
   { LiNwcNodeSetName(m_handle, name); }

   LtWideString GetName()
   { return LiNwcNodeGetName(m_handle); }

   void SetGuid(LtNwcGuid  guid)
   { LiNwcNodeSetGuid(m_handle, guid); }

   void SetClassName(LtWideString user_name, const char* internal_name)
   { LiNwcNodeSetClassName(m_handle, user_name, const_cast<LtString>(internal_name)); }

   void SetHidden(bool b)
   { LiNwcNodeSetHidden(m_handle, b); }

   void SetRequired(bool b)
   { LiNwcNodeSetRequired(m_handle, b); }

   void SetTwoSided(bool b)
   { LiNwcNodeSetTwoSided(m_handle, b); }

   void AddAttribute(LtNwcAttribute attrib)
   { LiNwcNodeAddAttribute(m_handle, attrib); }

   void SetEnableAutoMerge(bool b)
   { LiNwcNodeSetEnableAutoMerge(m_handle, b); }

protected:
   LcNwcNode(LtNwcNode handle, bool /*own*/)
      : m_handle(handle) {}

private:

   LtNwcNode m_handle;
};

#endif

#endif /* LINWCNODE_HDR */
