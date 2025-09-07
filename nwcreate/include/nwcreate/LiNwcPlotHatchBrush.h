/**
 * \file
 *
 * Defines a hatch brush for filling a closed Path or coloring
 * a Stroke.  This brush is a collection of parrallel line sets.
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

#ifndef LINWCPLOTHATCHBRUSH_HDR
#define LINWCPLOTHATCHBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotBrush.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a hatch brush
 *
 *  \return Newly created brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotHatchBrush LI_NWC_API
LiNwcPlotHatchBrushCreate( void );

/**
 *  Create a reference to a hatch brush
 *
 *  \param brush Brush to which a reference is created
 *  \return Referenced brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotHatchBrush LI_NWC_API
LiNwcPlotHatchBrushCreateRef( LtNwcPlotHatchBrush brush );

/**
 *  Destroy a hatch brush
 *
 *  \param brush Brush to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotHatchBrushDestroy( LtNwcPlotHatchBrush brush );

/**
 *  Sets the height of the pattern cell
 *
 *  \param brush The hatch brush
 *  \param val the value to set
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotHatchBrushSetHeight( LtNwcPlotHatchBrush brush, LtFloat val );

/**
 *  Sets the width of the pattern cell
 *
 *  \param brush The hatch brush
 *  \param val the value to set
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotHatchBrushSetWidth( LtNwcPlotHatchBrush brush, LtFloat val );

/**
 *  Begin a hatch pattern definition for the brush (defined one at a time, the brush may contain many definitions)
 *
 * \param brush The hatch brush
 * \param pt origin point
 * \param angle hatching angle
 * \param spacing hatching spacing
 * \param skew skew angle
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotHatchBrushPatternBegin( LtNwcPlotHatchBrush brush, LtPoint2d pt, LtFloat angle, LtFloat spacing, LtFloat skew );

/**
 *  Defines a dash / gap pair for the hatch pattern
 *
 *  \param brush The hatch brush
 *  \param dash_length The length of the dash
 *  \param gap_length The length of the gap
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotHatchBrushPatternGapPair( LtNwcPlotHatchBrush brush, LtFloat dash_length, LtFloat gap_length );

/**
 *  End a hatch pattern definition for the brush
 *
 *  \param brush The hatch brush
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotHatchBrushPatternEnd( LtNwcPlotHatchBrush brush );

#ifdef __cplusplus
}


/**
 * C++ wrapper around LtNwcPlotHatchBrush API calls
 *
 * \see LiNwcPlotHatchBrush.h
 */
class LcNwcPlotHatchBrush : public LcNwcPlotBrush
{
public:
   LcNwcPlotHatchBrush() : LcNwcPlotBrush(LiNwcPlotHatchBrushCreate(), true) {}
   LcNwcPlotHatchBrush(LtNwcPlotHatchBrush handle) : LcNwcPlotBrush(handle) {}

   operator LtNwcPlotHatchBrush () const
   { return static_cast<LtNwcPlotHatchBrush>(LcNwcPlotBrush::GetHandle()); }
   LtNwcPlotHatchBrush GetHandle() const
   { return static_cast<LtNwcPlotHatchBrush>(LcNwcPlotBrush::GetHandle()); }

   void SetHeight( LtFloat val )
   { LiNwcPlotHatchBrushSetHeight( GetHandle(), val ); }

   void SetWidth( LtFloat val )
   { LiNwcPlotHatchBrushSetWidth( GetHandle(), val ); }

   void PatternBegin( LtPoint2d pt, LtFloat angle, LtFloat spacing, LtFloat skew )
   { LiNwcPlotHatchBrushPatternBegin( GetHandle(), pt, angle, spacing, skew ); }

   void PatternGapPair( LtFloat dash_length, LtFloat gap_length )
   { LiNwcPlotHatchBrushPatternGapPair( GetHandle(), dash_length, gap_length ); }

   void PatternEnd( void )
   { LiNwcPlotHatchBrushPatternEnd( GetHandle() ); }
};

#endif /* __cplusplus */

#endif /* LINWCPLOTHATCHBRUSH_HDR */
