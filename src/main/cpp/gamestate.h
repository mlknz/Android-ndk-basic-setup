#ifndef __GameState__
#define __GameState__

class GameState {
public:
    GameState() {};
    ~GameState() {};

    double time = -1;
    double dt;

    int canvasWidth = -1;
    int canvasHeight = -1;
};

#endif