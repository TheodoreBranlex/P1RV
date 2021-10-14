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

	Camera(Vector3, double);
	Camera(Vector3, Vector3, double);
	Camera(Vector3, Vector3, Vector3, double);
	Camera(Vector3, Vector3, Vector3, double, double, double);

	void Use();
};

