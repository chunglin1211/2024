/**
 * \file
 *
 * A saved view that defines an animation constructed from LtNwcView
 * key frames and LtNwcCutView cuts.
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

#ifndef LINWCANIMVIEW_HDR
#define LINWCANIMVIEW_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcSavedView.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an empty NavisWorks animation.
 *
 * \return Newly created anim or NULL on error.
 */
LI_NWC_PUBLIC LtNwcAnimView LI_NWC_API
LiNwcAnimViewCreate();

/**
 * Add a saved view to an animation.
 *
 * \param anim Animation to add view too.
 * \param view View to add.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAnimViewAddSavedView(LtNwcAnimView anim, LtNwcSavedView view);

/**
 * Set loop property for an animation. If true animation will loop
 * continuously on playback.
 *
 * \param anim Animation to set loop property for.
 * \param loop true to enable looping, false for default.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAnimViewSetLoop(LtNwcAnimView anim, bool loop);

/**
 * Specifies what smoothing should be applied to animation playback.
 */
typedef enum LtNwcSmoothing__tag
{
   LI_NWC_SMOOTH_NONE, ///< Simple linear interpolation between frames
   LI_NWC_SMOOTH_SYNC, ///< Sync interpolation of each property (pos, rot, ...)
} LtNwcSmoothing;

/**
 * Set smoothing property for an animation
 *
 * \param anim Animation to set smoothing property for.
 * \param smoothing Smoothing type to set.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAnimViewSetSmoothing(LtNwcAnimView anim, LtNwcSmoothing smoothing);

/**
 * Destroy a NavisWorks animation
 *
 * \param anim - Animation to destroy.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcAnimViewDestroy(LtNwcAnimView anim);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcAnimView API calls
 *
 * \see LiNwcAnimView.h
 */
class LcNwcAnimView : public LcNwcSavedView
{
public:
   LcNwcAnimView() : LcNwcSavedView(LiNwcAnimViewCreate(), true) {}
   LcNwcAnimView(LtNwcAnimView handle) : LcNwcSavedView(handle, false) {}

   operator LtNwcAnimView () const
   { return static_cast<LtNwcAnimView>(LcNwcSavedView::GetHandle()); }
   LtNwcAnimView GetHandle() const
   { return static_cast<LtNwcAnimView>(LcNwcSavedView::GetHandle()); }

   void SetLoop(bool loop)
   { LiNwcAnimViewSetLoop(GetHandle(), loop); }

   void SetSmoothing(LtNwcSmoothing smoothing)
   { LiNwcAnimViewSetSmoothing(GetHandle(), smoothing); }

   void AddSavedView(LtNwcSavedView view)
   { LiNwcAnimViewAddSavedView(GetHandle(), view); }

private:
   // Can't copy
   LcNwcAnimView(const LcNwcAnimView&);
   LcNwcAnimView& operator= (const LcNwcAnimView&);
};

#endif

#endif /* LINWCANIMVIEW_HDR */
