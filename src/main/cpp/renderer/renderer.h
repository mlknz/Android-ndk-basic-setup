#ifndef __AppRenderer__
#define __AppRenderer__

#include <GLES2/gl2.h>

#include "../gamestate.h"

class Renderer {
public:
    Renderer(GameState* g);
    ~Renderer();

    GLuint createShaderProgram(char* vertCode, char* fragCode);

    void setClearColor(float r, float g, float b, float a);
    void resize(int w, int h);
    void render();
private:
    GameState* gameState;
};

#endif