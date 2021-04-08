//
// Created by studio25 on 08.04.2021.
//

#include "console_win.h"

void console_win::show_frame() {
    system("cls");
    for (int i = 0; i < life->get_height(); i++) {
        for (int j = 0; j < life->get_width(); j++) {

            if(life->get_cell(i,j)) printf("# ");
            else printf(". ");

        }
        printf("\n");
    }
}
