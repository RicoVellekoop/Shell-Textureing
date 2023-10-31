#ifndef APPLICATION_H
#define APPLICATION_H

#include "appwindow.h"
#include "shader.h"
#include "mesh.h"

class Application
{
public:
    Application();
    ~Application();
    void Run();
    // ... other methods as needed
private:
    AppWindow *window;
    Shader *shader;
    Mesh *mesh;
    // ... other data members as needed
};

#endif