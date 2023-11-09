#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.h"
#include "texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui.h>
#include <string>

class Object
{
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    Object(Mesh *mesh, Texture *texture, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    Object(Mesh *mesh, Texture *texture, glm::vec3 position, glm::vec3 rotation);
    Object(Mesh *mesh, Texture *texture, glm::vec3 position);
    Object(Mesh *mesh, Texture *texture);
    Object(Mesh *mesh);

    ~Object();

    int GetId() { return id; }

    void Render();
    glm::mat4 GetModelMatrix();
    void Menu();
    static void ObjectCreationMenu(std::vector<Object *> &objects);

private:
    Mesh *mesh;
    Texture *texture;
    int id;

    static int GetNextId()
    {
        static int nextId = 0;
        return nextId++;
    }

    static Texture *getDefaultTexture()
    {
        static Texture *defaultTexture = new Texture("../assets/textures/missing_texture.png");
        return defaultTexture;
    }
};
#endif