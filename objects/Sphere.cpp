#include "Sphere.h"

/* Contructors*/
Sphere::Sphere(): Object()
{
    Sphere(1.0, Vector3(0.0,0.0,0.0),
           Material(Color(0.0,0.0,0.0), 1, 1, 0, 0, 1));
}
Sphere::Sphere(double r, Vector3 pos, Material mat, bool emmit)
    :Object(pos, mat, emmit)
{
    Sphere::r = r;
}

/* 
    Ray intersection
    Returns the t value where the ray intersects the sphere
    If there is no intersection, it returns -1
*/
double Sphere::rayIntersection(Ray ray)
{
    //Calculates A, B and C to use in the quadratic equation
    double A, B, C;
    A = ray.getDir().dot(ray.getDir());
    B = (ray.getOrigin() - pos).dot(ray.getDir()*2);
    C = (ray.getOrigin() - pos).dot(ray.getOrigin() - pos) - r*r;
    
    //Calculate the discriminant
    double discr = B*B - 4*A*C;
    
    //If the discriminant is negative, the intersection
    //Occurs in the complex plane, and we retrun -1
    if(discr < 0.0)
        return -1.0;
    
    double t1 = (-B + sqrt(discr))/(2*A);
    double t2 = (-B - sqrt(discr))/(2*A);
    
    //Return the smallest t, because it was the first intersection
    return (t1 < t2)?t1:t2;
}

/* Getters */
Vector3 Sphere::getNorm(Vector3 p)
{
    return (p-pos).normalize();
}

double Sphere::getR()
{
    return r;
}

/* Gets the color in the specified object point
 * USED FOR TEXTURES ONLY
 */
Color Sphere::getColor(Vector3 point)
{
    return Color(0,0,0);
}


