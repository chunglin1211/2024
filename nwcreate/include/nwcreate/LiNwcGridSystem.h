/**
 * \file
 *
 * Component for defining a system of grid lines and levels. A
 * grid system is defined as a co-ordinate frame in 3D space and a
 * collection of grid levels and grid lines. Once a system is
 * added to a scene, positions in the scene can be reported by
 * grid position.
 *
 * To be useful, a grid system needs at lease one level, and at
 * least two grid lines that intersect at least once.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2011 Autodesk, Inc.  All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 *
 */

//----------------------------------------

#ifndef LINWCGRIDSYSTEM_HDR
#define LINWCGRIDSYSTEM_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a new grid system.
 *
 * A grid system is positioned in the world, and has an
 * orientation. Levels are parallel to the xy plane, and
 * sit at a given Z distance from the origin.
 *
 * \param label The label of the grid system.
 * \param origin The origin in world space of the grid system.
 * \param x_axis The x-axis of the grid system.
 * \param y_axis The y-axis of the grid system.
 * \return Created grid system.
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGridSystem LI_NWC_API
LiNwcGridSystemCreate(LtWideString label,
                      LtPoint origin,
                      LtVector x_axis,
                      LtVector y_axis);

/**
 * Creates a reference to a grid system.
 *
 * \param system Grid system.
 * \return Reference to existing grid system.
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGridSystem LI_NWC_API
LiNwcGridSystemCreateRef(LtNwcGridSystem system);

/**
 * Destroys a grid system.
 *
 * \param system Grid system.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridSystemDestroy(LtNwcGridSystem system);

/**
 * Adds a grid line to the system.
 *
 * \param system Grid system.
 * \param line Grid line to add.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridSystemAddGridLine(LtNwcGridSystem system,
                           LtNwcGridLine line);

/**
 * Adds a grid level to the system.
 *
 * \param system Grid system.
 * \param level Grid level to add.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridSystemAddGridLevel(LtNwcGridSystem system,
                            LtNwcGridLevel level);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcGridSystem API calls
 *
 * \see LiNwcGridSystem.h
 */
class LcNwcGridSystem
{
public:

   LcNwcGridSystem(LtWideString label,
                   LtPoint origin,
                   LtVector x_axis,
                   LtVector y_axis) : m_handle(LiNwcGridSystemCreate(label,
                                                                     origin,
                                                                     x_axis,
                                                                     y_axis))
   {}

   LcNwcGridSystem(LtNwcGridSystem handle) : m_handle(LiNwcGridSystemCreateRef(handle))
   {}

   LcNwcGridSystem(const LcNwcGridSystem &other) : m_handle(LiNwcGridSystemCreateRef(other))
   {}

   ~LcNwcGridSystem() { LiNwcGridSystemDestroy(m_handle); }

   operator LtNwcGridSystem () const { return m_handle; }
   LtNwcGridSystem GetHandle() const { return m_handle; }

   void AddGridLine(LtNwcGridLine line)
   { LiNwcGridSystemAddGridLine(m_handle, line); }

   void AddGridLevel(LtNwcGridLevel level)
   { LiNwcGridSystemAddGridLevel(m_handle, level); }

private:

   LtNwcGridSystem m_handle;
};

#endif

#endif // LINWCGRIDSYSTEM_HDR
