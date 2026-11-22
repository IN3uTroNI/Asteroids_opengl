//
// Created by neutron on 22.11.2026.
//

#ifndef MYOPENGLPROJECT_PARTICLES_H
#define MYOPENGLPROJECT_PARTICLES_H
#include <vector>

#include "EBO.h"
#include "VAO.h"
#include "glad/glad.h"


class Particles {
public:
    GLfloat vertices[90];
    GLuint indices[15];
    int Duration = 200;

    VAO parVAO;
    VBO parVBO;
    EBO parEBO;

    Particles(std::vector<GLfloat> centerPosition);
    void partBind();
    void partLink();
    void partUnbind();
    void partDraw();
    void partDelete();
    void partInit();
    void partUpdate();
    void partMove();
    int partGetDuration();
};


#endif //MYOPENGLPROJECT_PARTICLES_H
