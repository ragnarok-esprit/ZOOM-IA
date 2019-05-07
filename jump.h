#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>

void Saute(int *jumpspeed,int impulsion,int *status);
void Gravite(int *status,int factgravite,int factsautmaintenu,int jump,int *jumpspeed,int *mvmspeed);
void Evolue(SDL_Rect *position,int *status,int *jumpspeed,int *mvmspeed,int jump , int q ,int d);
#endif // JEU_H_INCLUDED
