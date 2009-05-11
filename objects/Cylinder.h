#ifndef CYLINDER_TRACER
#define CYLINDER_TRACER

#include "Object.h"

class Cylinder :public Object
{
  private:
    double r;
    Vector3 a, b;
  public:
    Cylinder(void);
    Cylinder(double r, Vector3 a, Vector3 b, Material mat, bool emmit=false);

    //Ray intersection
    double rayIntersection(Ray &ray);
    //Is the point inside
    bool isInside(Vector3 &point);
    //Getters
    Vector3 getNorm(Vector3 &p);
    Color getColor(Vector3 &point);
    double getR(void);
};

#endif
