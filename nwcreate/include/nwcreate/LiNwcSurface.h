/**
 * \file
 *
 * Definitions of 3D surfaces.
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
 */

#ifndef LINWCSURFACE_HDR
#define LINWCSURFACE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////
// Surface
//////////////////////////////////////////////////

/**
 * Destroy a NavisWorks surface of any type.
 *
 * \param surface surface to destroy.
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSurfaceDestroy(LtNwcSurface surface);

/**
 * Sets the user data field on the surface.
 *
 * \param surface surface to set data field on.
 * \param data data to attach.
 * \version 5.4
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSurfaceSetUserData(LtNwcSurface surface,
                        LtInt32 data);

/**
 * Evaluate a surface at a given point.
 *
 * \param surface surface to evaluate.
 * \param u u parameter.
 * \param v v parameter.
 * \param pnt return surface point at position (u, v).
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSurfaceEvaluate(LtNwcSurface surface,
                     LtFloat u,
                     LtFloat v,
                     LtPoint pnt);

/**
 * Creates a copy of a surface.
 *
 * \param surface surface to copy
 * \return copy of surface
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcSurface LI_NWC_API
LiNwcSurfaceCreateCopy(LtNwcSurface surface);

/**
 * Creates a reference to a surface.
 *
 * \param surface surface to reference
 * \return reference to surface
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcSurface LI_NWC_API
LiNwcSurfaceCreateRef(LtNwcSurface surface);

/**
 * Transforms a surface.
 *
 * \param surface surface to transform
 * \param transform transformation to apply to surface
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSurfaceTransform(LtNwcSurface surface,
                      LtNwcTransform transform);

/**
 * Translates a surface.
 *
 * \param surface surface to translate
 * \param x x component of translation
 * \param y y component of translation
 * \param z z component of translation
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSurfaceTranslate(LtNwcSurface surface,
                      LtFloat x,
                      LtFloat y,
                      LtFloat z);

//////////////////////////////////////////////////
// Plane
//////////////////////////////////////////////////

/**
 * Create a plane
 *
 * \param pnt a point on the surface
 * \param xaxis x axis of the plane
 * \param yaxis y axis of the plane
 * \param sense set to LI_NWC_SENSE_POSITIVE, currently unused
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcPlane LI_NWC_API
LiNwcPlaneCreate(LtPoint pnt,
                 LtVector xaxis,
                 LtVector yaxis,
                 LtNwcSense sense);

/**
 * Create a plane
 *
 * \param pnt a point on the surface
 * \param normal vector normal to the plane
 * \param sense set to LI_NWC_SENSE_POSITIVE, currently unused
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcPlane LI_NWC_API
LiNwcPlaneCreateEx(LtPoint pnt,
                   LtVector normal,
                   LtNwcSense sense);

//////////////////////////////////////////////////
// Conical Surface
//////////////////////////////////////////////////

/**
 * Create a conical surface
 *
 * \param pnt reference point at base of cone on main axis
 * \param xaxis x axis of the cone
 * \param yaxis y axis of the cone
 * \param radius radius of the cone at the base
 * \param half_angle half angle of the cone
 * \param sense set to LI_NWC_SENSE_POSITIVE, currently unused
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcConicalSurface LI_NWC_API
LiNwcConicalSurfaceCreate(LtPoint pnt,
                          LtVector xaxis,
                          LtVector yaxis,
                          LtFloat radius,
                          LtFloat half_angle,
                          LtNwcSense sense);

//////////////////////////////////////////////////
// Toroidal Surface
//////////////////////////////////////////////////

/**
 * Create a toroidal surface
 *
 * \param pnt reference point at centre torus on main axis
 * \param xaxis x axis of the torus
 * \param yaxis y axis of the torus
 * \param major_radius major radius of the torus
 * \param minor_radius minor radius of the torus
 * \param sense set to LI_NWC_SENSE_POSITIVE, currently unused
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcToroidalSurface LI_NWC_API
LiNwcToroidalSurfaceCreate(LtPoint pnt,
                           LtVector xaxis,
                           LtVector yaxis,
                           LtFloat major_radius,
                           LtFloat minor_radius,
                           LtNwcSense sense);

//////////////////////////////////////////////////
// Spherical Surface
//////////////////////////////////////////////////

/**
 * Create a spherical surface
 *
 * \param pnt reference point at centre of sphere on main axis
 * \param xaxis x axis of the sphere
 * \param yaxis y axis of the sphere
 * \param radius radius of the sphere
 * \param sense set to LI_NWC_SENSE_POSITIVE, currently unused
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcSphericalSurface LI_NWC_API
LiNwcSphericalSurfaceCreate(LtPoint pnt,
                            LtVector xaxis,
                            LtVector yaxis,
                            LtFloat radius,
                            LtNwcSense sense);

//////////////////////////////////////////////////
// Cylindrical Surface
//////////////////////////////////////////////////

/**
 * Create a cylindrical surface
 *
 * \param pnt reference point at base of cylinder on main axis
 * \param xaxis x axis of the cylinder
 * \param yaxis y axis of the cylinder
 * \param radius radius of the cylinder
 * \param sense set to LI_NWC_SENSE_POSITIVE, currently unused
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcCylindricalSurface LI_NWC_API
LiNwcCylindricalSurfaceCreate(LtPoint pnt,
                              LtVector xaxis,
                              LtVector yaxis,
                              LtFloat radius,
                              LtNwcSense sense);

//////////////////////////////////////////////////
// Bezier Surface
//////////////////////////////////////////////////

/**
 * Create a Bezier surface
 *
 * \param num_u_poles number of poles in u direction
 * \param num_v_poles number of poles in v direction
 * \param poles array of poles
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBezierSurface LI_NWC_API
LiNwcBezierSurfaceCreate(LtInt32 num_u_poles,
                         LtInt32 num_v_poles,
                         LtPoint *poles);

/**
 * Create a rational Bezier surface
 *
 * \param num_u_poles number of poles in u direction
 * \param num_v_poles number of poles in v direction
 * \param poles array of poles
 * \param weights array of weights
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBezierSurface LI_NWC_API
LiNwcBezierSurfaceCreateRational(LtInt32 num_u_poles,
                                 LtInt32 num_v_poles,
                                 LtPoint *poles,
                                 LtFloat *weights);

//////////////////////////////////////////////////
// BSpline Surface
//////////////////////////////////////////////////

/**
 * Create a BSpline surface
 *
 * \param num_u_poles number of poles in u direction
 * \param num_v_poles number of poles in v direction
 * \param poles array of poles
 * \param num_u_knots number of knots in u direction
 * \param u_knots array of knots for u direction
 * \param u_mults array of knot multiplicities for u direction
 * \param num_v_knots number of knots in v direction
 * \param v_knots array of knots for v direction
 * \param v_mults array of knot multiplicities for v direction
 * \param u_degree degree in u direction
 * \param v_degree degree in v direction
 * \param u_periodic is surface periodic in u direction
 * \param v_periodic is surface periodic in v direction
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBSplineSurface LI_NWC_API
LiNwcBSplineSurfaceCreate(LtInt32 num_u_poles,
                          LtInt32 num_v_poles,
                          LtPoint *poles,
                          LtInt32 num_u_knots,
                          LtFloat *u_knots,
                          LtInt32 *u_mults,
                          LtInt32 num_v_knots,
                          LtFloat *v_knots,
                          LtInt32 *v_mults,
                          LtInt32 u_degree,
                          LtInt32 v_degree,
                          bool u_periodic,
                          bool v_periodic);

/**
 * Create a rational BSpline surface
 *
 * \param num_u_poles number of poles in u direction
 * \param num_v_poles number of poles in v direction
 * \param poles array of poles
 * \param weights array of weights
 * \param num_u_knots number of knots in u direction
 * \param u_knots array of knots for u direction
 * \param u_mults array of knot multiplicities for u direction
 * \param num_v_knots number of knots in v direction
 * \param v_knots array of knots for v direction
 * \param v_mults array of knot multiplicities for v direction
 * \param u_degree degree in u direction
 * \param v_degree degree in v direction
 * \param u_periodic is surface periodic in u direction
 * \param v_periodic is surface periodic in v direction
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBSplineSurface LI_NWC_API
LiNwcBSplineSurfaceCreateRational(LtInt32 num_u_poles,
                                  LtInt32 num_v_poles,
                                  LtPoint *poles,
                                  LtFloat *weights,
                                  LtInt32 num_u_knots,
                                  LtFloat *u_knots,
                                  LtInt32 *u_mults,
                                  LtInt32 num_v_knots,
                                  LtFloat *v_knots,
                                  LtInt32 *v_mults,
                                  LtInt32 u_degree,
                                  LtInt32 v_degree,
                                  bool u_periodic,
                                  bool v_periodic);

//////////////////////////////////////////////////
// Rectangular Trimmed Surface
//////////////////////////////////////////////////

/**
 * Create a rectangular trimmed surface
 *
 * \param basis_surface surface to trim
 * \param u0 first u parameter
 * \param u1 second u parameter
 * \param v0 first v parameter
 * \param v1 second v parameter
 * \param u_sense is the u sense reversed
 * \param v_sense is the v sense reversed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcRectangularTrimmedSurface LI_NWC_API
LiNwcRectangularTrimmedSurfaceCreate(LtNwcSurface basis_surface,
                                     LtFloat u0,
                                     LtFloat u1,
                                     LtFloat v0,
                                     LtFloat v1,
                                     bool u_sense,
                                     bool v_sense);

/**
 * Create a rectangular trimmed surface
 *
 * \param basis_surface surface to trim
 * \param param0 first parameter
 * \param param1 second parameter
 * \param u_trim is the u direction trimmed
 * \param sense is the v sense reversed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcRectangularTrimmedSurface LI_NWC_API
LiNwcRectangularTrimmedSurfaceCreateEx(LtNwcSurface basis_surface,
                                       LtFloat param0,
                                       LtFloat param1,
                                       bool u_trim,
                                       bool sense);

//////////////////////////////////////////////////
// Offset Surface
//////////////////////////////////////////////////

/**
 * Create an offset surface
 *
 * \param basis_surface surface to offset
 * \param distance offset distance
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcOffsetSurface LI_NWC_API
LiNwcOffsetSurfaceCreate(LtNwcSurface basis_surface,
                         LtFloat distance);

//////////////////////////////////////////////////
// Extruded Surface
//////////////////////////////////////////////////

/**
 * Create a surface of linear extrusion
 *
 * \param basis_curve curve to extrude
 * \param direction direction of extrusion
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcExtrudedSurface LI_NWC_API
LiNwcExtrudedSurfaceCreate(LtNwcCurve basis_curve,
                           LtVector direction);

//////////////////////////////////////////////////
// Revolved Surface
//////////////////////////////////////////////////

/**
 * Create a surface of revolution
 *
 * \param basis_curve curve to revolve
 * \param location axis of revolution location
 * \param direction axis of revolution direction
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcRevolvedSurface LI_NWC_API
LiNwcRevolvedSurfaceCreate(LtNwcCurve basis_curve,
                           LtPoint location,
                           LtVector direction);

#ifdef __cplusplus
}

//////////////////////////////////////////////////
// Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcSurface
{
public:
   LcNwcSurface(LtNwcSurface handle) : m_handle(LiNwcSurfaceCreateRef(handle)) {}

   ~LcNwcSurface() { LiNwcSurfaceDestroy(m_handle); }

   LcNwcSurface(const LcNwcSurface &other) : m_handle(LiNwcSurfaceCreateRef(other)) {}

   LcNwcSurface& operator = (const LcNwcSurface &other)
   { LiNwcSurfaceDestroy(m_handle); m_handle = LiNwcSurfaceCreateRef(other); return *this; }

   operator LtNwcSurface () const { return m_handle; }
   LtNwcSurface GetHandle() const { return m_handle; }

   LcNwcSurface Copy()
   { return LcNwcSurface(LiNwcSurfaceCreateCopy(m_handle), true); }

   void SetUserData(LtInt32 data)
   { LiNwcSurfaceSetUserData(m_handle, data); }

   void Evaluate(LtFloat u,
                 LtFloat v,
                 LtPoint pnt)
   { LiNwcSurfaceEvaluate(m_handle, u, v, pnt); }

   void Transform(LtNwcTransform transform)
   { LiNwcSurfaceTransform(m_handle, transform); }

   void Translate(LtFloat x,
                  LtFloat y,
                  LtFloat z)
   { LiNwcSurfaceTranslate(m_handle, x, y, z); }

   void Translate(LtVector v)
   { LiNwcSurfaceTranslate(m_handle, v[0], v[1], v[2]); }

protected:
   LcNwcSurface(LtNwcSurface handle, bool /*own*/)
      : m_handle(handle) {}

private:

   LtNwcSurface m_handle;
};

//////////////////////////////////////////////////
// Plane
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcPlane API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcPlane : public LcNwcSurface
{
public:
   LcNwcPlane(LtPoint pnt,
              LtVector xaxis,
              LtVector yaxis,
              LtNwcSense sense = LI_NWC_SENSE_POSITIVE)
      : LcNwcSurface(LiNwcPlaneCreate(pnt,
                                      xaxis,
                                      yaxis,
                                      sense), true) {}

   LcNwcPlane(LtPoint pnt,
              LtVector normal,
              LtNwcSense sense = LI_NWC_SENSE_POSITIVE)
      : LcNwcSurface(LiNwcPlaneCreateEx(pnt,
                                        normal,
                                        sense), true) {}

   LcNwcPlane(LtNwcPlane handle)
      : LcNwcSurface(handle) {}

   operator LtNwcPlane () const
   { return static_cast<LtNwcPlane>(LcNwcSurface::GetHandle()); }
   LtNwcPlane GetHandle() const
   { return static_cast<LtNwcPlane>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Conical Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcConicalSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcConicalSurface : public LcNwcSurface
{
public:
   LcNwcConicalSurface(LtPoint pnt,
                       LtVector xaxis,
                       LtVector yaxis,
                       LtFloat radius,
                       LtFloat half_angle,
                       LtNwcSense sense = LI_NWC_SENSE_POSITIVE)
      : LcNwcSurface(LiNwcConicalSurfaceCreate(pnt,
                                               xaxis,
                                               yaxis,
                                               radius,
                                               half_angle,
                                               sense), true) {}

   LcNwcConicalSurface(LtNwcConicalSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcConicalSurface () const
   { return static_cast<LtNwcConicalSurface>(LcNwcSurface::GetHandle()); }
   LtNwcConicalSurface GetHandle() const
   { return static_cast<LtNwcConicalSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Toroidal Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcToroidalSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcToroidalSurface : public LcNwcSurface
{
public:
   LcNwcToroidalSurface(LtPoint pnt,
                        LtVector xaxis,
                        LtVector yaxis,
                        LtFloat major_radius,
                        LtFloat minor_radius,
                        LtNwcSense sense = LI_NWC_SENSE_POSITIVE)
      : LcNwcSurface(LiNwcToroidalSurfaceCreate(pnt,
                                                xaxis,
                                                yaxis,
                                                major_radius,
                                                minor_radius,
                                                sense), true) {}

   LcNwcToroidalSurface(LtNwcToroidalSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcToroidalSurface () const
   { return static_cast<LtNwcToroidalSurface>(LcNwcSurface::GetHandle()); }
   LtNwcToroidalSurface GetHandle() const
   { return static_cast<LtNwcToroidalSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Spherical Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcSphericalSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcSphericalSurface : public LcNwcSurface
{
public:
   LcNwcSphericalSurface(LtPoint pnt,
                         LtVector xaxis,
                         LtVector yaxis,
                         LtFloat radius,
                         LtNwcSense sense = LI_NWC_SENSE_POSITIVE)
      : LcNwcSurface(LiNwcSphericalSurfaceCreate(pnt,
                                                 xaxis,
                                                 yaxis,
                                                 radius,
                                                 sense), true) {}

   LcNwcSphericalSurface(LtNwcSphericalSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcSphericalSurface () const
   { return static_cast<LtNwcSphericalSurface>(LcNwcSurface::GetHandle()); }
   LtNwcSphericalSurface GetHandle() const
   { return static_cast<LtNwcSphericalSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Cylindrical Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcCylindricalSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcCylindricalSurface : public LcNwcSurface
{
public:
   LcNwcCylindricalSurface(LtPoint pnt,
                           LtVector xaxis,
                           LtVector yaxis,
                           LtFloat radius,
                           LtNwcSense sense = LI_NWC_SENSE_POSITIVE)
      : LcNwcSurface(LiNwcCylindricalSurfaceCreate(pnt,
                                                   xaxis,
                                                   yaxis,
                                                   radius,
                                                   sense), true) {}

   LcNwcCylindricalSurface(LtNwcCylindricalSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcCylindricalSurface () const
   { return static_cast<LtNwcCylindricalSurface>(LcNwcSurface::GetHandle()); }
   LtNwcCylindricalSurface GetHandle() const
   { return static_cast<LtNwcCylindricalSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Bezier Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBezierSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcBezierSurface : public LcNwcSurface
{
public:
   LcNwcBezierSurface(LtInt32 num_u_poles,
                      LtInt32 num_v_poles,
                      LtPoint *poles)
      : LcNwcSurface(LiNwcBezierSurfaceCreate(num_u_poles,
                                              num_v_poles,
                                              poles), true) {}

   LcNwcBezierSurface(LtInt32 num_u_poles,
                      LtInt32 num_v_poles,
                      LtPoint *poles,
                      LtFloat *weights)
      : LcNwcSurface(LiNwcBezierSurfaceCreateRational(num_u_poles,
                                                      num_v_poles,
                                                      poles,
                                                      weights), true) {}

   LcNwcBezierSurface(LtNwcBezierSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcBezierSurface () const
   { return static_cast<LtNwcBezierSurface>(LcNwcSurface::GetHandle()); }
   LtNwcBezierSurface GetHandle() const
   { return static_cast<LtNwcBezierSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// BSpline Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBSplineSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcBSplineSurface : public LcNwcSurface
{
public:
   LcNwcBSplineSurface(LtInt32 num_u_poles,
                       LtInt32 num_v_poles,
                       LtPoint *poles,
                       LtInt32 num_u_knots,
                       LtFloat *u_knots,
                       LtInt32 *u_mults,
                       LtInt32 num_v_knots,
                       LtFloat *v_knots,
                       LtInt32 *v_mults,
                       LtInt32 u_degree,
                       LtInt32 v_degree,
                       bool u_periodic = false,
                       bool v_periodic = false)
      : LcNwcSurface(LiNwcBSplineSurfaceCreate(num_u_poles,
                                               num_v_poles,
                                               poles,
                                               num_u_knots,
                                               u_knots,
                                               u_mults,
                                               num_v_knots,
                                               v_knots,
                                               v_mults,
                                               u_degree,
                                               v_degree,
                                               u_periodic,
                                               v_periodic), true) {}

   LcNwcBSplineSurface(LtInt32 num_u_poles,
                       LtInt32 num_v_poles,
                       LtPoint *poles,
                       LtFloat *weights,
                       LtInt32 num_u_knots,
                       LtFloat *u_knots,
                       LtInt32 *u_mults,
                       LtInt32 num_v_knots,
                       LtFloat *v_knots,
                       LtInt32 *v_mults,
                       LtInt32 u_degree,
                       LtInt32 v_degree,
                       bool u_periodic = false,
                       bool v_periodic = false)
      : LcNwcSurface(LiNwcBSplineSurfaceCreateRational(num_u_poles,
                                                       num_v_poles,
                                                       poles,
                                                       weights,
                                                       num_u_knots,
                                                       u_knots,
                                                       u_mults,
                                                       num_v_knots,
                                                       v_knots,
                                                       v_mults,
                                                       u_degree,
                                                       v_degree,
                                                       u_periodic,
                                                       v_periodic), true) {}

   LcNwcBSplineSurface(LtNwcBSplineSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcBSplineSurface () const
   { return static_cast<LtNwcBSplineSurface>(LcNwcSurface::GetHandle()); }
   LtNwcBSplineSurface GetHandle() const
   { return static_cast<LtNwcBSplineSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Rectangular Trimmed Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcRectangularTrimmedSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcRectangularTrimmedSurface : public LcNwcSurface
{
public:
   LcNwcRectangularTrimmedSurface(LtNwcSurface basis_surface,
                                  LtFloat u0,
                                  LtFloat u1,
                                  LtFloat v0,
                                  LtFloat v1,
                                  bool u_sense = true,
                                  bool v_sense = true)
      : LcNwcSurface(LiNwcRectangularTrimmedSurfaceCreate(basis_surface,
                                                          u0,
                                                          u1,
                                                          v0,
                                                          v1,
                                                          u_sense,
                                                          v_sense), true) {}

   LcNwcRectangularTrimmedSurface(LtNwcSurface basis_surface,
                                  LtFloat param0,
                                  LtFloat param1,
                                  bool u_trim,
                                  bool sense = true)
      : LcNwcSurface(LiNwcRectangularTrimmedSurfaceCreateEx(basis_surface,
                                                            param0,
                                                            param1,
                                                            u_trim,
                                                            sense), true) {}

   LcNwcRectangularTrimmedSurface(LtNwcRectangularTrimmedSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcRectangularTrimmedSurface () const
   { return static_cast<LtNwcRectangularTrimmedSurface>(LcNwcSurface::GetHandle()); }
   LtNwcRectangularTrimmedSurface GetHandle() const
   { return static_cast<LtNwcRectangularTrimmedSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Offset Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcOffsetSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcOffsetSurface : public LcNwcSurface
{
public:
   LcNwcOffsetSurface(LtNwcSurface basis_surface,
                      LtFloat distance)
      : LcNwcSurface(LiNwcOffsetSurfaceCreate(basis_surface,
                                              distance), true) {}

   LcNwcOffsetSurface(LtNwcOffsetSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcOffsetSurface () const
   { return static_cast<LtNwcOffsetSurface>(LcNwcSurface::GetHandle()); }
   LtNwcOffsetSurface GetHandle() const
   { return static_cast<LtNwcOffsetSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Extruded Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcExtrudedSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcExtrudedSurface : public LcNwcSurface
{
public:
   LcNwcExtrudedSurface(LtNwcCurve basis_curve,
                        LtVector direction)
      : LcNwcSurface(LiNwcExtrudedSurfaceCreate(basis_curve,
                                                direction), true) {}

   LcNwcExtrudedSurface(LtNwcExtrudedSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcExtrudedSurface () const
   { return static_cast<LtNwcExtrudedSurface>(LcNwcSurface::GetHandle()); }
   LtNwcExtrudedSurface GetHandle() const
   { return static_cast<LtNwcExtrudedSurface>(LcNwcSurface::GetHandle()); }
};

//////////////////////////////////////////////////
// Revolved Surface
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcRevolvedSurface API calls
 *
 * \see LiNwcSurface.h
 */
class LcNwcRevolvedSurface : public LcNwcSurface
{
public:
   LcNwcRevolvedSurface(LtNwcCurve basis_curve,
                        LtPoint location,
                        LtVector direction)
      : LcNwcSurface(LiNwcRevolvedSurfaceCreate(basis_curve,
                                                location,
                                                direction), true) {}

   LcNwcRevolvedSurface(LtNwcRevolvedSurface handle)
      : LcNwcSurface(handle) {}

   operator LtNwcRevolvedSurface () const
   { return static_cast<LtNwcRevolvedSurface>(LcNwcSurface::GetHandle()); }
   LtNwcRevolvedSurface GetHandle() const
   { return static_cast<LtNwcRevolvedSurface>(LcNwcSurface::GetHandle()); }
};

#endif

#endif /* LINWCSURFACE_HDR */
