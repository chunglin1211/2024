/**
 * \file
 *
 * A structure describing an image. The image format is compatible with windows DIB
 * with the following restrictions:
 *
 * No compression.
 * No color tables.
 * 8 bits per channel only.
 * The channel values should be contiguous in memory with scanline padding to a 4-byte alignment.
 * Bitmap should be bottom-up, origin lower-left corner, arranged in scanline-major order.
 * Alpha channels are assumed to operate such that 0 is transparent, 255 is opaque.
 * See the format enumeration for byte orderings.
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

#ifndef LINWCIMAGEHEADER_HDR
#define LINWCIMAGEHEADER_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Image format enumeration.
 * \version 4.1
 */
typedef enum LtNwcImageHeaderFormat__tag {
   LI_NWC_IMAGE_HEADER_GREY,     // Greyscale - 1 byte per pixel.
   LI_NWC_IMAGE_HEADER_ALPHA,    // Alpha - 1 byte per pixel.
   LI_NWC_IMAGE_HEADER_GA,       // Greyscale & alpha - 2 bytes per pixel.
   LI_NWC_IMAGE_HEADER_BGR,      // BGR format - 3 bytes per pixel.
   LI_NWC_IMAGE_HEADER_BGRA,     // BGRA format - 4 bytes per pixel.
} LtNwcImageHeaderFormat;

/**
 * Create an image header.
 *
 * \return Newly created image header or NULL on error.
 * \version 4.1
 */
LI_NWC_PUBLIC LtNwcImageHeader LI_NWC_API
LiNwcImageHeaderCreate();

/**
 * Create a copy of an image header.
 *
 * \param image_header image header to copy.
 * \return copied image header or NULL on error.
 * \version 4.1
 */
LI_NWC_PUBLIC LtNwcImageHeader LI_NWC_API
LiNwcImageHeaderCreateCopy(LtNwcImageHeader image_header);

/**
 * Create an image header from image file directly.
 *
 * \param image_file The local filename containing the image.
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcImageHeader LI_NWC_API
LiNwcImageHeaderCreateFromImage(LtWideString image_file);

/**
 * Set the width of the image in pixels.
 *
 * \param image_header Image header for which to set width.
 * \param width Width of the image in pixels.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcImageHeaderSetWidth(LtNwcImageHeader image_header, LtNat32 width);

/**
 * Set the height of the image in pixels.
 *
 * \param image_header Image header for which to set height.
 * \param height Height of the image in pixels.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcImageHeaderSetHeight(LtNwcImageHeader image_header, LtNat32 height);

/**
 * Set the format of the image.
 *
 * \param image_header Image header for which to set format.
 * \param format Format of image.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcImageHeaderSetFormat(LtNwcImageHeader image_header, LtNwcImageHeaderFormat format);

/**
 * Get the width of the image in pixels.
 *
 * \param image_header Image header for which to get width.
 * \version 4.1
 */
LI_NWC_PUBLIC LtNat32 LI_NWC_API
LiNwcImageHeaderGetWidth(LtNwcImageHeader image_header);

/**
 * Get the height of the image in pixels.
 *
 * \param image_header Image header for which to get height.
 * \version 4.1
 */
LI_NWC_PUBLIC LtNat32 LI_NWC_API
LiNwcImageHeaderGetHeight(LtNwcImageHeader image_header);

/**
 * Get the format of the image.
 *
 * \param image_header Image header for which to get format.
 * \version 4.1
 */
LI_NWC_PUBLIC LtNwcImageHeaderFormat LI_NWC_API
LiNwcImageHeaderGetFormat(LtNwcImageHeader image_header);

/**
 * Returns the expected buffer size in bytes for a suitable image header. This can be
 * used to confirm that the buffer you pass into functions like LiNwcApiCreateMap is the correct size.
 *
 * \param image_header Image header for which to retrieve buffer size.
 * \version 4.1
 */
LI_NWC_PUBLIC LtNat32 LI_NWC_API
LiNwcImageHeaderGetExpectedBufferSize(LtNwcImageHeader image_header);

/**
 * Destroy an image header.
 *
 * \param image_header Image header to destroy.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcImageHeaderDestroy(LtNwcImageHeader image_header);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcImageHeader API calls
 *
 * \see LiNwcImageHeader.h
 */
class LcNwcImageHeader
{
public:
   LcNwcImageHeader() : m_handle(LiNwcImageHeaderCreate()), m_own(true) {}
   LcNwcImageHeader(LtNwcImageHeader handle) : m_handle(handle), m_own(false) {}
   ~LcNwcImageHeader() {if(m_own) LiNwcImageHeaderDestroy(m_handle);}

   LcNwcImageHeader(const LcNwcImageHeader &other) : m_handle(LiNwcImageHeaderCreateCopy(other)), m_own(true) {}

   LcNwcImageHeader& operator = (const LcNwcImageHeader &other)
   { if(m_own) LiNwcImageHeaderDestroy(m_handle); m_handle = LiNwcImageHeaderCreateCopy(other); m_own = true; return *this; }

   operator LtNwcImageHeader () const { return m_handle; }
   LtNwcImageHeader GetHandle() const { return m_handle; }

   void CreateFromImage(LtWideString image_file)
   { if(m_own) LiNwcImageHeaderDestroy(m_handle); m_handle = LiNwcImageHeaderCreateFromImage(image_file); m_own = true; }

   void SetWidth(LtNat32 width)
   { LiNwcImageHeaderSetWidth(m_handle, width); }

   void SetHeight(LtNat32 height)
   { LiNwcImageHeaderSetHeight(m_handle, height); }

   void SetFormat(LtNwcImageHeaderFormat format)
   { LiNwcImageHeaderSetFormat(m_handle, format); }

   LtNat32 GetWidth()
   { return LiNwcImageHeaderGetWidth(m_handle); }

   LtNat32 GetHeight()
   { return LiNwcImageHeaderGetHeight(m_handle); }

   LtNat32 GetFormat()
   { return LiNwcImageHeaderGetFormat(m_handle); }

   LtNat32 GetExpectedBufferSize()
   { return LiNwcImageHeaderGetExpectedBufferSize(m_handle); }

private:

   LtNwcImageHeader m_handle;
   bool m_own;
};

#endif

#endif /* LINWCIMAGEHEADER_HDR */
