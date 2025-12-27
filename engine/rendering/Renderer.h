#pragma once

#include "Shader.h"
#include "Camera2D.h"
#include <glm/glm.hpp>

class Renderer {
public:
    Renderer(float screenWidth, float screenHeight);
    ~Renderer();

    void begin();
    void drawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
    void end();

private:
    unsigned int VAO, VBO;
    Shader shader;
    Camera2D camera;
};
