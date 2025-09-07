/**
 * \file
 *
 * Defines enums used in the NWcreate Plot API.
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

#ifndef LINWCPLOTENUMS_HDR
#define LINWCPLOTENUMS_HDR
#pragma once

typedef enum LtNwcPlotArcSweepDirection__tag
{
    LI_NWC_PLOT_ARC_SWEEP_CLOCKWISE,
    LI_NWC_PLOT_ARC_SWEEP_COUNTERCLOCKWISE,
} LtNwcPlotArcSweepDirection;

typedef enum LtNwcPlotBrushTileMode__tag
{
    LI_NWC_PLOT_BRUSH_TILE_MODE_NONE,
    LI_NWC_PLOT_BRUSH_TILE_MODE_TILE,
    LI_NWC_PLOT_BRUSH_TILE_MODE_FLIP_X,
    LI_NWC_PLOT_BRUSH_TILE_MODE_FLIP_Y,
    LI_NWC_PLOT_BRUSH_TILE_MODE_FLIP_XY,
} LtNwcPlotBrushTileMode;

typedef enum LtNwcPlotGradientBrushMethod__tag
{
  LI_NWC_PLOT_GRADIENT_BRUSH_SPREAD_METHOD_PAD,
  LI_NWC_PLOT_GRADIENT_BRUSH_SPREAD_METHOD_REFLECT,
  LI_NWC_PLOT_GRADIENT_BRUSH_SPREAD_METHOD_REPEAT,
} LtNwcPlotGradientBrushSpreadMethod;

typedef enum LtNwcPlotPaperUnits__tag
{
    LI_NWC_PLOT_PAPER_UNITS_MILLIMETERS,
    LI_NWC_PLOT_PAPER_UNITS_INCHES,
    LI_NWC_PLOT_PAPER_UNITS_UNKNOWN
} LtNwcPlotPaperUnits;

typedef enum LtNwcPlotPolyLineConnectRule__tag
{
   LI_NWC_PLOT_POLYLINE_CONNECT_RULE_LINE_STRIP,
   LI_NWC_PLOT_POLYLINE_CONNECT_RULE_LINE_LIST,
}LtNwcPlotPolyLineConnectRule;

typedef enum LtNwcPlotPathFillRule__tag
{
    LI_NWC_PLOT_PATH_FILL_RULE_EVEN_ODD,
    LI_NWC_PLOT_PATH_FILL_RULE_NON_ZERO,
    LI_NWC_PLOT_PATH_FILL_RULE_NONE,
} LtNwcPlotPathFillRule;

typedef enum LtNwcPlotStrokeCap__tag
{
    LI_NWC_PLOT_STROKE_CAP_BUTT,
    LI_NWC_PLOT_STROKE_CAP_SQUARE,
    LI_NWC_PLOT_STROKE_CAP_ROUND,
    LI_NWC_PLOT_STROKE_CAP_TRIANGLE,
} LtNwcPlotStrokeCap;

typedef enum LtNwcPlotStrokeJoin__tag
{
   LI_NWC_PLOT_STROKE_JOIN_NONE,
   LI_NWC_PLOT_STROKE_JOIN_MITER,
   LI_NWC_PLOT_STROKE_JOIN_BEVEL,
   LI_NWC_PLOT_STROKE_JOIN_ROUND,
   LI_NWC_PLOT_STROKE_JOIN_DIAMOND,
} LtNwcPlotStrokeJoin;

typedef enum LtNwcPlotTextHorizontalAlignment__tag {
    LI_NWC_PLOT_TEXT_LEFT,
    LI_NWC_PLOT_TEXT_CENTER,
    LI_NWC_PLOT_TEXT_RIGHT,
} LtNwcPlotTextHorizontalAlignment;

typedef enum LtNwcPlotTextVerticalAlignment__tag {
    LI_NWC_PLOT_TEXT_BOTTOM,
    LI_NWC_PLOT_TEXT_BASE,
    LI_NWC_PLOT_TEXT_MIDDLE,
    LI_NWC_PLOT_TEXT_CAP,
    LI_NWC_PLOT_TEXT_TOP,
} LtNwcPlotTextVerticalAlignment;

typedef enum LtNwcPlotLinePattern__tag {
    LI_NWC_PLOT_LINE_PATTERN_INVALID = 0,
    LI_NWC_PLOT_LINE_PATTERN_SOLID = 1,
    LI_NWC_PLOT_LINE_PATTERN_DASHED,
    LI_NWC_PLOT_LINE_PATTERN_DOTTED,
    LI_NWC_PLOT_LINE_PATTERN_DASH_DOT,
    LI_NWC_PLOT_LINE_PATTERN_SHORT_DASH,
    LI_NWC_PLOT_LINE_PATTERN_MEDIUM_DASH,
    LI_NWC_PLOT_LINE_PATTERN_LONG_DASH,
    LI_NWC_PLOT_LINE_PATTERN_SHORT_DASH_X2,
    LI_NWC_PLOT_LINE_PATTERN_MEDIUM_DASH_X2,
    LI_NWC_PLOT_LINE_PATTERN_LONG_DASH_X2,
    LI_NWC_PLOT_LINE_PATTERN_MEDIUM_LONG_DASH, // not to be confused with Dashed
    LI_NWC_PLOT_LINE_PATTERN_MEDIUM_DASH_SHORT_DASH_SHORT_DASH,
    LI_NWC_PLOT_LINE_PATTERN_LONG_DASH_SHORT_DASH,
    LI_NWC_PLOT_LINE_PATTERN_LONG_DASH_DOT_DOT,
    LI_NWC_PLOT_LINE_PATTERN_LONG_DASH_DOT,
    LI_NWC_PLOT_LINE_PATTERN_MEDIUM_DASH_DOT_SHORT_DASH_DOT,
    LI_NWC_PLOT_LINE_PATTERN_SPARSE_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DASH,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DASH_SPACE,
    LI_NWC_PLOT_LINE_PATTERN_ISO_LONG_DASH_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_LONG_DASH_DOUBLE_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_LONG_DASH_TRIPLE_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_LONG_DASH_SHORT_DASH,
    LI_NWC_PLOT_LINE_PATTERN_ISO_LONG_DASH_DOUBLE_SHORT_DASH,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DASH_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DOUBLE_DASH_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DASH_DOUBLE_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DOUBLE_DASH_DOUBLE_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DASH_TRIPLE_DOT,
    LI_NWC_PLOT_LINE_PATTERN_ISO_DOUBLE_DASH_TRIPLE_DOT,
    LI_NWC_PLOT_LINE_PATTERN_DECORATED_TRACKS,
    LI_NWC_PLOT_LINE_PATTERN_DECORATED_WIDE_TRACKS,
    LI_NWC_PLOT_LINE_PATTERN_DECORATED_CIRCLE_FENCE,
    LI_NWC_PLOT_LINE_PATTERN_DECORATED_SQUARE_FENCE,
} LtNwcPlotLinePattern;

typedef enum LtNwcPlotFontStyleCharacterTraits__tag {
   LI_NWC_PLOT_FONT_ITALIC                 = 0x01,
   LI_NWC_PLOT_FONT_UNDERLINE              = 0x02,
   LI_NWC_PLOT_FONT_STRIKEOUT              = 0x04,
   LI_NWC_PLOT_FONT_OVERLINE               = 0x08,      // Add this trait according to OGS text system
   LI_NWC_PLOT_FONT_BOLD                   = 0x10,
} LtNwcPlotFontStyleCharacterTraits;

typedef enum LtNwcPlotFontStyleCharacterSet__tag {
   LI_NWC_PLOT_FONT_CHARSET_ANSI           = 0,
   LI_NWC_PLOT_FONT_CHARSET_DEFAULT   = 1,
   LI_NWC_PLOT_FONT_CHARSET_SYMBOL   = 2,
   LI_NWC_PLOT_FONT_CHARSET_MAC            = 77,
   LI_NWC_PLOT_FONT_CHARSET_UNICODE      = 87,
   LI_NWC_PLOT_FONT_CHARSET_SHIFTJIS       = 128,
   LI_NWC_PLOT_FONT_CHARSET_HANGUL         = 129,
   LI_NWC_PLOT_FONT_CHARSET_JOHAB          = 130, /*Korean*/
   LI_NWC_PLOT_FONT_CHARSET_GB2312         = 134,
   LI_NWC_PLOT_FONT_CHARSET_CHINESEBIG5    = 136,
   LI_NWC_PLOT_FONT_CHARSET_GREEK          = 161,
   LI_NWC_PLOT_FONT_CHARSET_TURKISH        = 162,
   LI_NWC_PLOT_FONT_CHARSET_VIETNAMESE     = 163,
   LI_NWC_PLOT_FONT_CHARSET_HEBREW         = 177,
   LI_NWC_PLOT_FONT_CHARSET_ARABIC         = 178,
   LI_NWC_PLOT_FONT_CHARSET_BALTIC         = 186,
   LI_NWC_PLOT_FONT_CHARSET_RUSSIAN        = 204,
   LI_NWC_PLOT_FONT_CHARSET_THAI           = 222,
   LI_NWC_PLOT_FONT_CHARSET_EASTEUROPE     = 238,
   LI_NWC_PLOT_FONT_CHARSET_OEM     = 255,
} LtNwcPlotFontStyleCharacterSet;

typedef enum LtNwcPlotFontStyleWeight__tag {
   LI_NWC_PLOT_FONT_WEIGHT_DEFAULT         = 0,
   LI_NWC_PLOT_FONT_WEIGHT_THIN            = 100,
   LI_NWC_PLOT_FONT_WEIGHT_EXTRALIGHT      = 200,
   LI_NWC_PLOT_FONT_WEIGHT_LIGHT           = 300,
   LI_NWC_PLOT_FONT_WEIGHT_NORMAL          = 400,
   LI_NWC_PLOT_FONT_WEIGHT_MEDIUM          = 500,
   LI_NWC_PLOT_FONT_WEIGHT_SEMIBOLD        = 600,
   LI_NWC_PLOT_FONT_WEIGHT_BOLD            = 700,
   LI_NWC_PLOT_FONT_WEIGHT_EXTRABOLD       = 800,
   LI_NWC_PLOT_FONT_WEIGHT_HEAVY           = 900,
} LtNwcPlotFontStyleWeight;

typedef enum LtNwcPlotFontPitch__tag {
   LI_NWC_PLOT_FONT_PITCH_DEFAULT          = 0,
   LI_NWC_PLOT_FONT_PITCH_FIXED            = 1,
   LI_NWC_PLOT_FONT_PITCH_VARIABLE         = 2,
} LtNwcPlotFontPitch;

typedef enum LtNwcPlotFontFamily__tag {
   LI_NWC_PLOT_FONT_DONTCARE               = 0,
   LI_NWC_PLOT_FONT_ROMAN                  = 0x010,
   LI_NWC_PLOT_FONT_SWISS                  = 0x020,
   LI_NWC_PLOT_FONT_MODERN                 = 0x030,
   LI_NWC_PLOT_FONT_SCRIPT                 = 0x040,
   LI_NWC_PLOT_FONT_DECORATIVE             = 0x050,
} LtNwcPlotFontFamily;

typedef enum LtNwcPlotEmbeddedFontRequest__tag {
   LI_NWC_PLOT_TTEMBED_RAW                      = 0x00000000,
   LI_NWC_PLOT_TTEMBED_SUBSET                   = 0x00000001,
   LI_NWC_PLOT_TTEMBED_TTCOMPRESSED             = 0x00000004,
   LI_NWC_PLOT_TTEMBED_FAILIFVARIATIONSIMULATED = 0x00000010,
   LI_NWC_PLOT_TTEMBED_EMBEDEUDC                = 0x00000020,
   LI_NWC_PLOT_TTEMBED_VALIDATIONTESTS          = 0x00000040,
   LI_NWC_PLOT_TTEMBED_WEBOBJECT                = 0x00000080,
   LI_NWC_PLOT_TTEMBED_ENCRYPTDATA              = 0x10000000
} LtNwcPlotEmbeddedFontRequest;

typedef enum LtNwcPlotEmbeddedFontPrivilege__tag {
   LI_NWC_PLOT_EMBED_PREVIEWPRINT               = 1,
   LI_NWC_PLOT_EMBED_EDITABLE                   = 2,
   LI_NWC_PLOT_EMBED_INSTALLABLE                = 3,
   LI_NWC_PLOT_EMBED_NOEMBEDDING                = 4
} LtNwcPlotEmbeddedFontPrivilege;

typedef enum LtNwcPlotEmbeddedFontCharacterCode__tag {
   LI_NWC_PLOT_CHARSET_UNICODE                  = 1,
   LI_NWC_PLOT_CHARSET_SYMBOL                   = 2,
   LI_NWC_PLOT_CHARSET_GLYPHIDX                 = 3,

   LI_NWC_PLOT_CHARSET_DEFAULT                  = LI_NWC_PLOT_CHARSET_UNICODE
} LtNwcPlotEmbeddedFontCharacterCode;

#endif /* LINWCPLOTENUMS_HDR */
