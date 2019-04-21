#ifndef AGENTCAINE_H
#define AGENTCAINE_H

#include <Agent.h>
#include "Texture.h"
using namespace std;
class AgentCaine : public Agent
{
    public:
        AgentCaine();
        void Load(SDL_Renderer* Render);
        void reset();
        ~AgentCaine();

};

#endif // AGENTCAINE_H
