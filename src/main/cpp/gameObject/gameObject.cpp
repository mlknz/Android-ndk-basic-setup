#include "gameObject.h"

#include "../renderer/shaderProgram.h"

GameObject::GameObject(GameState* g, AssetManager* assetManager) {
    m_gameState = GameState::local();
    m_assetManager = assetManager;
}

GameObject::~GameObject() {
    dispose();
    m_gameState = nullptr;
    m_assetManager = nullptr;
}

void GameObject::setShaderProgram(std::string type) {
    auto it = m_gameState->shaderPrograms.find(type);

    if (it != m_gameState->shaderPrograms.end()) { // program is present
        this->shaderProgram = it->second;
    } else {
        this->shaderProgram = this->createShaderProgram(type);
        m_gameState->shaderPrograms[type] = this->shaderProgram;
    }
}

GLuint GameObject::createShaderProgram(std::string type) {
    std::string vertFileName = std::string("shaders/") + type + std::string(".vert");
    std::string fragFileName = std::string("shaders/") + type + std::string(".frag");

    char* vertCode = m_assetManager->loadFile(vertFileName);
    char* fragCode = m_assetManager->loadFile(fragFileName);

    GLuint vert = compileShader(GL_VERTEX_SHADER, vertCode);
    GLuint frag = compileShader(GL_FRAGMENT_SHADER, fragCode);

    GLuint program = linkShaderProgram(vert, frag);

    delete [] vertCode;
    delete [] fragCode;

    return program;
}