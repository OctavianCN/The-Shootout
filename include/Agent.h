#ifndef AGENT_H
#define AGENT_H
#include <iostream>
#include <SDL.h>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
#include "Table.h"
#include "Texture.h"
#include "GameObject.h"
#include "Gun.h"
using namespace std;

class Agent: public GameObject
{
    public:
        //Functii pentru initiere
        Agent();
        virtual void Load(SDL_Renderer* Render)=0;
        //Functii pentru statistici
        int GetAgentMoveDistance();
        int GetAgentVisionRange();
        int GetAgentHealth();
        int GetAgentDamage();
        void SetAgentDamage(int x);
        void SetAgentHp(int x);
        bool Alive();
        void Killed();
        void SetAgentGun(Gun *x);
        int GetPozGunInVector();
        void DestroyAgentGun();
        bool HaveGun();
        //Functie pentru numarul de agenti
        int GetNumberOfAgents();
        //Functie pentru Miscare
        void SetInitPoz(Table *table);
        void update(Table *table,Agent ***Agent);
        virtual void reset()=0;
       ~Agent();
    protected:
        //Variabile Pentru Statistica Agentului
        int Health;
        int VisionRange;
        int MoveDistance;
        int Damage;
        int RangeAttack;
        bool alive;
        Gun *gun;
        int PozGunInVector;

        //Numarul de agenti
        static int NrOfAgents;

};

#endif // AGENT_H
