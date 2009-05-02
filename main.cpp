

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#else
#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#endif

#ifdef WIN
#include <GL/openglut.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

#include "math/Vector3.h"
#include "math/Ray.h"
#include "objects/Sphere.h"
#include "objects/Wall.h"
#include "Util/color.h"
#include "Util/light.h"
#include "Util/camera.h"

using namespace std;

//Window dimensions
int width = 800, height = 600;

//Scene objects
vector<Object*> objects;

//Pixel information
Color *pixels;

//Keyboard
bool keyN[256];
bool keyS[21];

//Light
Light light;
//Global ambien light
Color gAmbient;

//Camera, corners of the plane, and camera pos
Vector3 minv;
Vector3 maxv;
Vector3 posv; 

//Keyboard functions
void keyDown(unsigned char key, int x, int y)
{
  keyN[key] = true;
}
void keyUp(unsigned char key, int x, int y)
{
  keyN[key] = false;
}
void keySDown(int key, int x, int y)
{
  keyS[key] = true;
}
void keySUp(int key, int x, int y)
{
  keyS[key] = false;
}

/*
Reads the keyboard state and updates
the simulation state
*/
void keyboard()
{
    if(keyN[27])exit(0);
}

/*
    Cast a ray and return the color of the intersected object
*/
Color castRay(Ray ray)
{
    int ii = 0;
    bool intersect = false;
    Color c(0.0, 0.0, 0.0);
    Object *o;
    double mint = INT_MAX, t, t2 = -1;
    //Check the nearest object the ray intersects
    for(int i = 0; i < objects.size(); ++i)
    {
        t = objects[i]->rayIntersection(ray);
        if(t > 0 && t < mint)
        {
            o = objects[i];
            mint = t;
            intersect = true;
            ii = i;
        }
    }
    
    //There wasn�t any intersection
    if(!intersect)
        return c;
    
    //point of intersection
    Vector3 p = ray.getPoint(mint);
    //Ray from the intersection point towards the light source
    Ray ray2(p, light.pos);
    
    //Ambient color calculation
    //done before shadow calculation because the scene will look ugly otherwise
    Color la = light.ambient;
    Color sa = o->getAmb();
    Color ga = gAmbient;
    c = Color(la.r*sa.r + ga.r*sa.r, la.g*sa.g + ga.g*sa.g, la.b*sa.b + ga.b*sa.b);
    
    //Now check if this object is receiving light
    for(int i = 0; i < objects.size(); ++i)
    {
        if(ii != i)t2 = objects[i]->rayIntersection(ray2);
        if(t2 > 0)
            return c;
    }
    //If we are here is because the object is receiving light
    //So we use the local ilumination model on that point
    
    //Diffuse color calculation
    Color ld = light.diffuse;
    Color sd = o->getDiff();
    Vector3 n = o->getNorm(p);
    double dot = n.dot(ray2.getDir());
    //double att = 120/(light.pos - p).magnitudeSquared();
    double att = 1.0;
    if(dot > 0)
    {
        c.r += att*ld.r*sd.r*dot;
        c.g += att*ld.g*sd.g*dot;
        c.b += att*ld.b*sd.b*dot;
        
        //Specular color calculation
        Color ls = light.specular;
        Vector3 v = (posv - p).normalize();
        Vector3 refl = -ray2.getDir() - n*2*(-ray2.getDir().dot(n));
    
        double k = refl.dot(v);
    
        if(k > 0)
        {
            k = pow(k, (1/o->getShin())*10);
            c.r += ls.r*k;
            c.g += ls.g*k;
            c.b += ls.b*k;
        }
    }
    
    return c;
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    
    //Camera calculation
    posv = Vector3(0.0, 0.0, 10.0);
    double h = 10*tan(3.1415926536/8);
    double w = h*800/600;
    minv = Vector3(-w, -h, 0);
    maxv = Vector3(w, h, 0);
    
    stringstream ss;
    ss.clear();
    ss << "width: " << w << "h: " << h << endl;
    glutSetWindowTitle(ss.str().c_str());
    
    //Calculates all the rays
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            Ray ray(posv, minv + Vector3(2*w*j/width, 2*h*i/height, 0));
            pixels[i*800 + j] = castRay(ray);
        }
    }

    glDrawPixels(width,height,GL_RGB,GL_FLOAT,pixels);
    
    glutSwapBuffers();
}

/*
Handles the resize events
*/
void resize(int w, int h)
{
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)
        h = 1;
        
    width = w, height = h;
  
    /*float ratio = 1.0* w / h;
  
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
  
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
  
    // Set the correct perspective.
    gluPerspective(45,ratio,1,500);*/
}

/*
    Initializes some stuff
*/
void init()
{
    pixels = new Color[width*height];
    //Resets the pixels
    memset(pixels, 0, sizeof(GLfloat)*3*width*height);
    
    //Add some spheres
    objects.push_back(new Sphere(1, Vector3(-3, 2, -5), Color(1.0, 0, 0), Color(1.0, 0, 0), Color(1.0, 0, 0), 1.0));
    objects.push_back(new Sphere(1, Vector3(3, 0, -5), Color(1.0, 0, 1.0), Color(1.0, 0, 1.0), Color(1.0, 0, 1.0), 1.0));
    objects.push_back(new Sphere(1, Vector3(3, 4, -5), Color(1.0, 1.0, 0), Color(1.0, 1.0, 0), Color(1.0, 1.0, 0.0), 1.0));
    objects.push_back(new Sphere(1, Vector3(1, 0, -3), Color(0, 0, 1.0), Color(0.0, 0, 1.0), Color(0.0, 0, 1.0), 1.0));
    
    //Add a wall
    objects.push_back(new Wall(Vector3(-20.0f, -5.0f, 20.0f), Vector3(20.0f, -5.0f, -20.0f), Vector3(20.0f, -5.0f, 20.0f), 
                                    Color(0.8,0.8,0.8), Color(0.8,0.8,0.8), Color(0.8,0.8,0.8), 1));
    
    //light, and global ambient
    light = Light(Vector3(-3.0, 5.0, 5.0), Color(0.0, 0.0, 0.0), Color(0.7, 0.7, 0.7), Color(0.8, 0.8, 0.8), GLOBAL);
    //light = Light(Vector3(5.0, 0, -5.0), Color(0.0, 0.0, 0.0), Color(0.7, 0.7, 0.7), Color(0.8, 0.8, 0.8), GLOBAL);
    gAmbient = Color(0.25, 0.25, 0.25);
}

/*
Initializes OpenGL
*/
void initGl()
{
    glShadeModel (GL_SMOOTH);
    glEnable(GL_CULL_FACE);
}

int main(int argc, char *argv[])
{
    glutInitWindowSize(width,height);
    glutInitWindowPosition(40,40);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Ray Tracer");

    //Can't allow reshape, the program will die of all the calculations
    //glutReshapeFunc(resize);
    
    glutDisplayFunc(draw);
    //Keyboard Functions
    glutKeyboardFunc(keyDown);
    glutSpecialFunc(keySDown);
    glutKeyboardUpFunc(keyUp);
    glutSpecialUpFunc(keySUp);
    
    //glutIdleFunc(idle);
    initGl();
    init();
    glutMainLoop();

    return 0;
}
