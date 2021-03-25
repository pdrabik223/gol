//
// Created by Piotr Drabik on 18.03.2021.
//

#ifndef GOL_CELL_H
#define GOL_CELL_H

class cell {
public:
    cell() : the_point_of_game_of_life(false) {};


    cell &operator=(const cell &other) {
        if (this == &other)return *this;
        the_point_of_game_of_life = other.the_point_of_game_of_life;
        return *this;
    }

    cell(const cell &other) { the_point_of_game_of_life = other.the_point_of_game_of_life; }

    cell(bool other) { the_point_of_game_of_life = other; }

    void kill() { the_point_of_game_of_life = false; };

    void reborn() { the_point_of_game_of_life = true; };

    explicit operator bool() const { return the_point_of_game_of_life; };

private:
    bool the_point_of_game_of_life;
};

#endif //GOL_CELL_H
