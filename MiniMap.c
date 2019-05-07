#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "MiniMap.h"

void littledot(PERSO_PRINCIPALE p,SDL_Surface *ecran,int resultat1,int resultat2)
{
	SDL_Surface *dot=NULL,*map=NULL,*enigme1=NULL,*enigme2=NULL;
	SDL_Rect positionm,positiond,positione1,positione2;
	positionm.x =0;
    positionm.y =0;
    positiond.x =5;
    positiond.y =p.position_actuel.y/10;
	dot=IMG_Load("dot.png");
    map=IMG_Load("MiniMap.png");
    map=rotozoomSurface(map,0,0.18,0.11);
    dot=rotozoomSurface(dot,0,0.18,0.11);
    SDL_BlitSurface(map,NULL,ecran,&positionm);
    SDL_BlitSurface(dot,NULL,ecran,&positiond);
    //blit des indication des enigmes au propos du resultats des enigmes
    if(resultat1==0)
    {
    	enigme1=IMG_Load("indication_enigme_noir.png");
    }
    else if(resultat1==-1)
    {
    	enigme1=IMG_Load("indication_enigme_rouge.png");
    }
    else if(resultat1==1)
    {
    	enigme1=IMG_Load("indication_enigme_vert.png");
    }
    position1.x =50;
    position1.y =0;
    enigme1=rotozoomSurface(enigme1,0,0.18,0.11);
    SDL_BlitSurface(enigme1,NULL,ecran,&position1);
    if(resultat2==0)
    {
    	enigme2=IMG_Load("indication_enigme_noir.png");
    }
    else if(resultat2==-1)
    {
    	enigme2=IMG_Load("indication_enigme_rouge.png");
    }
    else if(resultat2==1)
    {
    	enigme2=IMG_Load("indication_enigme_vert.png");
    }
    position1.x =100;
    position1.y =0;
    enigme2=rotozoomSurface(enigme2,0,0.18,0.11);
    SDL_BlitSurface(enigme2,NULL,ecran,&position2);
  
}