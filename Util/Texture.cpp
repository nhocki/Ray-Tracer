#include "Texture.h"
/*
    Contructors
*/
Texture::Texture()
{   
    width = 10, height = 10;
    data = new Color[width*height];
    
    int ind = 0;
    for(int i = 0; i < height; ++i, ind = (ind+1)%2)
    {
        for(int j = 0; j < width; ++j, ind = (ind+1)%2)
        {
            if(ind)
                data[i*width + j] = Color(0.0, 0.0, 0.0);
            else
                data[i*width + j] = Color(1.0, 1.0, 1.0);
        }
    }
}
Texture::Texture(string filename)
{
}

/*Getters*/
int Texture::getWidth(void)
{
    return width;
}
int Texture::getHeight(void)
{
    return height;
}
Color* Texture::getData(void)
{
    return data;
}
/*Get a pixel, given the relative coordinates
0,0 = bottom left 1,1 = top right*/
Color Texture::getColor(double relX, double relY)
{
    int x = (int)(relX*(width-1));
	int y = (int)(relY*(height-1));
	return data[y*width+x];;
}
