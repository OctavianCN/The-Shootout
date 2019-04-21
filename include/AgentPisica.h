#ifndef AGENTPISICA_H
#define AGENTPISICA_H
#include "Agent.h"
#include "Texture.h"
#include "Gun.h"
#include <iostream>

using namespace std;
class AgentPisica : public Agent
{
    public:
        AgentPisica();
        void Load(SDL_Renderer* Render);
        void reset();
        ~AgentPisica();
};

#endif // AGENTPISICA_H
