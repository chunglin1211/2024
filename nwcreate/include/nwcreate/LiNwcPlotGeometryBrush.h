/**
 * \file
 *
 * Defines a brush containing geometry used for filling a closed Path or
 * rendering a Stroke.
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

#ifndef LINWCPLOTGEOMETRYBRUSH_HDR
#define LINWCPLOTGEOMETRYBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotBrush.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create an geometry brush
 *
 *  \return Newly created brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotGeometryBrush LI_NWC_API
LiNwcPlotGeometryBrushCreate( void );

/**
 *  Create a reference to an geometry brush
 *
 *  \param brush Brush to which a reference is created
 *  \return Referenced brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotGeometryBrush LI_NWC_API
LiNwcPlotGeometryBrushCreateRef( LtNwcPlotGeometryBrush brush );

/**
 *  Destroy an geometry brush
 *
 *  \param brush Brush to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushDestroy( LtNwcPlotGeometryBrush brush );

/**
 *  Sets the transform to apply to the geometry brush
 *
 *  \param brush The brush
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushSetTransform( LtNwcPlotGeometryBrush brush, LtNwcPlotTransform transform );

/**
 *  Sets the opacity factor to apply to the geometry brush
 *
 *  \param brush The brush
 *  \param opacity_factor The factor to use (0 = transparent, 1 = opaque)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushSetOpacityFactor( LtNwcPlotGeometryBrush brush, LtFloat opacity_factor );

/**
 *  Sets the view source to apply to the geometry brush
 *
 *  View source defines the default coordinate system for the geometry resource.
 *
 *  \param brush The brush
 *  \param point The start point
 *  \param size The size of the source portion of the geometry
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushSetViewSource( LtNwcPlotGeometryBrush brush, LtPoint2d point, LtVector2d size );

/**
 *  Sets the view destination to apply to the geometry brush
 *
 *  View destination is the region that geometry brush is applied to.
 *
 *  \param brush The brush
 *  \param point The start point
 *  \param size The size of the destination tile
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushSetViewDestination( LtNwcPlotGeometryBrush brush, LtPoint2d point, LtVector2d size );

/**
 *  Sets the tile mode to apply to the geometry brush
 *
 *  Tile mode specify how contents of geometry brush is tiled in view destination.
 *  Valid values are None, Flip X, Flip Y, and Flip XY.
 *
 *  \param brush The brush
 *  \param tile_mode The tile mode.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushSetTileMode( LtNwcPlotGeometryBrush brush, LtNwcPlotBrushTileMode tile_mode );

/**
 *  Sets the tile offset to apply to the geometry brush
 *
 *  Subsequent rows will be offset horizontally by this amount.
 *
 *  \param brush The brush
 *  \param tile_offset The tile offset.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushSetTileOffset( LtNwcPlotGeometryBrush brush, LtFloat tile_offset );

/**
 *  Sets the geometry resource
 *
 *  \param brush The brush
 *  \param resource The handle of a defined geometry resource
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryBrushSetGeometryResource( LtNwcPlotGeometryBrush brush, LtNwcPlotResource resource );


#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotGeometryBrush API calls
 *
 * \see LiNwcPlotGeometryBrush.h
 */
class LcNwcPlotGeometryBrush : public LcNwcPlotBrush
{
public:
   LcNwcPlotGeometryBrush() : LcNwcPlotBrush(LiNwcPlotGeometryBrushCreate(), true) {}
   LcNwcPlotGeometryBrush(LtNwcPlotGeometryBrush handle) : LcNwcPlotBrush(handle) {}

   operator LtNwcPlotGeometryBrush () const
   { return static_cast<LtNwcPlotGeometryBrush>(LcNwcPlotBrush::GetHandle()); }
   LtNwcPlotGeometryBrush GetHandle() const
   { return static_cast<LtNwcPlotGeometryBrush>(LcNwcPlotBrush::GetHandle()); }

   void SetTransform( LtNwcPlotTransform transform )
   { LiNwcPlotGeometryBrushSetTransform( GetHandle(), transform ); }

   void SetOpacityFactor( LtFloat opacity_factor )
   { LiNwcPlotGeometryBrushSetOpacityFactor( GetHandle(), opacity_factor ); }

   void SetViewSource( LtPoint2d point, LtVector2d size )
   { LiNwcPlotGeometryBrushSetViewSource( GetHandle(), point, size ); }

   void SetViewDestination( LtPoint2d point, LtVector2d size )
   { LiNwcPlotGeometryBrushSetViewDestination( GetHandle(), point, size ); }

   void SetTileMode( LtNwcPlotBrushTileMode tile_mode )
   { LiNwcPlotGeometryBrushSetTileMode( GetHandle(), tile_mode ); }

   void SetTileOffset( LtFloat tile_offset )
   { LiNwcPlotGeometryBrushSetTileOffset( GetHandle(), tile_offset ); }

   void SetGeometryResource( LtNwcPlotResource resource )
   { LiNwcPlotGeometryBrushSetGeometryResource( GetHandle(), resource ); }
};

#endif /* __cplusplus */

#endif /* LINWCPLOTGEOMETRYBRUSH_HDR */
