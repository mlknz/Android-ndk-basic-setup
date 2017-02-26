#include "gameObject.h"

#include <map>

GameObject::GameObject(GameState* g) {
    this->gameState = g;
    auto it = this->gameState->shaderPrograms.find(this->type);

    if (it != this->gameState->shaderPrograms.end()) { // program is present
        this->shaderProgram = it->second;
    } else {
        this->shaderProgram = this->createShaderProgram(this->type);
        this->gameState->shaderPrograms[this->type] = this->shaderProgram;
    }
}

GameObject::~GameObject() {
    this->dispose();
    this->gameState = nullptr;
}

GLuint GameObject::createShaderProgram(std::string type) {
    return 0;
}