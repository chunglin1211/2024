//
// Copyright 2010 Autodesk, Inc.  All rights reserved.
//
// This software is provided as part of the NavisWorks SDK.  Use
// of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or 
// which otherwise accompanies this software in either electronic or
// hard copy form.
//

// Simulation of the sort of interface an external point engine would provide. This
// engine "manages" an evenly spaced cube of points with varying colors. The engine
// "loads" a subset of the points in the cube at a time. The engine exposes a Visitor
// pattern interface which returns multiple sets of points that fit within a frustum defined
// by six planes.

class Point
{
public:
   Point()
   {
      m_pt[0] = m_pt[1] = m_pt[2] = 0;
   }

   Point(float x, float y, float z)
   {
      m_pt[0] = x;
      m_pt[1] = y;
      m_pt[2] = z;
   }

   Point(double pt[3])
   {
      m_pt[0] = float(pt[0]);
      m_pt[1] = float(pt[1]);
      m_pt[2] = float(pt[2]);
   }

   Point(const Point& pt)
   {
      m_pt[0] = pt[0];
      m_pt[1] = pt[1];
      m_pt[2] = pt[2];
   }
   Point& operator=(const Point& pt)
   {
      m_pt[0] = pt[0];
      m_pt[1] = pt[1];
      m_pt[2] = pt[2];
      return *this;
   }

   const float* GetValue() const { return m_pt; }
   const float& operator[] (int i) const 
   { return m_pt[i]; }
   float& operator[] (int i) 
   { return m_pt[i]; }

   Point TransformedBy(double matrix[16]) const;

   friend Point operator+(const Point& v1, const Point& v2)
   { return Point(v1[0]+v2[0],v1[1]+v2[1],v1[2]+v2[2]); }
   friend Point operator-(const Point& v1, const Point& v2)
   { return Point(v1[0]-v2[0],v1[1]-v2[1],v1[2]-v2[2]); }
   friend Point operator*(const Point& v1, float d)
   { return Point(v1[0]*d,v1[1]*d,v1[2]*d); }
   friend Point operator/(const Point& v1, float d)
   { return Point(v1[0]/d,v1[1]/d,v1[2]/d); }

private:
   float m_pt[3];
};

// Plane defined by a normal (x,y,z) and distance. For any point on the
// plane, point Dot normal = distance.
class Plane
{
public:
   Plane() : m_x(1), m_y(0), m_z(0), m_d(0) {}
   Plane(double x, double y, double z, double d) : m_x(x), m_y(y), m_z(z), m_d(d) {}

   Plane(const Plane& p)
   {
      m_x = p.m_x;
      m_y = p.m_y;
      m_z = p.m_z;
      m_d = p.m_d;
   }
   Plane& operator=(const Plane& p)
   {
      m_x = p.m_x;
      m_y = p.m_y;
      m_z = p.m_z;
      m_d = p.m_d;
      return *this;
   }

   Plane TransformedByInverse(double matrix[16]) const;

   double MaxDistanceFromPlane(const Point& min_pt, const Point& max_pt);

private:
   double m_x, m_y, m_z, m_d;
};

class PointEngineVisitor
{
public:
   PointEngineVisitor() : m_num_planes(0) {}

   virtual void Points(int num, const Point* points, const unsigned char* rgba) =0;

   bool Cull(const Point& min_pt, const Point& max_pt);

   void SetNumCullPlanes(int num) { m_num_planes = num; }
   void SetCullPlane(int index, const Plane& plane) { m_planes[index] = plane; }

private:
   int m_num_planes;
   Plane m_planes[6];
};

class PointEngine
{
public:
   static void Initialise();
   static void Terminate();

   PointEngine(int num, const Point& min_pt, const Point& max_pt)
      : m_num(num), m_min_pt(min_pt), m_max_pt(max_pt) {}

   void Visit(PointEngineVisitor* visitor)
   { VisitR(visitor, m_num, m_min_pt, Point(0,0,0), m_max_pt, Point(1,1,1)); }

private:
   void VisitR(PointEngineVisitor* visitor, int num, const Point& min_pt, const Point& min_col, 
      const Point& max_pt, const Point& max_col);
   void FillBuffer(int num, const Point& min_pt, const Point& min_col, 
      const Point& max_pt, const Point& max_col);

   int m_num;
   Point m_min_pt;
   Point m_max_pt;
};

