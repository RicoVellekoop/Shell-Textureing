#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    Shader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource);
    ~Shader();
    void Use();
    void SetMat4(const std::string &name, const glm::mat4 &value);
    void SetVec3(const std::string &name, const glm::vec3 &value);

private:
    GLuint program;
};

#endif