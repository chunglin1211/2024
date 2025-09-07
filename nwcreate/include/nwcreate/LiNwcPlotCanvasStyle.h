/**
 * \file
 *
 * Defines stylization details for use with Canvas objects.
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

#ifndef LTNWCPLOTCANVASSTYLE_HDR
#define LTNWCPLOTCANVASSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a canvas style
 *
 *  \return Newly created style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotCanvasStyle LI_NWC_API
LiNwcPlotCanvasStyleCreate( void );

/**
 *  Create a reference to a canvas style
 *
 *  \param style Style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotCanvasStyle LI_NWC_API
LiNwcPlotCanvasStyleCreateRef( LtNwcPlotCanvasStyle style );

/**
 *  Create a copy to a canvas style
 *
 *  \param style Style for which a copy is created
 *  \return Copied style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotCanvasStyle LI_NWC_API
LiNwcPlotCanvasStyleCreateCopy( LtNwcPlotCanvasStyle style );

/**
 *  Destroy a canvas style
 *
 *  \param style Style to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCanvasStyleDestroy( LtNwcPlotCanvasStyle style );

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
LiNwcPlotCanvasStyleClipStreamOpen( LtNwcPlotCanvasStyle style, LtNwcPlotPathStreamStyle clip_style );

/**
 *  Closes input to a clipping stream
 *
 *  \param style The style
 *  \param geometry_stream Stream handle of clipping stream to close
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCanvasStyleClipStreamClose( LtNwcPlotCanvasStyle style, LtNwcPlotGeometryStream geometry_stream );

/**
 *  Sets whether to use anti aliasing for the canvas style
 *
 *  \param style The style
 *  \param flag The flag
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCanvasStyleSetAntiAliasEdges( LtNwcPlotCanvasStyle style, bool flag);

/**
 *  Sets the transform to apply to the canvas geometry
 *
 *  \param style The style
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCanvasStyleSetTransform( LtNwcPlotCanvasStyle style, LtNwcPlotTransform transform );

/**
 *  Sets the opacity factor to apply to the style
 *
 *  \param style The style
 *  \param opacity_factor The factor to use (0 = transparent, 1 = opaque)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCanvasStyleSetOpacityFactor( LtNwcPlotCanvasStyle style, LtFloat opacity_factor );

/**
 *  Sets a brush as the brush for the opacity mask
 *
 *  \param style The style
 *  \param brush The brush for the opacity mask
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotCanvasStyleSetOpacityMask( LtNwcPlotCanvasStyle style, LtNwcPlotBrush brush );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotCanvasStyle API calls
 *
 * \see LiNwcPlotCanvasStyle.h
 */
class LcNwcPlotCanvasStyle
{
public:
    LcNwcPlotCanvasStyle( void ) : m_handle( LiNwcPlotCanvasStyleCreate() ) {}
    ~LcNwcPlotCanvasStyle( void ) { LiNwcPlotCanvasStyleDestroy( m_handle ); };

    LcNwcPlotCanvasStyle(const LcNwcPlotCanvasStyle &other) : m_handle(LiNwcPlotCanvasStyleCreateRef(other)) {}

    LcNwcPlotCanvasStyle& operator = (const LcNwcPlotCanvasStyle &other)
    {LiNwcPlotCanvasStyleDestroy(m_handle); m_handle = LiNwcPlotCanvasStyleCreateRef(other); return *this;}

    LtNwcPlotCanvasStyle CreateCopy( LtNwcPlotCanvasStyle style )
    { return LiNwcPlotCanvasStyleCreateCopy( style ); }

    operator LtNwcPlotCanvasStyle () const
    { return static_cast<LtNwcPlotCanvasStyle>(m_handle); }

    LtNwcPlotCanvasStyle GetHandle() const
    { return static_cast<LtNwcPlotCanvasStyle>(m_handle); }

    LtNwcPlotGeometryStream ClipStreamOpen( LtNwcPlotPathStreamStyle style )
    { return LiNwcPlotCanvasStyleClipStreamOpen( m_handle, style ); }

    void ClipStreamClose( LtNwcPlotGeometryStream stream )
    { LiNwcPlotCanvasStyleClipStreamClose( m_handle, stream ); }

    void SetAntiAliasEdges( bool flag )
    { LiNwcPlotCanvasStyleSetAntiAliasEdges( m_handle, flag ); }

    void SetTransform( LtNwcPlotTransform transform )
    { LiNwcPlotCanvasStyleSetTransform( m_handle, transform ); }

    void SetOpacityFactor( LtFloat opacity_factor )
    { LiNwcPlotCanvasStyleSetOpacityFactor( m_handle, opacity_factor ); }

    void SetOpacityMask( LtNwcPlotBrush brush )
    { LiNwcPlotCanvasStyleSetOpacityMask( m_handle, brush ); }

    private:
        LtNwcPlotCanvasStyle m_handle;
};

#endif /* __cplusplus */

#endif /* LTNWCPLOTCANVASSTYLE_HDR */
