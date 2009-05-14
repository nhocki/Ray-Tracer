#include "PhotonMap.h"

PhotonMap::PhotonMap(void)
{
    // Initializes the seed
    srand((unsigned)time(0)); 
}

void PhotonMap::throwPhoton(Ray ray, vector<Object*>&objects, Color intensity)
{
    //Get the nearest intersection
    Object *o;
    double mint = INT_MAX, t=0;
    bool intersect=false;
    for(int i = 0; i < objects.size(); ++i)
    {
        t = objects[i]->rayIntersection(ray);
	    
        //We had an intersection!!
        if(t > 0 && t < mint)
        {
            mint = t;
            intersect = true;
            o = objects[i];
        }
    }
    //No intersection
    if(!intersect)return;

    //Get intersection point
    Vector3 point = ray.getPoint(t);

    //Russian Roulette
    //For now we calculate the diffuse reflection with a 50/50 chance
    double roulette = (double)rand()/(double)RAND_MAX;
    if(roulette <= o->getMat().refl)
    {
    }
    else if(roulette <= 0.5)
    {
    }
    else
        photons.push_back(Photon(point, ray.getDir(), intensity));
}

/*
  Generate photons from the sepcified light source to the scene.
  *******For now I treat everything as a point light**********
 */
void PhotonMap::generatePhotons(Light light, vector<Object*>&objects, int num)
{
    //Throw a photon in a random direction
    for(int i = 0; i < num; ++i)
    {
        Vector3 dir=Vector3((double)rand()/(double)RAND_MAX, (double)rand()/(double)RAND_MAX, 
                            (double)rand()/(double)RAND_MAX).normalize();
        Ray ray(light.pos, dir);
        throwPhoton(ray, objects, light.diffuse);
    }
}

/*
  Get the color intensity given by the photons on the specified position
 */
Color PhotonMap::getIntensity(Vector3 point, double r)
{
}
