#pragma once
struct GlutWindow
{
	void (*reshapeFunc)(int, int);

	GlutWindow(int, int);
	GlutWindow(const char*, int, int);
	GlutWindow(int, int, int, int);
	GlutWindow(const char*, int, int, int, int);
};