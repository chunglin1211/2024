/**
 * \file
 *
 * API for higher level BRep operations. Includes primitive creation, profile creation and
 * CSG operations on BReps.
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

#ifndef LINWCBREPAPI_HDR
#define LINWCBREPAPI_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcTopology.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////
// Primitives
//////////////////////////////////////////////////

/**
 * Creates a box. One corner is at the origin, the
 * opposite at (dx, dy, dz).
 *
 * \param dx size along x axis
 * \param dy size along y axis
 * \param dz size along z axis
 * \return box entity
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateBox(LtFloat dx,
                   LtFloat dy,
                   LtFloat dz);

/**
 * Creates a box given two opposite points.
 *
 * \param pnt1 first corner
 * \param pnt2 second corner
 * \return box entity
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateBoxEx(LtPoint pnt1,
                     LtPoint pnt2);

/**
 * Creates a cylinder. The lower cap is centred on
 * the origin.
 *
 * \param radius cylinder radius
 * \param height cylinder height (along the z axis)
 * \return cylinder entity
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateCylinder(LtFloat radius,
                        LtFloat height);

/**
 * Creates a prism. This is an existing B-rep
 * entity extruded in a certain direction.
 * You can extrude loops (to generate an open
 * shell), or a face (to generate a solid).
 *
 * \param entity entity to extrude
 * \param dir direction of extrusion
 * \param distance distance to extrude along direction
 * \param copy not used, please ignore
 * \return extruded entity, or NULL if failed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreatePrism(LtNwcBRepEntity entity,
                     LtVector dir,
                     LtFloat distance,
                     bool copy);

/**
 * Creates a revolve. This is an existing B-rep
 * entity revolved along an axis. You can revolve
 * a loop (to generate an open shell) or a face (to
 * generate a solid).
 *
 * \param entity entity to revolve
 * \param org origin for revolution axis
 * \param axis direction of revolution axis
 * \param angle angle to revolve by, in radians
 * \param copy not used, please ignore
 * \return revolved entity, of NULL if failed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateRevolve(LtNwcBRepEntity entity,
                       LtPoint org,
                       LtVector axis,
                       LtFloat angle,
                       bool copy);

/**
 * Creates a half-space object from a plane.
 *
 * \param plane plane to construct half-space.
 * \param sense_agreement if true, matter is on side normal points to.
 * \return half-space entity
 * \version 5.0;
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateHalfSpaceFromPlane(LtNwcPlane plane,
                                  bool sense_agreement);

//////////////////////////////////////////////////
// CSG
//////////////////////////////////////////////////

/**
 * Constructs the difference between two entites.
 * This is also know as the Subtract CSG operation.
 *
 * \param entity1 entity to subtract from
 * \param entity2 entity to subtract
 * \return result of CSG operation, or NULL if failed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateDifference(LtNwcBRepEntity entity1,
                          LtNwcBRepEntity entity2);

/**
 * Constructs the union between two entites.
 *
 * \param entity1 first entity to union
 * \param entity2 second entity to union
 * \return result of CSG operation, or NULL if failed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateUnion(LtNwcBRepEntity entity1,
                     LtNwcBRepEntity entity2);

/**
 * Constructs the intersection between two entites.
 *
 * \param entity1 first entity to intersect
 * \param entity2 second entity to intersect
 * \return result of CSG operation, or NULL if failed
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepCreateIntersection(LtNwcBRepEntity entity1,
                            LtNwcBRepEntity entity2);

//////////////////////////////////////////////////
// Profile Builder
//////////////////////////////////////////////////

/**
 * Creates a new profile builder.
 *
 * \param plane plane to build profile on
 * \return new profile builder
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepProfileBuilder LI_NWC_API
LiNwcBRepProfileBuilderCreate(LtNwcPlane plane);

/**
 * Adds a point to the profile.
 *
 * \param handle handle to profile builder
 * \param x x coordinate of point
 * \param y y coordinate of point
 * \return true if successful, false otherwise
 * \version 5.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcBRepProfileBuilderAddPoint(LtNwcBRepProfileBuilder handle,
                                LtFloat x,
                                LtFloat y);

/**
 * Sets the radius for the next vertex added. This
 * means that the corner where you add the next vertex
 * will have a filleted radius (if possible). Sometimes
 * it won't be possible to fullfill the requested radius.
 * In this case, no fillet will be generated.
 *
 * \param handle handle to profile builder
 * \param radius radius of next vertex.
 * \return true if successful, false otherwise
 * \version 5.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcBRepProfileBuilderSetRadius(LtNwcBRepProfileBuilder handle,
                                 LtFloat radius);

/**
 * Closes the profile. After you've closed a profile, you
 * cannot add any more points to it.
 *
 * \param handle handle to profile builder
 * \return true if successful, false otherwise
 * \version 5.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcBRepProfileBuilderClose(LtNwcBRepProfileBuilder handle);

/**
 * Resets the builder. Any profile under construction is
 * thrown away. The plane remains unchanged.
 *
 * \param handle handle to profile builder
 * \return true if successful, false otherwise
 * \version 5.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcBRepProfileBuilderReset(LtNwcBRepProfileBuilder handle);

/**
 * Generates a loop for the profile. You can then use
 * this loop to add to a face.
 *
 * Note that you are responsible for destroying the
 * loop that is returned.
 *
 * If you use the C++ version of this function, it
 * returns a wrapper class instead, which will own the
 * handle, and so you do NOT need to manually destroy it.
 *
 * \param handle handle to profile builder
 * \return handle to generated loop, or NULL if failed.
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcLoop LI_NWC_API
LiNwcBRepProfileBuilderCreateLoop(LtNwcBRepProfileBuilder handle);

/**
 * Destroys a profile builder.
 *
 * \param handle handle to profile builder
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBRepProfileBuilderDestroy(LtNwcBRepProfileBuilder handle);

#ifdef __cplusplus
}

//////////////////////////////////////////////////
// BRep Box
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepBox API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepBox : public LcNwcBRepEntity
{
public:

   LcNwcBRepBox(LtFloat dx,
                LtFloat dy,
                LtFloat dz) : LcNwcBRepEntity(LiNwcBRepCreateBox(dx, dy, dz), true) {}

   LcNwcBRepBox(LtPoint pnt1,
                LtPoint pnt2) : LcNwcBRepEntity(LiNwcBRepCreateBoxEx(pnt1, pnt2), true) {}
};

//////////////////////////////////////////////////
// BRep Cylinder
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepCylinder API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepCylinder : public LcNwcBRepEntity
{
public:

   LcNwcBRepCylinder(LtFloat radius,
                     LtFloat height) : LcNwcBRepEntity(LiNwcBRepCreateCylinder(radius, height), true) {}
};

//////////////////////////////////////////////////
// BRep Prism
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepPrism API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepPrism : public LcNwcBRepEntity
{
public:

   LcNwcBRepPrism(LtNwcBRepEntity entity,
                  LtVector dir,
                  LtFloat distance,
                  bool copy) : LcNwcBRepEntity(LiNwcBRepCreatePrism(entity, dir, distance, copy), true) {}
};

//////////////////////////////////////////////////
// BRep Revolve
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepRevolve API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepRevolve : public LcNwcBRepEntity
{
public:

   LcNwcBRepRevolve(LtNwcBRepEntity entity,
                    LtPoint org,
                    LtVector axis,
                    LtFloat angle,
                    bool copy) : LcNwcBRepEntity(LiNwcBRepCreateRevolve(entity, org, axis, angle, copy), true) {}
};

//////////////////////////////////////////////////
// BRep Half-space
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepHalfSpace API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepHalfSpace : public LcNwcBRepEntity
{
public:

   LcNwcBRepHalfSpace(LtNwcPlane plane,
                      bool sense_agreement) : LcNwcBRepEntity(LiNwcBRepCreateHalfSpaceFromPlane(plane, sense_agreement), true) {}
};

//////////////////////////////////////////////////
// BRep Difference
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepDifference API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepDifference : public LcNwcBRepEntity
{
public:

   LcNwcBRepDifference(LtNwcBRepEntity entity1,
                       LtNwcBRepEntity entity2) : LcNwcBRepEntity(LiNwcBRepCreateDifference(entity1, entity2), true) {}
};

//////////////////////////////////////////////////
// BRep Union
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepUnion API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepUnion : public LcNwcBRepEntity
{
public:

   LcNwcBRepUnion(LtNwcBRepEntity entity1,
                  LtNwcBRepEntity entity2) : LcNwcBRepEntity(LiNwcBRepCreateUnion(entity1, entity2), true) {}
};

//////////////////////////////////////////////////
// BRep Intersection
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepIntersection API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepIntersection : public LcNwcBRepEntity
{
public:

   LcNwcBRepIntersection(LtNwcBRepEntity entity1,
                         LtNwcBRepEntity entity2) : LcNwcBRepEntity(LiNwcBRepCreateIntersection(entity1, entity2), true) {}
};

//////////////////////////////////////////////////
// Profile Builder
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepProfileBuilder API calls
 *
 * \see LiNwcBRepAPI.h
 */
class LcNwcBRepProfileBuilder
{
public:
   LcNwcBRepProfileBuilder(LtNwcPlane plane) : m_handle(LiNwcBRepProfileBuilderCreate(plane)), m_own(true) {}
   LcNwcBRepProfileBuilder(LtNwcBRepProfileBuilder handle) : m_handle(handle), m_own(false) {}
   ~LcNwcBRepProfileBuilder() { if (m_own) LiNwcBRepProfileBuilderDestroy(m_handle); }

   operator LtNwcBRepProfileBuilder () const { return m_handle; }
   LtNwcBRepProfileBuilder GetHandle() const { return m_handle; }

   bool AddPoint(LtFloat x,
                      LtFloat y)
   { return LiNwcBRepProfileBuilderAddPoint(m_handle, x, y); }

   bool AddPoint(LtPoint pnt)
   { return LiNwcBRepProfileBuilderAddPoint(m_handle, pnt[0], pnt[1]); }

   bool SetRadius(LtFloat radius)
   { return LiNwcBRepProfileBuilderSetRadius(m_handle, radius); }

   bool Close()
   { return LiNwcBRepProfileBuilderClose(m_handle); }

   bool Reset()
   { return LiNwcBRepProfileBuilderReset(m_handle); }

   LcNwcLoop CreateLoop()
   {
      LtNwcLoop handle = LiNwcBRepProfileBuilderCreateLoop(m_handle);
      LcNwcLoop loop(handle);
      LiNwcBRepEntityDestroy(handle);
      return loop;
   }

private:
   // Can't copy
   LcNwcBRepProfileBuilder(const LcNwcBRepProfileBuilder&);
   LcNwcBRepProfileBuilder& operator= (const LcNwcBRepProfileBuilder&);

   LtNwcBRepProfileBuilder m_handle;
   bool m_own;
};

#endif //__cplusplus

#endif /* LINWCTOPOLOGY_HDR */
