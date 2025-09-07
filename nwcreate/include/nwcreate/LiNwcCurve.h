/**
 * \file
 *
 * Definitions of 3D curves.
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

#ifndef LINWCCURVE_HDR
#define LINWCCURVE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////
// 3D Curve
//////////////////////////////////////////////////

/**
 * Reverses a curve
 *
 * \param curve 3D curve to reverse
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurveReverse(LtNwcCurve curve);

/**
 * Destroy a 3D curve of any type
 *
 * \param curve 3D curve to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurveDestroy(LtNwcCurve curve);

/**
 * Sets the user data field on the curve.
 *
 * \param curve curve to set data field on.
 * \param data data to attach
 * \version 5.4
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurveSetUserData(LtNwcCurve curve,
                      LtInt32 data);

/**
 * Evaluate a curve at a given point.
 *
 * \param curve curve to evaluate
 * \param t parameter
 * \param pnt return curve point at parameter t
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurveEvaluate(LtNwcCurve curve,
                   LtFloat t,
                   LtPoint pnt);

/**
 * Creates a copy of a curve.
 *
 * \param curve curve to copy
 * \return copy of curve
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcCurve LI_NWC_API
LiNwcCurveCreateCopy(LtNwcCurve curve);

/**
 * Creates a reference to a curve.
 *
 * \param curve curve to reference
 * \return reference to curve
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcCurve LI_NWC_API
LiNwcCurveCreateRef(LtNwcCurve curve);

/**
 * Transforms a curve.
 *
 * \param curve curve to transform
 * \param transform transformation to apply to curve
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurveTransform(LtNwcCurve curve,
                    LtNwcTransform transform);

/**
 * Translates a curve.
 *
 * \param curve curve to translate
 * \param x x component of translation
 * \param y y component of translation
 * \param z z component of translation
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurveTranslate(LtNwcCurve curve,
                    LtFloat x,
                    LtFloat y,
                    LtFloat z);

/**
 * Returns the first parameter of a curve.
 * You can optionally pass in a parameter to determine
 * if the parameter is infinite.
 * If the first parameter is -infinity, the return value
 * will be LI_NWC_NEGATIVE_INFINITY.
 *
 * \param curve curve to query
 * \param is_infinite optional infinite flag
 * \return first parameter curve can be evaulated at
 * \version 5.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcCurveGetFirstParameter(LtNwcCurve curve,
                            bool *is_infinite);

/**
 * Returns the last parameter of a curve.
 * You can optionally pass in a parameter to determine
 * if the parameter is infinite.
 * If the first parameter is +infinity, the return value
 * will be LI_NWC_POSITIVE_INFINITY.
 *
 * \param curve curve to query
 * \param is_infinite optional infinite flag
 * \return last parameter curve can be evaulated at
 * \version 5.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcCurveGetLastParameter(LtNwcCurve curve,
                           bool *is_infinite);

//////////////////////////////////////////////////
// 3D Line
//////////////////////////////////////////////////

/**
 * Create a 3D line
 *
 * \param pnt a point on the line
 * \param dir direction of the line
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcLine LI_NWC_API
LiNwcLineCreate(LtPoint pnt,
                LtVector dir);

/**
 * Create a 3D line
 *
 * \param pnt0 first point on the line
 * \param pnt1 second point on the line
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcLine LI_NWC_API
LiNwcLineCreateEx(LtPoint pnt0,
                  LtPoint pnt1);

//////////////////////////////////////////////////
// 3D Circle
//////////////////////////////////////////////////

/**
 * Create a 3D circle
 *
 * \param pnt a point on the line
 * \param xaxis direction of the x axis
 * \param yaxis direction of the y axis
 * \param radius radius of circle
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcCircle LI_NWC_API
LiNwcCircleCreate(LtPoint pnt,
                  LtVector xaxis,
                  LtVector yaxis,
                  LtFloat radius);

//////////////////////////////////////////////////
// 3D Ellipse
//////////////////////////////////////////////////

/**
 * Create a 3D ellipse
 *
 * \param pnt centre point of ellipse
 * \param xaxis x direction of ellipse
 * \param yaxis y direction of ellipse
 * \param major_radius major radius of ellipse
 * \param minor_radius minor radius of ellipse
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcEllipse LI_NWC_API
LiNwcEllipseCreate(LtPoint pnt,
                   LtVector xaxis,
                   LtVector yaxis,
                   LtFloat major_radius,
                   LtFloat minor_radius);

//////////////////////////////////////////////////
// 3D Parabola
//////////////////////////////////////////////////

/**
 * Create a 3D parabola
 *
 * \param pnt apex of parabola
 * \param xaxis x direction of parabola
 * \param yaxis y direction of parabola
 * \param focal_length focal length of parabola
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcParabola LI_NWC_API
LiNwcParabolaCreate(LtPoint pnt,
                    LtVector xaxis,
                    LtVector yaxis,
                    LtFloat focal_length);

//////////////////////////////////////////////////
// 3D Hyperbola
//////////////////////////////////////////////////

/**
 * Create a 3D hyperbola
 *
 * \param pnt apex of hyperbola
 * \param xaxis x direction of hyperbola
 * \param yaxis y direction of hyperbola
 * \param major_radius major radius of hyperbola
 * \param minor_radius minor radius of hyperbola
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcHyperbola LI_NWC_API
LiNwcHyperbolaCreate(LtPoint pnt,
                     LtVector xaxis,
                     LtVector yaxis,
                     LtFloat major_radius,
                     LtFloat minor_radius);

//////////////////////////////////////////////////
// 3D Bezier Curve
//////////////////////////////////////////////////

/**
 * Create a 3D Bezier curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 3D poles
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBezierCurve LI_NWC_API
LiNwcBezierCurveCreate(LtInt32 num_poles,
                       LtPoint *poles);

/**
 * Create a rational 3D Bezier curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 3D poles
 * \param weights array of weights
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBezierCurve LI_NWC_API
LiNwcBezierCurveCreateRational(LtInt32 num_poles,
                               LtPoint *poles,
                               LtFloat *weights);

//////////////////////////////////////////////////
// 3D B-Spline Curve
//////////////////////////////////////////////////

/**
 * Create a 3D B-Spline curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 3D poles
 * \param num_knots number of knots in curve
 * \param knots array of knots
 * \param mults array of knot multiplicities
 * \param degree degree of curve
 * \param periodic is curve periodic
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBSplineCurve LI_NWC_API
LiNwcBSplineCurveCreate(LtInt32 num_poles,
                        LtPoint *poles,
                        LtInt32 num_knots,
                        LtFloat *knots,
                        LtInt32 *mults,
                        LtInt32 degree,
                        bool periodic);

/**
 * Create a rational 3D B-Spline curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 3D poles
 * \param weights array of weights
 * \param num_knots number of knots in curve
 * \param knots array of knots
 * \param mults array of knot multiplicities
 * \param degree degree of curve
 * \param periodic is curve periodic
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBSplineCurve LI_NWC_API
LiNwcBSplineCurveCreateRational(LtInt32 num_poles,
                                LtPoint *poles,
                                LtFloat *weights,
                                LtInt32 num_knots,
                                LtFloat *knots,
                                LtInt32 *mults,
                                LtInt32 degree,
                                bool periodic);

//////////////////////////////////////////////////
// 3D Trimmed Curve
//////////////////////////////////////////////////

/**
 * Create a 3D trimmed curve
 *
 * \param basis_curve curve to trim
 * \param param0 first parameter of trimmed curve
 * \param param1 second parameter of trimmed curve
 * \param sense is the sense of the trimmed curve reversed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcTrimmedCurve LI_NWC_API
LiNwcTrimmedCurveCreate(LtNwcCurve basis_curve,
                        LtFloat param0,
                        LtFloat param1,
                        bool sense);

/**
 * Create a 3D trimmed curve
 *
 * \param basis_curve curve to trim
 * \param pnt0 starting point of trimmed curve
 * \param pnt1 ending point of trimmed curve
 * \param sense is the sense of the trimmed curve reversed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcTrimmedCurve LI_NWC_API
LiNwcTrimmedCurveCreateEx(LtNwcCurve basis_curve,
                          LtPoint pnt0,
                          LtPoint pnt1,
                          bool sense);

#ifdef __cplusplus
}

//////////////////////////////////////////////////
// 3D Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcCurve API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcCurve
{
public:
   LcNwcCurve(LtNwcCurve handle) : m_handle(LiNwcCurveCreateRef(handle)) {}

   ~LcNwcCurve() { LiNwcCurveDestroy(m_handle); }

   LcNwcCurve(const LcNwcCurve &other) : m_handle(LiNwcCurveCreateRef(other)) {}
   LcNwcCurve& operator = (const LcNwcCurve &other)
   { LiNwcCurveDestroy(m_handle); m_handle = LiNwcCurveCreateRef(other); return *this; }

   operator LtNwcCurve () const { return m_handle; }
   LtNwcCurve GetHandle() const { return m_handle; }

   LcNwcCurve Copy()
   { return LcNwcCurve(LiNwcCurveCreateCopy(m_handle), true); }

   void SetUserData(LtInt32 data)
   { LiNwcCurveSetUserData(m_handle, data); }

   void Evaluate(LtFloat t,
                 LtPoint pnt)
   { LiNwcCurveEvaluate(m_handle, t, pnt); }

   void Reverse()
   { LiNwcCurveReverse(m_handle); }

   void Transform(LtNwcTransform transform)
   { LiNwcCurveTransform(m_handle, transform); }

   void Translate(LtFloat x,
                  LtFloat y,
                  LtFloat z)
   { LiNwcCurveTranslate(m_handle, x, y, z); }

   void Translate(LtVector v)
   { LiNwcCurveTranslate(m_handle, v[0], v[1], v[2]); }

   LtFloat GetFirstParameter(bool *is_infinite = NULL)
   { return LiNwcCurveGetFirstParameter(m_handle, is_infinite); }

   LtFloat GetLastParameter(bool *is_infinite = NULL)
   { return LiNwcCurveGetLastParameter(m_handle, is_infinite); }

protected:
   LcNwcCurve(LtNwcCurve handle, bool /*own*/)
      : m_handle(handle) {}

private:

   LtNwcCurve m_handle;
};

//////////////////////////////////////////////////
// 3D Line
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcLine API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcLine : public LcNwcCurve
{
public:
   LcNwcLine(LtPoint pnt,
             LtVector dir)
      : LcNwcCurve(LiNwcLineCreate(pnt,
                                   dir), true) {}

   LcNwcLine(LtNwcLine handle)
      : LcNwcCurve(handle) {}

   operator LtNwcLine () const
   { return static_cast<LtNwcLine>(LcNwcCurve::GetHandle()); }
   LtNwcLine GetHandle() const
   { return static_cast<LtNwcLine>(LcNwcCurve::GetHandle()); }
};

//////////////////////////////////////////////////
// 3D Circle
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcCircle API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcCircle : public LcNwcCurve
{
public:
   LcNwcCircle(LtPoint pnt,
               LtVector xaxis,
               LtVector yaxis,
               LtFloat radius)
      : LcNwcCurve(LiNwcCircleCreate(pnt,
                                     xaxis,
                                     yaxis,
                                     radius), true) {}

   LcNwcCircle(LtNwcCircle handle)
      : LcNwcCurve(handle) {}

   operator LtNwcCircle () const
   { return static_cast<LtNwcCircle>(LcNwcCurve::GetHandle()); }
   LtNwcCircle GetHandle() const
   { return static_cast<LtNwcCircle>(LcNwcCurve::GetHandle()); }
};

//////////////////////////////////////////////////
// 3D Ellipse
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcEllipse API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcEllipse : public LcNwcCurve
{
public:
   LcNwcEllipse(LtPoint pnt,
                LtVector xaxis,
                LtVector yaxis,
                LtFloat major_radius,
                LtFloat minor_radius)
      : LcNwcCurve(LiNwcEllipseCreate(pnt,
                                      xaxis,
                                      yaxis,
                                      major_radius,
                                      minor_radius), true) {}

   LcNwcEllipse(LtNwcEllipse handle)
      : LcNwcCurve(handle) {}

   operator LtNwcEllipse () const
   { return static_cast<LtNwcEllipse>(LcNwcCurve::GetHandle()); }
   LtNwcEllipse GetHandle() const
   { return static_cast<LtNwcEllipse>(LcNwcCurve::GetHandle()); }
};

//////////////////////////////////////////////////
// 3D Parabola
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcParabola API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcParabola : public LcNwcCurve
{
public:
   LcNwcParabola(LtPoint pnt,
                 LtVector xaxis,
                 LtVector yaxis,
                 LtFloat focal_length)
      : LcNwcCurve(LiNwcParabolaCreate(pnt,
                                       xaxis,
                                       yaxis,
                                       focal_length), true) {}

   LcNwcParabola(LtNwcParabola handle)
      : LcNwcCurve(handle) {}

   operator LtNwcParabola () const
   { return static_cast<LtNwcParabola>(LcNwcCurve::GetHandle()); }
   LtNwcParabola GetHandle() const
   { return static_cast<LtNwcParabola>(LcNwcCurve::GetHandle()); }
};

//////////////////////////////////////////////////
// 3D Hyperbola
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcHyperbola API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcHyperbola : public LcNwcCurve
{
public:
   LcNwcHyperbola(LtPoint pnt,
                  LtVector xaxis,
                  LtVector yaxis,
                  LtFloat major_radius,
                  LtFloat minor_radius)
      : LcNwcCurve(LiNwcHyperbolaCreate(pnt,
                                        xaxis,
                                        yaxis,
                                        major_radius,
                                        minor_radius), true) {}

   LcNwcHyperbola(LtNwcHyperbola handle)
      : LcNwcCurve(handle) {}

   operator LtNwcHyperbola () const
   { return static_cast<LtNwcHyperbola>(LcNwcCurve::GetHandle()); }
   LtNwcHyperbola GetHandle() const
   { return static_cast<LtNwcHyperbola>(LcNwcCurve::GetHandle()); }
};

//////////////////////////////////////////////////
// 3D Bezier Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBezierCurve API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcBezierCurve : public LcNwcCurve
{
public:
   LcNwcBezierCurve(LtInt32 num_poles,
                    LtPoint *poles)
      : LcNwcCurve(LiNwcBezierCurveCreate(num_poles,
                                          poles), true) {}

   LcNwcBezierCurve(LtInt32 num_poles,
                    LtPoint *poles,
                    LtFloat *weights)
      : LcNwcCurve(LiNwcBezierCurveCreateRational(num_poles,
                                                  poles,
                                                  weights), true) {}

   LcNwcBezierCurve(LtNwcBezierCurve handle)
      : LcNwcCurve(handle) {}

   operator LtNwcBezierCurve () const
   { return static_cast<LtNwcBezierCurve>(LcNwcCurve::GetHandle()); }
   LtNwcBezierCurve GetHandle() const
   { return static_cast<LtNwcBezierCurve>(LcNwcCurve::GetHandle()); }
};

//////////////////////////////////////////////////
// 3D B-Spline Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBSplineCurve API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcBSplineCurve : public LcNwcCurve
{
public:
   LcNwcBSplineCurve(LtInt32 num_poles,
                     LtPoint *poles,
                     LtInt32 num_knots,
                     LtFloat *knots,
                     LtInt32 *mults,
                     LtInt32 degree,
                     bool periodic = false)
      : LcNwcCurve(LiNwcBSplineCurveCreate(num_poles,
                                           poles,
                                           num_knots,
                                           knots,
                                           mults,
                                           degree,
                                           periodic), true) {}

   LcNwcBSplineCurve(LtInt32 num_poles,
                     LtPoint *poles,
                     LtFloat *weights,
                     LtInt32 num_knots,
                     LtFloat *knots,
                     LtInt32 *mults,
                     LtInt32 degree,
                     bool periodic = false)
      : LcNwcCurve(LiNwcBSplineCurveCreateRational(num_poles,
                                                   poles,
                                                   weights,
                                                   num_knots,
                                                   knots,
                                                   mults,
                                                   degree,
                                                   periodic), true) {}

   LcNwcBSplineCurve(LtNwcBSplineCurve handle)
      : LcNwcCurve(handle) {}

   operator LtNwcBSplineCurve () const
   { return static_cast<LtNwcBSplineCurve>(LcNwcCurve::GetHandle()); }
   LtNwcBSplineCurve GetHandle() const
   { return static_cast<LtNwcBSplineCurve>(LcNwcCurve::GetHandle()); }
};

//////////////////////////////////////////////////
// 3D Trimmed Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcTrimmedCurve API calls
 *
 * \see LiNwcCurve.h
 */
class LcNwcTrimmedCurve : public LcNwcCurve
{
public:
   LcNwcTrimmedCurve(LtNwcCurve basis_curve,
                     LtFloat param0,
                     LtFloat param1,
                     bool sense = true)
      : LcNwcCurve(LiNwcTrimmedCurveCreate(basis_curve,
                                           param0,
                                           param1,
                                           sense), true) {}

   LcNwcTrimmedCurve(LtNwcCurve basis_curve,
                     LtPoint pnt0,
                     LtPoint pnt1,
                     bool sense = true)
      : LcNwcCurve(LiNwcTrimmedCurveCreateEx(basis_curve,
                                             pnt0,
                                             pnt1,
                                             sense), true) {}

   LcNwcTrimmedCurve(LtNwcTrimmedCurve handle)
      : LcNwcCurve(handle) {}

   operator LtNwcTrimmedCurve () const
   { return static_cast<LtNwcTrimmedCurve>(LcNwcCurve::GetHandle()); }
   LtNwcTrimmedCurve GetHandle() const
   { return static_cast<LtNwcTrimmedCurve>(LcNwcCurve::GetHandle()); }
};

#endif

#endif /* LINWCCURVE_HDR */
