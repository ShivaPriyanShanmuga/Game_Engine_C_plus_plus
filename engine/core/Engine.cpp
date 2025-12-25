#include "Engine.h"
#include <iostream>

Engine::Engine() : window(800, 600, "C++ Game Engine") {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
    glViewport(0, 0, 800, 600);
}

Engine::~Engine() {}

void Engine::run() {
    while (!window.shouldClose()) {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.swapBuffers();
        window.pollEvents();
    }
}