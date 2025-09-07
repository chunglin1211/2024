/**
 * \file
 *
 * Defines stylization details for use with Path objects.
 *
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

#ifndef LINWCPLOTPATHSTYLE_HDR
#define LINWCPLOTPATHSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a path style
 *
 *  \return Newly created style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathStyle LI_NWC_API
LiNwcPlotPathStyleCreate( void );

/**
 *  Create a reference to a path style
 *
 *  \param style Style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathStyle LI_NWC_API
LiNwcPlotPathStyleCreateRef( LtNwcPlotPathStyle style );

/**
 *  Create a copy to a path style
 *
 *  \param style Style for which a copy is created
 *  \return Copied style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathStyle LI_NWC_API
LiNwcPlotPathStyleCreateCopy( LtNwcPlotPathStyle style );

/**
 *  Destroy a path style
 *
 *  \param style Style to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStyleDestroy( LtNwcPlotPathStyle style );

/**
 *  Sets a brush as the brush for the path fill
 *
 *  \param style The style
 *  \param brush The brush for the path fill
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStyleSetFill( LtNwcPlotPathStyle style, LtNwcPlotBrush brush );

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
LiNwcPlotPathStyleClipStreamOpen( LtNwcPlotPathStyle style, LtNwcPlotPathStreamStyle clip_style );

/**
 *  Closes input to a clipping stream
 *
 *  \param style The style
 *  \param geometry_stream Stream handle of clipping stream to close
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStyleClipStreamClose( LtNwcPlotPathStyle style, LtNwcPlotGeometryStream geometry_stream );

/**
 *  Sets the stroke definition for the path style
 *
 *  \param style The style
 *  \param stroke The stroke definition
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStyleSetStroke( LtNwcPlotPathStyle style, LtNwcPlotStroke stroke );

/**
 *  Sets the transform to apply to the path geometry
 *
 *  \param style The style
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStyleSetTransform( LtNwcPlotPathStyle style, LtNwcPlotTransform transform );

/**
 *  Sets the opacity factor to apply to the style
 *
 *  \param style The style
 *  \param opacity_factor The factor to use (0 = transparent, 1 = opaque)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStyleSetOpacityFactor( LtNwcPlotPathStyle style, LtFloat opacity_factor );

/**
 *  Sets a brush as the brush for the opacity mask
 *
 *  \param style The style
 *  \param brush The brush for the opacity mask
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStyleSetOpacityMask( LtNwcPlotPathStyle style, LtNwcPlotBrush brush );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotPathStyle API calls
 *
 * \see LiNwcPlotPathStyle.h
 */
class LcNwcPlotPathStyle
{
public:

    LcNwcPlotPathStyle( void ) : m_handle( LiNwcPlotPathStyleCreate() ) {}
    ~LcNwcPlotPathStyle( void ) { LiNwcPlotPathStyleDestroy( m_handle ); };

    LcNwcPlotPathStyle(const LcNwcPlotPathStyle &other) : m_handle(LiNwcPlotPathStyleCreateRef(other)) {}

    LcNwcPlotPathStyle& operator = (const LcNwcPlotPathStyle &other)
    {LiNwcPlotPathStyleDestroy(m_handle); m_handle = LiNwcPlotPathStyleCreateRef(other); return *this;}

    LtNwcPlotPathStyle CreateCopy( LtNwcPlotPathStyle style )
    { return LiNwcPlotPathStyleCreateCopy( style ); }

    operator LtNwcPlotPathStyle () const
    { return static_cast<LtNwcPlotPathStyle>(m_handle); }

    LtNwcPlotPathStyle GetHandle() const
    { return static_cast<LtNwcPlotPathStyle>(m_handle); }

    void SetFill( LtNwcPlotBrush brush )
    { LiNwcPlotPathStyleSetFill( m_handle, brush ); }

    LtNwcPlotGeometryStream ClipStreamOpen( LtNwcPlotPathStreamStyle style )
    { return LiNwcPlotPathStyleClipStreamOpen( m_handle, style ); }

    void ClipStreamClose( LtNwcPlotGeometryStream stream )
    { LiNwcPlotPathStyleClipStreamClose( m_handle, stream ); }

    void SetStroke( LtNwcPlotStroke stroke )
    { LiNwcPlotPathStyleSetStroke( m_handle, stroke ); }

    void SetTransform( LtNwcPlotTransform transform )
    { LiNwcPlotPathStyleSetTransform( m_handle, transform ); }

    void SetOpacityFactor( LtFloat opacity_factor )
    { LiNwcPlotPathStyleSetOpacityFactor( m_handle, opacity_factor ); }

    void SetOpacityMask( LtNwcPlotBrush brush )
    { LiNwcPlotPathStyleSetOpacityMask( m_handle, brush ); }

    private:
        LtNwcPlotPathStyle m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTPATHSTYLE_HDR */
