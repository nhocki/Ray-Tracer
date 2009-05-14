#ifndef PHOTON_TRACER
#define PHOTON_TRACER
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "math/Vector3.h"
#include "math/Ray.h"
#include "objects/Sphere.h"
#include "objects/Wall.h"
#include "objects/Cylinder.h"
#include "Util/Light.h"
#include "Util/Color.h"

using namespace std;

/*
  Struct that saves the photn information
 */
struct Photon
{
    Vector3 pos, dir;
    Color color;
  
    Photon(Vector3 pos, Vector3 dir, Color color)
    {
        Photon::pos = pos;
        Photon::dir = dir;
        Photon::color = color;
    }
};

/*
  Builds and stores the photon map
 */
class PhotonMap
{
  private:
    vector<Photon> photons;

  public:
    PhotonMap(void);
    void throwPhoton(Ray ray, vector<Object*>&objects, Color intensity);
    void generatePhotons(Light light, vector<Object*>&objects, int num);
    Color getIntensity(Vector3 point, double r);
};

#endif
