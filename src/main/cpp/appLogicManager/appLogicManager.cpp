#include "appLogicManager.h"
#include <sys/time.h>

AppLogicManager::AppLogicManager(GameState* g) {
    this->gameState = g;
}

AppLogicManager::~AppLogicManager() {}

long long currentTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void AppLogicManager::update() {
    this->gameState->time = currentTimeInMilliseconds();
}