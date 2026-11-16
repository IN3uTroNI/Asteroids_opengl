#include "headers/VAO.h"

VAO::VAO() {

    // Generate VAO and VBO with only one object each
    glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
    vbo.Bind();
     // Configure the Vertex Atribute so opengl knows how to read the VBO
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    // Enable vertex attribute so opengl knows to use it
    glEnableVertexAttribArray(layout);
    vbo.Unbind();
}

void VAO::Bind() { 
    // Make the VAO the current vertext array object by binding it
    glBindVertexArray(ID);
}

void VAO::Unbind() {
    // bind VAO and VBO to 0 so we don't accidentaly modify them;
    glBindVertexArray(0);

}

void VAO::Delete() {
    glDeleteVertexArrays(1, &ID);

}