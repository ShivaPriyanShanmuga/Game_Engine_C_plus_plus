#pragma once

class Engine {
    public:
        Engine();
        ~Engine();

        void run();
    private:
        bool running;
};