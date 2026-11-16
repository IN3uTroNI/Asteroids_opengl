#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>

class EBO {
    public:
        GLuint ID;
        EBO(GLuint* indices, GLsizeiptr size);

        // Default constructor with zero info
        EBO() : ID(0) {}

        void Bind();
        void Unbind();
        void Delete();
};

#endif