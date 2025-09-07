/**
 * \file
 *
 * Defines a solid color brush for filling a closed Path or coloring
 * a Stroke.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2009 Autodesk, Inc. All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 *
 */

#ifndef LINWCPLOTSOLIDCOLORBRUSH_HDR
#define LINWCPLOTSOLIDCOLORBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotBrush.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a solid color brush
 *
 *  \return Newly created brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotSolidColorBrush LI_NWC_API
LiNwcPlotSolidColorBrushCreate( void );

/**
 *  Create a reference to a solid color brush
 *
 *  \param brush Brush to which a reference is created
 *  \return Referenced brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotSolidColorBrush LI_NWC_API
LiNwcPlotSolidColorBrushCreateRef( LtNwcPlotSolidColorBrush brush );

/**
 *  Destroy a solid color brush
 *
 *  \param brush Brush to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotSolidColorBrushDestroy( LtNwcPlotSolidColorBrush brush );

/**
 *  Sets the color to apply to the brush
 *
 *  \param brush The brush
 *  \param r the red value (0 to 1) of the color at the offset
 *  \param g the green value (0 to 1) of the color at the offset
 *  \param b the blue value (0 to 1) of the color at the offset
 *  \param a the alpha value (0 to 1) of the color at the offset
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotSolidColorBrushSetColor( LtNwcPlotSolidColorBrush brush, LtFloat r, LtFloat g, LtFloat b, LtFloat a );

#ifdef __cplusplus
}


/**
 * C++ wrapper around LtNwcPlotSolidColorBrush API calls
 *
 * \see LiNwcPlotSolidColorBrush.h
 */
class LcNwcPlotSolidColorBrush : public LcNwcPlotBrush
{
public:
   LcNwcPlotSolidColorBrush() : LcNwcPlotBrush(LiNwcPlotSolidColorBrushCreate(), true) {}
   LcNwcPlotSolidColorBrush(LtNwcPlotSolidColorBrush handle) : LcNwcPlotBrush(handle) {}

   operator LtNwcPlotSolidColorBrush () const
   { return static_cast<LtNwcPlotSolidColorBrush>(LcNwcPlotBrush::GetHandle()); }
   LtNwcPlotSolidColorBrush GetHandle() const
   { return static_cast<LtNwcPlotSolidColorBrush>(LcNwcPlotBrush::GetHandle()); }

   void SetColor( LtFloat r, LtFloat g, LtFloat b, LtFloat a )
   { LiNwcPlotSolidColorBrushSetColor( GetHandle(), r, g, b, a ); }
};

#endif /* __cplusplus */

#endif /* LINWCPLOTSOLIDCOLORBRUSH_HDR */
