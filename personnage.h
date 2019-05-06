#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
/**
*@file personnage.h
*/

/**
*@struct PERSO_PRINCIPALE
*@brief struct  Personnage principale
*/
typedef struct PERSO_PRINCIPALE
{
	int vie;
	int score;
    int position_actuel;/*!<La position actuelle du personnage*/
    SDL_Rect position; /*!<Rectangle*/
    SDL_Surface *tab[16];/*!<Surface*/

}PERSO_PRINCIPALE;

/**
*@struct Score
*@brief struct  Score du jeu
*/
typedef struct Score
{
    SDL_Surface *text;/*!<Surface du text*/
    SDL_Rect position;/*!<Rectangle*/
    int nb;/*!<le score*/
    TTF_Font *police;/*!<police de l'ecriture du texte*/
    char scoretexte[20];
	
}Score;

/**
*@struct Health
*@brief struct vie
*/
typedef struct Health
{
int nb;
SDL_Rect position;/*!<Rectangle*/
SDL_Surface *health[7];/*!<tableau des photos du sang*/
SDL_Surface *lose;/*!image de GAME OVER*/
}Health;


#endif
