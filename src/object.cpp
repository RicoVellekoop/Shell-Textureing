#include "object.h"

Object::Object(Mesh *mesh, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
    this->mesh = mesh;
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

Object::Object(Mesh *mesh, glm::vec3 position, glm::vec3 rotation)
{
    this->mesh = mesh;
    this->position = position;
    this->rotation = rotation;
    this->scale = glm::vec3(1.0f);
}

Object::Object(Mesh *mesh, glm::vec3 position)
{
    this->mesh = mesh;
    this->position = position;
    this->rotation = glm::vec3(0.0f);
    this->scale = glm::vec3(1.0f);
}

Object::Object(Mesh *mesh)
{
    this->mesh = mesh;
    this->position = glm::vec3(0.0f);
    this->rotation = glm::vec3(0.0f);
    this->scale = glm::vec3(1.0f);
}

Object::~Object()
{
    delete mesh;
}

void Object::Render()
{
    mesh->Render();
}

glm::mat4 Object::GetModelMatrix()
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, scale);
    return model;
}
