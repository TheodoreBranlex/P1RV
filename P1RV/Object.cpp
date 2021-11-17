#include <gl/glut.h>
#include "Object.h"


vector<Object*> Object::all;


Object::Object(vector<Vector> vertexList, vector<vector<int>> faceList, Vector objectColor)
{
    vertices = vertexList;
    faces = faceList;
    color = objectColor;
    position = Vector();
    direction = Vector(0, 0, -1);
    up = Vector(0, 1, 0);
    Object::all.push_back(this);
}


void Object::Render() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    gluLookAt(0, 0, 0, -direction.x, direction.y, direction.z, up.x, up.y, up.z);
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