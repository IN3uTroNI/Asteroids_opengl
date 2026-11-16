#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO {
    public:
        GLuint ID;
        VBO(GLfloat* vertices, GLsizeiptr size);


        // Default constructor with zero info
        VBO() : ID(0) {}

        void Bind();
        void Unbind();
        void Delete();
};

#endif