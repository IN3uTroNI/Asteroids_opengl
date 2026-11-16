//
// Created by neutron on 16.11.2026.
//

#ifndef MYOPENGLPROJECT_TIMER_H
#define MYOPENGLPROJECT_TIMER_H

#include <vector>

#include "EBO.h"
#include "VAO.h"


namespace numbers_int {

    inline std::vector<GLuint> ZERO = {      // A B C D E F
        0, 1, 2,   0, 2, 3,
        1, 2, 5,   1, 5, 7,
        7, 10, 11, 7, 11, 13,
        12, 13, 11, 12, 11, 9,
        6, 8, 9,   6, 9, 12,
        0, 3, 4,   0, 4, 6
    };

    inline std::vector<GLuint> ONE = {       // B C
        1, 2, 5,   1, 5, 7,
        7, 10, 11, 7, 11, 13
    };

    inline std::vector<GLuint> TWO = {       // A B G E D
        0, 1, 2,   0, 2, 3,
        1, 2, 5,   1, 5, 7,
        6, 4, 8,   4, 5, 10,  4, 10, 8,  7, 5, 10,
        6, 8, 9,   6, 9, 12,
        12, 13, 11, 12, 11, 9
    };

    inline std::vector<GLuint> THREE = {     // A B G C D
        0, 1, 2,   0, 2, 3,
        1, 2, 5,   1, 5, 7,
        6, 4, 8,   4, 5, 10,  4, 10, 8,  7, 5, 10,
        7, 10, 11, 7, 11, 13,
        12, 13, 11, 12, 11, 9
    };

    inline std::vector<GLuint> FOUR = {      // F G B C
        0, 3, 4,   0, 4, 6,
        6, 4, 8,   4, 5, 10,  4, 10, 8,  7, 5, 10,
        1, 2, 5,   1, 5, 7,
        7, 10, 11, 7, 11, 13
    };

    inline std::vector<GLuint> FIVE = {      // A F G C D
        0, 1, 2,   0, 2, 3,
        0, 3, 4,   0, 4, 6,
        6, 4, 8,   4, 5, 10,  4, 10, 8,  7, 5, 10,
        7, 10, 11, 7, 11, 13,
        12, 13, 11, 12, 11, 9
    };

    inline std::vector<GLuint> SIX = {       // A F G E D C
        0, 1, 2,   0, 2, 3,
        0, 3, 4,   0, 4, 6,
        6, 4, 8,   4, 5, 10,  4, 10, 8,  7, 5, 10,
        6, 8, 9,   6, 9, 12,
        12, 13, 11, 12, 11, 9,
        7, 10, 11, 7, 11, 13
    };

    inline std::vector<GLuint> SEVEN = {     // A B C
        0, 1, 2,   0, 2, 3,
        1, 2, 5,   1, 5, 7,
        7, 10, 11, 7, 11, 13
    };

    inline std::vector<GLuint> EIGHT = {     // A B C D E F G
        0, 1, 2,   0, 2, 3,
        1, 2, 5,   1, 5, 7,
        7, 10, 11, 7, 11, 13,
        12, 13, 11, 12, 11, 9,
        6, 8, 9,   6, 9, 12,
        0, 3, 4,   0, 4, 6,
        6, 4, 8,   4, 5, 10,  4, 10, 8,  7, 5, 10
    };

    inline std::vector<GLuint> NINE = {      // A B C D F G
        0, 1, 2,   0, 2, 3,
        1, 2, 5,   1, 5, 7,
        7, 10, 11, 7, 11, 13,
        12, 13, 11, 12, 11, 9,
        0, 3, 4,   0, 4, 6,
        6, 4, 8,   4, 5, 10,  4, 10, 8,  7, 5, 10
    };
}


class Timer {
public:
    int timer;
    GLfloat verticies[168];
    std::vector<GLuint> indicies;

    VAO timerVAO;
    VBO timerVBO;
    EBO timerEBO;

    Timer(int score, GLfloat offsetX, GLfloat offsetY, GLfloat scale);
    void timerBind();
    void timerLink();
    void timerUnbind();
    void timerDraw();
    void timerDelete();
    void timerInit();
    void timerUpdate(int timer);
};


#endif //MYOPENGLPROJECT_TIMER_H
