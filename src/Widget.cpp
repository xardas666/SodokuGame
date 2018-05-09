#include "Widget.h"

#include <iostream>

using namespace std;

Widget::Widget(int _x, int _y, std::vector<std::string> _t):x(_x),y(_y), t(_t) {}

bool Widget::focus(int *px, int *py)
{
    selected = isOver(px, py);
    return selected;
}

