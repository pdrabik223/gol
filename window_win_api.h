//
// Created by studio25 on 19.05.2021.
//

#ifndef GOL_WINDOW_WIN_API_H
#define GOL_WINDOW_WIN_API_H


#include "engine_traits.h"
#include "gol_base/game_engine.h"
#include <thread>
#include "window.h"

class window_win_api : public engine_traits {
public:
    window_win_api() = delete;

    explicit window_win_api(game_engine *other_life, HINSTANCE hThisInstance) {
        life = other_life;
        display_context = new ez::window(hThisInstance, 1, "game OF life");
    };

    ///generate new state of life
    void gen_frame() override { life->iteration(); };

    ///display the current state of life
    void show_frame() override;

    ~window_win_api() override {
        delete life;
        delete display_context;
    }


    /// main loop of the game
    /// maintains game running till the end of times
    /// \return handles generation, and output of chosen game of life
    /// \param time_between_frames the wait time between two consecutive frames
    /// the default value for time_between_frames is 1000 = 1s
    void play(unsigned int time_between_frames = 1000);

protected:
    /// the ui holds ahe address of played game
    /// this way we can easily modify played game
    game_engine *life;
    ez::window *display_context;

};


#endif //GOL_WINDOW_WIN_API_H
