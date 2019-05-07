#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
SDL_Surface * Init_imagedefond( SDL_Surface *imagedefond ,SDL_Rect *image ,  int x , int y) 
 {
	       imagedefond =  IMG_Load("map/lvl_map1.png"); 

	      if  ( imagedefond ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     		{
     image->x  =  x ; 
     image->y  = y ;
     image->h=imagedefond->h ;
     image->w=imagedefond->w ;  
 			}
     
     return (imagedefond) ; 
}
 void Show_imagedefond (SDL_Surface *imagedefond , SDL_Surface *screen , SDL_Rect image ) 
  {
	 SDL_BlitSurface(imagedefond, NULL, screen, &image);
  }
void portal(int *i,SDL_Rect position,SDL_Surface * ecran,SDL_Rect camera)
{char imageee[30];
SDL_Surface *image=NULL;
printf("a\n");
sprintf(imageee,"../newgame/portal/%d",(*i));
image= IMG_Load(imageee);
printf("a\n");
position.x-=camera.x;
SDL_BlitSurface(image,NULL, ecran,&position);
printf("a\n");                    
 (*i)++;
if((*i)>82)
 (*i)=0;
}

