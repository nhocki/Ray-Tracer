#include "Color.h"
Color::Color()
{
    r = 1.0, g = 1.0, b = 1.0;
}
Color::Color(float r, float g, float b)
{
    //Clamps the color to the interval 0 - 1
    r = (r>=0.0)?r:0.0;
    g = (r>=0.0)?g:0.0;
    b = (r>=0.0)?b:0.0;
    Color::r = (r <= 1.0)?r:1.0;
    Color::g = (g <= 1.0)?g:1.0;
    Color::b = (b <= 1.0)?b:1.0;
}

/* Operator overloads*/
Color Color::operator*(double scale) const
{
    Color c(r*scale, g*scale, b*scale);
    return c;
}

Color Color::operator+(const Color &other)
{
    Color c(r + other.r, g + other.g, b + other.b);
    return c;
}

Color Color::operator-(const Color &other)
{
    Color c(r - other.r, g - other.g, b - other.b);
    return c;
}

Color Color::operator*(const Color &other)
{
    Color c(r*other.r, g*other.g, b*other.b);
    return c;
}
