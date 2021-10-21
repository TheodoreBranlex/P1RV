#pragma once
#include "Vector.h"

struct Camera
{
	static Camera * main;

	Vector position;
	Vector direction;
	Vector up;
	double fov;
	double znear, zfar;
	Vector backgroungColor;

	Camera(double, double, double);

	void Setup();
};