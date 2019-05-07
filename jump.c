#include <SDL/SDL.h>
#include "jump.h"
#define STAT_SOL 0
#define STAT_AIR 1
void Saute(int *jumpspeed,int impulsion,int *status)
{
    (*jumpspeed) = -impulsion;
    (*status) = STAT_AIR;
}
void ControleSol(SDL_Rect *position,int *jumpspeed ,int *status)
{
    if (position->y>435)
    {
        position->y = 435;
        if ((*jumpspeed)>0)
            (*jumpspeed) = 0;
         (*status) = STAT_SOL;
    }
}

void Gravite(int *status,int factgravite,int factsautmaintenu,int jump,int *jumpspeed,int *mvmspeed)
{
    if ((*status) == STAT_AIR && jump==1)
        factgravite-=factsautmaintenu;
    (*jumpspeed) += factgravite;
}
void Evolue(SDL_Rect *position,int *status,int *jumpspeed,int *mvmspeed,int jump , int q ,int d)
{
    int lateralspeed = 0.5;
    int airlateralspeedfacteur = 0.5;
    int maxhspeed = 3.0;
    int adherance = 1.5;
    int impulsion = 6.0;
    int factgravite = 0.5;
    int factsautmaintenu = 3.0;
// controle lateral
    if ((*status) == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
    if (q==1) // (*1)
        (*mvmspeed)-=lateralspeed;
    if (d==1)
        (*mvmspeed)+=lateralspeed;
    if ((*status) == STAT_SOL && !(q==1) && !(d==1)) // (*3)
        (*mvmspeed)/=adherance;
// limite vitesse
    if ((*mvmspeed)>maxhspeed) // (*4)
        (*mvmspeed) = maxhspeed;
    if ((*mvmspeed)<-maxhspeed)
        (*mvmspeed) = -maxhspeed;
// saut
    if ((jump==1) && (*status) == STAT_SOL)
        Saute(jumpspeed,impulsion,status);
    Gravite(status,factgravite,factsautmaintenu,jump,jumpspeed,mvmspeed);
    ControleSol(position,jumpspeed,status);
    position->x +=(*mvmspeed);
    position->y +=(*jumpspeed);
}
