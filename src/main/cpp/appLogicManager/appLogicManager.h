#ifndef __AppLogicManager__
#define __AppLogicManager__

#include <memory>
#include "../gamestate.h"
#include "../assetManager/assetManager.h"
#include "../viewController/viewController.h"

class AppLogicManager {
public:
    AppLogicManager(AssetManager* a);
    ~AppLogicManager();

    ViewController* getViewController();

    void onTouchStart(float posX, float posY);
    void onTouchMove(float posX, float posY);
    void onTouchEnd(float posX, float posY);

    void update();

private:
    GameState* m_gameState;
    AssetManager* m_assetManager;
    std::unique_ptr<ViewController> m_viewController;

    bool m_touchActive = false;
    float m_touchPosX = -1;
    float m_touchPosY = -1;
};

#endif
