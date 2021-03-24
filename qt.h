//
// Created by studio25 on 24.03.2021.
//

#ifndef GOL_QT_H
#define GOL_QT_H
#include "engine_traits.h"
#include "board.h"

class qt : public engine_traits {
public:
    qt() = delete;
    qt( board *other_life) { life = other_life; };

    void gen_frame() { life->iteration(); };
    void show_frame() {
     // here's where magic happens

    };

protected:
    board *life;

};
#endif //GOL_QT_H
