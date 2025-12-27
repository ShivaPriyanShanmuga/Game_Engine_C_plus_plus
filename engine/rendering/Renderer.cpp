#include "Renderer.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

Renderer::Renderer(float screenWidth, float screenHeight) 
: shader("shaders/basic.vert", "shaders/basic.frag"), 
  camera(screenWidth, screenHeight) {

    float vertices[] = {
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Renderer::begin() {
    shader.use();
    shader.setMat4("projection", camera.getProjection());
}

void Renderer::drawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color) {
    shader.use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));

    shader.setMat4("model", model);
    shader.setVec4("color", color);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Renderer::end() {
    glBindVertexArray(0);
}
