#include "renderer.h"

#include "../glm/glm.hpp" // todo: clean up libs linking mess
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtc/matrix_transform.hpp"

#include "../config.h"

Renderer::Renderer(GameState* g, SceneManager* s) {
    this->gameState = g;
    this->sceneManager = s;
    this->setClearColor(config::clearColor[0], config::clearColor[1], config::clearColor[2], config::clearColor[3]);
}

Renderer::~Renderer() {
    this->gameState = nullptr;
    this->sceneManager = nullptr;
}

void Renderer::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::resize(int w, int h) {
    this->gameState->canvasWidth = w;
    this->gameState->canvasHeight = h;
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    this->sceneManager->testButton->render();
}