#ifndef OBJECT_TRACER
#define OBJECT_TRACER
#include "../math/Vector3.h"
#include "../math/Ray.h"
#include "../Util/Color.h"
#include "../Util/Texture.h"

/*
  Material struct
  Saves information about the object color, reflection, refraction, etc
 */
struct Material
{
  Color color;
  double diff, spec, refl, refr, rIndex;
  Material();
  Material(Color color, double diff, double spec, double refl, double refr, double rIndex);
};

/*
  Abstract class that every object must implement
 */
class Object
{
    protected:
    //Position
    Vector3 pos;
    //materials
    Material mat;
    //Texture
    bool hasT;
    Texture tex;
    //Emit light?
    bool emmit;
    
    public:
    Object();
    Object(Vector3 pos, Material mat, bool emmit=false);
    Object(Vector3 pos, Material mat, Texture tex, bool emmit=false);
    virtual double rayIntersection(Ray ray)=0;
    virtual Vector3 getNorm(Vector3 p)=0;
    
    //texture
    Texture getTex(void);
    bool hasTex(void);
    virtual Color getColor(Vector3 point)=0;
    
    //Getters
    Vector3 getPos(void);
    Material getMat(void);
    bool emmitLight(void);
};

#endif
