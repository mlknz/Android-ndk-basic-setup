#include "appLogicManager.h"
#include <sys/time.h>

#include "../common.h"
#include "../gameObject/button.h"

float dx, dy = 0.f;

AppLogicManager::AppLogicManager(GameState* g, AssetManager* a, SceneManager* s) {
    this->gameState = g;
    this->assetManager = a;
    this->sceneManager = s;

    Button* startGameButton = new Button(this->gameState, this->assetManager, 0.0f, 0.0f, 0.7f, 0.5f, "textures/testImage.png");
    this->sceneManager->startGameButton = startGameButton;
}

AppLogicManager::~AppLogicManager() {
    this->gameState = nullptr;
    this->assetManager = nullptr;
    this->sceneManager = nullptr;
}

long long currentTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void AppLogicManager::onTouchStart(float posX, float posY) {
    this->touchPosX = posX;
    this->touchPosY = posY;

    this->touchActive = true;

    if (this->gameState->menuSceneActive) {
        float ndcX = this->touchPosX / this->gameState->canvasWidth;
        float ndcY = this->touchPosY / this->gameState->canvasHeight;

        if (this->sceneManager->startGameButton->containsTouch(ndcX, ndcY)) {
            LOGI("change scene");
            this->switchToGameScene();
        }
    }
}

void AppLogicManager::onTouchMove(float posX, float posY) {
    dx = posX - this->touchPosX;
    dy = posY - this->touchPosY;
    this->touchPosX = posX;
    this->touchPosY = posY;
}

void AppLogicManager::onTouchEnd(float posX, float posY) {
    this->touchActive = false;
}

void AppLogicManager::switchToMenuScene() {
    this->gameState->menuSceneActive = true;
    this->gameState->gameSceneActive = false;
}

void AppLogicManager::switchToGameScene() {
    this->gameState->menuSceneActive = false;
    this->gameState->gameSceneActive = true;
}

void AppLogicManager::update() {
    this->gameState->time = currentTimeInMilliseconds();
    if (this->gameState->menuSceneActive) {

    } else if (this->gameState->gameSceneActive) {

    }


}

