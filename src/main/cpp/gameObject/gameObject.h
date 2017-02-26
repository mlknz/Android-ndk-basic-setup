#ifndef __GameObject__
#define __GameObject__

#include <string>
#include <GLES2/gl2.h>

#include "../gamestate.h"

// abstract class
class GameObject {
public:
    GameObject(GameState* g);
    ~GameObject();

    virtual void tmpMakeAbstract() = 0;
    std::string type = "gameObject";

    GLuint shaderProgram;
    int zIndex = 0;

private:
    GLuint createShaderProgram(std::string type);
    virtual void dispose() {};
    GameState* gameState;
};

#endif