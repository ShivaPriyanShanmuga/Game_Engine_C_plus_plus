#include "Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexCode = loadFile(vertexPath);
    std::string fragmentCode = loadFile(fragmentPath);
    compile(vertexCode.c_str(), fragmentCode.c_str());
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::use() const {
    glUseProgram(id);
}

std::string Shader::loadFile(const std::string& path) const {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to load shader file: " << path << std::endl;
        throw std::runtime_error("Failed to load shader file: " + path);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void Shader::compile(const char* vertexSrc, const char* fragmentSrc) {
    int success;
    char infoLog[512];

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexSrc, nullptr);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cerr << "Vertex shader compilation failed: " << infoLog << std::endl;
        glDeleteShader(vertex);
        throw std::runtime_error("Vertex shader compilation failed");
    }

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentSrc, nullptr);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cerr << "Fragment shader compilation failed: " << infoLog << std::endl;
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        throw std::runtime_error("Fragment shader compilation failed");
    }

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, nullptr, infoLog);
        std::cerr << "Shader program linking failed: " << infoLog << std::endl;
        glDeleteProgram(id);
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        throw std::runtime_error("Shader program linking failed");
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::setMat4(const std::string& name, const glm::mat4& value) const {
    glUniformMatrix4fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        GL_FALSE,
        &value[0][0]
    );
}

void Shader::setVec4(const std::string& name, const glm::vec4& value) const {
    glUniform4fv(
        glGetUniformLocation(id, name.c_str()),
        1,
        &value[0]
    );
}
