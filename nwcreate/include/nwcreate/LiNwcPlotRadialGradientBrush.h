/**
 * \file
 *
 * Defines a radial gradient brush for filling a closed Path or coloring
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

#ifndef LINWCPLOTRADIALGRADIENTBRUSH_HDR
#define LINWCPLOTRADIALGRADIENTBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotBrush.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a radial gradient brush
 *
 *  \return Newly created brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotRadialGradientBrush LI_NWC_API
LiNwcPlotRadialGradientBrushCreate( void );

/**
 *  Create a reference to a radial gradient brush
 *
 *  \param brush Brush to which a reference is created
 *  \return Referenced brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotRadialGradientBrush LI_NWC_API
LiNwcPlotRadialGradientBrushCreateRef( LtNwcPlotRadialGradientBrush brush );

/**
 *  Destroy a radial gradient brush
 *
 *  \param brush Brush to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushDestroy( LtNwcPlotRadialGradientBrush brush );

/**
 *  Sets the transform to apply to the brush definition coordinates
 *
 *  \param brush The brush
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushSetTransform( LtNwcPlotRadialGradientBrush brush, LtNwcPlotTransform transform );

/**
 *  Sets the opacity factor to apply to the brush
 *
 *  \param brush The brush
 *  \param opacity_factor The factor to use (0 = transparent, 1 = opaque)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushSetOpacityFactor( LtNwcPlotRadialGradientBrush brush, LtFloat opacity_factor );

/**
 *  Sets the center point of the gradient to apply to the brush
 *
 *  Specify the center point of the radial gradient brush.
 *
 *  \param brush The brush
 *  \param point The center point of the ellipse defining the extent of the gradient color definition
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushSetCenterPoint( LtNwcPlotRadialGradientBrush brush, LtPoint2d point );

/**
 *  Sets the origin point of the gradient
 *
 *  \param brush The brush
 *  \param point The center point of the gradient, from which the gradient interpolation begins
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushSetGradientOriginPoint( LtNwcPlotRadialGradientBrush brush, LtPoint2d point );

/**
 *  Sets the major radius of the gradient ellipse
 *
 *  \param brush The brush
 *  \param radius The radius to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushSetMajorRadius( LtNwcPlotRadialGradientBrush brush, LtFloat radius );

/**
 *  Sets the minor radius of the gradient ellipse
 *
 *  \param brush The brush
 *  \param radius The radius to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushSetMinorRadius( LtNwcPlotRadialGradientBrush brush, LtFloat radius );

/**
 *  Begin the gradient color definition for the brush
 *
 *  \param brush The brush
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushOffsetColorsBegin( LtNwcPlotRadialGradientBrush brush );

/**
 *  Sets a gradient offset and color to apply to the brush
 *
 *  This offset color value is used to define the location and range of color progression for rendering the gradient.
 *
 *  \param brush The brush
 *  \param offset_factor The offset factor into the gradient (between the start and end points)
 *  \param r the red value (0 to 1) of the color at the offset
 *  \param g the green value (0 to 1) of the color at the offset
 *  \param b the blue value (0 to 1) of the color at the offset
 *  \param a the alpha value (0 to 1) of the color at the offset
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushOffsetColor( LtNwcPlotRadialGradientBrush brush, LtFloat offset_factor, LtFloat r, LtFloat g, LtFloat b, LtFloat a );

/**
 *  End the gradient color definition for the brush
 *
 *  \param brush The brush
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotRadialGradientBrushOffsetColorsEnd( LtNwcPlotRadialGradientBrush brush );

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
LiNwcPlotRadialGradientBrushSetSpreadMethod( LtNwcPlotRadialGradientBrush brush, LtNwcPlotGradientBrushSpreadMethod spread_method );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotRadialGradientBrush API calls
 *
 * \see LiNwcPlotRadialGradientBrush.h
 */
class LcNwcPlotRadialGradientBrush : public LcNwcPlotBrush
{
public:
   LcNwcPlotRadialGradientBrush() : LcNwcPlotBrush(LiNwcPlotRadialGradientBrushCreate(), true) {}
   LcNwcPlotRadialGradientBrush(LtNwcPlotRadialGradientBrush handle) : LcNwcPlotBrush(handle) {}

   operator LtNwcPlotRadialGradientBrush () const
   { return static_cast<LtNwcPlotRadialGradientBrush>(LcNwcPlotBrush::GetHandle()); }
   LtNwcPlotRadialGradientBrush GetHandle() const
   { return static_cast<LtNwcPlotRadialGradientBrush>(LcNwcPlotBrush::GetHandle()); }

   void SetTransform( LtNwcPlotTransform transform )
   { LiNwcPlotRadialGradientBrushSetTransform( GetHandle(), transform ); }

   void SetOpacityFactor( LtFloat opacity_factor )
   { LiNwcPlotRadialGradientBrushSetOpacityFactor( GetHandle(), opacity_factor ); }

   void SetCenterPoint( LtPoint2d point )
   { LiNwcPlotRadialGradientBrushSetCenterPoint( GetHandle(), point ); }

   void SetGradientOriginPoint( LtPoint2d point )
   { LiNwcPlotRadialGradientBrushSetGradientOriginPoint( GetHandle(), point ); }

   void SetMajorRadius( LtFloat radius )
   { LiNwcPlotRadialGradientBrushSetMajorRadius( GetHandle(), radius ); }

   void SetMinorRadius( LtFloat radius )
   { LiNwcPlotRadialGradientBrushSetMinorRadius( GetHandle(), radius ); }

   void OffsetColorsBegin( void )
   { LiNwcPlotRadialGradientBrushOffsetColorsBegin( GetHandle()); }

   void OffsetColor( LtFloat offset_factor, LtFloat r, LtFloat g, LtFloat b, LtFloat a )
   { LiNwcPlotRadialGradientBrushOffsetColor( GetHandle(), offset_factor, r, g, b, a ); }

   void OffsetColorsEnd( void )
   { LiNwcPlotRadialGradientBrushOffsetColorsEnd( GetHandle()); }

   void SetSpreadMethod( LtNwcPlotGradientBrushSpreadMethod spread_method )
   { LiNwcPlotRadialGradientBrushSetSpreadMethod( GetHandle(), spread_method ); }
};

#endif /* __cplusplus */

#endif /* LINWCPLOTRADIALGRADIENTBRUSH_HDR */
