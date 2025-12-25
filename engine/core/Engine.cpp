#include "Engine.h"
#include <iostream>

Engine::Engine() : running(true) {}

Engine::~Engine() {}

void Engine::run() {
    while (running) {
        std::cout << "Engine is running..." << std::endl;
        // For demonstration purposes, we'll stop the engine after one iteration
        running = false;
    }
}