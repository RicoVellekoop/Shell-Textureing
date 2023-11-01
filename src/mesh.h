#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/gtc/constants.hpp>
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
    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
    ~Mesh();
    void Render();
    static Mesh *CreateTriangle();
    static Mesh *CreateQuad();
    static Mesh *CreateCube();
    static Mesh *CreateSphere(int stacks, int slices);

private:
    GLuint VAO, VBO, EBO;
    GLsizei vertexCount, indexCount;
};

#endif