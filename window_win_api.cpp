//
// Created by studio25 on 19.05.2021.
//


#include "window_win_api.h"

void window_win_api::show_frame() {
    display_context->display_window();
}

void window_win_api::play(unsigned int time_between_frames) {

    int z = 0;
    while (true) {
        show_frame();
       //printf("frame : %d", z);
       // std::this_thread::sleep_for(std::chrono::milliseconds(time_between_frames));
        gen_frame();
        ++z;
    }
}
