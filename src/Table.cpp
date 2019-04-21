#include "Table.h"

Table::Table(int x,int y)
{   linii=x;
    coloane=y;
    PozOcupate=new int*[linii];
    for(int i=0;i<linii;i++)
        PozOcupate[i]=new int[coloane];
    // In Pozitii Ocupate vrific ce pozitie e ocupata si cu ce
    for(int i=0;i<linii;i++)
    {
        for(int j=0;j<coloane;j++)
            PozOcupate[i][j]=0;  //0 -> nu e ocupat 1->player 2->arma
    }
    Window w;
    // Calculez dimensiuniile dreptunghiurilor in functie de cat de mare e fereastra
    LungimeDr=w.GetWindowWidth()/(coloane+4);
    LatimeDr=w.GetWindowHeight()/(linii+4);
    inaltime.h=LatimeDr*linii;
    latime.w=LungimeDr*coloane;
    latime.h=inaltime.w=3;
    latime.y=w.GetWindowWidth()/40;
    latime.x=w.GetWindowHeight()/40;
    inaltime.x=latime.x;
    inaltime.y=latime.y+latime.h;
}
void Table::Draw(SDL_Renderer *Render)
{
    int InaltimeXInit=inaltime.x,LatimeYInit=latime.y;
    SDL_SetRenderDrawColor(Render,255,255,255,255);
    for(int i=0;i<=linii;i++)
    {
        for(int j=0;j<=coloane;j++)
        {
            SDL_RenderFillRect(Render,&inaltime);
            inaltime.x=inaltime.x+LungimeDr;

        }
        SDL_RenderFillRect(Render,&latime);
        latime.y=latime.y+LatimeDr;
        inaltime.x=InaltimeXInit;
    }
    latime.y=LatimeYInit;

}
void Table::reset()
{
    for(int i=0;i<linii;i++)
    {
        for(int j=0;j<coloane;j++)
            PozOcupate[i][j]=0;
    }
}
SDL_Rect** Table::GetTableMatrix()
{
    // In Table Matrix o sa tin minte coordonatele fiecarui patratel adica poitia din coltul din stanga si + dimensiunea lui
    SDL_Rect **TableMatrix;
    int Xcoord=inaltime.x,Ycoord=latime.y;
    TableMatrix=new SDL_Rect*[linii];
    for(int i=0;i<linii;i++)
        TableMatrix[i]=new SDL_Rect[coloane];
    for(int i=0;i<linii;i++)
    {
        for(int j=0;j<coloane;j++)
        {
            TableMatrix[i][j].w=LungimeDr;
            TableMatrix[i][j].h=LatimeDr;
            TableMatrix[i][j].x=Xcoord;
            TableMatrix[i][j].y=Ycoord;
            Xcoord+=LungimeDr;
        }
        Xcoord=inaltime.x;
        Ycoord+=LatimeDr;
    }
    return TableMatrix;
}
void Table::SetPozitiiOcupate(int i,int j,int type)
{
    PozOcupate[i][j]=type;
}
void Table::FreePozitiiOcupate(int i,int j)
{
    PozOcupate[i][j]=0;
}
int** Table::GetPozOcupate()
{
    return PozOcupate;
}
int Table::GetColoane()
{
    return coloane;
}
int Table::GetLinii()
{
    return linii;
}
Table::~Table()
{
    for(int i=0;i<linii;i++)
       delete []PozOcupate[i];
    delete []PozOcupate;
}
