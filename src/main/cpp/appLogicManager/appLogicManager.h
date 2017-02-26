#ifndef __AppLogicManager__
#define __AppLogicManager__

#include "../gamestate.h"

class AppLogicManager {
public:
    AppLogicManager(GameState* g);
    ~AppLogicManager();

    void onTouchStart(float posX, float posY);
    void onTouchMove(float posX, float posY);
    void onTouchEnd(float posX, float posY);

    void update();
private:
    GameState* gameState;

    bool touchActive = false;
    float touchPosX = -1;
    float touchPosY = -1;
};

#endif
