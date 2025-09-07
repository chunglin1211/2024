/**
 * \file
 *
 * A protocol for defining geometry data. Used to specify the data stored
 * in a geometry node (LtNwcGeometry).
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

#ifndef LINWCGEOMETRYSTREAM_HDR
#define LINWCGEOMETRYSTREAM_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Only used if no normals supplied with geometry.
 * \param stream Stream of geometry being defined
 * \param angle Angle (in radians) below which smooth normals are generated at shared vertices. Default: 0.5 (about 30 degrees)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCreaseAngle(LtNwcGeometryStream stream,
                               LtFloat angle);

/**
 * Geometry is automatically marked as solid if it forms one (or more) complete
 * manifold shells. Solids are typically rendered single sided.
 * Pass false to force all geometry to be treated as non-solids.
 * Default: true
 * \param stream Stream of geometry being defined
 * \param enable Enable/Disable optimization
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamMakeSolidsSingleSided(LtNwcGeometryStream stream,
                                         bool enable);

/**
 * Scale to apply to runtime priority.
 *
 * \param stream Stream of geometry being defined
 * \param scale Scale dictates changes to runtime priority.  Scales < 1 increase priority, scales > 1 decrease priority.  Default: 1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamPriorityScale(LtNwcGeometryStream stream,
                                 LtFloat scale);

/**
 * Flags that describe shape being defined by geometry stream.
 * The eTWO_SIDED flag is ignored for NavisWorks 4 and later. All geometry
 * is treated as two sided unless its solid.
 */
typedef enum LtNwcShapeFlags__tag {
   eTWO_SIDED           = 0x02,  // Need to render both sides
   eNORMALIZE           = 0x04,  // Normals sent to GL need normalizing
   eREVERSED            = 0x10,  // Geometry is reversed (CW orientation)
} LtNwcShapeFlags;

/**
 * Set flags that describe shape being defined by geometry stream.
 * Each flag that's set reduces performance and should be avoided if
 * possible.
 * Default: 0
 * \param stream Stream of geometry being defined
 * \param flags flags to describe shape.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamShapeFlags(LtNwcGeometryStream stream,
                              LtNwcShapeFlags flags);

/**
 * Will attempt to split geometry into manifold fragments when size
 * is greater than threshold.
 * Default: 100
 * \param stream Stream of geometry being defined
 * \param t Size threshold
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSplitThreshold(LtNwcGeometryStream stream,
                                  LtInt32 t);

/**
 * Will attempt to split geometry into fragments using a simple spatial
 * split when size is greater than threshold. Applied after any manifold
 * split.
 * Default: 500
 * \param stream Stream of geometry being defined
 * \param t Size threshold
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSpatialSplitThreshold(LtNwcGeometryStream stream,
                                         LtInt32 t);

/**
 * Will attempt to merge geometry fragments when size is less than
 * threshold.
 * Default: 25
 * \param stream Stream of geometry being defined
 * \param t Size threshold
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamMergeThreshold(LtNwcGeometryStream stream,
                                  LtInt32 t);

/**
 * OBSOLETE: Does nothing
 * If geometry coordinates are further than this distance from the origin
 * will recenter geometry about the origin and store with an offset to
 * actual location. This improves precision of data.
 * Default: 0 in NavisWorks 4, 1000 in NavisWorks 3 and earlier
 * \param stream Stream of geometry being defined
 * \param dist Distance from origin threshold for recentering geometry
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamRecenterThreshold(LtNwcGeometryStream stream,
                                     LtFloat dist);

/**
 * Scale independent control of surface faceting. Double factor to double
 * level of detail, halve to halve it. Default value is just enough to
 * generate smooth normals for a sphere using default crease angle.
 * If 0, not used.
 * \param stream Stream of geometry being defined
 * \param factor Factor (default 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamFacetingFactor(LtNwcGeometryStream stream, LtFloat factor);

/**
 * Absolute control of surface faceting. Maximum deviation allowed from
 * true surface. If 0, not used.
 * \param stream Stream of geometry being defined
 * \param tol Max deviation (default 0)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamMaxFacetDeviation(LtNwcGeometryStream stream, LtFloat tol);

/**
 * By default all facets lie on the interior of the surface boundary
 * (e.g. inside circle or cylinder). If true all facets will lie outside
 * boundary.
 * \param stream Stream of geometry being defined
 * \param b Enable/Disable exterior faceting
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamExteriorFaceting(LtNwcGeometryStream stream, bool b);

/**
 * If no normals are supplied geometry is automatically reoriented so that
 * triangles have the same orientation as their neighbours with generated
 * normals facing outward.
 * Pass false to generate normals based on the original orientation of
 * triangles.
 * \param stream Stream of geometry being defined
 * \param enable Enable/Disable automatic reorientation of triangles
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCorrectGenNormalOrientation(LtNwcGeometryStream stream,
                                               bool enable);

/**
 * If normals have been supplied, but there is a possibility that some of
 * then are reversed, set this true to check the normals and regenerate
 * them if some are reversed with respect to triangle winding.
 *
 * This flag has no effect if normals are not supplied.
 * \param stream Stream of geometry being defined
 * \param enable Enable/Disable automatic normal testing and correction
 * \version 5.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCorrectVertexNormalOrientation(LtNwcGeometryStream stream,
                                                  bool enable);

/**
 * Geometry described using the indexed vertex methods is assumed to use
 * the same index for all shared vertices. Pass true if multiple indices
 * can be aliases of the same vertex.
 * \param stream Stream of geometry being defined
 * \param enable Enable/Disable multiple indexing of vertexes
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamIndexedVertexAliases(LtNwcGeometryStream stream,
                                        bool enable);

/**
 * Push current transform onto stack
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamPushTransform(LtNwcGeometryStream stream);

/**
 * Set a transform which will be applied to all geometry
 * that's sent.
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSetTransformIdentity(LtNwcGeometryStream stream);

/**
 * Set a transform which will be applied to all geometry
 * that's sent.
 * \param stream Stream of geometry being defined
 * \param x x coordinate of translation
 * \param y y coordinate of translation
 * \param z z coordinate of translation
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSetTransformTranslation(LtNwcGeometryStream stream,
                                           LtFloat x,
                                           LtFloat y,
                                           LtFloat z);
/**
 * Set a transform which will be applied to all geometry
 * that's sent.
 * \param stream Stream of geometry being defined
 * \param matrix matrix of translation
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSetTransform(LtNwcGeometryStream stream,
                                LtFloat matrix[16]);

/**
 * Pre-multiply (MultLeft) with current transform. Combined with
 * PushTransform() and PopTransform() allows specification of geometric
 * parts in a nested hierarchy of transformation spaces.
 * \param stream Stream of geometry being defined
 * \param x x coordinate of translation
 * \param y y coordinate of translation
 * \param z z coordinate of translation
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamMultTransformTranslation(LtNwcGeometryStream stream,
                                            LtFloat x,
                                            LtFloat y,
                                            LtFloat z);

/**
 * Pre-multiply (MultLeft) with current transform. Combined with
 * PushTransform() and PopTransform() allows specification of geometric
 * parts in a nested hierarchy of transformation spaces.
 * \param stream Stream of geometry being defined
 * \param matrix matrix of translation
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamMultTransform(LtNwcGeometryStream stream,
                                LtFloat matrix[16]);

/**
 * Pop current transform from stack
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamPopTransform(LtNwcGeometryStream stream);

/**
 * Add external geometry to the stream
 * \param stream Stream of geometry being defined
 * \param geometry External geometry to add
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamExternalGeometry(LtNwcGeometryStream stream, LtNwcExternalGeometry geometry);

/**
 * What additional per vertex properties should be stored for each vertex
 */
typedef enum LtNwcVertexProperty__tag {
   LI_NWC_VERTEX_NONE      = 0x0,  /** No extra vertex properties */
   LI_NWC_VERTEX_NORMAL    = 0x1,  /** Normals */
   LI_NWC_VERTEX_COLOR     = 0x2,  /** Colors */
   LI_NWC_VERTEX_TEX_COORD = 0x4,  /** Texture Coordinates */
} LtNwcVertexProperty;

/**
 * Start defining a piece of geometry which has the given vertex properties
 * defined by ORing (|) together LtNwcVertexProperty values.
 * \param stream Stream of geometry being defined
 * \param vertex_properties Bitfield of LtNwcVertexProperty values
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamBegin(LtNwcGeometryStream stream,
                         LtBitfield vertex_properties);

/**
 * Send within Begin/End BEFORE corresponding vertex is sent.
 * \param stream Stream of geometry being defined
 * \param r Red component of color
 * \param g Green component of color
 * \param b Blue component of color
 * \param a Alpha component of color.  (Range 0 to 1, 0 is transparent, 1 is opaque)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamColor(LtNwcGeometryStream stream,
                         LtFloat r,
                         LtFloat g,
                         LtFloat b,
                         LtFloat a);


/**
 * Send within Begin/End BEFORE corresponding vertex is sent.
 * \param stream Stream of geometry being defined
 * \param x x coordinate of normal
 * \param y y coordinate of normal
 * \param z z coordinate of normal
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamNormal(LtNwcGeometryStream stream,
                         LtFloat x,
                         LtFloat y,
                         LtFloat z);

/**
 * Send within Begin/End BEFORE corresponding vertex is sent.
 * \param stream Stream of geometry being defined
 * \param x x coordinate
 * \param y y coordinate
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTexCoord(LtNwcGeometryStream stream,
                            LtFloat x,
                            LtFloat y);

/**
 * Add a vertex to be indexed. Returns the index to use (starts at 0
 * and increments). Vertices specified in this way can be reused
 * multiple times in calls to LiNwcGeometryStreamTriangleIndex,
 * LiNwcGeometryStreamTriStripIndex, LiNwcGeometryStreamTriFanIndex,
 * LiNwcGeometryStreamConvexPolyIndex, LiNwcGeometryStreamPolygonIndex.
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcGeometryStreamIndexedVertex(LtNwcGeometryStream stream,
                                 LtFloat x,
                                 LtFloat y,
                                 LtFloat z);

/**
 * Send one vertex of a triangle. Repeat 3 times to define a triangle.
 * \param stream Stream of geometry being defined
 * \param x X coordinate of vertex
 * \param y Y coordinate of vertex
 * \param z Z coordinate of vertex
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTriangleVertex(LtNwcGeometryStream stream,
                                  LtFloat x,
                                  LtFloat y,
                                  LtFloat z);

/**
 * Triangles: Defined by 3 triangle vertices
 * \param stream Stream of geometry being defined
 * \param index Index of triangle being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTriangleIndex(LtNwcGeometryStream stream,
                                 LtInt32 index);

/**
 * Triangle Strip: Defined by 3 or more vertices followed
 * by a SeqEnd().
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTriStripVertex(LtNwcGeometryStream stream,
                                  LtFloat x,
                                  LtFloat y,
                                  LtFloat z);

/**
 * Triangle Strip: Defined by 3 or more vertices followed
 * by a SeqEnd().
 * \param stream Stream of geometry being defined
 * \param index Index of triangle strip
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTriStripIndex(LtNwcGeometryStream stream,
                                 LtInt32 index);

/**
 * Triangle Fan: Defined by 3 or more vertices followed
 * by a SeqEnd().
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTriFanVertex(LtNwcGeometryStream stream,
                                LtFloat x,
                                LtFloat y,
                                LtFloat z);

/**
 * Triangle Fan: Defined by 3 or more vertices followed
 * by a SeqEnd().
 * \param stream Stream of geometry being defined
 * \param index Index of triangle fan
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTriFanIndex(LtNwcGeometryStream stream,
                               LtInt32 index);

/**
 * Convex Polygon: Defined by 3 or more vertices followed by
 * a SeqEnd().
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamConvexPolyVertex(LtNwcGeometryStream stream,
                                    LtFloat x,
                                    LtFloat y,
                                    LtFloat z);

/**
 * Convex Polygon: Defined by 3 or more vertices followed by
 * a SeqEnd().
 * \param stream Stream of geometry being defined
 * \param index Index of convex polygon
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamConvexPolyIndex(LtNwcGeometryStream stream,
                                   LtInt32 index);

/**
 * End current multi-vertex sequence. Ends definition of primitive
 * defined by LiNwcGeometryStreamConvexPolyVertex,
 * LiNwcGeometryStreamConvexPolyIndex, LiNwcGeometryStreamTriFanVertex,
 * LiNwcGeometryStreamTriFanIndex, LiNwcGeometryStreamTriStripVertex,
 * LiNwcGeometryStreamTriStripIndex,
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSeqEnd(LtNwcGeometryStream stream);

/**
 * Start defining complex polygons, possibly self intersecting, arbitrary
 * order of vertices, possibly with holes. Polygon is described as a
 * series of contours.
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamBeginPolygon(LtNwcGeometryStream stream);

/**
 * Start defining polygon contour.
 * Must be called between LiNwcGeometryStreamBeginPolygon and
 * LiNwcGeometryStreamEndPolygon.
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamBeginPolygonContour(LtNwcGeometryStream stream);

/**
 * Define a vertex of the current polygon contour
 * Must be called between LiNwcGeometryStreamBeginPolygonContour and
 * LiNwcGeometryStreamEndPolygonContour.
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamPolygonVertex(LtNwcGeometryStream stream,
                                 LtFloat x,
                                 LtFloat y,
                                 LtFloat z);

/**
 * Define a vertex of the current polygon contour
 * Must be called between LiNwcGeometryStreamBeginPolygonContour and
 * LiNwcGeometryStreamEndPolygonContour.
 * \param stream Stream of geometry being defined
 * \param index Index of vertex
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamPolygonIndex(LtNwcGeometryStream stream,
                                LtInt32 index);

/**
 * Define an elliptical arc within the current polygon contour.
 * Must be called between LiNwcGeometryStreamBeginPolygonContour and
 * LiNwcGeometryStreamEndPolygonContour.
 *
 * The orientation of
 * the ellipse is specified by vectors that define the major and minor
 * axes of the ellipse. The two vectors should be perpendicular to each
 * other. The ellipse is oriented so that the cross product of major
 * and minor defines the normal of the ellipse. The lengths of the
 * vectors define the major and minor radii of the ellipse.
 *
 * If start_ang and end_ang are not equal, an elliptical sector is
 * defined. An angle of 0 corresponds to a point on the major axis,
 * an angle of PI/2 corresponds to a point on the minor axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center of ellipse
 * \param major Major axis of ellipse
 * \param minor Minor axis of ellipse
 * \param start_ang Start angle of elliptical sector in radians
 * \param end_ang End angle of elliptical sector in radians
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamPolygonEllipse(LtNwcGeometryStream stream,
                                  LtPoint center,
                                  LtVector major, LtVector minor,
                                  LtFloat start_ang, LtFloat end_ang);

/**
 * Finish defining polygon contour.
 * Must be called between LiNwcGeometryStreamBeginPolygon and
 * LiNwcGeometryStreamEndPolygon.
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEndPolygonContour(LtNwcGeometryStream stream);

/**
 * Finish defining polygon.
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEndPolygon(LtNwcGeometryStream stream);

/**
 * Explicitly declare radius to use as a basis for facetting. The radius
 * is combined with facetting factor to determine the level of facetting
 * to use. If not set explicitly the first primitive sent to the stream
 * will determine the radius for all subsequent primitives until
 * LiNwcGeometryStreamFacetEnd() is called.
 * \param stream Stream of geometry being defined
 * \param radius Radius to use as basis for required level of facetting
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamFacetRadius(LtNwcGeometryStream stream, LtFloat radius);

/**
 * Compute the number of steps that a circle of a given radius would be
 * faceted to.
 *
 * \param stream Stream of geometry being defined
 * \param radius Radius of circle.
 * \return number of steps
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcGeometryStreamGetNumCirclePts(LtNwcGeometryStream stream, LtFloat radius);

/**
 * Defines a filled circle
 *
 * \param stream Stream of geometry being defined
 * \param center Center of circle
 * \param normal Vector perpendicular to plane in which circle lies. Defines orientation of circle. For a circle on the XY plane, use { 0, 0, 1 }.
 * \param radius Radius of circle
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCircle(LtNwcGeometryStream stream, LtPoint center,
                          LtUnitVector normal, LtFloat radius);

/**
 * Defines a filled circle based on three points on the perimeter
 * of the circle. If the points are colinear the circle is ignored.
 *
 * \param stream Stream of geometry being defined
 * \param pt1 Point on perimeter of circle
 * \param pt2 Point on perimeter of circle
 * \param pt3 Point on perimeter of circle
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCircle3Point(LtNwcGeometryStream stream,
                                LtPoint pt1, LtPoint pt2, LtPoint pt3);

/**
 * Defines a filled ellipse or elliptical sector. The orientation of
 * the ellipse is specified by vectors that define the major and minor
 * axes of the ellipse. The two vectors should be perpendicular to each
 * other. The ellipse is oriented so that the cross product of major
 * and minor defines the normal of the ellipse. The lengths of the
 * vectors define the major and minor radii of the ellipse.
 *
 * If start_ang and end_ang are not equal, an elliptical sector is
 * defined. An angle of 0 corresponds to a point on the major axis,
 * an angle of PI/2 corresponds to a point on the minor axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center of ellipse
 * \param major Major axis of ellipse
 * \param minor Minor axis of ellipse
 * \param start_ang Start angle of elliptical sector in radians
 * \param end_ang End angle of elliptical sector in radians
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEllipse(LtNwcGeometryStream stream, LtPoint center,
                           LtVector major, LtVector minor,
                           LtFloat start_ang, LtFloat end_ang);

/**
 * Defines a elliptical curve. The orientation of
 * the ellipse is specified by vectors that define the major and minor
 * axes of the ellipse. The two vectors should be perpendicular to each
 * other. The ellipse is oriented so that the cross product of major
 * and minor defines the normal of the ellipse. The lengths of the
 * vectors define the major and minor radii of the ellipse.
 *
 * If start_ang and end_ang are not equal, an elliptical sector is
 * defined. An angle of 0 corresponds to a point on the major axis,
 * an angle of PI/2 corresponds to a point on the minor axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center of ellipse
 * \param major Major axis of ellipse
 * \param minor Minor axis of ellipse
 * \param start_ang Start angle of elliptical sector in radians
 * \param end_ang End angle of elliptical sector in radians
 * \version 5.4
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEllipseCurve(LtNwcGeometryStream stream,
                                LtPoint center,
                                LtVector major,
                                LtVector minor,
                                LtFloat start_ang,
                                LtFloat end_ang);

/**
 * Defines a cylindrical surface. The end caps of the cylinder are not
 * included. Use LiNwcGeometryStreamCircle to define end caps if
 * required. The cylinder is oriented so that normals face outwards. Use
 * LiNwcGeometryStreamConic if inwards facing normals are required.
 *
 * \param stream Stream of geometry being defined
 * \param pt1 End point of cylinder on central axis
 * \param pt2 Other end point of cylinder on central axis
 * \param radius Radius of circle
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCylinder(LtNwcGeometryStream stream, LtPoint pt1,
                            LtPoint pt2, LtFloat radius);

/**
 * Defines a conic surface or surface section. The surface can be
 * thought of as the generalisation of a cylinder. The surface is
 * defined by two ellipses which lie at each end in the same way that
 * a cylinder is defined by two circles. These end caps are
 * not included. Use LiNwcGeometryStreamEllipse
 * to define end caps if required.
 *
 * The orientation of
 * each ellipse is specified by vectors that define the major and minor
 * axes of the ellipses. Each pair of vectors should be perpendicular to each
 * other.  The lengths of the vectors define the major and minor radii
 * of each ellipse. The surface is oriented so that normals face
 * outwards if the vectors major1, minor1 and pt2-pt1 form a right
 * handed coordinate system.
 *
 * Commonly the major and minor axes of each ellipse will use the same
 * directions and will be perpendicular to the central axis of the
 * surface defined by pt2-pt1. Rotations of the axes can produce special
 * effects such as twisted surfaces and sheared edges.
 *
 * If start_ang and end_ang are not equal, a section of the complete
 * surface is defined. An angle of 0 corresponds to a point on the
 * major axis of each ellipse. an angle of PI/2 corresponds to a point
 * on the minor axis of each ellipse.
 *
 * \param stream Stream of geometry being defined
 * \param pt1 Center point of ellipse defining one end of surface
 * \param major1 Major axis of ellipse defining one end of surface
 * \param minor1 Minor axis of ellipse defining one end of surface
 * \param pt2 Center point of ellipse defining other end of surface
 * \param major2 Major axis of ellipse defining other end of surface
 * \param minor2 Minor axis of ellipse defining other end of surface
 * \param start_ang Start angle of elliptical sector in radians
 * \param end_ang End angle of elliptical sector in radians
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamConic(LtNwcGeometryStream stream, LtPoint pt1,
                         LtVector major1, LtVector minor1,
                         LtPoint pt2, LtVector major2, LtVector minor2,
                         LtFloat start_ang, LtFloat end_ang);

/**
 * Defines a cuboid. Defined as a volume between two opposite points.
 * To get the normals facing out, pt1 should hold the lower bound
 * on all three axes, and pt2 the upper.
 *
 * \param stream Stream of geometry being defined
 * \param pt1 First point of cuboid
 * \param pt2 Second point of cuboid
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCuboid(LtNwcGeometryStream stream,
                          LtPoint pt1,
                          LtPoint pt2);

/**
 * Defines a sphere. The main axis will be along the Y axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center point of sphere
 * \param radius Radius of sphere
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSphere(LtNwcGeometryStream stream,
                          LtPoint center,
                          LtFloat radius);

/**
 * Defines a partial ellipsoid. The main axis will be along the Y axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center point of sphere
 * \param x_axis X-axis od ellipsoid
 * \param y_axis Y-axis od ellipsoid
 * \param z_axis Z-axis od ellipsoid
 * \param latitude_min latitude to start at (+/- Pi/2)
 * \param latitude_max latitude to end at (+/- Pi/2)
 * \param longitude_min longitude to start at
 * \param longitude_max longitude to end at
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEllipsoidSection(LtNwcGeometryStream stream,
                                    LtPoint center,
                                    LtVector x_axis,
                                    LtVector y_axis,
                                    LtVector z_axis,
                                    LtFloat latitude_min,
                                    LtFloat latitude_max,
                                    LtFloat longitude_min,
                                    LtFloat longitude_max);

/**
 * Defines an ellipsoid. The main axis will be along the Y axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center point of sphere
 * \param x_axis X-axis od ellipsoid
 * \param y_axis Y-axis od ellipsoid
 * \param z_axis Z-axis od ellipsoid
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEllipsoid(LtNwcGeometryStream stream,
                                    LtPoint center,
                                    LtVector x_axis,
                                    LtVector y_axis,
                                    LtVector z_axis);

/**
 * Defines a partial torus. The axis will be along the Z axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center point of torus
 * \param x_axis X-axis of torus
 * \param y_axis Y-axis of torus
 * \param major_radius major radius of torus
 * \param minor_radius minor radius of torus
 * \param phi_min phi to start at (+/- Pi/2)
 * \param phi_max phi to end at (+/- Pi/2)
 * \param longitude_min longitude to start at
 * \param longitude_max longitude to end at
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTorusSection(LtNwcGeometryStream stream,
                                LtPoint center,
                                LtVector x_axis,
                                LtVector y_axis,
                                LtFloat major_radius,
                                LtFloat minor_radius,
                                LtFloat phi_min,
                                LtFloat phi_max,
                                LtFloat longitude_min,
                                LtFloat longitude_max);

/**
 * Defines a torus. The axis will be along the Z axis.
 *
 * \param stream Stream of geometry being defined
 * \param center Center point of torus
 * \param x_axis X-axis of torus
 * \param y_axis Y-axis of torus
 * \param major_radius major radius of torus
 * \param minor_radius minor radius of torus
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamTorus(LtNwcGeometryStream stream,
                         LtPoint center,
                         LtVector x_axis,
                         LtVector y_axis,
                         LtFloat major_radius,
                         LtFloat minor_radius);

/**
 * Adds a line vertex to be indexed. Returns the index to use (starts
 * at 0 and increments).
 *
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 * \version 3.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcGeometryStreamIndexedLineVertex(LtNwcGeometryStream stream,
                                     LtFloat x,
                                     LtFloat y,
                                     LtFloat z);

/**
 * Defines a vertex to be used for a line.
 *
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamLineVertex(LtNwcGeometryStream stream,
                              LtFloat x,
                              LtFloat y,
                              LtFloat z);

/**
 * Defines an indexed vertex to be used for a line.
 *
 * \param stream Stream of geometry being defined
 * \param index Index of vertex
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamLineIndex(LtNwcGeometryStream stream,
                             LtInt32 index);

/**
 * Defines a vertex to be used for a line strip.
 *
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamLineStripVertex(LtNwcGeometryStream stream,
                                   LtFloat x,
                                   LtFloat y,
                                   LtFloat z);

/**
 * Defines an indexed vertex to be used as part of a line strip.
 *
 * \param stream Stream of geometry being defined
 * \param index Index of vertex
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamLineStripIndex(LtNwcGeometryStream stream,
                                  LtInt32 index);

/**
 * Adds a point into the scene.
 *
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamPoint(LtNwcGeometryStream stream,
                         LtFloat x,
                         LtFloat y,
                         LtFloat z);

/**
 * Adds a snap point into the scene.
 *
 * \param stream Stream of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamSnapPoint(LtNwcGeometryStream stream,
                             LtFloat x,
                             LtFloat y,
                             LtFloat z);

/**
 * Draws a 3D curve.
 *
 * \param stream Stream of geometry being defined
 * \param curve curve to draw. Must be a bounded curve
 * \version 5.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCurve(LtNwcGeometryStream stream,
                         LtNwcCurve curve);

/**
 * Draws a 3D curve segment.
 *
 * \param stream Stream of geometry being defined
 * \param curve curve to draw
 * \param start start parameter of segment
 * \param end end parameter of segment
 * \version 5.1
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCurveSegment(LtNwcGeometryStream stream,
                                LtNwcCurve curve,
                                LtFloat start,
                                LtFloat end);

/**
 * Used to mark the end of a group of facetted primitives which must
 * be facetted compatibly. The same level of facetting must be used for
 * all surfaces which join together.
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamFacetEnd(LtNwcGeometryStream stream);

/**
 * End current definition, started by LiNwcGeometryStreamBegin.
 * \param stream Stream of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEnd(LtNwcGeometryStream stream);

/**
 * Sets the coordinate tolerance. If two coordinates are equal
 * to this tolerance, they are considered to be the same point.
 * \param stream Stream of geometry being defined
 * \param tolerance Tolerance to use for coordinate comparisons.
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamCoordTolerance(LtNwcGeometryStream stream, LtFloat tolerance);

/**
 * Enables or disabled automatic creation of parametric primitives. If
 * enabled, the stream will try to generate parametric primitives where
 * possible. By default, this is enabled.
 *
 * \param stream Stream of geometry being defined
 * \param enable Flag to control parametric primitive generation.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamGenerateParametrics(LtNwcGeometryStream stream,
                                       bool enable);

/**
 * Facets a BRep shell.
 *
 * \param stream Stream of geometry being defined
 * \param shell shell to facet.
 * \version 5.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcGeometryStreamBRepShell(LtNwcGeometryStream stream,
                             LtNwcShell shell);

/**
 * Facets a BRep entity.
 *
 * \param stream Stream of geometry being defined
 * \param entity topological entity to facet
 * \version 5.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcGeometryStreamBRepEntity(LtNwcGeometryStream stream,
                              LtNwcBRepEntity entity);

/**
 * Returns the name of the faceter used for the last B-rep.
 *
 * \param stream Stream handle
 * \version 5.0
 */
LI_NWC_PUBLIC const char* LI_NWC_API
LiNwcGeometryStreamBRepFaceterName(LtNwcGeometryStream stream);

/**
 * Returns the number of faces that failes to facet
 * for the last B-rep.
 *
 * \param stream Stream handle
 * \version 5.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcGeometryStreamBRepNumFailedFaces(LtNwcGeometryStream stream);

/**
 * Begins text input to a stream.
 *
 * \param stream Stream handle
 * \param style Text style to use. Once you have called this function, you should not modify style.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamBeginText(LtNwcGeometryStream stream,
                             LtNwcTextStyle style);

/**
 * Adds text to a geometry stream.
 *
 * \param stream Stream handle
 * \param text Text to add
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamAddText(LtNwcGeometryStream stream,
                           LtWideString text);

/**
 * Ends text input to a stream.
 *
 * \param stream Stream handle
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeometryStreamEndText(LtNwcGeometryStream stream);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcGeometryStream API calls
 *
 * \see LiNwcGeometryStream.h
 */
class LcNwcGeometryStream
{
public:
   LcNwcGeometryStream(LtNwcGeometryStream handle)
      : m_handle(handle) {}

   operator LtNwcGeometryStream () const
   { return static_cast<LtNwcGeometryStream>(m_handle); }
   LtNwcGeometryStream GetHandle() const
   { return static_cast<LtNwcGeometryStream>(m_handle); }

   void CreaseAngle(LtFloat angle)
   { LiNwcGeometryStreamCreaseAngle(m_handle, angle); }

   void MakeSolidsSingleSided(bool enable)
   { LiNwcGeometryStreamMakeSolidsSingleSided(m_handle, enable); }

   void PriorityScale(LtFloat scale)
   { LiNwcGeometryStreamPriorityScale(m_handle, scale); }

   void ShapeFlags(LtNwcShapeFlags flags)
   { LiNwcGeometryStreamShapeFlags(m_handle, flags); }

   void SplitThreshold(LtInt32 t)
   { LiNwcGeometryStreamSplitThreshold(m_handle, t); }

   void SpatialSplitThreshold(LtInt32 t)
   { LiNwcGeometryStreamSpatialSplitThreshold(m_handle, t); }

   void MergeThreshold(LtInt32 t)
   { LiNwcGeometryStreamMergeThreshold(m_handle, t); }

   void RecenterThreshold(LtFloat dist)
   { LiNwcGeometryStreamRecenterThreshold(m_handle, dist); }

   void FacetingFactor(LtFloat factor)
   { LiNwcGeometryStreamFacetingFactor(m_handle, factor); }

   void MaxFacetDeviation(LtFloat tol)
   { LiNwcGeometryStreamMaxFacetDeviation(m_handle, tol); }

   void ExteriorFaceting(bool b)
   { LiNwcGeometryStreamExteriorFaceting(m_handle, b); }

   void CorrectGenNormalOrientation(bool enable)
   { LiNwcGeometryStreamCorrectGenNormalOrientation(m_handle, enable); }

   void CorrectVertexNormalOrientation(bool enable)
   { LiNwcGeometryStreamCorrectVertexNormalOrientation(m_handle, enable); }

   void IndexedVertexAliases(bool enable)
   { LiNwcGeometryStreamIndexedVertexAliases(m_handle, enable); }

   void PushTransform()
   { LiNwcGeometryStreamPushTransform(m_handle); }

   void SetTransformIdentity()
   { LiNwcGeometryStreamSetTransformIdentity(m_handle); }

   void SetTransformTranslation(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamSetTransformTranslation(m_handle, x, y, z); }

   void SetTransformTranslation(const LtVector v)
   { LiNwcGeometryStreamSetTransformTranslation(m_handle, v[0], v[1], v[2]); }

   void SetTransform(LtFloat matrix[16])
   { LiNwcGeometryStreamSetTransform(m_handle, matrix); }

   void MultTransformTranslation(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamMultTransformTranslation(m_handle, x, y, z); }

   void MultTransformTranslation(const LtVector v)
   { LiNwcGeometryStreamMultTransformTranslation(m_handle, v[0], v[1], v[2]); }

   void MultTransform(LtFloat matrix[16])
   { LiNwcGeometryStreamMultTransform(m_handle, matrix); }

   void PopTransform()
   { LiNwcGeometryStreamPopTransform(m_handle); }

   void ExternalGeometry(LtNwcExternalGeometry geometry)
   { LiNwcGeometryStreamExternalGeometry(m_handle, geometry); }

   void Begin(LtBitfield vertex_properties)
   { LiNwcGeometryStreamBegin(m_handle, vertex_properties); }

   void Color(LtFloat r, LtFloat g, LtFloat b, LtFloat a)
   { LiNwcGeometryStreamColor(m_handle, r, g, b, a); }

   void Normal(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamNormal(m_handle, x, y, z); }

   void Normal(const LtVector v)
   { LiNwcGeometryStreamNormal(m_handle, v[0], v[1], v[2]); }

   void TexCoord(LtFloat x, LtFloat y)
   {  LiNwcGeometryStreamTexCoord(m_handle, x, y); }

   LtInt32 IndexedVertex(LtFloat x, LtFloat y, LtFloat z)
   { return LiNwcGeometryStreamIndexedVertex(m_handle, x, y, z); }

   LtInt32 IndexedVertex(const LtPoint p)
   { return LiNwcGeometryStreamIndexedVertex(m_handle, p[0], p[1], p[2]); }

   void TriangleVertex(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamTriangleVertex(m_handle, x, y, z); }

   void TriangleVertex(const LtPoint p)
   { LiNwcGeometryStreamTriangleVertex(m_handle, p[0], p[1], p[2]); }

   void TriangleIndex(LtInt32 index)
   { LiNwcGeometryStreamTriangleIndex(m_handle, index); }

   void TriStripVertex(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamTriStripVertex(m_handle, x, y, z); }

   void TriStripVertex(const LtPoint p)
   { LiNwcGeometryStreamTriStripVertex(m_handle, p[0], p[1], p[2]); }

   void TriStripIndex(LtInt32 index)
   { LiNwcGeometryStreamTriStripIndex(m_handle, index); }

   void TriFanVertex(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamTriFanVertex(m_handle, x, y, z); }

   void TriFanVertex(const LtPoint p)
   { LiNwcGeometryStreamTriFanVertex(m_handle, p[0], p[1], p[2]); }

   void TriFanIndex(LtInt32 index)
   { LiNwcGeometryStreamTriFanIndex(m_handle, index); }

   void ConvexPolyVertex(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamConvexPolyVertex(m_handle, x, y, z); }

   void ConvexPolyVertex(const LtPoint p)
   { LiNwcGeometryStreamConvexPolyVertex(m_handle, p[0], p[1], p[2]); }

   void ConvexPolyIndex(LtInt32 index)
   { LiNwcGeometryStreamConvexPolyIndex(m_handle, index); }

   void SeqEnd()
   { LiNwcGeometryStreamSeqEnd(m_handle); }

   void BeginPolygon()
   { LiNwcGeometryStreamBeginPolygon(m_handle); }

   void BeginPolygonContour()
   { LiNwcGeometryStreamBeginPolygonContour(m_handle); }

   void PolygonVertex(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamPolygonVertex(m_handle, x, y, z); }

   void PolygonVertex(const LtPoint p)
   { LiNwcGeometryStreamPolygonVertex(m_handle, p[0], p[1], p[2]); }

   void PolygonIndex(LtInt32 index)
   { LiNwcGeometryStreamPolygonIndex(m_handle, index); }

   void PolygonEllipse(LtPoint center, LtVector major,
                LtVector minor, LtFloat start_ang=0, LtFloat end_ang=0)
   { LiNwcGeometryStreamPolygonEllipse(m_handle, center, major, minor, start_ang, end_ang); }

   void EndPolygonContour()
   { LiNwcGeometryStreamEndPolygonContour(m_handle); }

   void EndPolygon()
   { LiNwcGeometryStreamEndPolygon(m_handle); }

   void FacetRadius(LtFloat radius)
   { LiNwcGeometryStreamFacetRadius(m_handle, radius); }

   LtInt32 GetNumCirclePts(LtFloat radius)
   { return LiNwcGeometryStreamGetNumCirclePts(m_handle, radius); }

   void Circle(LtPoint center, LtUnitVector normal, LtFloat radius)
   { LiNwcGeometryStreamCircle(m_handle, center, normal, radius); }

   void Circle3Point(LtPoint pt1, LtPoint pt2, LtPoint pt3)
   { LiNwcGeometryStreamCircle3Point(m_handle, pt1, pt2, pt3); }

   void Ellipse(LtPoint center, LtVector major,
                LtVector minor, LtFloat start_ang=0, LtFloat end_ang=0)
   { LiNwcGeometryStreamEllipse(m_handle, center, major, minor, start_ang, end_ang); }

   void EllipseCurve(LtPoint center, LtVector major,
                     LtVector minor, LtFloat start_ang=0, LtFloat end_ang=0)
   { LiNwcGeometryStreamEllipseCurve(m_handle, center, major, minor, start_ang, end_ang); }

   void Cylinder(LtPoint pt1, LtPoint pt2, LtFloat radius)
   { LiNwcGeometryStreamCylinder(m_handle, pt1, pt2, radius); }

   void Conic(LtPoint pt1, LtVector major1, LtVector minor1,
              LtPoint pt2, LtVector major2, LtVector minor2,
              LtFloat start_ang=0, LtFloat end_ang=0)
   { LiNwcGeometryStreamConic(m_handle, pt1, major1, minor1, pt2,
        major2, minor2, start_ang, end_ang); }

   void Cuboid(LtPoint pt1, LtPoint pt2)
   { LiNwcGeometryStreamCuboid(m_handle, pt1, pt2); }

   void Sphere(LtPoint pt, LtFloat radius)
   { LiNwcGeometryStreamSphere(m_handle, pt, radius); }

   void EllipsoidSection(LtPoint center,
                         LtVector x_axis,
                         LtVector y_axis,
                         LtVector z_axis,
                         LtFloat latitude_min,
                         LtFloat latitude_max,
                         LtFloat longitude_min,
                         LtFloat longitude_max)
   { LiNwcGeometryStreamEllipsoidSection(m_handle, center, x_axis, y_axis, z_axis,
         latitude_min, latitude_max, longitude_min, longitude_max); }

   void Ellipsoid(LtPoint center,
                  LtVector x_axis,
                  LtVector y_axis,
                  LtVector z_axis)
   { LiNwcGeometryStreamEllipsoid(m_handle, center, x_axis, y_axis, z_axis); }

   void TorusSection(LtPoint center,
                     LtVector x_axis,
                     LtVector y_axis,
                     LtFloat major_radius,
                     LtFloat minor_radius,
                     LtFloat phi_min,
                     LtFloat phi_max,
                     LtFloat longitude_min,
                     LtFloat longitude_max)
   { LiNwcGeometryStreamTorusSection(m_handle, center, x_axis, y_axis,
         major_radius, minor_radius, phi_min, phi_max, longitude_min, longitude_max); }

   void Torus(LtPoint center,
              LtVector x_axis,
              LtVector y_axis,
              LtFloat major_radius,
              LtFloat minor_radius)
   { LiNwcGeometryStreamTorus(m_handle, center, x_axis, y_axis,
         major_radius, minor_radius); }

   LtInt32 IndexedLineVertex(LtFloat x, LtFloat y, LtFloat z)
   { return LiNwcGeometryStreamIndexedLineVertex(m_handle, x, y, z); }

   LtInt32 IndexedLineVertex(const LtPoint p)
   { return LiNwcGeometryStreamIndexedLineVertex(m_handle, p[0], p[1], p[2]); }

   void LineVertex(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamLineVertex(m_handle, x, y, z); }

   void LineVertex(const LtPoint p)
   { LiNwcGeometryStreamLineVertex(m_handle, p[0], p[1], p[2]); }

   void LineIndex(LtInt32 index)
   { LiNwcGeometryStreamLineIndex(m_handle, index); }

   void LineStripVertex(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamLineStripVertex(m_handle, x, y, z); }

   void LineStripVertex(const LtPoint p)
   { LiNwcGeometryStreamLineStripVertex(m_handle, p[0], p[1], p[2]); }

   void LineStripIndex(LtInt32 index)
   { LiNwcGeometryStreamLineStripIndex(m_handle, index); }

   void Point(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamPoint(m_handle, x, y, z); }

   void Point(const LtPoint p)
   { LiNwcGeometryStreamPoint(m_handle, p[0], p[1], p[2]); }

   void SnapPoint(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcGeometryStreamSnapPoint(m_handle, x, y, z); }

   void SnapPoint(const LtPoint p)
   { LiNwcGeometryStreamSnapPoint(m_handle, p[0], p[1], p[2]); }

   void Curve(LtNwcCurve curve)
   { LiNwcGeometryStreamCurve(m_handle, curve); }

   void CurveSegment(LtNwcCurve curve, LtFloat start, LtFloat end)
   { LiNwcGeometryStreamCurveSegment(m_handle, curve, start, end); }

   void FacetEnd()
   { LiNwcGeometryStreamFacetEnd(m_handle); }

   void End()
   { LiNwcGeometryStreamEnd(m_handle); }

   void CoordTolerance(LtFloat tolerance)
   { LiNwcGeometryStreamCoordTolerance(m_handle, tolerance); }

   void GenerateParametrics(bool enable)
   { LiNwcGeometryStreamGenerateParametrics(m_handle, enable); }

   LtInt32 BRepShell(LtNwcShell shell)
   { return LiNwcGeometryStreamBRepShell(m_handle, shell); }

   LtInt32 BRepEntity(LtNwcBRepEntity entity)
   { return LiNwcGeometryStreamBRepEntity(m_handle, entity); }

   const char* BRepFaceterName()
   { return LiNwcGeometryStreamBRepFaceterName(m_handle); }

   LtInt32 BRepNumFailedFaces()
   { return LiNwcGeometryStreamBRepNumFailedFaces(m_handle); }

   void BeginText(LtNwcTextStyle style)
   { LiNwcGeometryStreamBeginText(m_handle, style); }

   void AddText(LtWideString text)
   { LiNwcGeometryStreamAddText(m_handle, text); }

   void EndText()
   { LiNwcGeometryStreamEndText(m_handle); }

private:
   LtNwcGeometryStream m_handle;
};

#endif

#endif /* LINWCGEOMETRY_HDR */
