/**
@file [background.c]
*/
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h> 
#include "background.h"


/**
* @brief To initialize the background game bg .
* @param bg the background
* @return Nothing
*/
void initialiser_bg(background_game* bg)
{

bg->positionFond_b.x=0;
bg->positionFond_b.y=0;
bg->bg=IMG_Load("tozeur.png");
}
/**
* @brief To show the background bg .
* @param ecran the screen
* @param bg the background
* @param camera the  background scroll
* @return Nothing
*/
void afficher_bg(background_game *b,SDL_Surface *ecran,SDL_Rect camera)
{
	SDL_Delay(100);
	SDL_BlitSurface(b->bg,&camera,ecran,&(b->positionFond_b));
}

/**
* @brief To scroll the background bg to the left and right 
* @param camera the background scroll
* @param bg the background
* @param o the main caracter
* @param sens the input
* @return camera
*/
SDL_Rect scrolling(int sens,SDL_Rect camera,PERSO_PRINCIPALE *o,background_game *bg)
{
//deplacement a droite	
if(sens==1&&((o->position.x)%960)<370)
{ 
	//camera fixe
	o->position.x=o->position.x+50;
  o->moving=1;
  o->direction=1;
}

if(sens==1&&(o->position.x)>=370)
{//perso fixe
camera.x=camera.x+60;
o->moving=0;
o->direction=1;
}
if(sens==1&&camera.x>=7500)
{   
	camera.x=7500;
	o->position.x=o->position.x+50;
  o->moving=1;
  o->direction=1;
}
//deplacement a gauche
if(sens==2&&((o->position.x)%960>370))
{   //camera fixe
	o->position.x=o->position.x-50;
  o->moving=1;
  o->direction=2;
}
if(sens==2&&o->position.x<=370)
{//perso fixe
camera.x=camera.x-60;
o->moving=0;
 o->direction=2;
}
if(sens==2&&camera.x<=0)
{
	camera.x=0;
	o->position.x=o->position.x-50;
  o->moving=1;
   o->direction=2;
}
return camera ;
}
 /**
* @brief To the caracter input up and down
* @param o the main caracter
* @param bg the background
* @param sens the input
* @return Nothing
*/
void deplacement_personnage(PERSO_PRINCIPALE *o,int sens,background_game *bg)
{


       if(sens==3)//haut
    {
        if(o->position.y>=480)
        {
           o->position.y-=50;
           o->moving=1;
           o->direction=3;
        }
        else if(o->position.y<50);//(saut et gravité)
         o->position.y=480;
       
       
      
    } 
    

}

/**
* @brief To modifie the main carcter velocity
* @param per the main caracter
* @param p the objet
* @param dt the time variable
* @return Nothing
*/
void acceleration(PERSO_PRINCIPALE *per,Uint32 dt,objet p)
{ 
        if (per->positionperso.x>=p.px.x)//(lorsque le personnage depasse l'objet(collision avec l'objet))
         {
             per->position.x+=per->velocity/dt+per->acceleration;
         }
         
      
}
