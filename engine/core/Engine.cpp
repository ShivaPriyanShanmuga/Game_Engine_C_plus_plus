#include "Engine.h"
#include <iostream>

Engine::Engine() : window(800, 600, "C++ Game Engine"), renderer(nullptr) {
    std::cout << "Window created, loading GLAD..." << std::endl;
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
    std::cout << "GLAD loaded successfully" << std::endl;
    glViewport(0, 0, 800, 600);
    
    std::cout << "Creating Renderer..." << std::endl;
    renderer = new Renderer(800, 600);
    std::cout << "Engine initialization complete" << std::endl;
}

Engine::~Engine() {
    if (renderer) {
        delete renderer;
    }
}

void Engine::run() {
    std::cout << "Starting render loop..." << std::endl;
    while (!window.shouldClose()) {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        renderer->begin();
        renderer->drawQuad({100, 100}, {60, 30}, {0.2f, 0.9f, 0.3f, 1.0f});
        renderer->end();
        
        window.swapBuffers();
        window.pollEvents();
    }
    std::cout << "Render loop ended." << std::endl;
}
