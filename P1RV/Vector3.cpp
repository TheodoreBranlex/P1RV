#include "Vector3.h"
#include <cmath>


Vector3::Vector3() : Vector3(0, 0, 0) {}

Vector3::Vector3(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

Vector3::Vector3(const Vector3& v) : Vector3(v.x, v.y, v.z) {}


Vector3 Vector3::up = Vector3(0, 1, 0);

Vector3 Vector3::right = Vector3(1, 0, 0);

Vector3 Vector3::forward = Vector3(0, 0, -1);


Vector3& Vector3::operator= (const Vector3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector3& Vector3::operator+= (const Vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3 Vector3::operator+ (const Vector3& v) const
{
    Vector3 r = *this;
    r += v;
    return r;
}

Vector3& Vector3::operator-= (const Vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3 Vector3::operator- (const Vector3& v) const
{
    Vector3 r = *this;
    r -= v;
    return r;
}

Vector3& Vector3::operator*= (const double a)
{
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

Vector3 Vector3::operator* (const double a) const
{
    Vector3 r = *this;
    r *= a;
    return r;
}

Vector3 operator* (const double a, const Vector3& v)
{
    return Vector3(v.x * a, v.y * a, v.z * a);
}

Vector3& Vector3::operator/= (const double a)
{
    x /= a;
    y /= a;
    z /= a;
    return *this;
}

Vector3 Vector3::operator/ (const double a) const
{
    Vector3 r = *this;
    r /= a;
    return r;
}

Vector3 Vector3::operator*(const Vector3& v) const
{
    Vector3 r;
    r.x = y * v.z - z * v.y;
    r.y = z * v.x - x * v.z;
    r.z = x * v.y - y * v.x;
    return r;
}

Vector3& Vector3::operator*=(const Vector3& v)
{
    *this = *this * v;
    return *this;
}

double Vector3::length() const
{
    return sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::normalize()
{
    *this /= length();
    return *this;
}