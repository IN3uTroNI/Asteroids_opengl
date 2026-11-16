//
// Created by neutron on 14.11.2026.
//

#ifndef MYOPENGLPROJECT_CUBE_H
#define MYOPENGLPROJECT_CUBE_H
#define GLM_ENABLE_EXPERIMENTAL

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "EBO.h"
#include "VAO.h"
#include "VBO.h"


class Cube {
public:
    // The points
    GLfloat vertices[72];
    // Indices for vertices order
    GLuint indices[18] = {
        0, 2, 1, // Upper triangle
        1, 3, 2, // Lower triangle

        4, 5, 7, // up upper triangle
        5, 6, 7, // up lower triangle

        8, 9, 1,   // right wing
        10, 11, 3, // left wing
    };

    VAO cubeVAO;
    VBO cubeVBO;
    EBO cubeEBO;

    Cube(GLfloat centerPoint_[2], GLfloat height_, GLfloat width_, GLfloat color_[3]);
    Cube() {};
    void Input(GLFWwindow* window);
    void cubeBind();
    void cubeLink();
    void cubeUnbind();
    void drawCube();
    void cubeDelete();
    void cubeInit();
    void cubeUpdate();
    bool getCollision(GLfloat pointColl[2]);
};

#endif //MYOPENGLPROJECT_CUBE_H
