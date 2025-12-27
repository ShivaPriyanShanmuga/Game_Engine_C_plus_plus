#pragma once

#include <glm/glm.hpp>

class Camera2D {
public:
    Camera2D(float width, float height);

    const glm::mat4& getProjection() const;

private:
    glm::mat4 projection;
};
