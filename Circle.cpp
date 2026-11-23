//
// Created by neutron on 14.11.2026.
//

#include "Circle.h"
#include <iostream>
#include <glm/trigonometric.hpp>

#include "glad/glad.h"


Circle::Circle(GLfloat centerPoint_[2], GLfloat radius, GLfloat color_[3], float res) : radius(radius) {
    // Generate the points of the circle using the radius
    for (int i = 0; i <= res; i++) {
        float angle = glm::radians(360.0f / res * i);
        vertices.push_back(centerPoint_[0] + radius * glm::cos(angle)); // x
        vertices.push_back(centerPoint_[1] + radius * glm::sin(angle)); // y
        vertices.push_back(0.0f);                                       // z
        vertices.push_back(color_[0]);
        vertices.push_back(color_[1]);
        vertices.push_back(color_[2]);
    }

    // Center vertex
    vertices.push_back(centerPoint_[0]);
    vertices.push_back(centerPoint_[1]);
    vertices.push_back(0.0f);
    vertices.push_back(color_[0]);
    vertices.push_back(color_[1]);
    vertices.push_back(color_[2]);

    // Indices: triangle fan around the center
    for (int i = 0; i <= res; i++) {
        indecies.push_back(i);
        if (i == res) {
            indecies.push_back(0);
        } else {
            indecies.push_back(i + 1);
        }
        indecies.push_back(res+1); // center
    }
}

void Circle::circleBind() {
    // Generates Vertex Array Object and binds it
    circleVAO.Bind();
    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1((vertices.data()), vertices.size() * sizeof(GLfloat));
    circleVBO = VBO1;
    // Generates Element Buffer Object and links it to indices
    EBO EBO1((indecies.data()), indecies.size() * sizeof(GLuint));
    circleEBO = EBO1;
}

void Circle::circleLink() {
    circleVAO.LinkAttrib(circleVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    circleVAO.LinkAttrib(circleVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Circle::circleUnbind() {
    // unbind the VBO, VAO, EBO
    circleVAO.Unbind();
    circleVBO.Unbind();
    circleEBO.Unbind();
}

void Circle::circleDraw() {
    // Bind and draw the circle
    circleVAO.Bind();
    glDrawElements(GL_TRIANGLES, indecies.size(), GL_UNSIGNED_INT, (void*)0);
}

void Circle::circleDelete() {
    circleVAO.Delete();
    circleVBO.Delete();
    circleEBO.Delete();
}

void Circle::circleInit() {
    // Bind the square's VAO, VBO, EBO
    circleBind();
    // Link the square
    circleLink();
    // Unbind the square's VAO, VBO, EBO
    circleUnbind();
}

/* Used in another game to use
    Add a Cube& cube to main class
    definition and to the initializer
void Circle::circleMovement() {
    static float speedx = 0.004f;
    static float speedy = 0.004f;

    float centerX = vertices[vertices.size() - 6];
    float centerY = vertices[vertices.size() - 5];

    // Point on the side of the ball facing its direction of travel
    float leadX = centerX + (speedx > 0 ? radius : -radius);
    float colliderCircle[2] = { leadX, centerY };

    // check for wall or cube collision
    bool hitWallX = (centerX + radius >= 0.675f && speedx > 0) ||
                    (centerX - radius <= -0.675f && speedx < 0);
    bool hitCubes = cube1.getCollision(colliderCircle);

    if (hitWallX || hitCubes)
        speedx = -speedx;

    // check for celling or floor collision
    if ((centerY + radius >= 0.675f && speedy > 0) || (centerY - radius <= -0.675f && speedy < 0))
        speedy = -speedy;

    // move the circle accordingly
    for (size_t i = 0; i < vertices.size(); i += 6) {
        vertices[i]     += speedx;
        vertices[i + 1] += speedy;
    }

    circleUpdate();
}
*/


void Circle::circleMMove() {
    static float speedy = 0.003f;

    for (int i = 0; i < vertices.size(); i += 6) {
        vertices[i+1] -= speedy;
    }

    circleUpdate();
}


void Circle::circleUpdate() {
    circleVBO.Bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(GLfloat), vertices.data());
    circleVBO.Unbind();
}


// Returns a bool to see if it collided with something
bool Circle::getCollision(GLfloat pointContact[2]) {
    float ex1 = vertices[vertices.size() - 6] - pointContact[0];
    float ex2 = vertices[vertices.size() - 5] - pointContact[1];
    return ((ex1 * ex1) + (ex2 * ex2)) < (radius*radius);

    //return vertices[vertices.size() - 6] - (radius - 0.01f)<= pointContact[0] &&
    //       vertices[vertices.size() - 6] + (radius - 0.01f)>= pointContact[0] &&
    //       vertices[vertices.size() - 5] - (radius - 0.01f)<= pointContact[1] &&
    //       vertices[vertices.size() - 5] + (radius - 0.01f)>= pointContact[1];
}

// Returns the y position of the circle to check if it can be deleted if it went out of the screen
GLfloat Circle::getPos() {
    return vertices[vertices.size() - 5];
}

std::vector<GLfloat> Circle::getCenter() {
    std::vector<GLfloat> center = {vertices[vertices.size() - 6], vertices[vertices.size() - 5]};
    return center;
}
