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
	Vector direction;
	Vector up;
	
	Object(vector<Vector>, vector<vector<int>>, Vector = {1, 1, 1}, Vector = Vector(), Vector = Vector(0, 0, -1),  Vector = Vector(0, 1, 0));

	void Render();
};