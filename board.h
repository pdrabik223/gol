//
// Created by studio25 on 18.03.2021.
//

#ifndef GOL_BOARD_H
#define GOL_BOARD_H

#include "cell.h"

class board {

public:

    board(size_t x, size_t y) : width(y), height(x) { plane = new cell[x * y]; };

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

    bool tmof(int x) {

        // todo to sie da zrobić lepiej
        // ale pentle będą wyglądały tak samo źle

        short live_count = 0;
        if (x - width - 1 >= 0 && plane[x - width - 1])++live_count;
        if (x - width >= 0 && plane[x - width])++live_count;
        if (x - width + 1 >= 0 && plane[x - width + 1])++live_count;

        if (x - 1 >= 0 && plane[x - 1])++live_count;
        if (x + 1 < get_size() && plane[x + 1])++live_count;

        if (x + width - 1 < get_size() && plane[x + width - 1])++live_count;
        if (x + width < get_size() && plane[x + width])++live_count;
        if (x + width + 1 < get_size() && plane[x + width + 1])++live_count;

        if (live_count != 0) std::cout << x;
        if (!plane[x] && live_count == 3) return true;
        else if (plane[x] && (live_count == 2 || live_count == 3)) return true;

        else return false;


    }

    void iteration() {
        cell *plane_copy = new cell[get_size()];
        for (int i = 0; i < get_size(); i++) plane_copy[i] = plane[i];
        for (int i = 0; i < get_size(); i++) if (tmof(i)) plane[i].reborn(); else plane[i].kill();
        delete[] plane;
        plane = new cell[get_size()];
        plane = plane_copy;
        delete plane_copy;
    };

    cell &operator[](size_t position) { return plane[position]; };

    size_t get_size() { return width * height; };

    size_t get_width() { return width; };

    size_t get_height() { return height; };


private:
    size_t width;
    size_t height;
    cell *plane;


};

#endif //GOL_BOARD_H
