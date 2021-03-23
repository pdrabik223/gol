//
// Created by studio25 on 18.03.2021.
//

#ifndef GOL_BOARD_H
#define GOL_BOARD_H

#include "cell.h"
#include <utility>

class board {

public:

    board(size_t x, size_t y) : width(y), height(x) {

        plane = new cell[x * y];
    };

    board(const board &other) {
        width = other.width;
        height = other.height;
        for (int i = 0; i < get_size(); i++) plane[i] = other.plane[i];
    }

    const board &operator=(const board &other) {
        if (this != &other) return *this;
        width = other.width;
        height = other.height;
        for (int i = 0; i < get_size(); i++) plane[i] = other.plane[i];
        return *this;
    }

    bool tmof(int index) {

        // todo to sie da zrobić lepiej



        // implementing infinite space
        unsigned live_count = 0;

        unsigned ix = index / width;
        unsigned iy = index % width;
        unsigned nx = ix;
        unsigned ny = iy;

        int surrounding[8];

        surrounding[0] = index - width - 1;
        surrounding[1] = index - width;
        surrounding[2] = index - width + 1;
        surrounding[3] = index - 1;
        surrounding[4] = index + 1;
        surrounding[5] = index + width - 1;
        surrounding[6] = index + width;
        surrounding[7] = index + width + 1;

        if (ix == 0) {
            surrounding[0] = get_size() - 1;
            surrounding[1] = get_size() - 2;
            surrounding[2] = get_size() - 3;
        } else if (ix == height - 1) {
            surrounding[5] = iy + 2;
            surrounding[6] = iy + 1;
            surrounding[7] = iy;
        }


        if (iy == 0) {
            surrounding[0] += width - 1;
            surrounding[3] += width - 1;
            surrounding[5] += width - 1;
        }
        if (iy == width - 1) {
            surrounding[2] -= width - 1;
            surrounding[4] -= width - 1;
            surrounding[7] -= width - 1;
        }

        for (int i = 0; i < 8; i++) if (plane[surrounding[i]]) ++live_count;


        if (live_count == 3) return true;

        if (plane[index] && live_count == 2) return true;

        return false;


    }

    void iteration() {

        cell *plane_copy = new cell[get_size()];

        for (size_t i = 0; i < get_size(); i++)
            if(tmof(i)) plane_copy[i] = new cell(true);
            else plane_copy[i] = new cell(false);

        delete[] plane;
        plane = new cell[get_size()];

        for (size_t i = 0; i < get_size(); i++) // todo this can be better, but i don't know how to do it
            plane[i] = plane_copy[i];

        delete[] plane_copy;

    };

    bool operator[](size_t position) { return (bool) plane[position]; };

    size_t get_size() { return width * height; };

    size_t get_width() { return width; };

    size_t get_height() { return height; };


private:
    size_t width;
    size_t height;
    cell *plane;


};

#endif //GOL_BOARD_H
