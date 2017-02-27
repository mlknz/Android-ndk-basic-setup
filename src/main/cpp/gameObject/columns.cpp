#include "columns.h"

#include "../common.h"

Columns::Columns(GameState* g, AssetManager* a) : GameObject(g, a) {
    this->centerX = centerX;
    this->centerY = centerY;
    this->width = width;
    this->aspectRatio = aspectRatio;

    this->setShaderProgram(this->type);

    this->createGLBuffers();

    this->resize();
}

void Columns::resize() {
    this->left = this->centerX - this->width / 2.f;
    this->right = this->centerX + this->width / 2.f;
    this->down = this->centerY - this->width * this->aspectRatio * this->gameState->aspectRatio / 2.f;
    this->up = this->centerY + this->width * this->aspectRatio * this->gameState->aspectRatio / 2.f;

    this->updateGLBuffers();
}

void Columns::createGLBuffers() {
    glGenBuffers(1, &this->vertexBuffer);
}

void Columns::updateGLBuffers() {
    // glDeleteBuffers(1, &VertexVBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

    float data[24] = {
            this->left, this->down, // pos
            this->left, this->up,
            this->right, this->up,
            this->right, this->up,
            this->right, this->down,
            this->left, this->down,
            0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // uvs
            1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void Columns::render() {
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

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}