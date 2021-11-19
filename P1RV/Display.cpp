#include <gl/glut.h>
#include "Display.h"
#include "Camera.h"
#include "Object.h"


void Display::CreateWindow(const char* title, int width, int height, int xPosition, int yPosition)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(xPosition, yPosition);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
}

void Display::BeginDisplay(void (*UpdateScene) (int))
{
    BeginDisplay([]() {}, UpdateScene);
}

void Display::BeginDisplay(void (*InitializeScene) (), void (*UpdateScene) (int))
{
    glutDisplayFunc(RenderScene);
    glutReshapeFunc([](int width, int height) { glViewport(0, 0, width, height); });

    InitializeScene();

    int ms = 1000 / Display::fps;
    glutTimerFunc(ms, UpdateScene, ms);

    glutMainLoop();
}

void Display::RenderScene()
{
    Camera::main->Setup();
    for (auto object : Object::all)
        object->Render();
    glFlush();
}