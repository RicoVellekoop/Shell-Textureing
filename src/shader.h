#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
    Shader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource);
    ~Shader();
    void Use();

private:
    GLuint program;
};

#endif