/**
 * \file
 *
 * Defines a Stroke - the stylization of the line type, dash type, caps,
 * colors, etc. that are drawn on top of Path geometry.
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

#ifndef LINWCPLOTSTROKE_HDR
#define LINWCPLOTSTROKE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a stroke
 *
 *  \return Newly created stroke or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotStroke LI_NWC_API
LiNwcPlotStrokeCreate( void );

/**
 *  Create a reference to a stroke
 *
 *  \param stroke Stroke to which a reference is created
 *  \return Referenced stroke or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotStroke LI_NWC_API
LiNwcPlotStrokeCreateRef( LtNwcPlotStroke stroke );

/**
 *  Create a copy to a stroke
 *
 *  \param stroke Stroke for which a copy is created
 *  \return Copied stroke or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotStroke LI_NWC_API
LiNwcPlotStrokeCreateCopy( LtNwcPlotStroke stroke );

/**
 *  Destroy a text stroke
 *
 *  \param stroke Stroke to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeDestroy( LtNwcPlotStroke stroke );

/**
 *  Sets a brush as the brush for the stroke
 *
 *  \param stroke The stroke
 *  \param brush The brush for the stroke
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetBrush( LtNwcPlotStroke stroke, LtNwcPlotBrush brush );

/**
 *  Sets the dash offset for the stroke
 *
 *  Define the offset from the origin of the stroke, if no offset is set, the dash pattern
 *  will align at very beginning of the stroke.
 *
 *  \param stroke The stroke
 *  \param offset The dash pattern offset
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetDashOffset( LtNwcPlotStroke stroke, LtFloat offset );

/**
 *  Begin the dash pattern definition for the stroke (mutually exclusive with line pattern)
 *
 *  \param stroke The stroke
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeDashPatternBegin( LtNwcPlotStroke stroke );

/**
 *  Defines a dash / gap pair for the dash pattern
 *
 *  Describe the lengths and the gaps of the dashes, they should be set as a pair.
 *  When a stroke is drawn, the dashes and gaps specified by these values will be
 *  repeated to cover the length of the stroke.
 *
 *  \param stroke The stroke
 *  \param dash_length The length of the dash
 *  \param gap_length The length of the gap
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeDashPatternGapPair( LtNwcPlotStroke stroke, LtFloat dash_length, LtFloat gap_length );

/**
 *  End the dash pattern definition for the stroke
 *
 *  \param stroke The stroke
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeDashPatternEnd( LtNwcPlotStroke stroke );

/**
 *  Defines the cap to use for the start of each dash in the stroke (excluding the beginning of the stroke)
 *
 *  \param stroke The stroke
 *  \param cap The cap to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetDashStartCap( LtNwcPlotStroke stroke, LtNwcPlotStrokeCap cap );

/**
 *  Defines the cap to use for the end of each dash in the stroke (excluding the end of the stroke)
 *
 *  \param stroke The stroke
 *  \param cap The cap to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetDashEndCap( LtNwcPlotStroke stroke, LtNwcPlotStrokeCap cap );

/**
 *  Sets the line pattern for the stroke (mutually exclusive with dash pattern)
 *
 *  \param stroke The stroke
 *  \param pattern The line pattern (see LtNwcPlotLinePattern)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetLinePattern( LtNwcPlotStroke stroke, LtNwcPlotLinePattern pattern );

/**
 *  Sets the line pattern scale for the stroke (alternatively, applies to dash pattern if one is defined)
 *
 *  \param stroke The stroke
 *  \param scale The line pattern scale
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetLinePatternScale( LtNwcPlotStroke stroke, LtFloat scale );

/**
 *  Defines the cap to use for the start of the stroke
 *
 *  \param stroke The stroke
 *  \param cap The cap to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetStartCap( LtNwcPlotStroke stroke, LtNwcPlotStrokeCap cap );

/**
 *  Defines the cap to use for the end of the stroke
 *
 *  \param stroke The stroke
 *  \param cap The cap to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetEndCap( LtNwcPlotStroke stroke, LtNwcPlotStrokeCap cap );

/**
 *  Defines whether a whole line patterns must always be fit into the segment.
 *
 *  If adaptive patterns is set to 'true', the renderer is instructed to stretch
 *  (or shrink) the set of pattern elements so that the final pattern element of
 *  the stroked figure is not truncated.
 *
 *  \param stroke The stroke
 *  \param adapt_patterns The flag
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetAdaptivePatterns( LtNwcPlotStroke stroke, bool adapt_patterns );

/**
 *  Defines the join type to use between each segment in the path
 *
 *  \param stroke The stroke
 *  \param join_type The join to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetJoinStyle( LtNwcPlotStroke stroke, LtNwcPlotStrokeJoin join_type );

/**
 *  Defines the join miter limit type to use between each segment in the path
 *
 *  This value is only used when join style is set to Miter, then define the ratio between
 *  the maximum miter length and half of the stroke thickness.
 *
 *  \param stroke The stroke
 *  \param miter_limit The miter limit to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetJoinMiterLimit( LtNwcPlotStroke stroke, LtFloat miter_limit );

/**
 *  Defines the joint miter angle to use between each segment in the path
 *
 *   \param stroke The stroke
 *   \param miter_angle The miter angle to use
 *   \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetJoinMiterAngle( LtNwcPlotStroke stroke, LtFloat miter_angle);

/**
 *  Defines the stroke thickness
 *
 *  \param stroke The stroke
 *  \param thickness The stroke thickness to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeSetThickness( LtNwcPlotStroke stroke, LtFloat thickness );

/**
 *  Begins defining a variable stroke thickness, if the stroke thickness type is variable
 *
 *  \param stroke The stroke
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeOffsetThicknessBegin( LtNwcPlotStroke stroke );

/**
 *  Defines an offset and thickness factor for a variable stroke thickness
 *
 *  Specifies the offset factor and the thickness factor is to be applied when rendering the
 *  stroke.  The thicknessfactor at each offset is appllied to the defined stroke thickness.
 *  For example, if the stroke thickness is defined as 10, and offset/thickness factors are
 *  (0,.5) (.5,1) (1,2), the beginning stroke width of the path will be .5, ramping to a
 *  thickness of 10 at the midpoint of the path, then to a final thickness of 20.  If the
 *  beginning (offset 0) and end (offset 1) are not specified, they will default to the
 *  defined stroke thickness.
 *
 *  \param stroke The stroke
 *  \param offset The offset factor into the stroke
 *  \param thickness The thicknesss factor to apply
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeOffsetThicknessFactor( LtNwcPlotStroke stroke, LtFloat offset, LtFloat thickness );

/**
 *  Ends defining a variable stroke thickness, if the stroke thickness type is variable
 *
 *  \param stroke The stroke
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotStrokeOffsetThicknessEnd( LtNwcPlotStroke stroke );


#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotStroke API calls
 *
 * \see LiNwcPlotStroke.h
 */
class LcNwcPlotStroke
{
public:
    LcNwcPlotStroke( void ) : m_handle( LiNwcPlotStrokeCreate() ) {}
    ~LcNwcPlotStroke( void ) { LiNwcPlotStrokeDestroy( m_handle ); }

    LcNwcPlotStroke(const LcNwcPlotStroke &other) : m_handle(LiNwcPlotStrokeCreateRef(other)) {}

    LcNwcPlotStroke& operator = (const LcNwcPlotStroke &other)
    {LiNwcPlotStrokeDestroy(m_handle); m_handle = LiNwcPlotStrokeCreateRef(other); return *this;}

    LtNwcPlotStroke CreateCopy( LtNwcPlotStroke stroke )
    { return LiNwcPlotStrokeCreateCopy( stroke ); }

    operator LtNwcPlotStroke () const
    { return static_cast<LtNwcPlotStroke>( m_handle ); }

    LtNwcPlotStroke GetHandle() const
    { return static_cast<LtNwcPlotStroke>( m_handle ); }

    void SetBrush( LtNwcPlotBrush brush )
    { LiNwcPlotStrokeSetBrush( m_handle, brush ); }

    void SetDashOffset( LtFloat offset )
    { LiNwcPlotStrokeSetDashOffset( m_handle, offset ); }

    void DashPatternBegin( void )
    { LiNwcPlotStrokeDashPatternBegin( m_handle ); }

    void DashPatternGapPair( LtFloat dash_length, LtFloat gap_length )
    { LiNwcPlotStrokeDashPatternGapPair( m_handle, dash_length, gap_length ); }

    void DashPatternEnd( void )
    { LiNwcPlotStrokeDashPatternEnd( m_handle); }

    void SetDashStartCap( LtNwcPlotStrokeCap cap )
    { LiNwcPlotStrokeSetDashStartCap( m_handle, cap ); }

    void SetDashEndCap( LtNwcPlotStrokeCap cap )
    { LiNwcPlotStrokeSetDashEndCap( m_handle, cap ); }

    void SetLinePattern( LtNwcPlotLinePattern pattern )
    { LiNwcPlotStrokeSetLinePattern( m_handle, pattern ); }

    void SetLinePatternScale( LtFloat scale )
    { LiNwcPlotStrokeSetLinePatternScale( m_handle, scale ); }

    void SetStartCap( LtNwcPlotStrokeCap cap )
    { LiNwcPlotStrokeSetStartCap( m_handle, cap ); }

    void SetEndCap( LtNwcPlotStrokeCap cap )
    { LiNwcPlotStrokeSetEndCap( m_handle, cap ); }

    void SetAdaptivePatterns( bool adapt_patterns )
    { LiNwcPlotStrokeSetAdaptivePatterns( m_handle, adapt_patterns ); }

    void SetJoinStyle( LtNwcPlotStrokeJoin join_type )
    { LiNwcPlotStrokeSetJoinStyle( m_handle, join_type ); }

    void SetJoinMiterLimit( LtFloat miter_limit )
    { LiNwcPlotStrokeSetJoinMiterLimit( m_handle, miter_limit ); }

    void SetJoinMiterAngle( LtFloat miter_angle )
    { LiNwcPlotStrokeSetJoinMiterAngle( m_handle, miter_angle); }

    void SetThickness( LtFloat thickness )
    { LiNwcPlotStrokeSetThickness( m_handle, thickness ); }

    void OffsetThicknessBegin( void )
    { LiNwcPlotStrokeOffsetThicknessBegin( m_handle ); }

    void OffsetThicknessFactor( LtFloat offset, LtFloat thickness )
    { LiNwcPlotStrokeOffsetThicknessFactor( m_handle, offset, thickness ); }

    void OffsetThicknessEnd( void )
    { LiNwcPlotStrokeOffsetThicknessEnd( m_handle ); }

private:
    LtNwcPlotStroke m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTSTROKE_HDR */
