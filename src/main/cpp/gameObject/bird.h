#ifndef __GameObject_Bird__
#define __GameObject_Bird__


#include "gameObject.h"
#include <string>

class Bird : public GameObject {
public:
    Bird(GameState* g, AssetManager* a);

    std::string type = "bird";

    void render();
    void resize();
    bool containsTouch(float touchX, float touchY){};
    void setPosition(float posX, float posY);

    float radius;
    float posX = 0.f;
    float posY = 0.f;
    float speedY = 0.f;

private:
    void createGLBuffers();
    void updateGLBuffers();
    void dispose() {};

    GLuint vertexBuffer;
    GLint posUniformLoc;
    GLint radiusUniformLoc;
    GLint aspectRatioUniformLoc;

    GLint projectionMactrixUniformLoc;
};
#endif