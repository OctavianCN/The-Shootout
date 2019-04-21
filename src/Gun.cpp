#include "Gun.h"
int Gun::NrOfGuns=0;
Gun::Gun()
{
    taken=false;
    NrOfGuns++;
    destroy=false;
}
int Gun::GetGunDamage()
{
    return damage;
}
int Gun::GetGunRange()
 {
     return range;
 }
int Gun::GetNumberOfGuns()
 {
     return NrOfGuns;
 }
 void Gun::SetTaken()
 {
    taken=true;
 }
 bool Gun::CheckTaken()
 {
     return taken;
 }
 void Gun::SetInitPoz(Table *table)
 {
     table->SetPozitiiOcupate(LinePoz,ColPoz,2);//Ii Pun pozitia initiala pe harta
 }
 bool Gun::CheckDestroyed()
 {
     return destroy;
 }
 void Gun::DestroyGun()
 {
     destroy=true;
 }
 void Gun::update(int x,int y)
 {
     PosRect.x=x;
     PosRect.y=y;
 }
 void Gun::update(Table *table)
 {
     table->SetPozitiiOcupate(LinePoz,ColPoz,2);
 }
 void Gun::reset()
 {
    taken=false;
    destroy=false;
 }
Gun::~Gun()
{
    //dtor
}
