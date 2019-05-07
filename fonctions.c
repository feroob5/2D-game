#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"
#include <SDL/SDL_rotozoom.h>

int mot(char ch[],SDL_Surface *ecran,int *a)
{
    SDL_Surface *texte=NULL,*correct=NULL,*fals=NULL;
    SDL_Rect position1,position,positionr;
    SDL_Event event;
    Mix_Music *music;
    int i=0,x,n,result=0,done=1,continuer=1;
    char tab[10][15],motx[10],ca='\0',texttt[1000];
    SDL_Color couleurNoire = {0, 0, 0};
    //initialisation du TTF
    TTF_Font *police=NULL;
    TTF_Init();
    police=TTF_OpenFont("times.ttf",30);
    //initialisation du fichier
    FILE* fichier=NULL;
    x=rand()%10;//randomize
    fichier=fopen(ch,"r+");
    if(fichier==NULL)//verification de l'ouverture du fichier
    {
        printf("erore au niveau d'ouverture de fichiers");
        return 0;
    }
    else
    {

        while(fscanf(fichier,"%s",tab[i])!=EOF)
        {
             i++;
        }
    }//on met les mots dans le fichier dans un tableaux
    fclose(fichier);
    n=5;//initialzing the number of tryes
    correct=IMG_Load("correct.png");
    fals=IMG_Load("false.png");
    position.x =60;
    position.y =70;
    correct=rotozoomSurface(correct,0,0.18,0.11);
    fals=rotozoomSurface(fals,0,0.18,0.11);
    strcpy(motx,tab[x]);
    for(i=0;i<strlen(motx)-1;i++)
    {
        i++;
        if(i>strlen(motx))
        {
            printf("fin de cryptage.\n");
            break;
        }
        else
        {
            printf("cryptage de %c\n",motx[i]);
            motx[i]='*';
        }
    }
    i=0;
    texte =TTF_RenderText_Blended(police,motx,couleurNoire);
    SDL_BlitSurface(texte,NULL,ecran, &position);
    SDL_Flip(ecran);
    position1.x =60;
    position1.y =90;
    position.y =position1.y;
    positionr.x=260;
    positionr.y=640;
    printf("%s\n",motx);
    while(done)
    {
        texte=TTF_RenderText_Blended(police,"entrer la lettre.",couleurNoire);
        SDL_BlitSurface(texte, NULL, ecran, &position1); // Blit du texte
        SDL_Flip(ecran);
        ca='\0';
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
            {
                i++;
                n--;//dimunuer le nombre par 1 pour chaque essaie!
                printf("%d\n",n);
                switch(event.key.keysym.sym)
                {
                    case SDLK_a:
                    {
                        ca='a';
                        printf("bouton a\n");
                        break;
                    }
                    case SDLK_b:
                    {
                        ca='b';
                        break;
                    }
                    case SDLK_c:
                    {
                        ca='c';
                        break;
                    }
                    case SDLK_d:
                    {
                        ca='d';
                        break;
                    }
                    case SDLK_e:
                    {
                        ca='e';
                        break;
                    }
                    case SDLK_f:
                    {
                        ca='f';
                        break;
                    }
                    case SDLK_g:
                    {
                        ca='g';
                        break;
                    }
                    case SDLK_h:
                    {
                        ca='h';
                        break;
                    }
                    case SDLK_i:
                    {
                        ca='i';
                        break;
                    }
                    case SDLK_j:
                    {
                        ca='j';
                        break;
                    }
                    case SDLK_k:
                    {
                        ca='k';
                        break;
                    }
                    case SDLK_l:
                    {
                        ca='l';
                        break;
                    }
                    case SDLK_m:
                    {
                        ca='m';
                        break;
                    }
                    case SDLK_n:
                    {
                        ca='n';
                        break;
                    }
                    case SDLK_o:
                    {
                        ca='o';
                        break;
                    }
                    case SDLK_p:
                    {
                        ca='p';
                        break;
                    }
                    case SDLK_q:
                    {
                        ca='q';
                        break;
                    }
                    case SDLK_r:
                    {
                        ca='r';
                        break;
                    }
                    case SDLK_s:
                    {
                        ca='s';
                        break;
                    }
                    case SDLK_t:
                    {
                        ca='t';
                        break;
                    }
                    case SDLK_u:
                    {
                        ca='u';
                        break;
                    }
                    case SDLK_v:
                    {
                        ca='v';
                        break;
                    }
                    case SDLK_w:
                    {
                        ca='w';
                        break;
                    }
                    case SDLK_x:
                    {
                        ca='x';
                        break;
                    }
                    case SDLK_y:
                    {
                        ca='y';
                        break;
                    }
                    case SDLK_z:
                    {
                        ca='z';
                        break;
                    }
                }
                printf("%c\n",ca);
                if(ca==tab[x][i])
                {
                    printf("%c\n",tab[x][i]);//test des lettres
                    texte=TTF_RenderText_Blended(police,"la lettre est correcte",couleurNoire);
                    position.y=position.y+20;
                    SDL_BlitSurface(texte, NULL, ecran, &position);//Blit du texte
                    SDL_Flip(ecran);
                    music=Mix_LoadMUS("correct.mp3");
                    Mix_PlayMusic(music,1);
                    event.key.keysym.sym=ca;
                    motx[i]=event.key.keysym.sym;
                    texte=TTF_RenderText_Blended(police,motx,couleurNoire);
                    position.y=position.y+20;
                    SDL_BlitSurface(texte, NULL, ecran, &position);//Blit du texte
                    SDL_Flip(ecran);
                    i++;
                }
                else if(ca!=tab[x][i])
                {
                    printf("%c\n",tab[x][i]);//test des lettres
                    texte=TTF_RenderText_Blended(police,"la lettre que vois avez entrer est fausse!!",couleurNoire);
                    position.y=position.y+20;
                    SDL_BlitSurface(texte, NULL, ecran, &position); /// Blit du texte
                    SDL_Flip(ecran);
                    music=Mix_LoadMUS("false.mp3");
                    Mix_PlayMusic(music,1);
                    i--;
                }
                
                if(n<0)
                {
                    texte=TTF_RenderText_Blended(police,"vous aver depasser le nombre de try",couleurNoire);
                    position.y=position.y+20;
                    SDL_BlitSurface(texte, NULL, ecran, &position); // Blit du texte
                    SDL_BlitSurface(fals,NULL,ecran,&positionr);
                    SDL_Flip(ecran);
                    *a=0;
                    result=0;// resultat si l'enigme n'est pas passer
                    SDL_Delay(1000);
                    done=0;
                }
                else if(strcmp(tab[x],motx)==0)
                {
                    texte=TTF_RenderText_Blended(police,"felicitation vous aver reussir a deviner.",couleurNoire);
                    position.y=position.y+20;
                    SDL_BlitSurface(texte, NULL, ecran, &position); //Blit du texte
                    SDL_BlitSurface(correct,NULL,ecran,&positionr);
                    SDL_Flip(ecran);
                    result=1;//resultat de l'enigme  si il est passe
                    SDL_Delay(1000);
                    *a=0;
                    done=0;
                }
                break;
            }
        }
    }
    SDL_FreeSurface(texte);
    return (result);
}

Boutton initialiserBoutton(char* chemin1,char* chemin2,int x,int y)
{
  Boutton b;
  b.img[0]=IMG_Load(chemin1); // image non activée
  b.img[1]=IMG_Load(chemin2); // image activée
  b.scratch=NULL;
  b.position.x=x;
  b.position.y=y;
  b.num=0;
  return b;
}

/*int updateMenu(int c, int j,Menu m)
{
    if(c==1)
    {
        if((m.numBA==1)||(m.numBA==0))
            m.numBA=4;
        else 
            m.numBA--;
    }
    if(c==2)
    {
        if (m.numBA==4)
            m.numBA=1; 
        else
            m.numBA++;
    }
    j=m.numBA;
    return j;
}*/

int enigme2(SDL_Surface *ecran,int *a)
{
    int continuer=1,rep=0,x=0;
    SDL_Surface *question=NULL,*correct=NULL,*fals=NULL,*cover=NULL;
    SDL_Rect positionq,positionr;
    Boutton reponsea,reponseb,reponsec;
    Menu m;
    Mix_Music *music;
    SDL_Event event;
    reponsea=initialiserBoutton("a.png","a2.png",50,650);
    reponseb=initialiserBoutton("b.png","b2.png",225,650);
    reponsec=initialiserBoutton("c.png","c2.png",400,650);
    m.tab[0]=reponsea;
    m.tab[1]=reponseb;
    m.tab[2]=reponsec;
    cover=IMG_Load("cover.png");
    question=IMG_Load("question.png");
    correct=IMG_Load("correct.png");
    fals=IMG_Load("false.png");
    positionq.x=80;
    positionq.y=305;
    positionr.x=250;
    positionr.y=350;
    question=rotozoomSurface(question,0,0.18,0.11);
    m.tab[0].img[0]=rotozoomSurface(m.tab[0].img[0],0,0.18,0.11);
    m.tab[1].img[0]=rotozoomSurface(m.tab[1].img[0],0,0.18,0.11);
    m.tab[2].img[0]=rotozoomSurface(m.tab[2].img[0],0,0.18,0.11);
    m.tab[0].img[1]=rotozoomSurface(m.tab[0].img[1],0,0.18,0.11);
    m.tab[1].img[1]=rotozoomSurface(m.tab[1].img[1],0,0.18,0.11);
    m.tab[2].img[1]=rotozoomSurface(m.tab[2].img[1],0,0.18,0.11);
    correct=rotozoomSurface(correct,0,0.18,0.11);
    fals=rotozoomSurface(fals,0,0.18,0.11);
    while(continuer)
    {
        music=Mix_LoadMUS("boutton_pop.mp3");
        SDL_WaitEvent(&event);
        switch(x)
        {
            case 0:
            {
                SDL_BlitSurface(question,NULL,ecran,&positionq);
                SDL_BlitSurface(m.tab[0].img[0],NULL,ecran,&m.tab[0].position);
                SDL_BlitSurface(m.tab[1].img[0],NULL,ecran,&m.tab[1].position);
                SDL_BlitSurface(m.tab[2].img[0],NULL,ecran,&m.tab[2].position);
                break;
            }//aucune boutton est presser
            case 1:
            {
                SDL_BlitSurface(m.tab[0].img[1],NULL,ecran,&m.tab[0].position);
                SDL_BlitSurface(m.tab[1].img[0],NULL,ecran,&m.tab[1].position);
                SDL_BlitSurface(m.tab[2].img[0],NULL,ecran,&m.tab[2].position);
                break;
            }//la bouton a est presser
            case 2:
            {
                SDL_BlitSurface(m.tab[0].img[0],NULL,ecran,&m.tab[0].position);
                SDL_BlitSurface(m.tab[1].img[1],NULL,ecran,&m.tab[1].position);
                SDL_BlitSurface(m.tab[2].img[0],NULL,ecran,&m.tab[2].position);
                break;
            }//la boutton b est presser
            case 3:
            {
                SDL_BlitSurface(m.tab[0].img[0],NULL,ecran,&m.tab[0].position);
                SDL_BlitSurface(m.tab[1].img[0],NULL,ecran,&m.tab[1].position);
                SDL_BlitSurface(m.tab[2].img[1],NULL,ecran,&m.tab[2].position);
            }
        }
        switch (event.type)
        {
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym==SDLK_a)
                {
                    Mix_PlayMusic(music,1);
                    x=1;
                }
                else if(event.key.keysym.sym==SDLK_b)
                {
                    Mix_PlayMusic(music,1);
                    x=2;
                }
                else if(event.key.keysym.sym==SDLK_c)
                {
                    Mix_PlayMusic(music,1);
                    x=3;
                }
                else if(event.key.keysym.sym==SDLK_RETURN)
                {
                    if(x==0)//il n'ya pas de reponse saisir
                    {

                        rep=2;
                    }
                    else if(x==1)//la reponse est vrai
                    {
                        rep=1;
                        continuer=0;
                    }
                    else if((x==2)||(x==3))//la reponse est fausse
                    {
                        rep=2;
                    }
                }
                break;
            }
        }
        if(rep==2)
        {
            music=Mix_LoadMUS("false.mp3");
            Mix_PlayMusic(music,1);
            SDL_BlitSurface(fals,NULL,ecran,&positionr);
            rep=0;
            SDL_Flip(ecran);
            SDL_Delay(1000);
        }
        SDL_BlitSurface(cover,NULL,ecran,&positionr);
        SDL_Flip(ecran);
    }
    if (rep==1)
    {
        music=Mix_LoadMUS("correct.mp3");
        Mix_PlayMusic(music,1);
        SDL_BlitSurface(correct,NULL,ecran,&positionr);
        SDL_Flip(ecran);
        *a=0;
        SDL_Delay(1000);
    }
    return rep;
}