#include "GlutWindow.h"
#include <gl/glut.h>


void GlutWindow::Create(const char* title, int width, int height)
{
    Create(title, width, height, 0, 0);
}

void GlutWindow::Create(const char* title, int width, int height, int xPosition, int yPosition)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(xPosition, yPosition);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
}

void GlutWindow::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}