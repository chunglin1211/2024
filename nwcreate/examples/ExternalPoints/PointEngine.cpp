//
// Copyright 2010 Autodesk, Inc.  All rights reserved.
//
// This software is provided as part of the NavisWorks SDK.  Use
// of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or 
// which otherwise accompanies this software in either electronic or
// hard copy form.
//
#include "PointEngine.h"

#include <math.h>

// Point engine implementation. The Visitor pattern is implemented by recursively splitting the cube of
// points into 8 octants and repeating until small enough to fit into a fixed size buffer. The engine
// minimizes the number of points that the caller needs to process by culling against a set of planes
// at each step in the recursion.

const int cMAX_NUM = 8;
static Point* f_point_buffer = 0;
static unsigned char* f_rgba_buffer = 0;

void
PointEngine::Initialise()
{
   f_point_buffer = new Point[cMAX_NUM*cMAX_NUM*cMAX_NUM];
   f_rgba_buffer = new unsigned char[cMAX_NUM*cMAX_NUM*cMAX_NUM*4];
}

void
PointEngine::Terminate()
{
   delete [] f_point_buffer;
   f_point_buffer = 0;
   delete [] f_rgba_buffer;
   f_rgba_buffer = 0;
}

void 
PointEngine::VisitR(PointEngineVisitor* visitor, int num, const Point& min_pt, const Point& min_col, 
                    const Point& max_pt, const Point& max_col)
{
   if (visitor->Cull(min_pt, max_pt))
      return;

   if (num <= cMAX_NUM)
   {
      FillBuffer(num, min_pt, min_col, max_pt, max_col);
      visitor->Points(num*num*num, f_point_buffer, f_rgba_buffer);
   } else
   {
      Point mid_pt = (min_pt+max_pt)/2;
      Point mid_col = (min_col+max_col)/2;

      Point min_p, max_p, min_c, max_c;

      // MinX, MinY, MinZ Octant
      min_p[0] = min_pt[0]; min_c[0] = min_col[0];
      min_p[1] = min_pt[1]; min_c[1] = min_col[1];
      min_p[2] = min_pt[2]; min_c[2] = min_col[2];
      max_p[0] = mid_pt[0]; max_c[0] = mid_col[0];
      max_p[1] = mid_pt[1]; max_c[1] = mid_col[1];
      max_p[2] = mid_pt[2]; max_c[2] = mid_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);

      // MaX, MinY, MinZ Octant
      min_p[0] = mid_pt[0]; min_c[0] = mid_col[0];
      min_p[1] = min_pt[1]; min_c[1] = min_col[1];
      min_p[2] = min_pt[2]; min_c[2] = min_col[2];
      max_p[0] = max_pt[0]; max_c[0] = max_col[0];
      max_p[1] = mid_pt[1]; max_c[1] = mid_col[1];
      max_p[2] = mid_pt[2]; max_c[2] = mid_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);

      // MinX, MaxY, MinZ Octant
      min_p[0] = min_pt[0]; min_c[0] = min_col[0];
      min_p[1] = mid_pt[1]; min_c[1] = mid_col[1];
      min_p[2] = min_pt[2]; min_c[2] = min_col[2];
      max_p[0] = mid_pt[0]; max_c[0] = mid_col[0];
      max_p[1] = max_pt[1]; max_c[1] = max_col[1];
      max_p[2] = mid_pt[2]; max_c[2] = mid_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);

      // MaX, MaxY, MinZ Octant
      min_p[0] = mid_pt[0]; min_c[0] = mid_col[0];
      min_p[1] = mid_pt[1]; min_c[1] = mid_col[1];
      min_p[2] = min_pt[2]; min_c[2] = min_col[2];
      max_p[0] = max_pt[0]; max_c[0] = max_col[0];
      max_p[1] = max_pt[1]; max_c[1] = max_col[1];
      max_p[2] = mid_pt[2]; max_c[2] = mid_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);

      // MinX, MinY, MaxZ Octant
      min_p[0] = min_pt[0]; min_c[0] = min_col[0];
      min_p[1] = min_pt[1]; min_c[1] = min_col[1];
      min_p[2] = mid_pt[2]; min_c[2] = mid_col[2];
      max_p[0] = mid_pt[0]; max_c[0] = mid_col[0];
      max_p[1] = mid_pt[1]; max_c[1] = mid_col[1];
      max_p[2] = max_pt[2]; max_c[2] = max_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);

      // MaX, MinY, MaxZ Octant
      min_p[0] = mid_pt[0]; min_c[0] = mid_col[0];
      min_p[1] = min_pt[1]; min_c[1] = min_col[1];
      min_p[2] = mid_pt[2]; min_c[2] = mid_col[2];
      max_p[0] = max_pt[0]; max_c[0] = max_col[0];
      max_p[1] = mid_pt[1]; max_c[1] = mid_col[1];
      max_p[2] = max_pt[2]; max_c[2] = max_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);

      // MinX, MaxY, MaxZ Octant
      min_p[0] = min_pt[0]; min_c[0] = min_col[0];
      min_p[1] = mid_pt[1]; min_c[1] = mid_col[1];
      min_p[2] = mid_pt[2]; min_c[2] = mid_col[2];
      max_p[0] = mid_pt[0]; max_c[0] = mid_col[0];
      max_p[1] = max_pt[1]; max_c[1] = max_col[1];
      max_p[2] = max_pt[2]; max_c[2] = max_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);

      // MaX, MaxY, MaxZ Octant
      min_p[0] = mid_pt[0]; min_c[0] = mid_col[0];
      min_p[1] = mid_pt[1]; min_c[1] = mid_col[1];
      min_p[2] = mid_pt[2]; min_c[2] = mid_col[2];
      max_p[0] = max_pt[0]; max_c[0] = max_col[0];
      max_p[1] = max_pt[1]; max_c[1] = max_col[1];
      max_p[2] = max_pt[2]; max_c[2] = max_col[2];
      VisitR(visitor, num/2, min_p, min_c, max_p, max_c);
   }
}

void 
PointEngine::FillBuffer(int num, const Point& min_pt, const Point& min_col, 
                        const Point& max_pt, const Point& max_col)
{
   float* p_xyz = (float*) f_point_buffer;
   unsigned char* p_rgba = f_rgba_buffer;

   Point v = max_pt - min_pt;
   Point vc = max_col - min_col;

   for (int x = 0; x < num; x ++)
   {
      for (int y = 0; y < num; y ++)
      {
         for (int z = 0; z < num; z ++)
         {
            *p_rgba++ = unsigned char((min_col[0]+vc[0]*x/num)*255);
            *p_rgba++ = unsigned char((min_col[1]+vc[1]*y/num)*255); 
            *p_rgba++ = unsigned char((min_col[2]+vc[2]*z/num)*255);
            *p_rgba++ = 255;
            *p_xyz++ = min_pt[0]+v[0]*x/num;
            *p_xyz++ = min_pt[1]+v[1]*y/num;
            *p_xyz++ = min_pt[2]+v[2]*z/num;
         }
      }
   }
}

Point
Point::TransformedBy(double m[16]) const
{
#define MULT_COL(i) (m_pt[0] * m[i] + m_pt[1] * m[4+i] + m_pt[2] * m[8+i] + m[12+i])
   double s = double(1) / MULT_COL(3);
   double x = MULT_COL(0) * s;
   double y = MULT_COL(1) * s;
   double z = MULT_COL(2) * s;
#undef MULT_COL
    
   return Point(float(x), float(y), float(z));
}

double
Plane::MaxDistanceFromPlane(const Point& min_pt, const Point& max_pt)
{
   double sum = -m_d;
   sum += (m_x > 0.0 ? max_pt[0] : min_pt[0]) * m_x;
   sum += (m_y > 0.0 ? max_pt[1] : min_pt[1]) * m_y;
   sum += (m_z > 0.0 ? max_pt[2] : min_pt[2]) * m_z;
   return sum;
}

// Column multiply of plane in form [x y z -d] is equivalent to transforming plane
// definition by inverse of matrix.
Plane
Plane::TransformedByInverse(double m[16]) const
{
#define LCL_MULT(i) \
   (m[4*i] * m_x + m[4*i+1] * m_y + \
    m[4*i+2] * m_z - m[4*i+3] * m_d)

   double x = LCL_MULT(0);
   double y = LCL_MULT(1);
   double z = LCL_MULT(2);
   double w = LCL_MULT(3);
#undef LCL_MULT

   // Convert to normalized representation, we want normal to have unit
   // length.
   double len = sqrt(x * x + y * y + z * z);
   double s = double(1) / len;

   return Plane(x * s, y * s, z * s, -w * s);
}

bool
PointEngineVisitor::Cull(const Point& min_pt, const Point& max_pt)
{
   for (int i = 0; i < m_num_planes; i ++)
   {
      // If all points in box are on negative side of plane can cull out
      if (m_planes[i].MaxDistanceFromPlane(min_pt, max_pt) < 0)
         return true;
   }

   return false;
}
