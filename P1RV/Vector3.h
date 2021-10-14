#pragma once
struct Vector3
{
	double x;
	double y;
	double z;

	Vector3();
	Vector3(double, double, double);
	Vector3(const Vector3&);


	Vector3& operator= (const Vector3&);

	Vector3& operator+= (const Vector3&);
	Vector3 operator+ (const Vector3&) const;

	Vector3& operator-= (const Vector3&);
	Vector3 operator- (const Vector3&) const;

	Vector3& operator*= (const double);
	Vector3 operator* (const double) const;
	friend Vector3 operator* (const double, const Vector3&);

	Vector3& operator/= (const double);
	Vector3 operator/ (const double)const;

	// Cross product
	Vector3 operator* (const Vector3&) const;
	Vector3& operator*= (const Vector3&);

	double length() const;
	Vector3& normalize();
};
