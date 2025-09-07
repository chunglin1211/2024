/**
 * \file
 *
 * Defines stylization details for use with PathStream objects.
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
 */

#ifndef LINWCPLOTPATHSTREAMSTYLE_HDR
#define LINWCPLOTPATHSTREAMSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a path stream style
 *
 *  \return Newly created style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathStreamStyle LI_NWC_API
LiNwcPlotPathStreamStyleCreate( void );

/**
 *  Create a reference to a path stream style
 *
 *  \param style Style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathStreamStyle LI_NWC_API
LiNwcPlotPathStreamStyleCreateRef( LtNwcPlotPathStreamStyle style );

/**
 *  Create a copy to a path stream style
 *
 *  \param style Style for which a copy is created
 *  \return Copied style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathStreamStyle LI_NWC_API
LiNwcPlotPathStreamStyleCreateCopy( LtNwcPlotPathStreamStyle style );

/**
 *  Destroy a path stream style
 *
 *  \param style Style to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStreamStyleDestroy( LtNwcPlotPathStreamStyle style );

/**
 *  Sets the fill rule for the path stream
 *
 *  Describes how the intersecting areas of the shapes are filled to form an entire region.
 *  Valid values are even odd, and non zero.
 *
 *  \param style The style
 *  \param fill_rule The fill rule to apply
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStreamStyleSetFillRule( LtNwcPlotPathStreamStyle style, LtNwcPlotPathFillRule fill_rule );

/**
 *  Sets the transform to apply to the path stream
 *
 *  \param style The style
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathStreamStyleSetTransform( LtNwcPlotPathStreamStyle style, LtNwcPlotTransform transform );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotPathStreamStyle API calls
 *
 * \see LiNwcPlotPathStreamStyle.h
 */
class LcNwcPlotPathStreamStyle
{
public:
    LcNwcPlotPathStreamStyle( void ) : m_handle( LiNwcPlotPathStreamStyleCreate() ) {}
    ~LcNwcPlotPathStreamStyle( void ) { LiNwcPlotPathStreamStyleDestroy(m_handle); }

    LcNwcPlotPathStreamStyle(const LcNwcPlotPathStreamStyle &other) : m_handle(LiNwcPlotPathStreamStyleCreateRef(other)) {}

    LcNwcPlotPathStreamStyle& operator = (const LcNwcPlotPathStreamStyle &other)
    {LiNwcPlotPathStreamStyleDestroy(m_handle); m_handle = LiNwcPlotPathStreamStyleCreateRef(other); return *this;}

    LtNwcPlotPathStreamStyle CreateCopy( LtNwcPlotPathStreamStyle style )
    { return LiNwcPlotPathStreamStyleCreateCopy( style ); }

    operator LtNwcPlotPathStreamStyle () const
    { return static_cast<LtNwcPlotPathStreamStyle>(m_handle); }

    LtNwcPlotPathStreamStyle GetHandle() const
    { return static_cast<LtNwcPlotPathStreamStyle>(m_handle); }

    void SetFillRule( LtNwcPlotPathFillRule fill_rule )
    { LiNwcPlotPathStreamStyleSetFillRule( m_handle, fill_rule ); }

    void SetTransform( LtNwcPlotTransform transform )
    { LiNwcPlotPathStreamStyleSetTransform( m_handle, transform ); }

    private:
        LtNwcPlotPathStreamStyle m_handle;
};


#endif /* __cplusplus */

#endif /* LINWCPLOTPATHSTREAMSTYLE_HDR */
