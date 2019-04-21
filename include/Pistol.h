#ifndef PISTOL_H
#define PISTOL_H

#include "Gun.h"


class Pistol : public Gun
{
    public:
        Pistol();
        void Load(SDL_Renderer* Render);
         void GunTakeMessage(int i);
        ~Pistol();

};

#endif // PISTOL_H
