#include "mesh.h"

Mesh::Mesh(const std::vector<Vertex> &vertices)
{
    // Generate and bind the Vertex Array Object (VAO)
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind the Vertex Buffer Object (VBO)
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Copy the vertex data to the buffer
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    // Set the vertex attributes pointers
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, uv));

    // Unbind the VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    // Delete the VAO and VBO
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void Mesh::Render()
{
    // Bind the VAO
    glBindVertexArray(VAO);

    // Draw the mesh
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    // Unbind the VAO
    glBindVertexArray(0);
}

Mesh *Mesh::CreateTriangle()
{
    // Create the vertices
    std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.25f, 0.0f}},
        {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.75f, 0.0f}},
        {{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5f, 1.0f}}};

    // Create the mesh
    return new Mesh(vertices);
}
