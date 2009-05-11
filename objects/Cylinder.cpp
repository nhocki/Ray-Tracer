#include "Cylinder.h"
#include <iostream>

/*
  Constructos
 */
Cylinder::Cylinder()
{
}

Cylinder::Cylinder(double r, Vector3 a, Vector3 b, Material mat, bool emmit)
    :Object((a+b)*0.5, mat, emmit)
{
    Cylinder::r = r;
    Cylinder::a = a;
    Cylinder::b = b;
}

/* 
    Ray intersection
    Returns the t value where the ray intersects the cylinder
    If there is no intersection, it returns -1
*/
double Cylinder::rayIntersection(Ray ray)
{
    Vector3 AB = (b - a);
    Vector3 AO = (ray.getOrigin() - a);
    Vector3 AOxAB = (AO.cross(AB));
    Vector3 VxAB = (ray.getDir().cross(AB));
    double ab2 = (AB.dot(AB));
    double A = (VxAB.dot(VxAB));
    double B = 2 * (VxAB.dot(AOxAB));
    double C = (AOxAB.dot(AOxAB)) - (r*r * ab2);

    double discr = B*B-4*A*C;

    if(discr<0)return -1;

    double t1 = (-B + sqrt(discr))/(2*A);
    double t2 = (-B - sqrt(discr))/(2*A);

    double t = (t1 < t2)?t1:t2;
    if(t < 0)
        t = (t1 > t2)?t1:t2;



    //Return the smallest t greater than 0, because it was the first intersection
    return t;
}

bool Cylinder::isInside(Vector3 point)
{
    double dist = (point - pos).magnitudeSquared();
    return (dist <= r*r);
}

/* Getters */
Vector3 Cylinder::getNorm(Vector3 p)
{
    Vector3 n = Vector3(p[0]-pos[0], 0, p[2]-pos[2]).normalize();
    return n;
}

double Cylinder::getR()
{
    return r;
}

/* Gets the color in the specified object point
 * USED FOR TEXTURES ONLY
 */
Color Cylinder::getColor(Vector3 point)
{
    return Color(0,0,0);
}
