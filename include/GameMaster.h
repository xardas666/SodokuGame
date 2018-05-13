#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include "Widget.h"
#include <iostream>
#include <vector>

class GameMaster : public Widget
{


public:
    GameMaster(int _x, int _y, std::vector<std::vector<int>> _t) : Widget(_x,_y,_t) {}
    void draw();
    void eventHandler(genv::event bv);
    string getValue();
protected:
    bool isOver(int *px, int *py);
};

#endif // GAMEMASTER_H
