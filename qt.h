//
// Created by Piotr Drabik on 24.03.2021.
//
 // todo class still in progress

#ifndef GOL_QT_H
#define GOL_QT_H

#include "engine_traits.h"
#include "game_engine.h"

class qt : public engine_traits {
public:
    qt() = delete;

    qt(game_engine *other_life) { life = other_life; };

    void gen_frame() { life->iteration(); };

    void show_frame() {
        // here's where magic happens

    };

protected:
    game_engine *life;

};

#endif //GOL_QT_H
