//
// Created by Piotr Drabik on 18.03.2021.
//  klasa realizuje 

#ifndef GOL_GAME_ENGINE_H
#define GOL_GAME_ENGINE_H

#include <iostream>
#include "cell.h"
#include <utility>

/// the brain of the game
/// does all of calculations
/// implements game of life engine with classic John Convay rules
/// the implemented space is infinite and wraps around on each edge
///
///     & * * * * %
///     # . . . . %
///     # . . . . %
///     # . . . . %
///     % * * * * &
///
/// so top is linked to bottom
/// and left to right
class game_engine {

public:
/// constructor creates dead plane in size given in x,y
/// \param x the height that plane will take
/// \param y the height that plane will take
/// \return creates game_engine object of given size
    game_engine(size_t x, size_t y) : width(y), height(x) {

        plane = new cell[x * y];
    };

    game_engine(const game_engine &other);

    game_engine &operator=(const game_engine &other);

    /// holds and apply rules of game of life
    /// by counting values in neighbour cells
    /// \param index points to cell witch will be tested
    /// \return returns true if cell under index will be alive in next round
    /// false if dead
    bool game_rules(int index);

    /// main function iterating game,
    /// \return replaces current game status (plane) with next one
    /// the values in plane will be replaced
    void iteration();

    /// \param position of desired cell in 1d plane
    /// \return gives access to desired cell
    cell &operator[](size_t position) { return plane[position]; };


    /// \param x position in height of desired cell
    /// \param y position in width of desired cell
    /// \return gives access to desired cell
    cell &get_cell(size_t x, size_t y) { return plane[x * width + y]; };

    /// \return the total number of cells in the game
    size_t get_size() { return width * height; };

    /// \return number of cell that fin in width
    size_t get_width() { return width; };

    /// \return number of cell that fin in height
    size_t get_height() { return height; };

    ~game_engine() {
        delete[] plane;
    }

private:
    size_t width;
    size_t height;
    /// array holding all of the cell values
    cell *plane;


};

#endif //GOL_GAME_ENGINE_H
