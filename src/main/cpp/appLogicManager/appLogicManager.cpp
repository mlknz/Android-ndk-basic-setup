#include "appLogicManager.h"
#include <sys/time.h>

float dx, dy = 0.f;

AppLogicManager::AppLogicManager(GameState* g) {
    this->gameState = g;
}

AppLogicManager::~AppLogicManager() {
    this->gameState = nullptr;
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

void AppLogicManager::update() {
    this->gameState->time = currentTimeInMilliseconds();
}