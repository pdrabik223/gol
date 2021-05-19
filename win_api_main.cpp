//
// Created by studio25 on 19.05.2021.
//

#include <iostream>
#include <windows.h>
#include "window_win_api.h"

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nCmdShow) {
    int x, y;

    x = 7; // game will be 7 cells high
    y = 7; // and 7 cells width
    game_engine life(x, y);
    life.get_cell(2,3) = true;
    life.get_cell(3,4) = true;
    life.get_cell(4,4) = true;
    life.get_cell(4,3) = true;
    life.get_cell(4,2) = true;



    window_win_api game(&life, hThisInstance); // passing pointer to our game
    game.play(1000); // the game will update every second



    return 0;
}
