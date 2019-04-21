#include "Sniper.h"

Sniper::Sniper()
{
    damage=80;
    range=15;
}
void Sniper::Load(SDL_Renderer *Render)
{
     Texture::Load(Render,"sniper.bmp");
}
void Sniper::GunTakeMessage(int i)
{
    cout<<"\n Agentul "<<i<<" a luat un Sniper\n";
}
Sniper::~Sniper()
{}
