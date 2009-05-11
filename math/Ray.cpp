#include "Ray.h"

/* Contructor */
Ray::Ray(Vector3 origin, Vector3 dir)
{
    Ray::origin = origin;
    Ray::dir = dir;
}

/*
    Getters
*/
Vector3 Ray::getOrigin(void)
{
    return origin;
}

Vector3 Ray::getDir(void)
{
    return dir;
}

Vector3 Ray::getnnDir(void)
{
    return dir;
}
/* 
   Return a point given a t value
 */
Vector3 Ray::getPoint(double t)
{
    return origin + (dir*t);
}
/* 
   Return a t value given a point
   if there is not such value, returns -1
 */
double Ray::getT(Vector3 p)
{
    double t = (p[0]-origin[0])/dir[0];
    if(fabs(t - (p[1]-origin[1])/dir[1]) <= eps && fabs(t - (p[2]-origin[2])/dir[2]) <= eps)
        return t;
    return -1;    
}
