/**
 * \file
 *
 * Base type for plot brushes.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2011 Autodesk, Inc. All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 *
 */

#ifndef LINWCPLOTBRUSH_HDR
#define LINWCPLOTBRUSH_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a reference a plot brush of any type.
 *
 * \param brush brush to reference.
 * \return referenced brush.
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcPlotBrush LI_NWC_API
LiNwcPlotBrushCreateRef(LtNwcPlotBrush brush);

/**
 * Destroys a plot brush.
 *
 * \param brush brush to destroy.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotBrushDestroy(LtNwcPlotBrush brush);

#ifdef __cplusplus
}


/**
 * C++ wrapper around LtNwcPlotBrush API calls
 *
 * \see LiNwcPlotBrush.h
 */
class LcNwcPlotBrush
{
public:
   LcNwcPlotBrush(LtNwcPlotBrush handle) : m_handle(LiNwcPlotBrushCreateRef(handle)) {}
   ~LcNwcPlotBrush() { LiNwcPlotBrushDestroy(m_handle); }

   LcNwcPlotBrush(const LcNwcPlotBrush &other) : m_handle(LiNwcPlotBrushCreateRef(other)) {}

   LcNwcPlotBrush& operator = (const LcNwcPlotBrush &other)
   { LiNwcPlotBrushDestroy(m_handle); m_handle = LiNwcPlotBrushCreateRef(other); return *this; }

   operator LtNwcPlotBrush () const { return m_handle; }
   LtNwcPlotBrush GetHandle() const { return m_handle; }

protected:
   LcNwcPlotBrush(LtNwcPlotBrush handle, bool /*own*/)
      : m_handle(handle) {}

private:

   LtNwcPlotBrush m_handle;
};

#endif

#endif /* LINWCPLOTBRUSH_HDR */
