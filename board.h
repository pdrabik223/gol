//
// Created by studio25 on 18.03.2021.
//

#ifndef GOL_BOARD_H
#define GOL_BOARD_H

#include "byte.h"

class board {

public:

    board(size_t x, size_t y) : width(y), height(x) {
        size_t size = x * y / 8;
        plane = new dp::byte[x * y];
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

    bool tmof(int x) {

        // todo to sie da zrobić lepiej
        // ale pentle będą wyglądały tak samo źle


        // impolementing infinite space
        short live_count = 0;
        unsigned char index = x - width;

        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;
        --index;
        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;
        index += 2;
        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;
        index = x - 1;
        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;
        index += 2;
        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;
        index = x + width;
        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;
        --index;
        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;
        index += 2;
        if (index >= 0 && plane[index / 8].get_bite(index % 8)) ++live_count;


        if (!plane[x / 8].get_bite(x % 8) && live_count == 3) return true;
        else if (plane[x / 8].get_bite(x % 8) && (live_count == 2 || live_count == 3)) return true;

        else return false;


    }

    void iteration() {

        unsigned char local_size(get_size() / 8);
        if(get_size()%8!=0)++local_size;
        dp::byte *plane_copy = new dp::byte[local_size];

        for (int i = 0; i < get_size(); i++)
            if (tmof(i))
                plane_copy[i / 8].set_bite(i % 8, true);
            else
                plane_copy[i / 8].set_bite(i % 8, false);


        delete[] plane;
       // plane = new dp::byte[get_size()];
        plane = plane_copy;
        delete plane_copy;
    };

    bool operator[](size_t position) { return plane[position / 8].get_bite(position % 8); };

    size_t get_size() { return width * height; };

    size_t get_width() { return width; };

    size_t get_height() { return height; };


private:
    size_t width;
    size_t height;
    dp::byte *plane;


};

#endif //GOL_BOARD_H
