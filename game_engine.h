//
// Created by Piotr Drabik on 18.03.2021.
//  klasa realizuje 

#ifndef GOL_GAME_ENGINE_H
#define GOL_GAME_ENGINE_H
#include <iostream>
#include "cell.h"
#include <utility>

class game_engine {

public:

    game_engine(size_t x, size_t y) : width(y), height(x) {

        plane = new cell[x * y];
    };

    game_engine(const game_engine &other);

    game_engine &operator=(const game_engine &other);

    bool game_rules(int index);

    void iteration();

    cell& operator[](size_t position) { return plane[position]; };

    size_t get_size() { return width * height; };

    size_t get_width() { return width; };

    size_t get_height() { return height; };


private:
    size_t width;
    size_t height;
    cell *plane;


};

#endif //GOL_GAME_ENGINE_H
