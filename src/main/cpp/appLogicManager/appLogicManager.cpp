#include "appLogicManager.h"
#include <sys/time.h>

#include <math.h>
#include "../common.h"
#include "../gameObject/button.h"
#include "../gameObject/bird.h"
#include "../gameObject/columns.h"

float dx, dy = 0.f;
double t;

AppLogicManager::AppLogicManager(GameState* g, AssetManager* a, SceneManager* s) {
    this->gameState = g;
    this->assetManager = a;
    this->sceneManager = s;

    this->sceneManager->startGameButton = new Button(this->gameState, this->assetManager, 0.0f, 0.0f, 0.7f, 0.5f, "textures/playButton.png");
    this->sceneManager->bird = new Bird(this->gameState, this->assetManager);
    this->sceneManager->columns = new Columns(this->gameState, this->assetManager);
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
            this->switchToGameScene();
        }
    } else if (this->gameState->gameSceneActive) {
        this->sceneManager->bird->speedY = 0.5f;
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
    this->gameState->wPosX = 0.f;

    this->sceneManager->bird->setPosition(-0.5f, 0.0f);
    this->sceneManager->bird->speedY = 0.0f;
    this->gameState->menuSceneActive = false;
    this->gameState->gameSceneActive = true;
}

void AppLogicManager::update() {
    t = (double)currentTimeInMilliseconds();
    this->gameState->dt = (t - this->gameState->time) / 1000.0;
    this->gameState->time = t;

    if (this->gameState->menuSceneActive) {

    } else if (this->gameState->gameSceneActive) {
        this->gameState->wPosX += this->gameState->wSpeedX * this->gameState->dt;

        this->sceneManager->bird->posY += this->sceneManager->bird->speedY * this->gameState->dt;
        this->sceneManager->bird->speedY += this->gameState->gravity * this->gameState->dt;

        this->checkWinLose();
    }
}

void AppLogicManager::checkWinLose() {
    bool lose = false;
    if (this->sceneManager->bird->posY > 1.0 || this->sceneManager->bird->posY < -1.0) lose = true;

    if (this->sceneManager->columns->collidedByCircle(
            this->sceneManager->bird->posX + this->gameState->wPosX,
            this->sceneManager->bird->posY,
            this->sceneManager->bird->radius
    )) lose = true;

    if (lose) {
        this->switchToMenuScene();
    }
}

