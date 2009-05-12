#ifndef WALL_TRACER
#define WALL_TRACER
#include "Object.h"

/* Class Wall
 *  Contains all the necesary info about the Walls
 */
class Wall :public Object
{
private:
    //Lower left corner and upper right corner, and the tesselation
    Vector3 min, max;
    //Plane Ecuation
    double a,b,c,d;
    bool infinite;
public:
    Wall(void);
    Wall(Vector3 min, Vector3 max, Vector3 other, Material mat, 
         bool emmit=false, bool infinite=false);
    Wall(Vector3 min, Vector3 max, Vector3 other, Material mat, 
         Texture tex, bool emit=false, bool infinite = false);
    
    //Is the point inside
    bool isInside(Vector3 &point);
    
    //Getters
    Vector3 getNorm(Vector3 &p);
    Vector3 getMin(void);
    Vector3 getMax(void);
    double getA(void);
    double getB(void);
    double getC(void);
    double getD(void);
    
    Color getColor(Vector3 &point);
    
    double rayIntersection(Ray &ray);
};
#endif
