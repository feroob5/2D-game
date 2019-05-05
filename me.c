#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_rotozoom.h>
#include <string.h>
#include "Menu1.h"
#include "jeux.h"
#include <math.h> 

int main(int argc, char *argv[])
{ 

//initialisation SDL..

int *momo;
 SDL_Surface *ecran = NULL, *quit=NULL, *help=NULL, *tick=NULL, *choix=NULL, *v100=NULL,*v75=NULL,*v50=NULL,*v25=NULL,*v0=NULL;
 Mix_Music *musique;
 Mix_Chunk *scratch = NULL;
int ll=0;
char menu[300];
SDL_Surface **tab;
SDL_Rect postab[205],posquitmenu,postick,poshelp,poschoix,posv;
int w,u;
int mv=1;
for(u=1;u<142;u++)
{
postab[u].x=0;
postab[u].y=0;
}

    SDL_Init(SDL_INIT_EVERYTHING);
 
tab=(SDL_Surface**)malloc(sizeof(SDL_Surface*)*204);

//initialisation
Menu mP,mO,mJ;
background bg;
	int c=0;
	int continuer = 1;
	int X=0;
    int i=0;
    int j=0;
    int k=0;
    int p=0;
    int a=0;
    int r=0;
    int y=0;
    int t=0;
    int aa=0;
    int tk;
    int stg;
    int chx;
    int menup,menus;


SDL_Event event;
Boutton bnewgame,bload,bsettings,bquit,bmusic,bsingle,bmulti,bdisplay,bcommands,bsound;
poschoix.x=0;
poschoix.y=0;
poshelp.x=0;
poshelp.y=81;
posv.x=900;
posv.y=160;
posquitmenu.x=271;
posquitmenu.y=191;
//initialisation Des Bouttons
bg=initialiserBackground("Background.png",0,0);
bdisplay=initialiserBoutton("display1.png","display2.png",350,200);
bcommands=initialiserBoutton("commands1.png","commands2.png",350,280);
bsound=initialiserBoutton("sound1.png","sound2.png",350,360);
// initialiser le Menu Principale
mP= initialiserMenu(bg,5);
mP.tab[0]=initialiserBoutton("newgame1.png","newgame2.png",350,200);
mP.tab[1]=initialiserBoutton("load1.png","load2.png",350,280);
mP.tab[2]=initialiserBoutton("setting1.png","setting2.png",350,360);
mP.tab[3]=initialiserBoutton("quit1.png","quit2.png",60,600);
mP.tab[4]=initialiserBoutton("music1.png","music2.png",800,15);
// initialiser le menu de NEWGAME
mJ= initialiserMenu(bg,4);
mJ.tab[0]=initialiserBoutton("singleplayer1.jpg","singleplayer2.png",350,200);
mJ.tab[1]=initialiserBoutton("multiplayer1.jpg","multiplayer2.png",350,280);
mJ.tab[2]=initialiserBoutton("music1.png","music2.png",800,15);
mJ.tab[3]=initialiserBoutton("quit1.png","quit2.png",60,600);
// initialiser le menu de SETTINGS
mO= initialiserMenu(bg,5);
mO.tab[0]=initialiserBoutton("keyboard1.png","keyboard2.png",350,200);
mO.tab[1]=initialiserBoutton("mouse1.png","mouse2.png",350,280);
mO.tab[2]=initialiserBoutton("joystick1.png","joystick2.png",350,360);
mO.tab[4]=initialiserBoutton("quit1.png","quit2.png",60,600);
/**************************************************************************************************/ 
    ecran= SDL_SetVideoMode(960,662, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("****BALLOTING****", NULL);

for(w=1;w<205;w++) // exemple: 500 c'est le nombre d'image de la vidéo
{
sprintf(menu,"/home/houssem/Desktop/menujeu/intro game/intro_%d.png",w);
tab[w]=IMG_Load(menu);
tab[w]=rotozoomSurface(tab[w],0,0.5,0.62548759);
SDL_BlitSurface(tab[w],NULL,ecran,&postab[w]);
SDL_Flip(ecran);
}

   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }

musique= Mix_LoadMUS("song.wav");
Mix_PlayMusic(musique, -1);
// position de quitgame(fenetre)
quit=IMG_Load("Quitthegame.jpg");
//position de help
help=IMG_Load("Help.png");
tick=IMG_Load("tick.png");
choix=IMG_Load("choixjoueur.png");
// load du volume...
v0=IMG_Load("00.png");

v25=IMG_Load("25.png");

v50=IMG_Load("50.png");

v75=IMG_Load("75.png");

v100=IMG_Load("100.png");

// */*/*/*/*/**/
AfficherMenuprincipale(mP,ecran);
SDL_Flip(ecran);
/*********************************************************************************/
while (continuer)
{ 
     
      SDL_WaitEvent(&event);
      SDL_BlitSurface(help,NULL,ecran,&poshelp);
switch (event.type) 
{

case SDL_QUIT:
        {
			aa=1;
			break;
    	}

case SDL_KEYDOWN:
 {
	
	if(event.key.keysym.sym == SDLK_a ) // diminuer le volume...
	{
		
		if(mv ==1) // le son est 75...
		{
			SDL_BlitSurface(v75,NULL,ecran,&posv);
			Mix_VolumeMusic(MIX_MAX_VOLUME*3/4);
			Mix_VolumeMusic(-1);
			mv=2;
			
		}
		else
		if(mv ==2) //le son est 50...
		{
			SDL_BlitSurface(v50,NULL,ecran,&posv);
			Mix_VolumeMusic(MIX_MAX_VOLUME/2);
			Mix_VolumeMusic(-1);
			mv=3;
		}
		else
		if(mv ==3)// le son est 25...
		{
			SDL_BlitSurface(v25,NULL,ecran,&posv);
			Mix_VolumeMusic(MIX_MAX_VOLUME/4);
			Mix_VolumeMusic(-1);
			mv=4;
		}
		else
		if(mv ==4) // le son est 00...
		{
			//Mix_VolumeMusic(MIX_MAX_VOLUME 4);
			//Mix_VolumeMusic(-1);
			SDL_BlitSurface(v0,NULL,ecran,&posv);
			Mix_PauseMusic();
			mv=5;
		}
		/*else
		if(mv ==5) // le son est 0...
		{
			Mix_VolumeMusic(MIX_MAX_VOLUME * 3/4);
			Mix_VolumeMusic(-1);
			
			mv=6;
		} */
	}
	if(event.key.keysym.sym == SDLK_b ) // diminuer le volume...
	{
		
		if(mv ==5) // le son est 25...
		{
			SDL_BlitSurface(v25,NULL,ecran,&posv);
			Mix_ResumeMusic();
			mv=4;	
		}
		else
		if(mv ==4) //le son est 50...
		{
			SDL_BlitSurface(v50,NULL,ecran,&posv);
			Mix_VolumeMusic(MIX_MAX_VOLUME/2);
			Mix_VolumeMusic(-1);
			mv=3;
		}
		else
		if(mv ==3)// le son est 75...
		{
			SDL_BlitSurface(v75,NULL,ecran,&posv);
			Mix_VolumeMusic(MIX_MAX_VOLUME*3/4);
			Mix_VolumeMusic(-1);
			mv=2;
		}
		else
		if(mv ==2) // le son est 00...
		{
			SDL_BlitSurface(v100,NULL,ecran,&posv);
			Mix_VolumeMusic(MIX_MAX_VOLUME*1);
			Mix_VolumeMusic(-1);
			mv=1;
		} 

	  }
	if(event.key.keysym.sym == SDLK_UP ) 
	{ 
		if(((j==0)||(j==1)||(j==2)||(j==3)||(j==4))&&(k==0))
		  {
		  c=1;
		  scratch=Mix_LoadWAV( "button-10.wav");
     	  Mix_PlayChannel( -1,scratch, 0 );
		  }
        if((k==1))
		  {
		  	i=1;
		  }
		
		if((k==3))
		  {
		   p=1;
		   scratch=Mix_LoadWAV( "button-10.wav");
     	   Mix_PlayChannel( -1,scratch, 0 ); 
		  }

		  mP.numBA=updateBouttonMenuP(c,mP);
		  j=mP.numBA;
		  mO.numBA=updateBouttonMenuSETT(p,mO);
		  
	}	  
	
 	
	else
	if(event.key.keysym.sym == SDLK_DOWN) 
	{ 
	        if(((j==0)||(j==1)||(j==2)||(j==3)||(j==4))&&(k==0))
		  {
		    c=2;
		    scratch=Mix_LoadWAV( "button-10.wav");
     	    Mix_PlayChannel( -1,scratch, 0 );
		  }
		else
          	if((k==1))
		  {
		  	i=2;
		  }
		else
		if((k==3))
		  {
		    p=2;
		    scratch=Mix_LoadWAV( "button-10.wav");
     	    Mix_PlayChannel( -1,scratch, 0 );
		  }
		  mP.numBA=updateBouttonMenuP(c,mP);
		  j=mP.numBA;
		  mO.numBA=updateBouttonMenuSETT(p,mO);	  
	}
	else
	if(event.key.keysym.sym == SDLK_RETURN)
	{ 
	  if((k==0)) 
	  	{
	  	 c=3;
	  	 }
	  if((mO.numBA == 1))
	  			{
	  				tk=1;
	  			}
	  			else
	  if(mO.numBA == 2)
	  			{
	  				tk=2;
	  			}
	  			else
	  if(mO.numBA == 3)
	  			{
	  				tk=3;
	  			}
	  if(mP.numBA == 4)
	  		aa=1;

	k=updateMenuNG(c,mP);
		
	}
	else
	if(event.key.keysym.sym == SDLK_ESCAPE ) 
	{	
		k=0;
		t=0;

		if((k==3) || (t==3))
			{
			AfficherMenuprincipale(mP,ecran);
			SDL_BlitSurface(help,NULL,ecran,&poshelp);
			}
		if(((k==1) || (t==1)) &&(chx == 1))
			{
			AfficherMenuprincipale(mP,ecran);
			SDL_BlitSurface(help,NULL,ecran,&poshelp);
			chx=0;
			}
	}
	break;
}	

// Curseur de Souris.
case SDL_MOUSEMOTION:
{
if((event.motion.x >= 350) && (event.motion.y >=200) && (event.motion.x <= 590) && (event.motion.y <= 246)&& ((k==0) || (t==0)))
	{	menup=1;	
	}
			
if((event.motion.x >= 350) && (event.motion.y >=280) && (event.motion.x <= 594) && (event.motion.y <= 326)&& ((k==0) || (t==0)))
	{	menup=2;
    }
if((event.motion.x >= 350) && (event.motion.y >=350) && (event.motion.x <= 594) && (event.motion.y <= 404)&& ((k==0) || (t==0)))
	{	menup=3;
	}

if((event.motion.x >= 60) && (event.motion.y >=600) && (event.motion.x <= 227) && (event.motion.y <= 647) && ((k==0) || (t==0)))
	{	menup=4;

	}

if( (event.motion.x >= 350) && (event.motion.y >=200) && (event.motion.x <= 590) && (event.motion.y <= 246) && (t==1))
        {	
        	AfficherMenuNG1(mJ,ecran);

        }

if(((event.motion.x >= 350) && (event.motion.y >=280) && (event.motion.x <= 594) && (event.motion.y <= 326))&&(t==1))
	{AfficherMenuNG2(mJ,ecran);} 

if(((event.motion.x >= 60) && (event.motion.y >=600) && (event.motion.x <= 227) && (event.motion.y <= 647))&&(t==1))
	{ AfficherMenuNG3(mJ,ecran);}

if( (event.motion.x >= 350) && (event.motion.y >=200) && (event.motion.x <= 590) && (event.motion.y <= 246)&&(t==3))
	{	menus=1;
		
	}
else			
if((event.motion.x >= 350) && (event.motion.y >=280) && (event.motion.x <= 594) && (event.motion.y <= 326)&&(t==3))
	{
	 menus=2;
	}
else
if((event.motion.x >= 350) && (event.motion.y >=350) && (event.motion.x <= 594) && (event.motion.y <= 404)&& (t==3))
	{
		menus=3;
	}

}

// appui de la souris.
case SDL_MOUSEBUTTONUP :
{
		if(event.button.button==SDL_BUTTON_LEFT) 
			
		{
			// sur play
		        if ((event.button.x>=350)&&(event.button.y>=200)&&(event.button.x<=590)&&(event.button.y<=246) && (t==0))
			{ 
			  //AfficherMenuNG(mJ,ecran);

			  
			  if(Mix_PlayingMusic() == 1)
					Mix_PauseMusic();
			  t=1;

			}
			// setting
			if((event.button.x >= 350) && (event.button.y >=350) && (event.button.x <= 594) && (event.button.y <= 404) && (t==0))
			{ 
			  t=3;
			}
			// Quit
			if((event.button.x >= 60) && (event.button.y >=600) && (event.button.x <=227) && (event.button.y <= 647) && (t==0))
			{ 
				t=4;
				aa=1;			
			}
			//Music
			if (((event.button.x>=800)&&(event.button.y>=15)&&(event.button.x<=848)&&(event.button.y<=55)) && (t==0))
			{ 
				 if( Mix_PlayingMusic() == 0 ) { Mix_PlayMusic( musique, -1 ); }
			  	 else 
					{ 
						if( Mix_PausedMusic() == 1 ) 
						     {  AfficherMenuprincipale(mP,ecran);
								Mix_ResumeMusic(); 
							 } 

						else {  AfficherMenuprincipalenomusic(mP,ecran);
							Mix_PauseMusic(); } 
					}
			
			}
			// HOUSSEM bech yalaab.
			if((event.button.x >= 298) && (event.button.y >=152) && (event.button.x <=466) && (event.button.y <= 204) && ((t==1)||(k == 1)))
			{ 
				stage1(ecran,&stg);//teba3ni ena !!	
			}
			if((event.button.x >= 507) && (event.button.y >=152) && (event.button.x <=675) && (event.button.y <= 204) && ((t==1)||(k == 1)))
			{ 
				stage1m(ecran,&stg);//teba3 maneel...!!	
			}
			// YES.
			if (((event.button.x>=310)&&(event.button.y>=378)&&(event.button.x<=454)&&(event.button.y<=450)) && (aa==1))
					{continuer=0;}
			//NO.
			if (((event.button.x>=519)&&(event.button.y>=378)&&(event.button.x<=657)&&(event.button.y<=450)) && (aa==1))
					{

					}

			// sur Clavier
		    if ((event.button.x>=350)&&(event.button.y>=200)&&(event.button.x<=590)&&(event.button.y<=246) && (t==3))
			{ 
					tk=1;

			}
			else
			// sur souris.
			if((event.motion.x >= 350) && (event.motion.y >=280) && (event.motion.x <= 594) && (event.motion.y <= 326)&&(t==3))
			{
					tk=2;
			}
			else
			// sur joystick
			if((event.button.x >= 350) && (event.button.y >=350) && (event.button.x <= 594) && (event.button.y <= 404) && (t==3))
			{
					tk=3;
			}
		}
		
}
break;
} 


/***************************************************************************************************************************/
// les mises à jour...
if(j==1)
{ 
//scratch=Mix_LoadWAV( "button-10.wav");
//Mix_PlayChannel( -1,scratch, 0 );
AfficherMenu1(mP,ecran);
SDL_BlitSurface(help,NULL,ecran,&poshelp);
if(k==1)
{
  if( Mix_PlayingMusic() == 1 )
		{Mix_PauseMusic();}
  
}
}
/***********************************************************/
	
// Mise à jour des motions.
if(menup==1)
	{
	AfficherMenu1(mP,ecran);
	SDL_BlitSurface(help,NULL,ecran,&poshelp);
	}
if(menup==2)
	{
	AfficherMenu2(mP,ecran);
	SDL_BlitSurface(help,NULL,ecran,&poshelp);
	}
if(menup==3)
	{
	AfficherMenu3(mP,ecran);
	SDL_BlitSurface(help,NULL,ecran,&poshelp);
	}
if(menup==3)
	{
	AfficherMenu3(mP,ecran);
	SDL_BlitSurface(help,NULL,ecran,&poshelp);
	}
if(menup==4)
	{
	AfficherMenu4(mP,ecran);
	SDL_BlitSurface(help,NULL,ecran,&poshelp);
	}
if((t==1) || (k==1))
{
SDL_BlitSurface(choix,NULL,ecran,&poschoix);
}
if(t==3)
{
AfficherMenuSETT(mO,ecran);
if(menus==1)
{
AfficherMenuSETT1(mO,ecran);
	 if(tk == 1)
	{
	postick.x=550;
	postick.y=200;
	SDL_BlitSurface(tick,NULL,ecran,&postick);
	}
}
else
if(menus==2)
{
AfficherMenuSETT2(mO,ecran);
	 if(tk == 2)
	{
	postick.x=550;
	postick.y=280;
	SDL_BlitSurface(tick,NULL,ecran,&postick);
	}
}
else
if(menus==3)
{
AfficherMenuSETT3(mO,ecran);
	 if(tk == 3)
	{
	postick.x=550;
	postick.y=360;
	SDL_BlitSurface(tick,NULL,ecran,&postick);
	}
}
}

/**************************************************************************************************************/
// Load
if(j==2)
{
AfficherMenu2(mP,ecran);
SDL_BlitSurface(help,NULL,ecran,&poshelp);
}
//Settings
if(j==3)
{
AfficherMenu3(mP,ecran);
SDL_BlitSurface(help,NULL,ecran,&poshelp);
if(k==3)
{
  
  AfficherMenuSETT(mO,ecran);
  if(mO.numBA==1)
  {
  	AfficherMenuSETT1(mO,ecran);
  	if(tk == 1)
	{
	postick.x=550;
	postick.y=200;
	SDL_BlitSurface(tick,NULL,ecran,&postick);
	}
  }
  else
  if(mO.numBA==2)
  	{
  	 AfficherMenuSETT2(mO,ecran);
  		if(tk == 2)
		{
		postick.x=550;
		postick.y=280;
		SDL_BlitSurface(tick,NULL,ecran,&postick);
		}
  	}
  else
  if(mO.numBA==3)
  	{
  		AfficherMenuSETT3(mO,ecran);
  		if(tk == 3)
		{
			postick.x=550;
			postick.y=360;
			SDL_BlitSurface(tick,NULL,ecran,&postick);
		}
  	}

}
}

/********************************************************************************************************/
// Quit
if(j==4)
{
AfficherMenu4(mP,ecran);
SDL_BlitSurface(help,NULL,ecran,&poshelp);
if(k==4)
 aa=1;
}


// fermer le jeu aprés l'apparition de la fenetre QUIT.
if(aa==1)
	SDL_BlitSurface(quit,NULL,ecran,&posquitmenu);


SDL_Flip(ecran);

}
    Mix_FreeChunk(scratch);
    /*SDL_FreeSurface(b.fond);
    SDL_FreeSurface(mP.tab[0].img[0]);*/
 // Arrêt de la SDL
 
    return EXIT_SUCCESS; // Fermeture du programme
}


