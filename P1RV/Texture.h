#pragma once
#include <string>

using namespace std;

struct Texture
{
	unsigned int id;
	string path;

	Texture(string = "");

	void Load();
	void Apply();
};

