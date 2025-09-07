//
// Copyright 2010 Autodesk, Inc.  All rights reserved.
//
// This software is provided as part of the NavisWorks SDK.  Use
// of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or 
// which otherwise accompanies this software in either electronic or
// hard copy form.
//
#include <nwcreate/LiNwcAll.h>

#include <windows.h>
#include <stdio.h>
#include <share.h>

#include "PointEngine.h"

// Integration between NWcreate and PointEngine. Contains NWCreate entry point and
// callback implementations.

// Keep track of all connections for our link. 
class LinkData
{
public:
   LinkData() : connection_count(0) {}

   int connection_count;
};

static LinkData* f_link_data = NULL;

// Keep track of runtime data for each external geometry. Each instance of geometry has
// an instance of the PointEngine that generates points.
class GeomData
{
public:
   GeomData() : num_pts(0), engine(NULL) {}
   ~GeomData() { delete engine; }

   LtInt32 num_pts;
   LtPoint min_point;
   LtPoint max_point;
   LtPoint offset;

   PointEngine* engine;
};

// Utilities for reading information in .externalpoints file
static char f_line_buffer[250];

static char*
read_line(FILE* fp)
{
   for (;;)
   {
      char *ret = fgets(f_line_buffer, 250, fp);
      if (!ret)
         return NULL;

      if (ret[0] != '#' && !isspace(ret[0]))
         return ret;
   }
}

static bool
read_point(FILE* fp, LtPoint pt)
{
   char* s = read_line(fp);
   if (!s)
      return false;

   return (::sscanf_s(s, "%lg %lg %lg", &pt[0], &pt[1], &pt[2]) == 3);
}

static bool
read_int(FILE* fp, LtInt32* d)
{
   char* s = read_line(fp);
   if (!s)
      return false;

   return (::sscanf_s(s, "%d", d) == 1);
}

// Does the work needed to make connection to external engine
static LtNwcLoadStatus
connect(LinkData* data, LtNwcExternalGeometry geom)
{
   LcNwcExternalGeometry geomc(geom);

   GeomData* geom_data = static_cast<GeomData*>(geomc.GetUserData());
   if (geom_data)
   {
      // Already connected - must be initial creation, ignore redundant call
      return LI_NWC_LOAD_OK;
   }

   data->connection_count ++;

   if (data->connection_count == 1)
   {
      // Do whatever initialization is needed for external point cloud engine
      PointEngine::Initialise();
   }

   geom_data = new GeomData;
   geomc.SetUserData(geom_data);

   // Make sure file we're linking to is still there
   LcNwcLoader loader(LcNwcLoader::GetInstance(geomc.GetFileLoader()));
   if (!loader.GetHandle())
      return LI_NWC_LOAD_ERROR;
  
   wchar_t path[1024];
   LtNwcXRefStatus status = loader.ResolveXRef(NULL, geomc.GetUri(), TRUE, path);
   if (status != LI_NWC_XREF_OK)
   {
      return (status == LI_NWC_XREF_CANCEL) ? LI_NWC_LOAD_CANCELED : LI_NWC_LOAD_OK;
   }
   
   geomc.SetUri(path);

   FILE* fp = ::_wfsopen(geomc.GetUri(),L"r", _SH_DENYNO);
   if (!fp)
      return LI_NWC_LOAD_CANT_OPEN;

   bool ok = (read_point(fp, geom_data->min_point) &&
              read_point(fp, geom_data->max_point) &&
              read_point(fp, geom_data->offset) &&
              read_int(fp, &geom_data->num_pts));
   ::fclose(fp);

   if (!ok)
      return LI_NWC_LOAD_FILE_CORRUPT;

   geom_data->engine = new PointEngine(geom_data->num_pts, Point(geom_data->min_point), Point(geom_data->max_point));

   return LI_NWC_LOAD_OK;
}

// Called by Navisworks when ExternalGeometry object is loaded/created
static void LI_NWC_API
connect_cb(LtNwcExternalLink link,
           LtNwcExternalGeometry geom)
{
   LinkData* data = static_cast<LinkData*>(LiNwcExternalLinkGetUserData(link));
   connect(data, geom);
}

// Does the work needed to shutdown connection with server
static void
disconnect(LinkData* data,
           LtNwcExternalGeometry geom)
{
   GeomData* geom_data = static_cast<GeomData*>(LiNwcExternalGeometryGetUserData(geom));
   delete geom_data;

   data->connection_count --;

   if (data->connection_count == 0)
   {
      // Shutdown external point cloud engine
      PointEngine::Terminate();
   }
}

// Called by Navisworks when ExternalGeometry object is destroyed
static void LI_NWC_API
disconnect_cb(LtNwcExternalLink link,
              LtNwcExternalGeometry geom)
{
   LinkData* data = static_cast<LinkData*>(LiNwcExternalLinkGetUserData(link));
   disconnect(data, geom);
}

// Interfaces PointEngine with GeneratePrimitivesContext
class GenerateVisitor : public PointEngineVisitor
{
public:
   GenerateVisitor(LtNwcGeneratePrimitivesContext ctx) : m_ctx(ctx) {}

   virtual void Points(int num, const Point* points, const unsigned char* rgba)
   {
      for (LtInt32 i = 0; i < num; i ++)
      {
         const unsigned char* col = rgba+4*i;
         m_ctx.Color(float(col[0])/255, float(col[1])/255, float(col[2])/255, float(col[3])/255);
         const Point& p = points[i];
         m_ctx.Point(p[0], p[1], p[2]);
      }
   }

   LcNwcGeneratePrimitivesContext m_ctx;
};

// Called by Navisworks to generate points for non-performance critical, general purposes.
// Used by Clash Detective
static LtBoolean LI_NWC_API
generate_primitives_cb(LtNwcExternalLink link,
                        LtNwcExternalGeometry geom,
                        LtNwcGeneratePrimitivesContext context)
{
   GeomData* data = static_cast<GeomData*>(LiNwcExternalGeometryGetUserData(geom));

   LcNwcExternalGeometry ex_geom(geom);
   GenerateVisitor visitor(context);

   visitor.m_ctx.Begin(LI_NWC_PRIMITIVE_POINTS);
   data->engine->Visit(&visitor);
   visitor.m_ctx.End();

   return TRUE;
}

// Interfaces PointEngine with RenderContext
class RenderVisitor : public PointEngineVisitor
{
public:
   RenderVisitor(LtNwcRenderContext ctx) : m_ctx(ctx)
   {
      // Get transformation matrices from space in which points are defined
      // through to window clip space. Could use to generate pre-rendered image
      // which you then draw with DrawImage or to transform corners of bounding box
      // into window space to work out size on screen and pick appropriate screen
      // density. For this sample we'll use them to perform view frustum culling.
      double proj[16];
      double model_view[16];
      m_ctx.GetTransformationMatrices(proj, model_view);

      // Transform planes that define clip space viewing frustum back into
      // space of geometry so that we can clip against them in our local space.
      SetNumCullPlanes(6);
      AddPlane(proj, model_view, Plane(1,0,0,-1), 0);
      AddPlane(proj, model_view, Plane(-1,0,0,-1), 1);
      AddPlane(proj, model_view, Plane(0,1,0,-1), 2);
      AddPlane(proj, model_view, Plane(0,-1,0,-1), 3);
      AddPlane(proj, model_view, Plane(0,0,1,-1), 4);
      AddPlane(proj, model_view, Plane(0,0,-1,-1), 5);
   }

   virtual void Points(int num, const Point* points, const unsigned char* rgba)
   {
      m_ctx.DrawPoints(num, (LtSingle*) points, (LtNat8*) rgba);
   }

   LcNwcRenderContext m_ctx;

private:
   void AddPlane(double proj[16], double model_view[16], const Plane& plane, int index)
   {
      SetCullPlane(index, plane.TransformedByInverse(proj).TransformedByInverse(model_view));
   }
};

// Called by Navisworks to render the geometry
LtBoolean LI_NWC_API
render_cb(LtNwcExternalLink link,
          LtNwcExternalGeometry geom,
          LtNwcRenderContext context)
{
   GeomData* data = static_cast<GeomData*>(LiNwcExternalGeometryGetUserData(geom));

   RenderVisitor visitor(context);
   LtInt32 width = visitor.m_ctx.GetWindowWidth();
   LtInt32 height = visitor.m_ctx.GetWindowHeight();
   if (width == 0 || height == 0)
      return TRUE;

   data->engine->Visit(&visitor);

   return TRUE;
}

// Interfaces PointEngine with PickContext
class PickVisitor : public PointEngineVisitor
{
public:
   PickVisitor(LtNwcPickContext ctx) : m_ctx(ctx)
   {
      SetNumCullPlanes(6);
      AddPlane(0, LI_NWC_PICK_FRUSTUM_PLANE_LEFT);
      AddPlane(1, LI_NWC_PICK_FRUSTUM_PLANE_RIGHT);
      AddPlane(2, LI_NWC_PICK_FRUSTUM_PLANE_TOP);
      AddPlane(3, LI_NWC_PICK_FRUSTUM_PLANE_BOTTOM);
      AddPlane(4, LI_NWC_PICK_FRUSTUM_PLANE_NEAR);
      AddPlane(5, LI_NWC_PICK_FRUSTUM_PLANE_FAR);
   }

   virtual void Points(int num, const Point* points, const unsigned char* rgba)
   {
      for (LtInt32 i = 0; i < num; i ++)
      {
         const Point& p = points[i];
         m_ctx.Point(p[0], p[1], p[2]);
      }
   }

   LcNwcPickContext m_ctx;

private:
   void AddPlane(int index, LtNwcPickFrustumPlane plane)
   {
      LtFloat x, y, z, d;
      m_ctx.GetFrustumPlane(plane, &x, &y, &z, &d);
      SetCullPlane(index, Plane(x,y,z,d));
   }
};

// Called by Navisworks to pick closest point within a frustum
LtBoolean LI_NWC_API
pick_cb(LtNwcExternalLink link,
        LtNwcExternalGeometry geom,
        LtNwcPickContext context)
{
   GeomData* data = static_cast<GeomData*>(LiNwcExternalGeometryGetUserData(geom));
   PickVisitor visitor(context);
   data->engine->Visit(&visitor);

   return TRUE;
}

// Main NWcreate entry point to load a file. We create an external link with URI pointing
// at the file so we can render and pick content on demand.
static LtNwcLoadStatus LI_NWC_API 
load_file_ex_cb(LtNwcLoader loader_handle, 
                LtWideString pathname, 
                LtNwcScene scene_handle, 
                LtNwcProgress progress_handle,
                void *user_data)
{
   LcNwcLoader loader(loader_handle);
   LcNwcScene scene(scene_handle);
   LcNwcProgress progress(progress_handle);

   LcNwcExternalGeometry exgeom;
   exgeom.SetFileLoader("ExternalPoints");
   exgeom.SetLinkName("Link1");
   exgeom.SetUri(pathname);

   LtNwcLoadStatus status = connect(f_link_data, exgeom);
   if (status != LI_NWC_LOAD_OK)
      return status;

   GeomData* geom_data = static_cast<GeomData*>(exgeom.GetUserData());   
   exgeom.SetBoundingBox(geom_data->min_point, geom_data->max_point);

   exgeom.SetNumPrimitives(geom_data->num_pts * geom_data->num_pts * geom_data->num_pts);
   exgeom.SetVertexProperties(LI_NWC_VERTEX_COLOR);
   exgeom.SetPrimitiveTypes(LI_NWC_PRIMITIVE_POINTS);
   
   LcNwcGeometry geom;
   geom.SetClassName(L"External Points", "ExternalPoints");
   LcNwcGeometryStream stream = geom.OpenStream();

   // Geometry is single precision. To maximize precision we define points close
   // to origin and then translate them using a double precision offset.
   stream.MultTransformTranslation(geom_data->offset);
   stream.ExternalGeometry(exgeom);
   geom.CloseStream(stream);

   scene.AddNode(geom);

   // Set units and default orientation for data
   scene.SetLinearUnits(LI_NWC_UNITS_METERS);
   scene.SetWorldUpVector(0,0,1);
   scene.SetWorldFrontVector(0, 1, 0);
   LcNwcView view;
   view.SetWorldUpVector(0, 0, 1);
   scene.SetCurrentView(view);

   return LI_NWC_LOAD_OK;
}

// ExternalPoints.cfg configuration file defines number of parameters for loader
// and how they correspond to "which" argument. Could use to expose some global
// PointEngine parameters to end user.
static LtBoolean LI_NWC_API 
param_cb(LtNwcLoader loader,
         LtInt32 which,
         LtNwcData in_data,
         void* user_data)
{
   LcNwcData data(in_data);
   return TRUE;
}

// Entry point for loader. Setup callbacks for loading from file and
// handling external link.
extern "C" __declspec(dllexport) LtBoolean LI_NWC_API 
LiNwcLoaderEntry(LtNwcLoader loader_handle)
{
   LcNwcLoader loader(loader_handle);
   loader.SetLoadFileExCallback(&load_file_ex_cb, NULL);
   loader.SetParameterCallback(&param_cb, NULL);

   if (!f_link_data)
      f_link_data = new LinkData;

   LcNwcExternalLink link;
   link.SetName("Link1");
   link.SetUserData(f_link_data);
   link.SetConnectCallback(&connect_cb);
   link.SetGeneratePrimitivesCallback(&generate_primitives_cb);
   link.SetRenderCallback(&render_cb);
   link.SetPickCallback(&pick_cb);
   link.SetDisconnectCallback(&disconnect_cb);
   loader.AddLink(link);

   return TRUE;
}