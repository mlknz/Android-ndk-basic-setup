#ifndef __AppLogicManager__
#define __AppLogicManager__

#include "../gamestate.h"
#include "../assetManager/assetManager.h"
#include "../sceneManager/sceneManager.h"

class AppLogicManager {
public:
    AppLogicManager(GameState* g, AssetManager* a, SceneManager* s);
    ~AppLogicManager();

    void onTouchStart(float posX, float posY);
    void onTouchMove(float posX, float posY);
    void onTouchEnd(float posX, float posY);

    void update();

    void switchToMenuScene();
    void switchToGameScene();
private:
    GameState* gameState;
    AssetManager* assetManager;
    SceneManager* sceneManager;

    bool touchActive = false;
    float touchPosX = -1;
    float touchPosY = -1;
};

#endif
