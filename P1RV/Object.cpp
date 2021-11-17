#include <gl/glut.h>
#include "Object.h"


vector<Object*> Object::all;


Object::Object(vector<Vector> vertexList, vector<vector<int>> faceList, Vector objectColor, Vector initialPosition, Vector forwardDirection, Vector upDirection)
{
    vertices = vertexList;
    faces = faceList;
    color = objectColor;
    position = initialPosition;
    direction = forwardDirection;
    up = upDirection;
    Object::all.push_back(this);
}


void Object::Render() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    for (vector<int> face : faces) {
        glBegin(GL_POLYGON);
        for (int i : face) {
            glColor3f(color.x, color.y, color.z);
            glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
        }
        glEnd();
    }
    glPopMatrix();
}