//
// Created by studio25 on 18.05.2021.
//

#ifndef WIN_API_WINDOW_H
#define WIN_API_WINDOW_H

#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <chrono>
#include <string>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

namespace ez {
    class window {
    public:
        window(HINSTANCE hThisInstance, int nCmdShow, std::string window_text);

        void display_window();

        void main_loop();


    private:
        std::string window_text;
        HWND hwnd;               /* This is the handle for our window */
        MSG messages;            /* Here messages to the application are saved */
        WNDCLASSEX wincl;        /* Data structure for the windowclass */
        int nCmdShow = 1;               /* ifo about displayed window*/



    };
}
#endif //WIN_API_WINDOW_H
