#include "bird.h"

#include "../common.h"

Bird::Bird(GameState* g, AssetManager* a) : GameObject(g, a) {
    this->setShaderProgram(this->type);

    this->createGLBuffers();

    this->resize();

    this->updateGLBuffers();

    this->posUniformLoc = glGetUniformLocation(this->shaderProgram, "pos");
    this->radiusUniformLoc = glGetUniformLocation(this->shaderProgram, "radius");
    this->aspectRatioUniformLoc = glGetUniformLocation(this->shaderProgram, "aspectRatio");

    this->radius = 0.3f;
}

void Bird::resize() {
    // glUniform1f(this->aspectRatioUniformLoc, this->gameState->aspectRatio);
}

void Bird::setPosition(float posX, float posY) {
    this->posX = posX;
    this->posY = posY;
}

void Bird::createGLBuffers() {
    glGenBuffers(1, &this->vertexBuffer);
}

void Bird::updateGLBuffers() {
    // glDeleteBuffers(1, &VertexVBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

    float data[24] = {
            0.f, 0.f, // pos
            0.f, 1.f,
            1.f, 1.f,
            1.f, 1.f,
            1.f, 0.f,
            0.f, 0.f,
            0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // uvs
            1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void Bird::render() {
    glUseProgram(this->shaderProgram);

    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
            0,                  // attribute 0.
            2,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );

    glVertexAttribPointer(
            1,                  // attribute 1.
            2,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)(12 * 4)          // array buffer offset
    );

    glUniform2f(this->posUniformLoc, this->posX, this->posY);
    glUniform1f(this->radiusUniformLoc, this->radius); // todo: cut extra calls
    glUniform1f(this->aspectRatioUniformLoc, this->gameState->aspectRatio);

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
