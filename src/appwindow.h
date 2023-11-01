#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <string>
#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "camera.h"

class AppWindow
{
public:
    AppWindow(int width, int height, const std::string &title);
    ~AppWindow();
    void Update();
    bool ShouldClose() const;

    void Resize(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        // Get the AppWindow instance from the GLFW window
        AppWindow *appWindow = static_cast<AppWindow *>(glfwGetWindowUserPointer(window));

        // Update the AppWindow's width and height
        appWindow->Resize(width, height);
    }

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    float GetAspectRatio() const { return float(width) / height; }
    GLFWwindow *GetGLFWWindow() const { return window; }

private:
    GLFWwindow *window;
    int width;
    int height;
};

#endif