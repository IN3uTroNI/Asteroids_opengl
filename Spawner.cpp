//
// Created by neutron on 11/18/26.
//

#include "headers/Spawner.h"

#include <cstdlib>
#include <ctime>

Spawner::Spawner(GLfloat position[2]) {
    GLfloat newVert[24] = {
        position[0] - 0.01f, position[1] + 0.01f, 0.0f, 1.0f, 1.0f, 1.0f, // Upper left corner
        position[0] - 0.01f, position[1] - 0.01f, 0.0f, 1.0f, 1.0f, 1.0f, // Lower left corner
        position[0] + 0.01f, position[1] + 0.01f, 0.0f, 1.0f, 1.0f, 1.0f, // Upper right corner
        position[0] + 0.01f, position[1] - 0.01f, 0.0f, 1.0f, 1.0f, 1.0f // Lower right corner
    };
    for (int i = 0; i < 24; i++) {
        vertices[i] = newVert[i];
    }
}

void Spawner::spawnerBind() {
    // Generates Vertex Array Object and binds it
    spawnerVAO.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    spawnerVBO = VBO1;
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));
    spawnerEBO = EBO1;
}

void Spawner::spawnerLink() {
    // Links VBO attributes such as coordinates and colors to VAO
    spawnerVAO.LinkAttrib(spawnerVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    spawnerVAO.LinkAttrib(spawnerVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Spawner::spawnerUnbind() {
    // Unbinds VAO, VBO, EBO
    spawnerVAO.Unbind();
    spawnerVBO.Unbind();
    spawnerEBO.Unbind();
}

void Spawner::spawnerDraw() {
    // Bind the VAO so OpenGL knows to use it
    spawnerVAO.Bind();
    // Draw primitives, number of indices, datatype of indices, index of indices
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Spawner::spawnerDelete() {
    // Delete's the square 'Cube'
    spawnerVAO.Delete();
    spawnerVBO.Delete();
    spawnerEBO.Delete();
}

void Spawner::spawnerInit() {
    // Bind the square's VAO, VBO, EBO
    spawnerBind();
    // Link the square
    spawnerLink();
    // Unbind the square's VAO, VBO, EBO
    spawnerUnbind();
}


void Spawner::spawnerMovement() {
    std::srand(time(NULL));
    cooldown--;
    GLfloat currentPos[2] = {
        vertices[0], vertices[1]
    };
    static float speedx = 0.005f;
    if (vertices[0] <= -0.6f) {
        speedx = -speedx;
    }
    if (vertices[12] >= 0.6f) {
        speedx = -speedx;
    }

    for (int i = 0; i < 24; i+=6) {
        vertices[i] += speedx;
    }

    if (cooldown == 0) {
        circles.push_back(*new Circle(currentPos, 0.05f, colors::brown, res::MEDIUM_LOW_RES));
        circles[circles.size()-1].circleInit();
        cooldown = 200 - (rand() % 100 + 1);
    }

    GLfloat circleYPos;
    for (int i = 0; i < circles.size(); i++) {
        circles[i].circleMMove();
        circles[i].circleDraw();
        circleYPos = circles[i].getPos();
        if (circleYPos <= -0.7f ) {
            circles[i].circleDelete();
            circles.erase(circles.begin() + i);
            alive = false;
        }
    }

    spawnerUpdate();
}


void Spawner::spawnerUpdate() {
    spawnerVBO.Bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    spawnerVBO.Unbind();
}


bool Spawner::spawnerCollision(GLfloat position[2]) {
    for (int i = 0; i < circles.size(); i++) {
        if (circles[i].getCollision(position)) {
            circles[i].circleDelete();
            circles.erase(circles.begin() + i);
            return true;
        }
    }
    return false;
}

bool Spawner::getAlive() {
    return alive;
}
