#include "Camera.h"
#include <gl/glut.h>


Camera::Camera(double fieldOfView, double nearestDistance, double farthestDistance)
{
	position = Vector3();
	direction = Vector3(0, 0, -1);
	up = Vector3(0, 1, 0);
	fov = fieldOfView;
	znear = nearestDistance;
	zfar = farthestDistance;
	backgroungColor = Vector3(1, 1, 1);
}


void Camera::Setup()
{
	glClearColor(backgroungColor.x, backgroungColor.y, backgroungColor.z, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Vector3 target = position + direction;
	gluLookAt(position.x, position.y, position.z, target.x, target.y, target.z, up.x, up.y, up.z);

	int width = glutGet(GLUT_INIT_WINDOW_WIDTH);
	int height = glutGet(GLUT_INIT_WINDOW_HEIGHT);
	double ratio = (double) width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ratio, znear, zfar);
}