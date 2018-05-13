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
    for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){

                string T;
                stringstream ss;
                ss << t[i-1][j-1];
                ss >> T;
                if(t[i-1][j-1]==0){gout << color(255,0,0) << move_to(x+(i*cellameret-30),y+(j*cellameret-20)) << text(T);}
                for(int c=1;c<10;c++){
                    for(int k=1;k<10;k++){
                            bool fu =true;
                        if(t[i-1][j-1]==t[c-1][j-1] && i-1!=c-1 && t[i-1][j-1]!=0){
                           gout << color(255,0,255) << move_to(x+(i*cellameret-30),y+(j*cellameret-20)) << text(T);
                            fu =false;
                        }
                        if(t[i-1][j-1]==t[i-1][k-1] && j-1!=k-1 && t[i-1][j-1]!=0){
                           gout << color(255,0,255) << move_to(x+(i*cellameret-30),y+(j*cellameret-20)) << text(T);
                           fu =false;
                        }
                        if(fu==true) {gout << color(60,255,6) << move_to(x+(i*cellameret-30),y+(j*cellameret-20)) << text(T);}

                    }
                }

               // if(t[i-1][j-1]!=0){gout << color(60,255,6) << move_to(x+(i*cellameret-30),y+(j*cellameret-20)) << text(T);}
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

                //leptet
                int V;
                int B;
                if(bv.pos_x<=50  && bv.pos_x>=0)  {V=1;}
                if(bv.pos_x<=100 && bv.pos_x>=50) {V=2;}
                if(bv.pos_x<=150 && bv.pos_x>=100){V=3;}
                if(bv.pos_x<=200 && bv.pos_x>=150){V=4;}
                if(bv.pos_x<=250 && bv.pos_x>=200){V=5;}
                if(bv.pos_x<=300 && bv.pos_x>=250){V=6;}
                if(bv.pos_x<=350 && bv.pos_x>=300){V=7;}
                if(bv.pos_x<=400 && bv.pos_x>=350){V=8;}
                if(bv.pos_x<=450 && bv.pos_x>=400){V=9;}

                if(bv.pos_y<=50  && bv.pos_y>=0)  {B=1;}
                if(bv.pos_y<=100 && bv.pos_y>=50) {B=2;}
                if(bv.pos_y<=150 && bv.pos_y>=100){B=3;}
                if(bv.pos_y<=200 && bv.pos_y>=150){B=4;}
                if(bv.pos_y<=250 && bv.pos_y>=200){B=5;}
                if(bv.pos_y<=300 && bv.pos_y>=250){B=6;}
                if(bv.pos_y<=350 && bv.pos_y>=300){B=7;}
                if(bv.pos_y<=400 && bv.pos_y>=350){B=8;}
                if(bv.pos_y<=450 && bv.pos_y>=400){B=9;}

                if(t[V-1][B-1]>=9){t[V-1][B-1]=0;}
                if(t[V-1][B-1]>(-1) && t[V-1][B-1]<=8){t[V-1][B-1]++;}

                cout << B << " " << V << endl;
        }

    }


}






string Grid::getValue(){};

bool Grid::isOver(int *px, int *py){
    if(*px < x || x + meretX < *px || *py < y || y + meretY < *py)
        return false;

    return true;

}
