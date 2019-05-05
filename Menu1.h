#ifndef _Menu1_H
#define _Menu1_H

#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_rotozoom.h> 

typedef struct 
{
SDL_Surface *fond;
SDL_Rect positionFond;
}background;

typedef struct 
{
SDL_Surface *img[2];
int num;
SDL_Rect position;
}Boutton;

typedef struct 
{
background b;
int nbrB;
Boutton tab[5];
int numBA; //i 
}Menu;

void pause();
background initialiserBackground(char* chemin,int x,int y);
Boutton initialiserBoutton(char* chemin1,char* chemin2,int x,int y);
Boutton initialiserBouttonenigme(char* chemin1,char* chemin2,int x,int y);
Menu initialiserMenu(background b,int num);
void AfficherMenuprincipale(Menu m,SDL_Surface *ecran);
void AfficherMenuprincipalenomusic(Menu m,SDL_Surface *ecran);
void AfficherMenu1(Menu m,SDL_Surface *ecran);
void AfficherMenu2(Menu m,SDL_Surface *ecran);
void AfficherMenu3(Menu m,SDL_Surface *ecran);
void AfficherMenu4(Menu m,SDL_Surface *ecran);
void AfficherMenuNG(Menu m,SDL_Surface *ecran);
void AfficherMenuNG1(Menu m,SDL_Surface *ecran);
void AfficherMenuNG2(Menu m,SDL_Surface *ecran);
void AfficherMenuNG3(Menu m,SDL_Surface *ecran);
void AfficherMenuSETT(Menu m,SDL_Surface *ecran);
void AfficherMenuSETT1(Menu m,SDL_Surface *ecran);
void AfficherMenuSETT2(Menu m,SDL_Surface *ecran);
void AfficherMenuSETT3(Menu m,SDL_Surface *ecran);
void AfficherMenuNGnomusic (Menu m,SDL_Surface *ecran);
void AfficherMenuprincipalenomusic(Menu m,SDL_Surface *ecran);
int updateBouttonMenuP(int c,Menu m);
int updateMenuNG(int c,Menu m);
int updateBouttonMenuNG(int i,Menu m);
int updateBouttonMenuSETT(int p,Menu m);
int updateBack(int r,Menu m, int k);
SDL_Surface *rotozoomSurface(SDL_Surface * src, double angle, double zoom, int smooth);
int mot(char ch[],SDL_Surface *ecran,int *a);

int enigme2(SDL_Surface *ecran,int *a);

#endif 
