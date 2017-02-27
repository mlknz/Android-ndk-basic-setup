#ifndef __GameObject_Button__
#define __GameObject_Button__

#include "gameObject.h"

class Button : public GameObject {
public:
    Button(GameState* g, AssetManager* a);

    std::string type = "button";

    void prepareGLBuffers();
    void render();

private:
    GLuint vertexBuffer;
    void dispose() {};
};

#endif