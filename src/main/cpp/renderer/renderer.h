#ifndef __AppRenderer__
#define __AppRenderer__

#include <GLES2/gl2.h>

#include "../gamestate.h"
#include "../sceneManager/sceneManager.h"

class Renderer {
public:
    Renderer(GameState* g, SceneManager* s);
    ~Renderer();

    void setClearColor(float r, float g, float b, float a);
    void resize(int w, int h);
    void render();
private:
    GameState* gameState;
    SceneManager* sceneManager;
};

#endif