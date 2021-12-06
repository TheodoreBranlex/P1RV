#pragma once
#include <vector>
#include <string>
#include "Vector.h"

using namespace std;

struct Vertex
{
	Vector position;
	Vector texcoord;

	Vertex(Vector, Vector = Vector());
};

struct Mesh
{
	vector<Vertex> vertices;
	vector<vector<unsigned int>> faces;

	Mesh(vector<Vertex>, vector<vector<unsigned int>>);

	void Render();
};

struct Object
{
	inline static vector<Object*> all;

	vector<Mesh> meshes;

	double scale;
	Vector position;
	Vector direction;
	Vector up;
	
	Object(Mesh);
	Object(string, double = 1);

	void Render();
};