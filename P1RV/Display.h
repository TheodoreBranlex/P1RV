#pragma once
namespace Display
{
	inline int fps = 120;

	void CreateWindow(const char*, int, int, int = 0, int = 0);

	void BeginDisplay(void (*) (int));
	void BeginDisplay(void (*) (), void (*) (int));

	void RenderScene();
};