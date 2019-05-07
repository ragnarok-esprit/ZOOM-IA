#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "object.h"


#include "collision.h"
#include "ennemi.h"
#include "background.h"
#include "jump.h"
#include "playermov.h"
#include "utility.h"
#include "rot.h"
#include "ia.h"

void game (SDL_Surface *ecran);
