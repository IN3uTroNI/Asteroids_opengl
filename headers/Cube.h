//
// Created by neutron on 14.11.2026.
//

#ifndef MYOPENGLPROJECT_CUBE_H
#define MYOPENGLPROJECT_CUBE_H
#define GLM_ENABLE_EXPERIMENTAL

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Bullet.h"
#include "EBO.h"
#include "VAO.h"
#include "VBO.h"


class Cube {
public:
    // The points
    GLfloat vertices[24];
    // Indices for vertices order
    GLuint indices[6] = {
        0, 2, 1, // Upper triangle
        0, 3, 2, // Lower triangle
    };

    int cooldown = 50;

    std::vector<Bullet> bullets;
    Spawner& spawner;
    int* score;

    VAO cubeVAO;
    VBO cubeVBO;
    EBO cubeEBO;

    Cube(GLfloat centerPoint_[2], GLfloat height_, GLfloat width_, GLfloat color_[3], Spawner& spawner, int& score);
    void Input(GLFWwindow* window);
    void cubeBind();
    void cubeLink();
    void cubeUnbind();
    void drawCube();
    void cubeDelete();
    void cubeInit();
    void cubeUpdate();
    bool getCollision(GLfloat pointColl[2]);
    int getScore();
};

#endif //MYOPENGLPROJECT_CUBE_H
