#include "Ray.h"

/* Contructor */
Ray::Ray(Vector3 origin, Vector3 dest)
{
    Ray::origin = origin;
    Ray::dir = (dest - origin).normalize();
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

Vector3 Ray::getPoint(double t)
{
    return origin + (dir*t);
}
