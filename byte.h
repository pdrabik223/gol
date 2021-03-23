//
// Created by studio25 on 21.03.2021.
//

#ifndef GOL_BYTE_H
#define GOL_BYTE_H

#include <cstdlib>

namespace dp {


    class byte {
    public:
        byte(unsigned char &other) { memory = new unsigned char(other); }

        byte(const byte &other) { memory = new unsigned char(*other.memory); };

        bool get_bite(unsigned char position) {
            unsigned char index = 1;
            index << position;
            return *memory & index;
        };

        void set_bite(unsigned char position, const bool &value) {
            unsigned char index = 1;
            index << position;
            index *= value;
            *memory |= index;
        };


        byte() { memory = (unsigned char *) malloc(1); }

        ~byte() { delete memory; }

    protected:
        unsigned char *memory;
    };

};
#endif //GOL_BYTE_H
