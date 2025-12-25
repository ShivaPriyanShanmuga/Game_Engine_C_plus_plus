#pragma once

#include "../window/Window.h"

class Engine {
public:
    Engine();
    ~Engine();
    void run();

private:
    Window window;
};