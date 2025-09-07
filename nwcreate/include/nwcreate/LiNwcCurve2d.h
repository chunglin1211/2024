/**
 * \file
 *
 * Definitions of 2D curves.
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

#ifndef LINWCCURVE2D_HDR
#define LINWCCURVE2D_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////
// 2D Curve
//////////////////////////////////////////////////

/**
 * Reverses a curve
 *
 * \param curve 2D curve to reverse
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurve2dReverse(LtNwcCurve2d curve);

/**
 * Destroy a 2D curve of any type
 *
 * \param curve 2D curve to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurve2dDestroy(LtNwcCurve2d curve);

/**
 * Sets the user data field on the 2D curve.
 *
 * \param curve curve to set data field on.
 * \param data data to attach
 * \version 5.4
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurve2dSetUserData(LtNwcCurve2d curve,
                        LtInt32 data);

/**
 * Evaluate a 2D curve at a given point.
 *
 * \param curve curve to evaluate
 * \param t parameter
 * \param pnt return curve point at parameter t
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCurve2dEvaluate(LtNwcCurve2d curve,
                     LtFloat t,
                     LtPoint2d pnt);

/**
 * Creates a copy of a 2D curve.
 *
 * \param curve curve to copy
 * \return copy of curve
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcCurve2d LI_NWC_API
LiNwcCurve2dCreateCopy(LtNwcCurve2d curve);

/**
 * Creates a reference to a 2D curve.
 *
 * \param curve curve to reference
 * \return reference to curve
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcCurve2d LI_NWC_API
LiNwcCurve2dCreateRef(LtNwcCurve2d curve);

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
LiNwcCurve2dGetFirstParameter(LtNwcCurve2d curve,
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
LiNwcCurve2dGetLastParameter(LtNwcCurve2d curve,
                             bool *is_infinite);

//////////////////////////////////////////////////
// 2D Line
//////////////////////////////////////////////////

/**
 * Create a 2D line
 *
 * \param pnt a point on the line
 * \param dir direction of the line
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcLine2d LI_NWC_API
LiNwcLine2dCreate(LtPoint2d pnt,
                  LtVector2d dir);

/**
 * Create a 2D line
 *
 * \param pnt0 first point on the line
 * \param pnt1 second point on the line
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcLine2d LI_NWC_API
LiNwcLine2dCreateEx(LtPoint2d pnt0,
                    LtPoint2d pnt1);

//////////////////////////////////////////////////
// 2D Circle
//////////////////////////////////////////////////

/**
 * Create a 2D circle
 *
 * \param pnt centre point of circle
 * \param xaxis x direction of circle
 * \param yaxis y direction of circle
 * \param radius radius of circle
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcCircle2d LI_NWC_API
LiNwcCircle2dCreate(LtPoint2d pnt,
                    LtVector2d xaxis,
                    LtVector2d yaxis,
                    LtFloat radius);

/**
 * Create a 2D circle
 *
 * \param pnt centre point of circle
 * \param xaxis x direction of circle
 * \param radius radius of circle
 * \param reversed is the circle reversed
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcCircle2d LI_NWC_API
LiNwcCircle2dCreateEx(LtPoint2d pnt,
                      LtVector2d xaxis,
                      LtFloat radius,
                      bool reversed);

//////////////////////////////////////////////////
// 2D Ellipse
//////////////////////////////////////////////////

/**
 * Create a 2D ellipse
 *
 * \param pnt centre point of ellipse
 * \param xaxis x direction of ellipse
 * \param yaxis y direction of ellipse
 * \param major_radius major radius of ellipse
 * \param minor_radius minor radius of ellipse
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcEllipse2d LI_NWC_API
LiNwcEllipse2dCreate(LtPoint2d pnt,
                     LtVector2d xaxis,
                     LtVector2d yaxis,
                     LtFloat major_radius,
                     LtFloat minor_radius);

/**
 * Create a 2D ellipse
 *
 * \param pnt centre point of ellipse
 * \param xaxis x direction of ellipse
 * \param major_radius major radius of ellipse
 * \param minor_radius minor radius of ellipse
 * \param reversed is the ellipse reversed
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcEllipse2d LI_NWC_API
LiNwcEllipse2dCreateEx(LtPoint2d pnt,
                       LtVector2d xaxis,
                       LtFloat major_radius,
                       LtFloat minor_radius,
                       bool reversed);

//////////////////////////////////////////////////
// 2D Parabola
//////////////////////////////////////////////////

/**
 * Create a 2D parabola
 *
 * \param pnt apex of parabola
 * \param xaxis x direction of parabola
 * \param yaxis y direction of parabola
 * \param focal_length focal length of parabola
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcParabola2d LI_NWC_API
LiNwcParabola2dCreate(LtPoint2d pnt,
                      LtVector2d xaxis,
                      LtVector2d yaxis,
                      LtFloat focal_length);

/**
 * Create a 2D parabola
 *
 * \param pnt apex of parabola
 * \param xaxis x direction of parabola
 * \param focal_length focal length of parabola
 * \param reversed is the parabola reversed
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcParabola2d LI_NWC_API
LiNwcParabola2dCreateEx(LtPoint2d pnt,
                        LtVector2d xaxis,
                        LtFloat focal_length,
                        bool reversed);

//////////////////////////////////////////////////
// 2D Hyperbola
//////////////////////////////////////////////////

/**
 * Create a 2D hyperbola
 *
 * \param pnt apex of hyperbola
 * \param xaxis x direction of hyperbola
 * \param yaxis y direction of hyperbola
 * \param major_radius major radius of hyperbola
 * \param minor_radius minor radius of hyperbola
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcHyperbola2d LI_NWC_API
LiNwcHyperbola2dCreate(LtPoint2d pnt,
                       LtVector2d xaxis,
                       LtVector2d yaxis,
                       LtFloat major_radius,
                       LtFloat minor_radius);

/**
 * Create a 2D hyperbola
 *
 * \param pnt apex of hyperbola
 * \param xaxis x direction of hyperbola
 * \param major_radius major radius of hyperbola
 * \param minor_radius minor radius of hyperbola
 * \param reversed is the hyperbola reversed
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcHyperbola2d LI_NWC_API
LiNwcHyperbola2dCreateEx(LtPoint2d pnt,
                         LtVector2d xaxis,
                         LtFloat major_radius,
                         LtFloat minor_radius,
                         bool reversed);

//////////////////////////////////////////////////
// 2D Bezier Curve
//////////////////////////////////////////////////

/**
 * Create a 2D Bezier curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 2D poles
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBezierCurve2d LI_NWC_API
LiNwcBezierCurve2dCreate(LtInt32 num_poles,
                         LtPoint2d *poles);

/**
 * Create a rational 2D Bezier curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 2D poles
 * \param weights array of weights
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBezierCurve2d LI_NWC_API
LiNwcBezierCurve2dCreateRational(LtInt32 num_poles,
                                 LtPoint2d *poles,
                                 LtFloat *weights);

//////////////////////////////////////////////////
// 2D B-Spline Curve
//////////////////////////////////////////////////

/**
 * Create a 2D B-Spline curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 2D poles
 * \param num_knots number of knots in curve
 * \param knots array of knots
 * \param mults array of knot multiplicities
 * \param degree degree of curve
 * \param periodic is curve periodic
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBSplineCurve2d LI_NWC_API
LiNwcBSplineCurve2dCreate(LtInt32 num_poles,
                          LtPoint2d *poles,
                          LtInt32 num_knots,
                          LtFloat *knots,
                          LtInt32 *mults,
                          LtInt32 degree,
                          bool periodic);

/**
 * Create a rational 2D B-Spline curve
 *
 * \param num_poles number of poles in curve
 * \param poles array of 2D poles
 * \param weights array of weights
 * \param num_knots number of knots in curve
 * \param knots array of knots
 * \param mults array of knot multiplicities
 * \param degree degree of curve
 * \param periodic is curve periodic
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBSplineCurve2d LI_NWC_API
LiNwcBSplineCurve2dCreateRational(LtInt32 num_poles,
                                  LtPoint2d *poles,
                                  LtFloat *weights,
                                  LtInt32 num_knots,
                                  LtFloat *knots,
                                  LtInt32 *mults,
                                  LtInt32 degree,
                                  bool periodic);

//////////////////////////////////////////////////
// 2D Trimmed Curve
//////////////////////////////////////////////////

/**
 * Create a 2D trimmed curve
 *
 * \param basis_curve curve to trim
 * \param param0 first parameter of trimmed curve
 * \param param1 second parameter of trimmed curve
 * \param sense is the sense of the trimmed curve reversed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcTrimmedCurve2d LI_NWC_API
LiNwcTrimmedCurve2dCreate(LtNwcCurve2d basis_curve,
                          LtFloat param0,
                          LtFloat param1,
                          bool sense);

/**
 * Create a 2D trimmed curve
 *
 * \param basis_curve curve to trim
 * \param pnt0 starting point of trimmed curve
 * \param pnt1 ending point of trimmed curve
 * \param sense is the sense of the trimmed curve reversed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcTrimmedCurve2d LI_NWC_API
LiNwcTrimmedCurve2dCreateEx(LtNwcCurve2d basis_curve,
                            LtPoint2d pnt0,
                            LtPoint2d pnt1,
                            bool sense);

#ifdef __cplusplus
}

//////////////////////////////////////////////////
// 2D Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcCurve2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcCurve2d
{
public:
   LcNwcCurve2d(LtNwcCurve2d handle) : m_handle(LiNwcCurve2dCreateRef(handle)) {}

   ~LcNwcCurve2d() { LiNwcCurve2dDestroy(m_handle); }

   LcNwcCurve2d(const LcNwcCurve2d &other) : m_handle(LiNwcCurve2dCreateRef(other)) {}

   LcNwcCurve2d& operator = (const LcNwcCurve2d &other)
   { LiNwcCurve2dDestroy(m_handle); m_handle = LiNwcCurve2dCreateRef(other); return *this; }

   operator LtNwcCurve2d () const { return m_handle; }
   LtNwcCurve2d GetHandle() const { return m_handle; }

   LcNwcCurve2d Copy()
   { return LcNwcCurve2d(LiNwcCurve2dCreateCopy(m_handle), true); }

   void SetUserData(LtInt32 data)
   { LiNwcCurve2dSetUserData(m_handle, data); }

   void Evaluate(LtFloat t,
                 LtPoint2d pnt)
   { LiNwcCurve2dEvaluate(m_handle, t, pnt); }

   void Reverse()
   { LiNwcCurve2dReverse(m_handle); }

   LtFloat GetFirstParameter(bool *is_infinite = NULL)
   { return LiNwcCurve2dGetFirstParameter(m_handle, is_infinite); }

   LtFloat GetLastParameter(bool *is_infinite = NULL)
   { return LiNwcCurve2dGetLastParameter(m_handle, is_infinite); }

protected:
   LcNwcCurve2d(LtNwcCurve2d handle, bool /*own*/)
      : m_handle(handle) {}

   LtNwcCurve2d m_handle;
};

//////////////////////////////////////////////////
// 2D Line
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcLine2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcLine2d : public LcNwcCurve2d
{
public:
   LcNwcLine2d(LtPoint2d pnt,
               LtVector2d dir)
      : LcNwcCurve2d(LiNwcLine2dCreate(pnt,
                                       dir), true) {}

   LcNwcLine2d(LtNwcLine2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcLine2d () const
   { return static_cast<LtNwcLine2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcLine2d GetHandle() const
   { return static_cast<LtNwcLine2d>(LcNwcCurve2d::GetHandle()); }
};

//////////////////////////////////////////////////
// 2D Circle
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcCircle2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcCircle2d : public LcNwcCurve2d
{
public:
   LcNwcCircle2d(LtPoint2d pnt,
                 LtVector2d xaxis,
                 LtVector2d yaxis,
                 LtFloat radius)
      : LcNwcCurve2d(LiNwcCircle2dCreate(pnt,
                                         xaxis,
                                         yaxis,
                                         radius), true) {}

   LcNwcCircle2d(LtPoint2d pnt,
                 LtVector2d xaxis,
                 LtFloat radius,
                 bool reversed = false)
      : LcNwcCurve2d(LiNwcCircle2dCreateEx(pnt,
                                           xaxis,
                                           radius,
                                           reversed), true) {}

   LcNwcCircle2d(LtNwcCircle2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcCircle2d () const
   { return static_cast<LtNwcCircle2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcCircle2d GetHandle() const
   { return static_cast<LtNwcCircle2d>(LcNwcCurve2d::GetHandle()); }
};

//////////////////////////////////////////////////
// 2D Ellipse
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcEllipse2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcEllipse2d : public LcNwcCurve2d
{
public:
   LcNwcEllipse2d(LtPoint2d pnt,
                  LtVector2d xaxis,
                  LtVector2d yaxis,
                  LtFloat major_radius,
                  LtFloat minor_radius)
      : LcNwcCurve2d(LiNwcEllipse2dCreate(pnt,
                                          xaxis,
                                          yaxis,
                                          major_radius,
                                          minor_radius), true) {}

   LcNwcEllipse2d(LtPoint2d pnt,
                  LtVector2d xaxis,
                  LtFloat major_radius,
                  LtFloat minor_radius,
                  bool reversed = false)
      : LcNwcCurve2d(LiNwcEllipse2dCreateEx(pnt,
                                            xaxis,
                                            major_radius,
                                            minor_radius,
                                            reversed), true) {}

   LcNwcEllipse2d(LtNwcEllipse2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcEllipse2d () const
   { return static_cast<LtNwcEllipse2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcEllipse2d GetHandle() const
   { return static_cast<LtNwcEllipse2d>(LcNwcCurve2d::GetHandle()); }
};

//////////////////////////////////////////////////
// 2D Parabola
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcParabola2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcParabola2d : public LcNwcCurve2d
{
public:
   LcNwcParabola2d(LtPoint2d pnt,
                   LtVector2d xaxis,
                   LtVector2d yaxis,
                   LtFloat focal_length)
      : LcNwcCurve2d(LiNwcParabola2dCreate(pnt,
                                           xaxis,
                                           yaxis,
                                           focal_length), true) {}

   LcNwcParabola2d(LtPoint2d pnt,
                   LtVector2d xaxis,
                   LtFloat focal_length,
                   bool reversed = false)
      : LcNwcCurve2d(LiNwcParabola2dCreateEx(pnt,
                                             xaxis,
                                             focal_length,
                                             reversed), true) {}

   LcNwcParabola2d(LtNwcParabola2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcParabola2d () const
   { return static_cast<LtNwcParabola2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcParabola2d GetHandle() const
   { return static_cast<LtNwcParabola2d>(LcNwcCurve2d::GetHandle()); }
};

//////////////////////////////////////////////////
// 2D Hyperbola
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcHyperbola2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcHyperbola2d : public LcNwcCurve2d
{
public:
   LcNwcHyperbola2d(LtPoint2d pnt,
                    LtVector2d xaxis,
                    LtVector2d yaxis,
                    LtFloat major_radius,
                    LtFloat minor_radius)
      : LcNwcCurve2d(LiNwcHyperbola2dCreate(pnt,
                                            xaxis,
                                            yaxis,
                                            major_radius,
                                            minor_radius), true) {}

   LcNwcHyperbola2d(LtPoint2d pnt,
                    LtVector2d xaxis,
                    LtFloat major_radius,
                    LtFloat minor_radius,
                    bool reversed = false)
      : LcNwcCurve2d(LiNwcHyperbola2dCreateEx(pnt,
                                              xaxis,
                                              major_radius,
                                              minor_radius,
                                              reversed), true) {}

   LcNwcHyperbola2d(LtNwcHyperbola2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcHyperbola2d () const
   { return static_cast<LtNwcHyperbola2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcHyperbola2d GetHandle() const
   { return static_cast<LtNwcHyperbola2d>(LcNwcCurve2d::GetHandle()); }
};

//////////////////////////////////////////////////
// 2D Bezier Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBezierCurve2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcBezierCurve2d : public LcNwcCurve2d
{
public:
   LcNwcBezierCurve2d(LtInt32 num_poles,
                      LtPoint2d *poles)
      : LcNwcCurve2d(LiNwcBezierCurve2dCreate(num_poles,
                                              poles), true) {}

   LcNwcBezierCurve2d(LtInt32 num_poles,
                      LtPoint2d *poles,
                      LtFloat *weights)
      : LcNwcCurve2d(LiNwcBezierCurve2dCreateRational(num_poles,
                                                      poles,
                                                      weights), true) {}

   LcNwcBezierCurve2d(LtNwcBezierCurve2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcBezierCurve2d () const
   { return static_cast<LtNwcBezierCurve2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcBezierCurve2d GetHandle() const
   { return static_cast<LtNwcBezierCurve2d>(LcNwcCurve2d::GetHandle()); }
};

//////////////////////////////////////////////////
// 2D B-Spline Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBSplineCurve2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcBSplineCurve2d : public LcNwcCurve2d
{
public:
   LcNwcBSplineCurve2d(LtInt32 num_poles,
                       LtPoint2d *poles,
                       LtInt32 num_knots,
                       LtFloat *knots,
                       LtInt32 *mults,
                       LtInt32 degree,
                       bool periodic = false)
      : LcNwcCurve2d(LiNwcBSplineCurve2dCreate(num_poles,
                                               poles,
                                               num_knots,
                                               knots,
                                               mults,
                                               degree,
                                               periodic), true) {}

   LcNwcBSplineCurve2d(LtInt32 num_poles,
                       LtPoint2d *poles,
                       LtFloat *weights,
                       LtInt32 num_knots,
                       LtFloat *knots,
                       LtInt32 *mults,
                       LtInt32 degree,
                       bool periodic = false)
      : LcNwcCurve2d(LiNwcBSplineCurve2dCreateRational(num_poles,
                                                       poles,
                                                       weights,
                                                       num_knots,
                                                       knots,
                                                       mults,
                                                       degree,
                                                       periodic), true) {}

   LcNwcBSplineCurve2d(LtNwcBSplineCurve2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcBSplineCurve2d () const
   { return static_cast<LtNwcBSplineCurve2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcBSplineCurve2d GetHandle() const
   { return static_cast<LtNwcBSplineCurve2d>(LcNwcCurve2d::GetHandle()); }
};

//////////////////////////////////////////////////
// 2D Trimmed Curve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcTrimmedCurve2d API calls
 *
 * \see LiNwcCurve2d.h
 */
class LcNwcTrimmedCurve2d : public LcNwcCurve2d
{
public:
   LcNwcTrimmedCurve2d(LtNwcCurve2d basis_curve,
                       LtFloat param0,
                       LtFloat param1,
                       bool sense = true)
      : LcNwcCurve2d(LiNwcTrimmedCurve2dCreate(basis_curve,
                                               param0,
                                               param1,
                                               sense), true) {}

   LcNwcTrimmedCurve2d(LtNwcCurve2d basis_curve,
                       LtPoint2d pnt0,
                       LtPoint2d pnt1,
                       bool sense = true)
      : LcNwcCurve2d(LiNwcTrimmedCurve2dCreateEx(basis_curve,
                                                 pnt0,
                                                 pnt1,
                                                 sense), true) {}

   LcNwcTrimmedCurve2d(LtNwcTrimmedCurve2d handle)
      : LcNwcCurve2d(handle) {}

   operator LtNwcTrimmedCurve2d () const
   { return static_cast<LtNwcTrimmedCurve2d>(LcNwcCurve2d::GetHandle()); }
   LtNwcTrimmedCurve2d GetHandle() const
   { return static_cast<LtNwcTrimmedCurve2d>(LcNwcCurve2d::GetHandle()); }
};

#endif

#endif /* LINWCCURVE2D_HDR */
