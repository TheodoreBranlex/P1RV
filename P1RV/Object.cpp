#include <gl/glut.h>
#include "Object.h"


vector<Object*> Object::all;


Object::Object() {}

Object::Object(vector<Vector> vertexList, vector<vector<int>> faceList) : Object(vertexList, faceList, Vector(1, 1, 1)) {}

Object::Object(vector<Vector> vertexList, vector<vector<int>> faceList, Vector objectColor) : vertices(vertexList), faces(faceList), color(objectColor)
{
    Object::all.push_back(this);
}


void Object::Render() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    glRotated(rotation.Length(), rotation.x, rotation.y, rotation.z);
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