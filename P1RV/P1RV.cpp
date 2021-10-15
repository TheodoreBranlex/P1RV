#include <gl/glut.h>
#include "GlutWindow.h"
#include "Vector3.h"
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
});

void Init()
{
    camera.position.z = 10;
    camera.backgroungColor = Vector3(0, 0, 0.3);
    cube.position = Vector3(3, 3, 0);
    cube.rotation = Vector3(0, 45, 0);
}

void Display() {
    camera.Setup();
    cube.Render();
    glFlush();
}

void Update() {
    cube.position.y -= 0.00001;
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    GlutWindow window("P1RV", 1000, 1000);
    
    glutReshapeFunc(window.reshapeFunc);
    glutDisplayFunc(Display);
    glutIdleFunc(Update);

    Init();
    glutMainLoop();
}