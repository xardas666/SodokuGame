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

}
}
void Grid::eventHandler(genv::event bv){};
string Grid::getValue(){};

bool Grid::isOver(int *px, int *py){};
