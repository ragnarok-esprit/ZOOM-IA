#include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <stdbool.h>
#include "utility.h"
 #include <math.h>
 
 int CollisionTrigoCir (  SDL_Rect posj , SDL_Rect posobj[],int n )
 {
	 int r1,r2,x ; 
for(int i=0;i<n;i++){
	 
	       r1=(sqrt(pow(posj.h,2)+pow(posj.w,2)))/2     ;
      r2=(sqrt(pow(posobj[i].h,2)+pow(posobj[i].w,2)))/2 ;
	 
 if   ( (posobj[i].x+(posobj[i].w/2))-(posj.x+(posj.w/2)) <= r1 + r2 && (posj.x <= posobj[i].x+(posobj[i].w/2)+r2 ) && (posj.y+posj.h > ((posobj[i].y+(posobj[i].h/2)) - r2 ) ) )
     {
		x=1 ; ; 
	 }
   else x=0 ; }
return x ; 
	 
	 
}
