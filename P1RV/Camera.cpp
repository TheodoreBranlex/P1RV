#include "Camera.h"
#include <gl/glut.h>


Camera::Camera(Vector3 viewOrigin, double fieldOfView) : Camera(viewOrigin, Vector3::forward, Vector3::up, fieldOfView) {}

Camera::Camera(Vector3 viewOrigin, Vector3 viewDirection, double fieldOfView) : Camera(viewOrigin, viewDirection, Vector3::up, fieldOfView) {}

Camera::Camera(Vector3 viewOrigin, Vector3 viewDirection, Vector3 upVector, double fieldOfView) : Camera(viewOrigin, viewDirection, upVector, fieldOfView, 0.1, 100) {}

Camera::Camera(Vector3 viewOrigin, Vector3 viewDirection, Vector3 upVector, double fieldOfView, double nearestDistance, double farthestDistance)
{
	position = viewOrigin;
	direction = viewDirection;
	up = upVector;
	fov = fieldOfView;
	znear = nearestDistance;
	zfar = farthestDistance;
}


void Camera::Use()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Vector3 target = position + direction;
	gluLookAt(position.x, position.y, position.z, target.x, target.y, target.z, up.x, up.y, up.z);

	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	double ratio = (double) width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(fov, ratio, znear, zfar);
}