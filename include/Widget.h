#ifndef WIDGET_H
#define WIDGET_H


#include "graphics.hpp"
#include "vector"
#include "string"
#include "window.h"
using namespace std;

class Widget
{
protected:
    int x, y;
    int meretX=100;
    int meretY=40;
    bool selected = false;
    virtual bool isOver(int *px, int *py)=0;
    std::vector<std::vector<int>> t;
public:
    Widget(int _x, int _y, std::vector<std::vector<int>> _t);
    virtual ~Widget() {}
    virtual bool focus(int *px, int *py);
    void unfocus()
    {
        selected=false;
    }
    virtual void draw()=0;
    virtual void eventHandler(genv::event ev)=0;
    virtual string getValue()=0;
};
#endif // WIDGET_H
