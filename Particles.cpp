//
// Created by neutron on 22.11.2026.
//

#include "headers/Particles.h"

#include "Colors.h"

Particles::Particles(std::vector<GLfloat> centerPosition) {
    GLfloat tempVec[] = {                                                                                 // Accual num-> | <- the coresponding triangle
        centerPosition[0]        , centerPosition[1]        , 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point Thri 0  1 CENTER
        centerPosition[0] - 0.05f, centerPosition[1]        , 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 1  1
        centerPosition[0] - 0.03f, centerPosition[1] + 0.05f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 2  1

        centerPosition[0]        , centerPosition[1]        , 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 3  2 CENTER
        centerPosition[0] - 0.05f, centerPosition[1]        , 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 4  2
        centerPosition[0] - 0.01f, centerPosition[1] - 0.05f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 5  2

        centerPosition[0]        , centerPosition[1]        , 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 6  3 CENTER
        centerPosition[0] - 0.01f, centerPosition[1] - 0.05f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 7  3
        centerPosition[0] + 0.05f, centerPosition[1] - 0.01f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 8  3

        centerPosition[0]        , centerPosition[1]        , 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 9  4 CENTER
        centerPosition[0] + 0.05f, centerPosition[1] - 0.01f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 10 4
        centerPosition[0] + 0.03f, centerPosition[1] + 0.04f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 11 4

        centerPosition[0]        , centerPosition[1]        , 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 12 5 CENTER
        centerPosition[0] + 0.03f, centerPosition[1] + 0.04f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2], // Point THri 13 5
        centerPosition[0] - 0.03f, centerPosition[1] + 0.05f, 0.0f, colors::brown[0], colors::brown[1], colors::brown[2]  // Point THri 14 5
    };
    for (int i = 0; i < sizeof(tempVec)/sizeof(tempVec[0]); i++) {
        vertices[i] = tempVec[i];
    }
    GLuint tempInd[] = {
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11,
        12, 13, 14
    };
    for (int i = 0; i < sizeof(tempInd)/sizeof(tempInd[0]); i++) {
        indices[i] = tempInd[i];
    }
}

void Particles::partBind() {
    // Generates Vertex Array Object and binds it
    parVAO.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    parVBO = VBO1;
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));
    parEBO = EBO1;
}

void Particles::partLink() {
    // Links VBO attributes such as coordinates and colors to VAO
    parVAO.LinkAttrib(parVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    parVAO.LinkAttrib(parVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Particles::partUnbind() {
    parVAO.Unbind();
    parVBO.Unbind();
    parEBO.Unbind();
}
void Particles::partDraw() {
    // Bind the VAO so OpenGL knows to use it
    parVAO.Bind();
    // Draw primitives, number of indices, datatype of indices, index of indices
    glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, 0);
}

void Particles::partDelete() {
    // Delete's the square 'Cube'
    parVAO.Delete();
    parVBO.Delete();
    parEBO.Delete();
}

void Particles::partInit() {
    // Bind the square's VAO, VBO, EBO
    partBind();
    // Link the square
    partLink();
    // Unbind the square's VAO, VBO, EBO
    partUnbind();
}

void Particles::partUpdate() {
    parVBO.Bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    parVBO.Unbind();
}

void Particles::partMove() {
    static float speedx = 0.0005f;
    static float speedy = 0.0005f;

    // triangle 1
    for (int i = 0; i < (sizeof(vertices)/sizeof(vertices[0]))/5; i+=6) {
        vertices[i] -= speedx;
        vertices[i+1] += speedy;
    }

    // triangle 2
    for (int i = 18; i < ((sizeof(vertices)/sizeof(vertices[0]))/5)*2; i+=6) {
        vertices[i] += speedx;
        vertices[i+1] += 0.0f;
    }

    // triangle 3
    for (int i = 36; i < ((sizeof(vertices)/sizeof(vertices[0]))/5)*3; i+=6) {
        vertices[i] += speedx;
        vertices[i+1] += speedy;
    }

    // triangle 4
    for (int i = 54; i < ((sizeof(vertices)/sizeof(vertices[0]))/5)*4; i+=6) {
        vertices[i] -= speedx;
        vertices[i+1] -= speedy;
    }

    // triangle 5
    for (int i = 72; i < (sizeof(vertices)/sizeof(vertices[0])); i+=6) {
        vertices[i] += speedx;
        vertices[i+1] -= speedy;
    }

    Duration--;

    partUpdate();
}

int Particles::partGetDuration() {
    return Duration;
}
