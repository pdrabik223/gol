//
// Created by studio25 on 08.04.2021.
//

#include <thread>
#include "console_win.h"

void console_win::show_frame() {

    for (int i = 0; i < life->get_height(); i++) {
        for (int j = 0; j < life->get_width(); j++) {

            if (life->get_cell(i, j)) printf("# ");
            else printf(". ");

        }
        printf("\n");
    }
}

void console_win::play(unsigned int time_between_frames /* by default 1000*/) {
    int z = 0;
    while (true) {
        system("cls");
        show_frame();
        printf("frame : %d", z);
        std::this_thread::sleep_for(std::chrono::milliseconds(time_between_frames));
        gen_frame();
        ++z;
    }
}
