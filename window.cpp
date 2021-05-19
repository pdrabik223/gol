//
// Created by studio25 on 18.05.2021.
//

#include <iostream>
#include <thread>
#include "window.h"

ez::window::window(HINSTANCE hThisInstance, int nCmdShow, std::string window_text) : nCmdShow(nCmdShow) {
    this->window_text = window_text;


    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "window";
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl))
        throw "window_error";

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx(
            0,                   /* Extended possibilites for variation */
            "window",               /* Classname */
            window_text.c_str(),       /* Title Text */
            WS_OVERLAPPEDWINDOW, /* default window */
            CW_USEDEFAULT,       /* Windows decides the position */
            CW_USEDEFAULT,       /* where the window ends up on the screen */
            544,                 /* The programs width */
            375,                 /* and height in pixels */
            HWND_DESKTOP,        /* The window is a child-window to desktop */
            NULL,                /* No menu */
            hThisInstance,       /* Program Instance handler */
            NULL                 /* No Window Creation data */
    );
}

void ez::window::display_window() {
    /* Make the window visible on the screen */
    ShowWindow(hwnd, nCmdShow);
}

void ez::window::main_loop() {


    while (GetMessage(&messages, NULL, 0, 0)) {
        /* Run the message loop. It will run until GetMessage() returns 0 */

        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);

    }
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

    switch (message)                  /* handle the messages */
    {
        case WM_CLOSE: {
            DestroyWindow(hwnd);
            break;
        }
        case WM_cre:
            HPEN CzerwonePioro;
            CzerwonePioro = CreatePen(PS_SOLID, 1, 0x0000FF);

            HDC hdcOkno;
            hdcOkno = GetDC(hwnd);

            SelectObject( hdcOkno, CzerwonePioro );
            LineTo(hdcOkno, 21, 10);

            ReleaseDC(hwnd, hdcOkno);
            /// here should our code be placed
            /// witch is emmm weird
        case WM_DESTROY:
            PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
            break;

        default:                      /* for messages that we don't deal with */
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
