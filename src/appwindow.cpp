#include "appwindow.h"

AppWindow::AppWindow(int width, int height, const std::string &title) : width(width), height(height)
{
    // Initialize GLFW
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    // Create a GLFWwindow object
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLEW");
    }

    // Set the framebuffer size callback
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    // Store a pointer to this AppWindow instance in the GLFW window
    glfwSetWindowUserPointer(window, this);
}

AppWindow::~AppWindow()
{
    glfwTerminate();
}

void AppWindow::Update()
{
    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
}

bool AppWindow::ShouldClose() const
{
    return glfwWindowShouldClose(window);
}
