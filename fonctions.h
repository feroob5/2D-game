#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct 
{
SDL_Surface *fond;
SDL_Rect positionFond;
}Background;

typedef struct 
{
SDL_Surface *img[2];
int num;
SDL_Rect position;
Mix_Chunk *scratch;
}Boutton;

typedef struct 
{
Background b;
int nbrB;
Boutton tab[5];
int numBA; //i
}Menu;

/*int updateMenu(int c, int j,Menu m);*/
Boutton initialiserBoutton(char* chemin1,char* chemin2,int x,int y);
int mot(char ch[],SDL_Surface *ecran,int *a);
int enigme2(SDL_Surface *ecran,int *a);

#endif // FONCTIONS_H_INCLUDED
