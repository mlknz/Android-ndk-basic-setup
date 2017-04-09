#include "appLogicManager.h"
#include <sys/time.h>

#include <math.h>
#include "../common.h"
float dx, dy = 0.f;
double t;

AppLogicManager::AppLogicManager(AssetManager* a) {
    this->assetManager = a;
    this->gameState = new GameState(); // todo: use singletone

    this->viewController = new ViewController();
}

AppLogicManager::~AppLogicManager() {
    this->gameState = nullptr;
    this->assetManager = nullptr;
    this->viewController = nullptr;
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

//        float ndcX = this->touchPosX / this->gameState->canvasWidth;
//        float ndcY = this->touchPosY / this->gameState->canvasHeight;
//
//        if (this->sceneManager->startGameButton->containsTouch(ndcX, ndcY)) {
//            this->switchToGameScene();
//        }
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

void AppLogicManager::update() {
    t = (double)currentTimeInMilliseconds();
    this->gameState->dt = (t - this->gameState->time) / 1000.0;
    this->gameState->time = t;

    this->viewController->activeView->update();
}


