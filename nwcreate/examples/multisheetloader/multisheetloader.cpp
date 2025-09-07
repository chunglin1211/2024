//------------------------------------------------------------------
// NavisWorks Sample code
//------------------------------------------------------------------
//
// (C) Copyright 2011 by Autodesk Inc.
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

#include <stdio.h>
#include <stdlib.h>

#include <nwcreate/LiNwcAll.h>
#include "ColumnSpec.h"

// Loader parameters. Should match defaults in define_options_cb.
ColumnProfile ColumnSpec::m_profile = eCIRCLE;

// Useful base vectors.
LtPoint origin = {0, 0, 0};
LtVector x = { 1, 0, 0 };
LtVector y = { 0, 1, 0 };
LtVector z = { 0, 0, 1 };
LtVector mz = { 0, 0, -1 };

// Define geometry for 3D column with circle profile.
static LtBoolean LI_NWC_API
geom_col_circle(LcNwcGeometryStream stream, 
                ColumnSpec* spec)
{
   LtPoint base;
   spec->GetCenter(base);

   LtPoint top = {base[0], base[1], base[2] + spec->GetHeight()};
   LtFloat r = 1;

   stream.Circle(base, mz, r);
   stream.Cylinder(base, top, r);
   stream.Circle(top, z, r);

   return TRUE;
}

// Define geometry for 3D column with square profile.
static LtBoolean LI_NWC_API
geom_col_square(LcNwcGeometryStream stream, 
                ColumnSpec* spec)
{
   LtPoint base;
   spec->GetCenter(base);

   LtPoint corner = {base[0] - 1, base[1] - 1, base[2]};
   LtPoint corner_opposite = {base[0] + 1, base[1] + 1, base[2] + spec->GetHeight()};

   stream.Cuboid(corner, corner_opposite);

   return TRUE;
}

// Define geometry for 3D column with I profile.
static LtBoolean LI_NWC_API
geom_col_I(LcNwcGeometryStream stream, 
           ColumnSpec* spec)
{
   LtPoint base;
   spec->GetCenter(base);

   LcNwcPlane plane(origin, x, y);
   LcNwcBRepProfileBuilder builder(plane);

   builder.SetRadius(0.0);
   builder.AddPoint(base[0] + 1,   base[1] + 1);
   builder.AddPoint(base[0] + 1,   base[1] + 0.5);
   builder.AddPoint(base[0] + 0.5, base[1] + 0.5);
   builder.AddPoint(base[0] + 0.5, base[1] - 0.5);
   builder.AddPoint(base[0] + 1,   base[1] - 0.5);
   builder.AddPoint(base[0] + 1,   base[1] - 1);
   builder.AddPoint(base[0] - 1,   base[1] - 1);
   builder.AddPoint(base[0] - 1,   base[1] - 0.5);
   builder.AddPoint(base[0] - 0.5, base[1] - 0.5);
   builder.AddPoint(base[0] - 0.5, base[1] + 0.5);
   builder.AddPoint(base[0] - 1,   base[1] + 0.5);
   builder.AddPoint(base[0] - 1,   base[1] + 1);
   
   LcNwcLoop loop = builder.CreateLoop();
   LcNwcFace face(plane, LI_NWC_SENSE_POSITIVE);
   face.AddLoop(loop);

   LcNwcBRepPrism column(face, z, spec->GetHeight(), true);
   stream.BRepEntity(column);
   
   return TRUE;
}

// Define geometry for 2D column with circle profile.
static LtBoolean LI_NWC_API
geom_col_circle(LcNwcPlotGeometryStream path_geo_stream, 
                ColumnSpec* spec)
{
   LtPoint base;
   spec->GetCenter(base);

   LcNwcPlotCircleSegment circle = LcNwcPlotCircleSegment(path_geo_stream);
   LtPoint2d center = {base[0], base[1]};
   circle.SetCenterPoint(center);
   circle.SetRadius(1.0);

   path_geo_stream.CircleSegment(circle);

   return TRUE;
}

// Define geometry for 2D column with square profile.
static LtBoolean LI_NWC_API
geom_col_square(LcNwcPlotGeometryStream path_geo_stream, 
                ColumnSpec* spec)
{
   LtPoint base;
   spec->GetCenter(base);

   // Draw a polyline.
   LtPoint2d points[5] = {
      {base[0] + 1,   base[1] + 1},
      {base[0] + 1,   base[1] - 1},
      {base[0] - 1,   base[1] - 1},
      {base[0] - 1,   base[1] + 1}, 
      {base[0] + 1,   base[1] + 1} };

   // Begin a polyline segement.
   path_geo_stream.PolyLineSegmentBegin(true);
   for (LtInt32 i = 0; i < 5; ++i)
      path_geo_stream.PolyLineSegmentPoint(points[i]);
   path_geo_stream.PolyLineSegmentEnd();

   return TRUE;
}

// Define geometry for 2D column with I profile.
static LtBoolean LI_NWC_API
geom_col_I(LcNwcPlotGeometryStream path_geo_stream, 
           ColumnSpec* spec)
{
   LtPoint base;
   spec->GetCenter(base);

   // Draw a polyline.
   LtPoint2d points[13] = {
      {base[0] + 1,   base[1] + 1},
      {base[0] + 1,   base[1] + 0.5},
      {base[0] + 0.5, base[1] + 0.5},
      {base[0] + 0.5, base[1] - 0.5},
      {base[0] + 1,   base[1] - 0.5},
      {base[0] + 1,   base[1] - 1},
      {base[0] - 1,   base[1] - 1},
      {base[0] - 1,   base[1] - 0.5},
      {base[0] - 0.5, base[1] - 0.5},
      {base[0] - 0.5, base[1] + 0.5},
      {base[0] - 1,   base[1] + 0.5},
      {base[0] - 1,   base[1] + 1}, 
      {base[0] + 1,   base[1] + 1} };

   // Begin a polyline segement.
   path_geo_stream.PolyLineSegmentBegin(true);
   for (LtInt32 i = 0; i < 13; ++i)
      path_geo_stream.PolyLineSegmentPoint(points[i]);
   path_geo_stream.PolyLineSegmentEnd();

   return TRUE;
}

// 2D geometry.
static LtBoolean LI_NWC_API
geometry(LtNwcGeometry geometry, 
         LtNwcPlotStream stream_handle, 
         void* user_data)
{
   LcNwcPlotStream stream(stream_handle);
   ColumnSpec* spec = static_cast<ColumnSpec*>(user_data);

   // Prepare path style: fill brush and stroke to draw a figure
   // 
   // fill brush, red one
   LcNwcPlotSolidColorBrush brush;
   brush.SetColor(1, 0, 0, 1);
   // stroke, set its color by brush
   LcNwcPlotStroke stroke;
   stroke.SetBrush(brush);

   // Then set the defined filled brush and stroke to path style
   LcNwcPlotPathStyle path_style;
   path_style.SetFill(brush);
   path_style.SetStroke(stroke);

   // Begin path, mandatory if you want to draw figures
   stream.PathBegin(path_style);

   // Begin the path geometry stream in this path
   LcNwcPlotPathStreamStyle path_stream_style;
   path_stream_style.SetFillRule(LI_NWC_PLOT_PATH_FILL_RULE_NONE);
   LcNwcPlotGeometryStream path_geo_stream = stream.PathStreamOpen(path_stream_style);

   // Begin the path figure
   LcNwcPlotPathFigureStyle path_figure_style;
   path_geo_stream.PathFigureBegin(path_figure_style);

   // Define the path figure.
   if (spec->m_profile == eSQUARE)
      geom_col_square(path_geo_stream, spec);
   else if (spec->m_profile == eIBEAM)
      geom_col_I(path_geo_stream, spec);
   else
      geom_col_circle(path_geo_stream, spec);

   // End the path figure
   path_geo_stream.PathFigureEnd();
   stream.PathStreamClose(path_geo_stream);

   // End path
   stream.PathEnd();

   return TRUE;
}

// 3D geometry.
static LtBoolean LI_NWC_API
geometry(LtNwcGeometry geometry, 
         LtNwcGeometryStream stream_handle, 
         void* user_data)
{
   LcNwcGeometryStream stream(stream_handle);
   ColumnSpec* spec = static_cast<ColumnSpec*>(user_data);

   stream.Begin(LI_NWC_VERTEX_NORMAL);

   if (spec->m_profile == eSQUARE)
      geom_col_square(stream, spec);
   else if (spec->m_profile == eIBEAM)
      geom_col_I(stream, spec);
   else
      geom_col_circle(stream, spec);

   stream.End();

   return TRUE;
}

static LtBoolean LI_NWC_API
add_grid_level(LcNwcGridSystem system, 
               LtFloat height, 
               LtWideString label)
{
   LcNwcGridLevel level(label, height);
   system.AddGridLevel(level);

   return TRUE;
}

static LtBoolean LI_NWC_API
add_grid_line(LcNwcGridSystem system, 
              LtWideString label, 
              LtPoint start, 
              LtPoint end)
{
   LcNwcGridLine line(label);
   line.AddLinearSegment(start, end);
   system.AddGridLine(line);

   return TRUE;
}

static LtBoolean LI_NWC_API
add_grid_lines(LcNwcGridSystem system)
{
   LtPoint lineA[2] = { {-10, -5, 0}, {10, -5, 0} };
   add_grid_line(system, L"A", lineA[0], lineA[1]);

   LtPoint lineB[2] = { {-10, 0, 0}, {10, 0, 0} };
   add_grid_line(system, L"B", lineB[0], lineB[1]);

   LtPoint lineC[2] = { {-10, 5, 0}, {10, 5, 0} };
   add_grid_line(system, L"C", lineC[0], lineC[1]);

   LtPoint line1[2] = { {-5, -10, 0}, {-5, 10, 0} };
   add_grid_line(system, L"1", line1[0], line1[1]);

   LtPoint line2[2] = { {0, -10, 0}, {0, 10, 0} };
   add_grid_line(system, L"2", line2[0], line2[1]);

   LtPoint line3[2] = { {5, -10, 0}, {5, 10, 0} };
   add_grid_line(system, L"3", line3[0], line3[1]);
 
   return TRUE;
}

static void LI_NWC_API
define_options_cb(LtNwcLoader loader, 
                  LtNwcOptionSet option_set, 
                  void *user_data)
{
   LcNwcOptionSet opts(option_set);
   LcNwcData value;

   value.SetNameEnum(NULL, "navisworks_mlf_column_profile", eCIRCLE);
   opts.DefineOption("column_profile", value);
}

static LtNwcLoadStatus LI_NWC_API 
load_fileinfo_cb(LtNwcLoader loader_handle,
                 LtWideString pathname,
                 LtNwcFileInfo file_handle,
                 LtNwcProgress progress_handle,
                 void *user_data)
{
   LcNwcFileInfo fileinfo(file_handle);
   
   // Add a 3D sheet.
   LcNwcSheetInfo sheet3D;
   sheet3D.SetSheetType(LI_NWC_SHEET_3D);
   sheet3D.SetDisplayName(L"Columns in 3D");
   sheet3D.SetId(L"sheet3D");
   fileinfo.AddSheet(sheet3D);
   
   // Add a 2D sheet.
   LcNwcSheetInfo sheet2D;
   sheet2D.SetSheetType(LI_NWC_SHEET_2D);
   sheet2D.SetDisplayName(L"Columns in 2D");
   sheet2D.SetId(L"sheet2D");
   fileinfo.AddSheet(sheet2D);
   
   // Set the default sheet.
   fileinfo.SetCurrentSheetId(L"sheet2D");

   return LI_NWC_LOAD_OK;
}

static LtNwcLoadStatus LI_NWC_API 
load_file_sheet_cb(LtNwcLoader loader_handle, 
                   LtWideString pathname, 
                   LtWideString sheet_id, 
                   LtNwcScene scene_handle, 
                   LtNwcProgress progress_handle, 
                   void *user_data)
{
   // Read options.
   LcNwcLoader loader(loader_handle);
   LcNwcOptionSet options = loader.GetOptions();

   LcNwcData value;
   options.GetOption("column_profile", value);

   LtInt32 profile_type;
   value.GetNameEnum("navisworks_mlf_column_profile", NULL, &profile_type);

   ColumnSpec::m_profile = static_cast<ColumnProfile>(profile_type);

   // Load file.
   std::vector<ColumnSpec> columns;
   LtNwcLoadStatus status = ColumnSpec::LoadFromFile(pathname, columns);

   if (status != LI_NWC_LOAD_OK)
      return status;

   LcNwcScene scene(scene_handle);
   scene.SetStatistics(pathname);

   // Begin building grid.
   LcNwcGridSystem system(L"MLFGridSystem", origin, x, y);
   add_grid_lines(system);

   // For each of our columns.
   int num_cols = (int) columns.size();
   for (int i = 0; i < num_cols; i++)
   {
      ColumnSpec spec = columns.at(i);

      // Create geometry for each column.
      LcNwcGeometry geom;

      if (!wcscmp(sheet_id, L"sheet3D"))
      {
         LcNwcGeometryStream geom_stream = geom.OpenStream();
         geometry(geom, geom_stream, &spec);
         geom.CloseStream(geom_stream);
      }
      else if (!wcscmp(sheet_id, L"sheet2D"))
      {
         LcNwcPlotStream plot_stream = geom.OpenPlotStream();
         geometry(geom, plot_stream, &spec);
         geom.ClosePlotStream(plot_stream);
      }
      else
         return LI_NWC_LOAD_ERROR;

      // Set GUID.
      std::wstring guid_wstr = spec.GetGuid();
      LtNwcGuid guid = LiNwcGuidCreateFromGuidString(guid_wstr.c_str());
      geom.SetGuid(guid);

      scene.AddNode(geom);

      // Add grid level corresponding to the top of the column.
      add_grid_level(system, spec.GetHeight(), L"Top");
   }

   // Add the complete grid system to the scene.
   scene.AddGridSystem(system);

   // Extra bits and pieces.
   if (!wcscmp(sheet_id, L"sheet3D"))
   {
      LiNwcSceneSetWorldUpVector(scene, 0, 0, 1);
   }
   else if (!wcscmp(sheet_id, L"sheet2D"))
   {
      // Paper style
      LcNwcPlotPaperStyle paper_style;
      paper_style.SetColor(1, 1, 1, 1);   // White paper
      LtVector2d size = {15, 15};
      paper_style.SetSize(size);
      scene.SetPaperStyle(paper_style);

      scene.SetIsPlot(true);
   }

   return LI_NWC_LOAD_OK;
}

// Entry point for loader.
extern "C" __declspec(dllexport) LtBoolean LI_NWC_API 
LiNwcLoaderEntry(LtNwcLoader loader_handle)
{
   LcNwcLoader loader(loader_handle);

   loader.SetLoadFileInfoCallback(&load_fileinfo_cb, NULL);
   loader.SetLoadFileSheetCallback(&load_file_sheet_cb, NULL);

   loader.SetDefineOptionsCallback(&define_options_cb, NULL);

   return TRUE;
}