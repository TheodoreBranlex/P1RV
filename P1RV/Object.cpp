#include <gl/glut.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Object.h"


Mesh::Mesh(vector<Vector> vertexList, vector<vector<unsigned int>> faceList)
{
    vertices = vertexList;
    faces = faceList;
}

void Mesh::Render()
{
    for (vector<unsigned int> face : faces)
    {
        glBegin(GL_POLYGON);
        for (unsigned int i : face)
            glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
        glEnd();
    }
}

Mesh readMesh(aiMesh* mesh, const aiScene* scene)
{
    vector<Vector> vertices;
    vector<vector<unsigned int>> faces;
    for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
        vertices.push_back(Vector(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z));
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        vector<unsigned int> face;
        for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
            face.push_back(mesh->mFaces[i].mIndices[j]);
        faces.push_back(face);
    }
    return (Mesh(vertices, faces));
}


Object::Object(vector<Mesh> meshList) : meshes(meshList)
{
    Object::all.push_back(this);
    position = Vector();
    direction = Vector(0, 0, -1);
    up = Vector(0, 1, 0);
}

void readNode(aiNode* node, const aiScene* scene, Object* target)
{
    for (unsigned int i = 0; i < node->mNumMeshes; ++i)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        target->meshes.push_back(readMesh(mesh, scene));
    }
    for (unsigned int i = 0; i < node->mNumChildren; ++i)
        readNode(node->mChildren[i], scene, target);
}

Object::Object(string filename) : position(), direction(0, 0, -1), up(0, 1, 0)
{
    string path = "Models/" + filename;
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
    readNode(scene->mRootNode, scene, this);
    Object::all.push_back(this);
}


void Object::Render()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    gluLookAt(0, 0, 0, -direction.x, direction.y, direction.z, up.x, up.y, up.z);
    for (Mesh mesh : meshes)
        mesh.Render();
    glPopMatrix();
}