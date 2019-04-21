#include "Pistol.h"

Pistol::Pistol()
{
    damage=40;
    range=2;
}
void Pistol::Load(SDL_Renderer *Render)
{
     Texture::Load(Render,"pistol.bmp");
}
void Pistol::GunTakeMessage(int i)
{
    cout<<"\n Agentul "<<i<<" a luat un pistol\n";
}
Pistol::~Pistol()
{}
