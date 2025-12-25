#pragma once

#include <glad/glad.h>
#include <string>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool shouldClose() const;
    void pollEvents();
    void swapBuffers();

    GLFWwindow* getNativeWindow() const;

private:
    GLFWwindow* window;
};