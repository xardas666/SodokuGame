#include "Grid.h"
#include "graphics.hpp"
#include "iostream"
#include "sstream"
#include "string"
#include "cstdlib"
#include <stdio.h>
using namespace genv;
using namespace std;

void Grid::draw()
{
//9*9es tábla
int cellameret=50;
meretX=450;
meretY=450;
int r,g,b;
for(int i=0; i<10;i++){
        if(i==0 || i==3 || i==6 || i==9){r=250 ; g=0; b=250;}
        else {r=0; g=250; b=0;}
    gout << color(r,g,b) << move_to(x+(i*cellameret),y) << line_to(x+(i*cellameret),y+meretY);
    gout << color(r,g,b) << move_to(x,y+(i*cellameret)) << line_to(x+meretX,y+(i*cellameret));
    for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                string T;
                stringstream ss;
                ss << i;
                ss >> T;
                gout << color(60,255,6) << move_to(x+(i*cellameret-30),y+(j*cellameret-20)) << text(T);
            }
    }
}
}


void Grid::eventHandler(genv::event bv){
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






string Grid::getValue(){};

bool Grid::isOver(int *px, int *py){
    if(*px < x || x + meretX < *px || *py < y || y + meretY < *py)
        return false;

    return true;

}
