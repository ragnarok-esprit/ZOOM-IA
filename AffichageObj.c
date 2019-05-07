#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"


void affichageObj ( Objet obj , SDL_Surface *screen,SDL_Rect camera) 
{
obj.position.x-=camera.x;
SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));

}
void freesurfaceobject(Objet *obj){
SDL_FreeSurface(obj->image);
}
