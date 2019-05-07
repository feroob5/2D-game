#include "jeux.h"
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
// HOuSSEmmM
void initialiser_personnageP(PERSO_PRINCIPALE *p)
{
  p->position.x=53;
  p->position.y=565;
  p->position.h=75;
  p->position.w=75;
  char walking[100];
  int i;
  for(i=0;i<=16;i++)
  {
      sprintf(walking,"/home/houssem/Desktop/Integration/walking/HH%d.png",i);
      p->tab[i]=IMG_Load(walking);
  }
  p->position_actuel=1;
  p->vie=100;
  p->score=0;
  p->moving=0;
  p->acceleration=0;
  p->velocity=0;
}
// Manel
void initialiser_personnagePManel(PERSO_PRINCIPALE *p)
{
  p->position.x=53;
  p->position.y=565;
  //p->position.h=75;
  //p->position.w=75;
  char walking[100];
  int i;
  for(i=0;i<=16;i++)
  {
      sprintf(walking,"/home/houssem/Desktop/menujeu/MMd/MM%d.png",i);
      p->tab[i]=IMG_Load(walking);
  }
  p->position_actuel=1;
  p->vie=100;
  p->score=0;
}

// Afficher PERSO
void afficher_personnageP(PERSO_PRINCIPALE *perso,SDL_Surface *fenetre)
{
  SDL_BlitSurface(perso->tab[perso->position_actuel],NULL,fenetre,&(perso->position));
  SDL_Delay(20);
}

void animation_personnage_clavier(PERSO_PRINCIPALE *perso,int sens)
{
  if(sens==1)//droite//
  {
    if(perso->position_actuel>=8)
    {
      perso->position_actuel=1;
    }
    else
    {
      if(perso->position_actuel <9)
      {
        perso->position_actuel++;
      }
      else
      {
        perso->position_actuel=1;
      }
    }
  }
  else
  {
if(sens==2)//gauche//
  {
    if(perso->position_actuel<=8)
    {
      perso->position_actuel=9;
    }
    else
    {
      if(perso->position_actuel<16)
      {
        perso->position_actuel++;
      }
      else
      {
        perso->position_actuel=9;
      }
    }
  }
}

}


void deplacement_personnage(PERSO_PRINCIPALE *perso,int sens, Background *bg)
{

if(sens==3)//haut
    {
        if(perso->position.y>300)
        {
           perso->position.y+=20;
           perso->moving=1;
           perso->direction=3;
        }
        else
        {
           perso->position.y-=20;
           perso->moving=1;
           perso->direction=3;
        }
      
    }
 }
    
void jump(PERSO_PRINCIPALE *p)//saut et gravité de personnage ...
{
  if(p->position.y<565)
      p->position.y=565;
}
// en attendant Feres 
int enigme()
{
  int i;
  i=9;
  return i;
}

void acceleration(PERSO_PRINCIPALE *per,Uint32 dt,objet o)
{ 
        
             per->position.x+=per->velocity/dt+per->acceleration;//(vitesse mtaa l perso tzid)
            

}



