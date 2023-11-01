#version 330 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;

out vec3 Normal;
out vec3 FragPos;
out vec2 TexCoord;

void main()
{
    vec4 pos = (projection * view * model) * vec4(position, 1.0);
    gl_Position = vec4(pos.xyz / pos.w, 1.0);
    Normal = normal;
    FragPos = position;
    TexCoord = texCoord;
}

