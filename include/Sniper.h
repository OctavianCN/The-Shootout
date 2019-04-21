#ifndef SNIPER_H
#define SNIPER_H

#include "Gun.h"


class Sniper : public Gun
{
    public:
        Sniper();
        void Load(SDL_Renderer* Render);
         void GunTakeMessage(int i);
        ~Sniper();

};

#endif // SNIPER_H
