    cmake_minimum_required(VERSION 3.19)
    project(gol)
    set(CMAKE_CXX_STANDARD 14)
    set(GOL_BASE gol_base/cell.h gol_base/cell.cpp gol_base/game_engine.h gol_base/game_engine.cpp)


    add_executable(console main.cpp
            ${GOL_BASE}
            engine_traits.h
            console_win.h console_win.cpp)

    add_executable(win_api win_api_main.cpp
            ${GOL_BASE}
            engine_traits.h
            window.h window.cpp
            window_win_api.h window_win_api.cpp)
