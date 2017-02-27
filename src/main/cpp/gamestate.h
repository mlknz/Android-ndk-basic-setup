#ifndef __GameState__
#define __GameState__

#include <GLES2/gl2.h>

#include <map>
#include <string>

class GameState {
public:
    GameState() {};
    ~GameState() {};

    double time = -1;
    double dt;

    int canvasWidth = 1;
    int canvasHeight = 1;
    float aspectRatio = 1.f;

    std::map<std::string, GLuint> shaderPrograms;
};

#endif