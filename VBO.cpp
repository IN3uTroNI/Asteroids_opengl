#include "headers/VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size) {
    glGenBuffers(1, &ID);
    // Make the VBO specifing it is a GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    // Insert the vertices in the VBO
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::Bind() {
    // Make the VBO specifing it is a GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
    // Make the VBO specifing it is a GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
    glDeleteBuffers(1, &ID);
}