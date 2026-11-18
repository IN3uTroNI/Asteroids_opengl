//
// Created by neutron on 11/18/26.
//

#ifndef MYOPENGLPROJECT_SPAWNER_H
#define MYOPENGLPROJECT_SPAWNER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Colors.h"

#include "Circle.h"

class Spawner {
public:
    int cooldown = 200;
    GLfloat vertices[24];
    GLuint indices[6] = {
        0, 1, 2,
        2, 3, 1
    };
    std::vector<Circle> circles;

    VAO spawnerVAO;
    VBO spawnerVBO;
    EBO spawnerEBO;


    Spawner(GLfloat position[2]);
    void spawnerMovement();
    void spawnerBind();
    void spawnerLink();
    void spawnerUnbind();
    void spawnerDraw();
    void spawnerDelete();
    void spawnerInit();
    void spawnerUpdate();
    bool spawnerCollision(GLfloat position[2]);


};


#endif //MYOPENGLPROJECT_SPAWNER_H
