#ifndef __SceneManager__
#define __SceneManager__

#include "../gameObject/gameObject.h"
#include "../gameObject/bird.h"
#include "../gameObject/columns.h"

class SceneManager {
public:
    SceneManager() {};
    ~SceneManager() {};

    GameObject* startGameButton;

    Bird* bird;
    Columns* columns;
};
#endif
