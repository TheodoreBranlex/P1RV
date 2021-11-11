#include <gl/glut.h>
#include "Display.h"
#include "Vector.h"
#include "Camera.h"
#include "Object.h"
#include "Input.h"


Camera camera(65, 0.1, 100);

Object cube({
    {-1, -1, 1},
    {-1, 1, 1},
    {1, 1, 1},
    {1, -1, 1},
    {-1, -1, -1},
    {-1, 1, -1},
    {1, 1, -1},
    {1, -1, -1},
},{
    {0,1,2,3},
    {3,2,6,7},
    {4,5,6,7},
    {0,1,5,4},
    {1,5,6,2},
    {0,4,7,3}
},
    {1, 0, 0});

Object plane({
    {-5, 0, -5},
    {-5, 0, 5},
    {5, 0, 5},
    {5, 0, -5},
},
    {{0,1,2,3}});


void Initialize()
{
    camera.position = Vector(0, 5, 10);
    camera.direction.z = -0.5;
    camera.backgroungColor = { 0, 0, 0.3 };

    cube.position = Vector(0, 10, 0);
    cube.rotation = Vector(0, 45, 0);
}


Vector up(0, 1, 0);
double cameraDistance = 10;

void Update(int ms) {
    double dt = (double) ms / 1000;

    Vector right = (camera.direction * up).Normalize();
    Vector forward = (up * right).Normalize();

    if (cube.position.y > 1)
        cube.position.y -= 20 * dt;
    else
        cube.position.y = 1;
    cube.position += 10 * (Input::move.x * right + Input::move.z * forward) * dt;

    camera.direction += Input::camera.x * right + Input::camera.y * up;
    camera.direction.Normalize();
    camera.position = cube.position - cameraDistance * camera.direction;

    glutPostRedisplay();
    glutTimerFunc(ms, Update, ms);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    Display::CreateWindow("P1RV", 800, 800);
    Input::BeginInput();
    Display::BeginDisplay(Initialize, Update);
}