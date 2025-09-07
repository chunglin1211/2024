/**
 * \file
 *
 * Defines an image brush for filling a closed Path or rendering a Stroke.
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

#ifndef LINWCPLOTIMAGEBRUSH_HDR
#define LINWCPLOTIMAGEBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotBrush.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create an image brush
 *
 *  \return Newly created brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotImageBrush LI_NWC_API
LiNwcPlotImageBrushCreate( void );

/**
 *  Create a reference to an image brush
 *
 *  \param brush Brush to which a reference is created
 *  \return Referenced brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotImageBrush LI_NWC_API
LiNwcPlotImageBrushCreateRef( LtNwcPlotImageBrush brush );

/**
 *  Destroy an image brush
 *
 *  \param brush Brush to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushDestroy( LtNwcPlotImageBrush brush );

/**
 *  Sets the transform to apply to the image brush
 *
 *  \param brush The brush
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetTransform( LtNwcPlotImageBrush brush, LtNwcPlotTransform transform );

/**
 *  Sets the opacity factor to apply to the image brush
 *
 *  \param brush The brush
 *  \param opacity_factor The factor to use (0 = transparent, 1 = opaque)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetOpacityFactor( LtNwcPlotImageBrush brush, LtFloat opacity_factor );

/**
 *  Sets the view source to apply to the image brush
 *
 *  View source specifies the position and size of the image brush's source content.
 *
 *  \param brush The brush
 *  \param point The start point in pixels
 *  \param size The size of the source portion of the image in pixels
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetViewSource( LtNwcPlotImageBrush brush, LtPlotInt32Point point, LtPlotInt32Size size );

/**
 *  Sets the view destination to apply to the image brush
 *
 *  View destination is the region that image brush is applied to.
 *
 *  \param brush The brush
 *  \param point The start point
 *  \param size The size of the destination tile
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetViewDestination( LtNwcPlotImageBrush brush, LtPoint2d point, LtVector2d size );

/**
 *  Sets the tile mode to apply to the image brush
 *
 *  Tile mode specify how contents of the brush will be tiled in view destination.
 *  Valid values are None, Flip X, Flip Y, and Flip XY.
 *
 *  \param brush The brush
 *  \param tile_mode The tile mode.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetTileMode( LtNwcPlotImageBrush brush, LtNwcPlotBrushTileMode tile_mode );

/**
 *  Sets the tile offset to apply to the image brush
 *
 *  Subsequent rows will be offset horizontally by this amount.
 *
 *  \param brush The brush
 *  \param tile_offset The tile offset.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetTileOffset( LtNwcPlotImageBrush brush, LtFloat tile_offset );

/**
 *  Sets the image from a file
 *
 *  \param brush The brush
 *  \param image_file The local filename containing the image (a known supported format)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetImageFromFile( LtNwcPlotImageBrush brush, LtWideString image_file );

/**
 *  Sets the image from an image header object
 *
 *  \param brush The brush
 *  \param image The image header defining the image
 *  \param pixels The image buffer
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotImageBrushSetImageFromMemory( LtNwcPlotImageBrush brush, LtNwcImageHeader image, const LtNat8* pixels );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotImageBrush API calls
 *
 * \see LiNwcPlotImageBrush.h
 */
class LcNwcPlotImageBrush : public LcNwcPlotBrush
{
public:
   LcNwcPlotImageBrush() : LcNwcPlotBrush(LiNwcPlotImageBrushCreate(), true) {}
   LcNwcPlotImageBrush(LtNwcPlotImageBrush handle) : LcNwcPlotBrush(handle) {}

   operator LtNwcPlotImageBrush () const
   { return static_cast<LtNwcPlotImageBrush>(LcNwcPlotBrush::GetHandle()); }
   LtNwcPlotImageBrush GetHandle() const
   { return static_cast<LtNwcPlotImageBrush>(LcNwcPlotBrush::GetHandle()); }

   void SetTransform( LtNwcPlotTransform transform )
   { LiNwcPlotImageBrushSetTransform( GetHandle(), transform ); }

   void SetOpacityFactor( LtFloat opacity_factor )
   { LiNwcPlotImageBrushSetOpacityFactor( GetHandle(), opacity_factor ); }

   void SetViewSource( LtPlotInt32Point point, LtPlotInt32Size size )
   { LiNwcPlotImageBrushSetViewSource( GetHandle(), point, size ); }

   void SetViewDestination( LtPoint2d point, LtVector2d size )
   { LiNwcPlotImageBrushSetViewDestination( GetHandle(), point, size ); }

   void SetTileMode( LtNwcPlotBrushTileMode tile_mode )
   { LiNwcPlotImageBrushSetTileMode( GetHandle(), tile_mode ); }

   void SetTileOffset( LtFloat tile_offset )
   { LiNwcPlotImageBrushSetTileOffset( GetHandle(), tile_offset ); }

   void SetImageFromFile( LtWideString image_file )
   { LiNwcPlotImageBrushSetImageFromFile( GetHandle(), image_file ); }

   void SetImageFromMemory( LtNwcImageHeader image, const LtNat8* pixels )
   { LiNwcPlotImageBrushSetImageFromMemory( GetHandle(), image, pixels ); }
};

#endif /* __cplusplus */

#endif /* LINWCPLOTIMAGEBRUSH_HDR */
