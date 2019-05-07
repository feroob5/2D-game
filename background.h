/**
@file [background.h]
*/
#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#define FPS 60
#define ACCELX 0
#define ACCELY 0
#define SCREEN_W 1000
#define SCREEN_H 400

/**
* @struct background_game
* @brief struct for background
*/
typedef struct 
{
   
   SDL_Surface *bg;   /*!< Surface. */           
  SDL_Rect positionFond_b;/*!< Rectangle*/
}background_game;
/**
* @struct PERSO_PRINCIPALE
* @brief struct personnage principale
*/
typedef struct PERSO_PRINCIPALE
{
  int vie;
  int score;
  int position_actuel;
  SDL_Rect position;
  SDL_Surface *tab[16];
  double velocity/*(vitesse)*/,acceleration;
  int moving; // 0 moving 1 not moving
  int direction; //1right 2 left 3 up
}PERSO_PRINCIPALE;
void initialiser_bg(background_game* bg);// initialisation du background
void afficher_bg(background_game *b,SDL_Surface *ecran,SDL_Rect camera);//affichage du background
SDL_Rect scrolling(int sens,SDL_Rect camera,PERSO_PRINCIPALE *o,background_game *bg);
void deplacement_personnage(PERSO_PRINCIPALE *o,int sens, background_game *bg);
void acceleration(PERSO_PRINCIPALE *per,Uint32 dt,objet p);// vitesse et acceleration du personnage
#endif 