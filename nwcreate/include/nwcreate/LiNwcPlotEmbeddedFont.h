/**
 * \file
 *
 * Defines stylization details for use with EmbeddedFont objects.
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

#ifndef LINWCPLOTEMBEDDEDFONT_HDR
#define LINWCPLOTEMBEDDEDFONT_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 *  Create an embedded font
 *
 *  \return Newly created font or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotEmbeddedFont LI_NWC_API
LiNwcPlotEmbeddedFontCreate( void );

/**
 *  Create a reference to an embedded font
 *
 *  \param font  to which a reference is created
 *  \return Referenced font or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotEmbeddedFont LI_NWC_API
LiNwcPlotEmbeddedFontCreateRef( LtNwcPlotEmbeddedFont font );

/**
 *  Create a copy to an embedded font
 *
 *  \param font  for which a copy is created
 *  \return Copied font or NULL on error
 *  \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotEmbeddedFont LI_NWC_API
LiNwcPlotEmbeddedFontCreateCopy( LtNwcPlotEmbeddedFont font );

/**
 *  Destroy an embedded font
 *
 *  \param font  to destroy
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontDestroy( LtNwcPlotEmbeddedFont font );

/**
 *  Sets the embedded font technology type
 *
 *  Use "T2Embed" for AGFA t2embed font subset
 *      "OpenType" for XPS-font OpenType font subset
 *      "ObfuscatedOpenType" for XPS-font obfuscated OpenType font subset
 *
 *  \param font The font
 *  \param type The embedded font type
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetType( LtNwcPlotEmbeddedFont font, LtString type );

/**
 *  Sets a pointer to the buffer containing the embedded font binary image
 *
 *  \param font The font
 *  \param buffer The buffer containing the embedded font binary image
 *  \param size The size (in bytes) of the embedded font binary image
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetBuffer( LtNwcPlotEmbeddedFont font, LtNat8* buffer, LtInt32 size );

/**
 *  Sets the full descriptive font name.
 *
 *  \param font the font
 *  \param canoncial_name the full descriptive font name.
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetCanoncialName( LtNwcPlotEmbeddedFont font, LtWideString canoncial_name );

/**
 *  Sets shorter logfont name. (32 byte character length restriction applies)
 *
 *  \param font the font
 *  \param log_font_name the shorter logfont name
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetLogFontName( LtNwcPlotEmbeddedFont font, LtWideString log_font_name );

/**
 *  Sets the character set of the embedded font
 *
 *  This flag can have one of the following values:
 *  LI_NWC_PLOT_CHARSET_UNICODE - A Unicode character set, requiring 16-bit character encoding.
 *  LI_NWC_PLOT_CHARSET_SYMBOL - A symbol character set, requiring 16-bit character encoding.
 *  LI_NWC_PLOT_CHARSET_GLYPHIDX - Indicates that subset values passed are to be interpreted as glyph id's (rather than unicode values).
 *  LI_NWC_PLOT_CHARSET_DEFAULT - Equal to LI_NWC_PLOT_CHARSET_UNICODE, which is used in default.
 *
 *  See the LtNwcPlotEmbeddedFontCharacterCode enumeration for character code value definition.
 *
 *  \param font the font
 * \param character_code A flag specifying the character set of the font to be embedded
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetCharacterSetType( LtNwcPlotEmbeddedFont font, LtNwcPlotEmbeddedFontCharacterCode character_code );

/**
 *  Sets the embedding privilege of the font
 *
 *  This flag can have one of the following values:
 *  LI_NWC_PLOT_EMBED_PREVIEWPRINT - Preview and Print Embedding.
 *  LI_NWC_PLOT_EMBED_EDITABLE - Editable Embedding.
 *  LI_NWC_PLOT_EMBED_INSTALLABLE - Installable Embedding.
 *  LI_NWC_PLOT_EMBED_NOEMBEDDING - Restricted License Embedding
 *
 *  See the LtNwcPlotEmbeddedFontPrivilege enumeration for privilege value definition.
 *
 *  \param font the font
 *  \param privilege A flag indicating the embedding privileges of the font
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetPrivilege( LtNwcPlotEmbeddedFont font, LtNwcPlotEmbeddedFontPrivilege privilege );

/**
 *  Sets the request type by which the font information was embedded
 *
 *  This field could be one or more of the following Request values by which font information would
 *  have been embedded by Microsoft's Open Type Font Embedding SDK:
 *
 *  LI_NWC_PLOT_TTEMBED_RAW - Returns a font structure containing the full character set, non-compressed. This is
                     the default behavior of the function.
 *  LI_NWC_PLOT_TTEMBED_SUBSET - Returns a subsetted font containing only the glyphs indicated by pusCharCodeSet.
                        These character codes must be denoted as 16-bit Unicode values.
 *  LI_NWC_PLOT_TTEMBED_TTCOMPRESSED - Returns a compressed font structure.
 *  LI_NWC_PLOT_TTEMBED_FAILIFVARIATIONSIMULATED - In some cases, a client will want to avoid embedding simulated fonts,
                                          especially if the normal instance of the typeface is being embedded.
                                          If this flag is set and the font in the DC is simulated, TTEmbedFont( )
                                          will fail, generating an error.
 *  LI_NWC_PLOT_TTEMBED_EMBEDEUDC - Embed EUDC font. If there is typeface EUDC embed it; otherwise, embed system EUDC.
 *  LI_NWC_PLOT_TTEMBED_VALIDATIONTESTS - Confirms validity of the font file before embedding.
 *  LI_NWC_PLOT_TTEMBED_WEBOBJECT - Clients embedding fonts for the web must use this flag to create valid web objects.
                           Clients embedding fonts in their own document files do not use this flag.
 *  LI_NWC_PLOT_TTEMBED_ENCRYPTDATA - Causes font data in the embedded object to be additionally encrypted when compression is being performed.
 *
 *  See the LtNwcPlotEmbeddedFontRequest enumeration for bit definitions.
 *
 *  \param font the font
 *  \param request_type an unsigned-integer value denoting the request by which the font information was embedded (bitfield)
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetRequestType( LtNwcPlotEmbeddedFont font, LtNat32 request_type );

/**
 *  Set identifier for an embedded fonts, if font type is ObfuscatedOpenType
 *
 *  \param font the font
 *  \param identifier a 128-bit GUID with that the font is obfuscated
 *  \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotEmbeddedFontSetIdentifier( LtNwcPlotEmbeddedFont font, LtWideString identifier );

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcPlotEmbeddedFont API calls
 *
 * \see LiNwcPlotEmbeddedFont.h
 */
class LcNwcPlotEmbeddedFont
{
public:
    LcNwcPlotEmbeddedFont( void ) : m_handle( LiNwcPlotEmbeddedFontCreate() ) {}
    ~LcNwcPlotEmbeddedFont (void ) { LiNwcPlotEmbeddedFontDestroy( m_handle ); }

    LcNwcPlotEmbeddedFont(const LcNwcPlotEmbeddedFont &other) : m_handle(LiNwcPlotEmbeddedFontCreateRef(other)) {}

    LcNwcPlotEmbeddedFont& operator = (const LcNwcPlotEmbeddedFont &other)
    {LiNwcPlotEmbeddedFontDestroy(m_handle); m_handle = LiNwcPlotEmbeddedFontCreateRef(other); return *this;}

    LtNwcPlotEmbeddedFont CreateCopy( LtNwcPlotEmbeddedFont font )
    { return LiNwcPlotEmbeddedFontCreateCopy( font ); }

    operator LtNwcPlotEmbeddedFont () const
    { return static_cast<LtNwcPlotEmbeddedFont>(m_handle); }

    LtNwcPlotEmbeddedFont GetHandle() const
    { return static_cast<LtNwcPlotEmbeddedFont>(m_handle); }

    void SetType( LtString type )
    { LiNwcPlotEmbeddedFontSetType( m_handle, type ); }

    void SetBuffer( const LtNat8* buffer, LtInt32 size )
    { LiNwcPlotEmbeddedFontSetBuffer( m_handle, const_cast<LtNat8*>(buffer), size ); }

    void SetRequestType(LtNat32 request_type)
    { LiNwcPlotEmbeddedFontSetRequestType(m_handle, request_type); }

    void SetPrivilege(LtNwcPlotEmbeddedFontPrivilege privilege)
    { LiNwcPlotEmbeddedFontSetPrivilege(m_handle, privilege); }

    void SetCharacterSetType(LtNwcPlotEmbeddedFontCharacterCode type)
    { LiNwcPlotEmbeddedFontSetCharacterSetType(m_handle, type); }

    void SetCanoncialName(LtWideString name)
    { LiNwcPlotEmbeddedFontSetCanoncialName(m_handle, name); }

    void SetLogFontName(LtWideString name)
    { LiNwcPlotEmbeddedFontSetLogFontName(m_handle, name); }

    void SetIdentifier(LtWideString identifier)
    { LiNwcPlotEmbeddedFontSetIdentifier(m_handle, identifier); }

    private:
        LtNwcPlotEmbeddedFont m_handle;
};

#endif /* __cplusplus */

#endif /* LINWCPLOTEMBEDDEDFONT_HDR */
