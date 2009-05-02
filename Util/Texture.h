#ifndef TEXTURE_TRACER
#define TEXTURE_TRACER
#include <string>
#include "Color.h"
using namespace std;

class Texture
{
private:
    int width, height;
    Color *data;
    
public:
    Texture(void);
    Texture(string filename);
    //Getters
    int getWidth(void);
    int getHeight(void);
    Color* getData(void);
    //Get a pixel, given relative coordinates
    //0,0 = bottom left 1,1 = top right
    Color getColor(double relX, double relY);
};
#endif
