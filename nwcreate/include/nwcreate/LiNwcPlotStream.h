/**
 * \file
 *
 * A protocol for defining 2D plot geometry data.
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

#ifndef LINWCPLOTSTREAM_HDR
#define LINWCPLOTSTREAM_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Start defining a 2D stream.
 *  \param stream Stream being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamBegin( LtNwcPlotStream stream );

/**
 *  End current definition, started by LiNwcPlotStreamBegin.
 *  \param stream Stream being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamEnd( LtNwcPlotStream stream );

/**
 *  OBSOLETE: Does nothing
 *  If geometry coordinates are further than this distance from the origin
 *  will recenter geometry about the origin and store with an offset to
 *  actual location. This improves precision of data.
 *  Default: 0 (no threshold)
 *  \param stream Stream of geometry being defined
 *  \param dist Distance from origin threshold for recentering geometry
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamRecenterThreshold( LtNwcPlotStream stream, LtFloat dist );

/**
 *  Opens input to a stream to define path geometry
 *
 *  Usage: client code defines a path style, begins a path, begins a path stream
 *         begins a figure (in the stream), adds geometry (in the stream), ends
 *         the figure, perhaps defines another figure, closes the path stream,
 *         and ends the path
 *
 *  \return Newly opened path geometry stream or NULL on error
 *
 *  \param stream Stream handle of parent plot stream
 *  \param style Style containing path stream options
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotGeometryStream LI_NWC_API
LiNwcPlotStreamPathStreamOpen( LtNwcPlotStream stream, LtNwcPlotPathStreamStyle style );

/**
 *  Closes input to a path geometry stream
 *
 *  \param stream Stream handle of parent plot stream
 *  \param geometry_stream Stream handle of path geometry stream to close
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamPathStreamClose( LtNwcPlotStream stream, LtNwcPlotGeometryStream geometry_stream );

/**
 *  Begins a viewport input to a stream.
 *
 *  \param stream Stream handle
 *  \param style Viewport style definition handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamViewportBegin( LtNwcPlotStream stream, LtNwcPlotViewportStyle style );

/**
 *  Ends a viewport input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamViewportEnd( LtNwcPlotStream stream );

/**
 *  Begins a canvas input to a stream.
 *
 *  \param stream Stream handle
 *  \param style Canvas style definition handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamCanvasBegin( LtNwcPlotStream stream, LtNwcPlotCanvasStyle style );

/**
 *  Ends a canvas input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamCanvasEnd( LtNwcPlotStream stream );

/**
 *  Begins a path geometry input to a stream (contains one or more path figures)
 *
 *  Only one path geometry is allowed in a Path or Clip element
 *
 * \param stream Stream handle
 * \param style style for path
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamPathBegin( LtNwcPlotStream stream, LtNwcPlotPathStyle style );

/**
 *  Ends a path geometry input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamPathEnd( LtNwcPlotStream stream );

/**
 *  Begins text input to a stream.
 *
 *  \param stream Stream handle
 *  \param font_style The font style for the text
 *  \param style The text style
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamTextBegin( LtNwcPlotStream stream, LtNwcPlotFontStyle font_style, LtNwcPlotTextStyle style );

/**
 *  Ends text input to a stream.
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamTextEnd( LtNwcPlotStream stream );

/**
 *  Adds text to a geometry stream.
 *
 *  \param stream Stream handle
 *  \param text Text to add
 *  \param point Insertion point for text, defined as the baseline for the text line
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamText( LtNwcPlotStream stream, LtWideString text, LtPoint2d point );

/**
 *  Adds text to a geometry stream, with the given bounds.  When used, the
 *  TextEmHeight, HorizontalAlignment, VerticalAlignment and CharacterSpacing
 *  attributes are ignored.
 *  Received bounds should have four points to specify the current bounds, which
 *  don't have to be a rectangle. And, the bounds should have the following format:
 *  first point is bottom-left, second point is bottom-right, third point is top-right,
 *  and the fourth point is top-left.
 *  The position of the text should be the bottom-left point of the bounds.
 *
 *  \param stream Stream handle
 *  \param text Text to add
 *  \param bounds The bounds of the text.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamBoundedText( LtNwcPlotStream stream, LtWideString text, LtNwcPlotBounds2d bounds );

/**
 *  Adds a snap point text to a geometry stream.
 *
 *  \param stream Stream handle
 *  \param point The snap point
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStreamSnapPoint( LtNwcPlotStream stream, LtPoint2d point );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotStream API calls
 *
 * \see LiNwcPlotStream.h
 */
class LcNwcPlotStream
{
public:
    LcNwcPlotStream( LtNwcPlotStream handle )
      : m_handle(handle)
    {}

    operator LtNwcPlotStream () const
    { return static_cast<LtNwcPlotStream>(m_handle); }

    LtNwcPlotStream GetHandle() const
    { return static_cast<LtNwcPlotStream>(m_handle); }

    void Begin( void )
    { LiNwcPlotStreamBegin( m_handle ); }

    void End( void )
    { LiNwcPlotStreamEnd( m_handle ); }

    void RecenterThreshold( LtFloat dist )
    { LiNwcPlotStreamRecenterThreshold( m_handle, dist ); }

    LtNwcPlotGeometryStream PathStreamOpen( LtNwcPlotPathStreamStyle style )
    { return LiNwcPlotStreamPathStreamOpen( m_handle, style ); }

    void PathStreamClose( LtNwcPlotGeometryStream stream )
    { LiNwcPlotStreamPathStreamClose( m_handle, stream ); }

    void ViewportBegin( LtNwcPlotViewportStyle style )
    { LiNwcPlotStreamViewportBegin( m_handle, style ); }

    void ViewportEnd( void )
    { LiNwcPlotStreamViewportEnd( m_handle ); }

    void CanvasBegin( LtNwcPlotCanvasStyle style )
    { LiNwcPlotStreamCanvasBegin( m_handle, style ); }

    void CanvasEnd( void )
    { LiNwcPlotStreamCanvasEnd( m_handle ); }

    void PathBegin( LtNwcPlotPathStyle style )
    { LiNwcPlotStreamPathBegin( m_handle, style ); }

    void PathEnd( void )
    { LiNwcPlotStreamPathEnd( m_handle ); }

    void TextBegin( LtNwcPlotFontStyle font_style, LtNwcPlotTextStyle style )
    { LiNwcPlotStreamTextBegin( m_handle, font_style, style ); }

    void TextEnd( void )
    { LiNwcPlotStreamTextEnd( m_handle ); }

    void Text( LtWideString text, LtPoint2d point )
    { LiNwcPlotStreamText( m_handle, text, point ); }

    void BoundedText( LtWideString text, LtNwcPlotBounds2d bounds )
    { LiNwcPlotStreamBoundedText( m_handle, text, bounds ); }

    void SnapPoint( LtPoint2d point )
    { LiNwcPlotStreamSnapPoint( m_handle, point ); }

private:
   LtNwcPlotStream m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTSTREAM_HDR */
