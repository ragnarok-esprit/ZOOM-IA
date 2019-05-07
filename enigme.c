

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"

int enigm(SDL_Surface *screen)
{ SDL_Event event;	 
int answer=2;
	 SDL_Init ( SDL_INIT_VIDEO ) ;



	 
	
	 while (run)
	 {
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }	
        	
if(answer==1||answer==2)
return answer ;
			       SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					     case SDL_QUIT :
                              running =0 ;
						      run=0 ;
					     break ;
                         case SDL_KEYDOWN :
						    
                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE: 
			                           running= 0 ;
			                        break ;
			                      }
						 break ;
                       }
                    } 	
   }
      SDL_Quit();
}
