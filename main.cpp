// jzo_gr2_stac

#include <iostream>
#include "console_win.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    int x, y;
    std::cin >> x >> y;
    board life(x, y);

    console_win game(&life);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {

    game.show_frame();
    game.gen_frame();

       }
#pragma clang diagnostic pop


    return 0;
}
