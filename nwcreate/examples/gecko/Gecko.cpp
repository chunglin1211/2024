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

#include <nwcreate/LiNwcAll.h>
#include <stdio.h>
#include <stdlib.h>

#define LI_NWC_NO_PROGRESS_CALLBACKS NULL
#define LI_NWC_NO_USER_DATA NULL

static LtBoolean LI_NWC_API
geom_gecko_top(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LcNwcGeometryStream s(stream);

   s.Begin(LI_NWC_VERTEX_NONE);

   s.TriangleVertex(0, 5, 0);
   s.TriangleVertex(10, 20, 0);
   s.TriangleVertex(10, 0, 5);

   s.TriangleVertex(20, 0, 5);
   s.TriangleVertex(20, 20, 0);
   s.TriangleVertex(30, 5, 0);

   s.BeginPolygon();
   s.BeginPolygonContour();
   s.ConvexPolyVertex(10, 0, 5);
   s.ConvexPolyVertex(10, 20, 0);
   s.ConvexPolyVertex(20, 20, 0);
   s.ConvexPolyVertex(20, 0, 5);
   s.EndPolygonContour();
   s.EndPolygon();

   s.End();

   return TRUE;
}

static LtBoolean LI_NWC_API
geom_gecko_bottom(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LcNwcGeometryStream s(stream);

   s.Begin(LI_NWC_VERTEX_NONE);
   s.IndexedVertex(0, 5, 0);
   s.IndexedVertex(10, 20, 0);
   s.IndexedVertex(10, 0, -5);

   s.IndexedVertex(20, 0, -5);
   s.IndexedVertex(20, 20, 0);
   s.IndexedVertex(30, 5, 0);

   s.TriangleIndex(0);
   s.TriangleIndex(1);
   s.TriangleIndex(2);

   s.TriangleIndex(3);
   s.TriangleIndex(4);
   s.TriangleIndex(5);

   s.ConvexPolyIndex(2);
   s.ConvexPolyIndex(1);
   s.ConvexPolyIndex(4);
   s.ConvexPolyIndex(3);
   s.SeqEnd();

   s.End();

   return TRUE;
}


static LtBoolean LI_NWC_API
geom_gecko_rear(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LcNwcGeometryStream s(stream);
   //Rear

   s.Begin(LI_NWC_VERTEX_NONE);
   s.TriangleVertex(0, 5, 0);
   s.TriangleVertex(10, 0, -5);
   s.TriangleVertex(10, 0, 5);

   s.TriangleVertex(20, 0, -5);
   s.TriangleVertex(20, 0, 5);
   s.TriangleVertex(30, 5, 0);

   //The Square at the rear of the ship can be built with a Triangle Fan
   s.TriFanVertex(10, 0, -5);
   s.TriFanVertex(10, 0, 5);
   s.TriFanVertex(20, 0, 5);
   s.TriFanVertex(20, 0, -5);
   s.End();

   s.Begin(LI_NWC_VERTEX_NONE);
   s.End();
  
   return TRUE;
}

static LtBoolean LI_NWC_API
geom_gecko_exhaust(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LcNwcGeometryStream s(stream);

   //Must always start with a Begin and finish with an End
   s.Begin(LI_NWC_VERTEX_NONE);

   s.BeginPolygon();

   //The exhaust is just a thick square
   //This is the outside edge
   s.BeginPolygonContour();
   s.PolygonVertex(10,-0.1,0);
   s.PolygonVertex(15,-0.1,-3);
   s.PolygonVertex(20,-0.1,0);
   s.PolygonVertex(15,-0.1,3);
   s.EndPolygonContour();
   
   //This is the inside edge
   s.BeginPolygonContour();
   s.PolygonVertex(12.5,-0.1,0);
   s.PolygonVertex(15,  -0.1,-1.5);
   s.PolygonVertex(17.5,-0.1,0);
   s.PolygonVertex(15,  -0.1,1.5);
   s.EndPolygonContour();

   s.EndPolygon();

   s.End();

   return TRUE;
}

static LtBoolean LI_NWC_API
geom_gecko_burner(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LcNwcGeometryStream s(stream);

   //Must always start with a Begin and finish with an End
   s.Begin(LI_NWC_VERTEX_COLOR);

   int i;
   LtFloat x, y, z;
   LtFloat max_radius;

   for(i = 0 ; i < 500 ; i++)
   {
      y = ((LtFloat)rand() / RAND_MAX) * 30.0;
      max_radius = y * 0.5;

      s.Color(1, 1, (30 - y) / 30, 1);

      x = 15.0 + (((LtFloat)rand() / RAND_MAX) * max_radius) - (max_radius / 2.0);
      z = 0.0 + (((LtFloat)rand() / RAND_MAX) * max_radius) - (max_radius / 2.0);

      s.Point(x, -y, z);
   }

   s.End();

   s.Begin(LI_NWC_VERTEX_COLOR);

   for(i = 0 ; i < 5 ; i++)
   {
      s.Color(1, 1, 1, 1);
      s.LineVertex(15.0, 0.0, 0.0);

      x = 15.0 + (((LtFloat)rand() / RAND_MAX) * 15) - 7.5;
      z = 0.0 + (((LtFloat)rand() / RAND_MAX) * 15) - 7.5;

      s.Color(1, 0, 0, 1);
      s.LineVertex(x, -30.0, z);
   }

   s.End();

   return TRUE;
}

static LtBoolean LI_NWC_API
geom_gecko_laser(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LcNwcGeometryStream s(stream);
   
   //We want to remember the vertex colors
   s.Begin(LI_NWC_VERTEX_COLOR);

   s.Color(1,0.2,0,1);
   s.TriangleVertex(10, 20, 0);

   s.Color(0,0,1,1);
   s.TriangleVertex(10, 500, 0);

   s.Color(0,0,1,1);
   s.TriangleVertex(15, 500, 0);


   s.Color(1,0.2,0,1);
   s.TriangleVertex(20, 20, 0);

   s.Color(0,0,1,1);
   s.TriangleVertex(20, 500, 0);

   s.Color(0,0,1,1);
   s.TriangleVertex(15, 500, 0);

   s.End();

   return TRUE;
}

static void
do_test()
{
   LcNwcScene scene;

   LcNwcGroup group, ship;
   LcNwcGeometry geom_top, geom_bottom, geom_rear, geom_laser, geom_exhaust, geom_burner;

   geom_top.SetName(L"Gecko top");
   geom_bottom.SetName(L"Gecko bottom");
   geom_rear.SetName(L"Gecko rear");
   geom_laser.SetName(L"Gecko laser");
   geom_exhaust.SetName(L"Gecko exhaust");
   geom_burner.SetName(L"Gecko burner");

   geom_top.SetClassName(L"Part","Space CAD Ship Part");
   geom_bottom.SetClassName(L"Part","Space CAD Ship Part");
   geom_rear.SetClassName(L"Part","Space CAD Ship Part");
   geom_laser.SetClassName(L"Part","Space CAD Ship Part");
   geom_exhaust.SetClassName(L"Part","Space CAD Ship Part");
   geom_burner.SetClassName(L"Exhaust Fumes", "Space CAD Ship Part");

   LcNwcMaterial top_material;
   //Set ambient and diffuse color so that the color will remain whatever the lighting is
   top_material.SetDiffuseColor(0.9,0.9,0.9);
   top_material.SetAmbientColor(0.9,0.9,0.9);
   //Set the colour for the whole group and everything inside it
   geom_top.AddAttribute(top_material);
   
   LcNwcMaterial bottom_material;
   bottom_material.SetDiffuseColor(0.5,0.5,0.5);
   bottom_material.SetAmbientColor(0.5,0.5,0.5);
   geom_bottom.AddAttribute(bottom_material);

   LcNwcMaterial rear_material;
   rear_material.SetDiffuseColor(1,0,0);
   rear_material.SetAmbientColor(1,0,0);
   geom_rear.AddAttribute(rear_material);

   LcNwcMaterial exhaust_material;
   exhaust_material.SetDiffuseColor(1,0.1,0.1);
   exhaust_material.SetAmbientColor(1,0.1,0.1);
   geom_exhaust.AddAttribute(exhaust_material);

   LcNwcGeometryStream stream_gecko_top = geom_top.OpenStream();
   LcNwcGeometryStream stream_gecko_bottom = geom_bottom.OpenStream();
   LcNwcGeometryStream stream_gecko_rear = geom_rear.OpenStream();
   LcNwcGeometryStream stream_gecko_laser = geom_laser.OpenStream();
   LcNwcGeometryStream stream_gecko_exhaust = geom_exhaust.OpenStream();
   LcNwcGeometryStream stream_gecko_burner = geom_burner.OpenStream();

   geom_gecko_top(geom_top, stream_gecko_top, LI_NWC_NO_USER_DATA);
   geom_gecko_bottom(geom_bottom, stream_gecko_bottom, LI_NWC_NO_USER_DATA);
   geom_gecko_rear(geom_rear, stream_gecko_rear, LI_NWC_NO_USER_DATA);
   geom_gecko_laser(geom_laser, stream_gecko_laser, LI_NWC_NO_USER_DATA);
   geom_gecko_exhaust(geom_exhaust, stream_gecko_exhaust, LI_NWC_NO_USER_DATA);
   geom_gecko_burner(geom_burner, stream_gecko_burner, LI_NWC_NO_USER_DATA);

   geom_top.CloseStream(stream_gecko_top);
   geom_bottom.CloseStream(stream_gecko_bottom);
   geom_rear.CloseStream(stream_gecko_rear);
   geom_laser.CloseStream(stream_gecko_laser);
   geom_exhaust.CloseStream(stream_gecko_exhaust);
   geom_burner.CloseStream(stream_gecko_burner);

   group.SetName(L"Gecko Army");
   
   //Give the Gecko Army an "layer" icon in the Selection Tree View
   group.SetLayer(TRUE);
   group.SetClassName(L"Layer","Space CAD Layer");

   ship.SetName(L"Gecko");
   ship.SetClassName(L"Ship","Space CAD Ship");

   ship.AddNode(geom_top); 
   ship.AddNode(geom_bottom);
   ship.AddNode(geom_rear);
   ship.AddNode(geom_laser);
   ship.AddNode(geom_exhaust);
   ship.AddNode(geom_burner);

   //Create a ship specification comprised of a series of properties.
   LcNwcPropertyAttribute specification;
   specification.SetClassName(L"Specification","spec");
   specification.SetName(L"Gecko Specification");

   LcNwcData armaments;
   armaments.SetWideString(L"Ingram 1919 A4 Laser, LM Homing Missile.");
   specification.AddProperty(L"Armaments","Specification Armaments",armaments);

   LcNwcData cargo;
   cargo.SetInt32(3);
   specification.AddProperty(L"Cargo (TC)","Specification Cargo",cargo);

   LcNwcData max_velocity;
   max_velocity.SetFloat(0.3);
   specification.AddProperty(L"Maximum Velocity","Specification Maximum Velocity",max_velocity);

   LcNwcData hyperspace_capable;
   hyperspace_capable.SetBoolean(FALSE);
   specification.AddProperty(L"Hyperspace","Specification Hyperspace",hyperspace_capable);
   ship.AddAttribute(specification);

   LcNwcData manufactured;
   manufactured.SetTime(6710045820);
   specification.AddProperty(L"Manufactured", "Specification Manufactured", manufactured);

   LcNwcData length;
   length.SetLinearFloat(24);
   specification.AddProperty(L"Length", "Specification Length", length);

   LcNwcData optimum_reentry_angle;
   optimum_reentry_angle.SetAngularFloat(0.5233);
   specification.AddProperty(L"Optimum Re-entry Angle", "Specification Optimum Re-entry Angle", optimum_reentry_angle);

   LcNwcData window_area;
   window_area.SetAreaFloat(3);
   specification.AddProperty(L"Total Window Area", "Specification Total Window Area", window_area);

   LcNwcData cargo_bay;
   cargo_bay.SetVolumeFloat(20);
   specification.AddProperty(L"Cargo Bay Volume", "Specification Cargo Bay Volume", cargo_bay);

   LcNwcData point3d;
   point3d.SetPoint3D(10, 20, 200);
   specification.AddProperty(L"A point In 3D Space", "Specification A point In 3D Space", point3d);

   LcNwcData name;
   name.SetName(L"Gecko", "Gecko");
   specification.AddProperty(L"Ship Type", "Specification Ship Type", name);

   //Attach some generic text to the Ship...
   //Description is not a magic string *but* infact a tab item is created called "Description"
   LcNwcTextAttribute text;
   text.SetClassName(L"Description", "descr");
   text.SetName(L"Gecko Description");
   text.SetText(L"Patented by Robert Bream, but not manufactured until Ace and Faber improved upon the original design specifications after the death of the inventor.  Later the design was stolen and widely circulated to a number of 'backyard' workshops who produced the ship in vast numbers.  Mainly used as a single-pilot combat craft, typically by pirates.");
   ship.AddAttribute(text);

   //May not be visible from both sides unless this option is set.
   geom_laser.SetTwoSided(TRUE);
   geom_exhaust.SetTwoSided(TRUE);

   wchar_t ship_name[255];
      
   for(LtInt32 i = 0 ; i < 3 ; ++i)
   {
      for(LtInt32 j = 0 ; j < 3 ; ++j)
      {
         //Not a pointer as it doesn't matter if Ship goes out of scope after being added to group.
         LcNwcGroup ship_instance;
         LcNwcTransform transform(i * 100, 0, j * 100);
         
         //Build the Ship up
         ship_instance.AddNode(ship);

         ship_instance.AddAttribute(transform);

         swprintf(&ship_name[0], 255, L"Gecko %d", (i*3) + j + 1);

         //Give each Ship a title in the Selection Tree View
         ship_instance.SetName(ship_name);

         ship_instance.SetClassName(L"Instance","Space CAD Ship Instance");

         //Give each ship an "inserted item" icon in the Selection Tree View
         ship_instance.SetInsert(TRUE);
      
         group.AddNode(ship_instance);
      }
   }

   scene.AddNode(group);

   //Set up an interesting view
   LcNwcView army_view;
   army_view.SetWorldUpVector(0, 1, 0);
   army_view.SetPosition(130.22, 440.42, 63.07);
   army_view.PointAt(114.89, 10.37, 99.23);
   army_view.AlignUp(0, 1, 0);

   //make this view the default view
   scene.SetCurrentView(army_view);

   army_view.SetName(L"Army Attacks");
   scene.AddSavedView(army_view);

   // Add some detail to scene statistics dialog in NavisWorks
   scene.SetStatistics(
      L"Converted 5 Parts\nConverted 1 Ship\nConverted 9 Instances");

   //Save the NavisWorks file
   scene.WriteCache(L"", L"gecko.nwc", LI_NWC_NO_PROGRESS_CALLBACKS, LI_NWC_NO_USER_DATA);
}

void LI_NWC_API 
error_handler(LtNwcSeverity severity, LtString message, void* user_data)
{
   switch (severity)
   {
   case LI_NWC_SEVERITY_ERROR:
      printf("Error: %s\n", message);
      exit(1);
      break;

   case LI_NWC_SEVERITY_WARNING:
      printf("Warning: %s\n", message);
      break;

   default:
      printf("UNKNOWN: %s\n", message);
      exit(1);
      break;
   }
}

int main()
{
   LiNwcApiErrorInitialise();

   switch (LiNwcApiInitialise())
   {
   case LI_NWC_API_OK:
      break;

   case LI_NWC_API_NOT_LICENSED:
      printf("Not Licensed\n");
      return 1;

   case LI_NWC_API_INTERNAL_ERROR:
   default:
      printf("Internal Error\n");
      return 1;
   }

   LiNwcApiSetErrorHandler(&error_handler, NULL);
   do_test();
   LiNwcApiTerminate();

   printf("Done\n");
   return 0;
}
