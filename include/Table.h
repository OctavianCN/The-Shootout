#ifndef TABLE_H
#define TABLE_H
#include <SDL.h>
#include <iostream>
#include "Window.h"
using namespace std;

class Table
{
    public:
        Table(int x,int y);
        void Draw(SDL_Renderer *Render);
        SDL_Rect** GetTableMatrix();
        int GetLinii();
        int GetColoane();
        int** GetPozOcupate();
        void SetPozitiiOcupate(int i,int j,int type);
        void FreePozitiiOcupate(int i,int j);
        void reset();
        ~Table();
    private:
        SDL_Rect latime;
        SDL_Rect inaltime;
        int LungimeDr;
        int LatimeDr;
        int linii;
        int coloane;
        int **PozOcupate;
};

#endif // TABLE_H
