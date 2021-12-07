#pragma once

struct Texture
{
	int width, height;
	int channels;
	unsigned char* data;

	Texture(const char*);

	void Use();
};

