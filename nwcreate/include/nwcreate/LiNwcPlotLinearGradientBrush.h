/**
 * \file
 *
 * Defines a linear gradient brush for filling a closed Path or coloring
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

#ifndef LINWCPLOTLINEARGRADIENTBRUSH_HDR
#define LINWCPLOTLINEARGRADIENTBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotBrush.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a linear gradient brush
 *
 *  \return Newly created brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotLinearGradientBrush LI_NWC_API
LiNwcPlotLinearGradientBrushCreate( void );

/**
 *  Create a reference to a linear gradient brush
 *
 *  \param brush Brush to which a reference is created
 *  \return Referenced brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotLinearGradientBrush LI_NWC_API
LiNwcPlotLinearGradientBrushCreateRef( LtNwcPlotLinearGradientBrush brush );

/**
 *  Destroy a linear gradient brush
 *
 *  \param brush Brush to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushDestroy( LtNwcPlotLinearGradientBrush brush );

/**
 *  Sets the transform to apply to the brush definition coordinates
 *
 *  \param brush The brush
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushSetTransform( LtNwcPlotLinearGradientBrush brush, LtNwcPlotTransform transform );

/**
 *  Sets the opacity factor to apply to the brush
 *
 *  \param brush The brush
 *  \param opacity_factor The factor to use (0 = transparent, 1 = opaque)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushSetOpacityFactor( LtNwcPlotLinearGradientBrush brush, LtFloat opacity_factor );

/**
 *  Sets the start point for the gradient
 *
 *  \param brush The brush
 *  \param point the point to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushSetStartPoint( LtNwcPlotLinearGradientBrush brush, LtPoint2d point );

/**
 *  Sets the end point for the gradient
 *
 *  \param brush The brush
 *  \param point the point to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushSetEndPoint( LtNwcPlotLinearGradientBrush brush, LtPoint2d point );

/**
 *  Begin the gradient color definition for the brush
 *
 *  \param brush The brush
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushOffsetColorsBegin( LtNwcPlotLinearGradientBrush brush );

/**
 *  Sets a gradient offset and color to apply to the brush
 *
 *  This offset color value is used to define the location and range of color progression for rendering the gradient.
 *
 *  \param brush The brush
 *  \param offset The offset factor into the gradient (between the start and end points)
 *  \param r the red value (0 to 1) of the color at the offset
 *  \param g the green value (0 to 1) of the color at the offset
 *  \param b the blue value (0 to 1) of the color at the offset
 *  \param a the alpha value (0 to 1) of the color at the offset
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushOffsetColor( LtNwcPlotLinearGradientBrush brush, LtFloat offset, LtFloat r, LtFloat g, LtFloat b, LtFloat a );

/**
 *  End the gradient color definition for the brush
 *
 *  \param brush The brush
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushOffsetColorsEnd( LtNwcPlotLinearGradientBrush brush );

/**
 *  Sets the spread method to apply to the brush
 *
 *  Describes how the brush should fill outside of the primary region.
 *  Valid values are pad, reflect and repeat.
 *
 *  \param brush The brush
 *  \param spread_method The spread method to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotLinearGradientBrushSetSpreadMethod( LtNwcPlotLinearGradientBrush brush, LtNwcPlotGradientBrushSpreadMethod spread_method );

#ifdef __cplusplus
}


/**
 * C++ wrapper around LtNwcPlotLinearGradientBrush API calls
 *
 * \see LiNwcPlotLinearGradientBrush.h
 */
class LcNwcPlotLinearGradientBrush : public LcNwcPlotBrush
{
public:
   LcNwcPlotLinearGradientBrush() : LcNwcPlotBrush(LiNwcPlotLinearGradientBrushCreate(), true) {}
   LcNwcPlotLinearGradientBrush(LtNwcPlotLinearGradientBrush handle) : LcNwcPlotBrush(handle) {}

   operator LtNwcPlotLinearGradientBrush () const
   { return static_cast<LtNwcPlotLinearGradientBrush>(LcNwcPlotBrush::GetHandle()); }
   LtNwcPlotLinearGradientBrush GetHandle() const
   { return static_cast<LtNwcPlotLinearGradientBrush>(LcNwcPlotBrush::GetHandle()); }

   void SetTransform( LtNwcPlotTransform transform )
   { LiNwcPlotLinearGradientBrushSetTransform( GetHandle(), transform ); }

   void SetOpacityFactor( LtFloat opacity_factor )
   { LiNwcPlotLinearGradientBrushSetOpacityFactor( GetHandle(), opacity_factor ); }

   void SetStartPoint( LtPoint2d point )
   { LiNwcPlotLinearGradientBrushSetStartPoint( GetHandle(), point ); }

   void SetEndPoint( LtPoint2d point )
   { LiNwcPlotLinearGradientBrushSetEndPoint( GetHandle(), point ); }

   void OffsetColorsBegin( void )
   { LiNwcPlotLinearGradientBrushOffsetColorsBegin( GetHandle() ); }

   void OffsetColor( LtFloat offset, LtFloat r, LtFloat g, LtFloat b, LtFloat a )
   { LiNwcPlotLinearGradientBrushOffsetColor( GetHandle(), offset, r, g, b, a ); }

   void OffsetColorsEnd( void )
   { LiNwcPlotLinearGradientBrushOffsetColorsEnd( GetHandle()); }

   void SetSpreadMethod( LtNwcPlotGradientBrushSpreadMethod spread_method )
   { LiNwcPlotLinearGradientBrushSetSpreadMethod( GetHandle(), spread_method ); }
};

#endif /* __cplusplus */

#endif /* LINWCPLOTLINEARGRADIENTBRUSH_HDR */
