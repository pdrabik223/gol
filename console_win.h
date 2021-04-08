//
// Created by Piotr Drabik on 18.03.2021.
//

#ifndef GOL_CONSOLE_WIN_H
#define GOL_CONSOLE_WIN_H
#include <iostream>
#include "engine_traits.h"
#include "game_engine.h"

class console_win : public engine_traits {

public:
    console_win() = delete;

    console_win(game_engine *other_life) { life =other_life; };

    void gen_frame() { life->iteration(); };

    void show_frame() override;

    ~console_win(){delete life;}
protected:
    game_engine *life;

};



#endif //GOL_CONSOLE_WIN_H
