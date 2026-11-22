//
// Created by neutron on 11/18/26.
//

#ifndef MYOPENGLPROJECT_BULLET_H
#define MYOPENGLPROJECT_BULLET_H
#include <vector>

#include "EBO.h"
#pragma once
class Spawner;
#include "VAO.h"


class Bullet {
public:

    GLfloat verticies[18];
    GLuint indicies[3] = {
        0, 1, 2
    };
    Spawner* spawner;
    int* score;

    VAO bulletVAO;
    VBO bulletVBO;
    EBO bulletEBO;

    Bullet(GLfloat posX, GLfloat posY, Spawner &spawner, int &score);
    void bulletBind();
    void bulletLink();
    void bulletUnbind();
    void bulletDraw();
    void bulletDelete();
    void bulletInit();
    void bulletUpdate();
    void bulletMove();
    bool getCollision();
    std::vector<GLfloat> getPosition();
};


#endif //MYOPENGLPROJECT_BULLET_H
