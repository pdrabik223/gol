//
// Created by studio25 on 18.03.2021.
//

#ifndef GOL_CONSOLE_WIN_H
#define GOL_CONSOLE_WIN_H
#include <iostream>
#include "engine_traits.h"
#include "board.h"

class console_win : public engine_traits {

public:
    console_win() = delete;
    console_win( board *other_life) { life = other_life; };

    void gen_frame() { life->iteration(); };

    void show_frame() {
      system("cls");
        for (int i = 0; i < life->get_height(); i++) {
            for (int j = 0; j < life->get_width(); j++) {

                if(life->operator[](i*life->get_width()+j)) printf("# ");
                else printf(". ");

            }
            printf("\n");
        }
    };

protected:
    board *life;

};

#endif //GOL_CONSOLE_WIN_H
