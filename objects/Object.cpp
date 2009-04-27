#include "Object.h"

/* Contructors */
Object::Object()
{
    //Object(Vector3(0,0,0), Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f), 1.0);
}
Object::Object(Vector3 pos, Color amb, Color diff, Color spec, double shin)
{
    Object::pos = pos;
    Object::amb = amb;
    Object::diff = diff;
    Object::spec = spec;
    Object::shin = shin;
}

/* Getters */
Vector3 Object::getPos()
{
    return pos;
}

Color Object::getAmb(void)
{
    return amb;
}

Color Object::getDiff(void)
{
    return diff;
}

Color Object::getSpec(void)
{
    return spec;
}

double Object::getShin(void)
{
    return shin;
}
