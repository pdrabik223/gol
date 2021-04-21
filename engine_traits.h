//
// Created by studio25 on 18.03.2021.
//

#ifndef GOL_ENGINE_TRAITS_H
#define GOL_ENGINE_TRAITS_H

/// template class for all different ways to make ui
class engine_traits {
protected:
    /// iterates game_of_life,
    /// generates next cycle of life
    virtual void gen_frame() = 0;

    /// update the screen
    virtual void show_frame() = 0;

    virtual ~engine_traits() {};

};


#endif //GOL_ENGINE_TRAITS_H
