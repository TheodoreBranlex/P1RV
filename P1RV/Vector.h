#pragma once
struct Vector
{
	double x;
	double y;
	double z;

	Vector();
	Vector(double, double, double);
	Vector(const Vector&);


	Vector& operator= (const Vector&);

	Vector& operator+= (const Vector&);
	Vector operator+ (const Vector&) const;

	Vector& operator-= (const Vector&);
	Vector operator- (const Vector&) const;

	Vector& operator*= (const double);
	Vector operator* (const double) const;
	friend Vector operator* (const double, const Vector&);

	Vector& operator/= (const double);
	Vector operator/ (const double)const;

	// Cross product
	Vector operator* (const Vector&) const;
	Vector& operator*= (const Vector&);

	// Dot product
	double Dot(const Vector&) const;

	double Length() const;
	Vector& Normalize();
};