#include "Sphere.h"

/* Contructors*/
Sphere::Sphere(): Object()
{
    Sphere(1.0, Vector3(0.0,0.0,0.0),
           Material(Color(0.0,0.0,0.0), 1, 1, 0, 0, 1));
}
Sphere::Sphere(double r, Vector3 pos, Material mat, bool emmit)
    :Object(pos, mat, emmit)
{
    Sphere::r = r;
}

/* 
    Ray intersection
    Returns the t value where the ray intersects the sphere
    If there is no intersection, it returns -1
*/
double Sphere::rayIntersection(Ray &ray)
{
    Vector3 RC = pos - ray.getOrigin();
    double lengthRTSC2 = RC.dot(RC);
      
    double cl = RC.dot(ray.getDir());
    if (cl < 0 ) // behind the ray origin
        return -1;
    
    double halfCord2 = r*r - lengthRTSC2 + cl*cl; 
    if(halfCord2 < 0) // no intersection
        return -1;
    
        return cl - sqrt(halfCord2);
}

bool Sphere::isInside(Vector3 &point)
{
    double dist = (point - pos).magnitudeSquared();
    return (dist <= r*r);
}

/* Getters */
Vector3 Sphere::getNorm(Vector3 &p)
{
    return (p-pos).normalize();
}

double Sphere::getR()
{
    return r;
}

/* Gets the color in the specified object point
 * USED FOR TEXTURES ONLY
 */
Color Sphere::getColor(Vector3 &point)
{
    return Color(0,0,0);
}


