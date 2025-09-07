/**
 * \file
 *
 * Component for defining grid levels in a system. A level is
 * defined as an infinite plane in the XY direction at a given
 * elevation in the Z direction of the grid system.
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

#ifndef LINWCGRIDLEVEL_HDR
#define LINWCGRIDLEVEL_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a new grid level.
 *
 * A grid level can be thought of as as infinite plane
 * on the xy axis of the grid system. The elevation is the distance
 * along the z axis of the system the level is positioned at.
 *
 * \param label The label of the grid level.
 * \param elevation The elevation of the grid level above the origin of the grid system.
 * \return Created grid level.
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGridLevel LI_NWC_API
LiNwcGridLevelCreate(LtWideString label,
                     LtFloat elevation);

/**
 * Creates a reference to an existing grid level.
 *
 * \param level Grid level.
 * \return Reference to grid level.
 * \version 10.0
 */
LI_NWC_PUBLIC LtNwcGridLevel LI_NWC_API
LiNwcGridLevelCreateRef(LtNwcGridLevel level);

/**
 * Destroys a grid level.
 *
 * \param level Grid level.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGridLevelDestroy(LtNwcGridLevel level);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcGridLevel API calls
 *
 * \see LiNwcGridLevel.h
 */
class LcNwcGridLevel
{
public:

   LcNwcGridLevel(LtWideString label, LtFloat elevation) : m_handle(LiNwcGridLevelCreate(label, elevation)) {}
   LcNwcGridLevel(LtNwcGridLevel handle) : m_handle(LiNwcGridLevelCreateRef(handle)) {}
   LcNwcGridLevel(const LcNwcGridLevel &other) : m_handle(LiNwcGridLevelCreateRef(other)) {}

   ~LcNwcGridLevel() { LiNwcGridLevelDestroy(m_handle); }

   operator LtNwcGridLevel () const { return m_handle; }
   LtNwcGridLevel GetHandle() const { return m_handle; }

private:

   LtNwcGridLevel m_handle;
};

#endif

#endif // LINWCGRIDLEVEL_HDR
