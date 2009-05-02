#include "Light.h"

/* Contructors */
Light::Light(void)
{
    Light(Vector3(5.0, 5.0, 5.0), Color(1.0, 1.0, 1.0), Color(1.0, 1.0, 1.0), Color(1.0, 1.0, 1.0), GLOBAL);
}
Light::Light(Vector3 pos, Color ambient, Color diffuse, Color specular, Type type)
{
    Light::pos = pos;
    Light::ambient = ambient;
    Light::specular = specular;
    Light::diffuse = diffuse;
    Light::type = type;
}
