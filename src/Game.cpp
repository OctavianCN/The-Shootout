#include "Game.h"
int Game::turn=0;
Game::Game():table(25,25)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        cout<<"Nu am putut initializa SDL";
        throw ".";
    }
  // Imi aloc memorie pentru toate
   window=new Window;
   agent=new Agent*[4];
   gun=new Gun*[8];
   UpdateTime=0;
   for(int i=0;i<4;i++)
   {
       if(i<2)
        agent[i]=new AgentPisica;
       else
        agent[i]=new AgentCaine;
        agent[i]->SetInitialPoz(&table);
   }
   Clasament=new int[agent[0]->GetNumberOfAgents()];
   for(int i=0;i<agent[0]->GetNumberOfAgents();i++)
    Clasament[i]=0;
   for(int i=0;i<8;i++)
   {
       if(i<2)
       {
           gun[i]=new M4;
       }
       else
       {
          if(i<4)
          gun[i]=new Pistol;
          else
          {
             if(i<6)
             gun[i]=new Shotgun;
             else
             {
              if(i<8)
                gun[i]=new Sniper;
             }
           }
      }
      gun[i]->SetInitialPoz(&table);
   }
   WinPrint=0;
   Win=false;
}
void Game::run()
{
    SDL_Event e;
    bool quit=false;
    bool finish=false;
    int CurrRound=1;
    float delta;
    float CurrTime=0;
    float PrevTime;
    bool Pause=false,StartRound=false;
    int nr=0;
    this->LoadObjects();
    this->SetInitPoz();
    cout<<"Apasa S pentru start\n";
    cout<<"Apasa P pentru a pune pe pauza\n";
    while(!quit)
    {
        PrevTime=CurrTime;
        CurrTime=SDL_GetTicks();
        delta=(CurrTime-PrevTime)/1000.0f;// Calculez timpul pentru o parcurgere a while-ului
        int win=0;
        while(SDL_PollEvent(&e)!=0)
            {
                if(e.type==SDL_QUIT)
                   {
                       quit=true;
                   }
                else
                {
                    if(e.type==SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                        {
                            case SDLK_p:
                            if(Pause==false)
                            {
                                cout<<"\nPauza\n";
                                Pause=true;
                                StartRound=false;

                            }
                            else
                            {
                                cout<<"\nGata Pauza\n";
                                Pause=false;
                                StartRound=true;
                            }
                            break;
                            case SDLK_s:
                            StartRound=true;
                            break;

                        }
                    }
                }

            }
        SDL_RenderClear(window->GetRenderer());
        this->draw();
        //Verific daca sa fac update-uri
        if((CheckWin()==false)&&(Pause==false)&&(StartRound==true))
        {
        this->update(delta);
        }
        else
        {
            if(Win==true)
            {
                StartRound=false;
                Win=false;
            }

            if(CurrRound>NrOfRounds)
            {
                 for(int i=0;i<agent[0]->GetNumberOfAgents();i++)
                        cout<<"Agentul "<<i<<" are "<<Clasament[i]<<" victorii\n";
                break;

            }
            else
            {
                if(StartRound==true)
                {
                    CurrRound++;
                    //resetez pozitiile pentru a avea loc o alta runda
                    this->ResetPoz();
                    WinPrint=0;
                    StartRound=false;
                    Win=false;
                }

            }
        }

        SDL_RenderPresent(window->GetRenderer());

    }
}
void Game::draw()
{

   background.Draw(window->GetRenderer());
   table.Draw(window->GetRenderer());
   for(int i=0;i<agent[i]->GetNumberOfAgents();i++)
    {
        if(agent[i]->Alive()==true)
        agent[i]->Draw(window->GetRenderer());
    }
   for(int i=0;i<gun[i]->GetNumberOfGuns();i++)
    {
        if(gun[i]->CheckDestroyed()==false)
        gun[i]->Draw(window->GetRenderer());
    }

}
void Game::LoadObjects()
{
    background.Load(window->GetRenderer(),"background.bmp");
    for(int i=0;i<agent[i]->GetNumberOfAgents();i++)
    {
        agent[i]->Load(window->GetRenderer());
        SDL_SetTextureColorMod(agent[i]->GetTexture(),rand()%255+100,rand()%255+100,rand()%255+100);// Schimb culorile agentilor in cazul in care sunt 2 agenti de acelasi tip
        cout<<"Agentul "<<i<<" status\n"<<"Health : "<<agent[i]->GetAgentHealth()<<", Damage : "<<agent[i]->GetAgentDamage()<<", Move : "<<agent[i]->GetAgentMoveDistance()<<", Vision : "<<agent[i]->GetAgentVisionRange()<<"\n";
        cout<<agent[i]->GetLinePoz()<<" "<<agent[i]->GetColPoz()<<"\n";
    }
   for(int i=0;i<gun[i]->GetNumberOfGuns();i++)
   gun[i]->Load(window->GetRenderer());

}
void Game::update(float delta)
{

    UpdateTime=UpdateTime+delta;// Fac timpul dupa care sa dau un Update
    if(UpdateTime>=0.50f)
        {

            if(agent[turn]->Alive()==true)
            {
            agent[turn]->update(&table,&agent);
            for(int i=0;i<gun[i]->GetNumberOfGuns();i++)
            {
                //Verific pentru fiecare agent daca este pe aceeasi pozitie cu o arma care nu este luata sau nu a fost luata
                if((agent[turn]->GetLinePoz()==gun[i]->GetLinePoz())&&(agent[turn]->GetColPoz()==gun[i]->GetColPoz())&&(agent[turn]->HaveGun()==false)&&(gun[i]->CheckTaken()==false))
                    {
                        agent[turn]->SetAgentGun(gun[i]);
                        gun[i]->GunTakeMessage(turn);
                    }
            }
            for(int i=0;i<gun[i]->GetNumberOfGuns();i++)
            {
                if(gun[i]->CheckTaken()==false)
                    gun[i]->update(&table);
            }
            }
            turn++;
          if(turn>=agent[0]->GetNumberOfAgents())
            turn=0;
           UpdateTime=0;
        }

}
bool Game::CheckWin()
{
    int NrAgentsKilled=0;
    for(int i=0;i<agent[i]->GetNumberOfAgents();i++)
    {
        if(agent[i]->Alive()==false)
            NrAgentsKilled++;
    }
    if(agent[0]->GetNumberOfAgents()-NrAgentsKilled==1)
    {
        for(int i=0;i<agent[i]->GetNumberOfAgents();i++)
       {
        if(agent[i]->Alive()==true)
           {
            if(WinPrint==0)
             {
                 cout<<"\nAgentul "<<i<<" a castigat runda\n";
                 Clasament[i]++;
                 WinPrint=1;
                 Win=true;
             }

             return true;
           }

       }
    }
    return false;
}
void Game::SetInitPoz()
{
    for(int i=0;i<agent[i]->GetNumberOfAgents();i++)
    {
        agent[i]->SetInitPoz(&table);
    }
    for(int i=0;i<gun[i]->GetNumberOfGuns();i++)
   {
      gun[i]->SetInitPoz(&table);
   }
}
void Game::ResetPoz()
{

    table.reset();
    for(int i=0;i<agent[i]->GetNumberOfAgents();i++)
    {
         agent[i]->reset();
        agent[i]->SetInitialPoz(&table);

    }
    for(int i=0;i<gun[i]->GetNumberOfGuns();i++)
   {
       gun[i]->reset();
      gun[i]->SetInitialPoz(&table);

   }
   this->SetInitPoz();

}
Game::~Game()
{
  delete []agent;
  delete []gun;
  delete []window;
  delete []Clasament;
}
