#ifndef __GameObject_Columns__
#define __GameObject_Columns__

#include "gameObject.h"
#include <string>

struct Column {
    Column() {
        x1 = 0.f;
        x2 = 0.f;
        y1 = 0.f;
        y2 = 0.f;
    }

    float x1;
    float x2;
    float y1;
    float y2;
};

class Columns : public GameObject {
public:
    Columns(GameState* g, AssetManager* a);

    std::string type = "columns";

    int columnsCount = 50;

    void render();
    void resize();
    bool containsTouch(float touchX, float touchY){};

    bool collidedByCircle(float x, float y, float r);
private:

    void initColumns();
    void createGLBuffers();
    void updateGLBuffers();
    void dispose() {};

    Column* columns;
    float columnWidth = 0.1f;

    GLuint vertexBuffer;
    GLint wPosXUniformLoc;
    GLint aspectRatioUniformLoc;
};
#endif