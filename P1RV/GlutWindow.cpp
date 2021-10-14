#include "GlutWindow.h"
#include <gl/glut.h>


GlutWindow::GlutWindow(int width, int height) : GlutWindow("", width, height, 0, 0) {}

GlutWindow::GlutWindow(const char* title, int width, int height) : GlutWindow(title, width, height, 0, 0) {}

GlutWindow::GlutWindow(int width, int height, int xPosition, int yPosition) : GlutWindow("", width, height, yPosition, yPosition) {}

GlutWindow::GlutWindow(const char* title, int width, int height, int xPosition, int yPosition)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(xPosition, yPosition);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
}


void (*GlutWindow::GetReshape())(int width, int height)
{
    auto Reshape = [](int width, int height) {glViewport(0, 0, width, height);};
    return Reshape;
}