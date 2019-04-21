#include "Texture.h"

Texture::Texture()
{
   textura=NULL;
   TextureDimW=TextureDimH=0;

}
void Texture::Load(SDL_Renderer *Render,char *numeimagine)
{
    if(textura==NULL)
    {
        SDL_Surface *suprafata=SDL_LoadBMP(numeimagine);
        if(suprafata==NULL)
       {
        cout<<"Nu am putut incarca suprafata";
       }
        SDL_SetColorKey(suprafata,SDL_TRUE,SDL_MapRGB(suprafata->format,255,255,255));
        textura=SDL_CreateTextureFromSurface(Render,suprafata);
        if(textura==NULL)
           {
            cout<<"Nu am putut incarca textura";
            throw ".";
           }
        SDL_FreeSurface(suprafata);
        SDL_QueryTexture(textura,NULL,NULL,&TextureDimW,&TextureDimH);
    }
}
void Texture::Draw(SDL_Renderer *Render)
{
    SDL_RenderCopy(Render,textura,NULL,NULL);
}
SDL_Texture* Texture::GetTexture()
{
    return textura;
}
Texture::~Texture()
{
    SDL_DestroyTexture(textura);
}
