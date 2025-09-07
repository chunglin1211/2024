/**
 * \file
 *
 * Component for defining grid lines. A grid line is defined as a
 * collection of 2D curve segments that sit on the levels in a
 * system. A grid line must contain at least one segment. You can
 * also set the vertical extents of the grid line to limit which
 * levels the grid line appears on.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2011
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

//----------------------------------------

#ifndef LINWCGRIDLINE_HDR
#define LINWCGRIDLINE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a new grid line.
 *
 * \param label The label of the grid line.
 * \return Created grid line.
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGridLine LI_NWC_API
LiNwcGridLineCreate(LtWideString label);

/**
 * Creates a reference to a grid line.
 *
 * \param line Grid line.
 * \return Reference to existing grid line.
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGridLine LI_NWC_API
LiNwcGridLineCreateRef(LtNwcGridLine line);

/**
 * Destroys a grid line.
 *
 * \param line Grid line.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridLineDestroy(LtNwcGridLine line);

/**
 * Adds a linear segment to the grid line.
 *
 * The segment is specified as a start and end point
 * that lie on the xy plane of the grid system.
 *
 * \param line Grid line.
 * \param start Starting point of segment.
 * \param end Ending point of segment.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridLineAddLinearSegment(LtNwcGridLine line,
                              LtPoint start,
                              LtPoint end);

/**
 * Adds an arc segment to the grid line.
 *
 * The segment is specified as a centre, start and end points
 * that lie on the xy plane of the grid system. The arc
 * goes in an anti-clockwise direction from the start point
 * to the end point as viewed from the negative z direction
 * of the grid system (i.e. it follows the right-hand screw
 * rule).
 *
 * \param line Grid line.
 * \param centre Centre point of segment.
 * \param start Starting point of segment.
 * \param end Ending point of segment.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridLineAddArcSegment(LtNwcGridLine line,
                           LtPoint centre,
                           LtPoint start,
                           LtPoint end);

/**
 * Sets the vertical extents of the grid line.
 *
 * By default, a grid line will extend into infinity
 * both up and down. That is, it will appear on every grid
 * level defined in the system.
 *
 * You can limit which levels a grid line appears on by specifying
 * vertical extents. Then, the grid line will only appear on levels
 * that have an elevation in the range of the vertical extents.
 *
 * \param line Grid line.
 * \param min_elevation Minimum elevation grid line appears on.
 * \param max_elevation Maximum elevation grid line appears on.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridLineSetVerticalExtents(LtNwcGridLine line,
                                LtFloat min_elevation,
                                LtFloat max_elevation);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcGridLine API calls
 *
 * \see LiNwcGridLine.h
 */
class LcNwcGridLine
{
public:

   LcNwcGridLine(LtWideString label) : m_handle(LiNwcGridLineCreate(label)) {}
   LcNwcGridLine(LtNwcGridLine handle) : m_handle(LiNwcGridLineCreateRef(handle)) {}
   LcNwcGridLine(const LcNwcGridLine &other) : m_handle(LiNwcGridLineCreateRef(other)) {}

   ~LcNwcGridLine() { LiNwcGridLineDestroy(m_handle); }

   operator LtNwcGridLine () const { return m_handle; }
   LtNwcGridLine GetHandle() const { return m_handle; }

   void AddLinearSegment(LtPoint start,
                         LtPoint end)
   { LiNwcGridLineAddLinearSegment(m_handle, start, end); }

   void AddArcSegment(LtPoint centre,
                      LtPoint start,
                      LtPoint end)
   { LiNwcGridLineAddArcSegment(m_handle, centre, start, end); }

   void SetVerticalExtents(LtFloat min_elevation,
                           LtFloat max_elevation)
   { LiNwcGridLineSetVerticalExtents(m_handle, min_elevation, max_elevation); }

private:

   LtNwcGridLine m_handle;
};

#endif

#endif // LINWCGRIDLINE_HDR
