#include "Counter.h"
#include "graphics.hpp"
#include "iostream"
#include "sstream"
#include "string"
#include "cstdlib"
#include <stdio.h>
using namespace genv;
using namespace std;

void Counter::draw()
{
    string vText;
    stringstream sz;
    sz << value;
    sz >> vText;
    if(selected)
    {
        gout << color(0,250,0) << move_to(x,y) << box(meretX,meretY);
        gout << color(0,25,250) << move_to(x,y) << box(meretX/5,meretY);
        gout << color(0,25,250) << move_to(((meretX/5)*4)+x,y) << box(meretX/5,meretY);
        gout << color(255,255,250) << move_to(x+5,(y+meretY/2)+5) << text("-");
        gout << color(255,255,250) << move_to(((meretX/5)*4)+x+5,(y+meretY/2)+5) << text("+");
        gout << color(255,0,0)<<  move_to(x+meretX/2,y+meretY/2)<<text(vText);
    }
    else
    {
        gout << color(0,255,250) << move_to(x,y) << box(meretX,meretY);
        gout << color(0,25,250) << move_to(x,y) << box(meretX/5,meretY);
        gout << color(0,25,250) << move_to(((meretX/5)*4)+x,y) << box(meretX/5,meretY);
        gout << color(255,255,250) << move_to(x+5,(y+meretY/2)+5) << text("-");
        gout << color(255,255,250) << move_to(((meretX/5)*4)+x+5,(y+meretY/2)+5) << text("+");
        gout << color(255,0,0)<<  move_to(x+meretX/2,y+meretY/2)<<text(vText);
    }
}

void Counter::eventHandler(event bv)
{
    if(bv.type == ev_mouse)
    {
        if(bv.button == btn_left)
        {
            if (isOver(&bv.pos_x, &bv.pos_y))
                _checked = ! _checked;
        }
        if((((meretX/5))+x)>=bv.pos_x && (meretY+y)>=bv.pos_y && x <=bv.pos_x && y <=bv.pos_y && bv.button==btn_left  )
            //csökkent
        {
            string vText;
            stringstream sz;
            value--;
            sz << value;
            sz >> vText;
        }
        if(((((meretX/5)*4))+x)<=bv.pos_x && (meretY+y)>=bv.pos_y && x+meretX >=bv.pos_x && y <=bv.pos_y && bv.button==btn_left )
            //növel
        {
            string vText;
            stringstream sz;
            value++;
            sz << value;
            sz >> vText;
        }
    }
    if(bv.type==ev_key)
    {
        if(bv.keycode==key_pgdn)
        {
            string vText;
            stringstream sz;
            value--;
            sz << value;
            sz >> vText;
        }
        if(bv.keycode==key_pgup)
        {
            string vText;
            stringstream sz;
            value++;
            sz << value;
            sz >> vText;
        }
    }
}
bool Counter::isOver(int *px, int *py)
{
    if(*px < x || x + meretX < *px || *py < y || y + meretY < *py)
        return false;

    return true;
}
string Counter::getValue()
{
    string T;
    stringstream ss;
    ss << value;
    ss >> T;
    return T;
}
