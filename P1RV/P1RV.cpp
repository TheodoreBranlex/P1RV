#include<Windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include "GlutWindow.h"
#include "Vector3.h"


GLvoid display();

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    GlutWindow window("P1RV", 1000, 1000);

    glutDisplayFunc(display);
    glutReshapeFunc(window.GetReshape());
    glutMainLoop();
}

GLvoid display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}