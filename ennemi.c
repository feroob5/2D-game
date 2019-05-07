/**
* @file ennemi.c
*/
#include "ennemi.h"
#include "hero.h"
#include <math.h>

/**
* @brief To initialize ennemi E .
* @param E the ennemi
* @param path is the path of the images
* @return ok if init went ok 
*/

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

/**
* @brief To load ennemi images
* @param A the ennemi
* @param path the path of images
* @return 1 or 0
*/

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

	E->positionAbsolue.x = 0.5 * BACKGND_W;
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
	E->distance=0 ;
	
}

/**
* @brief To display ennemi
* @param E the ennemi
* @param screen is the screen window 
* @return Nothing
*/

void display_ennemi(Ennemi E, SDL_Surface* screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation[E.Frame.i][E.Frame.j], screen, &E.positionAbsolue);
}
/**
* @brief To animate the ennemi
* @param E the ennemi
* @param distEH distance between hero and ennemi
* @return Nothing
*/
void animateEnnemi(Ennemi* E,int distEH)
{
	// mise a jour du numero de ligne de l'imagette 
	// si l'ennemi n'est pas en train d'attaquer --> ligne = 1
	if(distEH<0)
	{
		if (E->State!=ATTACKING)
			E->Frame.i = 0 ;
	// si l'ennemi est  en train d'attaquer --> ligne = 3

		else if(E->State==ATTACKING)
			E->Frame.i = 2 ;
	}
	else 
	{
		if (E->State!=ATTACKING)
			E->Frame.i = 1 ;
	

		else if(E->State==ATTACKING)
			E->Frame.i = 3 ;
	}

	 
	// mise a jour du numero de colonne de l'imagette pour avoir l'effet de l'animation
	
	E->Frame.j ++;    
	if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
		 E->Frame.j = 0;  
	SDL_Delay(50);	
}

/**
* @brief To make ennemi move
* @param E the ennemi
* @param posHero is the position of the hero
* @return 1 or 0
*/

void moveEnnemi(Ennemi *E, SDL_Rect posHero)
{
	
		if (posHero.x<E->positionAbsolue.x) //hero à gauche de l'ennemi
		{
        	E->positionAbsolue.x -= 8; 
		}
		else // hero a droite de l'ennemi 
		{
			E->positionAbsolue.x += 8;
		}
	
}

/**
* @brief To move the ennemi randomly 
* @param E the ennemi
* @return Nothing
*/

void moveEnnemiAleatoire(Ennemi *E)
{
				if(E->Direction==0)
				{
        			E->Frame.i=0;
        			E->Frame.j++;
        			if(E->Frame.j==SPRITE_ENNEMI_NbCol)
        			{
        				E->Frame.j=0 ;
        				//ok=1 ;
        			}
        		}
        		else 
        		{
        			E->Frame.i=1;
        			E->Frame.j++;
        			if(E->Frame.j==SPRITE_ENNEMI_NbCol)
        			{
        				E->Frame.j=0 ;
        				//ok=0 ;
        			}
        		}
        		
        		E->distance++;
        		if(E->Direction==1)
        		{
        			E->positionAbsolue.x-=50 ;
        			
        			if(E->distance >= 3) 
        			{// le probleme
        				E->Direction=0 ;
        				E->distance=0 ;
        			}
        		}
        		else 
        		{
        			E->positionAbsolue.x+=50;
        			
        			if(E->distance >= 3)
        			{// le probleme
        				E->Direction=1 ;
        				E->distance=0 ;
        			}
        		}
        		printf(" La direction est %d \n",E->Direction );
        		SDL_Delay(100);
        		
        		
}

        		
/**
* @brief To update ennemi
* @param E the ennemi
* @param posHero the position of the hero
* @return Nothing
*/


void update_ennemi(Ennemi* E, SDL_Rect posHero)
{
	
	int distEH = E->positionAbsolue.x - (posHero.x + Hero_WIDTH);
	printf("distEH = %d\t E->State = %d\n", distEH,E->State);
    	switch(E->State)
    	{
        	case WAITING :
        	{
            		animateEnnemi(E,distEH);
            		break;
        	}

        	case FOLLOWING :
        	{
            		animateEnnemi(E,distEH);
            		moveEnnemi(E,posHero);
            		break;
        	}

        	case ATTACKING :
        	{
			// Attaque en se déplaçant vers l'ennemi
		    	animateEnnemi(E,distEH);
				moveEnnemi(E,posHero);
			break;
        	}  
        	case MOVING :
        	{
        		moveEnnemiAleatoire(E);
        		break ;
        	} 
    	}
      
	updateEnnemiState(E, abs(distEH));	
	
}

/**
* @brief To update Ennemi state
* @param E the ennemi
* @param distEH distance between hero and ennemi
* @return nothing
*/

void updateEnnemiState(Ennemi* E, int distEH)
{
	
	switch(E->State)
	{
	case WAITING :
		if(300<distEH && distEH<=600)
			E->State=MOVING ;
		break ;
	case MOVING : 
		if(distEH>600)
			E->State=WAITING ;
		else if(100<distEH && distEH<=300)
			E->State=FOLLOWING ;
		break ;
	case FOLLOWING :
		if(300<distEH && distEH<=600)
			E->State=MOVING ;
		else if(0<distEH && distEH<=100)
			E->State=ATTACKING ;
		break ;
	case ATTACKING :
		if(100<distEH && distEH<=300)
			E->State=FOLLOWING ;
		break ;
	}
	
}


/*********************************************************/
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}
