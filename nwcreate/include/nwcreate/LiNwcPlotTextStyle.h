/**
 * \file
 *
 * Defines stylization details for use with plot Text objects.
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

#ifndef LINWCPLOTTEXTSTYLE_HDR
#define LINWCPLOTTEXTSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a text style
 *
 *  \return Newly created style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotTextStyle LI_NWC_API
LiNwcPlotTextStyleCreate( void );

/**
 *  Create a reference to a text style
 *
 *  \param style Style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotTextStyle LI_NWC_API
LiNwcPlotTextStyleCreateRef( LtNwcPlotTextStyle style );

/**
 *  Create a copy to a text style
 *
 *  \param style Style for which a copy is created
 *  \return Copied style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotTextStyle LI_NWC_API
LiNwcPlotTextStyleCreateCopy( LtNwcPlotTextStyle style );

/**
 *  Destroy a text style
 *
 *  \param style Style to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleDestroy( LtNwcPlotTextStyle style );

/**
 *  Sets a brush as the brush for the text fill
 *
 *  \param style The style
 *  \param brush The brush for the text fill
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetFill( LtNwcPlotTextStyle style, LtNwcPlotBrush brush );

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
LiNwcPlotTextStyleClipStreamOpen( LtNwcPlotTextStyle style, LtNwcPlotPathStreamStyle clip_style );

/**
 *  Closes input to a clipping stream
 *
 *  \param style The style
 *  \param geometry_stream Stream handle of clipping stream to close
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleClipStreamClose( LtNwcPlotTextStyle style, LtNwcPlotGeometryStream geometry_stream );

/**
 *  Sets the 'em' height of the text in model units
 *
 *  \param style Text style
 *  \param height Em hight of text in model units.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetTextEmHeight( LtNwcPlotTextStyle style, LtFloat height );

/**
 *  Sets the character spacing of the text style, using ACW (average character width)
 *
 *  The default value is 1.0 (no modified spacing)
 *
 *  \param style Text style
 *  \param spacing Character spacing factor.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetCharacterSpacing( LtNwcPlotTextStyle style, LtFloat spacing );

/**
 *  Sets the rotation of the text style
 *
 *  The default value is 0 (no need to rotate)
 *
 * \param style Text style
 * \param rotation Text rotation radians.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetRotation( LtNwcPlotTextStyle style, LtFloat rotation );

/**
 *  Sets the horizontal alignment relative to the insertion point.
 *
 *  The default value is left.
 *
 *  \param style Text style
 *  \param horizontal_alignment One of the enumerated alignment values from LtNwcPlotTextHorizontalAlignment
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetHorizontalAlignment( LtNwcPlotTextStyle style, LtNwcPlotTextHorizontalAlignment horizontal_alignment );

/**
 *  Sets the vertical alignment relative to the insertion point.
 *
 *  The default value is base.
 *
 *  \param style Text style
 *  \param vertical_alignment One of the enumerated alignment values from LtNwcPlotTextVerticalAlignment
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetVerticalAlignment( LtNwcPlotTextStyle style, LtNwcPlotTextVerticalAlignment vertical_alignment );

/**
 *  Sets the text as being vertical (sideways - i.e. some asian fonts are vertical/sideways)
 *
 *  \param style The style
 *  \param flag The flag
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetIsSideways( LtNwcPlotTextStyle style, bool flag );

/**
 *  Sets the text as being right-to-left.  Insertion point is to the right of the first character.
 *
 *  \param style The style
 *  \param flag The flag
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetIsRightToLeft( LtNwcPlotTextStyle style, bool flag );

/**
 *  Sets the transform to apply to the text geometry
 *
 *  \param style The style
 *  \param transform The transform to use
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetTransform( LtNwcPlotTextStyle style, LtNwcPlotTransform transform );

/**
 *  Sets if it is an outline text
 *
 *  \param style The style
 *  \param is_outline outline text or not
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetIsOutLine( LtNwcPlotTextStyle style, bool is_outline);

/**
 *  Sets the opacity factor to apply to the style
 *
 *  \param style The style
 *  \param opacity_factor The factor to use (0 = transparent, 1 = opaque)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetOpacityFactor( LtNwcPlotTextStyle style, LtFloat opacity_factor );

/**
 *  Sets a brush as the brush for the opacity mask
 *
 *  \param style The style
 *  \param brush The brush for the opacity mask
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotTextStyleSetOpacityMask( LtNwcPlotTextStyle style, LtNwcPlotBrush brush );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotTextStyle API calls
 *
 * \see LiNwcPlotTextStyle.h
 */
class LcNwcPlotTextStyle
{
public:
    LcNwcPlotTextStyle( void ) : m_handle( LiNwcPlotTextStyleCreate() ) {}
    ~LcNwcPlotTextStyle( void ) { LiNwcPlotTextStyleDestroy( m_handle ); }

    LcNwcPlotTextStyle(const LcNwcPlotTextStyle &other) : m_handle(LiNwcPlotTextStyleCreateRef(other)) {}

    LcNwcPlotTextStyle& operator = (const LcNwcPlotTextStyle &other)
    {LiNwcPlotTextStyleDestroy(m_handle); m_handle = LiNwcPlotTextStyleCreateRef(other); return *this;}

    LtNwcPlotTextStyle CreateRef( LtNwcPlotTextStyle style )
    { return LiNwcPlotTextStyleCreateRef( style ); }

    LtNwcPlotTextStyle CreateCopy( LtNwcPlotTextStyle style )
    { return LiNwcPlotTextStyleCreateCopy( style ); }

    operator LtNwcPlotTextStyle () const
    { return static_cast<LtNwcPlotTextStyle>(m_handle); }

    LtNwcPlotTextStyle GetHandle() const
    { return static_cast<LtNwcPlotTextStyle>(m_handle); }

    LtNwcPlotGeometryStream ClipStreamOpen( LtNwcPlotPathStreamStyle style )
    { return LiNwcPlotTextStyleClipStreamOpen( m_handle, style ); }

    void ClipStreamClose( LtNwcPlotGeometryStream stream )
    { LiNwcPlotTextStyleClipStreamClose( m_handle, stream ); }

    void SetTextEmHeight( LtFloat height )
    { LiNwcPlotTextStyleSetTextEmHeight( m_handle, height ); }

    void SetCharacterSpacing( LtFloat spacing )
    { LiNwcPlotTextStyleSetCharacterSpacing( m_handle, spacing ); }

    void SetRotation( LtFloat rotation )
    { LiNwcPlotTextStyleSetRotation( m_handle, rotation ); }

    void SetHorizontalAlignment( LtNwcPlotTextHorizontalAlignment horizontal_alignment )
    { LiNwcPlotTextStyleSetHorizontalAlignment( m_handle, horizontal_alignment ); }

    void SetVerticalAlignment( LtNwcPlotTextVerticalAlignment vertical_alignment )
    { LiNwcPlotTextStyleSetVerticalAlignment( m_handle, vertical_alignment ); }

    void SetFill( LtNwcPlotBrush brush )
    { LiNwcPlotTextStyleSetFill( m_handle, brush ); }

    void SetIsSideways( bool flag )
    { LiNwcPlotTextStyleSetIsSideways( m_handle, flag ); }

    void SetIsRightToLeft( bool flag )
    { LiNwcPlotTextStyleSetIsRightToLeft( m_handle, flag ); }

    void SetTransform( LtNwcPlotTransform transform )
    { LiNwcPlotTextStyleSetTransform( m_handle, transform ); }

    void SetIsOutLine( bool is_outline)
    { LiNwcPlotTextStyleSetIsOutLine( m_handle, is_outline); }

    void SetOpacityFactor( LtFloat opacity_factor )
    { LiNwcPlotTextStyleSetOpacityFactor( m_handle, opacity_factor ); }

    void SetOpacityMask( LtNwcPlotBrush brush )
    { LiNwcPlotTextStyleSetOpacityMask( m_handle, brush ); }

private:
    LtNwcPlotTextStyle m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTTEXTSTYLE_HDR */
