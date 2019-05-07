#include "fonction.h"
 #include "playermov.h"
void initialiserperso(perso *perso)
{
perso->a=0;
perso->position.x = 100 ;
perso->position.y = 435 ;

perso->fond00 = IMG_Load("../newgame/charc/1.png");
perso->fond0 = IMG_Load("../newgame/charc/2.png");
perso->fond1 = IMG_Load("../newgame/charc/3.png");
perso->fond2 = IMG_Load("../newgame/charc/4.png");
perso->fond3 = IMG_Load("../newgame/charc/5.png");
perso->fond4 = IMG_Load("../newgame/charc/6.png");
perso->fonda = IMG_Load("../newgame/charc/8.png");
perso->fondb = IMG_Load("../newgame/charc/9.png");
perso->fondd = IMG_Load("../newgame/charc/10.png");
perso->fonde = IMG_Load("../newgame/charc/7.png");
perso->fond100 = IMG_Load("../newgame/charc/11.png");
perso->fond10 = IMG_Load("../newgame/charc/12.png");
perso->fond11 = IMG_Load("../newgame/charc/13.png");
perso->fond12 = IMG_Load("../newgame/charc/14.png");
perso->fond13 = IMG_Load("../newgame/charc/15.png");
perso->fond14 = IMG_Load("../newgame/charc/16.png");
perso->fond1a = IMG_Load("../newgame/charc/17.png");
perso->fond1b = IMG_Load("../newgame/charc/18.png");
perso->fond1d = IMG_Load("../newgame/charc/19.png");
perso->fond1e = IMG_Load("../newgame/charc/20.png");
perso->position.h=perso->fond00->h;
perso->position.w=perso->fond00->w;
}


void freefurfaceperso(perso *perso)
{
SDL_FreeSurface(perso->fond00);
SDL_FreeSurface(perso->fond0);
SDL_FreeSurface(perso->fond1);
SDL_FreeSurface(perso->fond2);
SDL_FreeSurface(perso->fond3);
SDL_FreeSurface(perso->fonda);
SDL_FreeSurface(perso->fondb);
SDL_FreeSurface(perso->fondc);
SDL_FreeSurface(perso->fond4);
SDL_FreeSurface(perso->fondd);
SDL_FreeSurface(perso->fonde);
SDL_FreeSurface(perso->fond100);
SDL_FreeSurface(perso->fond10);
SDL_FreeSurface(perso->fond11);
SDL_FreeSurface(perso->fond12);
SDL_FreeSurface(perso->fond13);
SDL_FreeSurface(perso->fond1a);
SDL_FreeSurface(perso->fond1b);
SDL_FreeSurface(perso->fond1c);
SDL_FreeSurface(perso->fond14);
SDL_FreeSurface(perso->fond1e);

}
int mouv(int d,int q,int z,int s,int x,perso perso,int prevd,int prevq)
{
if(d==0&&q==0)
{
if(prevq==1)
x=20;
else
x=10;
}
if(z!=0){
	if(prevq==1)
	x=13;
else 
	x=4;
}else if(s==1){
	if(prevq==1)
	x=11;
else
	x=1;
}
else if(d==1)
{
switch(x)
{
case 10:
x=1;
	break;
case 1:
x=2;
	break;
case 2:
x=3;
	break;
case 3:
x=4;
	break;
case 4:
x=5;
	break;
	case 5:
x=6;
break;
case 6:
x=7;
break;
case 7:
x=9;
break;
case 8:
x=9;
break;
case 9:
x=1;
break;
default:
x=10;
break;


}
}

else if(q==1)
{
	switch(x){
case 20:
x=11;
	break;
case 11:
x=12;
	break;
case 12:
x=13;
	break;
case 13:
x=14;
	break;
case 14:
x=15;
	break;
	case 15:
x=16;
break;
case 16:
x=17;
break;
case 17:
x=18;
break;
case 18:
x=19;
break;
case 19:
x=11;
break;
default:
x=20;
break;
}	}
return x ;
}



void afficherperso(perso perso,SDL_Surface *ecran,int x)
{
switch(x)
{
case 0:
SDL_BlitSurface(perso.fond00,NULL, ecran,&perso.position);
	break ;
case 1:
SDL_BlitSurface(perso.fond0,NULL, ecran,&perso.position);
	break ;
case 2:
SDL_BlitSurface(perso.fond1,NULL, ecran,&perso.position);
	break ;
case 3:
SDL_BlitSurface(perso.fond2,NULL, ecran,&perso.position);
	break ;
case 4:
SDL_BlitSurface(perso.fond3,NULL, ecran,&perso.position);
	break ;
case 5:
SDL_BlitSurface(perso.fond4,NULL, ecran,&perso.position);
	break ;
case 6:
SDL_BlitSurface(perso.fonda,NULL, ecran,&perso.position);
	break ;
case 7:
SDL_BlitSurface(perso.fondb,NULL, ecran,&perso.position);
	break ;
case 8:
SDL_BlitSurface(perso.fondc,NULL, ecran,&perso.position);
	break ;
case 9:
SDL_BlitSurface(perso.fondd,NULL, ecran,&perso.position);
	break ;

case 10:
SDL_BlitSurface(perso.fonde,NULL, ecran,&perso.position);
	break ;
case 11:
SDL_BlitSurface(perso.fond100,NULL, ecran,&perso.position);
	break ;
case 12:
SDL_BlitSurface(perso.fond10,NULL, ecran,&perso.position);
	break ;
case 13:
SDL_BlitSurface(perso.fond11,NULL, ecran,&perso.position);
	break ;
case 14:
SDL_BlitSurface(perso.fond12,NULL, ecran,&perso.position);
	break ;
case 15:
SDL_BlitSurface(perso.fond13,NULL, ecran,&perso.position);
	break ;
case 16:
SDL_BlitSurface(perso.fond14,NULL, ecran,&perso.position);
	break ;
case 17:
SDL_BlitSurface(perso.fond1a,NULL, ecran,&perso.position);
	break ;
case 18:
SDL_BlitSurface(perso.fond1b,NULL, ecran,&perso.position);
	break ;
case 19:
SDL_BlitSurface(perso.fond1d,NULL, ecran,&perso.position);
	break ;

case 20:
SDL_BlitSurface(perso.fond1e,NULL, ecran,&perso.position);
	break ;
}
}

void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x = 0 ;
vie->position.y = 0 ;
vie->position2.x = 0 ;
vie->position2.y = 0 ;
vie->fond1 = IMG_Load("../newgame/charc/v1.png");
vie->fond2 = IMG_Load("../newgame/charc/v2.png");
vie->fond3 = IMG_Load("../newgame/charc/v3.png");
vie->fond4 = IMG_Load("../newgame/charc/v4.png");
vie->fond5 = IMG_Load("../newgame/charc/GameOver.png");
}
void freesurfacevie(vie *vie)
{
SDL_FreeSurface(vie->fond1);
SDL_FreeSurface(vie->fond2);
SDL_FreeSurface(vie->fond3);
SDL_FreeSurface(vie->fond4);
SDL_FreeSurface(vie->fond5);
}

void affichervie(vie *vie,perso perso,SDL_Surface *ecran)
{
vie->position.x=perso.position.x-30;
vie->position.y=perso.position.y-40;
if(vie->nb==3)
{
SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);
}
if(vie->nb==0)
{
SDL_BlitSurface(vie->fond4,NULL, ecran,&vie->position);
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position2);

vie->nb=3;
SDL_Flip(ecran);
SDL_Delay(2000);
}
}
void mouvement(SDL_Rect *position,SDL_Rect *camera,int d,int q,int mvmspeed)
{
	(*camera)=collision((*camera));
if(camera->x>=0&&camera->x<=11000)
{
	if(d==1){
	if  (position->x>=600 && camera->x<=10600)
            camera->x += mvmspeed/2;
        else if (position->x<=1190)
            position->x +=mvmspeed;
(*camera)=collision((*camera));
}
if(q==1){
	if(position->x<=250 && camera->x>=0)
            camera->x -= mvmspeed/2;
        else if (position->x>=0) 
            position->x -=mvmspeed;
        (*camera)=collision((*camera));
}
}
}
void jumpin(SDL_Rect *position,SDL_Rect *camera,int jump,int *i,int jumpheight,int jumpspeed,int *falling,int d,int q,int *mvmspeed){
    int lateralspeed = 0.5;
    int airlateralspeedfacteur = 0.5;

if((jump==1||(*i)!=0)&&((*i)<jumpheight)&&(*falling)==0){
	position->y-=jumpspeed-(*i);
	(*i)++;
        jumpspeed*= airlateralspeedfacteur;

}else{
	(*i)=0;
	(*falling)=1;
}
printf("falling%d\n",(*falling));
}
void gravity(SDL_Rect *positionchar,int gravity,int a,int *jumping,int jumpspeed,int *falling,int fall){
if((*falling)==1){	

	 if(positionchar->y<gravity)
{
	      
	positionchar->y+=jumpspeed;
	fall=1;
}else
	 	(*falling)=0;
}

}
