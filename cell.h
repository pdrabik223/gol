//
// Created by studio25 on 18.03.2021.
//

#ifndef GOL_CELL_H
#define GOL_CELL_H

class cell {
public:
    cell() : the_point_of_game_of_life(false) {};

    cell(bool the_way_of_living)  {
     the_point_of_game_of_life = the_way_of_living;

    };

    void kill() { the_point_of_game_of_life = false; };

    void reborn() { the_point_of_game_of_life = true; };

    explicit operator bool() const { return the_point_of_game_of_life; };

private:
    bool the_point_of_game_of_life;
};
#endif //GOL_CELL_H
