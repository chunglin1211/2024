/**
 * \file
 *
 * Defines stylization details for use with Font (and EmbeddedFont) objects.
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

#ifndef LINWCFONTSTYLE_HDR
#define LINWCFONTSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcPlotEnums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a font style
 *
 *  \return Newly created style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotFontStyle LI_NWC_API
LiNwcPlotFontStyleCreate( void );

/**
 *  Create a reference to a font style
 *
 *  \param style Style to which a reference is created
 *  \return Referenced style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotFontStyle LI_NWC_API
LiNwcPlotFontStyleCreateRef( LtNwcPlotFontStyle style );

/**
 *  Create a copy to a font style
 *
 *  \param style Style for which a copy is created
 *  \return Copied style or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotFontStyle LI_NWC_API
LiNwcPlotFontStyleCreateCopy( LtNwcPlotFontStyle style );

/**
 *  Destroy a font style
 *
 *  \param style Style to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleDestroy( LtNwcPlotFontStyle style );

/**
 *  Sets the canonical typeface for the font.
 *
 *  Typefaces for vertical fonts should be preceeded with an '@'
 *
 *  \param style Font style
 *  \param typeface Typeface of font
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetTypeface(LtNwcPlotFontStyle style, LtWideString typeface);

/**
 *  Sets the character traits (bitfield) for the font.
 *
 *  See the LtNwcPlotFontStyleCharacterTraits enumeration for bit definitions.
 *
 *  \param style Font style
 *  \param traits Character traits of the font (bitfield)
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetCharacterTraits(LtNwcPlotFontStyle style, LtInt32 traits );

/**
 *  Sets the point size of the text. Note that this value
 *  has no effect on the rendered size of the text. It just
 *  determines which font is used.
 *
 *  The default value for this is 50pt.
 *
 *  \param style Font style
 *  \param point_size Size of font in points.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetPointSize(LtNwcPlotFontStyle style, LtInt32 point_size);

/**
 *  Sets the weight of the font.
 *
 *  See the LtNwcPlotFontStyleWeight enumeration for weight values.
 *
 *  \param style Font style
 *  \param weight Weight of the font.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetWeight(LtNwcPlotFontStyle style, LtNwcPlotFontStyleWeight weight);

/**
 *  Sets the character set of the font.
 *
 *  Specifies the character set, used to help font mapping to mitigate
 *  the possibility of the font not being found on the system.
 *
 *  See the LtNwcPlotFontStyleCharacterSet enumeration
 *
 *  \param style Font style
 *  \param character_set The character set of the font
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetCharacterSet(LtNwcPlotFontStyle style, LtNwcPlotFontStyleCharacterSet character_set );

/**
 *  Sets the pitch of the font.
 *
 *  Specifies the font pitch, used to help font mapping to mitigate
 *  the possibility of the font not being found on the system.
 *
 *  See the LtNwcFontPitch enumeration
 *
 *  \param style Font style
 *  \param pitch The pitch of the font
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetPitch(LtNwcPlotFontStyle style, LtNwcPlotFontPitch pitch );

/**
 *  Sets the family of the font.
 *
 *  Specifies the font family, used to help font mapping to mitigate
 *  the possibility of the font not being found on the system.
 *
 *  See the LtNwcFontFamily enumeration.
 *
 *  \param style Font style
 *  \param family The family of the font
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetFamily(LtNwcPlotFontStyle style, LtNwcPlotFontFamily family );

/**
 *  Sets the embedded font
 *
 *  If the typeface here matches the embedded font's name, then it is supposed to use embedded font instead.
 *
 *  \param style Font style
 *  \param embedded_font embedded font to be set
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotFontStyleSetEmbeddedFont(LtNwcPlotFontStyle style, LtNwcPlotEmbeddedFont embedded_font);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotFontStyle API calls
 *
 * \see LiNwcPlotFontStyle.h
 */
class LcNwcPlotFontStyle
{
public:
    LcNwcPlotFontStyle( void ) : m_handle( LiNwcPlotFontStyleCreate() ) {}
    ~LcNwcPlotFontStyle( void ) { LiNwcPlotFontStyleDestroy(m_handle); }

    LcNwcPlotFontStyle(const LcNwcPlotFontStyle &other) : m_handle(LiNwcPlotFontStyleCreateRef(other)) {}

    LcNwcPlotFontStyle& operator = (const LcNwcPlotFontStyle &other)
    {LiNwcPlotFontStyleDestroy(m_handle); m_handle = LiNwcPlotFontStyleCreateRef(other); return *this;}

    LtNwcPlotFontStyle CreateCopy( LtNwcPlotFontStyle style )
    { return LiNwcPlotFontStyleCreateCopy( style ); }

    operator LtNwcPlotFontStyle () const
    { return static_cast<LtNwcPlotFontStyle>(m_handle); }

    LtNwcPlotFontStyle GetHandle() const
    { return static_cast<LtNwcPlotFontStyle>(m_handle); }

    void SetTypeface( LtWideString typeface )
    { LiNwcPlotFontStyleSetTypeface( m_handle, typeface ); }

    void SetCharacterTraits( LtInt32 traits )
    { LiNwcPlotFontStyleSetCharacterTraits( m_handle, traits ); }

    void SetPointSize( LtInt32 point_size )
    { LiNwcPlotFontStyleSetPointSize( m_handle, point_size ); }

    void SetWeight( LtNwcPlotFontStyleWeight weight )
    { LiNwcPlotFontStyleSetWeight( m_handle, weight ); }

    void SetCharacterSet( LtNwcPlotFontStyleCharacterSet character_set  )
    { LiNwcPlotFontStyleSetCharacterSet( m_handle, character_set ); }

    void SetPitch( LtNwcPlotFontPitch pitch  )
    { LiNwcPlotFontStyleSetPitch( m_handle, pitch ); }

    void SetFamily( LtNwcPlotFontFamily family  )
    { LiNwcPlotFontStyleSetFamily( m_handle, family ); }

    void SetEmbeddedFont( LtNwcPlotEmbeddedFont embedded_font )
    { LiNwcPlotFontStyleSetEmbeddedFont( m_handle, embedded_font ); }
    private:
        LtNwcPlotFontStyle m_handle;
};


#endif /* __cplusplus */

#endif /* LINWCFONTSTYLE_HDR */
