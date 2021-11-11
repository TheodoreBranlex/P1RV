#pragma once
#include "Vector.h"

struct Button
{
	bool press = false;
	operator bool() { if (press) { press = false; return true; } else return false; }
};

namespace Input
{
	inline Vector move;
	inline Vector camera;
	inline Button roll;
	inline Button attack;
	inline Button target;

	inline double mouseSensitivity = 0.1;

	void BeginInput();
};