#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Texture.h"
#include "Table.h"
#include <iostream>
using namespace std;

class GameObject: public Texture
{
    public:
        GameObject();
        virtual void Draw(SDL_Renderer *Render);
        virtual void SetInitPoz(Table *table)=0;
        int GetLinePoz();
        int GetColPoz();
        void SetInitialPoz(Table *table);
        ~GameObject();
    protected:
        SDL_Rect PosRect;
        int LinePoz;
        int ColPoz;
};

#endif // GAMEOBJECT_H
