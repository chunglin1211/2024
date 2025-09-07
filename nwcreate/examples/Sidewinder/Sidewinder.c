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
geom_sidewinder_top(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LiNwcGeometryStreamBegin(stream, LI_NWC_VERTEX_NONE);
   LiNwcGeometryStreamTriangleVertex(stream, 0, 5, 0);
   LiNwcGeometryStreamTriangleVertex(stream, 20, 20, 0);
   LiNwcGeometryStreamTriangleVertex(stream, 25, 0, 5);

   LiNwcGeometryStreamTriangleVertex(stream, 25, 0, 5);
   LiNwcGeometryStreamTriangleVertex(stream, 30, 20, 0);
   LiNwcGeometryStreamTriangleVertex(stream, 50, 5, 0);

   LiNwcGeometryStreamBeginPolygon(stream);
   LiNwcGeometryStreamBeginPolygonContour(stream);
   LiNwcGeometryStreamConvexPolyVertex(stream, 25, 0, 5);
   LiNwcGeometryStreamConvexPolyVertex(stream, 20, 20, 0);
   LiNwcGeometryStreamConvexPolyVertex(stream, 30, 20, 0);
   LiNwcGeometryStreamEndPolygonContour(stream);
   LiNwcGeometryStreamEndPolygon(stream);

   LiNwcGeometryStreamEnd(stream);


   return TRUE;
}

static LtBoolean LI_NWC_API
geom_sidewinder_bottom(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   LiNwcGeometryStreamBegin(stream, LI_NWC_VERTEX_NONE);
   LiNwcGeometryStreamIndexedVertex(stream, 0, 5, 0);
   LiNwcGeometryStreamIndexedVertex(stream, 20, 20, 0);
   LiNwcGeometryStreamIndexedVertex(stream, 20, 0, -5);

   LiNwcGeometryStreamIndexedVertex(stream, 30, 0, -5);
   LiNwcGeometryStreamIndexedVertex(stream, 30, 20, 0);
   LiNwcGeometryStreamIndexedVertex(stream, 50, 5, 0);

   LiNwcGeometryStreamTriangleIndex(stream, 0);
   LiNwcGeometryStreamTriangleIndex(stream, 1);
   LiNwcGeometryStreamTriangleIndex(stream, 2);

   LiNwcGeometryStreamTriangleIndex(stream, 3);
   LiNwcGeometryStreamTriangleIndex(stream, 4);
   LiNwcGeometryStreamTriangleIndex(stream, 5);

   LiNwcGeometryStreamConvexPolyIndex(stream, 2);
   LiNwcGeometryStreamConvexPolyIndex(stream, 1);
   LiNwcGeometryStreamConvexPolyIndex(stream, 4);
   LiNwcGeometryStreamConvexPolyIndex(stream, 3);
   LiNwcGeometryStreamSeqEnd(stream);

   LiNwcGeometryStreamEnd(stream);

   return TRUE;
}

static LtBoolean LI_NWC_API
geom_sidewinder_rear(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{

   /* The rear of the ship can be built with a Triangle Fan */
   LiNwcGeometryStreamBegin(stream, LI_NWC_VERTEX_NONE);
   LiNwcGeometryStreamTriFanVertex(stream, 25, 0, 5);
   LiNwcGeometryStreamTriFanVertex(stream, 0, 5, 0);
   LiNwcGeometryStreamTriFanVertex(stream, 20, 0, -5);
   LiNwcGeometryStreamTriFanVertex(stream, 30, 0, -5);
   LiNwcGeometryStreamTriFanVertex(stream, 50, 5, 0);
   LiNwcGeometryStreamSeqEnd(stream);
   LiNwcGeometryStreamEnd(stream);
  
   return TRUE;
}

static LtBoolean LI_NWC_API
geom_sidewinder_exhaust(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   /* Must always start with a Begin and finish with an End */
   LiNwcGeometryStreamBegin(stream, LI_NWC_VERTEX_NONE);

   LiNwcGeometryStreamBeginPolygon(stream);

   /* The exhaust is just a thick square
      This is the outside edge */
   LiNwcGeometryStreamBeginPolygonContour(stream);
   LiNwcGeometryStreamPolygonVertex(stream, 20,-0.1,0);
   LiNwcGeometryStreamPolygonVertex(stream, 25,-0.1,-3);
   LiNwcGeometryStreamPolygonVertex(stream, 30,-0.1,0);
   LiNwcGeometryStreamPolygonVertex(stream, 25,-0.1,3);
   LiNwcGeometryStreamEndPolygonContour(stream);
   
   /* This is the inside edge */
   LiNwcGeometryStreamBeginPolygonContour(stream);
   LiNwcGeometryStreamPolygonVertex(stream, 22.5,-0.1,0);
   LiNwcGeometryStreamPolygonVertex(stream, 25,  -0.1,-1.5);
   LiNwcGeometryStreamPolygonVertex(stream, 27.5,-0.1,0);
   LiNwcGeometryStreamPolygonVertex(stream, 25,  -0.1,1.5);
   LiNwcGeometryStreamEndPolygonContour(stream);

   LiNwcGeometryStreamEndPolygon(stream);

   LiNwcGeometryStreamEnd(stream);
  
   return TRUE;
}

static LtBoolean LI_NWC_API
geom_sidewinder_laser(LtNwcGeometry geometry, LtNwcGeometryStream stream, void* user_data)
{
   /* We want to remember the vertex colors */
   LiNwcGeometryStreamBegin(stream, LI_NWC_VERTEX_COLOR);

   LiNwcGeometryStreamColor(stream, 1,0.2,0,1);
   LiNwcGeometryStreamTriangleVertex(stream, 20, 20, 0);

   LiNwcGeometryStreamColor(stream, 0,0,1,1);
   LiNwcGeometryStreamTriangleVertex(stream, 20, 500, 0);

   LiNwcGeometryStreamColor(stream, 0,0,1,1);
   LiNwcGeometryStreamTriangleVertex(stream, 25, 500, 0);

   LiNwcGeometryStreamColor(stream, 1,0.2,0,1);
   LiNwcGeometryStreamTriangleVertex(stream, 30, 20, 0);

   LiNwcGeometryStreamColor(stream, 0,0,1,1);
   LiNwcGeometryStreamTriangleVertex(stream, 30, 500, 0);

   LiNwcGeometryStreamColor(stream, 0,0,1,1);
   LiNwcGeometryStreamTriangleVertex(stream, 25, 500, 0);

   LiNwcGeometryStreamEnd(stream);

   return TRUE;
}

static void
do_test(void)
{
   LtNwcScene scene;
   LtNwcGroup group, ship;
   LtNwcGeometry geom_top, geom_bottom, geom_rear, geom_laser, geom_exhaust;
   LtNwcMaterial top_material, bottom_material, rear_material, exhaust_material;
   LtNwcTextAttribute text;
   LtNwcPropertyAttribute specification;
   LtNwcData armaments, cargo, max_velocity, hyperspace_capable;
   wchar_t ship_name[255];
   LtInt32 i, j;
   LtNwcGroup ship_instance;
   LtNwcTransform transform;
   LtNwcView army_view;

   scene = LiNwcSceneCreate();
   group = LiNwcGroupCreate();
   ship = LiNwcGroupCreate();
   geom_top = LiNwcGeometryCreate();
   geom_bottom = LiNwcGeometryCreate();
   geom_rear = LiNwcGeometryCreate();
   geom_laser = LiNwcGeometryCreate();
   geom_exhaust = LiNwcGeometryCreate();

   LiNwcNodeSetName(LI_BASE(geom_top), L"Sidewinder top");
   LiNwcNodeSetName(LI_BASE(geom_bottom), L"Sidewinder bottom");
   LiNwcNodeSetName(LI_BASE(geom_rear), L"Sidewinder rear");
   LiNwcNodeSetName(LI_BASE(geom_laser), L"Sidewinder laser");
   LiNwcNodeSetName(LI_BASE(geom_exhaust), L"Sidewinder exhaust");

   LiNwcNodeSetClassName(LI_BASE(geom_top), L"Part","Space CAD Ship Part");
   LiNwcNodeSetClassName(LI_BASE(geom_bottom), L"Part","Space CAD Ship Part");
   LiNwcNodeSetClassName(LI_BASE(geom_rear), L"Part","Space CAD Ship Part");
   LiNwcNodeSetClassName(LI_BASE(geom_laser), L"Part","Space CAD Ship Part");
   LiNwcNodeSetClassName(LI_BASE(geom_exhaust), L"Part","Space CAD Ship Part");

   top_material = LiNwcMaterialCreate();
   /* Set ambient and diffuse color so that the color will remain whatever the lighting is */
   LiNwcMaterialSetDiffuseColor(top_material, 0.9,0.9,0.9);
   LiNwcMaterialSetAmbientColor(top_material, 0.9,0.9,0.9);
   /* Set the colour for the whole group and everything inside it */
   LiNwcNodeAddAttribute(LI_BASE(geom_top), LI_BASE(top_material));
   LiNwcMaterialDestroy(top_material);
   
   bottom_material = LiNwcMaterialCreate();
   LiNwcMaterialSetDiffuseColor(bottom_material, 0.5,0.5,0.5);
   LiNwcMaterialSetAmbientColor(bottom_material, 0.5,0.5,0.5);
   LiNwcNodeAddAttribute(LI_BASE(geom_bottom), LI_BASE(bottom_material));
   LiNwcMaterialDestroy(bottom_material);

   rear_material = LiNwcMaterialCreate();
   LiNwcMaterialSetDiffuseColor(rear_material, 1,0,0);
   LiNwcMaterialSetAmbientColor(rear_material, 1,0,0);
   LiNwcNodeAddAttribute(LI_BASE(geom_rear), LI_BASE(rear_material));
   LiNwcMaterialDestroy(rear_material);

   exhaust_material = LiNwcMaterialCreate();
   LiNwcMaterialSetDiffuseColor(exhaust_material, 1,0.1,0.1);
   LiNwcMaterialSetAmbientColor(exhaust_material, 1,0.1,0.1);
   LiNwcNodeAddAttribute(LI_BASE(geom_exhaust), LI_BASE(exhaust_material));
   LiNwcMaterialDestroy(exhaust_material);

#if 1
   /* Using callbacks is the preferred method, although unused code below performs the same task */
   LiNwcGeometrySetCallback(geom_top, &geom_sidewinder_top, LI_NWC_NO_USER_DATA);
   LiNwcGeometrySetCallback(geom_bottom, &geom_sidewinder_bottom, LI_NWC_NO_USER_DATA);
   LiNwcGeometrySetCallback(geom_rear, &geom_sidewinder_rear, LI_NWC_NO_USER_DATA);
   LiNwcGeometrySetCallback(geom_laser, &geom_sidewinder_laser, LI_NWC_NO_USER_DATA);
   LiNwcGeometrySetCallback(geom_exhaust, &geom_sidewinder_exhaust, LI_NWC_NO_USER_DATA);
#else
   LcNwcGeometryStream stream_sidewinder_top = geom_top.OpenStream();
   LcNwcGeometryStream stream_sidewinder_bottom = geom_bottom.OpenStream();
   LcNwcGeometryStream stream_sidewinder_rear = geom_rear.OpenStream();
   LcNwcGeometryStream stream_sidewinder_laser = geom_laser.OpenStream();
   LcNwcGeometryStream stream_sidewinder_exhaust = geom_exhaust.OpenStream();

   geom_sidewinder_top(geom_top, stream_sidewinder_top, LI_NWC_NO_USER_DATA);
   geom_sidewinder_bottom(geom_bottom, stream_sidewinder_bottom, LI_NWC_NO_USER_DATA);
   geom_sidewinder_rear(geom_rear, stream_sidewinder_rear, LI_NWC_NO_USER_DATA);
   geom_sidewinder_laser(geom_laser, stream_sidewinder_laser, LI_NWC_NO_USER_DATA);
   geom_sidewinder_exhaust(geom_exhaust, stream_sidewinder_exhaust, LI_NWC_NO_USER_DATA);

   geom_top.CloseStream(stream_sidewinder_top);
   geom_bottom.CloseStream(stream_sidewinder_bottom);
   geom_rear.CloseStream(stream_sidewinder_rear);
   geom_laser.CloseStream(stream_sidewinder_laser);
   geom_exhaust.CloseStream(stream_sidewinder_exhaust);

#endif

   LiNwcNodeSetName(LI_BASE(group), L"Sidewinder Army");
   
   /* Give the Sidewinder Army an "layer" icon in the Selection Tree View */
   LiNwcGroupSetLayer(group, TRUE);
   LiNwcNodeSetClassName(LI_BASE(group), L"Layer","Space CAD Layer");

   LiNwcNodeSetName(LI_BASE(ship), L"Sidewinder");
   LiNwcNodeSetClassName(LI_BASE(ship), L"Ship","Space CAD Ship");

   LiNwcGroupAddNode(ship, LI_BASE(geom_top)); 
   LiNwcGeometryDestroy(geom_top);
   LiNwcGroupAddNode(ship, LI_BASE(geom_bottom));
   LiNwcGeometryDestroy(geom_bottom);
   LiNwcGroupAddNode(ship, LI_BASE(geom_rear));
   LiNwcGeometryDestroy(geom_rear);
   
   LiNwcGroupAddNode(ship, LI_BASE(geom_laser));
   LiNwcGeometryDestroy(geom_laser);
   LiNwcGroupAddNode(ship, LI_BASE(geom_exhaust));
   LiNwcGeometryDestroy(geom_exhaust);
   
   /*Create a ship specification comprised of a series of properties.*/
   specification = LiNwcPropertyAttributeCreate();
   LiNwcAttributeSetClassName(LI_BASE(specification),L"Specification","spec");
   LiNwcAttributeSetName(LI_BASE(specification),L"Sidewinder Specification");

   armaments = LiNwcDataCreate();
   LiNwcDataSetWideString(armaments,L"Dual 22-18 lasers, Seeker missiles.");
   LiNwcPropertyAttributeAddProperty(specification,L"Armaments","Specification Armaments",armaments);
   LiNwcDataDestroy(armaments);

   cargo = LiNwcDataCreate();
   LiNwcDataSetInt32(cargo,0);
   LiNwcPropertyAttributeAddProperty(specification,L"Cargo (TC)","Specification Cargo",cargo);
   LiNwcDataDestroy(cargo);

   max_velocity = LiNwcDataCreate();
   LiNwcDataSetFloat(max_velocity,0.37);
   LiNwcPropertyAttributeAddProperty(specification,L"Maximum Velocity","Specification Maximum Velocity",max_velocity);
   LiNwcDataDestroy(max_velocity);

   hyperspace_capable = LiNwcDataCreate();
   LiNwcDataSetBoolean(hyperspace_capable,TRUE);
   LiNwcPropertyAttributeAddProperty(specification,L"Hyperspace","Specification Hyperspace",hyperspace_capable);
   LiNwcDataDestroy(hyperspace_capable);

   LiNwcNodeAddAttribute(LI_BASE(ship), LI_BASE(specification));
   LiNwcPropertyAttributeDestroy(specification);

   /* Attach some generic text to the Ship...
      Description is not a magic string *but* infact a tab item is created called "Description" */
   text = LiNwcTextAttributeCreate();
   LiNwcAttributeSetClassName(LI_BASE(text), L"Description", "descr");
   LiNwcAttributeSetName(LI_BASE(text), L"Sidewinder Description");
   LiNwcTextAttributeSetText(text, L"Designed by Faulcon de Lacy and built in the Onrira Orbital Shipyards by Splader and Starblaze Inc. to Galactic Navy specifications for a multi-purpose support craft.  Mainly used for atmosphere and planetary surface scouting.");
   LiNwcNodeAddAttribute(LI_BASE(ship), LI_BASE(text));
   LiNwcTextAttributeDestroy(text);

   /* May not be visible from both sides unless this option is set. */
   LiNwcNodeSetTwoSided(LI_BASE(geom_laser), TRUE);
   LiNwcNodeSetTwoSided(LI_BASE(geom_exhaust), TRUE);
      
   for(i = 0 ; i < 3 ; ++i)
   {
      for(j = 0 ; j < 3 ; ++j)
      {
         /* Not a pointer as it doesn't matter if Ship goes out of scope after being added to group. */
         ship_instance = LiNwcGroupCreate();
         transform = LiNwcTransformCreateTrans(i * 100, 0, j * 100);
         
         /* Build the Ship up */
         LiNwcGroupAddNode(ship_instance, LI_BASE(ship));

         LiNwcNodeAddAttribute(LI_BASE(ship_instance), LI_BASE(transform));
         LiNwcTransformDestroy(transform);

         swprintf(&ship_name[0],255,L"Sidewinder %d", (i*3) + j + 1);

         /* Give each Ship a title in the Selection Tree View */
         LiNwcNodeSetName(LI_BASE(ship_instance), ship_name);

         LiNwcNodeSetClassName(LI_BASE(ship_instance), L"Instance","Space CAD Ship Instance");

         /* Give each ship_instance an "inserted item" icon in the Selection Tree View */
         LiNwcGroupSetInsert(ship_instance, TRUE);
      
         LiNwcGroupAddNode(group, LI_BASE(ship_instance));
         LiNwcGroupDestroy(ship_instance);
      }
   }
   LiNwcGroupDestroy(ship);

   LiNwcSceneAddNode(scene, LI_BASE(group));
   LiNwcGroupDestroy(group);

   /* Set up an interesting view */
   army_view = LiNwcViewCreate();
   LiNwcViewSetWorldUpVector(army_view, 0, 1, 0);
   LiNwcViewSetPosition(army_view, 130.22, 440.42, 63.07);
   LiNwcViewPointAt(army_view, 114.89, 10.37, 99.23);
   LiNwcViewAlignUp(army_view, 0, 1, 0);

   /* Use LI_BASE macro to safely class LtNwcView handle to base
   // clase LtNwcSavedView handle
   */
   LiNwcSavedViewSetName(LI_BASE(army_view), L"Army Attacks");
   LiNwcSceneAddSavedView(scene, LI_BASE(army_view));

   /* make this view the default view */
   LiNwcSceneSetCurrentView(scene, army_view);
   LiNwcViewDestroy(army_view);

   /* Add some detail to scene statistics dialog in NavisWorks */
   LiNwcSceneSetStatistics(scene, 
      L"Converted 5 Parts\nConverted 1 Ship\nConverted 9 Instances");

   /* Save the NavisWorks file */
   LiNwcSceneWriteCache(scene, L"", L"sidewinder.nwc", LI_NWC_NO_PROGRESS_CALLBACKS, LI_NWC_NO_USER_DATA);

   /* Only operation allowed on a scene after write is destroy */
   LiNwcSceneDestroy(scene);
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

int main(void)
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

