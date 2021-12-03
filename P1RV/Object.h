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

struct Object : vector<Mesh>
{
	inline static vector<Object*> all;

	double scale;
	Vector position;
	Vector direction;
	Vector up;
	
	Object(Mesh);
	Object(string, double = 1);

	void Render();
};