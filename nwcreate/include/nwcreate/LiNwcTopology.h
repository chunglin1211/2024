/**
 * \file
 *
 * Definitions of topology (vertex, edge, face, shell, etc.) used to define a
 * BRep (Boundary Representation) model.
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

#ifndef LINWCTOPOLOGY_HDR
#define LINWCTOPOLOGY_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////
// BRepEntity
//////////////////////////////////////////////////

/**
 * B-Rep entity types.
 */
typedef enum LtNwcBRepEntityType_tag {
   LI_NWC_BREP_UNKNOWN,   /** Unknown */
   LI_NWC_BREP_COMPOUND,  /** Compound */
   LI_NWC_BREP_COMPSOLID, /** Compound solid */
   LI_NWC_BREP_BODY,      /** Body */
   LI_NWC_BREP_SOLID,     /** Solid */
   LI_NWC_BREP_SHELL,     /** Shell */
   LI_NWC_BREP_FACE,      /** Face */
   LI_NWC_BREP_LOOP,      /** Loop */
   LI_NWC_BREP_COEDGE,    /** Coedge */
   LI_NWC_BREP_EDGE,      /** Edge */
   LI_NWC_BREP_VERTEX     /** Vertex */
} LtNwcBRepEntityType;

/**
 * Returns the type of a B-rep entity.
 *
 * \param entity entity to query
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntityType LI_NWC_API
LiNwcBRepEntityGetType(LtNwcBRepEntity entity);

/**
 * Sets the user data field on the entity.
 *
 * \param entity entity to set data on
 * \param data data to attach
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBRepEntitySetUserData(LtNwcBRepEntity entity,
                           LtInt32 data);

/**
 * Destroys a B-rep entity.
 *
 * \param entity entity to destroy
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBRepEntityDestroy(LtNwcBRepEntity entity);

/**
 * Creates a copy of a B-rep entity.
 *
 * \param entity entity to copy
 * \return copy of entity
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepEntityCreateCopy(LtNwcBRepEntity entity);

/**
 * Creates a reference to a B-rep entity.
 *
 * \param entity entity to reference
 * \return reference to entity
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcBRepEntity LI_NWC_API
LiNwcBRepEntityCreateRef(LtNwcBRepEntity entity);

/**
 * Transforms a B-rep entity.
 *
 * \param entity entity to transform
 * \param transform transformation to apply
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBRepEntityTransform(LtNwcBRepEntity entity,
                         LtNwcTransform transform);

/**
 * Translates a B-rep entity.
 *
 * \param entity entity to translate
 * \param x x component of translation
 * \param y y component of translation
 * \param z z component of translation
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBRepEntityTranslate(LtNwcBRepEntity entity,
                         LtFloat x,
                         LtFloat y,
                         LtFloat z);

//////////////////////////////////////////////////
// Vertex
//////////////////////////////////////////////////

/**
 * Create a vertex
 *
 * \param pnt point at vertex
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcVertex LI_NWC_API
LiNwcVertexCreate(LtPoint pnt);

/**
 * Destroy a vertex
 *
 * \param vertex vertex to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcVertexDestroy(LtNwcVertex vertex);

/**
 * Sets the user data field on the vertex.
 *
 * \param vertex vertex to set data on
 * \param data data to attach
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcVertexSetUserData(LtNwcVertex vertex,
                       LtInt32 data);

//////////////////////////////////////////////////
// Edge
//////////////////////////////////////////////////

/**
 * Create an edge
 *
 * \param curve curve of edge
 * \param coedge coedge edge belongs to
 * \param sense sense of edge with respect to curve
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcEdge LI_NWC_API
LiNwcEdgeCreate(LtNwcCurve curve,
                LtNwcCoedge coedge,
                LtNwcSense sense);

/**
 * Sets the first coedge of an edge
 *
 * \param edge edge to set coedge on
 * \param coedge first coedge on edge
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcEdgeSetCoedge(LtNwcEdge edge,
                   LtNwcCoedge coedge);

/**
 * Destroy an edge
 *
 * \param edge edge to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcEdgeDestroy(LtNwcEdge edge);

/**
 * Sets the user data field on the edge.
 *
 * \param edge edge to set data on
 * \param data data to attach.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcEdgeSetUserData(LtNwcEdge edge,
                     LtInt32 data);

//////////////////////////////////////////////////
// Coedge
//////////////////////////////////////////////////

/**
 * Create a coedge
 *
 * \param curve curve of coedge
 * \param edge edge of coedge
 * \param vertex forward vertex of coedge
 * \param sense orientation of coedge in relation to edge
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcCoedge LI_NWC_API
LiNwcCoedgeCreate(LtNwcCurve2d curve,
                  LtNwcEdge edge,
                  LtNwcVertex vertex,
                  LtNwcSense sense);

/**
 * Links to coedges together.
 *
 * \param coedge1 first coedge to link
 * \param coedge2 second coedge to link
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCoedgeLink(LtNwcCoedge coedge1,
                LtNwcCoedge coedge2);

/**
 * Destroy a coedge
 *
 * \param coedge coedge to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCoedgeDestroy(LtNwcCoedge coedge);

/**
 * Sets the user data field on the coedge.
 *
 * \param coedge coedge to set data on
 * \param data data to attach.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCoedgeSetUserData(LtNwcCoedge coedge,
                       LtInt32 data);

//////////////////////////////////////////////////
// Loop
//////////////////////////////////////////////////

/**
 * B-rep loop types
 */
typedef enum LtNwcLoopType__tag {
   LI_NWC_LOOP_AUTO,      /** Type automatically determined (default) */
   LI_NWC_LOOP_BOUNDARY,  /** Loop represents a boundary */
   LI_NWC_LOOP_HOLE,      /** Loop represents a hole */
} LtNwcLoopType;

/**
 * Create a loop of coedges
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcLoop LI_NWC_API
LiNwcLoopCreate();

/**
 * Add a coedge to the loop
 *
 * \param loop loop to add coedge to
 * \param coedge coedge to add
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoopAddCoedge(LtNwcLoop loop,
                   LtNwcCoedge coedge);

/**
 * Destroy an loop
 *
 * \param loop loop to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoopDestroy(LtNwcLoop loop);

/**
 * Sets the type of a loop
 *
 * \param loop loop to set type of
 * \param type type of loop
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoopSetType(LtNwcLoop loop,
                 LtNwcLoopType type);

/**
 * Sets the user data field on the loop.
 *
 * \param loop loop to set data on
 * \param data data to attach.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoopSetUserData(LtNwcLoop loop,
                     LtInt32 data);

//////////////////////////////////////////////////
// Face
//////////////////////////////////////////////////

/**
 * Create a face
 *
 * \param surface surface of face
 * \param sense sense of face with respect to the surface
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcFace LI_NWC_API
LiNwcFaceCreate(LtNwcSurface surface,
                LtNwcSense sense);

/**
 * Add a loop to a face.
 *
 * \param face face to add loop to
 * \param loop loop to add
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFaceAddLoop(LtNwcFace face,
                 LtNwcLoop loop);

/**
 * Adds a trimming curve from a polyline in parameter space
 * to the face.
 *
 * Internally will create an additional loop on the face.
 *
 * \param face face to add trimming curve to.
 * \param num_pnts number of points in polyline.
 * \param pnts points of the polyline. Must be a closed curve.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFaceAddPolylineTrimCurve(LtNwcFace face,
                              LtInt32 num_pnts,
                              LtPoint2d *pnts);

/**
 * Destroy a face
 *
 * \param face face to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFaceDestroy(LtNwcFace face);

/**
 * Sets the user data field on the face.
 *
 * \param face face to set data on
 * \param data data to attach.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcFaceSetUserData(LtNwcFace face,
                     LtInt32 data);

//////////////////////////////////////////////////
// Shell
//////////////////////////////////////////////////

/**
 * Create a shell
 *
 * \version 4.0
 */
LI_NWC_PUBLIC LtNwcShell LI_NWC_API
LiNwcShellCreate();

/**
 * Add a face to a shell
 *
 * \param shell shell to add face to
 * \param face face to add
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcShellAddFace(LtNwcShell shell,
                  LtNwcFace face);

/**
 * Destroy a shell
 *
 * \param shell shell to destroy
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcShellDestroy(LtNwcShell shell);

/**
 * Sets the user data field on the shell.
 *
 * \param shell shell to set data on
 * \param data data to attach.
 * \version 4.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcShellSetUserData(LtNwcShell shell,
                      LtInt32 data);

//////////////////////////////////////////////////
// Solid
//////////////////////////////////////////////////

/**
 * Create a solid
 *
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcSolid LI_NWC_API
LiNwcSolidCreate();

/**
 * Add a shell to a solid
 *
 * \param solid solid to add shell to
 * \param shell shell to add
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSolidAddShell(LtNwcSolid solid,
                   LtNwcShell shell);

/**
 * Get the number of shells in a solid
 *
 * \param solid solid to query
 * \return Number of shells in the solid
 * \version 5.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcSolidGetNumShells(LtNwcSolid solid);

/**
 * Destroy a solid
 *
 * \param solid solid to destroy
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSolidDestroy(LtNwcSolid solid);

//////////////////////////////////////////////////
// Body
//////////////////////////////////////////////////

/**
 * Create a body
 *
 * \version 8.0
 */
LI_NWC_PUBLIC LtNwcBody LI_NWC_API
LiNwcBodyCreate();

/**
 * Add a solid to a body
 *
 * \param body body to add entity to
 * \param solid solid to add
 * \version 8.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBodyAddSolid(LtNwcBody body,
                  LtNwcSolid solid);

/**
 * Destroy a body
 *
 * \param body body to destroy
 * \version 8.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcBodyDestroy(LtNwcBody body);

//////////////////////////////////////////////////
// Compound
//////////////////////////////////////////////////

/**
 * Create a compound
 *
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcCompound LI_NWC_API
LiNwcCompoundCreate();

/**
 * Add an entity to a compound
 *
 * \param compound compound to add entity to
 * \param entity entity to add
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCompoundAddEntity(LtNwcCompound compound,
                       LtNwcBRepEntity entity);

/**
 * Get the number of entities in a compound
 *
 * \param compound compound to query
 * \return Number of shells in the compound
 * \version 5.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcCompoundGetNumEntities(LtNwcCompound compound);

/**
 * Destroy a compound
 *
 * \param compound compound to destroy
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcCompoundDestroy(LtNwcCompound compound);

#ifdef __cplusplus
}

//////////////////////////////////////////////////
// BRepEntity
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepEntity API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcBRepEntity
{
public:
   LcNwcBRepEntity(LtNwcBRepEntity handle) : m_handle(LiNwcBRepEntityCreateRef(handle)) {}

   ~LcNwcBRepEntity() { LiNwcBRepEntityDestroy(m_handle); }

   LcNwcBRepEntity(const LcNwcBRepEntity &other) : m_handle(LiNwcBRepEntityCreateRef(other)) {}

   LcNwcBRepEntity& operator = (const LcNwcBRepEntity &other)
   { LiNwcBRepEntityDestroy(m_handle); m_handle = LiNwcBRepEntityCreateRef(other); return *this; }

   operator LtNwcBRepEntity () const { return m_handle; }
   LtNwcBRepEntity GetHandle() const { return m_handle; }

   LtNwcBRepEntityType GetType() const
   { return LiNwcBRepEntityGetType(m_handle); }

   void SetUserData(LtInt32 data)
   { LiNwcBRepEntitySetUserData(m_handle, data); }

   LcNwcBRepEntity Copy() const
   { return LcNwcBRepEntity(LiNwcBRepEntityCreateCopy(m_handle), true); }

   void Transform(LtNwcTransform transform)
   { LiNwcBRepEntityTransform(m_handle, transform); }

   void Translate(LtFloat x,
                  LtFloat y,
                  LtFloat z)
   { LiNwcBRepEntityTranslate(m_handle, x, y, z); }

   void Translate(LtVector v)
   { LiNwcBRepEntityTranslate(m_handle, v[0], v[1], v[2]); }

protected:
   LcNwcBRepEntity(LtNwcBRepEntity handle, bool /*own*/)
      : m_handle(handle) {}

private:

   LtNwcBRepEntity m_handle;
};

//////////////////////////////////////////////////
// Vertex
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcVertex API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcVertex : public LcNwcBRepEntity
{
public:
   LcNwcVertex(LtPoint pnt)
      : LcNwcBRepEntity(LiNwcVertexCreate(pnt), true) {}
   LcNwcVertex(LtNwcVertex handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcVertex () const
   { return static_cast<LtNwcVertex>(LcNwcBRepEntity::GetHandle()); }
   LtNwcVertex GetHandle() const
   { return static_cast<LtNwcVertex>(LcNwcBRepEntity::GetHandle()); }
};

//////////////////////////////////////////////////
// Edge
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcEdge API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcEdge : public LcNwcBRepEntity
{
public:
   LcNwcEdge(LtNwcCurve curve, LtNwcCoedge coedge, LtNwcSense sense)
      : LcNwcBRepEntity(LiNwcEdgeCreate(curve, coedge, sense), true) {}
   LcNwcEdge(LtNwcEdge handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcEdge () const
   { return static_cast<LtNwcEdge>(LcNwcBRepEntity::GetHandle()); }
   LtNwcEdge GetHandle() const
   { return static_cast<LtNwcEdge>(LcNwcBRepEntity::GetHandle()); }

   void SetCoedge(LtNwcCoedge coedge)
   { LiNwcEdgeSetCoedge(GetHandle(), coedge); }
};

//////////////////////////////////////////////////
// Coedge
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcCoedge API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcCoedge : public LcNwcBRepEntity
{
public:
   LcNwcCoedge(LtNwcCurve2d curve, LtNwcEdge edge, LtNwcVertex vertex, LtNwcSense sense)
      : LcNwcBRepEntity(LiNwcCoedgeCreate(curve, edge, vertex, sense), true) {}
   LcNwcCoedge(LtNwcCoedge handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcCoedge () const
   { return static_cast<LtNwcCoedge>(LcNwcBRepEntity::GetHandle()); }
   LtNwcCoedge GetHandle() const
   { return static_cast<LtNwcCoedge>(LcNwcBRepEntity::GetHandle()); }

   void Link(LtNwcCoedge other)
   { LiNwcCoedgeLink(GetHandle(), other); }
};

//////////////////////////////////////////////////
// Loop
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBRepProfileBuilder API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcBRepProfileBuilder;

/**
 * C++ wrapper around LtNwcLoop API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcLoop : public LcNwcBRepEntity
{
public:
   LcNwcLoop()
      : LcNwcBRepEntity(LiNwcLoopCreate(), true) {}
   LcNwcLoop(LtNwcLoop handle)
      : LcNwcBRepEntity(handle) {}
   LcNwcLoop(LcNwcBRepProfileBuilder &builder);

   operator LtNwcLoop () const
   { return static_cast<LtNwcLoop>(LcNwcBRepEntity::GetHandle()); }
   LtNwcLoop GetHandle() const
   { return static_cast<LtNwcLoop>(LcNwcBRepEntity::GetHandle()); }

   void AddCoedge(LtNwcCoedge coedge)
   { LiNwcLoopAddCoedge(GetHandle(), coedge); }

   void SetType(LtNwcLoopType type)
   { LiNwcLoopSetType(GetHandle(), type); }
};

//////////////////////////////////////////////////
// Face
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcFace API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcFace : public LcNwcBRepEntity
{
public:
   LcNwcFace(LtNwcSurface surface, LtNwcSense sense)
      : LcNwcBRepEntity(LiNwcFaceCreate(surface, sense), true) {}
   LcNwcFace(LtNwcFace handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcFace () const
   { return static_cast<LtNwcFace>(LcNwcBRepEntity::GetHandle()); }
   LtNwcFace GetHandle() const
   { return static_cast<LtNwcFace>(LcNwcBRepEntity::GetHandle()); }

   void AddLoop(LtNwcLoop loop)
   { LiNwcFaceAddLoop(GetHandle(), loop); }
};

//////////////////////////////////////////////////
// Shell
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcShell API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcShell : public LcNwcBRepEntity
{
public:
   LcNwcShell()
      : LcNwcBRepEntity(LiNwcShellCreate(), true) {}
   LcNwcShell(LtNwcShell handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcShell () const
   { return static_cast<LtNwcShell>(LcNwcBRepEntity::GetHandle()); }
   LtNwcShell GetHandle() const
   { return static_cast<LtNwcShell>(LcNwcBRepEntity::GetHandle()); }

   void AddFace(LtNwcFace face)
   { LiNwcShellAddFace(GetHandle(), face); }
};

//////////////////////////////////////////////////
// Solid
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcSolid API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcSolid : public LcNwcBRepEntity
{
public:
   LcNwcSolid()
      : LcNwcBRepEntity(LiNwcSolidCreate(), true) {}
   LcNwcSolid(LtNwcSolid handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcSolid () const
   { return static_cast<LtNwcSolid>(LcNwcBRepEntity::GetHandle()); }
   LtNwcSolid GetHandle() const
   { return static_cast<LtNwcSolid>(LcNwcBRepEntity::GetHandle()); }

   void AddShell(LtNwcShell shell)
   { LiNwcSolidAddShell(GetHandle(), shell); }

   LtInt32 GetNumShells() const
   { return LiNwcSolidGetNumShells(GetHandle()); }
};

//////////////////////////////////////////////////
// Body
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcBody API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcBody : public LcNwcBRepEntity
{
public:
   LcNwcBody()
      : LcNwcBRepEntity(LiNwcBodyCreate(), true) {}
   LcNwcBody(LtNwcBody handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcBody () const
   { return static_cast<LtNwcBody>(LcNwcBRepEntity::GetHandle()); }
   LtNwcBody GetHandle() const
   { return static_cast<LtNwcBody>(LcNwcBRepEntity::GetHandle()); }

   void AddSolid(LtNwcSolid solid)
   { LiNwcBodyAddSolid(GetHandle(), solid); }
};

//////////////////////////////////////////////////
// Compound
//////////////////////////////////////////////////

/**
 * C++ wrapper around LtNwcCompound API calls
 *
 * \see LiNwcTopology.h
 */
class LcNwcCompound : public LcNwcBRepEntity
{
public:
   LcNwcCompound()
      : LcNwcBRepEntity(LiNwcCompoundCreate(), true) {}
   LcNwcCompound(LtNwcCompound handle)
      : LcNwcBRepEntity(handle) {}

   operator LtNwcCompound () const
   { return static_cast<LtNwcCompound>(LcNwcBRepEntity::GetHandle()); }
   LtNwcCompound GetHandle() const
   { return static_cast<LtNwcCompound>(LcNwcBRepEntity::GetHandle()); }

   void AddEntity(LtNwcBRepEntity entity)
   { LiNwcCompoundAddEntity(GetHandle(), entity); }

   LtInt32 GetNumEntities() const
   { return LiNwcCompoundGetNumEntities(GetHandle()); }
};

#endif

#endif /* LINWCTOPOLOGY_HDR */
