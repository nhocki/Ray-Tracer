#ifndef SPHERE_TRACER
#define SPHERE_TRACER
#include "Object.h"

/* Class Sphere
 *  Contains all the necesary info about the spheres
 */
class Sphere :public Object
{
    private:
    double r;

    public:
    //Contructors
    Sphere(void);
    Sphere(double r, Vector3 pos, Color amb, Color diff, Color spec, double shin);

    //Ray intersection
    double rayIntersection(Ray ray);

    //Getters
    Vector3 getNorm(Vector3 p);
    double getR(void);
};
#endif
