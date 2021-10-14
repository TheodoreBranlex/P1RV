#pragma once
struct GlutWindow
{
	GlutWindow(int, int);
	GlutWindow(const char*, int, int);
	GlutWindow(int, int, int, int);
	GlutWindow(const char*, int, int, int, int);

	void (*GetReshape())(int, int);
};