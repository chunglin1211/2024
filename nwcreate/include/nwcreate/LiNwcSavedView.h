/**
 * \file
 *
 * Base type for all saved viewpoint types. SavedViews are
 * used only as a common base type and cannot be created directly.
 *
 * Saved views can be arranged in a tree using folders. A
 * view may only be added to one parent.
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

#ifndef LINWCSAVEDVIEW_HDR
#define LINWCSAVEDVIEW_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set the name of a view.
 *
 * \param view view to set name of
 * \param name Name to give view
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSavedViewSetName(LtNwcSavedView view, LtWideString name);

/**
 * Set the guid of a  view.
 *
 * \param view view to set guid of
 * \param guid guid to give view.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSavedViewSetGuid(LtNwcSavedView view, LtNwcGuid guid);

/**
 * Destroy a NavisWorks saved view of any type
 *
 * \param view Saved view to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSavedViewDestroy(LtNwcSavedView view);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcSavedView API calls
 *
 * \see LiNwcSavedView.h
 */
class LcNwcSavedView
{
public:
   LcNwcSavedView(LtNwcSavedView handle) : m_handle(handle), m_own(false) {}
   ~LcNwcSavedView() { if (m_own) LiNwcSavedViewDestroy(m_handle); }

   operator LtNwcSavedView () const { return m_handle; }
   LtNwcSavedView GetHandle() const { return m_handle; }

   void SetName(LtWideString name)
   { LiNwcSavedViewSetName(m_handle, name); }

   void SetGuid(LtNwcGuid guid)
   { LiNwcSavedViewSetGuid(m_handle, guid);  }

protected:
   LcNwcSavedView(LtNwcSavedView handle, bool own)
      : m_handle(handle), m_own(own) {}

private:
   // Can't copy
   LcNwcSavedView(const LcNwcSavedView&);
   LcNwcSavedView& operator= (const LcNwcSavedView&);

   LtNwcSavedView m_handle;
   bool m_own;
};

#endif

#endif /* LINWCSAVEDVIEW_HDR */
