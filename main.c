#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"
#include <SDL/SDL_rotozoom.h>

int main(void)
{
	SDL_Surface *ecran=NULL,*fond=NULL,*texte=NULL;
	SDL_Rect position,positiontext;
    char texttt[1000];
    int resultat,done=1,a=1;
    SDL_Event event;
    SDL_Color couleurNoire = {0, 0, 0};
    //initialisation du TTF
    TTF_Font *police=NULL;
    TTF_Init();
    police=TTF_OpenFont("times.ttf",50);
    Mix_Music *music;//construct Mix_Music pointer
    SDL_Init(SDL_INIT_AUDIO);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)//API mixer INITIALIZATION
    {
    	printf("%s\n",Mix_GetError());
    }
    music=Mix_LoadMUS("open_pop.mp3");//load the music
    Mix_PlayMusic(music,1);//play music
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
	printf("unable to initialize SDL: %s\n",SDL_GetError());
	return 1;
    }
    //initialisation de l'SDL
    /*SDL_Init(SDL_INIT_EVERYTHING);*/
    ecran=SDL_SetVideoMode(610,760,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("enigme",NULL);
    if(ecran==NULL)
    {
	printf("unable to set video mode: %s\n",SDL_GetError());
	return 1;
    }
    fond=IMG_Load("cadre.png");
    if(fond==NULL)
    {
	printf("unable to load fond: %s\n",SDL_GetError());
	return 1;
    }
    position.x=0;
    position.y=0;
    positiontext.x=400;
    positiontext.y=305;
    fond=rotozoomSurface(fond,0,0.18,0.11);
    while(done==1)
    {
        SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */
        SDL_Flip(ecran);
        printf("dans le main\n");
        resultat=mot("enigme.txt",ecran,&a);
        //resultat=enigme2(ecran,&a);
        if(a==0)
        {
            music=Mix_LoadMUS("close.mp3");
            Mix_PlayMusic(music,1);
            SDL_Delay(500);
            done=0;
        }
    }
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
