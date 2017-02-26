#ifndef __AppRenderer__
#define __AppRenderer__

class Renderer {
public:
    Renderer();
    ~Renderer();

    void setClearColor(float r, float g, float b, float a);
    void resize(int w, int h);
    void render();
private:
    int width;
    int height;
};

#endif