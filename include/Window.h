#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <iostream>
using namespace std;

class Window
{
    public:
        Window();
        int GetWindowHeight();
        int GetWindowWidth();
        SDL_Renderer* GetRenderer();
        ~Window();
    private:
        static const int WindowHeight=900;
        static const int WindowWidth=1000;
        SDL_Renderer *render;
        SDL_Window *window;
};

#endif // WINDOW_H
