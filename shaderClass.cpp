#include "headers/shaderClass.h"
#include <cerrno>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <string>

std::string get_file_contents(const char *filename) {
    std::ifstream in(filename, std::ios::binary);
    if (in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return (contents);
    }
    throw std::runtime_error(std::string("Failed to open shader file: ") + filename);
}

shader::shader(const char* vertextFile, const char* fragmentFile) {
    std::string vertextCode = get_file_contents(vertextFile);
    std::string fragmentCode = get_file_contents(fragmentFile);
    
    const char* vertexSource = vertextCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach the vertext shader
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    // Compile the vertext shader
    glCompileShader(vertexShader);
    
    // Create the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Attach the fragment shader
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    // Compile the fragment shader
    glCompileShader(fragmentShader);

    //  the shaders
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    // Delete the shaders as they are loaded
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void shader::Activate() {
    glUseProgram(ID);
}

void shader::Delete() {
    glDeleteProgram(ID);
}