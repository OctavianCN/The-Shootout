#include "AgentPisica.h"

AgentPisica::AgentPisica()
{
    MoveDistance=rand()%2+1;
    VisionRange=rand()%8+1;
    Damage=0;
    while(VisionRange<=MoveDistance)
    VisionRange=rand()%5+1;
}
void AgentPisica::Load(SDL_Renderer *Render)
{
   Texture::Load(Render,"CapitanCLaw.bmp");
}
void AgentPisica::reset()
{
  Health=100;
  RangeAttack=1;
  alive=true;
  gun=NULL;
  MoveDistance=rand()%2+1;
    VisionRange=rand()%8+1;
    Damage=20;
    while(VisionRange<=MoveDistance)
    VisionRange=rand()%5+1;
}
AgentPisica::~AgentPisica()
{
    //dtor
}
