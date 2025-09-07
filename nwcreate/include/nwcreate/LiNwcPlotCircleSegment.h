/**
 * \file
 *
 * Defines an plot circle.
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

#ifndef LINWCPLOTCIRCLESEGMENT_HDR
#define LINWCPLOTCIRCLESEGMENT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a circle segment
 *
 *  \param stream The current stream for the circle segment.
 *  \return Newly created segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotCircleSegment LI_NWC_API
LiNwcPlotCircleSegmentCreate( LtNwcPlotGeometryStream stream );

/**
 *  Create a reference to a circle segment
 *
 *  \param segment Segment to which a reference is created
 *  \return Referenced segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotCircleSegment LI_NWC_API
LiNwcPlotCircleSegmentCreateRef( LtNwcPlotCircleSegment segment );

/**
 *  Create a copy to a circle segment
 *
 *  \param segment Segment for which a copy is created
 *  \return Copied segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotCircleSegment LI_NWC_API
LiNwcPlotCircleSegmentCreateCopy( LtNwcPlotCircleSegment segment );

/**
 *  Destroy a circle segment
 *
 *  \param segment Segment to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCircleSegmentDestroy( LtNwcPlotCircleSegment segment );

/**
 *  Sets the center point of the circle segment
 *
 *  \param segment The segment
 *  \param point The center point
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCircleSegmentSetCenterPoint( LtNwcPlotCircleSegment segment, LtPoint2d point );

/**
 *  Sets the radius of the circle segment
 *
 *  \param segment The segment
 *  \param radius The radius
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCircleSegmentSetRadius( LtNwcPlotCircleSegment segment, LtFloat radius );

/**
 *  Sets whether or not the segment is visible / stroked
 *
 *  \param segment The segment
 *  \param flag The flag indicating whether the segment will be visible / stroked
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCircleSegmentSetIsStroked( LtNwcPlotCircleSegment segment, bool flag );

#ifdef __cplusplus
}


/**
 * C++ wrapper around LtNwcPlotCircleSegment API calls
 *
 * \see LiNwcPlotCircleSegment.h
 */
class LcNwcPlotCircleSegment
{
public:
   LcNwcPlotCircleSegment( LtNwcPlotGeometryStream stream ) : m_handle( LiNwcPlotCircleSegmentCreate( stream ) ) {}
   ~LcNwcPlotCircleSegment( void ) { LiNwcPlotCircleSegmentDestroy(m_handle); };

   LcNwcPlotCircleSegment(const LcNwcPlotCircleSegment &other) : m_handle(LiNwcPlotCircleSegmentCreateRef(other)) {}

   LcNwcPlotCircleSegment& operator = (const LcNwcPlotCircleSegment &other)
   {LiNwcPlotCircleSegmentDestroy(m_handle); m_handle = LiNwcPlotCircleSegmentCreateRef(other); return *this;}

   LtNwcPlotCircleSegment CreateCopy( LtNwcPlotCircleSegment segment )
   { return LiNwcPlotCircleSegmentCreateCopy( segment ); }

   operator LtNwcPlotCircleSegment () const
   { return static_cast<LtNwcPlotCircleSegment>(m_handle); }

   LtNwcPlotCircleSegment GetHandle() const
   { return static_cast<LtNwcPlotCircleSegment>(m_handle); }

   void SetCenterPoint( LtPoint2d point )
   { LiNwcPlotCircleSegmentSetCenterPoint( m_handle, point ); }

   void SetRadius( LtFloat radius )
   { LiNwcPlotCircleSegmentSetRadius( m_handle, radius ); }

   void SetIsStroked( bool flag )
   { LiNwcPlotCircleSegmentSetIsStroked( m_handle, flag ); }

private:
   LtNwcPlotCircleSegment m_handle;
};

#endif /*__cplusplus */

#endif /*LINWCPLOTCIRCLESEGMENT_HDR*/
