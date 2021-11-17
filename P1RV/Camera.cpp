#include <gl/glut.h>
#include "Camera.h"


Camera * Camera::main = nullptr;


Camera::Camera(double fieldOfView, double nearestDistance, double farthestDistance, Vector backgroungColor)
{
	position = Vector();
	direction = Vector(0, 0, -1);
	up = Vector(0, 1, 0);
	fov = fieldOfView;
	znear = nearestDistance;
	zfar = farthestDistance;
	color = backgroungColor;

	if (!Camera::main)
		Camera::main = this;
}


void Camera::Setup()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(color.x, color.y, color.z, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Vector target = position + direction;
	gluLookAt(position.x, position.y, position.z, target.x, target.y, target.z, up.x, up.y, up.z);

	double ratio = (double)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ratio, znear, zfar);
}