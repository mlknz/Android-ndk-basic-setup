#ifndef __GameState__
#define __GameState__

#include <GLES2/gl2.h>

#include <map>
#include <string>

class GameState {
public:
    GameState() {};
    ~GameState() {};

    static GameState* local()
    {
        static GameState instance;
        return &instance;
    }

    GameState(GameState const&) = delete;
    void operator=(GameState const&) = delete;

    double time = -1;
    double dt;

    int canvasWidth = 1;
    int canvasHeight = 1;
    float aspectRatio = 1.f;
    float projectionMatrix[16] = {
            2.f / (float)canvasHeight, 0.f, 0.f, -1.f,
            0.f, 2.f / (float)canvasWidth, 0.f, -1.f,
            0.f, 0.f, -1.f, 0.f,
            0.f, 0.f, 0.f, 1.f
    };

    float wPosX = 0.0f;
    float wSpeedX = 0.3f;
    float gravity = -0.8f;

    std::map<std::string, GLuint> shaderPrograms;
};

#endif