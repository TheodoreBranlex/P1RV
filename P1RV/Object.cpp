#include "Object.h"
#include <gl/glut.h>


Vertex::Vertex(double x, double y, double z) : position(x, y, z), color(1, 1, 1) {}

Vertex::Vertex(double x, double y, double z, double r, double g, double b) : position(x, y, z), color(r, g, b) {}


Object::Object(vector<Vertex> vertexList, vector<vector<int>> faceList) : vertices(vertexList), faces(faceList) {};


void Object::Render() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    glRotated(rotation.Length(), rotation.x, rotation.y, rotation.z);
    for (vector<int> face : faces) {
        glBegin(GL_POLYGON);
        for (int i : face) {
            Vector3 color(vertices[i].color);
            glColor3f(color.x, color.y, color.z);
            Vector3 position(vertices[i].position);
            glVertex3f(position.x, position.y, position.z);
        }
        glEnd();
    }
    glPopMatrix();
}