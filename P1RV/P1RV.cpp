#include <gl/glut.h>
#include "Display.h"
#include "Vector.h"
#include "Camera.h"
#include "Object.h"
#include "Input.h"
#include <iostream>


Camera camera(65, 0.1, 100, {0, 0, 0.3});

Object player
({
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
    {0.7, 0, 0.3}
);

Object plane
({
    {-5, 0, -5},
    {-5, 0, 5},
    {5, 0, 5},
    {5, 0, -5},
},
    {{0,1,2,3}}
);

Vector target;


double cameraDistance = 10;
double targetSpeed = 20;

double gravity = 200;
double runSpeed = 10;
double rollSpeed = 30;
double deceleration = 30;

double jumpThreshold = 0.7;
Vector sideHop(0, 25, 40);
Vector backFlip(0, 40, 30);


void Initialize()
{
    player.position = Vector(0, 10, 0);
}


Vector speed(0, 0, runSpeed);
bool targetLock = false;

void Update(int ms)
{
    double dt = (double) ms / 1000;
    
    Vector up = Vector(0, 1, 0);
    Vector right = (camera.direction * up).Normalize();
    Vector forward = (up * right).Normalize();

    Vector move = Input::move.x * right + Input::move.z * forward;

    if (move.Length() != 0)
        player.direction = move;

    if (player.position.y > 1)
        speed.y -= gravity * dt;
    else
    {
        player.position.y = 1;
        speed.y = 0;
    }

    if (Input::roll)
        if (targetLock && Input::move.z < -jumpThreshold)
            speed = backFlip;
        else if (targetLock && abs(Input::move.x) > jumpThreshold)
            speed = sideHop;
        else
            speed.z = rollSpeed;

    if (speed.z > runSpeed)
        speed.z -= deceleration * dt;

    Vector velocity = speed.y * up + speed.z * move;

    player.position += velocity * dt;
    

    if (Input::target)
        targetLock = !targetLock;

    if (!targetLock)
        camera.direction += Input::camera.x * right + Input::camera.y * up;
    else
        camera.direction.Damp((target - player.position).Normalize(), targetSpeed, dt);
    camera.direction.Normalize();
    camera.position = player.position - cameraDistance * camera.direction;
    

    glutPostRedisplay();

    ms = 1000 / Display::fps;
    glutTimerFunc(ms, Update, ms);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    Display::CreateWindow("P1RV", 800, 800);
    Input::BeginInput();
    Display::BeginDisplay(Initialize, Update);
}