#define _USE_MATH_DEFINES

#include "Vector.h"
#include <cmath>


Vector::Vector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

Vector::Vector(const Vector& v) : Vector(v.x, v.y, v.z) {}


Vector& Vector::operator= (const Vector& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector& Vector::operator+= (const Vector& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector Vector::operator+ (const Vector& v) const
{
    Vector r = *this;
    r += v;
    return r;
}

Vector& Vector::operator-= (const Vector& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector Vector::operator- (const Vector& v) const
{
    Vector r = *this;
    r -= v;
    return r;
}

Vector& Vector::operator*= (const double a)
{
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

Vector Vector::operator* (const double a) const
{
    Vector r = *this;
    r *= a;
    return r;
}

Vector operator* (const double a, const Vector& v)
{
    return Vector(v.x * a, v.y * a, v.z * a);
}

Vector& Vector::operator/= (const double a)
{
    x /= a;
    y /= a;
    z /= a;
    return *this;
}

Vector Vector::operator/ (const double a) const
{
    Vector r = *this;
    r /= a;
    return r;
}

Vector Vector::operator*(const Vector& v) const
{
    Vector r;
    r.x = y * v.z - z * v.y;
    r.y = z * v.x - x * v.z;
    r.z = x * v.y - y * v.x;
    return r;
}

Vector& Vector::operator*=(const Vector& v)
{
    *this = *this * v;
    return *this;
}

double Vector::Dot(const Vector& v) const
{
    return (x * v.x + y * v.y + z * v.z);
}

double Vector::Length() const
{
    return sqrt(Dot(*this));
}

Vector& Vector::Normalize()
{
    if (Length() != 0)
        *this /= Length();
    return *this;
}