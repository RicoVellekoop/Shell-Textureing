#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <string>
#include <stdexcept>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class AppWindow
{
public:
    AppWindow(int width, int height, const std::string &title);
    ~AppWindow();
    void Update();
    bool ShouldClose() const;
    // ... other methods as needed
private:
    GLFWwindow *window;
    // ... other data members as needed
};

#endif