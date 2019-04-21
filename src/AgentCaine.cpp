#include "AgentCaine.h"

AgentCaine::AgentCaine()
{
    MoveDistance=rand()%3+1;
    VisionRange=rand()%4+1;
    Damage=0;
    while(VisionRange<=MoveDistance)
    VisionRange=rand()%5+1;
}
void AgentCaine::Load(SDL_Renderer *Render)
{
   Texture::Load(Render,"Dog.bmp");
}
void AgentCaine::reset()
{
  Health=100;
  RangeAttack=1;
  alive=true;
  gun=NULL;
  MoveDistance=rand()%3+1;
  VisionRange=rand()%4+1;
  Damage=40;
  while(VisionRange<=MoveDistance)
    VisionRange=rand()%5+1;
}
AgentCaine::~AgentCaine()
{
    //dtor
}
