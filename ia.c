#include "ia.h"


int init_ennemi(Ennemi* E, char* path)
{
	int OK;

	OK = loadEnnemiImages(E, path);
	if (OK != -1)
	{
		initEnnemiAttributes(E);
	}
	
	return OK;
}


int loadEnnemiImages(Ennemi * A, char* path)
{
	A->image = IMG_Load(path);

	if(A->image == NULL) {
		printf("Unable to load Ennemi png:%s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}


void initEnnemiAttributes(Ennemi* E)
{	
	int i, j;	

	E->positionAbsolue.x = 0.55 * BACKGND_W;
	E->positionAbsolue.y = 0.8 * BACKGND_H - Ennemi_HEIGHT;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	
	E->Frame.i = 1;
	E->Frame.j = 0;
	
        // Faire le calcul des SDL_Rect des positions de toutes 
	// les imagettes une seule fois à l'initialisation
	for (i = 0; i < SPRITE_ENNEMI_NbL; i++)
	{	for(j = 0; j < SPRITE_ENNEMI_NbCol; j++)
		{	
			E->positionAnimation[i][j].x = j * Ennemi_WIDTH;
			E->positionAnimation[i][j].y = i * Ennemi_HEIGHT;
			E->positionAnimation[i][j].w = Ennemi_WIDTH;  
			E->positionAnimation[i][j].h = Ennemi_HEIGHT;
		}
	}
	E->Direction = 1;
	E->State = WAITING;
	
}

void display_ennemi(Ennemi E, SDL_Surface* screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation[E.Frame.i][E.Frame.j], screen, &E.positionAbsolue);
}

void animateEnnemi(Ennemi* E)
{
	printf("E->D %d\n",E->Direction);
	if(E->State == FOLLOWING || E->State == WAITING){
		if(E->Direction)
			E->Frame.i = 1;
		else
			E->Frame.i = 0;
		E->Frame.j ++;    
		if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
			E->Frame.j = 0;  
			SDL_Delay(50);	
	}
	else if( E->State == ATTACKING  ){
		if(E->Direction)
			E->Frame.i = 3;
		else
			E->Frame.i = 2;	
		E->Frame.j ++;    
		if (E->Frame.j == SPRITE_ENNEMI_NbCol){
			E->Frame.j = 0;  
			SDL_Delay(50);	
		}	
	}
}


void moveEnnemi(Ennemi *E, SDL_Rect posHero, SDL_Rect camera)
{
	if (posHero.x<E->positionAbsolue.x) //hero à gauche de l'ennemi
	{
        	E->positionAbsolue.x -= 5; 
E->Direction = 1;
	}
	if (posHero.x>E->positionAbsolue.x) //hero à droite de l'ennemi
	{
E->positionAbsolue.x += 8; 
E->Direction = 0; 

	}
}

void update_ennemi(Ennemi* E, SDL_Rect posHero)
{SDL_Rect camera;
	int distEH = E->positionAbsolue.x - (posHero.x + Hero_WIDTH);
	printf("distEH = %d\t E->State = %d\n", distEH,E->State);
    	switch(E->State)
    	{
        	case WAITING :
        	{
            		animateEnnemi(E);
            		break;
        	}

        	case FOLLOWING :
        	{
            		animateEnnemi(E);
            		moveEnnemi(E,posHero,camera);
            		break;
        	}

        	case ATTACKING :
        	{
			// Attaque en se déplaçant vers l'ennemi
		    	animateEnnemi(E);
			moveEnnemi(E,posHero,camera);
			break;
        	}       
    	}

	updateEnnemiState(E, distEH);	
}


void updateEnnemiState(Ennemi* E, int distEH){
	if(distEH>300)
		E->State = WAITING;
	else
		if(299>distEH>150)
			E->State = FOLLOWING;
		else
			E->State = ATTACKING;
}

/*********************************************************/
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}
