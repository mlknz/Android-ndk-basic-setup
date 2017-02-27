#ifndef __SceneManager__
#define __SceneManager__

#include "../gameObject/gameObject.h"

class SceneManager {
public:
    SceneManager() {};
    ~SceneManager() {};

    GameObject* startGameButton;

    GameObject* bird;
    GameObject* columns;
};
#endif
