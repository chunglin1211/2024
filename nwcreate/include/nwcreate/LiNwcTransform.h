/**
 * \file
 *
 * An attribute that applies a transformation to a node. Transformations
 * are accumulated down the path to geometry.
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

#ifndef LINWCTRANSFORM_HDR
#define LINWCTRANSFORM_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcAttribute.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a transform with the given translation.
 *
 * \param x X coordinate of translation vector
 * \param y Y coordinate of translation vector
 * \param z Z coordinate of translation vector
 * \return Newly created transform or NULL on error
 */
LI_NWC_PUBLIC LtNwcTransform LI_NWC_API
LiNwcTransformCreateTrans(LtFloat x, LtFloat y, LtFloat z);

/**
 * Create a transform with the given rotation followed by the given
 * translation.
 *
 * \param rX X coordinate of axis to rotate about
 * \param rY Y coordinate of axis to rotate about
 * \param rZ Z coordinate of axis to rotate about
 * \param rA Angle (in radians) to rotate by
 * \param tX X coordinate of translation vector
 * \param tY Y coordinate of translation vector
 * \param tZ Z coordinate of translation vector
 * \return Newly created transform or NULL on error
 */
LI_NWC_PUBLIC LtNwcTransform LI_NWC_API
LiNwcTransformCreateRotTrans(LtFloat rX, LtFloat rY, LtFloat rZ, LtFloat rA,
                             LtFloat tX, LtFloat tY, LtFloat tZ);

/**
 * Set a transform to the given 4x4 matrix.
 *
 * The top left 3x3 sub matrix
 * is the orthogonal rotation matrix, the lower left 1x3 row vector is the
 * translation. The matrix must be affine, so the right most 4x1 column vector
 * must be [ 0 0 0 1 ].
 *
 * \param matrix Matrix as array of 16 floats in row major order
 * \param reverses true if matrix reverses orientation of geometry (e.g. a reflection)
 * \return Newly created transform or NULL on error
 */
LI_NWC_PUBLIC LtNwcTransform LI_NWC_API
LiNwcTransformCreateAffine(LtFloat matrix[16], bool reverses);

/**
 * Destroy a NavisWorks transform.
 *
 * \param transform Transform to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcTransformDestroy(LtNwcTransform transform);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcTransform API calls
 *
 * \see LiNwcTransform.h
 */
class LcNwcTransform : public LcNwcAttribute
{
public:
   LcNwcTransform(LtFloat x, LtFloat y, LtFloat z)
      : LcNwcAttribute(LiNwcTransformCreateTrans(x,y,z), true) {}
   LcNwcTransform(LtFloat rX, LtFloat rY, LtFloat rZ, LtFloat rA,
      LtFloat tX, LtFloat tY, LtFloat tZ)
      : LcNwcAttribute(LiNwcTransformCreateRotTrans(rX,rY,rZ,rA,tX,tY,tZ), true) {}
   LcNwcTransform(LtFloat matrix[16], bool reverses)
      : LcNwcAttribute(LiNwcTransformCreateAffine(matrix,reverses), true) {}
   LcNwcTransform(LtNwcTransform handle) : LcNwcAttribute(handle) {}

   operator LtNwcTransform () const
   { return static_cast<LtNwcTransform>(LcNwcAttribute::GetHandle()); }
   LtNwcTransform GetHandle() const
   { return static_cast<LtNwcTransform>(LcNwcAttribute::GetHandle()); }
};

#endif

#endif /* LINWCTRANSFORM_HDR */
