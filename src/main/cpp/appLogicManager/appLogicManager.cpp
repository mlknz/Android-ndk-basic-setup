#include "appLogicManager.h"
#include <sys/time.h>

#include <math.h>
#include "../common.h"
float dx, dy = 0.f;
double t;

AppLogicManager::AppLogicManager(AssetManager* assetManager) {
    m_assetManager = assetManager;
    m_viewController = std::make_unique<ViewController>(); // todo: viewController loads all needed assets on view change if needed
    m_gameState = GameState::local();
}

AppLogicManager::~AppLogicManager() {
    m_gameState = nullptr;
    m_assetManager = nullptr;
    m_viewController = nullptr;
}

ViewController* AppLogicManager::getViewController() {
    return m_viewController.get();
}

long long currentTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void AppLogicManager::onTouchStart(float posX, float posY) {
    m_touchPosX = posX;
    m_touchPosY = posY;

    m_touchActive = true;

    float ndcX = m_touchPosX / m_gameState->canvasWidth;
    float ndcY = m_touchPosY / m_gameState->canvasHeight;

//        if (this->sceneManager->startGameButton->containsTouch(ndcX, ndcY))
//            this->switchToGameScene();
}

void AppLogicManager::onTouchMove(float posX, float posY) {
    dx = posX - m_touchPosX;
    dy = posY - m_touchPosY;
    m_touchPosX = posX;
    m_touchPosY = posY;
}

void AppLogicManager::onTouchEnd(float posX, float posY) {
    m_touchActive = false;
}

void AppLogicManager::update() {
    t = (double)currentTimeInMilliseconds();
    m_gameState->dt = (t - m_gameState->time) / 1000.0;
    m_gameState->time = t;

    m_viewController->activeView->update();
}


