#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL.h>
#include "Texture.h"
#include <cstring>
#include "Table.h"
#include "Window.h"
#include "Agent.h"
#include "AgentPisica.h"
#include "AgentCaine.h"
#include "Gun.h"
#include "M4.h"
#include "Pistol.h"
#include "Sniper.h"
#include "Shotgun.h"
using namespace std;
class Game
{
    public:
        Game();
        ~Game();
        void run();
        void draw();
        void LoadObjects();
        bool CheckWin();
        void update(float delta);
        void SetInitPoz();
        void ResetPoz();
    private:
        Window *window;
        Table table;
        Texture background;
        Agent **agent;
        Gun **gun;
        float UpdateTime;
        bool Win;
        int WinPrint;
        int *Clasament;
        const int NrOfRounds=3;
        static int turn;
        // Sa inlocuiesc tot si sa pun in run :agents,background,table

};

#endif
