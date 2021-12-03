#include <gl/glut.h>
#include "Display.h"
#include "Vector.h"
#include "Camera.h"
#include "Object.h"
#include "Input.h"
#include "Texture.h"

Camera camera(65, 0.1, 100, {0, 0, 0.3});

Object player("Models/Link/AdultLink.obj", 0.05);

Texture tex("Models/Link/Original Textures/eye.png");

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
Vector sideHop(0, 25, 40);
Vector backFlip(0, 40, 30);


void Initialize()
{
    player.position = Vector(0, 10, 0);
}


Vector speed(0, 0, runSpeed);
bool grounded;
bool targetLock = false;

void Update(int ms)
{
    double dt = (double) ms / 1000;

    
    Vector up = Vector(0, 1, 0);
    Vector right = (camera.direction * up).Normalize();
    Vector forward = (up * right).Normalize();

    Vector move = Input::move.x * right + Input::move.z * forward;

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
    {
        camera.direction += Input::camera.x * right + Input::camera.y * up;
        if (move.Length() != 0)
            player.direction = move;
    }
    else
    {
        Vector targetDirection = (target - player.position).Normalize();
        camera.direction.Damp(targetDirection, targetSpeed, dt);
        targetDirection.y = 0;
        player.direction = targetDirection;
    }
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