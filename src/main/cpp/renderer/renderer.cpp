#include "renderer.h"

#include <GLES2/gl2.h>

#include "../config.h"

Renderer::Renderer() {
    this->setClearColor(0.8f, 0.5f, 0.9f, 0.0f);
}

Renderer::~Renderer() { }

void Renderer::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::resize(int w, int h) {
    this->width = w;
    this->height = h;
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);
}