#pragma once
#include "Vector3.h"
#include "GlutWindow.h"
struct Camera
{
	Vector3 position;
	Vector3 direction;
	Vector3 up;
	double fov;
	double znear, zfar;
	Vector3 backgroungColor;

	Camera(double, double, double);

	void Setup();
};