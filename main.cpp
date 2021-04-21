//

#include <iostream>
#include <conio.h>
#include "console_win.h"


int main() {

    int x, y;

    x = 7; // gra będzie miała wyokość 7 komórek
    y = 7; // szerokość 7 komórek
    game_engine life(x, y);
    life.get_cell(2,3) = true;
    life.get_cell(3,4) = true;
    life.get_cell(4,4) = true;
    life.get_cell(4,3) = true;
    life.get_cell(4,2) = true;



    console_win game(&life); // przekazujemy mu wskaźnik na grę
    game.play(1000); // gra będzie wyświetlała klatę co 1s



    return 1;
}
