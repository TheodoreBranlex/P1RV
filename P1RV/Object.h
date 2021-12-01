#pragma once
#include "Vector.h"
#include <vector>
#include <string>

using namespace std;

struct Mesh
{
	vector<Vector> vertices;
	vector<vector<unsigned int>> faces;

	Mesh(vector<Vector>, vector<vector<unsigned int>>);

	void Render();
};

struct Object
{
	inline static vector<Object*> all;

	vector<Mesh> meshes;

	Vector position;
	Vector direction;
	Vector up;
	
	Object(vector<Mesh>);
	Object(string filename);

	void Render();
};