#pragma once

#include <string>
#include <iostream>
#include <glm/glm.hpp>


class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;

    void setMat4(const std::string& name, const glm::mat4& value) const;
    void setVec4(const std::string& name, const glm::vec4& value) const;

private:
    unsigned int id;

    std::string loadFile(const std::string& path) const;
    void compile(const char* vertexSrc, const char* fragmentSrc);
};
