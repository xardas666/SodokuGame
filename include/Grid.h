#ifndef GRID_H
#define GRID_H

#include "sstream"
#include "graphics.hpp"
#include "Widget.h"
#include "string"

class Grid : public Widget
{
    bool _checked = false;
    int value=0;
public:
    Grid(int _x, int _y, std::vector<std::string> _t) : Widget(_x,_y,_t) {}
    void draw();
    void eventHandler(genv::event bv);
    string getValue();
protected:
    bool isOver(int *px, int *py);
};

#endif // GRID_H
