#include "Camera2D.h"
#include <glm/gtc/matrix_transform.hpp>

Camera2D::Camera2D(float width, float height) {
    projection = glm::ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
}

const glm::mat4& Camera2D::getProjection() const {
    return projection;
}
