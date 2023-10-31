#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <cmath>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

class Mesh
{
public:
    Mesh(const std::vector<Vertex> &vertices);
    ~Mesh();
    void Render();
    static Mesh *CreateTriangle();

private:
    GLuint VAO, VBO;
    GLsizei vertexCount;
};

#endif