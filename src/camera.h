#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

#include <imgui.h>

class ICamera
{
public:
    virtual glm::mat4 GetViewMatrix() const = 0;
    virtual glm::mat4 GetProjectionMatrix(float aspectRatio) const = 0;
};

class Camera : public ICamera
{
private:
    float fieldOfView;
    float nearPlane;
    float farPlane;

public:
    glm::vec3 position;
    glm::vec3 focusPoint;

    Camera() : position(0.0f, 0.0f, 0.0f), focusPoint(0.0f, 0.0f, -1.0f),
               fieldOfView(45.0f), nearPlane(0.1f), farPlane(1000.0f) {}

    Camera(const glm::vec3 &position, const glm::vec3 &lookAt)
        : position(position), fieldOfView(45.0f), nearPlane(0.1f), farPlane(1000.0f)
    {
        LookAt(lookAt);
    }

    void LookAt(const glm::vec3 &target)
    {
        focusPoint = target;
    }

    glm::mat4 GetViewMatrix() const
    {
        return glm::lookAt(position, focusPoint, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    glm::mat4 GetProjectionMatrix(float aspectRatio) const
    {
        return glm::perspective(glm::radians(fieldOfView), aspectRatio, nearPlane, farPlane);
    }

    void Menu()
    {
        if (ImGui::CollapsingHeader("Camera"))
        {
            ImGui::SliderFloat3("Position", &position[0], -10.0f, 10.0f);
            ImGui::SliderFloat3("Focus Point", &focusPoint[0], -10.0f, 10.0f);
            ImGui::SliderFloat("Field of View", &fieldOfView, 0.0f, 180.0f);
            ImGui::SliderFloat("Near Plane", &nearPlane, 0.0f, 10.0f);
            ImGui::SliderFloat("Far Plane", &farPlane, 0.0f, 1000.0f);
        }
    }
};

#endif