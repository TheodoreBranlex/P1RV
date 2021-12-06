#include <glut.h>
#include "Input.h"
#include "Display.h"

using namespace Input;


struct { bool left, right, up, down; } keypad;

void KeyDown(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		keypad.left = true; break;
	case 'd':
		keypad.right = true; break;
	case 'z':
		keypad.up = true; break;
	case 's':
		keypad.down = true; break;
	}
	move = Vector(keypad.right - keypad.left, 0, keypad.up - keypad.down).Normalize();
}

void KeyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		keypad.left = false; break;
	case 'd':
		keypad.right = false; break;
	case 'z':
		keypad.up = false; break;
	case 's':
		keypad.down = false; break;
	}
	move = Vector(keypad.right - keypad.left, 0, keypad.up - keypad.down).Normalize();
}


void MousePress(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			roll.Set(true);
		if (state == GLUT_UP)
			roll.Set(false);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			target.Set(true);
		if (state == GLUT_UP)
			target.Set(false);
		break;
	}
}


void MouseMove(int dx, int dy)
{
	int cx = glutGet(GLUT_WINDOW_WIDTH) / 2, cy = glutGet(GLUT_WINDOW_HEIGHT) / 2;
	camera = mouseSensitivity / Display::fps * Vector(dx - cx, cy - dy, 0);
	glutWarpPointer(cx, cy);
}


void Input::BeginInput()
{
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseFunc(MousePress);
	glutMotionFunc(MouseMove);
	glutPassiveMotionFunc(MouseMove);

	glutSetCursor(GLUT_CURSOR_NONE);
}