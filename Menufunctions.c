#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
 #include"Menu1.h"
void animationpressanykeytoenter(SDL_Surface *ecran ){            
int press;
press=1;
char chemin[][50]={"../newgame/menures/1.png","../newgame/menures/2.png","../newgame/menures/3.png","../newgame/menures/4.png","../newgame/menures/5.png","../newgame/menures/11.png","../newgame/menures/6.png","../newgame/menures/7.png","../newgame/menures/8.png","../newgame/menures/13.png","../newgame/menures/9.png","../newgame/menures/12.Png"};
SDL_Surface *image=NULL;
SDL_Event event;
while(press){
for(int i=0;i<11;i++){
image= IMG_Load(chemin[i]);
SDL_BlitSurface(image,NULL, ecran,0 );
                    SDL_Flip(ecran);

SDL_PollEvent(&event);
if(event.type==SDL_QUIT){
 SDL_Quit();
}
if(event.type==SDL_KEYDOWN){
press=0;
break;
}
}}
SDL_FreeSurface(image);}
background initialiserBackground (char* chemin,int x,int y){
background b;
b.fond=IMG_Load(chemin);
b.positionFond.x=x;
b.positionFond.y=y;
return b;
}
Menu InitialiserMenu(background b){
Menu m;
m.b=b;
m.but=Mix_LoadMUS("../newgame/menures/button.wav");
return m;
}
void AfficherMenu(Menu m,SDL_Surface *ecran ){	 
//Mix_AllocateChannels(20);
//Mix_PlayMusic(m.b.musique, -1);
//Mix_VolumeMusic(MIX_MAX_VOLUME/1);
SDL_BlitSurface(m.b.fond,NULL,ecran,0);
SDL_Flip(ecran);
                    SDL_Delay(10);
}

void updateMenu(SDL_Surface *ecran)
{
Mix_Chunk *but;
int press;
press=1;
int cont;
cont=1;
int i=0;
SDL_Surface *image=NULL,*image1=NULL,*image2=NULL,*image3=NULL,*image4=NULL;
image= IMG_Load("../newgame/menures/menu1.png");
image2= IMG_Load("../newgame/menures/menu2.png");
image3= IMG_Load("../newgame/menures/menu3.png");
image4= IMG_Load("../newgame/menures/menu0.png");
SDL_Event event;

but=Mix_LoadWAV("../newgame/menures/button.wav");
while(cont){
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN:

switch(event.key.keysym.sym)
            {

            case SDLK_RETURN: 
if (i==1)
                { 
game(ecran);


                }
                else if (i==2)
                {
                }
                else if (i==3)
                {
                    cont=0;
                }

                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                
                }
                if(i==1)
                {

                    SDL_BlitSurface(image,NULL, ecran,0);
                    SDL_Flip(ecran);
               
     Mix_PlayChannel(1,but,0);
                    SDL_Delay(100);

                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran,0);
                    SDL_Flip(ecran);
     Mix_PlayChannel(1, but, 0);
SDL_Delay(100);
Mix_PlayChannel(1, but, 0);     
           }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, 0);
                    SDL_Flip(ecran);
     Mix_PlayChannel(1, but, 0);
SDL_Delay(100);
Mix_PlayChannel(1, but, 0);
                }
                break;
            case SDLK_UP: 
                i--;
                if(i<0)
                {
                 	   i=3;
                }
                
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran,0);
                    SDL_Flip(ecran);
     Mix_PlayChannel(1, but, 0);
SDL_Delay(100);
Mix_PlayChannel(1, but, 0);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran,0);
                    SDL_Flip(ecran);
     Mix_PlayChannel(1, but, 0);
SDL_Delay(100);
Mix_PlayChannel(1, but, 0);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran,0);
                    SDL_Flip(ecran);
SDL_Delay(100);
Mix_PlayChannel(1, but, 0);
                }
                break;        
}
}
 
}}

