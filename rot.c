#include "fonction.h"

#include <SDL/SDL_rotozoom.h>

SDL_Surface* zoom (double *a,double *r,SDL_Surface *kalb)
{
SDL_Surface *rota=NULL;

//rot angle
(*a)+=1;
//zoom
(*r)+=0.01;
printf("%f\n",(*a));
//rot 1 plus smooth 0 non smooth
rota=rotozoomSurface (kalb, *a,*r, 1);
return rota;
}
