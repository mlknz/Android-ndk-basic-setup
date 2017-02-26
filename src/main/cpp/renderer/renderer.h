#ifndef __AppRenderer__
#define __AppRenderer__

#include <GLES2/gl2.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    GLuint createShaderProgram(char* vertCode, char* fragCode);

    void setClearColor(float r, float g, float b, float a);
    void resize(int w, int h);
    void render();
private:
    int width;
    int height;
};

#endif