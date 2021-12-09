#pragma once
namespace Display
{
	inline int fps = 60;

	void CreateWindow(const char*, int, int, int = 0, int = 0);

	void BeginDisplay(void (*) (int));
};