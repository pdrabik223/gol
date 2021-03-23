// jzo_gr2_stac

#include <iostream>
#include <conio.h>
#include "console_win.h"


int main() {
    std::cout << "Hello, World!" <<std::endl;

    int x, y;

    x=5;y=5;
    board life(x, y);

    console_win game(&life);

int z=0;
    while (true) {

    game.show_frame();
    printf("frame : %d",z);
    getch();
    game.gen_frame();

    ++z;
    }



    return 0;
}
