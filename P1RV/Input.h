#pragma once
#include "Vector.h"

class Button
{
	bool press = false;
public:
	void Set(bool state) { press = state; }
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