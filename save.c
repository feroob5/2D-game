#include "jeux.h"

void SaveGame(char* nomFich,PERSO_PRINCIPALE p,Background b,Score score,Health heal)
{
FILE* f=NULL;
f=fopen(nomFich,"w");
fprintf(f,"%d %d %d %hd %hd\n",Score.nb,heal.nb,p.sens_mouvement,p.position.x,p.position.y);
fprintf(f,"%hd %hd %hd %hd %hd %hd\n",b.positionFond_b.x,b.positionFond_b.y,b.position_collision.x,b.position_collision.y,b.scroll.x,b.scroll.y);
fclose(f);
}
/*-----------------------------------------------------------------------------------------------*/

void LoadGame(char* nomFich,PERSO_PRINCIPALE *p,Background* b,Score* score,Health *heal)
{
FILE* f=NULL;
f=fopen(nomFich,"r");
fscanf(f,"%d %d %d %hd %hd\n",&Score->nb,&heal->nb,&p->sens_mouvement,&p->position.x,&p->position.y);
fscanf(f,"%hd %hd %hd %hd %hd %hd\n",&b->positionFond_b.x,&b->positionFond_b.y,&b->position_collision.x,&b->position_collision.y,&b->scroll.x,&b->scroll.y);
fclose(f);
}
/*-----------------------------------------------------------------------------------------------*/

void SaveGamestage(char* nomFich,int x)
{
FILE* f=NULL;
f=fopen(nomFich,"w");
fprintf(f,"%d \n",x);
fclose(f);
}
/*-----------------------------------------------------------------------------------------------*/

void LoadGamestage(char* nomFich,int *x)
{
FILE* f=NULL;
f=fopen(nomFich,"r");
fscanf(f,"%d \n",x);
fclose(f);
}

