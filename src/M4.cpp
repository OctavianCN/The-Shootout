#include "M4.h"

M4::M4()
{
    damage=30;
    range=4;

}
void M4::Load(SDL_Renderer *Render)
{
     Texture::Load(Render,"m4.bmp");
}
void M4::GunTakeMessage(int i)
{
    cout<<"\n Agentul "<<i<<" a luat un M4\n";
}
M4::~M4()
{}
