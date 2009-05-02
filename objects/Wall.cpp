#include "Wall.h"
#include <iostream>
using namespace std;
Wall::Wall()
{
    //Wall(Vector3(-20.0f, 0.0f, 20.0f), Vector3(20.0f, 0.0f, -20.0f), Vector3(20.0f, 0.0f, 20.0f), Color(1,1,1), Color(1,1,1), Color(1,1,1), 1);
}

Wall:: Wall(Vector3 min, Vector3 max, Vector3 other, Color amb, Color diff, double spec, double shin, double refr, double opaque)
    :Object((min+max)/2, amb, diff, spec, shin, refr, opaque)
{
    Wall::min = min;
    Wall::max = max;

    Vector3 u = min - other;
    Vector3 v = max - other;
    Vector3 n = v.cross(u).normalize();
    
    a = n[0], b = n[1], c = n[2];
    d = -(a*min[0] + b*min[1] + c*min[2]);
}

Wall:: Wall(Vector3 min, Vector3 max, Vector3 other, double shin, double refr, double opaque, Texture tex)
    :Object((min+max)/2, shin, refr, opaque, tex)
{
    Wall::min = min;
    Wall::max = max;

    Vector3 u = min - other;
    Vector3 v = max - other;
    Vector3 n = v.cross(u).normalize();
    
    a = n[0], b = n[1], c = n[2];
    d = -(a*min[0] + b*min[1] + c*min[2]);
}

/* Get the plane ecuation components
 */
double Wall::getA(void){return a;}
double Wall::getB(void){return b;}
double Wall::getC(void){return c;}
double Wall::getD(void){return d;}

Vector3 Wall::getNorm(Vector3 p)
{
    Vector3 n(a,b,c);
    n.normalize();
    return n;
}

/* Gets the color in the specified object point
 * Used for textures only
 */
Color Wall::getColor(Vector3 p)
{
    return tex.getColor((p[0]-min[0])/14, (p[2]-min[2])/12);
}

/*
    Intersection between a ray and a plane
    If there is no intersection it returns -1
*/
double Wall::rayIntersection(Ray ray)
{
    Vector3 n(a,b,c);
    n;
    double dot = n.dot(ray.getDir());
    if(dot >= 0)return -1;
    
    double t = -(d + n.dot(ray.getOrigin()))/dot;
    
    Vector3 p = ray.getPoint(t);

    if(p >= min && p <= max)
        return t;
    
    return -1;
}
