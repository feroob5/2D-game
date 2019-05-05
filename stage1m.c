
#include "jeux.h"
#include "Menu1.h"
#include <SDL/SDL_mixer.h>
#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.


int stage1m(SDL_Surface *fenetre, int *stag)
{ 
 
 Mix_Music *song,*music;
 SDL_Surface *start=NULL,*fond=NULL, *quit=NULL,  *rotation = NULL;
 Mix_Chunk *scrtch= NULL;
 SDL_Rect position,posquitmenu;
 SDL_Event event;
 Background b;
 Health heal;
 int pop,ee=0,wiwi=0,x,y;
 PERSO_PRINCIPALE perso;
 b.fenetre=fenetre;
 int continuer=1,sens=0,a,senspred=0,k=0,collision;
 int verifenigme1=0,verifenigme2=0,m2;
 int *z=0;
 double angle = 0;
 int tempsPrecedent = 0, tempsActuel = 0;
 Score score;
 objet chikh,chikh2,o1,o2,o3,o4,o5,o6,o7,o8,o9,o10,o11,o12,o13,o14;
 int test=0,resultat;
 SDL_Surface *flag=NULL , *win=NULL , *dattex=NULL;
 SDL_Rect posdattex,poswin,posstart;
 SDL_Rect camera={8500,8500,9000,662};     
     camera.x=0;
     camera.y=0;
 posstart.x=300;
 posstart.y=280;
 posdattex.x=30;
 posdattex.y=30;

 position.x=200;
 position.y=0;

 fond=IMG_Load("cadre.png");
 start=IMG_Load("START.png");
 flag=IMG_Load("flag.png");
 dattex=IMG_Load("Dattex.png");
 fond=rotozoomSurface(fond,0,0.18,0.11);
 SDL_SetColorKey(flag, SDL_SRCCOLORKEY, SDL_MapRGB(flag->format, 255, 255, 255));
 TTF_Init();
 //SDL_SetColorKey(o2.fond, SDL_SRCCOLORKEY, SDL_MapRGB(o2.fond->format, 255, 255, 255));
 
 o1=initialiser_objet("degla2.png",120,560);
 o2=initialiser_objet("degla2.png",440,560);
 o3=initialiser_objet("degla2.png",630,560);
 o4=initialiser_objet("degla2.png",700,560);
 o5=initialiser_objet("degla2.png",2599,560);
 o6=initialiser_objet("degla2.png",1000,560);
 o7=initialiser_objet("degla2.png",2600,560);
 o8=initialiser_objet("degla2.png",2980,560);
 o9=initialiser_objet("degla2.png",2100,560);
 o4=initialiser_objet("degla2.png",3100,560);
 o5=initialiser_objet("degla2.png",1762,560);
 o6=initialiser_objet("degla2.png",1500,560);
 o7=initialiser_objet("degla2.png",3600,560);
 o10=initialiser_objet("degla2.png",2300,560);
 o11=initialiser_objet("degla2.png",2800,560);
 o12=initialiser_objet("degla2.png",3000,560);
 o13=initialiser_objet("degla2.png",3100,560);
 o14=initialiser_objet("degla2.png",3600,560);
 // chikh(enigme)
 chikh=initialiser_objet("personnage tu.png",760,500);
 chikh2=initialiser_objet("personnage tu.png",2009,500);
 
 initialiser_score(&score);
 initialiser_vie (&heal);
 initialiser_background (&b);
 initialiser_personnagePManel(&perso);

 // layem kilberrima.
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }

song= Mix_LoadMUS("song.mp3");
Mix_PlayMusic(song,1);

quit=IMG_Load("Quitthegame.jpg");
posquitmenu.x=271;
posquitmenu.y=191;
// save the stage.
//LoadGame("save.txt",&perso,&b,&score,&heal);

while (continuer)
    {   	

      SDL_PollEvent(&event);
       

switch (event.type) 
{

case SDL_QUIT:
        a=1;
        //continuer = 0;

case SDL_MOUSEBUTTONDOWN:
{
	if(event.button.button==SDL_BUTTON_LEFT)
	{
		sens=2;
		test=1;
		if ((event.button.x>=0)&&(event.button.y>=0))
		{
			animation_personnage_clavier(&perso,sens); 
			camera=scrolling(sens,camera,&perso,&b);
			
		}
		if((((event.button.x>=310)&&(event.button.y>=378)&&(event.button.x<=454)&&(event.button.y<=450))))
			*z=0;

	
	}
	if(event.button.button==SDL_BUTTON_RIGHT)
	{
		sens=1;
		test=1;
		if ((event.button.x>=0)&&(event.button.y>=0))
		{
			deplacement_personnage(&perso,sens,&b);
			animation_personnage_clavier(&perso,sens);
			camera=scrolling(sens,camera,&perso,&b);
			if(Collision_trigonometrique_inscr_iscr(perso.position,o1.position)== 1 &&  (o1.detection == 0)) //collision trigo 
			{
			  o1.detection=1;
			  score.nb+=10;
			  ee=1;
			}
			
else if(Collision_trigonometrique_inscr_iscr(perso.position,o2.position)== 1 &&  (o2.detection == 0)) //collision trigo 
			{
			  o2.detection=1;
			  ee=1;
			  score.nb+=10;
			  ee=1;
			}
			
else if(Collision_trigonometrique_inscr_iscr(perso.position,o3.position)== 1 &&  (o3.detection == 0)) //collision trigo 
			{
			  o3.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o4.position)== 1 &&  (o4.detection == 0)) //collision trigo 
			{
			  o4.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else  if(Collision_trigonometrique_inscr_iscr(perso.position,o5.position)== 1 &&  (o5.detection == 0)) //collision trigo 
			{
			  o5.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o6.position)== 1 &&  (o6.detection == 0)) //collision trigo 
			{
			  o6.detection=1;
			  ee=1;
			  score.nb+=10;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o7.position)== 1 &&  (o7.detection == 0)) //collision trigo 
			{
			  o7.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o8.position)== 1 &&  (o8.detection == 0)) //collision trigo 
			{
			  o8.detection=1;
			  score.nb+=10;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o9.position)== 1 &&  (o9.detection == 0)) //collision trigo 
			{
			  o9.detection=1;
			  score.nb+=10;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o10.position)== 1 &&  (o10.detection == 0)) //collision trigo 
			{
			  o10.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o11.position)== 1 &&  (o11.detection == 0)) //collision trigo 
			{
			  o11.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o12.position)== 1 &&  (o12.detection == 0)) //collision trigo 
			{
			  o12.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o13.position)== 1 &&  (o13.detection == 0)) //collision trigo 
			{
			  o13.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o14.position)== 1 &&  (o14.detection == 0)) //collision trigo 
			{
			  o14.detection=1;
			  score.nb+=10;
			  ee=1;
			}

		if(collision_perprisens1(&b,&perso)==1)
		{
			
			perso.position.x-=5;
			scrtch=Mix_LoadWAV( "button-10.wav");
			Mix_PlayChannel( -1,scrtch, 0 );
		}
		else
		if(collision_perprisens1(&b,&perso)==2 && (verifenigme1==0)) //collision avec enigme1 (couleur Rouge) par exemple.
		{
			 SDL_BlitSurface(fond, NULL,b.fenetre, &position); /* Blit du fond */
			 //SDL_Flip(b.fenetre);
			resultat=enigme2(b.fenetre,&a);
			    if(resultat == 1)
			    {
				verifenigme1=1;
				score.nb+=50;
				}
		}	
		}
	break;	
	}
	break;
}
      
case SDL_KEYDOWN :
{
 
	if(event.key.keysym.sym == SDLK_ESCAPE)
	{
		
		m2= menu2(b.fenetre);
		if(m2 == 1) // save
		{
			//SaveGame("save.txt",perso,b,score,heal);		
			//continuer=0;
		}
		else if(m2 == 0)
		{
			//continuer=0;
		} 
		
	}

	if(event.key.keysym.sym == SDLK_RIGHT) 
	{ 
		sens=1;
		test=1;
		animation_personnage_clavier(&perso,sens);
		camera=scrolling(sens,camera,&perso,&b);
		// verification des collisions
if(Collision_trigonometrique_inscr_iscr(perso.position,o1.position)== 1 &&  (o1.detection == 0)) //collision trigo 
			{
			  o1.detection=1;
			  score.nb+=10;
			  ee=1;
			}
			
else if(Collision_trigonometrique_inscr_iscr(perso.position,o2.position)== 1 &&  (o2.detection == 0)) //collision trigo 
			{
			  o2.detection=1;
			  ee=1;
			  score.nb+=10;
			  ee=1;
			}
			
else if(Collision_trigonometrique_inscr_iscr(perso.position,o3.position)== 1 &&  (o3.detection == 0)) //collision trigo 
			{
			  o3.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o4.position)== 1 &&  (o4.detection == 0)) //collision trigo 
			{
			  o4.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else  if(Collision_trigonometrique_inscr_iscr(perso.position,o5.position)== 1 &&  (o5.detection == 0)) //collision trigo 
			{
			  o5.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o6.position)== 1 &&  (o6.detection == 0)) //collision trigo 
			{
			  o6.detection=1;
			  ee=1;
			  score.nb+=10;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o7.position)== 1 &&  (o7.detection == 0)) //collision trigo 
			{
			  o7.detection=1;
			  score.nb+=10;
			  ee=1;
			}
else if(Collision_trigonometrique_inscr_iscr(perso.position,o8.position)== 1 &&  (o8.detection == 0)) //collision trigo 
			{
			  o8.detection=1;
			  score.nb+=10;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o9.position)== 1 &&  (o9.detection == 0)) //collision trigo 
			{
			  o9.detection=1;
			  score.nb+=10;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o10.position)== 1 &&  (o10.detection == 0)) //collision trigo 
			{
			  o10.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o11.position)== 1 &&  (o11.detection == 0)) //collision trigo 
			{
			  o11.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o12.position)== 1 &&  (o12.detection == 0)) //collision trigo 
			{
			  o12.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o13.position)== 1 &&  (o13.detection == 0)) //collision trigo 
			{
			  o13.detection=1;
			  score.nb+=10;
			  ee=1;
			}
if(Collision_trigonometrique_inscr_iscr(perso.position,o14.position)== 1 &&  (o14.detection == 0)) //collision trigo 
			{
			  o14.detection=1;
			  score.nb+=10;
			  ee=1;
			}

		if(collision_perprisens1(&b,&perso)==1)
		{
			
			perso.position.x-=5;
			scrtch=Mix_LoadWAV( "button-10.wav");
			Mix_PlayChannel( -1,scrtch, 0 );
		}
		else
		if(collision_perprisens1(&b,&perso)==2 && (verifenigme1==0)) //collision avec enigme1 (couleur Rouge) par exemple.
		{
			 SDL_BlitSurface(fond, NULL,b.fenetre, &position); /* Blit du fond */
			 //SDL_Flip(b.fenetre);
			resultat=enigme2(b.fenetre,&a);
			    if(resultat == 1)
			    {
				verifenigme1=1;
				score.nb+=50;
				}
		}	
		else
		if(collision_perprisens1(&b,&perso)==3 && (verifenigme2==0)) //collision avec enigme1
		{
			
			    resultat=enigme2(b.fenetre,&a);
			    if(resultat == 1)
			    {
				verifenigme2=1;
				score.nb+=50;
				}
			
		}
		break;
		
	}
	// Flèche Gauche.
	if(event.key.keysym.sym == SDLK_LEFT)
	{ 
		sens=2;
		deplacement_personnage(&perso,sens,&b);
		animation_personnage_clavier(&perso,sens);
		camera=scrolling(sens,camera,&perso,&b);
		if(perso.position.x<=53)
			perso.position.x+=5;

		if(collision_perprisens2(&b,&perso)==1)
		{
			perso.position.x+=5;
			scrtch=Mix_LoadWAV( "button-10.wav");
			Mix_PlayChannel( -1,scrtch, 0 );
			
		}
		else
		if(collision_perprisens2(&b,&perso)==2 && (verifenigme1==0)) //enigme1 (left)
		{
			
			resultat=enigme2(b.fenetre,&a);
			if(resultat == 1)
			{
				verifenigme1=1;
				score.nb+=50;
			}
			else
			{
				heal.nb-=50;
			}
			
		}
		else
		if(collision_perprisens2(&b,&perso)==3 && (verifenigme2==0)) //enigme2 (left)
		{
			verifenigme2=1;
			if(resultat == 1)
			{
				score.nb+=50;
			}
			else
			{
				heal.nb-=50;
			}
			
		}
		break;
		
	}
	if(event.key.keysym.sym == SDLK_UP)
	{
		sens=3;

	       perso.position.y-=50;
	       perso.position.x+=20;
	    
		if(collision_perprisens3(&b,&perso)==1)
		{
		   {
		   	perso.position.y+=3;
		   	scrtch=Mix_LoadWAV( "button-10.wav");
			Mix_PlayChannel( -1,scrtch, 0 );	   	
		   }
		}
		break;
	} 
	
	if(event.key.keysym.sym == SDLK_DOWN)
	{
		sens=4;
		perso.position.y+=3;
		if(collision_perprisens4(&b,&perso)==1)
			{ 
			  perso.position.y-=3;
			  scrtch=Mix_LoadWAV( "button-10.wav");
			  Mix_PlayChannel( -1,scrtch, 0 );
		    }
	}
	break;
}
break;
}

afficher_bg(&b,b.fenetre,camera);
afficher_vie(&heal,b.fenetre);
afficher_score(&score,b.fenetre);
afficher_personnageP( &perso, b.fenetre);
// chikh
afficher_objet(b.fenetre,chikh,camera);
afficher_objet(b.fenetre,chikh2,camera);
// objet with scrolling.
o5=depobjet(b.fenetre,camera,o5,sens,ee);
o6=depobjet(b.fenetre,camera,o6,sens,ee);
o7=depobjet(b.fenetre,camera,o7,sens,ee);
o8=depobjet(b.fenetre,camera,o8,sens,ee);
o9=depobjet(b.fenetre,camera,o9,sens,ee);
o10=depobjet(b.fenetre,camera,o10,sens,ee);
o11=depobjet(b.fenetre,camera,o11,sens,ee);
o12=depobjet(b.fenetre,camera,o12,sens,ee);
o13=depobjet(b.fenetre,camera,o13,sens,ee);
o14=depobjet(b.fenetre,camera,o14,sens,ee);

	

if(o1.detection !=1)
	afficher_objet(b.fenetre,o1,camera);
if(o2.detection !=1)
	afficher_objet(b.fenetre,o2,camera);
if(o3.detection !=1)
	afficher_objet(b.fenetre,o3,camera);
if(o4.detection !=1)
	afficher_objet(b.fenetre,o4,camera);



// des condition de fin de jeu...
// START the Game		
if(test == 0)
{
	SDL_BlitSurface(start,NULL,b.fenetre,&posstart);
}

// condition de jump.
if(perso.position.y < 565)
	perso.position.y=565;

 //Win
if(score.nb>=140)
{
	SDL_BlitSurface(win,NULL,b.fenetre,&poswin);
}
// deglaX (rotation!!)

		tempsActuel = SDL_GetTicks();

        if (tempsActuel - tempsPrecedent > TEMPS)

        {

            angle += 2; //On augmente l'angle pour que l'image tourne sur elle-même.

 

            tempsPrecedent = tempsActuel;

        }

        else

        {

            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));

        }

        rotation = rotozoomSurface(dattex, angle, 1.0, 1);
        SDL_BlitSurface(rotation , NULL, b.fenetre, &posdattex);






//SDL_BlitSurface(dattex,NULL,b.fenetre,&posdattex);
//Lose
if(heal.nb == 0)
{
	afficher_vie(&heal,b.fenetre);
}
if(a ==1)
	SDL_BlitSurface(quit,NULL,b.fenetre,&posquitmenu);


 SDL_Flip(b.fenetre);
} // fin du while...
Mix_FreeChunk(scrtch);
TTF_CloseFont(score.police);
TTF_Quit();
}

		



