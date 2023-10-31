#version 330 core

layout(location = 0) out vec4 FragColor;

// Input from the vertex shader
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

void main()
{
    FragColor = vec4(TexCoord, 0.0, 1.0); // Red color
}