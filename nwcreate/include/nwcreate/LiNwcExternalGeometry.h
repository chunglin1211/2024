/**
 * \file
 *
 * Geometry whose content is provided by a link to an
 * external source of data.
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

#ifndef LINWCEXTERNALGEOMETRY_HDR
#define LINWCEXTERNALGEOMETRY_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a NavisWorks external geometry
 *
 * \return Newly created external geometry or NULL on error
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcExternalGeometry LI_NWC_API
LiNwcExternalGeometryCreate();

/**
 * Set the name of the file loader (base name of .dll and .cfg) that implements
 * the external link that will supply content for the geometry.
 *
 * \param geometry External geometry to set file loader for
 * \param file_loader The name of the file loader
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetFileLoader(LtNwcExternalGeometry geometry, LtString file_loader);

/**
 * Get the name of the file loader that implements
 * the external link that will supply content for the geometry.
 *
 * \param geometry External geometry to get file loader for
 * \return The name of the file loader
 * \version 9.0
 */
LI_NWC_PUBLIC LtString LI_NWC_API
LiNwcExternalGeometryGetFileLoader(LtNwcExternalGeometry geometry);

/**
 * Set the name of the external link that will supply content for the geometry.
 *
 * \param geometry External geometry to set link name for
 * \param link_name The name of the external link
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetLinkName(LtNwcExternalGeometry geometry, LtString link_name);

/**
 * Get the name of the external link that will supply content for the geometry.
 *
 * \param geometry External geometry to get link name for
 * \return The name of the external link that will supply content for the geometry
 * \version 9.0
 */
LI_NWC_PUBLIC LtString LI_NWC_API
LiNwcExternalGeometryGetLinkName(LtNwcExternalGeometry geometry);

/**
 * Set a uri that specifies the specific content the external link should supply.
 * Interpretation of the Uri is specific to the link being used.
 *
 * \param geometry External geometry to set uri for
 * \param uri The uri that specifies content to be used
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetUri(LtNwcExternalGeometry geometry, LtWideString uri);

/**
 * Get the uri that specifies the specific content the external link should supply.
 * Interpretation of the Uri is specific to the link being used.
 *
 * \param geometry External geometry to get URI for
 * \return The uri that specifies content to be used
 * \version 9.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcExternalGeometryGetUri(LtNwcExternalGeometry geometry);

/**
 * Set user data that should be stored with the geometry. This is typically used by the
 * link creator to store data required by the link callbacks.
 *
 * \param geometry External geometry to set user data for
 * \param user_data The data to store
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetUserData(LtNwcExternalGeometry geometry, void* user_data);

/**
 * Get the user data stored with the geometry.
 *
 * \param geometry External geometry to get user data for
 * \return The user data for the geometry
 * \version 9.0
 */
LI_NWC_PUBLIC void* LI_NWC_API
LiNwcExternalGeometryGetUserData(LtNwcExternalGeometry geometry);

/**
 * Set the additional vertex properties that are defined by this geometry.
 *
 * \param geometry External geometry to set vertex properties for
 * \param vertex_properties Bitfield of LtNwcVertexProperty values
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetVertexProperties(LtNwcExternalGeometry geometry, LtBitfield vertex_properties);

/**
 * Sets the bounding box of the geometry
 *
 * \param geometry External geometry to set bounding box for
 * \param min_point The corner of the box with minimum x,y,z values
 * \param max_point The corner of the box with maximum x,y,z values
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetBoundingBox(LtNwcExternalGeometry geometry, LtPoint min_point, LtPoint max_point);

/**
 * Set the approximate number of primitives (triangles,lines,points) that the
 * external link will supply.
 *
 * \param geometry External geometry to set number of primitives for
 * \param num_primitives Number of primitives
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetNumPrimitives(LtNwcExternalGeometry geometry, LtNat32 num_primitives);

/**
 * What types of primitives may be supplied
 */
typedef enum LtNwcPrimitiveType__tag {
   LI_NWC_PRIMITIVE_TRIANGLES    = 0x0001,  /** Has triangle primitives */
   LI_NWC_PRIMITIVE_LINES        = 0x0002,  /** Has line primitives */
   LI_NWC_PRIMITIVE_POINTS       = 0x0004,  /** Has point primitives */
   LI_NWC_PRIMITIVE_SNAP_POINTS  = 0x0008,  /** Has snap (construction) point primitives */
   LI_NWC_PRIMITIVE_TEXT         = 0x0010,  /** Has text primitives */
} LtNwcPrimitiveType;

/**
 * Set the primitive types that are defined by this geometry.
 *
 * \param geometry External geometry to set primitive types for
 * \param primitive_types Bitfield of LtNwcPrimitiveType values
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometrySetPrimitiveTypes(LtNwcExternalGeometry geometry, LtBitfield primitive_types);

/**
 * Destroy a Navisworks external geometry handle
 *
 * \param geometry External geometry to destroy
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcExternalGeometryDestroy(LtNwcExternalGeometry geometry);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcExternalGeometry API calls
 *
 * \see LiNwcExternalGeometry.h
 */
class LcNwcExternalGeometry
{
public:
   LcNwcExternalGeometry() : m_handle(LiNwcExternalGeometryCreate()), m_own(true) {}
   LcNwcExternalGeometry(LtNwcExternalGeometry handle)
      : m_handle(handle), m_own(false) { }
   ~LcNwcExternalGeometry() {if(m_own) LiNwcExternalGeometryDestroy(m_handle);}

   operator LtNwcExternalGeometry () const { return m_handle; }
   LtNwcExternalGeometry GetHandle() const { return m_handle; }

   void SetFileLoader(LtString file_loader)
   { LiNwcExternalGeometrySetFileLoader(m_handle, file_loader); }

   LtString GetFileLoader() const
   { return LiNwcExternalGeometryGetFileLoader(m_handle); }

   void SetLinkName(LtString link_name)
   { LiNwcExternalGeometrySetLinkName(m_handle, link_name); }

   LtString GetLinkName() const
   { return LiNwcExternalGeometryGetLinkName(m_handle); }

   void SetUri(LtWideString uri)
   { LiNwcExternalGeometrySetUri(m_handle, uri); }

   LtWideString GetUri() const
   { return LiNwcExternalGeometryGetUri(m_handle); }

   void SetUserData(void* user_data)
   {
      LiNwcExternalGeometrySetUserData(m_handle, user_data);
   }

   void* GetUserData() const
   {
      return LiNwcExternalGeometryGetUserData(m_handle);
   }

   void SetVertexProperties(LtBitfield vertex_properties)
   { LiNwcExternalGeometrySetVertexProperties(m_handle, vertex_properties); }

   void SetBoundingBox(LtPoint min_point, LtPoint max_point)
   { LiNwcExternalGeometrySetBoundingBox(m_handle, min_point, max_point); }

   void SetNumPrimitives(LtNat32 num_primitives)
   { LiNwcExternalGeometrySetNumPrimitives(m_handle, num_primitives); }

   void SetPrimitiveTypes(LtBitfield primitive_types)
   { LiNwcExternalGeometrySetPrimitiveTypes(m_handle, primitive_types); }

private:
   // Can't copy
   LcNwcExternalGeometry(const LcNwcExternalGeometry &);
   LcNwcExternalGeometry& operator= (const LcNwcExternalGeometry &);

   LtNwcExternalGeometry m_handle;
   bool m_own;
};

#endif /*__cplusplus*/

#endif /* LINWCEXTERNALGEOMETRY_HDR */
