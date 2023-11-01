#include "application.h"

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
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window->GetGLFWWindow(), true); // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    while (!window->ShouldClose())
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow(); // Show demo window! :)

        // Draw the mesh
        shader->Use();
        shader->SetMat4("model", glm::mat4(1.0f));
        shader->SetMat4("view", camera.GetViewMatrix());
        shader->SetMat4("projection", camera.GetProjectionMatrix(window->GetAspectRatio()));

        mesh->Render();

        // Rendering
        // (Your code clears your framebuffer, renders your other stuff etc.)
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // (Your code calls glfwSwapBuffers() etc.)
        window->Update();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
