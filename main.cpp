//

#include <iostream>
#include <conio.h>
#include "console_win.h"


int main() {

    int x, y;

    x = 7;
    y = 7;
    game_engine life(x, y);
    life.get_cell(2,3) = true;
    life.get_cell(3,4) = true;
    life.get_cell(4,4) = true;
    life.get_cell(4,3) = true;
    life.get_cell(4,2) = true;



    console_win game(&life);

    int z = 0;
    while (true) {

        game.show_frame();
        printf("frame : %d", z);
        _sleep(1000);
        game.gen_frame();

        ++z;

    }


}
