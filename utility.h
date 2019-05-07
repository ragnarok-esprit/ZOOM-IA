#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
int collisionbb( SDL_Rect posj , SDL_Rect posobj,SDL_Rect camera ) ; 
int collisiontrigoinscrit ( SDL_Rect posj , SDL_Rect posobj,int n  ) ; 
int CollisionTrigoCir (  SDL_Rect posj , SDL_Rect posobj,int n  );
int  collisionpit(int debut[],int fin[],int * gravity,int n,SDL_Rect posj,SDL_Rect camera );
int collisionplatform(int debut[],int fin[],int *gravity,int n,SDL_Rect posj,SDL_Rect camera ,int haut[]);
#endif /* FONCTIONS_H_ */
