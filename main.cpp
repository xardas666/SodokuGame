#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Widget.h"
#include "Counter.h"

using namespace std;
using namespace genv;

const unsigned int MAX_X = 400;
const unsigned int MAX_Y = 400;

int eventLoop(vector<Widget*> & tomb)
{
    Widget * focused = NULL;
    event ev;
    while(gin >> ev)
    {
        if(ev.type == ev_key)
        {
            if(ev.keycode==key_enter)
            {



                ofstream myfile;
                myfile.open ("data.txt");
                for(unsigned int i=0; tomb.size() > i; i++)
                {
                    myfile << tomb[i]->getValue()<< " | ";

                }
                myfile.close();
            }
            if(ev.keycode == key_escape)
                return 0;
        }
        else if(ev.type == ev_mouse)
        {
            if(ev.button == btn_left)
            {
                if(focused != NULL)
                {
                    focused->unfocus();
                    focused=NULL;
                }
                for(int i=tomb.size()-1; i>=0; --i)
                {
                    if(tomb[i]->focus(&ev.pos_x, &ev.pos_y))
                    {
                        focused = tomb[i];
                        break;
                    }
                }
            }
        }
        if(focused != NULL)
        {
            focused->eventHandler(ev);
        }
        gout << color(0,0,0) << move_to(0,0) << box(MAX_X, MAX_Y);
        for(Widget * w : tomb)
            w->draw();
        gout << refresh;
    }
    return 0;
}


int main()
{
    vector<string> l;


    vector<Widget*> tomb;

    tomb.push_back(new Counter(50,150,l));


    gout.open(MAX_X, MAX_Y);

    eventLoop(tomb);

    for(Widget *w : tomb)
        delete w;

    return 0;
}
