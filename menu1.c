#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include"Menu1.h"
#include "fonction.h"
int main()
{
Menu m;
SDL_Init(SDL_INIT_VIDEO);   
SDL_Surface *ecran =NULL;
ecran=SDL_SetVideoMode(1370, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
background b;
SDL_WM_SetCaption("Nano-Doc", NULL);
b=initialiserBackground("../newgame/menures/menu0.png",0,0);
m=InitialiserMenu(b);
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
Mix_Music *musique;
Mix_AllocateChannels(20);
musique = Mix_LoadMUS("../newgame/menures/music1.mp3");
Mix_PlayMusic(musique, -1);
Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
SDL_Event event;
animationpressanykeytoenter(ecran);
Mix_FreeMusic(musique);
musique = Mix_LoadMUS("../newgame/menures/music.mp3");
Mix_PlayMusic(musique, -1);
AfficherMenu(m,ecran); 
updateMenu(ecran);
Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_Quit(); 
return EXIT_SUCCESS;
}
