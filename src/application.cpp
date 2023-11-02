#include "application.h"

Application::Application()
{
    window = new AppWindow(800, 600, "OpenGL Application");
    shader = new Shader("../shaders/shader.vert", "../shaders/shader.frag");
    objects = std::vector<Object *>();
    camera = Camera(glm::vec3(3.0f, 3.0f, 3.0f), // Camera position
                    glm::vec3(0.0f, 0.0f, 0.0f)  // Target position
    );
}

Application::~Application()
{
    for (auto obj : objects)
    {
        delete obj;
    }
    objects.clear();

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
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window->GetGLFWWindow(), true); // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    while (!window->ShouldClose())
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        bool open = true;
        if (ImGui::Begin("My Custom Window", &open))
        {
            object->Menu();
            for (auto obj : objects)
            {
                obj->Menu();
            }
        }

        ImGui::End();

        shader->Use();
        shader->SetMat4("view", camera.GetViewMatrix());
        shader->SetMat4("projection", camera.GetProjectionMatrix(window->GetAspectRatio()));

        for (auto object : objects)
        {
            shader->SetMat4("model", object->GetModelMatrix());
            object->Render();
        }

        ImGui::Render();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window->Update();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
