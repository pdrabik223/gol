//
// Created by Piotr Drabik on 18.03.2021.
//

#ifndef GOL_CELL_H
#define GOL_CELL_H

/// cell represents one tile in the game
/// one entity that is either alive or not
/// cell isa wrapper around boolean, it's done that way to separate this entity from rest of the game
class cell {
public:
    /// default is that cell is dead
    cell() : the_point_of_game_of_life(false) {};

    cell &operator=(const cell &other);

    cell(bool other) { the_point_of_game_of_life = other; }

    explicit operator bool() const { return the_point_of_game_of_life; };

private:
    bool the_point_of_game_of_life;
};


#endif //GOL_CELL_H
