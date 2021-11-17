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
	Vector color;

	Camera(double, double, double, Vector = {0, 0, 0});

	void Setup();
};