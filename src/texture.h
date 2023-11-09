#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include "stb_image.h"

class Texture
{
public:
    Texture();
    Texture(const char *filename);
    ~Texture();
    void load(const char *filename);
    void bind();
    void unbind();

private:
    GLuint texture;
};

#endif