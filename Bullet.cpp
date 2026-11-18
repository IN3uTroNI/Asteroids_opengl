//
// Created by neutron on 11/18/26.
//

#include "headers/Bullet.h"
#include "Spawner.h"

Bullet::Bullet(GLfloat posX, GLfloat posY, Spawner &spawner, int &score) : spawner(&spawner), score(&score) {
    GLfloat tempVert[24] = {
        posX - 0.000f, posY + 0.011f, 0.0f, 1.0f, 1.0f, 0.0f, // 0
        posX - 0.006f, posY - 0.011f, 0.0f, 1.0f, 1.0f, 0.0f, // 1
        posX + 0.006f, posY - 0.011f, 0.0f, 1.0f, 1.0f, 0.0f, // 2
    };
    for (int i = 0; i < 18; i++) {
        verticies[i] = tempVert[i];
    }
}

void Bullet::bulletBind() {
    // Generates Vertex Array Object and binds it
    bulletVAO.Bind();
    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(verticies, sizeof(verticies));
    bulletVBO = VBO1;
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indicies, sizeof(indicies));
    bulletEBO = EBO1;
}

void Bullet::bulletLink() {
    // Links VBO attributes such as coordinates and colors to VAO
    bulletVAO.LinkAttrib(bulletVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    bulletVAO.LinkAttrib(bulletVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Bullet::bulletUnbind() {
    // Unbinds VAO, VBO, EBO
    bulletVAO.Unbind();
    bulletVBO.Unbind();
    bulletEBO.Unbind();
}

void Bullet::bulletDraw() {
    // Bind the VAO so OpenGL knows to use it
    bulletVAO.Bind();
    // Draw primitives, number of indices, datatype of indices, index of indices
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void Bullet::bulletDelete() {
    // Delete's the square 'Cube'
    bulletVAO.Delete();
    bulletVBO.Delete();
    bulletEBO.Delete();
}

void Bullet::bulletInit() {
    // Bind the square's VAO, VBO, EBO
    bulletBind();
    // Link the square
    bulletLink();
    // Unbind the square's VAO, VBO, EBO
    bulletUnbind();
}

void Bullet::bulletUpdate() {
    bulletVBO.Bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verticies), verticies);
    bulletVBO.Unbind();
}

// Deals with updateing and moving the bullet
void Bullet::bulletMove() {
    static float speedY = 0.02f;
    for (int i = 0; i < 24; i+=6) {
        verticies[i+1] += speedY;
    }
    bulletUpdate();
}


bool Bullet::getCollision() {
    GLfloat position[2] = {
        verticies[0], verticies[1]
    };
    if (spawner->spawnerCollision(position)) {
        ++(*score);
        return true;
    }
    return false;
}

