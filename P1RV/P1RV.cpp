#include <gl/glut.h>
#include "Display.h"
#include "Vector.h"
#include "Camera.h"
#include "Object.h"


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


void Init()
{
    camera.position = Vector(0, 5, 10);
    camera.direction.z = -0.5;
    camera.backgroungColor = { 0, 0, 0.3 };

    cube.position = Vector(0, 10, 0);
    cube.rotation = Vector(0, 45, 0);
}

void Update(int ms) {
    double dt = (double) ms / 1000;
    cube.position.y -= 10 * dt;
    glutPostRedisplay();
    glutTimerFunc(ms, Update, ms);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    Display::CreateWindow("P1RV", 1000, 1000);
    Display::BeginDisplay(Init, Update, 60);
}