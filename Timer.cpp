//
// Created by neutron on 16.11.2026.
//

#include "Timer.h"

inline std::vector<GLuint> sum(std::vector<GLuint> v1, int mod) {
    std::vector<GLuint> v2(v1.size());
    for (int i = 0; i < v1.size(); i++) {
        v2[i] = v1[i] + mod;
    }
    return v2;
}


Timer::Timer(int score, GLfloat offsetX, GLfloat offsetY, GLfloat scale, GLfloat color_[3]) : timer(score) {
    GLfloat tempVert[] = {
        // first part 00<-
        0.50f, 0.50f, 0.0f,     color_[0], color_[1], color_[2],   // 0
        0.60f, 0.50f, 0.0f,     color_[0], color_[1], color_[2],   // 1
        0.58f, 0.48f, 0.0f,     color_[0], color_[1], color_[2],   // 2
        0.52f, 0.48f, 0.0f,     color_[0], color_[1], color_[2],   // 3
        0.52f, 0.42f, 0.0f,     color_[0], color_[1], color_[2],   // 4
        0.58f, 0.42f, 0.0f,     color_[0], color_[1], color_[2],   // 5
        0.50f, 0.41f, 0.0f,     color_[0], color_[1], color_[2],   // 6
        0.60f, 0.41f, 0.0f,     color_[0], color_[1], color_[2],   // 7
        0.52f, 0.40f, 0.0f,     color_[0], color_[1], color_[2],   // 8
        0.52f, 0.34f, 0.0f,     color_[0], color_[1], color_[2],   // 9
        0.58f, 0.40f, 0.0f,     color_[0], color_[1], color_[2],   // 10
        0.58f, 0.34f, 0.0f,     color_[0], color_[1], color_[2],   // 11
        0.50f, 0.32f, 0.0f,     color_[0], color_[1], color_[2],   // 12
        0.60f, 0.32f, 0.0f,     color_[0], color_[1], color_[2],   // 13

        // second part ->00
        0.35f, 0.50f, 0.0f,     color_[0], color_[1], color_[2],   // 14
        0.45f, 0.50f, 0.0f,     color_[0], color_[1], color_[2],   // 15
        0.43f, 0.48f, 0.0f,     color_[0], color_[1], color_[2],   // 16
        0.37f, 0.48f, 0.0f,     color_[0], color_[1], color_[2],   // 17
        0.37f, 0.42f, 0.0f,     color_[0], color_[1], color_[2],   // 18
        0.43f, 0.42f, 0.0f,     color_[0], color_[1], color_[2],   // 19
        0.35f, 0.41f, 0.0f,     color_[0], color_[1], color_[2],   // 20
        0.45f, 0.41f, 0.0f,     color_[0], color_[1], color_[2],   // 21
        0.37f, 0.40f, 0.0f,     color_[0], color_[1], color_[2],   // 22
        0.37f, 0.34f, 0.0f,     color_[0], color_[1], color_[2],   // 23
        0.43f, 0.40f, 0.0f,     color_[0], color_[1], color_[2],   // 24
        0.43f, 0.34f, 0.0f,     color_[0], color_[1], color_[2],   // 25
        0.35f, 0.32f, 0.0f,     color_[0], color_[1], color_[2],   // 26
        0.45f, 0.32f, 0.0f,     color_[0], color_[1], color_[2]    // 27
    };
    // Set the points for the score
    for (int i = 0; i < 168; i++) {
        verticies[i] = tempVert[i];
    }

    switch (timer % 10) {
        case 0:
            indicies = numbers_int::ZERO;
            break;
        case 1:
            indicies = numbers_int::ONE;
            break;
        case 2:
            indicies = numbers_int::TWO;
            break;
        case 3:
            indicies = numbers_int::THREE;
            break;
        case 4:
            indicies = numbers_int::FOUR;
            break;
        case 5:
            indicies = numbers_int::FIVE;
            break;
        case 6:
            indicies = numbers_int::SIX;
            break;
        case 7:
            indicies = numbers_int::SEVEN;
            break;
        case 8:
            indicies = numbers_int::EIGHT;
            break;
        case 9:
            indicies = numbers_int::NINE;
            break;
        default:
            break;
    } // left digit

    std::vector<GLuint>tempInd;
    switch (timer / 10) {
        case 0:
            tempInd = sum(numbers_int::ZERO, 14);
            for (int i = 0; i < numbers_int::ZERO.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 1:
            tempInd = sum(numbers_int::ONE, 14);
            for (int i = 0; i < numbers_int::ONE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 2:
            tempInd = sum(numbers_int::TWO, 14);
            for (int i = 0; i < numbers_int::TWO.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 3:
            tempInd = sum(numbers_int::THREE, 14);
            for (int i = 0; i < numbers_int::THREE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 4:
            tempInd = sum(numbers_int::FOUR, 14);
            for (int i = 0; i < numbers_int::FOUR.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 5:
            tempInd = sum(numbers_int::FIVE, 14);
            for (int i = 0; i < numbers_int::FIVE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 6:
            tempInd = sum(numbers_int::SIX, 14);
            for (int i = 0; i < numbers_int::SIX.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 7:
            tempInd = sum(numbers_int::SEVEN, 14);
            for (int i = 0; i < numbers_int::SEVEN.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 8:
            tempInd = sum(numbers_int::EIGHT, 14);
            for (int i = 0; i < numbers_int::EIGHT.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 9:
            tempInd = sum(numbers_int::NINE, 14);
            for (int i = 0; i < numbers_int::NINE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        default:
            break;
    } // right digit

    // sets an offset for the score
    for (int i = 0; i < (sizeof(verticies) / sizeof(GLfloat)); i+=6) {
        verticies[i] += offsetX;
        verticies[i+1] += offsetY;
    }

    // changes size of the score counter
    for (int i = 0; i < (sizeof(verticies) / sizeof(GLfloat)); i++) {
        verticies[i] *= scale;
    }

}


void Timer::timerBind() {
    // Generates Vertex Array Object and binds it
    timerVAO.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(verticies, sizeof(verticies));
    timerVBO = VBO1;
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indicies.data(), indicies.size() * sizeof(GLuint));
    timerEBO = EBO1;
}

void Timer::timerLink() {
    // Links VBO attributes such as coordinates and colors to VAO
    timerVAO.LinkAttrib(timerVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    timerVAO.LinkAttrib(timerVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Timer::timerUnbind() {
    // Unbinds VAO, VBO, EBO
    timerVAO.Unbind();
    timerVBO.Unbind();
    timerEBO.Unbind();
}

void Timer::timerDraw() {
    // Bind the VAO so OpenGL knows to use it
    timerVAO.Bind();
    // Draw primitives, number of indices, datatype of indices, index of indices
    glDrawElements(GL_TRIANGLES, indicies.size(), GL_UNSIGNED_INT, 0);
}

void Timer::timerDelete() {
    // Delete's the square 'Cube'
    timerVAO.Delete();
    timerVBO.Delete();
    timerEBO.Delete();
}

void Timer::timerInit() {
    // Bind the square's VAO, VBO, EBO
    timerBind();
    // Link the square
    timerLink();
    // Unbind the square's VAO, VBO, EBO
    timerUnbind();
}

void Timer::timerUpdate(int timer) {
    // clear indices array so it does not break reality
    this->timer = timer;
    indicies.clear();

    // reset the numbers
    switch (timer % 10) {
        case 0:
            indicies = numbers_int::ZERO;
            break;
        case 1:
            indicies = numbers_int::ONE;
            break;
        case 2:
            indicies = numbers_int::TWO;
            break;
        case 3:
            indicies = numbers_int::THREE;
            break;
        case 4:
            indicies = numbers_int::FOUR;
            break;
        case 5:
            indicies = numbers_int::FIVE;
            break;
        case 6:
            indicies = numbers_int::SIX;
            break;
        case 7:
            indicies = numbers_int::SEVEN;
            break;
        case 8:
            indicies = numbers_int::EIGHT;
            break;
        case 9:
            indicies = numbers_int::NINE;
            break;
        default:
            break;
    } // left digit
    std::vector<GLuint>tempInd;
    switch (timer / 10) {
        case 0:
            tempInd = sum(numbers_int::ZERO, 14);
            for (int i = 0; i < numbers_int::ZERO.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 1:
            tempInd = sum(numbers_int::ONE, 14);
            for (int i = 0; i < numbers_int::ONE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 2:
            tempInd = sum(numbers_int::TWO, 14);
            for (int i = 0; i < numbers_int::TWO.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 3:
            tempInd = sum(numbers_int::THREE, 14);
            for (int i = 0; i < numbers_int::THREE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 4:
            tempInd = sum(numbers_int::FOUR, 14);
            for (int i = 0; i < numbers_int::FOUR.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 5:
            tempInd = sum(numbers_int::FIVE, 14);
            for (int i = 0; i < numbers_int::FIVE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 6:
            tempInd = sum(numbers_int::SIX, 14);
            for (int i = 0; i < numbers_int::SIX.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 7:
            tempInd = sum(numbers_int::SEVEN, 14);
            for (int i = 0; i < numbers_int::SEVEN.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 8:
            tempInd = sum(numbers_int::EIGHT, 14);
            for (int i = 0; i < numbers_int::EIGHT.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        case 9:
            tempInd = sum(numbers_int::NINE, 14);
            for (int i = 0; i < numbers_int::NINE.size(); i++) {
                indicies.push_back(tempInd[i]);
            }
            break;
        default:
            break;
    } // right digit

    // rebind the buffer array so it looks ok and does not crash?? | maybe
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(GLuint), indicies.data(), GL_DYNAMIC_DRAW);
    glDrawElements(GL_TRIANGLES, indicies.size(), GL_UNSIGNED_INT, 0);

}