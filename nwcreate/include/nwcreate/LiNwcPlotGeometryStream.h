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

#ifndef LINWCPLOTGEOMETRYSTREAM_HDR
#define LINWCPLOTGEOMETRYSTREAM_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Start defining a piece of geometry.
 *  \param stream Stream of geometry being defined
 *  \param style Path stream style for all segments in the stream
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamBegin( LtNwcPlotGeometryStream stream, LtNwcPlotPathStreamStyle style );

/**
 *  Send within Begin/End Segment BEFORE corresponding vertex is sent.
 *
 *  \param stream Stream of geometry being defined
 *  \param r Red component of color
 *  \param g Green component of color
 *  \param b Blue component of color
 *  \param a Alpha component of color.  (Range 0 to 1, 0 is transparent, 1 is opaque)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamColor(LtNwcPlotGeometryStream stream, LtFloat r, LtFloat g, LtFloat b, LtFloat a);

/**
 *  End current definition, started by LiNwcPlotGeometryStreamBegin.
 *  \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamEnd( LtNwcPlotGeometryStream stream );

/**
 *  Begins a path figure input to a stream
 *
 *  Part of a path geometry
 *
 *  A path figure can be defined contianing various segment types (line, bezier, arc, etc.)
 *
 *  \param stream Stream handle
 *  \param style Path figure style definition handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPathFigureBegin( LtNwcPlotGeometryStream stream, LtNwcPlotPathFigureStyle style );

/**
 *  Ends a path figure input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPathFigureEnd( LtNwcPlotGeometryStream stream );

/**
 *  Begins a point list segment input to a stream (contains one or more points)
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \param isStroked Indicates whether the segment will be visible or not (i.e. may be invisible if defining a filled region without a border)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPointListSegmentBegin( LtNwcPlotGeometryStream stream, bool isStroked);

/**
 *  Inserts a point
 *
 *  \param stream Stream handle
 *  \param point a point
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPointListSegmentPoint( LtNwcPlotGeometryStream stream, LtPoint2d point );

/**
 *  Ends a point list segment input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPointListSegmentEnd( LtNwcPlotGeometryStream stream );

/**
 *  Begins a poly line segment input to a stream (contains one or more verticies)
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \param isStroked Indicates whether the segment will be visible or not (i.e. may be invisible if defining a filled region without a border)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyLineSegmentBegin( LtNwcPlotGeometryStream stream, bool isStroked );

/**
 *  Inserts a poly line segment vertex
 *
 *  \param stream Stream handle
 *  \param point Poly line vertex
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyLineSegmentPoint( LtNwcPlotGeometryStream stream, LtPoint2d point );

/**
 *  Ends a poly line segment input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyLineSegmentEnd( LtNwcPlotGeometryStream stream );

/**
 *  Begins a poly bezier segment input to a stream (contains one or more control points )
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \param isStroked Indicates whether the segment will be visible or not (i.e. may be invisible if defining a filled region without a border)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyBezierSegmentBegin( LtNwcPlotGeometryStream stream, bool isStroked );

/**
 *  Inserts a poly bezier segment control point
 *
 *  \param stream Stream handle
 *  \param point Poly bezier control point
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyBezierSegmentPoint( LtNwcPlotGeometryStream stream, LtPoint2d point );

/**
 *  Ends a poly bezier segment input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyBezierSegmentEnd( LtNwcPlotGeometryStream stream );

/**
 *  Begins a poly quadratic bezier segment input to a stream (contains one or more control points )
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \param isStroked Indicates whether the segment will be visible or not (i.e. may be invisible if defining a filled region without a border)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyQuadraticBezierSegmentBegin( LtNwcPlotGeometryStream stream, bool isStroked );

/**
 *  Inserts a poly quadratic bezier segment control point
 *
 *  \param stream Stream handle
 *  \param point Poly quadratic bezier control point
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyQuadraticBezierSegmentPoint( LtNwcPlotGeometryStream stream, LtPoint2d point );

/**
 *  Ends a poly quadratic bezier segment input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyQuadraticBezierSegmentEnd( LtNwcPlotGeometryStream stream );

/**
 *  Inserts a poly triangle segment to a stream
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyTriangleSegmentBegin( LtNwcPlotGeometryStream stream );

/**
 *  Inserts a poly triangle segment vertex
 *
 *  \param stream Stream handle
 *  \param point Poly triangle vertex
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyTriangleSegmentPoint( LtNwcPlotGeometryStream stream, LtPoint2d point );

/**
 *  Ends a poly triangle segment input to a stream
 *
 *  \param stream Stream handle
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamPolyTriangleSegmentEnd( LtNwcPlotGeometryStream stream );

/**
 *  Inserts an circle segment to a stream
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \param segment The segment definition
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamCircleSegment( LtNwcPlotGeometryStream stream, LtNwcPlotCircleSegment segment );

/**
 *  Inserts an ellipse segment to a stream
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \param segment The segment definition
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamEllipseSegment( LtNwcPlotGeometryStream stream, LtNwcPlotEllipseSegment segment );

/**
 *  Inserts an arc segment to a stream
 *
 *  Part of a path figure
 *
 *  \param stream Stream handle
 *  \param segment The segment definition
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotGeometryStreamArcSegment( LtNwcPlotGeometryStream stream, LtNwcPlotArcSegment segment );


#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotGeometryStream API calls
 *
 * \see LiNwcPlotGeometryStream.h
 */
class LcNwcPlotGeometryStream
{
public:
    LcNwcPlotGeometryStream( LtNwcPlotGeometryStream handle )
      : m_handle(handle)
    {}

    operator LtNwcPlotGeometryStream () const
    { return static_cast<LtNwcPlotGeometryStream>(m_handle); }

    LtNwcPlotGeometryStream GetHandle() const
    { return static_cast<LtNwcPlotGeometryStream>(m_handle); }

    void Begin( LtNwcPlotPathStreamStyle style )
    { LiNwcPlotGeometryStreamBegin( m_handle, style ); }

    void Color( LtFloat r, LtFloat g, LtFloat b, LtFloat a )
    { LiNwcPlotGeometryStreamColor( m_handle, r, g, b, a ); }

    void End( void )
    { LiNwcPlotGeometryStreamEnd( m_handle ); }

    void PathFigureBegin( LtNwcPlotPathFigureStyle style )
    { LiNwcPlotGeometryStreamPathFigureBegin( m_handle, style );  }

    void PathFigureEnd( void )
    { LiNwcPlotGeometryStreamPathFigureEnd( m_handle ); }

    void PolyLineSegmentBegin( bool isStroked )
    { LiNwcPlotGeometryStreamPolyLineSegmentBegin( m_handle, isStroked ); }

    void PolyLineSegmentPoint( LtPoint2d point )
    { LiNwcPlotGeometryStreamPolyLineSegmentPoint( m_handle, point ); }

    void PolyLineSegmentEnd( void )
    { LiNwcPlotGeometryStreamPolyLineSegmentEnd( m_handle ); }

    void PolyBezierSegmentBegin( bool isStroked )
    { LiNwcPlotGeometryStreamPolyBezierSegmentBegin( m_handle, isStroked ); }

    void PolyBezierSegmentPoint( LtPoint2d point )
    { LiNwcPlotGeometryStreamPolyBezierSegmentPoint( m_handle, point ); }

    void PolyBezierSegmentEnd( void )
    { LiNwcPlotGeometryStreamPolyBezierSegmentEnd( m_handle ); }

    void PolyQuadraticBezierSegmentBegin( bool isStroked )
    { LiNwcPlotGeometryStreamPolyQuadraticBezierSegmentBegin( m_handle, isStroked ); }

    void PolyQuadraticBezierSegmentPoint( LtPoint2d point )
    { LiNwcPlotGeometryStreamPolyQuadraticBezierSegmentPoint( m_handle, point ); }

    void PolyQuadraticBezierSegmentEnd( void )
    { LiNwcPlotGeometryStreamPolyQuadraticBezierSegmentEnd( m_handle ); }

    void PolyTriangleSegmentBegin( void )
    { LiNwcPlotGeometryStreamPolyTriangleSegmentBegin( m_handle ); }

    void PolyTriangleSegmentPoint( LtPoint2d point )
    { LiNwcPlotGeometryStreamPolyTriangleSegmentPoint( m_handle, point ); }

    void PolyTriangleSegmentEnd( void )
    { LiNwcPlotGeometryStreamPolyTriangleSegmentEnd( m_handle ); }

    void PointListSegmentBegin( bool isStroked )
    { LiNwcPlotGeometryStreamPointListSegmentBegin( m_handle, isStroked ); }

    void PointListSegmentPoint( LtPoint2d point )
    { LiNwcPlotGeometryStreamPointListSegmentPoint( m_handle, point ); }

    void PointListSegmentEnd( void )
    { LiNwcPlotGeometryStreamPointListSegmentEnd( m_handle ); }

    void CircleSegment( LtNwcPlotCircleSegment segment )
    { LiNwcPlotGeometryStreamCircleSegment( m_handle, segment ); }

    void EllipseSegment( LtNwcPlotEllipseSegment segment )
    { LiNwcPlotGeometryStreamEllipseSegment( m_handle, segment ); }

    void ArcSegment( LtNwcPlotArcSegment segment )
    { LiNwcPlotGeometryStreamArcSegment( m_handle, segment ); }

private:
   LtNwcPlotGeometryStream m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTGEOMETRYSTREAM_HDR */
