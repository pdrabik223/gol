//
// Created by studio25 on 08.04.2021.
//
#include "cell.h"


cell &cell::operator=(const cell &other) {
    if (this == &other)return *this;
    the_point_of_game_of_life = other.the_point_of_game_of_life;
    return *this;
}
