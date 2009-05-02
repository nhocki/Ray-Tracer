#ifndef OBJECT_TRACER
#define OBJECT_TRACER
#include "../math/Vector3.h"
#include "../math/Ray.h"
#include "../Util/Color.h"
#include "../Util/Texture.h"

class Object
{
    protected:
    //Position
    Vector3 pos;
    //materials
    Color amb, diff;
    double shin, spec;
    //Refraction
    double opaque;
    double refr;
    //Texture
    bool hasT;
    Texture tex;
    
    public:
    Object();
    Object(Vector3 pos, Color amb, Color diff, double spec, double Shin, double refr, double opaque);
    Object(Vector3 pos, double Shin, double refr, double opaque, Texture tex);
    virtual double rayIntersection(Ray ray)=0;
    virtual Vector3 getNorm(Vector3 p)=0;
    
    //texture
    Texture getTex(void);
    bool hasTex(void);
    virtual Color getColor(Vector3 point)=0;
    
    //Getters
    Vector3 getPos(void);
    Color getAmb();
    Color getDiff();
    double getSpec();
    double getShin(void);
    double getOpaque(void);
};

#endif
