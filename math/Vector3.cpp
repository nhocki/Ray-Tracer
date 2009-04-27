#include "Vector3.h"

Vector3::Vector3()
{
    x = y = z = 0.0f;
}

Vector3::Vector3(double x, double y, double z)
{
    Vector3::x = x;
    Vector3::y = y;
    Vector3::z = z;
}

/* Return the element especified by the index
 */
double &Vector3::operator[](int index) {
	if(index  == 0)return x;
    if(index == 1)return y;
    return z;
}

/* Return the element especified by the index
 */
double Vector3::operator[](int index) const {
	if(index  == 0)return x;
    if(index == 1)return y;
    return z;
}

/* Multiplication of a vector times a scalar
 */
Vector3 Vector3::operator*(double scale) const {
	return Vector3(x*scale, y*scale, z*scale);
}

/* Division of a vector with a scalar
 */
Vector3 Vector3::operator/(double scale) const {
	return Vector3(x/scale, y/scale, z/scale);
}

/* Sum of two vectors
 */
Vector3 Vector3::operator+(const Vector3 &v) const {
	return Vector3(x + v[0], y + v[1], z + v[2]);
}

/* Substraction of two vectors
 */
Vector3 Vector3::operator-(const Vector3 &v) const {
	return Vector3(x - v[0], y - v[1], z - v[2]);
}

/* Invert the vector
 */
Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

/* Multiply this vector by the scale
 */
const Vector3 &Vector3::operator*=(double scale) {
	x *= scale;
	y *= scale;
	z *= scale;
	return *this;
}

/* Divide this vector by the scale
 */
const Vector3 &Vector3::operator/=(double scale) {
	x /= scale;
	y /= scale;
	z /= scale;
	return *this;
}

/* Add this vector to another one
 */
const Vector3 &Vector3::operator+=(const Vector3 &v) {
	x += v[0];
	y += v[1];
	z += v[2];
	return *this;
}

/* Substract a vector to this one
 */
const Vector3 &Vector3::operator-=(const Vector3 &v) {
	x -= v[0];
	y -= v[1];
	z -= v[2];
	return *this;
}

/* Calculates the magnitude of the vector
 */
double Vector3::magnitude() const {
	return sqrt(x*x + y*y + z*z);
}

/* Calculates the magnitude squared of this vector
 * it saves the costly sqrt function
 */
double Vector3::magnitudeSquared() const {
	return  x*x + y*y + z*z;
}

/* Normalize the vector
 */
Vector3 Vector3::normalize() const {
	double m = Vector3::magnitude();
	return Vector3(x/m, y/m, z/m);
}

/* Calculates the dot product
 */
double Vector3::dot(const Vector3 &v) const {
	return x*v[0] + y*v[1] + z*v[2];
}

/* Calculates the cross product
 */
Vector3 Vector3::cross(const Vector3 &v) const {
	return Vector3(y*v[2] - z*v[1],
				    z*v[0] - x*v[2],
				    x*v[1] - y*v[0]);
}

/* Comparisson operators
*/
bool Vector3::operator==(const Vector3 &other)
{
    return (x == other[0] && y == other[1] && z == other[2]);
}
bool Vector3::operator!=(const Vector3 &other)
{
    return !(x == other[0] && y == other[1] && z == other[2]);
}

/* Tells the iostram how to output the vector
 */
std::ostream &operator<<(std::ostream &output, const Vector3 &v) {
    std::cout << '(' << v[0] << ", " << v[1] << ", " << v[2] << ')';
	return output;
}
