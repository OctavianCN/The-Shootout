#ifndef GUN_H
#define GUN_H

#include "Texture.h"
#include "Table.h"
#include "GameObject.h"
using namespace std;
class Gun : public GameObject
{
    public:
        Gun();
        virtual void Load(SDL_Renderer* Render)=0;
        int GetGunDamage();
        int GetGunRange();
        int GetNumberOfGuns();
        void SetTaken();
        bool CheckTaken();
        bool CheckDestroyed();
        void DestroyGun();
        virtual void GunTakeMessage(int i)=0;
        void SetInitPoz(Table *table);
        void update(int x,int y);
        void update(Table *table);
        void reset();
        ~Gun();
    protected:
        bool taken;
        bool destroy;
        int range;
        int damage;
        static int NrOfGuns;
};

#endif // GUN_H
