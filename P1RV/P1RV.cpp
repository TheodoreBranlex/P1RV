#include <glut.h>
#include "Display.h"
#include "Vector.h"
#include "Camera.h"
#include "Object.h"
#include "Input.h"
#include "Texture.h"

Camera camera(65, 0.1, 100, {0, 0, 0.3});

Object player("Models/Link/AdultLink.dae", 0.05);

Object plane
({{
    {{-5, 0, -5}},
    {{-5, 0, 5}},
    {{5, 0, 5}},
    {{5, 0, -5}}
},{
    {0, 1, 2, 3}
}});

Vector target;

double cameraDistance = 10;
double targetSpeed = 20;

double gravity = 200;
double runSpeed = 10;
double rollSpeed = 30;
double deceleration = 30;

double jumpThreshold = 0.7;
Vector sideHop(40, 25);
Vector backFlip(30, 40);

Vector speed(runSpeed, 0);
bool grounded;
bool targetLock = false;

void Update(int ms)
{
    ms = 1000 / Display::fps;
    glutTimerFunc(ms, Update, ms);
    double dt = (double) ms / 1000;

    
    Vector up = Vector(0, 1, 0);
    Vector right = (camera.direction * up).Normalize();
    Vector forward = (up * right).Normalize();

    Vector move = Vector(Input::move).Normalize().x * right + Vector(Input::move).Normalize().y * forward;

    if (player.position.y > 0.1)
    {
        speed.y -= gravity * dt;
        grounded = false;
    }
    else
    {
        player.position.y = 0.1;
        speed.y = 0;
        grounded = true;
    }

    if (Input::roll && grounded)
        if (targetLock && Input::move.y < -jumpThreshold)
            speed = backFlip;
        else if (targetLock && abs(Input::move.x) > jumpThreshold)
            speed = sideHop;
        else
            speed.x = rollSpeed;

    if (speed.x > runSpeed)
        speed.x -= deceleration * dt;

    Vector velocity = speed.x * move + speed.y * up;

    player.position += velocity * dt;
    

    if (Input::target)
        targetLock = !targetLock;

    if (!targetLock)
    {
        camera.direction += Input::camera.x * right + Input::camera.y * up;
        if (move.Length() != 0)
            player.direction = move;
    }
    else
    {
        Vector targetDirection = (target - player.position).Flat().Normalize(forward);
        player.direction = targetDirection;
        targetDirection.y = camera.direction.y;
        camera.direction.Damp(targetDirection, targetSpeed, dt);
        camera.direction += Input::camera.y * up;
    }
    camera.position = player.position - cameraDistance * Vector(camera.direction).Normalize();
    

    glutPostRedisplay();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    Display::CreateWindow("P1RV", 800, 800);
    Input::BeginInput();
    Display::BeginDisplay(Update);
}