#ifndef __AppLogicManager__
#define __AppLogicManager__

#include "../gamestate.h"
#include "../assetManager/assetManager.h"

class AppLogicManager {
public:
    AppLogicManager(GameState* g, AssetManager* a);
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

    bool menuSceneActive = false;
    bool gameSceneActive = false;

    bool touchActive = false;
    float touchPosX = -1;
    float touchPosY = -1;
};

#endif
