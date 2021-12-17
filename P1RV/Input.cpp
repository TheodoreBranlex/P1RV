#include <glut.h>
#include "Input.h"
#include "Display.h"

using namespace Input;


void KeyDown(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		move.x -= 1; break;
	case 'd':
		move.x += 1; break;
	case 'z':
		move.y += 1; break;
	case 's':
		move.y -= 1; break;
	}
}

void KeyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		move.x += 1; break;
	case 'd':
		move.x -= 1; break;
	case 'z':
		move.y -= 1; break;
	case 's':
		move.y += 1; break;
	}
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
	glutSetCursor(GLUT_CURSOR_NONE);
	glutIgnoreKeyRepeat(true);

	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseFunc(MousePress);
	glutMotionFunc(MouseMove);
	glutPassiveMotionFunc(MouseMove);
}