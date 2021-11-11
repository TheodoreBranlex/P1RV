#pragma once
namespace Display
{
	inline int fps = 120;

	void CreateWindow(const char*, int, int);
	void CreateWindow(const char*, int, int, int, int);

	void BeginDisplay(void (*) (int));
	void BeginDisplay(void (*) (), void (*) (int));

	void RenderScene();
};