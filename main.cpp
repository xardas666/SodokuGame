#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Widget.h"
#include "Counter.h"
#include "Grid.h"
#include "window.h"
#include "GameMaster.h"


using namespace std;
using namespace genv;
//460
const unsigned int MAX_X = 460;
const unsigned int MAX_Y = 460;

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
    vector<Widget*> tomb;

int no_of_cols = 9;
int no_of_rows = 9;
int initial_value = 0;

std::vector<std::vector<int>> matrix;
matrix.resize(no_of_rows, std::vector<int>(no_of_cols, initial_value));
ifstream myfile ("1.txt");
if (myfile.is_open()){
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){



        myfile >> matrix[i][j];
        cout << matrix[i][j];
    }
    cout << endl;
}}

    tomb.push_back(new Grid(5,5,matrix));
  //  tomb.push_back(new GameMaster(5,5,matrixx));
    gout.open(MAX_X, MAX_Y);
    eventLoop(tomb);

    for(Widget *w : tomb)
        delete w;

    return 0;
}
