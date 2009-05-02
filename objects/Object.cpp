#include "Object.h"

/* Contructors */
Object::Object()
{
    //Object(Vector3(0,0,0), Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f), 1.0);
}
Object::Object(Vector3 pos, Color amb, Color diff, double spec, double shin, double refr, double opaque)
{
    Object::pos = pos;
    Object::amb = amb;
    Object::diff = diff;
    Object::spec = spec;
    Object::shin = shin;
    Object::refr = refr;
    Object::opaque = opaque;
    hasT = false;
}
Object::Object(Vector3 pos, double shin, double refr, double opaque, Texture tex)
{
    Object::pos = pos;
    Object::shin = shin;
    Object::tex = tex;
    Object::refr = refr;
    Object::opaque = opaque;
    hasT = true;
}

/* Texture managment
*/
Texture Object::getTex(void)
{
    return tex;
}
bool Object::hasTex(void)
{
    return hasT;
}

/* Getters */
Vector3 Object::getPos()
{
    return pos;
}
Color Object::getAmb()
{
    return amb;
}
Color Object::getDiff()
{
    return diff;
}
double Object::getSpec()
{
    return spec;
}
double Object::getShin(void)
{
    return shin;
}
double Object::getOpaque(void)
{
    return opaque;
}
