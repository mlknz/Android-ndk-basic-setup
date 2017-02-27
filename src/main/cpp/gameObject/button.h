#ifndef __GameObject_Button__
#define __GameObject_Button__

#include "gameObject.h"
#include <string>

class Button : public GameObject {
public:
    Button(GameState* g, AssetManager* a,
           float centerX, float centerY, float width, float aspectRatio,
           std::string imagePath);

    std::string type = "button";

    void render();
    void resize();
    bool containsTouch(float touchX, float touchY);

    float left;
    float right;
    float up;
    float down;

private:

    void createGLBuffers();
    void updateGLBuffers();
    GLuint prepareGLTexture(int w, int h, uint8_t* data);
    void dispose() {};

    GLuint vertexBuffer;
    GLuint textureID;

    float centerX;
    float centerY;
    float width;
    float aspectRatio;

    bool useTexture = false;
};

#endif