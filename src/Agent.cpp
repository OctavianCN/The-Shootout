#include "Agent.h"
int Agent::NrOfAgents=0;
Agent::Agent()
{
  Health=100;
  RangeAttack=1;
  alive=true;
  NrOfAgents++;
  gun==NULL;
}
int Agent::GetAgentMoveDistance()
{
    return MoveDistance;
}
int Agent::GetAgentVisionRange()
{
    return VisionRange;
}
int Agent::GetAgentHealth()
{
    return Health;
}
int Agent::GetAgentDamage()
{
    return Damage;
}
bool Agent::Alive()
{
    return alive;
}
int Agent::GetNumberOfAgents()
{
    return NrOfAgents;
}
void Agent::Killed()
{
    alive=false;
}
void Agent::SetInitPoz(Table *table)
{
    (*table).SetPozitiiOcupate(LinePoz,ColPoz,1);
}
void Agent::SetAgentDamage(int x)
{
    Damage=Damage+x;
}
void Agent::SetAgentHp(int x)
{
    Health=Health+x;
}
void Agent::SetAgentGun(Gun *x)
{
    gun=x;
    gun->SetTaken();
    gun->update(PosRect.x,PosRect.y);
    Damage=gun->GetGunDamage();
    RangeAttack=gun->GetGunRange();
}
void Agent::DestroyAgentGun()
{
    gun->DestroyGun();
}
bool Agent::HaveGun()
{
    if(gun!=NULL)
        return true;
    return false;
}
void Agent::update(Table *table,Agent ***agent)
{
  if(alive==true)
    {
    int **PozOcupate=table->GetPozOcupate();
    SDL_Rect **TableMatrix=table->GetTableMatrix();
    int LineMinVision,LineMaxVision,ColMinVision,ColMaxVision;
   pair < pair < float, int> , pair < int, int > > *PotentialPos;  // In Potential Pos o sa tin minte distanta, ce e pe pozitia potentiala si coordonatele in vector ale obiectului
   PotentialPos = new pair < pair < float, int> , pair < int, int > > [4*VisionRange];
   // Calculez Pozitiile de pe care poate agentul sa vada
   if(LinePoz-VisionRange>=0)
    LineMinVision=LinePoz-VisionRange;
   else
    LineMinVision=0;
   if(LinePoz+VisionRange<=table->GetLinii())
    LineMaxVision=LinePoz+VisionRange;
   else
    LineMaxVision=table->GetLinii();
    if(ColPoz-VisionRange>=0)
    ColMinVision=ColPoz-VisionRange;
   else
    ColMinVision=0;
   if(ColPoz+VisionRange<=table->GetColoane())
    ColMaxVision=ColPoz+VisionRange;
   else
    ColMaxVision=table->GetColoane();
   int NrOfPotentialPos=0;
   for(int i=LineMinVision;i<LineMaxVision;i++)
   {
       for(int j=ColMinVision;j<ColMaxVision;j++)
       {
        // Verific fiecare Pozitie Potentiala ( O pozitie potentiala ar fi cazul in care e o arma pe harta iar agentul nu are una sau e un inamic iar agentul are arma)
          if((PozOcupate[i][j]!=0)&&((LinePoz!=i)||(ColPoz!=j)))
          {
            if(gun==NULL)
             {
             if(PozOcupate[i][j]!=1)
             {
             PotentialPos[NrOfPotentialPos].first.first=sqrt(pow(i-LinePoz,2)+pow(j-ColPoz,2));
             PotentialPos[NrOfPotentialPos].first.second=PozOcupate[i][j];
             PotentialPos[NrOfPotentialPos].second.first=i;
             PotentialPos[NrOfPotentialPos].second.second=j;
           //  cout<<i<<" "<<j<<" \n ";
             NrOfPotentialPos++;
             }
             }
             else
             {
                 if(PozOcupate[i][j]!=2)
                 {
                     PotentialPos[NrOfPotentialPos].first.first=sqrt(pow(i-LinePoz,2)+pow(j-ColPoz,2))-RangeAttack;
                     PotentialPos[NrOfPotentialPos].first.second=PozOcupate[i][j];
                     PotentialPos[NrOfPotentialPos].second.first=i;
                     PotentialPos[NrOfPotentialPos].second.second=j;
                    //cout<<i<<" "<<j<<" \n ";
                    NrOfPotentialPos++;
                 }
             }

          }
       }
   }
   //sortez pozitiile in functie de distanta daca nu sunt pozitii pun random
   if(NrOfPotentialPos!=0)
   sort(PotentialPos,PotentialPos+NrOfPotentialPos);
   else
   {
       PotentialPos[0].second.first=rand()%table->GetLinii();
       PotentialPos[0].second.second=rand()%table->GetColoane();
       while(PozOcupate[PotentialPos[0].second.first][PotentialPos[0].second.second]==1)
       {
       PotentialPos[0].second.first=rand()%table->GetLinii();
       PotentialPos[0].second.second=rand()%table->GetColoane();
       }
       PotentialPos[0].first.second=-1;
   }
  // Daca pozitia potentiala nu e un inamic sau daca nu e inamicul in raza atunci decid sa mut agentul altfel il pun sa atace
   if((PotentialPos[0].first.second!=1)||(!((PotentialPos[0].second.first>LinePoz-RangeAttack)&&(PotentialPos[0].second.first<LinePoz+RangeAttack)&&(PotentialPos[0].second.second>ColPoz-RangeAttack)&&(PotentialPos[0].second.second<ColPoz+RangeAttack))))
   {
    int ok=0,DirX=0,DirY=0;// Daca DirX=0 atunci e stanga daca e 1 atunci e dreapta DirY=0 sus 1 jos (Folosesc pentru a evita suprapunerile de agenti)
    table->FreePozitiiOcupate(LinePoz,ColPoz);
    if(PozOcupate[PotentialPos[0].second.first][PotentialPos[0].second.second]==1)
    {
        ok=1;
    }
   if(PotentialPos[0].second.first>LinePoz)
      {
        if((MoveDistance+LinePoz>=PotentialPos[0].second.first)||(ok==1))
        {
            LinePoz=PotentialPos[0].second.first;
            if((ok==1)&&(LinePoz+1<table->GetLinii()))
               {
                   LinePoz=LinePoz+1;
                   ok=0;
               }
        }
        else
            LinePoz=LinePoz+MoveDistance;
         DirX=1;
      }
      else
      {
        if((LinePoz-MoveDistance<=PotentialPos[0].second.first)||(ok==1))
        {
            LinePoz=PotentialPos[0].second.first;
            if((ok==1)&&(LinePoz-1>0))
               {
                LinePoz=LinePoz-1;
                ok=0;
               }
        }
        else
        LinePoz=LinePoz-MoveDistance;
      }
    if(PotentialPos[0].second.second>ColPoz)
    {
        if((MoveDistance+ColPoz>=PotentialPos[0].second.second)||(ok==1))
          {
            ColPoz=PotentialPos[0].second.second;
            if((ok==1)&&(ColPoz+1<table->GetColoane()))
                {
                    ColPoz=ColPoz+1;
                    ok=0;
                }
          }
        else
            ColPoz=ColPoz+MoveDistance;
    }
     else
    {
        if((ColPoz-MoveDistance<=PotentialPos[0].second.second)||(ok==1))
         {
             ColPoz=PotentialPos[0].second.second;
             if((ok==1)&&(ColPoz-1>0))
               {
                   ColPoz=ColPoz-1;
                   ok=0;
               }

         }
        else
        ColPoz=ColPoz-MoveDistance;
        DirY=1;
    }
    // Daca se suprapun agentii ii mut o casuta inapoi (adica mai aproape de unde au venit) ca sa nu ii suprapun
    if(PozOcupate[LinePoz][ColPoz]==1)
    {
        if(DirX==0)
        {
            if(LinePoz-1>0)
            LinePoz=LinePoz-1;
        }
        else
        {
            if(LinePoz+1<table->GetLinii())
                LinePoz=LinePoz+1;
        }
        if(DirY==0)
        {
            if(ColPoz+1<table->GetColoane())
            ColPoz=ColPoz+1;
        }
        else
        {
            if(ColPoz-1>0)
            ColPoz=ColPoz-1;
        }

    }
    table->SetPozitiiOcupate(LinePoz,ColPoz,1);
    PosRect.x=TableMatrix[LinePoz][ColPoz].x;
    PosRect.y=TableMatrix[LinePoz][ColPoz].y;
    // Verific daca agentul are arma ca sa ii dau si ei update in functie de agent
    if(gun!=NULL)
      gun->update(PosRect.x,PosRect.y);
   }
   else
   {
       for(int i=0;i<NrOfAgents;i++)
       {
               if((PotentialPos[0].second.first==(*agent)[i]->GetLinePoz())&&(PotentialPos[0].second.second==(*agent)[i]->GetColPoz()))
               {
                   (*agent)[i]->SetAgentHp(-Damage);
                   cout<<"Agent "<<i<<" a luat Damage "<<" HP ramas : "<<(*agent)[i]->GetAgentHealth()<<"\n";
                   if((*agent)[i]->GetAgentHealth()<=0)
                   {
                       // Daca agentul moare eliberez poz ocupate si distrug arma
                       (*agent)[i]->Killed();
                       if((*agent)[i]->HaveGun()==true)
                       (*agent)[i]->DestroyAgentGun();
                       cout<<" Agentul "<<i<<" a murit\n";
                       table->FreePozitiiOcupate((*agent)[i]->GetLinePoz(),(*agent)[i]->GetColPoz());
                   }

               }
       }
   }
   delete []PotentialPos;
 }

}
Agent::~Agent()
{

}

