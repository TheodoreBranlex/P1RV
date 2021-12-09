#include <glut.h>
#include "Display.h"
#include "Camera.h"
#include "Object.h"
#include "Texture.h"


void Display::CreateWindow(const char* title, int width, int height, int xPosition, int yPosition)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(xPosition, yPosition);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
}


void LoadTextures(int i)
{
    for (auto object : Object::all)
        for (auto& mesh : object->meshes)
            mesh.texture.Load();
}

void RenderScene()
{
    Camera::main->Setup();
    for (auto object : Object::all)
        object->Render();
    glFlush();
}


void Display::BeginDisplay(void (*UpdateScene) (int))
{
    glutReshapeFunc([](int width, int height) { glViewport(0, 0, width, height); });

    glutTimerFunc(0, LoadTextures, 0);
    glutDisplayFunc(RenderScene);

    int ms = 1000 / Display::fps;
    glutTimerFunc(ms, UpdateScene, ms);

    glutMainLoop();
}