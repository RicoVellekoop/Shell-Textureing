#ifndef APPLICATION_H
#define APPLICATION_H

#include "appwindow.h"
#include "shader.h"
#include "mesh.h"
#include "camera.h"

class Application
{
public:
    Application();
    ~Application();
    void Run();

private:
    AppWindow *window;
    Shader *shader;
    Mesh *mesh;
    Camera camera;
};

#endif