#include <gl/glut.h>
#include "Display.h"
#include "Camera.h"
#include "Object.h"


void Display::CreateWindow(const char* title, int width, int height)
{
    CreateWindow(title, width, height, 0, 0);
}

void Display::CreateWindow(const char* title, int width, int height, int xPosition, int yPosition)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(xPosition, yPosition);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
}

void Display::BeginDisplay(void (*UpdateScene) (int), int fps)
{
    BeginDisplay([]() {}, UpdateScene, fps);
}

void Display::BeginDisplay(void (*InitScene) (), void (*UpdateScene) (int), int fps)
{
    glutDisplayFunc(RenderScene);
    glutReshapeFunc([](int width, int height) { glViewport(0, 0, width, height); });

    int ms = 1000 / fps;
    glutTimerFunc(ms, UpdateScene, ms);

    InitScene();
    glutMainLoop();
}

void Display::RenderScene()
{
    Camera::main->Setup();
    for (auto object : Object::all)
        object->Render();
    glFlush();
}