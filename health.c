
#include "jeux.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>


// Initialiser Score
void initialiser_score(Score *score)
{
  score->nb=0;
  score->positionfinale.x=450;
  score->positionfinale.y=400;
  score->position.x=200;
  score->position.y=38;
  score->police=TTF_OpenFont("arial.ttf",50);
  sprintf(score->scoretexte,"%d",score->nb);
}

//Afficher SCORE 
void afficher_score (Score *score,SDL_Surface *ecran)
{
  SDL_Color couleur ={162,80,23};
  sprintf(score->scoretexte,"%d",score->nb);
  score->text=TTF_RenderText_Blended(score->police,score->scoretexte,couleur);
  SDL_BlitSurface(score->text,NULL,ecran,&score->position);/*Blit du texte*/
}
//init VIE
void initialiser_vie(Health *heal)
{

int i;
heal->nb=100;
heal->position.x=757;
heal->position.y=3;
char health[100];
for(i=1;i<7;i++)
{
  sprintf(health,"/home/houssem/Desktop/Integration/vie/vie%d.png",i);
  heal->health[i]=IMG_Load(health);
}
heal->lose=IMG_Load("/home/houssem/Desktop/Integration/vie/GameOver.png");
}

// Afficher VIE
void afficher_vie(Health *heal,SDL_Surface *ecran)
{
  
if(heal->nb>75 && heal->nb<=100)
{
  SDL_BlitSurface(heal->health[1],NULL,ecran,&heal->position);
}
if(heal->nb>50 && heal->nb<=75)
{
  SDL_BlitSurface(heal->health[2],NULL,ecran,&heal->position);
}
if(heal->nb>25 && heal->nb<=50)
{
  SDL_BlitSurface(heal->health[3],NULL,ecran,&heal->position);
}
if(heal->nb>10 && heal->nb<=25)
{
  SDL_BlitSurface(heal->health[4],NULL,ecran,&heal->position);
}
if(heal->nb<=10 && heal->nb>0)
{
  SDL_BlitSurface(heal->health[5],NULL,ecran,&heal->position);
}
if(heal->nb==0)
{
  SDL_BlitSurface(heal->health[6],NULL,ecran,&heal->position);
  SDL_Flip(ecran);
  //sleep(4);
}

}

objet initialiser_objet(char* chemin,int x,int y)
{
objet o;
o.fond=IMG_Load(chemin);
o.position.x=x;
o.position.y=y;
o.position.w=21;
o.position.h=30;
o.detection=0;
o.affiche.x=rand()%1000+200;
o.affiche.x=x;
o.affiche.y=y;
return o;
}

void afficher_objet (SDL_Surface *ecran,objet o,SDL_Rect camera)
{
  SDL_BlitSurface(o.fond,NULL,ecran,&o.position);
}

objet depobjet(SDL_Surface *ecran ,SDL_Rect camera,objet o , int sens,int collision)
{
  if(camera.x >= o.affiche.x-960 && camera.x <= o.affiche.x)
  {
    if(sens == 1)
    {
      o.position.x -= 10;
    }
  }
  if((o.detection!=1) ||(collision == 0))
  {
    SDL_BlitSurface(o.fond,NULL,ecran,&(o.position));
  }
return o;

}
