#ifndef COUNTER_H
#define COUNTER_H
#include "sstream"
#include "graphics.hpp"
#include "Widget.h"
#include "string"

class Counter : public Widget
{
    bool _checked = false;
    int value=0;
public:
    Counter(int _x, int _y, std::vector<std::vector<int>> _t) : Widget(_x,_y,_t) {}
    void draw();
    void eventHandler(genv::event bv);
    string getValue();
protected:
    bool isOver(int *px, int *py);
};


#endif // COUNTER_H
