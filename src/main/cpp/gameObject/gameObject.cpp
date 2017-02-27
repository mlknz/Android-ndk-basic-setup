#include "gameObject.h"

#include "../common.h"
#include "../renderer/shaderProgram.h"

GameObject::GameObject(GameState* g, AssetManager* a) {
    this->gameState = g;
    this->assetManager = a;
}

GameObject::~GameObject() {
    this->dispose();
    this->gameState = nullptr;
    this->assetManager = nullptr;
}

void GameObject::setShaderProgram(std::string type) {
    auto it = this->gameState->shaderPrograms.find(type);

    if (it != this->gameState->shaderPrograms.end()) { // program is present
        this->shaderProgram = it->second;
    } else {
        this->shaderProgram = this->createShaderProgram(type);
        this->gameState->shaderPrograms[type] = this->shaderProgram;
    }
}

GLuint GameObject::createShaderProgram(std::string type) {
    std::string vertFileName = std::string("shaders/") + type + std::string(".vert");
    std::string fragFileName = std::string("shaders/") + type + std::string(".frag");

    char* vertCode = this->assetManager->loadFile(vertFileName);
    char* fragCode = this->assetManager->loadFile(fragFileName);

    GLuint vert = compileShader(GL_VERTEX_SHADER, vertCode);
    GLuint frag = compileShader(GL_FRAGMENT_SHADER, fragCode);

    GLuint program = linkShaderProgram(vert, frag);

    delete [] vertCode;
    delete [] fragCode;

    return program;
}