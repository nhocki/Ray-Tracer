#ifndef LIGHT_TRACER
#define LIGHT_TRACER
#include "../math/Vector3.h"
#include "Color.h"

enum Type {GLOBAL, DIRECTIONAL, SPOTLIGHT};

struct Light
{
    Vector3 pos;
    Type type;
    Color ambient, specular, diffuse;
    
    //Contructors
    Light(void);
    Light(Vector3 pos, Color ambient, Color diffuse, Color specular, Type type);
};

#endif
