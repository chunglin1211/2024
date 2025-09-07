/**
 * \file
 *
 * A node that stores geometric data (e.g. triangles) that defines
 * the shapes that make up the model. Geometric data is defined for the
 * node using a Geometry Stream (LtNwcGeometryStream) protocol. The geometric
 * data can be defined either when the geometry object is created or on
 * demand via a callback. The latter option is preferred as it gives
 * NavisWorks more flexibility in making best use of resources during
 * creation of the NavisWorks model.
 */

/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2001-2002
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCGEOMETRY_HDR
#define LINWCGEOMETRY_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcNode.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a NavisWorks geometry node
 *
 * \return Newly created Geometry or NULL on error
 */
LI_NWC_PUBLIC LtNwcGeometry LI_NWC_API
LiNwcGeometryCreate();

/**
 * Called when geometric data in geometry node needs to be described.
 *
 * \param geometry Geometry node for which definition of geometric data required
 * \param stream Geometry stream to which geometry should be described
 * \param user_data Data passed over when geometry callback set
 * \return false to cancel the operation.
 */
typedef bool LI_NWC_API
LtNwcGeometryCallback(LtNwcGeometry geometry,
                      LtNwcGeometryStream stream,
                      void* user_data);

/**
 * Set a callback function to define the geometric data stored in the node.
 * The callback will be called when NavisWorks needs to know the geometric
 * data stored in the node (typically within LtNwcSceneWrite).
 *
 * \param geometry Node for which to set callback
 * \param cb Callback function
 * \param user_data Data passed to callback when invoked
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometrySetCallback(LtNwcGeometry geometry, LtNwcGeometryCallback* cb,
                         void* user_data);

/**
 * Open a NavisWorks geometry stream to define the geometric data that will
 * be stored in a geometry node. Only one geometry stream can be open for
 * a geometry node at any time. Provided as an alternative to the callback
 * based method.
 *
 * \param geometry Geometry node in which to store geometric data
 * \return Newly opened geometry stream or NULL on error
 */
LI_NWC_PUBLIC LtNwcGeometryStream LI_NWC_API
LiNwcGeometryOpenStream(LtNwcGeometry geometry);

/**
 * Close an open geometry stream. Completes the definition of data to be stored
 * in the geometry node. Once closed, the stream handle is no longer valid.
 *
 * \param geometry Geometry to close stream for
 * \param stream Stream to close. Must have been opened on given geometry.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryCloseStream(LtNwcGeometry geometry, LtNwcGeometryStream stream);

/**
 * Open a NavisWorks 2D stream to define the geometric data that will
 * be stored in a geometry node. Only one 2D stream can be open for
 * a geometry node at any time.
 *
 * Set draw order for plot stream. Within plot stream, primitives are in traversal order.
 * If there are several plot streams having the same draw order, they remain in traversal order of scene graph.
 * The default draw order for this is 0.
 *
 * \param geometry Geometry node in which to store 2D geometric data
 * \param draw_order Order to set
 * \return Newly opened 2D stream or NULL on error
 */
LI_NWC_PUBLIC LtNwcPlotStream LI_NWC_API
LiNwcGeometryOpenPlotStream( LtNwcGeometry geometry, LtNat32 draw_order );

/**
 * Close an open 2D geometry stream. Completes the definition of data to be stored
 * in the geometry node. Once closed, the stream handle is no longer valid.
 *
 * \param geometry Geometry to close stream for
 * \param stream 2D stream to close. Must have been opened on given geometry.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryClosePlotStream( LtNwcGeometry geometry, LtNwcPlotStream stream );

/**
 * Destroy a NavisWorks geometry node
 *
 * \param geometry Geometry to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryDestroy(LtNwcGeometry geometry);

/**
 * Test a node handle to see if its actually a geometry.
 *
 * \param node Node whose type is to be tested
 * \return true if node is a geometry, false otherwise.
 * \version 3.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcGeometryIsA(LtNwcNode node);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcGeometry API calls
 *
 * \see LiNwcGeometry.h
 */
class LcNwcGeometry : public LcNwcNode
{
public:
   LcNwcGeometry() : LcNwcNode(LiNwcGeometryCreate(), true) {}
   LcNwcGeometry(LtNwcGeometry handle) : LcNwcNode(handle) {}

   operator LtNwcGeometry () const
   { return static_cast<LtNwcGeometry>(LcNwcNode::GetHandle()); }
   LtNwcGeometry GetHandle() const
   { return static_cast<LtNwcGeometry>(LcNwcNode::GetHandle()); }

   void SetCallback(LtNwcGeometryCallback* cb, void* user_data)
   { LiNwcGeometrySetCallback(GetHandle(), cb, user_data); }

   LtNwcGeometryStream OpenStream()
   { return LiNwcGeometryOpenStream(GetHandle()); }

   void CloseStream(LtNwcGeometryStream stream)
   { LiNwcGeometryCloseStream(GetHandle(), stream); }

   LtNwcPlotStream OpenPlotStream(LtNat32 draw_order = 0)
   { return LiNwcGeometryOpenPlotStream(GetHandle(), draw_order); }

   void ClosePlotStream(LtNwcPlotStream stream)
   { LiNwcGeometryClosePlotStream(GetHandle(), stream); }

};

#endif

#endif /* LINWCGEOMETRY_HDR */
