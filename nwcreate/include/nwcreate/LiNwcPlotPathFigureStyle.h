/**
 * \file
 *
 * Defines stylization details for use with PathFigure objects.
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

#ifndef LINWCPLOTPATHFIGURESTYLE_HDR
#define LINWCPLOTPATHFIGURESTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a path figure style
 *
 *  \return Newly created style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathFigureStyle LI_NWC_API
LiNwcPlotPathFigureStyleCreate( void );

/**
 *  Create a reference to a path figure style
 *
 *  \param style Style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathFigureStyle LI_NWC_API
LiNwcPlotPathFigureStyleCreateRef( LtNwcPlotPathFigureStyle style );

/**
 *  Create a copy to a path figure style
 *
 *  \param style Style for which a copy is created
 *  \return Copied style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotPathFigureStyle LI_NWC_API
LiNwcPlotPathFigureStyleCreateCopy( LtNwcPlotPathFigureStyle style );

/**
 *  Destroy a path figure style
 *
 *  \param style Style to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathFigureStyleDestroy( LtNwcPlotPathFigureStyle style );

/**
 *  Sets whether the path figure should be closed (segment drawn from last point to start point)
 *
 *  \param style The style
 *  \param flag The boolean flag
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathFigureStyleSetIsClosed( LtNwcPlotPathFigureStyle style, bool flag );

/**
 *  Sets whether the path figure should be filled (requies a Fill brush to be set on the path)
 *
 *  \param style The style
 *  \param flag The boolean flag
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathFigureStyleSetIsFilled( LtNwcPlotPathFigureStyle style, bool flag );

/**
 *  Sets the connect rule (valid only for poly line segment)
 *
 *  \param style The style
 *  \param rule The connect rule (see LtNwcPlotPolylineConnectRule)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotPathFigureStyleSetPolyLineConnectRule( LtNwcPlotPathFigureStyle style, LtNwcPlotPolyLineConnectRule rule );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotPathFigureStyle API calls
 *
 * \see LiNwcPlotPathFigureStyle.h
 */
class LcNwcPlotPathFigureStyle
{
public:
    LcNwcPlotPathFigureStyle( void ) : m_handle( LiNwcPlotPathFigureStyleCreate() ) {}
    ~LcNwcPlotPathFigureStyle( void ) { LiNwcPlotPathFigureStyleDestroy(m_handle); }

    LcNwcPlotPathFigureStyle(const LcNwcPlotPathFigureStyle &other) : m_handle(LiNwcPlotPathFigureStyleCreateRef(other)) {}

    LcNwcPlotPathFigureStyle& operator = (const LcNwcPlotPathFigureStyle &other)
    {LiNwcPlotPathFigureStyleDestroy(m_handle); m_handle = LiNwcPlotPathFigureStyleCreateRef(other); return *this;}

    LtNwcPlotPathFigureStyle CreateCopy( LtNwcPlotPathFigureStyle style )
    { return LiNwcPlotPathFigureStyleCreateCopy( style ); }

    operator LtNwcPlotPathFigureStyle () const
    { return static_cast<LtNwcPlotPathFigureStyle>(m_handle); }

    LtNwcPlotPathFigureStyle GetHandle() const
    { return static_cast<LtNwcPlotPathFigureStyle>(m_handle); }

    void SetIsClosed( bool flag )
    { LiNwcPlotPathFigureStyleSetIsClosed( m_handle, flag ); }

    void SetIsFilled( bool flag )
    { LiNwcPlotPathFigureStyleSetIsFilled( m_handle, flag ); }

    void SetPolyLineConnectRule( LtNwcPlotPolyLineConnectRule rule )
    { LiNwcPlotPathFigureStyleSetPolyLineConnectRule( m_handle, rule ); }

    private:
        LtNwcPlotPathFigureStyle m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTPATHFIGURESTYLE_HDR */
