#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui.h>

class Object
{
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    Object(Mesh *mesh, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    Object(Mesh *mesh, glm::vec3 position, glm::vec3 rotation);
    Object(Mesh *mesh, glm::vec3 position);
    Object(Mesh *mesh);

    ~Object();
    void Render();
    glm::mat4 GetModelMatrix();
    void Menu();

private:
    Mesh *mesh;
};

#endif