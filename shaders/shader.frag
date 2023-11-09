#version 330 core

layout(location = 0) out vec4 FragColor;

// Input from the vertex shader
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

uniform sampler2D texture_diffuse1;

// Uniforms
void main()
{
    vec4 texColor = texture(texture_diffuse1, TexCoord);
    FragColor = vec4(texColor);
}