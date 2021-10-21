#pragma once
namespace Display
{
	void CreateWindow(const char*, int, int);
	void CreateWindow(const char*, int, int, int, int);

	void BeginDisplay(void (*) (int), int);
	void BeginDisplay(void (*) (), void (*) (int), int);

	void RenderScene();
};