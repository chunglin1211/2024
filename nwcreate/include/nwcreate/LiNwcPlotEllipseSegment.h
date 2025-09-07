/**
 * \file
 *
 * Defines a plot elliptical segment.
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

#ifndef LINWCPLOTELLIPSESEGMENT_HDR
#define LINWCPLOTELLIPSESEGMENT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a ellipse segment
 *
 *  \param stream The current stream for the ellipse segment.
 *  \return Newly created segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotEllipseSegment LI_NWC_API
LiNwcPlotEllipseSegmentCreate( LtNwcPlotGeometryStream stream );

/**
 *  Create a reference to a ellipse segment
 *
 *  \param segment Segment to which a reference is created
 *  \return Referenced segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotEllipseSegment LI_NWC_API
LiNwcPlotEllipseSegmentCreateRef( LtNwcPlotEllipseSegment segment );

/**
 *  Create a copy to a ellipse segment
 *
 *  \param segment Segment for which a copy is created
 *  \return Copied segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotEllipseSegment LI_NWC_API
LiNwcPlotEllipseSegmentCreateCopy( LtNwcPlotEllipseSegment segment );

/**
 *  Destroy a ellipse segment
 *
 *  \param segment Segment to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEllipseSegmentDestroy( LtNwcPlotEllipseSegment segment );

/**
 *  Sets the center point of the ellipse segment
 *
 *  \param segment The segment
 *  \param point The center point
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEllipseSegmentSetCenterPoint( LtNwcPlotEllipseSegment segment, LtPoint2d point );

/**
 *  Sets the major radius of the ellipse segment
 *
 *  \param segment The segment
 *  \param radius The major radius
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEllipseSegmentSetMajorRadius( LtNwcPlotEllipseSegment segment, LtFloat radius );

/**
 *  Sets the minor radius of the ellipse segment
 *
 *  \param segment The segment
 *  \param radius The minor radius
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEllipseSegmentSetMinorRadius( LtNwcPlotEllipseSegment segment, LtFloat radius );

/**
 *  Sets the radian to rotate the ellipse segment
 *
 *  \param segment The segment
 *  \param radian The ending radian
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEllipseSegmentSetRotationRadian( LtNwcPlotEllipseSegment segment, LtFloat radian );

/**
 *  Sets whether or not the segment is visible / stroked
 *
 *  \param segment The segment
 *  \param flag The flag indicating whether the segment will be visible / stroked
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEllipseSegmentSetIsStroked( LtNwcPlotEllipseSegment segment, bool flag );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotEllipseSegment API calls
 *
 * \see LiNwcPlotEllipseSegment.h
 */
class LcNwcPlotEllipseSegment
{
public:
   LcNwcPlotEllipseSegment( LtNwcPlotGeometryStream stream ) : m_handle( LiNwcPlotEllipseSegmentCreate( stream ) ) {}
   ~LcNwcPlotEllipseSegment( void ) { LiNwcPlotEllipseSegmentDestroy(m_handle); }

   LcNwcPlotEllipseSegment(const LcNwcPlotEllipseSegment &other) : m_handle(LiNwcPlotEllipseSegmentCreateRef(other)) {}

   LcNwcPlotEllipseSegment& operator = (const LcNwcPlotEllipseSegment &other)
   {LiNwcPlotEllipseSegmentDestroy(m_handle); m_handle = LiNwcPlotEllipseSegmentCreateRef(other); return *this;}

   LtNwcPlotEllipseSegment CreateCopy( LcNwcPlotEllipseSegment segment )
   { return LiNwcPlotEllipseSegmentCreateCopy( segment ); }

   operator LtNwcPlotEllipseSegment () const
   { return static_cast<LtNwcPlotEllipseSegment>(m_handle); }

   LtNwcPlotEllipseSegment GetHandle() const
   { return static_cast<LtNwcPlotEllipseSegment>(m_handle); }

   void SetCenterPoint( LtPoint2d point )
   { LiNwcPlotEllipseSegmentSetCenterPoint( m_handle, point ); }

   void SetMajorRadius( LtFloat radius )
   { LiNwcPlotEllipseSegmentSetMajorRadius( m_handle, radius ); }

   void SetMinorRadius( LtFloat radius )
   { LiNwcPlotEllipseSegmentSetMinorRadius( m_handle, radius ); }

   void SetRotationRadian( LtFloat radian )
   { LiNwcPlotEllipseSegmentSetRotationRadian( m_handle, radian ); }

   void SetIsStroked( bool flag )
   { LiNwcPlotEllipseSegmentSetIsStroked( m_handle, flag ); }

private:
   LtNwcPlotEllipseSegment m_handle;
};

#endif /*__cplusplus */

#endif /*LINWCPLOTELLIPSESEGMENT_HDR*/
