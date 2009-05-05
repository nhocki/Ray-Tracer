#ifndef RAY_TRACER
#define RAY_TRACER
#include "Vector3.h"
#include <math.h>

class Ray
{
    private:
        double t;
        Vector3 origin, dir;

    public:
        Ray(Vector3 origin, Vector3 dest);
        Vector3 getOrigin(void);
        Vector3 getDir(void);
        Vector3 getnnDir(void);
        Vector3 getPoint(double t);
        double getT(Vector3 point);
};

#endif
