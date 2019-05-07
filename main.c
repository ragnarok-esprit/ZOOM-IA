#include "fonction.h"

#include <SDL/SDL_rotozoom.h>

void game (SDL_Surface *ecran){
int jumping=0;
int attacksync=0;
int mjump=0;
int mvm=100;
int fall=0;
int aideenem1=1;
int aideenem2=0;
int numkeys;
int charcattacking=0;
int answer=2;
int azer=0;
int hp[100];
int ques=0;
int posmax=1200;
int pit=0;
int plat=0;
double angle=0,zoomox=1;
//nourrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
/*SDL_Rect pos_enemy;
SDL_Rect pos_bullet;
pos_enemy.y=550;
pos_enemy.x=6500;
pos_bullet.y=560;
pos_bullet.x=6365;
*/
//SDL_Surface *green=NULL;
//SDL_Surface *brown=NULL;
int k=0;

//green=IMG_Load("xa.png");
//brown=IMG_Load("poopatc.png");



///////////////////////////////////////////////////////////////////////////////////////////////////

int posmin=1000;
enigme e;
int sol,r,run =1,running=1,alea;
char image[30]="";
int attackingnow=0;
int hpnumber=0;
perso perso ;
int portals=0;
int hit[100];
int status=0;
int falling=0;
int collisiopill=0;
int startplat[100],endplat[100],haut[100];
int lastpos=0;
int collisiontumeur=0;
int collisionenuron=0;
int d=0,q=0,s=0,jump=0,x=0,y=1;
int mvmspeed=20;
int jumpspeed=30;
int jumpheight=20;
ennemis firstenm ;
Objet attackcharc;
Objet tumor,pill,neuron,enemipoop,poopattack,green,brown,red,rood;
int continuer = 1;
int gravit=435;
int saut=1;
vie vie;
int debut[3];
int fin[3];
debut[0]=2195;
fin[0]=2523;
debut[1]=7205;
fin[1]=7517;
SDL_Rect positionp;
positionp.x=11000;
positionp.y=100;
debut[2]=9139;
fin[2]=11521;
initialiservie(&vie) ;
startplat[0]=2000;
haut[0]=180;
endplat[0]=2300;
//nour*************************************************
char path_ennemi [500] = "ennemi_spr.png";
Ennemi ennemie;
int ie;
/*
double *a;
double *r;
SDL_Surface *kalb=NULL;*/


Objet logox;

SDL_Surface *logono=NULL;
logono=IMG_Load("kalb.png");

int ennmouv,w=10;
SDL_Rect camera;
int prevd,prevq;
SDL_Surface *imageback=NULL;
SDL_Event event;
initialiserennemi(&firstenm);
//nour**********************************
ie = init_ennemi(&ennemie, path_ennemi);

imageback=Init_imagedefond(imageback ,&camera ,0, 0 );
initialiserperso(&perso);
 init_enigme(&e);
initialiserObj(&neuron,"../newgame/map/neuron.png",2700 ,435 );
initialiserObj(&attackcharc,"../newgame/charc/attack.png",-100 ,-100 );
initialiserObj(&pill ,"../newgame/map/pill1.png", 2350, 210 );
initialiserObj(&tumor ,"../newgame/map/tumor.png", 600,500 );
initialiserObj(&enemipoop ,"../newgame/charc/virus2.png", 3200,600 );
initialiserObj(&poopattack,"../newgame/charc/poopatc.png", 3250,610);
initialiserObj(&green,"xa.png",6000,550);
initialiserObj(&brown,"poopatc.png",5900,550);

initialiserObj(&logox,"kalb.png",50,50);

while(continuer)
{
falling=0;
	    running=1,r=0 ;
SDL_PollEvent(&event);
switch(event.type)
  	{
        case SDL_QUIT:
            continuer = 0;
	case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            			case SDLK_LEFT :
		q=1;	
                    	break ;

		case SDLK_RIGHT :
		d=1; 
			break ;
			case SDLK_LCTRL:

charcattacking=1;
			break;
		case SDLK_UP :
		jump=1; 
			break ;
	    }
		break;
	case SDL_KEYUP:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		    //continuer=0 ;
			break ;
				case SDLK_LCTRL:

charcattacking=0;
			break;
		

		case SDLK_LEFT :
		q=0;	
                    	break ;

		case SDLK_RIGHT :
		d=0; 
			break ;
		case SDLK_UP :
		jump=0; 
			break ;
	    }
		break;
}
SDL_Delay(20);


/////////// ZOOOOOOOOOOOOOOOOOOOM nourrrrrrrrrrrrrrrrrrrrrr
if(angle<361){
	//logox.image=zoom(&angle,&zoomox,logono);

angle+=5;
zoomox+=0.01;
logox.image=rotozoomSurface(logono,angle,zoomox,1);

}








if(pit==0&&plat==0)
gravit=435;
plat=collisionplatform(startplat,endplat,&gravit,1,perso.position,camera ,haut);
pit=collisionpit(debut,fin,&gravit,3,perso.position,camera);

mvmspeed=mvm;

if(perso.position.x+camera.x>=11250&&answer==2){
    
 generate_afficher ( ecran  , image ,&e,&alea) ;
      sol=solution_e (image,&ques);	
		r=resolution (&running,&run);
			answer=afficher_resultat(ecran,sol,r,&e,ques) ;
}
if(answer==1)
vie.nb++;
gravity(&perso.position,gravit,jump,&jumping,jumpspeed,&fall,falling);
jumpin(&perso.position,&camera,jump,&jumping,jumpheight,jumpspeed,&fall,d,q,&mvm);
x=mouv(d,q,jumping,falling,x,perso,prevd,prevq);
collisionenuron=collisionbb(perso.position,neuron.position,camera);
if(collisionenuron==1){
	mvmspeed=10;
}
collisiopill=collisionbb(perso.position,pill.position,camera);
if(collisiopill==1){
	mvm=60;
	pill.position.y=-50;
	pill.position.x=-50;
}

collisiontumeur=collisionbb(perso.position,tumor.position,camera);
if(collisiontumeur==1&&d==1)
perso.position.x-=30;
else if(collisiontumeur==1&&q==1)
	perso.position.x+=30;
mouvement(&perso.position,&camera,d,q,mvmspeed);
y=splitennemi(y);



//fffffffffffffffffffffffffffffffffffffffffffffffffffffffff
attacking(&poopattack.position,&attacksync);


		




hp[0]=collisionbb(perso.position,poopattack.position,camera);
hp[1]=collisionbb(perso.position,enemipoop.position,camera);
if(perso.position.y>=550){
	hp[3]=1;
}else 
hp[3]=0;
printf("ennemis %d perso %d,gravity %d\n" ,perso.position.y,perso.position.x,gravit);

//hp[2]=0;
hp[2]=collisionbb(perso.position,firstenm.position,camera);
Health(&vie,hp,&camera,&perso.position,&firstenm.position,4);







if(charcattacking==1&&attackingnow==0){
attackcharc.position.x=perso.position.x+camera.x+60;
attackcharc.position.y=perso.position.y+30;
attackingnow=30;
}
if (attackingnow==0&&charcattacking==0)
{
attackcharc.position.x=-500;

}
SDL_BlitSurface(imageback, &camera, ecran, NULL);
if(attackingnow>0){
	attackcharc.position.x+=100;
	attackingnow--;
}
hit[0]=collisionbb(attackcharc.position,firstenm.position,camera);
if(hit[0]==1){
printf("boucle\n");
	firstenm.position.x=-5000;
	firstenm.position.y=-4000;

}
firstenm=mouvennemi(firstenm,perso,d,q,camera,ecran,&posmin,&posmax,&y,mvmspeed,&lastpos,&aideenem1,&aideenem2);
//collisionennemi(&perso,&firstenm,&camera,&vie);



///// nourr////////////////////////////////////
update_ennemi(&ennemie, perso.position);

//////////////////////////////////////////////////////////////////////////////////////////////////
portal(&portals,positionp,ecran,camera);
affichageObj(attackcharc,ecran,camera);
affichageObj(pill , ecran,camera) ;
affichageObj(poopattack,ecran,camera) ;
affichageObj(enemipoop, ecran,camera) ;

affichageObj(neuron , ecran,camera);
afficherperso(perso,ecran,x);
affichervie(&vie,perso,ecran);
afficherennemi(firstenm,ecran,y,camera);
/////////////////////////////////////nouuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuurr;)
display_ennemi(ennemie,ecran);
affichageObj(logox, ecran,camera) ;


prevd = d;
prevq = q;
affichageObj(tumor , ecran,camera) ;
SDL_Flip(ecran);
}
SDL_FreeSurface(imageback);  
freefurfaceperso(&perso);
freesurfaceennemi(&firstenm);
freesurfaceobject(&pill);
freesurfaceobject(&attackcharc);
freesurfaceobject(&poopattack);
freesurfaceobject(&tumor);
freesurfaceobject(&enemipoop);
freesurfaceobject(&neuron);
freesurfaceobject(&logox);
SDL_Quit();
}













