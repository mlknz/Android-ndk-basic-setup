#include "button.h"

Button::Button(GameState* g, AssetManager* a,
               float centerX, float centerY, float width, float aspectRatio,
               std::string imagePath) : GameObject(g, a) {
    this->centerX = centerX;
    this->centerY = centerY;
    this->width = width;
    this->aspectRatio = aspectRatio;

    // todo: use screen width / height and handle resize
    this->left = this->centerX - this->width / 2.f;
    this->right = this->centerX + this->width / 2.f;
    this->down = this->centerY - this->width * this->aspectRatio / 2.f;
    this->up = this->centerY + this->width * this->aspectRatio / 2.f;

    this->setShaderProgram(this->type);

    this->prepareGLBuffers();

    this->useTexture = imagePath.size() > 0;
    if (this->useTexture) {
        ImageData* image = this->assetManager->loadPNGImage(imagePath);
        this->textureID = this->prepareGLTexture(image->img_width, image->img_height, image->pixels);
    }
}

void Button::prepareGLBuffers() {
    glGenBuffers(1, &this->vertexBuffer); // glDeleteBuffers(1, &VertexVBO);
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

GLuint Button::prepareGLTexture(int w, int h, uint8_t* data) {
    GLuint textureID;
    glGenTextures(1, &textureID);

    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    return textureID;
}

void Button::render() {
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

    GLint texLoc = glGetUniformLocation(this->shaderProgram, "map");
    glUniform1i(texLoc, 0); // Texture unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
