//
// Created by Piotr Drabik on 18.03.2021.
//

#ifndef GOL_CONSOLE_WIN_H
#define GOL_CONSOLE_WIN_H

#include <iostream>
#include "engine_traits.h"
#include "game_engine.h"


///provides visualisation of played game using windows console
class console_win : public engine_traits {

public:
    console_win() = delete;

    console_win(game_engine *other_life) { life = other_life; };

    void gen_frame() { life->iteration(); };

    void show_frame() override;

    ~console_win() { delete life; }

protected:
    /// the ui holds ahe address of played game
    /// this way we can easily modify played game
    game_engine *life;

};


#endif //GOL_CONSOLE_WIN_H
