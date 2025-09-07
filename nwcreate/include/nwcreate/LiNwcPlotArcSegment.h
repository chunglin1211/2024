/**
 * \file
 *
 * Defines a plot arc segment.
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

#ifndef LINWCPLOTARCSEGMENT_HDR
#define LINWCPLOTARCSEGMENT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a arc segment
 *
 *  \param stream The current stream for the arc segment.
 *  \return Newly created segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotArcSegment LI_NWC_API
LiNwcPlotArcSegmentCreate( LtNwcPlotGeometryStream stream );

/**
 *  Create a reference to an arc segment
 *
 *  \param segment Segment to which a reference is created
 *  \return Referenced segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotArcSegment LI_NWC_API
LiNwcPlotArcSegmentCreateRef( LtNwcPlotArcSegment segment );

/**
 *  Create a copy to a segment
 *
 *  \param segment Segment for which a copy is created
 *  \return Copied segment or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotArcSegment LI_NWC_API
LiNwcPlotArcSegmentCreateCopy( LtNwcPlotArcSegment segment );

/**
 *  Destroy an arc segment
 *
 *  \param segment Segment to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentDestroy( LtNwcPlotArcSegment segment );

/**
 *  Sets the center point of the ellipse / arc segment
 *
 *  \param segment The segment
 *  \param point The center point
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetCenterPoint( LtNwcPlotArcSegment segment, LtPoint2d point );

/**
 *  Sets the major radius of the ellipse / arc segment
 *
 *  \param segment The segment
 *  \param radius The major radius
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetMajorRadius( LtNwcPlotArcSegment segment, LtFloat radius );

/**
 *  Sets the minor radius of the ellipse / arc segment
 *
 *  \param segment The segment
 *  \param radius The minor radius
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetMinorRadius( LtNwcPlotArcSegment segment, LtFloat radius );

/**
 *  Sets the radian where the arc begins
 *
 *  \param segment The segment
 *  \param radian The beginning radian
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetStartRadian( LtNwcPlotArcSegment segment, LtFloat radian );

/**
 *  Sets the radian where the arc ends
 *
 *  \param segment The segment
 *  \param radian The ending radian
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetEndRadian( LtNwcPlotArcSegment segment, LtFloat radian );

/**
 *  Sets the sweep direction around the ellipse / arc segment from begin to end radian
 *
 *  \param segment The segment
 *  \param sweep The sweep direction
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetSweepDirection( LtNwcPlotArcSegment segment, LtNwcPlotArcSweepDirection sweep );

/**
 *  Sets the radian to rotate the ellipse / arc segment
 *
 *  \param segment The segment
 *  \param radian The ending radian
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetRotationRadian( LtNwcPlotArcSegment segment, LtFloat radian );

/**
 *  Sets whether or not the segment is visible / stroked
 *
 *  \param segment The segment
 *  \param flag The flag indicating whether the segment will be visible / stroked
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotArcSegmentSetIsStroked( LtNwcPlotArcSegment segment, bool flag );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotArcSegment API calls
 *
 * \see LiNwcPlotArcSegment.h
 */
class LcNwcPlotArcSegment
{
public:
    LcNwcPlotArcSegment( LtNwcPlotGeometryStream stream ) : m_handle( LiNwcPlotArcSegmentCreate( stream ) ) {}
    ~LcNwcPlotArcSegment( void ) { LiNwcPlotArcSegmentDestroy(m_handle); };

    LcNwcPlotArcSegment(const LcNwcPlotArcSegment &other) : m_handle(LiNwcPlotArcSegmentCreateRef(other)) {}

    LcNwcPlotArcSegment& operator = (const LcNwcPlotArcSegment &other)
    {LiNwcPlotArcSegmentDestroy(m_handle); m_handle = LiNwcPlotArcSegmentCreateRef(other); return *this;}

    LtNwcPlotArcSegment CreateCopy( LtNwcPlotArcSegment segment )
    { return LiNwcPlotArcSegmentCreateCopy( segment ); }

    operator LtNwcPlotArcSegment () const
    { return static_cast<LtNwcPlotArcSegment>(m_handle); }

    LtNwcPlotArcSegment GetHandle() const
    { return static_cast<LtNwcPlotArcSegment>(m_handle); }

    void SetCenterPoint( LtPoint2d point )
    { LiNwcPlotArcSegmentSetCenterPoint( m_handle, point ); }

    void SetMajorRadius( LtFloat radius )
    { LiNwcPlotArcSegmentSetMajorRadius( m_handle, radius ); }

    void SetMinorRadius( LtFloat radius )
    { LiNwcPlotArcSegmentSetMinorRadius( m_handle, radius ); }

    void SetStartRadian( LtFloat radian )
    { LiNwcPlotArcSegmentSetStartRadian( m_handle, radian ); }

    void SetEndRadian( LtFloat radian )
    { LiNwcPlotArcSegmentSetEndRadian( m_handle, radian ); }

    void SetSweepDirection( LtNwcPlotArcSweepDirection sweep )
    { LiNwcPlotArcSegmentSetSweepDirection( m_handle, sweep ); }

    void SetRotationRadian( LtFloat radian )
    { LiNwcPlotArcSegmentSetRotationRadian( m_handle, radian ); }

    void SetIsStroked( bool flag )
    { LiNwcPlotArcSegmentSetIsStroked( m_handle, flag ); }

    private:
        LtNwcPlotArcSegment m_handle;
};

#endif /*__cplusplus */

#endif /*LINWCPLOTARCSEGMENT_HDR*/
