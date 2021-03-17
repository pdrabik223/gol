#include <iostream>

class cell {
public:
    cell() : the_point_of_game_of_life(false) {};

    cell(bool the_way_of_living) : the_point_of_game_of_life(the_way_of_living) {};

    void kill() { the_point_of_game_of_life = false; };

    void reborn() { the_point_of_game_of_life = true; };

    operator bool() const { return the_point_of_game_of_life; };

private:
    bool the_point_of_game_of_life;
};

class board {

public:
    board() = delete;

    board(size_t x, size_t y) : width(y), height(x) { plane = new cell[x * y]; };

    board(const board &other) {
        width = other.width;
        height = other.height;
        for (int i = 0; i < width * height; i++) plane[i] = other.plane[i];
    }

    const board &operator=(const board &other) {
        if (this != &other) return *this;
        width = other.width;
        height = other.height;
        for (int i = 0; i < width * height; i++) plane[i] = other.plane[i];
        return *this;
    }

    bool tmof(int x) {
        char live_count = 0;
        if (x - 8 - 1 > 0 && plane[x - 8 - 1])++live_count;
        if (x - 8 > 0 && plane[x - 8])++live_count;
        if (x - 8 + 1 > 0 && plane[x - 8 + 1])++live_count;

        if (x - 1 > 0 && plane[x - 1])++live_count;
        if (x + 1 < width * height && plane[x + 1])++live_count;

        if (x + 8 - 1 < width * height && plane[x + 8 - 1])++live_count;
        if (x + 8 < width * height && plane[x + 8])++live_count;
        if (x + 8 + 1 < width * height && plane[x + 8 + 1])++live_count;

        if (!plane[x] && live_count == 3) return true;
        else if (plane[x] && (live_count == 2 || live_count == 3)) return true;
        else return false;


    }

    void iteration() {
        cell *plane_copy = new cell[width * height];


        for (int i = 0; i < width * height; i++) {
            plane_copy[i] = new cell(tmof(i));

        }

        plane = plane_copy;
        delete plane_copy;
    };

    void show() {

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (plane[i * height + j]) printf("# ");
                else printf(". ");

            }
            printf("\n");
        }

    }

private:
    size_t width;
    size_t height;
    cell *plane;


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x, y;
    std::cin >> x >> y;
    board life(x, y);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        system("cls");
        life.iteration();
        life.show();

        _sleep(1000);
    }
#pragma clang diagnostic pop


    return 0;
}
