/**
 * \file
 *
 * Defines stylization details for use with plot Viewport objects.
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

#ifndef LTNWCPLOTVIEWPORTSTYLE_HDR
#define LTNWCPLOTVIEWPORTSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a viewport style
 *
 *  \return Newly created style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotViewportStyle LI_NWC_API
LiNwcPlotViewportStyleCreate( void );

/**
 *  Create a reference to a viewport style
 *
 *  \param style Style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotViewportStyle LI_NWC_API
LiNwcPlotViewportStyleCreateRef( LtNwcPlotViewportStyle style );

/**
 *  Create a copy to a viewport style
 *
 *  \param style Style for which a copy is created
 *  \return Copied style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotViewportStyle LI_NWC_API
LiNwcPlotViewportStyleCreateCopy( LtNwcPlotViewportStyle style );

/**
 *  Destroy a viewport style
 *
 *  \param style Style to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotViewportStyleDestroy( LtNwcPlotViewportStyle style );

/**
 *  Opens input to a stream to define a clipping region
 *
 *  \return Newly opened clip stream or NULL on error
 *
 *  \param style The style
 *  \param clip_style Style containing clip stream options
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotGeometryStream LI_NWC_API
LiNwcPlotViewportStyleClipStreamOpen( LtNwcPlotViewportStyle style, LtNwcPlotPathStreamStyle clip_style );

/**
 *  Closes input to a clipping stream
 *
 *  \param style The style
 *  \param geometry_stream Stream handle of clipping stream to close
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotViewportStyleClipStreamClose( LtNwcPlotViewportStyle style, LtNwcPlotGeometryStream geometry_stream );

/**
 *  Sets the transform that transforms viewport coordinates to real world coordinates
 *
 *  \param style The style
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotViewportStyleSetWorldTransform( LtNwcPlotViewportStyle style, LtNwcPlotTransform transform );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotViewportStyle API calls
 *
 * \see LiNwcPlotViewportStyle.h
 */
class LcNwcPlotViewportStyle
{
public:
    LcNwcPlotViewportStyle( void ) : m_handle( LiNwcPlotViewportStyleCreate() ) {}
    ~LcNwcPlotViewportStyle( void ) { LiNwcPlotViewportStyleDestroy(m_handle); }

    LcNwcPlotViewportStyle(const LcNwcPlotViewportStyle &other) : m_handle(LiNwcPlotViewportStyleCreateRef(other)) {}

    LcNwcPlotViewportStyle& operator = (const LcNwcPlotViewportStyle &other)
    {LiNwcPlotViewportStyleDestroy(m_handle); m_handle = LiNwcPlotViewportStyleCreateRef(other); return *this;}

    LtNwcPlotViewportStyle CreateCopy( LtNwcPlotViewportStyle style )
    { return LiNwcPlotViewportStyleCreateCopy( style ); }

    operator LtNwcPlotViewportStyle () const
    { return static_cast<LtNwcPlotViewportStyle>(m_handle); }

    LtNwcPlotViewportStyle GetHandle() const
    { return static_cast<LtNwcPlotViewportStyle>(m_handle); }

    LtNwcPlotGeometryStream ClipStreamOpen( LtNwcPlotPathStreamStyle style )
    { return LiNwcPlotViewportStyleClipStreamOpen( m_handle, style ); }

    void ClipStreamClose( LtNwcPlotGeometryStream stream )
    { LiNwcPlotViewportStyleClipStreamClose( m_handle, stream ); }

    void SetWorldTransform( LtNwcPlotTransform transform )
    { LiNwcPlotViewportStyleSetWorldTransform( m_handle, transform ); }

    private:
        LtNwcPlotViewportStyle m_handle;

};

#endif /* __cplusplus */

#endif /* LTNWCPLOTVIEWPORTSTYLE_HDR */
