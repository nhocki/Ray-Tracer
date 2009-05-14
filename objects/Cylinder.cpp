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
    Cylinder::dir = (a-b).normalize();
}

/* 
    Ray intersection
    Returns the t value where the ray intersects the cylinder
    If there is no intersection, it returns -1
*/
double Cylinder::rayIntersection(Ray &ray)
{
    //Check the intersection with the upper plane
    double dotP1 = dir.dot(ray.getDir());
    if(dotP1 < 0)
    {
        double d1 = -(dir.dot(a));
        double t1 = -(d1 + dir.dot(ray.getOrigin()))/dotP1;
        Vector3 p1 = ray.getPoint(t1);

        if((p1-a).magnitudeSquared() <= r*r)
            return t1;
    }
    //Check the intersection with the lower plane
    double dotP2 = (-dir).dot(ray.getDir());
    if(dotP2 < 0)
    { 
        double d2 = -((-dir).dot(b));
        double t2 = -(d2 + (-dir).dot(ray.getOrigin()))/dotP2;
        Vector3 p2 = ray.getPoint(t2);

        if((p2-b).magnitudeSquared() <= r*r)
            return t2;
    }

    //Check the intersection with the torso
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

    if(t>=0)
    {
        Vector3 point = ray.getPoint(t);
        double dotA = (point-a).dot(dir);
        double dotB = (point-b).dot(-dir);
        if(dotA > 0 || dotB > 0)
            t = -1;
    }

    //Return the smallest t greater than 0, because it was the first intersection
    return t;
}

bool Cylinder::isInside(Vector3 &point)
{
    double dist = (point - pos).magnitudeSquared();
    return (dist <= r*r);
}

/* Getters */
Vector3 Cylinder::getNorm(Vector3 &p)
{
    //Check if the point is on the upper plane
    double d1 = -(dir.dot(a));
    if(fabs(dir.dot(p) + d1) <= eps)
        return (dir);
    //Check if the point is on the lower plane
    double d2 = -((-dir).dot(b));
    if(fabs((-dir).dot(p) + d2) <= eps)
        return (-dir);

    //Find the normal vector to the plane formed by a, b and p
    Vector3 perpendicular = (p-b).cross(dir);
    //The cylinder direction cross this vector will give me the normal
    return (dir.cross(perpendicular)).normalize();

    Vector3 n = (Vector3(p[0]-pos[0], 0, p[2]-pos[2]).normalize()).normalize();
    return n;
}

double Cylinder::getR()
{
    return r;
}

/* Gets the color in the specified object point
 * USED FOR TEXTURES ONLY
 */
Color Cylinder::getColor(Vector3 &point)
{
    return Color(0,0,0);
}
