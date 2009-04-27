#include "Wall.h"

Wall::Wall()
{
    //Wall(Vector3(-20.0f, 0.0f, 20.0f), Vector3(20.0f, 0.0f, -20.0f), Vector3(20.0f, 0.0f, 20.0f), Color(1,1,1), Color(1,1,1), Color(1,1,1), 1);
}

Wall:: Wall(Vector3 min, Vector3 max, Vector3 other, Color amb, Color diff, Color spec, double shin)
    :Object((min+max)/2, amb, diff, spec, shin)
{
    Wall::min = min;
    Wall::max = max;

    Vector3 u = other - min;
    Vector3 v = other - max;
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
    return Vector3(a,b,c).normalize();
}

/*
    Intersection between a ray and a plane
    If there is no intersection it returns -1
*/
double Wall::rayIntersection(Ray ray)
{
    Vector3 n(a,b,c);
    double dot = n.dot(ray.getDir());
    if(dot == 0)return -1;
    
    double t = -(d + n.dot(ray.getOrigin()))/dot;
    
    Vector3 p = ray.getPoint(t);
    
    if(p[0] >= min[0] && p[0] <= max[0] && p[1] >= min[1] && p[1] <= max[1] && p[2] >= min[2] && p[2] <= max[2])
        return t;
    
    return t;
}
