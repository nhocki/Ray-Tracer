#include "Camera.h"

Camera::Camera(){}

Camera::Camera(double fovx, double width, double height, Vector3 pos, Vector3 lookAt, Vector3 up)
{
    Camera::pos = pos;
    Camera::fovx = fovx;
    Camera::width = width;
    Camera::height = height;

    dist = (lookAt - pos).magnitude();
    
    //Orthobasis
    v = up.normalize();
    w = (lookAt - pos).normalize();
    u = (w.cross(v)).normalize();

    Vector3 dest = pos + w*dist;

    //View rectangle calculation
    vw = dist*tan(fovx/2);
    vh = vw*(height/width);
    c = dest + (-u)*vw + (-v)*vh;
}

/*
  Return a ray that passes through the Camera origin
  and a point on the camera plane specified by x and y
 */
Ray Camera::getRay(double x, double y)
{
    Vector3 dest = c + u*2*vw*x/width + v*2*vh*y/height;
    return Ray(pos, dest);
}
