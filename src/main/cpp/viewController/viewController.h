#ifndef __View_Controller__
#define __View_Controller__

#include "./view.h"

class ViewController {
public:
    ViewController() {};
    ~ViewController() {};

    View* activeView;

    void resize(int w, int h) {};
};
#endif
