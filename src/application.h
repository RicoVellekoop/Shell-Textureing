#ifndef APPLICATION_H
#define APPLICATION_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <vector>

#include "appwindow.h"
#include "shader.h"
#include "object.h"
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
    std::vector<Object *> objects;
    Camera camera;
};

#endif