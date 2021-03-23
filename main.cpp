// jzo_gr2_stac

#include <iostream>
#include <conio.h>
#include "console_win.h"


int main() {
    std::cout << "Hello, World!" <<std::endl;

    int x, y;
    //std::cin >> x >> y;
    x=5;y=5;
    board life(x, y);

    console_win game(&life);


    while (true) {

    game.show_frame();
    getch();
    game.gen_frame();

       }



    return 0;
}
