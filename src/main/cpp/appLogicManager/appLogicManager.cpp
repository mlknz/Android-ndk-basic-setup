#include "appLogicManager.h"
#include <sys/time.h>

#include "../gameObject/button.h"

float dx, dy = 0.f;

AppLogicManager::AppLogicManager(GameState* g, AssetManager* a, SceneManager* s) {
    this->gameState = g;
    this->assetManager = a;
    this->sceneManager = s;

    Button* startGameButton = new Button(this->gameState, this->assetManager);
    this->sceneManager->testButton = startGameButton;
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
    this->menuSceneActive = true;
    this->gameSceneActive = false;
}

void AppLogicManager::switchToGameScene() {
    this->menuSceneActive = false;
    this->gameSceneActive = true;
}

void AppLogicManager::update() {
    this->gameState->time = currentTimeInMilliseconds();


}

