//------------------------------------------------------------------
// NavisWorks Sample code
//------------------------------------------------------------------
//
// (C) Copyright 2008 by Autodesk Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//------------------------------------------------------------------

#ifndef lint
static char rcsid[] = "@(#)$Id: //NavisWorks/release/21.0/Api/nwcreate/examples/loader/loader.cpp#1 $" ;
#endif

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <nwcreate/LiNwcAll.h>

// Useful constant
#define         LI_PI                   3.14159265358979323846

// Loader parameters. Should match defaults in define_options_cb.
static LtFloat f_faceting_factor = 1;
static LtFloat f_max_facet_deviation = 0;
static LtBoolean f_make_cylinder = TRUE;

// Specification of widget read from file
struct WidgetSpec
{
   LtFloat inner_radius;
   LtFloat outer_radius;
   LtFloat arm_length;
   LtFloat thickness;
};

// Deletes any data needed by geometry callbacks when done
static void LI_NWC_API
scene_complete_cb(LtNwcScene scene_handle, void* user_data)
{
   WidgetSpec* p = static_cast<WidgetSpec*>(user_data);
   delete p;
}

// Useful utilities for working with vectors
static inline void
vec_set(LtVector a, const LtVector b)
{
   a[0] = b[0];
   a[1] = b[1];
   a[2] = b[2];
}

static inline void
vec_set(LtVector a, LtFloat x, LtFloat y, LtFloat z)
{
   a[0] = x;
   a[1] = y;
   a[2] = z;
}

static inline void
vec_add(LtVector c, const LtVector a, const LtVector b)
{
   c[0] = a[0] + b[0];
   c[1] = a[1] + b[1];
   c[2] = a[2] + b[2];
}

static inline void
vec_sub(LtVector c, const LtVector a, const LtVector b)
{
   c[0] = a[0] - b[0];
   c[1] = a[1] - b[1];
   c[2] = a[2] - b[2];
}

static inline void
vec_scale(LtVector c, const LtVector a, LtFloat b)
{
   c[0] = a[0] * b;
   c[1] = a[1] * b;
   c[2] = a[2] * b;
}

static LtBoolean LI_NWC_API
geometry_cb(LtNwcGeometry geometry, 
            LtNwcGeometryStream stream_handle, 
            void* user_data)
{
   LcNwcGeometryStream stream(stream_handle);
   WidgetSpec* spec = static_cast<WidgetSpec*>(user_data);

   // Usefull base vectors
   LtPoint c = { 0, 0, 0 };
   LtUnitVector x = { 1, 0, 0};
   LtUnitVector y = { 0, 1, 0};
   LtUnitVector z = { 0, 0, 1};
   LtUnitVector mx = { -1, 0, 0};
   LtUnitVector my = { 0, -1, 0};
   LtUnitVector mz = { 0, 0, -1};

   // Loader parameters allow user to control faceting
   stream.FacetingFactor(f_faceting_factor);
   stream.MaxFacetDeviation(f_max_facet_deviation);

   // So we can see whether we've oriented pieces consistently. If
   // default used NavisWorks will automatically make all pieces
   // consistent with each other.
   stream.CorrectGenNormalOrientation(FALSE);

   // Derive some other stuff from input parameters
   LtFloat width = spec->outer_radius - spec->inner_radius;
   LtFloat inner_arm_length = width + spec->arm_length;
   LtPoint outer_c; vec_set(outer_c, width, 0, 0);
   LtVector inner_x; vec_scale(inner_x, x, spec->inner_radius);
   LtVector inner_y; vec_scale(inner_y, y, spec->inner_radius);
   LtVector outer_x; vec_scale(outer_x, x, spec->outer_radius);
   LtVector outer_y; vec_scale(outer_y, y, -spec->outer_radius);
   LtVector thick_vec; vec_set(thick_vec, 0, 0, spec->thickness);

   stream.Begin(LI_NWC_VERTEX_NORMAL);

   //
   // Bottom face of widget
   //
   stream.Normal(mz);
   stream.BeginPolygon();

   // Outer edge
   stream.BeginPolygonContour();

   // Inner cylindrical face of widget. Use exterior faceting so
   // that any cylinder fitted into widget can't intersect.
   stream.ExteriorFaceting(TRUE);
   stream.PolygonEllipse(c, inner_x, inner_y, -LI_PI/2, LI_PI/2);
   LtPoint in_top_edge; vec_add(in_top_edge, c, inner_y);

   LtVector inner_arm; vec_scale(inner_arm, y, inner_arm_length);
   LtPoint in_top; vec_add(in_top, in_top_edge, inner_arm);
   stream.PolygonVertex(in_top);

   LtVector width_vec; vec_scale(width_vec, x, width);
   LtPoint out_top; vec_add(out_top, in_top, width_vec);
   stream.PolygonVertex(out_top);

   LtVector outer_arm; vec_scale(outer_arm, y, spec->arm_length);
   LtPoint out_top_edge; vec_sub(out_top_edge, out_top, outer_arm);

   // Outer cylindrical face of widget. Use normal facetting.
   stream.ExteriorFaceting(FALSE);
   stream.PolygonEllipse(outer_c, outer_x, outer_y, -LI_PI/2, LI_PI/2);

   LtPoint out_bot_edge; vec_set(out_bot_edge,
      out_top_edge[0], -out_top_edge[1], out_top_edge[2]);
   LtPoint out_bot; vec_sub(out_bot, out_bot_edge, outer_arm);
   stream.PolygonVertex(out_bot);

   LtPoint in_bot; vec_sub(in_bot, out_bot, width_vec);
   stream.PolygonVertex(in_bot);
   stream.EndPolygonContour();

   LtPoint in_bot_edge; vec_add(in_bot_edge, in_bot, inner_arm);

   // Hole
   stream.BeginPolygonContour();
   LtPoint hc; vec_set(hc, spec->inner_radius + width * 0.5, 0, 0);
   LtVector hole_x; vec_scale(hole_x, x, width * 0.2 );
   LtVector hole_y; vec_scale(hole_y, y, width * 0.5 );
   stream.PolygonEllipse(hc, hole_x, hole_y);
   stream.EndPolygonContour();
   stream.EndPolygon();


   
   //
   // Top face of widget. Reverse order of top face to get
   // orientation outwards.
   //
   stream.Normal(z);
   stream.BeginPolygon();

   // Outer edge
   stream.BeginPolygonContour();

   LtPoint in_top_edge2; vec_add(in_top_edge2, in_top_edge, thick_vec);

   LtPoint c2; vec_add(c2, c, thick_vec);
   LtVector inner_x2; vec_set(inner_x2, inner_x);
   LtVector inner_y2; vec_scale(inner_y2, y, -spec->inner_radius);
   stream.ExteriorFaceting(TRUE);
   stream.PolygonEllipse(c2, inner_x2, inner_y2, -LI_PI/2, LI_PI/2);

   LtPoint in_bot_edge2; vec_add(in_bot_edge2, in_bot_edge, thick_vec);

   LtPoint in_bot2; vec_add(in_bot2, in_bot, thick_vec);
   stream.PolygonVertex(in_bot2);

   LtPoint out_bot2; vec_add(out_bot2, out_bot, thick_vec);
   stream.PolygonVertex(out_bot2);

   LtPoint out_bot_edge2; vec_add(out_bot_edge2, out_bot_edge, thick_vec);

   stream.ExteriorFaceting(FALSE);
   LtPoint outer_c2; vec_add(outer_c2, outer_c, thick_vec);
   LtVector outer_x2; vec_set(outer_x2, outer_x);
   LtVector outer_y2; vec_scale(outer_y2, y, spec->outer_radius);
   stream.PolygonEllipse(outer_c2, outer_x2, outer_y2, -LI_PI/2, LI_PI/2);

   LtPoint out_top_edge2; vec_add(out_top_edge2, out_top_edge, thick_vec);

   LtPoint out_top2; vec_add(out_top2, out_top, thick_vec);
   stream.PolygonVertex(out_top2);

   LtPoint in_top2; vec_add(in_top2, in_top, thick_vec);
   stream.PolygonVertex(in_top2);
   stream.EndPolygonContour();

   // Hole
   stream.BeginPolygonContour();
   LtPoint hc2; vec_add(hc2, hc, thick_vec);
   LtVector hole_x2; vec_set(hole_x2, hole_x);
   LtVector hole_y2; vec_set(hole_y2, 
      hole_y[0], -hole_y[1], hole_y[2]);
   stream.PolygonEllipse(hc2, hole_x2, hole_y2);
   stream.EndPolygonContour();
   stream.EndPolygon();


   //
   // Now do the surfaces that connect the top and bottom faces
   //

   stream.ExteriorFaceting(TRUE);
   stream.Conic(c2, inner_x, inner_y, c, inner_x, inner_y,
      -LI_PI/2, LI_PI/2);

   stream.Normal(mx);
   stream.ConvexPolyVertex(in_bot_edge);
   stream.ConvexPolyVertex(in_bot);
   stream.ConvexPolyVertex(in_bot2);
   stream.ConvexPolyVertex(in_bot_edge2);
   stream.SeqEnd();

   stream.Normal(my);
   stream.ConvexPolyVertex(in_bot);
   stream.ConvexPolyVertex(out_bot);
   stream.ConvexPolyVertex(out_bot2);
   stream.ConvexPolyVertex(in_bot2);
   stream.SeqEnd();

   stream.Normal(x);
   stream.ConvexPolyVertex(out_bot);
   stream.ConvexPolyVertex(out_bot_edge);
   stream.ConvexPolyVertex(out_bot_edge2);
   stream.ConvexPolyVertex(out_bot2);
   stream.SeqEnd();

   stream.ExteriorFaceting(FALSE);
   stream.Conic(outer_c2, outer_x, outer_y, outer_c, outer_x, outer_y,
      -LI_PI/2, LI_PI/2);

   stream.Normal(x);
   stream.ConvexPolyVertex(out_top_edge);
   stream.ConvexPolyVertex(out_top);
   stream.ConvexPolyVertex(out_top2);
   stream.ConvexPolyVertex(out_top_edge2);
   stream.SeqEnd();

   stream.Normal(y);
   stream.ConvexPolyVertex(out_top);
   stream.ConvexPolyVertex(in_top);
   stream.ConvexPolyVertex(in_top2);
   stream.ConvexPolyVertex(out_top2);
   stream.SeqEnd();

   stream.Normal(mx);
   stream.ConvexPolyVertex(in_top);
   stream.ConvexPolyVertex(in_top_edge);
   stream.ConvexPolyVertex(in_top_edge2);
   stream.ConvexPolyVertex(in_top2);
   stream.SeqEnd();

   stream.Conic(hc2, hole_x, hole_y, hc, hole_x, hole_y);

   stream.End();


   //
   // Cylinder "held" by widget to show that exterior faceting of
   // inner widget surface means no intersection with cylinder of
   // same radius.
   //
   if (f_make_cylinder)
   {
      // We'll let NavisWorks sort out consistent orientation and generate
      // normals this time.
      stream.CorrectGenNormalOrientation(TRUE);

      // Facet cylinder to high level of quality
      stream.FacetingFactor(100);
      stream.MaxFacetDeviation(1);

      stream.Begin(LI_NWC_VERTEX_COLOR);
      stream.Color(1,0,0,0);
      c[2] += spec->thickness * 0.1;
      c2[2] -= spec->thickness * 0.1;
      stream.Cylinder(c2, c, spec->inner_radius);
      stream.Circle(c, z, spec->inner_radius);
      stream.Circle(c2, z, spec->inner_radius);
      stream.End();
   }
   
   return TRUE;
}

static LtBoolean
parse_file(FILE* fp, WidgetSpec* spec)
{
   if (fscanf_s(fp, "%lg", &spec->inner_radius) != 1)
      return FALSE;
   if (fscanf_s(fp, "%lg", &spec->outer_radius) != 1)
      return FALSE;
   if (fscanf_s(fp, "%lg", &spec->arm_length) != 1)
      return FALSE;
   if (fscanf_s(fp, "%lg", &spec->thickness) != 1)
      return FALSE;

   return TRUE;
}

static LtNwcLoadStatus LI_NWC_API 
load_file_cb(LtNwcLoader loader_handle,
             LtWideString pathname, 
             LtNwcScene scene_handle, 
             LtNwcProgressCallback* progress,
             void* progress_data,
             void* user_data)
{
   LcNwcLoader loader(loader_handle);
   LcNwcData value;
   LcNwcOptionSet options = loader.GetOptions();

   options.GetOption("faceting_factor", value);
   f_faceting_factor = value.GetFloat();

   options.GetOption("max_facet_deviation", value);
   f_max_facet_deviation = value.GetFloat();

   options.GetOption("make_cylinder", value);
   f_make_cylinder = value.GetBoolean();

   FILE* fp = NULL;
   _wfopen_s(&fp, pathname, L"r");
   if (!fp)
      return LI_NWC_LOAD_CANT_OPEN;

   WidgetSpec* spec = new WidgetSpec;
   if (!parse_file(fp, spec))
   {
      delete spec;
      return LI_NWC_LOAD_FILE_CORRUPT;
   }

   (*progress)(0, progress_data);

   LcNwcScene scene(scene_handle);

   LcNwcGeometry geom;

#if 1
   geom.SetCallback(&geometry_cb, spec);
   scene.SetSceneCompleteCallback(&scene_complete_cb, spec);
#else
   LcNwcGeometryStream stream = geom.OpenStream();
   geometry_cb(geom, stream, spec);
   geom.CloseStream(stream);
   delete spec;
#endif

   // Sleep so you get to see progress working
   ::Sleep(1000);
   (*progress)(0.5, progress_data);

   scene.AddNode(geom);
   scene.SetStatistics(pathname);

   fclose(fp);

   // Sleep so you get to see progress working
   ::Sleep(1000);
   (*progress)(1, progress_data);

   return LI_NWC_LOAD_OK;
}

static void LI_NWC_API
define_options_cb(LtNwcLoader loader, LtNwcOptionSet option_set, void *user_data)
{
   LcNwcOptionSet opts(option_set);
   LcNwcData value;

   value.SetFloat(1.0);
   opts.DefineOption("faceting_factor", value);

   value.SetFloat(0.0);
   opts.DefineOption("max_facet_deviation", value);

   value.SetBoolean(TRUE);
   opts.DefineOption("make_cylinder", value);
}

// Entry point for loader. Setup callbacks for loading from file and
// changing loader parameters.
extern "C" __declspec(dllexport) LtBoolean LI_NWC_API 
LiNwcLoaderEntry(LtNwcLoader loader_handle)
{
   LcNwcLoader loader(loader_handle);
   loader.SetLoadFileCallback(&load_file_cb, NULL);
   loader.SetDefineOptionsCallback(&define_options_cb, NULL);

   return TRUE;
}
