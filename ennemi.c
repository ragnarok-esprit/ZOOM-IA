#include "fonction.h"
#include "playermov.h"
void initialiserennemi(ennemis *ennemi)
{
ennemi->position.x = 1001 ;
ennemi->position.y = 435 ;
ennemi->position.h = 180 ;
ennemi->position.w= 120 ;
ennemi->position2.x = 0 ;
ennemi->position2.y = 0 ;
//nour
ennemi->fond = IMG_Load("../newgame/charc/warning.png");
ennemi->fond1 = IMG_Load("../newgame/charc/x1.png");
ennemi->fond2 = IMG_Load("../newgame/charc/x2.png");
ennemi->fond3 = IMG_Load("../newgame/charc/x3.png");
ennemi->fond4 = IMG_Load("../newgame/charc/x4.png");
ennemi->fonda = IMG_Load("../newgame/charc/xa.png");
ennemi->fondb = IMG_Load("../newgame/charc/xb.png");
ennemi->fondc = IMG_Load("../newgame/charc/xc.png");
ennemi->fondd = IMG_Load("../newgame/charc/xd.png");

}
void freesurfaceennemi(ennemis *ennemi)
{
SDL_FreeSurface(ennemi->fond);
SDL_FreeSurface(ennemi->fond1);
SDL_FreeSurface(ennemi->fond2);
SDL_FreeSurface(ennemi->fond3);
SDL_FreeSurface(ennemi->fond4);
SDL_FreeSurface(ennemi->fondc);
SDL_FreeSurface(ennemi->fondd);
SDL_FreeSurface(ennemi->fonda);
SDL_FreeSurface(ennemi->fondb);
}
ennemis mouvennemi(ennemis ennemi,perso perso,int d,int q,SDL_Rect camera,SDL_Surface *ecran,int *posmin,int *posmax,int *y,int mvmspeed,int *lastpos,int *z,int*x)
{
//int r ;
//r = rand();
if((*lastpos)!=camera.x){
	printf("cja\n");
ennemi.position.x=ennemi.position.x+(*lastpos)-camera.x;
*posmax=*posmax+(*lastpos)-camera.x;
*posmin=*posmin+(*lastpos)-camera.x;
}

if(ennemi.position.x>=*posmax){
	*z=2;
}if(ennemi.position.x<=*posmin){
*z=1;
}
if(ennemi.position.x<*posmax&& *z==1){
	*x=2;	
}if(ennemi.position.x>*posmin&& *z==2){
*x=1;

}
//nourr 
if(((ennemi.position.x-perso.position.x<300&&ennemi.position.x-perso.position.x>0)||(perso.position.x-ennemi.position.x<300&&perso.position.x-ennemi.position.x>0)))
{
	ennemi.position2.x=ennemi.position.x+50;
	ennemi.position2.y=ennemi.position.y-70;
	SDL_BlitSurface(ennemi.fond,NULL, ecran,&ennemi.position2);
	if(ennemi.position.x-perso.position.x<300&&ennemi.position.x-perso.position.x>0)
	{

	if((*y)!=1&&(*y)!=2&&(*y)!=3&&(*y)!=4)
	{

	(*y)=1;
	}
	if((d==0&&q==0)&&(camera.x<11000&&camera.x>0))
	{
	ennemi.position.x=ennemi.position.x-10;
(*lastpos)=camera.x;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x-20;
}
if(q==1)
{
ennemi.position.x=ennemi.position.x-5;
}
}
if(perso.position.x-ennemi.position.x<300&&perso.position.x-ennemi.position.x>0)
{
if((*y)!=5&&(*y)!=6&&(*y)!=7&&(*y)!=8)
{
(*y)=5;
}
if((d==0&&q==0)&&(camera.x<11000&&camera.x>0))
{
ennemi.position.x=ennemi.position.x+10;
(*lastpos)=camera.x;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x+5;
}
if(q==1)
{
ennemi.position.x=ennemi.position.x+20;
}
}
(*lastpos)=camera.x;
return ennemi;
}else if(*x==1){
if((*y)!=1&&(*y)!=2&&(*y)!=3&&(*y)!=4)
	{

	(*y)=1;
	}

ennemi.position.x=ennemi.position.x-20;
}else if(*x==2){
ennemi.position.x=ennemi.position.x+20;
if((*y)!=5&&(*y)!=6&&(*y)!=7&&(*y)!=8)
{
(*y)=5;
}

}(*lastpos)=camera.x;
return ennemi;
}
int splitennemi(int y)
{

switch(y)
{
case 1:
y=2;
	break;
case 2:
y=3;
	break;
case 3:
y=4;
	break;
case 4:
y=1;
	break;
case 5 :
y=6;
break;
case 6 :
y=7;
break;
case 7 :
y=8;
break;
case 8 :
y=5;
break;

}	
return y ;
}
void afficherennemi(ennemis ennemi,SDL_Surface *ecran,int y,SDL_Rect camera)
{

switch(y)
{
case 3:
SDL_BlitSurface(ennemi.fonda,NULL, ecran,&ennemi.position);
	break ;
case 4:
SDL_BlitSurface(ennemi.fondb,NULL, ecran,&ennemi.position);
	break ;
case 1:
SDL_BlitSurface(ennemi.fondc,NULL, ecran,&ennemi.position);
	break ;
case 2:
SDL_BlitSurface(ennemi.fondd,NULL, ecran,&ennemi.position);
	break ;

case 5:
SDL_BlitSurface(ennemi.fond1,NULL, ecran,&ennemi.position);
	break ;
case 6:
SDL_BlitSurface(ennemi.fond2,NULL, ecran,&ennemi.position);
	break ;
case 7:
SDL_BlitSurface(ennemi.fond3,NULL, ecran,&ennemi.position);
	break ;
case 8:
SDL_BlitSurface(ennemi.fond4,NULL, ecran,&ennemi.position);
	break ;
}
}
void attacking(SDL_Rect *position,int *i){
if((*i)<45){
	position->y-=15;
	(*i)++;
}else{
	(*i)=0;
	position->y=610;
}
}


void attackinggg(SDL_Rect *position,SDL_Rect pos_enemy,int *i){
if((*i)<4){
	position->x-=5;
	(*i)++;
}else{
	(*i)=0;
	position->x=pos_enemy.x;
}
}


void inarti(int x, SDL_Rect *pos_enemy ,int *k ,SDL_Rect *pos_bullet ){



if((pos_enemy->x-x<300&&pos_enemy->x-x>0)||(x-pos_enemy->x<300&&x-pos_enemy->x>0))
{
(pos_enemy->x)--;

attackinggg(pos_bullet,*pos_enemy,k);

printf("positi pos_bulletkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk   %d    posenemi        %d\n\n\n\n\n\n",pos_bullet->x,pos_enemy->x );

}

printf("positi sprite               %d\n\n\n\n\n",x );


}
