#include "GameObject.h"

GameObject::GameObject()
{}
void GameObject::SetInitialPoz(Table *table)
{
   int i,j;
   int **PozOcupate=table->GetPozOcupate();
   SDL_Rect **TableMatrix=table->GetTableMatrix();
   //Ii Pun agentului o pozitie random pe harta
   i=rand()%table->GetLinii();
   j=rand()%table->GetColoane();
   while(PozOcupate[i][j]!=0)
   {
       i=rand()%table->GetLinii();
       j=rand()%table->GetColoane();
   }
   PosRect.x=TableMatrix[i][j].x;
   PosRect.y=TableMatrix[i][j].y;
   PosRect.w=TableMatrix[i][j].w;
   PosRect.h=TableMatrix[i][j].h;
   LinePoz=i;
   ColPoz=j;
}
int GameObject::GetColPoz()
{
    return ColPoz;
}
int GameObject::GetLinePoz()
{
    return LinePoz;
}
void GameObject::Draw(SDL_Renderer *Render)
{
    SDL_RenderCopy(Render,textura,NULL,&PosRect);
}
GameObject::~GameObject()
{}
