#ifndef __AppLogicManager__
#define __AppLogicManager__

#include "../gamestate.h"

class AppLogicManager {
public:
    AppLogicManager(GameState* g);
    ~AppLogicManager();

    void update();
private:
    GameState* gameState;
};

#endif
