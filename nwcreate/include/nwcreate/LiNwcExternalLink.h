/**
 * \file
 *
 * Represents a link to an external geometry source.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2010 Autodesk, Inc.  All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 *
 *
 */

#ifndef LINWCEXTERNALLINK_HDR
#define LINWCEXTERNALLINK_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcExternalGeometry.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a NavisWorks external link
 *
 * \return Newly created external geometry or NULL on error
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcExternalLink LI_NWC_API
LiNwcExternalLinkCreate();

/**
 * Set the name of the link. The name is used to find the correct link to use for ExternalGeometry.
 *
 * \param link External link to set name for
 * \param name The name of the external link
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetName(LtNwcExternalLink link, LtString name);

/**
 * Set user data that should be stored with the link. This is typically used by the
 * link creator to store data required by the link callbacks.
 *
 * \param link External link to set user data for
 * \param user_data The data to store
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetUserData(LtNwcExternalLink link, void* user_data);

/**
 * Get the user data stored with the link.
 *
 * \param link External link to get user data for
 * \return The user data for the link
 * \version 9.0
 */
LI_NWC_PUBLIC void* LI_NWC_API
LiNwcExternalLinkGetUserData(LtNwcExternalLink link);

/**
 * Callback function invoked when external geometry is connected with an external link.
 * Will be called before any other callbacks are called for geometry.
 *
 * \param link Link callback is being invoked on
 * \param geom External geometry callback us being invoked for
 * \version 9.0
 */
typedef void LI_NWC_API
LtNwcExternalLinkConnectCallback(LtNwcExternalLink link,
                                 LtNwcExternalGeometry geom);

/**
 * Set connect callback function. This callback is optional.
 *
 * \param link Link to set connect callback for
 * \param cb callback function
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetConnectCallback(LtNwcExternalLink link,
                                    LtNwcExternalLinkConnectCallback* cb);

/**
 * Callback function invoked for external link to clear any cached data associated
 * with an external geometry instance.
 *
 * \param link Link callback is being invoked on
 * \param geom External geometry callback us being invoked for
 * \version 11.0
 */
typedef void LI_NWC_API
LtNwcExternalLinkClearCachedDataCallback(LtNwcExternalLink link,
                                         LtNwcExternalGeometry geom);

/**
 * Set clear cached data callback function. This callback is optional.
 *
 * \param link Link to set clear cached data callback for
 * \param cb callback function
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetClearCachedDataCallback(LtNwcExternalLink link,
                                    LtNwcExternalLinkClearCachedDataCallback* cb);

/**
 * Callback function invoked for external link to generate primitives defined by
 * an external geometry instance. Used for Clash Detection, Photorealistic rendering,
 * default implementation of rendering and picking if no Render or Pick callback is supplied.
 *
 * \param link Link callback is being invoked on
 * \param geom External geometry callback us being invoked for
 * \param context Context to pass generated primitives to
 * \return true if link supports generating primitives
 * \version 9.0
 */
typedef bool LI_NWC_API
LtNwcExternalLinkGeneratePrimitivesCallback(LtNwcExternalLink link,
                        LtNwcExternalGeometry geom,
                        LtNwcGeneratePrimitivesContext context);

/**
 * Set generate primitives callback function. This callback is optional. If the callback is not
 * supplied or returns false, no primitives will be passed to Clash Detection or Photorealistic rendering.
 * If Render and Pick callbacks are also not supplied, proxy graphics will be used.
 * If the callback is supplied, it will be called when primitives are required.
 *
 * \param link Link to set generate primitives callback for
 * \param cb callback function
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetGeneratePrimitivesCallback(LtNwcExternalLink link,
                                      LtNwcExternalLinkGeneratePrimitivesCallback* cb);

/**
 * Callback function invoked for external link to render content defined by
 * an external geometry instance.
 *
 * \param link Link callback is being invoked on
 * \param geom External geometry callback us being invoked for
 * \param context Context to render primitives with
 * \return true if link supports rendering primitives
 * \version 9.0
 */
typedef bool LI_NWC_API
LtNwcExternalLinkRenderCallback(LtNwcExternalLink link,
                        LtNwcExternalGeometry geom,
                        LtNwcRenderContext context);

/**
 * Set render callback function. This callback is optional. If the callback is not
 * supplied or returns false, the generate primitives callback will be used to supply content to render.
 *
 * \param link Link to set render callback for
 * \param cb callback function
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetRenderCallback(LtNwcExternalLink link,
                                      LtNwcExternalLinkRenderCallback* cb);

/**
 * Callback function invoked for external link to pick content defined by
 * an external geometry instance.
 *
 * \param link Link callback is being invoked on
 * \param geom External geometry callback us being invoked for
 * \param context Context to pick primitives with
 * \return true if link supports picking primitives
 * \version 9.0
 */
typedef bool LI_NWC_API
LtNwcExternalLinkPickCallback(LtNwcExternalLink link,
                        LtNwcExternalGeometry geom,
                        LtNwcPickContext context);

/**
 * Set pick callback function. This callback is optional. If the callback is not
 * supplied or returns false, the generate primitives callback will be used to supply content to pick.
 *
 * \param link Link to set render callback for
 * \param cb callback function
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetPickCallback(LtNwcExternalLink link,
                                 LtNwcExternalLinkPickCallback* cb);

/**
 * Callback function invoked when external geometry is disconnected from an external link.
 * Will be called after any other callbacks are called for geometry.
 *
 * \param link Link callback is being invoked on
 * \param geom External geometry callback us being invoked for
 * \version 9.0
 */
typedef void LI_NWC_API
LtNwcExternalLinkDisconnectCallback(LtNwcExternalLink link,
                                    LtNwcExternalGeometry geom);

/**
 * Set disconnect callback function. This callback is optional.
 *
 * \param link Link to set connect callback for
 * \param cb callback function
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetDisconnectCallback(LtNwcExternalLink link,
                                       LtNwcExternalLinkDisconnectCallback* cb);

/**
 * Callback function invoked after external geometry has been deserialized. Gives
 * link the chance to upgrade (replace) with another geometry representation.
 *
 * \param link Link callback is being invoked on
 * \param geom External geometry callback is being invoked for
 * \version 12.0
 */
typedef LtNwcExternalGeometry LI_NWC_API
LtNwcExternalLinkUpgradeCallback(LtNwcExternalLink link,
                                 LtNwcExternalGeometry geom,
                                 LtNwcUpgradeContext context);

/**
 * Set upgrade callback function. This callback is optional.
 *
 * \param link Link to set upgrade callback for
 * \param cb callback function
 * \version 12.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkSetUpgradeCallback(LtNwcExternalLink link,
                                    LtNwcExternalLinkUpgradeCallback* cb);

/**
 * Destroy a Navisworks external link handle
 *
 * \param link External link to destroy
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalLinkDestroy(LtNwcExternalLink link);

/**
 * Get the vertex properties that should be defined for generated primitives
 *
 * \param context Context to get vertex properties from
 * \return Bitfield of LtNwcVertexProperty values
 * \version 9.0
 */
LI_NWC_PUBLIC LtBitfield LI_NWC_API
LiNwcGeneratePrimitivesContextGetVertexProperties(LtNwcGeneratePrimitivesContext context);

/**
 * Get the max deviation from the true surface for generated primitives. A value of 0 means use
 * a reasonable level of accuracy for general purposes.
 * This is a performance hint which can be used to reduce the number of generated primitives.
 *
 * \param context Context to get maximum deviation from
 * \return Maximum deviation
 * \version 11.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcGeneratePrimitivesContextGetMaxDeviation(LtNwcGeneratePrimitivesContext context);

/**
 * Get a region of space to limit the generated primitives to.
 * This is a performance hint which can be used to reduce the number of generated primitives. Any primitives outside
 * the box can be ignored.
 *
 * \param context Context to get limit box from
 * \param min_point Returns the corner of the box with minimum x,y,z values
 * \param max_point Returns the corner of the box with maximum x,y,z values
 * \return false if no limit box has been defined
 * \version 11.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcGeneratePrimitivesContextGetLimitBox(LtNwcGeneratePrimitivesContext context,
   LtPoint min_point, LtPoint max_point);

/**
 * Start defining a set of primitives of the same type.
 * \param context context of geometry being defined
 * \param primitive_type Type of primitive being defined
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeneratePrimitivesContextBegin(LtNwcGeneratePrimitivesContext context,
                        LtNwcPrimitiveType primitive_type);

/**
 * Send within Begin/End BEFORE corresponding vertex is sent.
 * \param context context of geometry being defined
 * \param r Red component of color
 * \param g Green component of color
 * \param b Blue component of color
 * \param a Alpha component of color.  (Range 0 to 1, 0 is transparent, 1 is opaque)
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeneratePrimitivesContextColor(LtNwcGeneratePrimitivesContext context,
                         LtSingle r,
                         LtSingle g,
                         LtSingle b,
                         LtSingle a);


/**
 * Send within Begin/End BEFORE corresponding vertex is sent.
 * \param context context of geometry being defined
 * \param x x coordinate of normal
 * \param y y coordinate of normal
 * \param z z coordinate of normal
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeneratePrimitivesContextNormal(LtNwcGeneratePrimitivesContext context,
                         LtSingle x,
                         LtSingle y,
                         LtSingle z);

/**
 * Send within Begin/End BEFORE corresponding vertex is sent.
 * \param context context of geometry being defined
 * \param x x coordinate
 * \param y y coordinate
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeneratePrimitivesContextTexCoord(LtNwcGeneratePrimitivesContext context,
                            LtSingle x,
                            LtSingle y);

/**
 * Add a point primitive.
 * \param context context of geometry being defined
 * \param x x coordinate of vertex
 * \param y y coordinate of vertex
 * \param z z coordinate of vertex
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeneratePrimitivesContextPoint(LtNwcGeneratePrimitivesContext context,
                                 LtSingle x,
                                 LtSingle y,
                                 LtSingle z);

/**
 * End current definition, started by LiNwcGeneratePrimitivesContextBegin.
 * \param context Context of geometry being defined
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcGeneratePrimitivesContextEnd(LtNwcGeneratePrimitivesContext context);

/**
 * Get the window width being rendered to
 *
 * \param context Context to get width from
 * \return Width of window
 * \version 9.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcRenderContextGetWindowWidth(LtNwcRenderContext context);

/**
 * Get the window height being rendered to
 *
 * \param context Context to get height from
 * \return Height of window
 * \version 9.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcRenderContextGetWindowHeight(LtNwcRenderContext context);

/**
 * Get the transformation matrices being used for rendering. The matrices follow
 * OpenGL rules. The model_view matrix transforms geometric primitives from their
 * local space into the space of a normalized camera (at the origin, looking down -Z, with Y up).
 * The projection matrix transforms points from normalized camera space into clip space where all
 * visible points lies within a -1 to 1 cube.
 *
 * \param context Context to get transformation matrices from
 * \param projection Matrix in which projection transform will be returned
 * \param model_view Matrix in which model view transform will be returned
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcRenderContextGetTransformationMatrices(LtNwcRenderContext context,
                                            LtFloat projection[16],
                                            LtFloat model_view[16]);

/**
 * Draw a set of points with optional rgba colors
 *
 * \param context Context to draw to
 * \param num_points Number of points to draw
 * \param coord_xyz Array of 3 * num_points single precision floats defining coordinates of each point
 * \param color_rgba Array of 4 * num_points bytes defining color of each point, or NULL
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcRenderContextDrawPoints(LtNwcRenderContext context,
                             LtInt32 num_points,
                             LtSingle* coord_xyz,
                             LtNat8* color_rgba);

/**
 * Draw a pre-rendered image directly into the rendered output. The image format and
 * layout follows OpenGL rules.
 *
 * \param context Context to draw to
 * \param x X coordinate of image position within window (lower left corner)
 * \param y Y coordinate of image position within window (lower left corner)
 * \param width Width of image
 * \param height Height of image
 * \param rgba Array of 4 * width * height bytes defining color of each pixel in image, or NULL
 * \param depth Array of width * height single precision floats defining depth of each pixel, or NULL
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcRenderContextDrawImage(LtNwcRenderContext context,
                            LtInt32 x,
                            LtInt32 y,
                            LtInt32 width,
                            LtInt32 height,
                            LtNat8* rgba,
                            LtSingle* depth);

/**
 * Which side of frustum each plane corresponds to
 */
typedef enum LtNwcPickFrustumPlane__tag {
   LI_NWC_PICK_FRUSTUM_PLANE_LEFT,   /** Plane defining left side of pick frustum */
   LI_NWC_PICK_FRUSTUM_PLANE_RIGHT,  /** Plane defining right side of pick frustum */
   LI_NWC_PICK_FRUSTUM_PLANE_TOP,    /** Plane defining top side of pick frustum */
   LI_NWC_PICK_FRUSTUM_PLANE_BOTTOM, /** Plane defining bottom side of pick frustum */
   LI_NWC_PICK_FRUSTUM_PLANE_NEAR,   /** Plane defining near side of pick frustum */
   LI_NWC_PICK_FRUSTUM_PLANE_FAR,    /** Plane defining far side of pick frustum */
} LtNwcPickFrustumPlane;

/**
 * Returns one of the six planes that defines the picking frustum. Any primitives outside
 * (on the side facing away from the normal) of any of the planes can be culled out.
 *
 * \param context Context to use for picking
 * \param plane Which plane to return
 * \param x Returns X coordinate of plane normal
 * \param y Returns Y coordinate of plane normal
 * \param z Returns Z coordinate of plane normal
 * \param d Returns distance of plane along the normal from the origin
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPickContextGetFrustumPlane(LtNwcPickContext context,
                                LtNwcPickFrustumPlane plane,
                                LtFloat* x,
                                LtFloat* y,
                                LtFloat* z,
                                LtFloat* d);

/**
 * Returns the center line of the picking frustum.
 *
 * \param context Context to use for picking
 * \param point Returns a point on the line
 * \param direction Returns a vector in the direction of the line
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPickContextGetFrustumCenterLine(LtNwcPickContext context,
                                     LtPoint point,
                                     LtUnitVector direction);

/**
 * Picks a point. Call with each point in turn. Points outside the picking frustum
 * will be ignored.
 *
 * \param context Context to use for picking
 * \param x x coordinate of point
 * \param y y coordinate of point
 * \param z z coordinate of point
 * \return Returns true if no further primitives need to be picked
 * \version 9.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcPickContextPoint(LtNwcPickContext context,
                      LtSingle x,
                      LtSingle y,
                      LtSingle z);

/**
 * Get the filename of the file that the geometry to be upgraded
 * is being loaded from.
 *
 * \param context Context to get filename from
 * \return Filename
 * \version 12.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcUpgradeContextGetReferFilename(LtNwcUpgradeContext context);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcExternalLink API calls
 *
 * \see LiNwcExternalLink.h
 */
class LcNwcExternalLink
{
public:
   LcNwcExternalLink() : m_handle(LiNwcExternalLinkCreate()), m_own(true) {}
   LcNwcExternalLink(LtNwcExternalLink handle)
      : m_handle(handle), m_own(false) { }
   ~LcNwcExternalLink() {if(m_own) LiNwcExternalLinkDestroy(m_handle);}


   operator LtNwcExternalLink () const { return m_handle; }
   LtNwcExternalLink GetHandle() const { return m_handle; }

   void SetName(LtString name)
   {
      LiNwcExternalLinkSetName(m_handle, name);
   }

   void SetUserData(void* user_data)
   {
      LiNwcExternalLinkSetUserData(m_handle, user_data);
   }

   void* GetUserData() const
   {
      return LiNwcExternalLinkGetUserData(m_handle);
   }

   void SetConnectCallback(LtNwcExternalLinkConnectCallback* cb)
   {
      LiNwcExternalLinkSetConnectCallback(m_handle, cb);
   }

   void SetClearCachedDataCallback(LtNwcExternalLinkClearCachedDataCallback* cb)
   {
      LiNwcExternalLinkSetClearCachedDataCallback(m_handle, cb);
   }

   void SetGeneratePrimitivesCallback(LtNwcExternalLinkGeneratePrimitivesCallback* cb)
   {
      LiNwcExternalLinkSetGeneratePrimitivesCallback(m_handle, cb);
   }

   void SetRenderCallback(LtNwcExternalLinkRenderCallback* cb)
   {
      LiNwcExternalLinkSetRenderCallback(m_handle, cb);
   }

   void SetPickCallback(LtNwcExternalLinkPickCallback* cb)
   {
      LiNwcExternalLinkSetPickCallback(m_handle, cb);
   }

   void SetDisconnectCallback(LtNwcExternalLinkDisconnectCallback* cb)
   {
      LiNwcExternalLinkSetDisconnectCallback(m_handle, cb);
   }

   void SetUpgradeCallback(LtNwcExternalLinkUpgradeCallback* cb)
   {
      LiNwcExternalLinkSetUpgradeCallback(m_handle, cb);
   }

private:
   // Can't copy
   LcNwcExternalLink(const LcNwcExternalLink &);
   LcNwcExternalLink& operator= (const LcNwcExternalLink &);

   LtNwcExternalLink m_handle;
   bool m_own;
};

/**
 * C++ wrapper around LtNwcGeneratePrimitivesContext API calls
 *
 * \see LiNwcExternalLink.h
 */
class LcNwcGeneratePrimitivesContext
{
public:
   LcNwcGeneratePrimitivesContext(LtNwcGeneratePrimitivesContext handle)
      : m_handle(handle) { }

   operator LtNwcGeneratePrimitivesContext () const { return m_handle; }
   LtNwcGeneratePrimitivesContext GetHandle() const { return m_handle; }

   LtBitfield GetVertexProperties()
   {
      return LiNwcGeneratePrimitivesContextGetVertexProperties(m_handle);
   }

   LtFloat GetMaxDeviation() const
   { return LiNwcGeneratePrimitivesContextGetMaxDeviation(m_handle); }

   bool GetLimitBox(LtPoint min_point, LtPoint max_point) const
   { return LiNwcGeneratePrimitivesContextGetLimitBox(m_handle, min_point, max_point); }

   void Begin(LtNwcPrimitiveType primitive_type)
   { LiNwcGeneratePrimitivesContextBegin(m_handle, primitive_type); }

   void Color(LtSingle r, LtSingle g, LtSingle b, LtSingle a)
   { LiNwcGeneratePrimitivesContextColor(m_handle, r, g, b, a); }

   void Normal(LtSingle x, LtSingle y, LtSingle z)
   { LiNwcGeneratePrimitivesContextNormal(m_handle, x, y, z); }

   void TexCoord(LtSingle x, LtSingle y)
   {  LiNwcGeneratePrimitivesContextTexCoord(m_handle, x, y); }

   void Point(LtSingle x, LtSingle y, LtSingle z)
   { LiNwcGeneratePrimitivesContextPoint(m_handle, x, y, z); }

   void End()
   { LiNwcGeneratePrimitivesContextEnd(m_handle); }

private:
   // Can't copy
   LcNwcGeneratePrimitivesContext(const LcNwcGeneratePrimitivesContext &);
   LcNwcGeneratePrimitivesContext& operator= (const LcNwcGeneratePrimitivesContext &);

   LtNwcGeneratePrimitivesContext m_handle;
};

/**
 * C++ wrapper around LtNwcRenderContext API calls
 *
 * \see LiNwcExternalLink.h
 */
class LcNwcRenderContext
{
public:
   LcNwcRenderContext(LtNwcRenderContext handle)
      : m_handle(handle) { }

   operator LtNwcRenderContext () const { return m_handle; }
   LtNwcRenderContext GetHandle() const { return m_handle; }

   LtInt32 GetWindowWidth()
   { return LiNwcRenderContextGetWindowWidth(m_handle); }

   LtInt32 GetWindowHeight()
   { return LiNwcRenderContextGetWindowHeight(m_handle); }

   void GetTransformationMatrices(LtFloat projection[16], LtFloat model_view[16])
   {
      LiNwcRenderContextGetTransformationMatrices(m_handle, projection, model_view);
   }

   void DrawPoints(LtInt32 num_points,
                   LtSingle* coord_xyz,
                   LtNat8* color_rgba)
   {
      LiNwcRenderContextDrawPoints(m_handle,num_points,coord_xyz,color_rgba);
   }

   void DrawImage(LtInt32 x,
                  LtInt32 y,
                  LtInt32 width,
                  LtInt32 height,
                  LtNat8* rgba,
                  LtSingle* depth)
   {
      LiNwcRenderContextDrawImage(m_handle,x,y,width,height,rgba,depth);
   }

private:
   // Can't copy
   LcNwcRenderContext(const LcNwcRenderContext &);
   LcNwcRenderContext& operator= (const LcNwcRenderContext &);

   LtNwcRenderContext m_handle;
};

/**
 * C++ wrapper around LtNwcPickContext API calls
 *
 * \see LiNwcExternalLink.h
 */
class LcNwcPickContext
{
public:
   LcNwcPickContext(LtNwcPickContext handle)
      : m_handle(handle) { }

   operator LtNwcPickContext () const { return m_handle; }
   LtNwcPickContext GetHandle() const { return m_handle; }

   void LI_NWC_API GetFrustumPlane(LtNwcPickFrustumPlane plane,
                                LtFloat* x,
                                LtFloat* y,
                                LtFloat* z,
                                LtFloat* d)
   {
      LiNwcPickContextGetFrustumPlane(m_handle, plane, x, y, z, d);
   }

   void LI_NWC_API GetFrustumCenterLine(LtPoint point,
                                     LtUnitVector direction)
   {
      LiNwcPickContextGetFrustumCenterLine(m_handle, point, direction);
   }

   bool LI_NWC_API Point(LtSingle x, LtSingle y, LtSingle z)
   {
      return LiNwcPickContextPoint(m_handle, x, y, z);
   }

private:
   // Can't copy
   LcNwcPickContext(const LcNwcPickContext &);
   LcNwcPickContext& operator= (const LcNwcPickContext &);

   LtNwcPickContext m_handle;
};

/**
 * C++ wrapper around LtNwcUpgradeContext API calls
 *
 * \see LiNwcExternalLink.h
 */
class LcNwcUpgradeContext
{
public:
   LcNwcUpgradeContext(LtNwcUpgradeContext handle)
      : m_handle(handle) { }

   operator LtNwcUpgradeContext () const { return m_handle; }
   LtNwcUpgradeContext GetHandle() const { return m_handle; }

   LtWideString LI_NWC_API GetReferFilename()
   {
      return LiNwcUpgradeContextGetReferFilename(m_handle);
   }

private:
   // Can't copy
   LcNwcUpgradeContext(const LcNwcUpgradeContext &);
   LcNwcUpgradeContext& operator= (const LcNwcUpgradeContext &);

   LtNwcUpgradeContext m_handle;
};

#endif /*__cplusplus*/

#endif /* LINWCEXTERNALLINK_HDR */
