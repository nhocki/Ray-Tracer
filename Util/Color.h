#ifndef COLOR_TRACER
#define COLOR_TRACER

struct Color
{
    float r,g,b;
    Color(void);
    Color(float r, float g, float b);
    
    //Operator overloads
    Color operator*(double scale) const;
    
    Color operator+(const Color &other);
    Color operator-(const Color &other);
    Color operator*(const Color &other);
};

#endif
