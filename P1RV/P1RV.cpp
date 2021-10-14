#include<Windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include "GlutWindow.h"
#include "Camera.h"
#include "Vector3.h"


Camera camera(Vector3(0, 0, 1), 65);

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    camera.Use();
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    GlutWindow window("P1RV", 1000, 1000);

    glutDisplayFunc(Display);
    glutReshapeFunc(window.GetReshape());
    glutMainLoop();
}