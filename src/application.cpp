#include "application.h"

Application::Application()
{
    window = new AppWindow(800, 600, "OpenGL Application");
    shader = new Shader("../shaders/shader.vert", "../shaders/shader.frag");
    mesh = Mesh::CreateTriangle();
}

Application::~Application()
{
    delete mesh;
    delete shader;
    delete window;
}

void Application::Run()
{
    while (!window->ShouldClose())
    {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the mesh
        shader->Use();
        mesh->Render();

        window->Update();
    }
}
