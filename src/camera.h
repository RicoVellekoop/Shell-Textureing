#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
    glm::vec3 position;
    glm::vec3 direction;
    float fieldOfView;
    float nearPlane;
    float farPlane;

public:
    Camera() : position(0.0f, 0.0f, 0.0f), direction(0.0f, 0.0f, -1.0f),
               fieldOfView(45.0f), nearPlane(0.1f), farPlane(1000.0f) {}

    Camera(const glm::vec3 &position, const glm::vec3 &lookAt)
        : position(position), fieldOfView(45.0f), nearPlane(0.1f), farPlane(1000.0f)
    {
        LookAt(lookAt);
    }

    void LookAt(const glm::vec3 &target)
    {
        direction = glm::normalize(target - position);
    }

    glm::mat4 GetViewMatrix() const
    {
        return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    glm::mat4 GetProjectionMatrix(float aspectRatio) const
    {
        return glm::perspective(glm::radians(fieldOfView), aspectRatio, nearPlane, farPlane);
    }
};

#endif