#ifndef __GameObject_Columns__
#define __GameObject_Columns__

#include "gameObject.h"
#include <string>

class Columns : public GameObject {
public:
    Columns(GameState* g, AssetManager* a);

    std::string type = "columns";

    void render();
    void resize();
    bool containsTouch(float touchX, float touchY){};

    float left;
    float right;
    float up;
    float down;

private:

    void createGLBuffers();
    void updateGLBuffers();
    void dispose() {};

    GLuint vertexBuffer;
    GLuint textureID;

    float centerX;
    float centerY;
    float width;
    float aspectRatio;
};
#endif