#pragma once
#include "Vector.h"

namespace Input
{
	extern Vector move;
	extern Vector camera;
	extern bool roll;
	extern bool attack;
	extern bool target;

	void BeginInput();
};