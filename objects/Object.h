#ifndef OBJECT_TRACER
#define OBJECT_TRACER
#include "../math/Vector3.h"
#include "../math/Ray.h"
#include "../Util/Color.h"

class Object
{
    protected:
    //Position
    Vector3 pos;
    //materials
    Color amb, diff, spec;
    double shin;
    //texture
    unsigned int tex;
    
    public:
    Object();
    Object(Vector3 pos, Color amb, Color diff, Color spec, double Shin);
    virtual double rayIntersection(Ray ray)=0;
    virtual Vector3 getNorm(Vector3 p)=0;
    
    //Getters
    Vector3 getPos(void);
    Color getAmb(void);
    Color getDiff(void);
    Color getSpec(void);
    double getShin(void);
};

#endif
