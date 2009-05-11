#ifndef CAMERA_TRACER
#define CAMERA_TRACER

#include "../math/Vector3.h"
#include "../math/Ray.h"

class Camera
{
  private:
    //Orthobasis and position
    Vector3 pos, u, v, w;
    Vector3 c;
    double dist;
    double fovx;
    //Screen width and height, and virtual plane width and height
    double width, height, vw, vh;

    void setUp(void);

  public:
    Camera(void);
    Camera(double fovx, double width, double height, Vector3 pos, Vector3 lookAt, Vector3 up);
    void changeDim(double width, double height);
    Ray getRay(double x, double y);
};

#endif
