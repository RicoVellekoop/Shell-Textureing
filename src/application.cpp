#include "application.h"

#include <iostream>

Application::Application()
{
    window = new AppWindow(800, 600, "OpenGL Application");
    shader = new Shader("../shaders/shader.vert", "../shaders/shader.frag");
    mesh = Mesh::CreateTriangle();
    camera = Camera(glm::vec3(3.0f, 3.0f, 3.0f), // Camera position
                    glm::vec3(0.0f, 0.0f, 0.0f)  // Target position
    );
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
        shader->SetMat4("model", glm::mat4(1.0f));
        shader->SetMat4("view", camera.GetViewMatrix());
        shader->SetMat4("projection", camera.GetProjectionMatrix(window->GetAspectRatio()));

        mesh->Render();

        window->Update();
    }
}
