#include "shader.h"

#include <fstream>
#include <sstream>

std::string loadShaderSource(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open shader file: " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

Shader::Shader(const std::string &vertexShaderSource, const std::string &fragmentShaderSource)
{
    // Create the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string vertexShaderSourceStr = loadShaderSource(vertexShaderSource);
    const char *vertexShaderSourceCStr = vertexShaderSourceStr.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, NULL);
    glCompileShader(vertexShader);
    GLint vertexShaderCompileStatus;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexShaderCompileStatus);
    if (vertexShaderCompileStatus != GL_TRUE)
    {
        GLint logLength;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
        std::string log(logLength, ' ');
        glGetShaderInfoLog(vertexShader, logLength, NULL, &log[0]);
        throw std::runtime_error("Failed to compile vertex shader: " + log);
    }

    // Create the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fragmentShaderSourceStr = loadShaderSource(fragmentShaderSource);
    const char *fragmentShaderSourceCStr = fragmentShaderSourceStr.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, NULL);
    glCompileShader(fragmentShader);
    GLint fragmentShaderCompileStatus;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentShaderCompileStatus);
    if (fragmentShaderCompileStatus != GL_TRUE)
    {
        GLint logLength;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
        std::string log(logLength, ' ');
        glGetShaderInfoLog(fragmentShader, logLength, NULL, &log[0]);
        throw std::runtime_error("Failed to compile fragment shader: " + log);
    }

    // Create the shader program
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    GLint shaderProgramLinkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &shaderProgramLinkStatus);
    if (shaderProgramLinkStatus != GL_TRUE)
    {
        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        std::string log(logLength, ' ');
        glGetProgramInfoLog(program, logLength, NULL, &log[0]);
        throw std::runtime_error("Failed to link shader program: " + log);
    }

    // Clean up the shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(program);
}

void Shader::Use()
{
    glUseProgram(program);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &value)
{
    GLint uniformLoc = glGetUniformLocation(program, name.c_str());
    glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetVec3(const std::string &name, const glm::vec3 &value)
{
    GLint uniformLoc = glGetUniformLocation(program, name.c_str());
    glUniform3fv(uniformLoc, 1, glm::value_ptr(value));
}
