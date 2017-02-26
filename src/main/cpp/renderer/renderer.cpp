#include "renderer.h"

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtc/matrix_transform.hpp"

#include "shaderProgram.h"
#include "../config.h"

Renderer::Renderer() {
    this->setClearColor(config::clearColor[0], config::clearColor[1], config::clearColor[2], config::clearColor[3]);
}

Renderer::~Renderer() { }

void Renderer::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::resize(int w, int h) {
    this->width = w;
    this->height = h;
}

GLuint Renderer::createShaderProgram(char* vertCode, char* fragCode) {
    GLuint vert = compileShader(GL_VERTEX_SHADER, vertCode);
    GLuint frag = compileShader(GL_FRAGMENT_SHADER, vertCode);

    GLuint program = linkShaderProgram(vert, frag);

    return program;
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);
}