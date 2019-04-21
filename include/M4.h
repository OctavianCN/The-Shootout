#ifndef M4_H
#define M4_H

#include <Gun.h>


class M4 : public Gun
{
    public:
        M4();
        void Load(SDL_Renderer* Render);
        void GunTakeMessage(int i);
        ~M4();

};

#endif // M4_H
