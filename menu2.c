#include"jeux.h"

int menu2(SDL_Surface *ecran)
{ 


    SDL_Surface *fond=NULL ,*exit=NULL , *save=NULL, *text=NULL;
    int res=0,continuer=1;
    int x,y;

    SDL_Event event;

SDL_Rect position ,positionexit, positionsave,positiontext;
position.x=283;
position.y=184;
positionsave.x=437;
positionsave.y=323;
positionexit.x=437;
positionexit.y=340;
positiontext.x=244;
positiontext.y=390;

fond=IMG_Load("fond.png");
save=IMG_Load("SAVE.png");
exit=IMG_Load("EXIT.png");
text=IMG_Load("text.png");

/**************************************************************************************************/
while(continuer == 1)
{
            SDL_GetMouseState(&x,&y);
      	    printf("x=%d\ny=%d\n",x,y);

SDL_PollEvent(&event);
switch(event.type)
{

                  
        case SDL_MOUSEBUTTONUP:

// YES...
if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 437&& event.button.x <=545 && event.button.y <=352 && event.button.y >=323 /*&& event.button.y >=144*/ ))
   {   
	res=1;// save the game 
	return res;
  continuer=0;
   }
// NO...
if ((event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 437  && event.button.x <=545 && event.button.y <=397 && event.button.y >=340))
{
res=0;// Quit the game without saving
return res;
continuer =0;
}  

} 

      SDL_BlitSurface(fond,NULL,ecran,&position);
      SDL_BlitSurface(save,NULL,ecran,&positionsave);
      SDL_BlitSurface(exit,NULL,ecran,&positionexit);
      SDL_BlitSurface(text,NULL,ecran,&positiontext);
      SDL_Flip(ecran);
}

	SDL_FreeSurface(save);
	SDL_FreeSurface(exit);
	SDL_FreeSurface(fond);
  	SDL_FreeSurface(text); 
 

}
