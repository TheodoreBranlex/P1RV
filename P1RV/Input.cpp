#include <gl/glut.h>
#include "Input.h"

using namespace Input;


Vector Input::move;
Vector Input::camera;
bool Input::roll = false;
bool Input::attack = false;
bool Input::target = false;

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
	move = Vector(right - left, 0, down - up).Normalize();
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
	move = Vector(right - left, 0, down - up).Normalize();
}


void MousePress(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			roll = true;
		if (state == GLUT_UP)
			roll = false;
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			attack = true;
		if (state == GLUT_UP)
			attack = false;
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			target = true;
		if (state == GLUT_UP)
			target = false;
		break;
	}
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