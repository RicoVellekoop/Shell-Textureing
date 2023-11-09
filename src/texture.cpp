#include "texture.h"

Texture::Texture()
{
    glGenTextures(1, &texture);
}

Texture::Texture(const char *filename)
{
    glGenTextures(1, &texture);
    load(filename);
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture);
}

void Texture::load(const char *filename)
{
    int width, height, channels;
    unsigned char *data = stbi_load(filename, &width, &height, &channels, 0);
    if (data == NULL)
    {
        fprintf(stderr, "Error loading texture: %s\n", filename);
        exit(1);
    }

    GLenum format;
    switch (channels)
    {
    case 1:
        format = GL_RED;
        break;
    case 2:
        format = GL_RG;
        break;
    case 3:
        format = GL_RGB;
        break;
    case 4:
        format = GL_RGBA;
        break;
    default:
        fprintf(stderr, "Error loading texture: %s\n", filename);
        exit(1);
    }

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    // Set texture parameters
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, format == GL_RGBA ? GL_LINEAR : GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, format == GL_RGBA ? GL_LINEAR : GL_NEAREST);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}