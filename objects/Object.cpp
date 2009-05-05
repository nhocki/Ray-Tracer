#include "Object.h"

/*
  Class Material
 */

/* Contructor*/
Material::Material()
{
    color = Color(0.0,0.0,0.0);
    diff = 1.0;
    spec = 0.0;
    refl = 0.0;
    refr = 0.0;
    rIndex = 1.0;
}
Material::Material(Color color, double diff, double spec, double refl, double refr, double rIndex)
{
    Material::color = color;
    Material::diff = diff;
    Material::spec = spec;
    Material::refl = refl;
    Material::refr = refr;
    Material::rIndex = rIndex;
}


/* 
   Class Object
 */

/* Contructors */
Object::Object()
{
}
Object::Object(Vector3 pos, Material mat, bool emmit)
{
    Object::pos = pos;
    Object::mat = mat;
    Object::emmit = emmit;  
    hasT = false;
}
Object::Object(Vector3 pos, Material mat, Texture tex, bool emmit)
{
    Object::pos = pos;
    Object::mat = mat;
    Object::tex = tex;
    Object::emmit = emmit;
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
Material Object::getMat()
{
    return mat;
}
/* Emmit light? */
bool Object::emmitLight()
{
    return emmit;
}
