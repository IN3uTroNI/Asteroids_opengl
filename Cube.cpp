//
// Created by neutron on 14.11.2026.
//

#include "headers/Cube.h"
#include "headers/Colors.h"

#include <iostream>
#include <ostream>

Cube::Cube(GLfloat centerPoint_[2], GLfloat height_, GLfloat width_, GLfloat color_[3]) {
    GLfloat newVert[24] = {
        centerPoint_[0],              centerPoint_[1] + (height_/3),    0.0f,    color_[0], color_[1], color_[2], // Center up corner
        centerPoint_[0] - (width_/2), centerPoint_[1] - (height_/2),    0.0f,    color_[0], color_[1], color_[2], // Lower left corner
        centerPoint_[0],              centerPoint_[1] - (height_/3),    0.0f,    color_[0], color_[1], color_[2], // Center down corner
        centerPoint_[0] + (width_/2), centerPoint_[1] - (height_/2),    0.0f,    color_[0], color_[1], color_[2], // Lower right corner
    };

    for (int i = 0; i < 24; i++) {
        vertices[i] = newVert[i];
    }
}

void Cube::cubeBind() {
    // Generates Vertex Array Object and binds it
    cubeVAO.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    cubeVBO = VBO1;
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));
    cubeEBO = EBO1;
}

void Cube::cubeLink() {
    // Links VBO attributes such as coordinates and colors to VAO
    cubeVAO.LinkAttrib(cubeVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    cubeVAO.LinkAttrib(cubeVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Cube::cubeUnbind() {
    // Unbinds VAO, VBO, EBO
    cubeVAO.Unbind();
    cubeVBO.Unbind();
    cubeEBO.Unbind();
}

void Cube::drawCube() {
    // Bind the VAO so OpenGL knows to use it
    cubeVAO.Bind();
    // Draw primitives, number of indices, datatype of indices, index of indices
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Cube::cubeDelete() {
    // Delete's the square 'Cube'
    cubeVAO.Delete();
    cubeVBO.Delete();
    cubeEBO.Delete();
}

void Cube::cubeInit() {
    // Bind the square's VAO, VBO, EBO
    cubeBind();
    // Link the square
    cubeLink();
    // Unbind the square's VAO, VBO, EBO
    cubeUnbind();
}

void Cube::Input(GLFWwindow* window) {
    float speed = 0.02f;
    if ((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) && (vertices[0] <= 0.6f)) { // right
        for (int i = 0; i < sizeof(vertices)/sizeof(vertices[0]); i+=6) {
            vertices[i] += speed;
        }
    }
    if ((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) && (vertices[12] >= -0.6f)) { // left
        for (int i = 0; i < sizeof(vertices)/sizeof(vertices[0]); i+=6) {
            vertices[i] -= speed;
        }
    }

    cubeUpdate();
}

void Cube::cubeUpdate() {
    cubeVBO.Bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    cubeVBO.Unbind();
}

bool Cube::getCollision(GLfloat pointColl[2]) {
    return pointColl[0] >= vertices[6]  &&   // left
           pointColl[0] <= vertices[12] &&   // right
           pointColl[1] >= vertices[7]  &&   // bottom
           pointColl[1] <= vertices[1];      // top
}
