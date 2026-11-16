//
// Created by neutron on 14.11.2026.
//

#ifndef MYOPENGLPROJECT_CIRCLE_H
#define MYOPENGLPROJECT_CIRCLE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Cube.h"
#include "EBO.h"
#include "VAO.h"

namespace res {
    static float LOW_RES = 4.0f;
    static float MEDIUM_LOW_RES = 8.0f;
    static float MEDIUM_RES = 12.0f;
    static float MEDIUM_HIGH_RES = 16.0f;
    static float HIGH_RES = 20.0f;
}

class Circle {
    public:
        GLfloat radius;
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indecies;
        Cube& cube1;

        VAO circleVAO;
        VBO circleVBO;
        EBO circleEBO;

        Circle(GLfloat centerPoint_[2], GLfloat radius, GLfloat color_[3], float res, Cube& cube1_);
        void circleBind();
        void circleLink();
        void circleUnbind();
        void circleDraw();
        void circleDelete();
        void circleInit();
        void circleMovement();
        void circleUpdate();

};


#endif //MYOPENGLPROJECT_CIRCLE_H
