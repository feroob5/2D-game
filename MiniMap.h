#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED

typedef struct PERSO_PRINCIPALE
{
	int vie;
	int score;
  	int position_actuel;
  	SDL_Rect position;
  	SDL_Surface *tab[16];

}PERSO_PRINCIPALE;

void littledot(PERSO_PRINCIPALE p,SDL_Surface *ecran);

#endif // MINIMAP_H_INCLUDED