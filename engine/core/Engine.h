#pragma once

#include "../window/Window.h"
#include "../rendering/Renderer.h"

class Engine {
public:
    Engine();
    ~Engine();
    void run();

private:
    Window window;
    Renderer* renderer;
};