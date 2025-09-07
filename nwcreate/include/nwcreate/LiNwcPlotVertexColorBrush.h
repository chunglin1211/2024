/**
 * \file
 *
 * Defines a vertex color brush for filling a closed Path or coloring
 * a Stroke.  This brush is a set of indices (corresponding to the
 * vertices of the containing Path), and colors to be applied to
 * each vertex. The rendering engine is tasked with interpolating colors
 * between the vertices.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2010 Autodesk, Inc. All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 *
 */

#ifndef LINWCPLOTVERTEXCOLORBRUSH_HDR
#define LINWCPLOTVERTEXCOLORBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotBrush.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a vertex color brush
 *
 *  \return Newly created brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotVertexColorBrush LI_NWC_API
LiNwcPlotVertexColorBrushCreate( void );

/**
 *  Create a reference to a vertex color brush
 *
 *  \param brush Brush to which a reference is created
 *  \return Referenced brush or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotVertexColorBrush LI_NWC_API
LiNwcPlotVertexColorBrushCreateRef( LtNwcPlotVertexColorBrush brush );

/**
 *  Destroy a vertex color brush
 *
 *  \param brush Brush to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotVertexColorBrushDestroy( LtNwcPlotVertexColorBrush brush );

#ifdef __cplusplus
}


/**
 * C++ wrapper around LtNwcPlotVertexColorBrush API calls
 *
 * \see LiNwcPlotVertexColorBrush.h
 */
class LcNwcPlotVertexColorBrush : public LcNwcPlotBrush
{
public:
   LcNwcPlotVertexColorBrush() : LcNwcPlotBrush(LiNwcPlotVertexColorBrushCreate(), true) {}
   LcNwcPlotVertexColorBrush(LtNwcPlotVertexColorBrush handle) : LcNwcPlotBrush(handle) {}

   operator LtNwcPlotVertexColorBrush () const
   { return static_cast<LtNwcPlotVertexColorBrush>(LcNwcPlotBrush::GetHandle()); }
   LtNwcPlotVertexColorBrush GetHandle() const
   { return static_cast<LtNwcPlotVertexColorBrush>(LcNwcPlotBrush::GetHandle()); }
};

#endif /* __cplusplus */

#endif /* LINWCPLOTVERTEXCOLORBRUSH_HDR */
