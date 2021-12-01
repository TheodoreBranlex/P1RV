#pragma once
#include "Vector.h"

struct Camera
{
	inline static Camera* main = 0;

	Vector position;
	Vector direction;
	Vector up;
	double fov;
	double znear, zfar;
	Vector color;

	Camera(double, double, double, Vector = {0, 0, 0});

	void Setup();
};