#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "utility.h"

int collisionbb( SDL_Rect posj , SDL_Rect posobj,SDL_Rect camera)
{
 int x ; 
if((posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h)&&(posj.x+camera.x+posj.w>=posobj.x)&&(posj.x+camera.x<=posobj.x+posobj.w)) 
{
	x=1 ; 
}
else x=0 ; 
return x ;
}
int  collisionpit(int debut[],int fin[],int *gravity,int n,SDL_Rect posj,SDL_Rect camera ){
for(int i=0;i<n;i++){
if(posj.x+camera.x>debut[i]&&posj.x+camera.x<fin[i]){
(*gravity)=660;
return 1;
}

}
return 0;
}
int collisionplatform(int debut[],int fin[],int *gravity,int n,SDL_Rect posj,SDL_Rect camera ,int haut[]){
int x;
for(int i=0;i<n;i++){
if(posj.x+camera.x>debut[i]&&posj.x+camera.x<fin[i]){

if(posj.y<haut[i]){
(*gravity)=haut[i]-10;
return 1;
}
}
return 0;
}

	
}
