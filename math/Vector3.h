#ifndef VECTOR3_TRACER
#define VECTOR3_TRACER

#include <iostream>
#include <math.h>

const double eps = 1e-7;

class Vector3
{
private:
    double x, y, z;

public:
    //Constructors
    Vector3(void);
    Vector3(double x, double y, double z);
    
    //Overloads to get the x, y and z components
    double &operator[](int index);
    double operator[](int index) const;
	
    //Operator overloads
    Vector3 operator*(double scale) const;
    Vector3 operator/(double scale) const;
    Vector3 operator+(const Vector3 &other) const;
    Vector3 operator-(const Vector3 &other) const;
    Vector3 operator-() const;
	
    const Vector3 &operator*=(double scale);
    const Vector3 &operator/=(double scale);
    const Vector3 &operator+=(const Vector3 &other);
    const Vector3 &operator-=(const Vector3 &other);
	
    //Other operations
    double magnitude() const;
    double magnitudeSquared() const;
    Vector3 normalize() const;
    double dot(const Vector3 &other) const;
    Vector3 cross(const Vector3 &other) const;
    
    //Comparison
    bool operator==(const Vector3 &other);
    bool operator!=(const Vector3 &other);
    bool operator>(const Vector3 &other);
    bool operator<(const Vector3 &other);
    bool operator>=(const Vector3 &other);
    bool operator<=(const Vector3 &other);
};

//Tells the iostream how to print the vector 3
std::ostream &operator<<(std::ostream &output, const Vector3 &v);

#endif
