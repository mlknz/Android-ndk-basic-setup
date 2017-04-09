#ifndef __AppRenderer__
#define __AppRenderer__

#include <GLES2/gl2.h>

#include "../viewController/viewController.h"

class Renderer {
public:
    Renderer(ViewController* v);
    ~Renderer();

    void setClearColor(float r, float g, float b, float a);
    void resize(int w, int h);
    void render();
private:
    ViewController* viewController;
};

#endif