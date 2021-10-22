#pragma once
#include "Vector.h"
#include <vector>

using namespace std;

struct Object
{
	static vector<Object*> all;

	vector<Vector> vertices;
	vector<vector<int>> faces;
	Vector color;
	Vector position;
	Vector rotation;

	Object();
	Object(vector<Vector>, vector<vector<int>>);
	Object(vector<Vector>, vector<vector<int>>, Vector);

	void Render();
};