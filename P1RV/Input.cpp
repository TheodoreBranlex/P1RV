#include <gl/glut.h>
#include "Input.h"


Vector Input::move;
Vector Input::camera;
bool Input::roll;
bool Input::attack;

bool left, right, up, down;


void KeyDown(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		left = true; break;
	case 'd':
		right = true; break;
	case 'z':
		up = true; break;
	case 's':
		down = true; break;
	}
	Input::move = Vector(right - left, 0, down - up);
}

void KeyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		left = false; break;
	case 'd':
		right = false; break;
	case 'z':
		up = false; break;
	case 's':
		down = false; break;
	}
	Input::move = Vector(right - left, 0, down - up);
}


void MousePress(int button, int state, int x, int y)
{

}

void MouseMove(int x, int y)
{

}


void Input::BeginInput()
{
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseFunc(MousePress);
	glutMotionFunc(MouseMove);
	glutPassiveMotionFunc(MouseMove);
}