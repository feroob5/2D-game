/**
*@file personnage.c
*/
#include "personnage.h"

/**
*@brief initialiser le personnage principale.
*@param p personnage principale
*@return rien
*/
void initialiser_personnageP(PERSO_PRINCIPALE *p)
{
  p->position.x=150;
  p->position.y=150;
  char walking[16];
  int i;
  for(i=0;i<=16;i++)
  {
      sprintf(walking,"walking/MM%d.png",i);
      p->tab[i]=IMG_Load(walking);
  }
  p->vie=100;
  p->score=0;
}

/**
*@brief affichage du personnage.
*@param perso personnage principale
*@param fenetre filtrer la fenetre
*@return rien
*/
void afficher_personnageP(PERSO_PRINCIPALE *perso,SDL_Surface *fenetre)
{
  SDL_BlitSurface(perso->tab[perso->position_actuel],NULL,fenetre,&(perso->position));
  SDL_Delay(40);
}
 
/**
*@brief initialiser le score.
*@param score le score
*@return rien
*/
void initialiser_score(Score *score)
{
  score->nb=0;
  score->position.x=300;
  score->position.y=94;
  score->police=TTF_OpenFont("arial.ttf",32);
  sprintf(score->scoretexte,"%d",score->nb);
  //texte=TTF_RenderrText_Blended(score->police,score->scoretexte,score->couleur)//
  //SDL_BlitSurface(score->texte,NULL,ecran,&score->position);/*Blit du texte*///
}

/**
*@brief affichage du score.
*@param score le score
*@param ecran filtrer l'ecran
*@return rien
*/
void afficher_score (Score *score,SDL_Surface *ecran)
{
  SDL_Color couleur ={162,80,23};
  sprintf(score->scoretexte,"%d",score->nb);
  score->text=TTF_RenderText_Blended(score->police,score->scoretexte,couleur);
  SDL_BlitSurface(score->text,NULL,ecran,&score->position);/*Blit du texte*/
}

/**
*@brief initialiser la vie.
*@param heal =Health= la vie
*@return rien
*/
void initialiser_vie(Health *heal)
{
int i;
heal->nb=100;
heal->position.x=-200;
heal->position.y=-40;
char health[20];
for(i=1;i<7;i++)
{
  sprintf(health,"vie/...png",i);
  heal->health[i]=IMG_Load(health);
}
heal->lose=IMG_Load("vie/GameOver.png");
}

/**
*@brief affichage la vie.
*@param heal=Health=la vie
*@param ecran filtrer l'ecran
*@return rien
*/
void afficher_vie(Health *heal,SDL_Surface *ecran)
{
heal->position.x=0;
heal->position.y=0;
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
  heal->position.x=0;
  heal->position.y=0;
  SDL_BlitSurface(heal->lose,NULL,ecran,&heal->position);
  heal->nb=5;
  SDL_Flip(ecran);
  sleep(4);
}
}

/**
*@brief la collision bounding box.
*@param perso personnage principale 
*@param ennemi l'entite secondaire
*@return verif
*/
int collision_BoundingBox(PERSO_PRINCIPALE *perso,ENTITE_SECONDAIRE *ennemi)
{
  int verif=1;
  int leftA,leftB;
  int rightA,rightB;
  int topA,topB;
  int bottomA,bottomB;
//calculate the sides of rect A//
  leftA=ennemi->position.x;
  rightA=ennemi->position.x+ennemi->position.w;
  topA=ennemi->position.y;
  bottomA=ennemi->position.y+ennemi->position.h;
//calculate the sides of rect B//
  leftB=perso->position.x;
  rightB=perso->position.x+perso->position.w;
  topB=perso->position.y;
  bottomB=perso->position.y+perso->position.h;
//if any of the sides from A are outside of B//
  if(bottomA<=topB)
    {
      verif=0;
    }
  if(topA>=bottomB)
    {
      verif=0;
    }
  if(rightA<=leftB)
    {
      verif=0;
    }
  if(leftA>=rightB)
  {
    verif=0;
  }
return verif ;
}

/**
*@brief animation du personnage.
*@param perso personnage principale
*@param sens le sens du personnage droite ou gauche
*@return rien
*/
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
      if(perso->position<9)
      {
        perso->position_actuel++;
      }
      else
      {
        perso->position_actuel=1;
      }
    }
  }

if(sens==2)//gauche//
  {
    if(perso->position_actuel<=8)
    {
      perso->position_actuel=1;

      
    }
    else
    {
      if(perso->position<15)
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
