/**
 * \file
 *
 * A view that contains other views. Used to create a logical
 * hierarchy that defines structure of saved viewpoints.
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

#ifndef LINWCFOLDERVIEW_HDR
#define LINWCFOLDERVIEW_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcSavedView.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an empty NavisWorks saved viewpoints folder
 *
 * \return Newly created folder or NULL on error
 */
LI_NWC_PUBLIC LtNwcFolderView LI_NWC_API
LiNwcFolderViewCreate();

/**
 * Add a view to a folder
 *
 * \param folder Folder to add view too
 * \param view View to add
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFolderViewAddSavedView(LtNwcFolderView folder, LtNwcSavedView view);

/**
 * Destroy a NavisWorks saved viewpoints folder.
 *
 * \param folder Folder to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFolderViewDestroy(LtNwcFolderView folder);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcFolderView API calls
 *
 * \see LiNwcFolderView.h
 */
class LcNwcFolderView : public LcNwcSavedView
{
public:
   LcNwcFolderView() : LcNwcSavedView(LiNwcFolderViewCreate(), true) {}
   LcNwcFolderView(LtNwcFolderView handle) : LcNwcSavedView(handle, false) {}

   operator LtNwcFolderView () const
   { return static_cast<LtNwcFolderView>(LcNwcSavedView::GetHandle()); }
   LtNwcFolderView GetHandle() const
   { return static_cast<LtNwcFolderView>(LcNwcSavedView::GetHandle()); }

   void AddSavedView(LtNwcSavedView view)
   { LiNwcFolderViewAddSavedView(GetHandle(), view); }

private:
   // Can't copy
   LcNwcFolderView(const LcNwcFolderView&);
   LcNwcFolderView& operator= (const LcNwcFolderView&);
};

#endif

#endif /* LINWCFOLDERVIEW_HDR */
