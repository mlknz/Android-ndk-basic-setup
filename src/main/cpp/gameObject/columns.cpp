#include "columns.h"

#include "../common.h"

Columns::Columns(GameState* g, AssetManager* a) : GameObject(g, a) {

    this->setShaderProgram(this->type);

    this->createGLBuffers();

    this->resize();

    this->initColumns();

    this->updateGLBuffers();

    this->wPosXUniformLoc = glGetUniformLocation(this->shaderProgram, "wPosX");
    this->aspectRatioUniformLoc = glGetUniformLocation(this->shaderProgram, "aspectRatio");
}

void Columns::initColumns() {
    this->columns = new Column[this->columnsCount];
    for (int i = 0; i < this->columnsCount; i += 2) {
        this->columns[i].x = float(i) / 5.f;
        this->columns[i].y1 = 0.5f;
        this->columns[i].y2 = 1.0f;

        this->columns[i + 1].x = float(i) / 5.f;
        this->columns[i + 1].y1 = -1.f;
        this->columns[i + 1].y2 = -0.5f;

    }
}

void Columns::resize() {
}

void Columns::createGLBuffers() {
    glGenBuffers(1, &this->vertexBuffer);
}

void Columns::updateGLBuffers() {
    // glDeleteBuffers(1, &VertexVBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

    float data[12 * this->columnsCount];

    float left, right, up, down;
    int j;

    for (int i = 0; i < this->columnsCount; i++) {
        j = i*12;

        left = this->columns[i].x;
        right = left + this->columnWidth;
        down = this->columns[i].y1;
        up = this->columns[i].y2;

        data[j] = left; data[j + 1] = down;
        data[j + 2] = left; data[j + 3] = up;
        data[j + 4] = right; data[j + 5] = up;
        data[j + 6] = right; data[j + 7] = up;
        data[j + 8] = right; data[j + 9] = down;
        data[j + 10] = left; data[j + 11] = down;
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

bool Columns::collidedByCircle(float x, float y, float r) {
    return false;
}

void Columns::render() {
    glUseProgram(this->shaderProgram);

    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,                  // attribute 0.
            2,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );

    glUniform1f(this->wPosXUniformLoc, this->gameState->wPosX);
    glUniform1f(this->aspectRatioUniformLoc, this->gameState->aspectRatio);

    glDrawArrays(GL_TRIANGLES, 0, this->columnsCount * 6);
    glDisableVertexAttribArray(0);
}