#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "Gun.h"


class Shotgun : public Gun
{
    public:
        Shotgun();
        void Load(SDL_Renderer* Render);
         void GunTakeMessage(int i);
        ~Shotgun();

};

#endif // SHOTGUN_H
