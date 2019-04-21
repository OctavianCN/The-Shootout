#ifndef TEXTURE_H
#define TEXTURE_H
#include<iostream>
#include <SDL.h>
#include "Table.h"
using namespace std;

class Texture
{
    public:
        public:
        Texture();
        void Load(SDL_Renderer *Render,char *numeimagine);
        virtual void Draw(SDL_Renderer *Render);
        SDL_Texture* GetTexture();
        ~Texture();
    protected:
        SDL_Texture *textura;
        int TextureDimW,TextureDimH;


};

#endif // TEXTURE_H
