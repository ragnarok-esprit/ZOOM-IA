#ifndef PERSO_H_
#define PERSO_H_
#include "fonction.h"

typedef struct perso
{
	int a;
	SDL_Rect position;
	SDL_Surface *fond00;
	SDL_Surface *fond0;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
	SDL_Surface *fondc;
	SDL_Surface *fondd;
	SDL_Surface *fonde;
		SDL_Surface *fond100;
	SDL_Surface *fond10;
	SDL_Surface *fond11;
	SDL_Surface *fond12;
	SDL_Surface *fond13;
	SDL_Surface *fond14;
	SDL_Surface *fond1a;
	SDL_Surface *fond1b;
	SDL_Surface *fond1c;
	SDL_Surface *fond1d;
	SDL_Surface *fond1e;

}perso;

typedef struct vie
{
	int nb;
	SDL_Rect position;
	SDL_Rect position2;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fond5;
}vie;

typedef struct 
{
 SDL_Surface * img;
 SDL_Rect p;
}enigme;
	
void gravity(SDL_Rect *positionchar,int gravity,int a,int *jumping,int jumpspeed,int *falling,int fall);
void jumpin(SDL_Rect *position,SDL_Rect *camera,int jump,int *i,int jumpheight,int jumpspeed,int *falling,int d,int q,int *mvm);
void initialiserperso(perso *perso);
void initialiserperso2(perso *perso);
void initialiserperso3(perso *perso);
void freefurfaceperso(perso *perso);
int mouv(int d,int q,int z,int s,int x,perso perso,int prevd,int prevq);
void splitperso2(int d,int q,int *x);
void mouvement(SDL_Rect *position,SDL_Rect *camera,int d,int q,int mvmspeed);
void afficherperso(perso perso,SDL_Surface *ecran,int x);
void initialiservie(vie *vie);
void freesurfacevie(vie *vie);
void affichervie(vie *vie,perso perso,SDL_Surface *ecran);

#endif 
