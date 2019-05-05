#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_rotozoom.h>
#include <string.h>
#include "Menu1.h"

background initialiserBackground(char* chemin,int x,int y)
{

background b;
b.fond=IMG_Load(chemin);
b.positionFond.x=x;
b.positionFond.y=y;
return b;

}

Boutton initialiserBoutton(char* chemin1,char* chemin2,int x,int y)
{
Boutton b;
b.img[0]=IMG_Load(chemin1); // image non activée
b.img[1]=IMG_Load(chemin2); // image activée
b.position.x=x;
b.position.y=y;
b.num=0;
return b;
}

Menu initialiserMenu(background b, int num)
{
Menu m;
int i;
m.b=b;
Boutton tab[num];
m.nbrB=num;
m.numBA=0;
return m;
}

// Afficher les bouttons actifs d'un menu 
void AfficherMenuprincipale(Menu m,SDL_Surface *ecran)
{


SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position); 
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
SDL_BlitSurface(m.tab[4].img[0], NULL, ecran,&m.tab[4].position);
}
void AfficherMenuprincipalenomusic(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position); 
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
SDL_BlitSurface(m.tab[4].img[1], NULL, ecran,&m.tab[4].position);
}
void AfficherMenu1(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[1], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position); 
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
SDL_BlitSurface(m.tab[4].img[0], NULL, ecran,&m.tab[4].position);
}
void AfficherMenu2(Menu m,SDL_Surface *ecran)
{


SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[1], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position); 
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
SDL_BlitSurface(m.tab[4].img[0], NULL, ecran,&m.tab[4].position);
}
void AfficherMenu3(Menu m,SDL_Surface *ecran)
{


SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[1], NULL, ecran,&m.tab[2].position); 
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
SDL_BlitSurface(m.tab[4].img[0], NULL, ecran,&m.tab[4].position);
}
void AfficherMenu4(Menu m,SDL_Surface *ecran)
{

SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position); 
SDL_BlitSurface(m.tab[3].img[1], NULL, ecran,&m.tab[3].position);
SDL_BlitSurface(m.tab[4].img[0], NULL, ecran,&m.tab[4].position);

}
// Afficher les Sous-Menus 
void AfficherMenuNG(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
}
void AfficherMenuNG1(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[1], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
}
void AfficherMenuNG2(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[1], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
}
// boutton BACK actif
void AfficherMenuNG3(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[1], NULL, ecran,&m.tab[3].position);
}
void AfficherMenuSETT(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
}
void AfficherMenuSETT1(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[1], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);

}
void AfficherMenuSETT2(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[1], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);

}
void AfficherMenuSETT3(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[1], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);

}
// boutton BACK actif
/*void AfficherMenuSETT4(Menu m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.b.fond, NULL, ecran,&m.b.positionFond);
SDL_BlitSurface(m.tab[0].img[0], NULL, ecran,&m.tab[0].position);
SDL_BlitSurface(m.tab[1].img[0], NULL, ecran,&m.tab[1].position);
SDL_BlitSurface(m.tab[2].img[0], NULL, ecran,&m.tab[2].position);
SDL_BlitSurface(m.tab[3].img[0], NULL, ecran,&m.tab[3].position);
SDL_BlitSurface(m.tab[4].img[1], NULL, ecran,&m.tab[4].position);
}
*/
int updateBouttonMenuP(int c,Menu m)
{

if((c==1))
{
if((m.numBA==1)||(m.numBA==0)) m.numBA=4; 
else m.numBA--; 
}

if((c==2))
{
if (m.numBA==4) m.numBA=1; 
else m.numBA++;
}
return (m.numBA);
}

int updateMenuNG(int c,Menu m)
{

int k=0;
if((c==3)&&(m.numBA==1))
{
  k=1;
}
else
if((c==3)&&(m.numBA==2))
{
  k=2;
}
else
if((c==3)&&(m.numBA==3))
{
  k=3;
}
else
if((c==3)&&(m.numBA==4))
{
  k=4;
}

return k;

}



// update bouttons menu NEWGAME
int updateBouttonMenuNG(int i,Menu m)
{
if((i==1))
{
if((m.numBA==1)||(m.numBA==0)) m.numBA=3; 
else m.numBA--; 
}

if((i==2))
{
if (m.numBA==3) m.numBA=1; 
else m.numBA++;
}

return (m.numBA);
}
// update Bouttons Menu OPTIONS
int updateBouttonMenuSETT(int p,Menu m)
{
if((p==1))
{
if((m.numBA==1)||(m.numBA==0)) m.numBA=3; 
else m.numBA--; 
}

if((p==2))
{
if (m.numBA==3) m.numBA=1; 
else m.numBA++;
}

return (m.numBA);
}

int updateBack(int r,Menu m, int k)
{

int y=0;
if((r==3)&&(m.numBA==3))
{ y=1;}
else 
if((r==3)&&(m.numBA==4) && (k==3))
{ y=2;} 

return y;

}



/*
int Quit()
{ 


    SDL_Surface *ecran = NULL , *fond=NULL ;
    int continuer=1,res=0;

    SDL_Event event;
   

    SDL_Rect position ,positionexit, positionsave ;
    position.x=0;
    position.y=0;

SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL


 ecran=SDL_SetVideoMode(275,185, 32, SDL_HWSURFACE| SDL_DOUBLEBUF); // Ouverture de la fenêtre
SDL_WM_SetCaption("Sure ??", NULL);
fond=IMG_Load("menuquit.png"); 
SDL_BlitSurface(fond,NULL,ecran,&position);
SDL_Flip(ecran);  Mise à jour de l'écran 




while (continuer)

{

        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:
                continuer = 0;
              break;
   
            case SDL_MOUSEBUTTONUP:

                  if (event.button.button == SDL_BUTTON_LEFT && event.button.button.x >=100 && event.button.button.y <90)
                     {   

                  	res=1;// save the game 

                  	return res;

                  	continuer = 0;

                     }
                  if (event.button.button == SDL_BUTTON_LEFT && event.motion.x > positionexit.x && event.motion.x < positionexit.x+200 && event.motion.y> positionexit.y &&  event.motion.y < positionexit.y+200)
                  {

                  res=0;// Quit the game without saving 
                  continuer = 0;
                  return res;
                    }  
      } 

                   
}
	SDL_FreeSurface(fond);


    SDL_Quit(); // Arrêt de la SDL
 

   EXIT_SUCCESS; // Fermeture du programme

}

*/





