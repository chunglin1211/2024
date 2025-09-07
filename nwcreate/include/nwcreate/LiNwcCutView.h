/**
 * \file
 *
 * A view that defines a cut in an animation sequence.
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

#ifndef LINWCCUTVIEW_HDR
#define LINWCCUTVIEW_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcSavedView.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a cut
 *
 * \return Newly created cut or NULL on error
 */
LI_NWC_PUBLIC LtNwcCutView LI_NWC_API
LiNwcCutViewCreate();

/**
 * Set the time to delay the animation before jumping to the next key frame.
 *
 * \param cut Cut to set delay for
 * \param delay Time in seconds. Default is 1 second
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCutViewSetDelay(LtNwcCutView cut, LtFloat delay);

/**
 * Destroy a cut.
 *
 * \param cut Cut to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCutViewDestroy(LtNwcCutView cut);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcCutView API calls
 *
 * \see LiNwcCutView.h
 */
class LcNwcCutView : public LcNwcSavedView
{
public:
   LcNwcCutView() : LcNwcSavedView(LiNwcCutViewCreate(), true) {}
   LcNwcCutView(LtNwcCutView handle) : LcNwcSavedView(handle, false) {}

   operator LtNwcCutView () const
   { return static_cast<LtNwcCutView>(LcNwcSavedView::GetHandle()); }
   LtNwcCutView GetHandle() const
   { return static_cast<LtNwcCutView>(LcNwcSavedView::GetHandle()); }

   void SetDelay(LtFloat delay)
   { LiNwcCutViewSetDelay(GetHandle(), delay); }

private:
   // Can't copy
   LcNwcCutView(const LcNwcCutView&);
   LcNwcCutView& operator= (const LcNwcCutView&);
};

#endif

#endif /* LINWCCUTVIEW_HDR */
