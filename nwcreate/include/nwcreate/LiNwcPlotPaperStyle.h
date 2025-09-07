/**
 * \file
 *
 * Definition for plot paper style
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

#ifndef LINWCPLOTPAPERSTYLE_HDR
#define LINWCPLOTPAPERSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a paper style
 *
 *  \return Newly created paper style or NULL on error
 *  \version 2.0
 */
LI_NWC_PUBLIC LtNwcPlotPaperStyle LI_NWC_API
LiNwcPlotPaperStyleCreate();

/**
 *  Destroy a paper style
 *
 *  \param style paper style to destroy
 *  \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPaperStyleDestroy( LtNwcPlotPaperStyle style );

/**
 *  Create a reference to a paper style
 *
 *  \param style Paper style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPaperStyle LI_NWC_API
LiNwcPlotPaperStyleCreateRef( LtNwcPlotPaperStyle style );

/**
 *  Sets the initial paper visibility
 *
 *  \param style The paper style
 *  \param flag the flag
 *  \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPaperStyleSetVisible( LtNwcPlotPaperStyle style, bool flag );

/**
 *  Sets the paper color
 *
 *  \param style The paper style
 *  \param r the red value (0.0 to 1.0) of the color
 *  \param g the green value (0.0 to 1.0) of the color
 *  \param b the blue value (0.0 to 1.0) of the color
 *  \param a the alpha value (0.0 to 1.0) of the color
 *  \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPaperStyleSetColor( LtNwcPlotPaperStyle style, LtFloat r, LtFloat g, LtFloat b, LtFloat a );

/**
 *  Sets the units of the paper size/clip values
 *
 *  See the LtNwcPlotPaperUnits enumeration
 *
 *  Default is inches
 *
 *  \param style The paper style
 *  \param units the units
 *  \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPaperStyleSetUnits( LtNwcPlotPaperStyle style, LtNwcPlotPaperUnits units );

/**
 *  Sets the paper size
 *
 *  \param style The paper style
 *  \param size the size (in paper units)
 *  \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPaperStyleSetSize( LtNwcPlotPaperStyle style, LtVector2d size );

/**
 *  Sets the clipping region outside which no standard geometry should be rendered
 *
 *  Note, markup geometry may appear outside the clipping region
 *
 *  \param style The paper style
 *  \param left the clipping offset from the left edge of the paper
 *  \param top the clipping offset from the top edge of the paper
 *  \param right the clipping offset from the right edge of the paper
 *  \param bottom the clipping offset from the bottom edge of the paper
 *  \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPaperStyleSetClip( LtNwcPlotPaperStyle style, LtFloat left, LtFloat top, LtFloat right, LtFloat bottom );


#ifdef __cplusplus
}


/**
 * C++ wrapper around LtNwcPlotPaperStyle API calls
 *
 * \see LiNwcPlotPaperStyle.h
 */
class LcNwcPlotPaperStyle
{
public:
    LcNwcPlotPaperStyle( void ) : m_handle(LiNwcPlotPaperStyleCreate()) {  }
    ~LcNwcPlotPaperStyle( void ) { LiNwcPlotPaperStyleDestroy(m_handle); }

    LcNwcPlotPaperStyle(const LcNwcPlotPaperStyle &other) : m_handle(LiNwcPlotPaperStyleCreateRef(other)) {}

    LcNwcPlotPaperStyle& operator = (const LcNwcPlotPaperStyle &other)
    {LiNwcPlotPaperStyleDestroy(m_handle); m_handle = LiNwcPlotPaperStyleCreateRef(other); return *this;}

    operator LtNwcPlotPaperStyle () const
    { return static_cast<LtNwcPlotPaperStyle>(m_handle); }

    LtNwcPlotPaperStyle GetHandle() const
    { return static_cast<LtNwcPlotPaperStyle>(m_handle); }

    void Destroy( LtNwcPlotPaperStyle style )
    { LiNwcPlotPaperStyleDestroy( style ); }

    void SetVisible( bool flag )
    { LiNwcPlotPaperStyleSetVisible( GetHandle(), flag ); }

    void SetColor( LtFloat r, LtFloat g, LtFloat b, LtFloat a )
    { LiNwcPlotPaperStyleSetColor( GetHandle(), r, g, b, a ); }

    void SetUnits( LtNwcPlotPaperUnits units )
    { LiNwcPlotPaperStyleSetUnits( GetHandle(), units ); }

    void SetSize( LtVector2d size )
    { LiNwcPlotPaperStyleSetSize( GetHandle(), size ); }

    void SetClip( LtFloat left, LtFloat top, LtFloat right, LtFloat bottom )
    { LiNwcPlotPaperStyleSetClip( GetHandle(), left, top, right, bottom ); }

private:
   LtNwcPlotPaperStyle m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTPAPERSTYLE_HDR */
