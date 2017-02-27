#include "button.h"
#include "../common.h"

Button::Button(GameState* g, AssetManager* a) : GameObject(g, a) {
    this->setShaderProgram(this->type);

    this->prepareGLBuffers();
}

void Button::prepareGLBuffers() {
    glGenBuffers(1, &this->vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

    float data[12] = {
            -0.5f, -0.5f,
            -0.5f, 0.5f,
            0.0f, 0.5f,
            0.0f, 0.5f,
            0.5f, 0.5f,
            0.5f, -0.5f
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void Button::render() {
    glUseProgram(this->shaderProgram);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
    glVertexAttribPointer(
            0,                  // attribute 0.
            2,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
}
