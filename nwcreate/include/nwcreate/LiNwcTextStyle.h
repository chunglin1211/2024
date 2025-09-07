/**
 * \file
 *
 * Defines a font style for 2D text including typeface, font size
 * and other properties.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2001
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCTEXTSTYLE_HDR
#define LINWCTEXTSTYLE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a text style.
 *
 * \return Newly created style or NULL on error
 * \version 6.0
 */
LI_NWC_PUBLIC LtNwcTextStyle LI_NWC_API
LiNwcTextStyleCreate(LtWideString typeface);

/**
 * Create a reference to a text style.
 *
 * \param style Style to create reference to
 * \return Referenced style or NULL on error
 * \version 6.0
 */
LI_NWC_PUBLIC LtNwcTextStyle LI_NWC_API
LiNwcTextStyleCreateRef(LtNwcTextStyle style);

/**
 * Sets the typeface for a text style.
 *
 * \param style Text style
 * \param typeface Name of typeface. Must be a TrueType font name.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextStyleSetTypeface(LtNwcTextStyle style,
                          LtWideString typeface);

/**
 * Sets the height of the text.
 *
 * \param style Text style
 * \param height Height of font in world units.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextStyleSetFontHeight(LtNwcTextStyle style,
                            LtFloat height);

/**
 * Sets the point size of the text. Note that this value
 * has no effect on the rendered size of the text. It just
 * determines which font is used.
 *
 * The default value for this is 50pt.
 *
 * \param style Text style
 * \param point_size Size of font in points.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextStyleSetPointSize(LtNwcTextStyle style,
                           LtInt32 point_size);

/**
 * Text render style.
 */
typedef enum LtNwcTextRenderStyle__tag {
   LI_NWC_TEXT_RENDER_FILLED,  /** Filled */
   LI_NWC_TEXT_RENDER_OUTLINE, /** Outlined */
} LtNwcTextRenderStyle;

/**
 * Sets the render style of the text, either outline or filled.
 *
 * The default value is filled.
 *
 * \param style Text style
 * \param render_style Render style for text
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextStyleSetRenderStyle(LtNwcTextStyle style,
                             LtNwcTextRenderStyle render_style);

/**
 * Text font style flags.
 */
typedef enum LtNwcTextFontStyle__tag {
   LI_NWC_TEXT_FONT_ITALIC      = 0x01, /** Italic */
   LI_NWC_TEXT_FONT_UNDERLINE   = 0x02, /** Underline */
   LI_NWC_TEXT_FONT_STRIKEOUT   = 0x04, /** Strike-out */
} LtNwcTextFontStyle;

/**
 * Sets the font style of the text.
 *
 * The default value is normal.
 *
 * \param style Text style
 * \param font_style Bitfield of styles from LtNwcTextFontStyle
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextStyleSetFontStyle(LtNwcTextStyle style,
                           LtInt32 font_style);

/**
 * Font weights.
 */
typedef enum LtNwcTextFontWeight__tag {
   LI_NWC_TEXT_FONT_WEIGHT_DEFAULT = 0,   /** Default */
   LI_NWC_TEXT_FONT_WEIGHT_NORMAL  = 400, /** Normal */
   LI_NWC_TEXT_FONT_WEIGHT_BOLD    = 700, /** Bold */
} LtNwcTextFontWeight;

/**
 * Sets the fot weight of the text style.
 *
 * \param style Text style
 * \param font_weight Weight of font. A value between 0 and 900.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextStyleSetFontWeight(LtNwcTextStyle style,
                            LtInt32 font_weight);

/**
 * Destroy a text style
 *
 * \param style Style to destroy
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTextStyleDestroy(LtNwcTextStyle style);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcTextStyle API calls
 *
 * \see LiNwcTextStyle.h
 */
class LcNwcTextStyle
{
public:
   LcNwcTextStyle(LtWideString typeface) : m_handle(LiNwcTextStyleCreate(typeface)) {}
   LcNwcTextStyle(LtNwcTextStyle handle) : m_handle(LiNwcTextStyleCreateRef(handle)) {}

   ~LcNwcTextStyle() { LiNwcTextStyleDestroy(m_handle); }

   LcNwcTextStyle(const LcNwcTextStyle& other) : m_handle(LiNwcTextStyleCreateRef(other)) {}

   LcNwcTextStyle& operator = (const LcNwcTextStyle &other)
   { LiNwcTextStyleDestroy(m_handle); m_handle = LiNwcTextStyleCreateRef(other); return *this; }

   LcNwcTextStyle& operator = (LtNwcTextStyle handle)
   { LiNwcTextStyleDestroy(m_handle); m_handle = LiNwcTextStyleCreateRef(handle); return *this; }

   operator LtNwcTextStyle () const { return m_handle; }
   LtNwcTextStyle GetHandle() const { return m_handle; }

   void SetTypeface(LtWideString typeface)
   { LiNwcTextStyleSetTypeface(GetHandle(), typeface); }

   void SetFontHeight(LtFloat height)
   { LiNwcTextStyleSetFontHeight(GetHandle(), height); }

   void SetPointSize(LtInt32 point_size)
   { LiNwcTextStyleSetPointSize(GetHandle(), point_size); }

   void SetRenderStyle(LtNwcTextRenderStyle render_style)
   { LiNwcTextStyleSetRenderStyle(GetHandle(), render_style); }

   void SetFontStyle(LtInt32 font_style)
   { LiNwcTextStyleSetFontStyle(GetHandle(), font_style); }

   void SetFontWeight(LtInt32 font_weight)
   { LiNwcTextStyleSetFontWeight(GetHandle(), font_weight); }

private:

   LtNwcTextStyle m_handle;
};

#endif

#endif /* LINWCTEXTSTYLE_HDR */
