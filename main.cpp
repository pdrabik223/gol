// jzo_gr2_stac

#include <iostream>
#include <conio.h>
#include "console_win.h"


int main() {
    std::cout << "Hello, World!" <<std::endl;

    int x, y;

    x=5;y=5;
    board life(x, y);
    life[7] = true;
    life[13] = true;
    life[16] = true;
    life[17] = true;
    life[18] = true;
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
