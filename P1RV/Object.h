#pragma once
#pragma once
#include "Vector3.h"
#include <vector>
using namespace std;

struct Vertex
{
	Vector3 position;
	Vector3 color;

	Vertex(double, double, double);
	Vertex(double, double, double, double, double, double);
};

struct Object
{
	vector<Vertex> vertices;
	vector<vector<int>> faces;
	Vector3 position;

	Object(vector<Vertex>, vector<vector<int>>);

	void Render();
};

