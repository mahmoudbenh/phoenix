#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDE
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>

typedef enum STATE STATE;
enum STATE {WAITING, FOLLOWING,ATTACKING};
typedef struct
{
   
    SDL_Surface *sprite1;
    SDL_Surface *sprite2;
    SDL_Surface *sprite3;
    SDL_Surface *sprite4;
    SDL_Rect posEnnemi;
    SDL_Rect posMax;
    SDL_Rect posMin;
    SDL_Rect posSprite;
    SDL_Rect posSprite2;
    STATE State;
} Ennemi;

typedef struct
{
    SDL_Surface *imgbackground;
    SDL_Rect posbackground;
} back;
typedef struct
{
    SDL_Rect poshero;
    SDL_Surface *imageh;
} perso;
void initEnnemi(Ennemi*e);
void initback(back *b);
void initperso(perso *p);
void afficherback(back b,SDL_Surface *ecran);
void afficherEnnemi(Ennemi e,SDL_Surface *ecran,int multijoueur);
void afficherperso(perso p,SDL_Surface *ecran);
void animerEnnemi(Ennemi *e,int multijoueur);
void deplacer(Ennemi *e);
int collisionBB(perso p,Ennemi e,int collision);
void deplacerIA(Ennemi *e,perso p);
void update_ennemi(Ennemi* e, perso p);
void updateEnnemiState(Ennemi* e, int distEH);

#endif
