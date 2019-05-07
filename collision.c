#include "fonction.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    switch(bpp) {
    case 1:
        return *p;
        break;
    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

SDL_Rect collision(SDL_Rect camera)
{
if(camera.x<0)
{
camera.x=0;
}

if(camera.x>10650)
{
camera.x=10650;
}

return camera ;
}


void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie)
{
if(((((perso->position.x+perso->fond1->w > ennemi->position.x)&&(perso->position.x+perso->fond1->w < ennemi->position.x+ennemi->fond1->w))||((perso->position.x < ennemi->position.x+ennemi->fond1->w)&&(perso->position.x > ennemi->position.x)))&&perso->position.y==435&&ennemi->position.y == 435)||((((perso->position.x+perso->fond1->w > ennemi->position.x)&&(perso->position.x+perso->fond1->w < ennemi->position.x+ennemi->fond1->w))||((perso->position.x < ennemi->position.x+ennemi->fond1->w)&&(perso->position.x > ennemi->position.x)))&&perso->position.y==435&&ennemi->position.y == 435))
{
ennemi->position.x = 1001 ;
perso->position.x = 100 ;
perso->position.y = 435 ;
camera->x=0;
vie->nb--;
}
}
void Health(vie *vie,int x[],SDL_Rect *camera,SDL_Rect *perso,SDL_Rect *enemie,int n ){
for(int i=0;i<n;i++){
    if(x[i]==1){
        camera->x=0;
        perso->x=100; 
        perso->y=435;
        enemie->x=1001; 
        enemie->y=435;
vie->nb--;


}}}


