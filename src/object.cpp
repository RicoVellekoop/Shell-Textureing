#include "object.h"

Object::Object(Mesh *mesh, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
    this->id = GetNextId();
    this->mesh = mesh;
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

Object::Object(Mesh *mesh, glm::vec3 position, glm::vec3 rotation)
{
    this->id = GetNextId();

    this->mesh = mesh;
    this->position = position;
    this->rotation = rotation;
    this->scale = glm::vec3(1.0f);
}

Object::Object(Mesh *mesh, glm::vec3 position)
{
    this->id = GetNextId();
    this->mesh = mesh;
    this->position = position;
    this->rotation = glm::vec3(0.0f);
    this->scale = glm::vec3(1.0f);
}

Object::Object(Mesh *mesh)
{
    this->id = GetNextId();
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

void Object::Menu()
{
    if (ImGui::CollapsingHeader(("Object " + std::to_string(GetId())).c_str()))
    {
        ImGui::SliderFloat3(("Position##" + std::to_string(GetId())).c_str(), &position.x, -10.0f, 10.0f);
        ImGui::SliderFloat3(("Rotation##" + std::to_string(GetId())).c_str(), &rotation.x, -180.0f, 180.0f);
        ImGui::SliderFloat3(("Scale##" + std::to_string(GetId())).c_str(), &scale.x, 0.0f, 10.0f);

        if (ImGui::Button(("Reset##" + std::to_string(GetId())).c_str()))
        {
            position = glm::vec3(0.0f);
            rotation = glm::vec3(0.0f);
            scale = glm::vec3(1.0f);
        }
    }
}
