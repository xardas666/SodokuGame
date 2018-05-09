#include "graphics.hpp"
using namespace genv;


int main()
{
    gout.open(400,400);
    gout <<text("hello szilvia!")<< refresh;
    event ev;
    while(gin >> ev) {
    }
    return 0;
}
