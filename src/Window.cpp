#include "Window.h"

Window::Window()
{
    window=SDL_CreateWindow("TheShootOut",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WindowWidth,WindowHeight,SDL_WINDOW_SHOWN);
    if(window==NULL)
    {
            cout<<"Nu am putut initializa fereastra";
            throw ".";
    }
    render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(render==NULL)
    {
        cout<<"Nu am putut crea un render\n";
        throw ".";
    }
}
SDL_Renderer* Window::GetRenderer()
{
    return render;
}
int Window::GetWindowWidth()
{
    return WindowWidth;
}
int Window::GetWindowHeight()
{
    return WindowHeight;
}
Window::~Window()
{
   SDL_DestroyRenderer(render);
   SDL_DestroyWindow(window);
}
