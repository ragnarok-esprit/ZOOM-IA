#ifndef ENNEMI_H_
#define ENNEMI_H_
#include "playermov.h"
typedef struct ennemis
{
	SDL_Rect position;
	SDL_Rect position2;
	SDL_Surface *fond;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
	SDL_Surface *fondc;
	SDL_Surface *fondd;
}ennemis;

void initialiserennemi(ennemis *ennemi);
void freesurfaceennemi(ennemis *ennemi);
ennemis mouvennemi(ennemis ennemi,perso perso,int d,int q,SDL_Rect camera,SDL_Surface *ecran,int *posmin,int *posmax,int *y,int mvmspeed,int *lastpos,int *z,int*x);
int splitennemi(int y);
void afficherennemi(ennemis ennemi,SDL_Surface *ecran,int y,SDL_Rect camera);
void attacking(SDL_Rect *position,int *i);

//nour/////////////////////////////////////////
void inarti(int x, SDL_Rect *pos_enemy ,int *k ,SDL_Rect *pos_bullet );

#endif 
