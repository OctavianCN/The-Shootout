#include "Shotgun.h"

Shotgun::Shotgun()
{
    damage=50;
    range=2;
}
void Shotgun::Load(SDL_Renderer *Render)
{
     Texture::Load(Render,"shotgun.bmp");
}
void Shotgun::GunTakeMessage(int i)
{
    cout<<"\n Agentul "<<i<<" a luat un Shotgun\n";
}
Shotgun::~Shotgun()
{
    //dtor
}
