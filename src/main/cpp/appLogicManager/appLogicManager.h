#ifndef __AppLogicManager__
#define __AppLogicManager__

#include "../gamestate.h"
#include "../assetManager/assetManager.h"
#include "../viewController/viewController.h"

class AppLogicManager {
public:
    AppLogicManager(AssetManager* a);
    ~AppLogicManager();

    void onTouchStart(float posX, float posY);
    void onTouchMove(float posX, float posY);
    void onTouchEnd(float posX, float posY);

    void update();

    GameState* gameState;
    ViewController* viewController;
private:

    AssetManager* assetManager;

    bool touchActive = false;
    float touchPosX = -1;
    float touchPosY = -1;
};

#endif
