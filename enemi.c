#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "enemi.h"

void initEnnemi(Ennemi *e)
{

    e->posEnnemi.x=1500;
    e->posEnnemi.y=450;
    e->posEnnemi.w = 89;
    e->posEnnemi.h = 150;
    e->posMax.x = 1800;
    e->posMax.y = 450;
    e->posMin.x = 1300;
    e->posMin.y = 450;
    
  e->posSprite.x=0;
  e->posSprite.y=0;
  e->posSprite.w=445/5;
  e->posSprite.h=300/2;
  e->sprite1=IMG_Load("sprite sheet_marche.png");
  e->posSprite2.x=0;
  e->posSprite2.y=0;
  e->posSprite2.w=534/6;
  e->posSprite2.h=300/2;
  e->sprite2=IMG_Load("sprite sheet_action.png");
  e->direction=0;
  e->State = WAITING;
}

void initback(back *b)
{
    b->imgbackground= NULL;
    b->imgbackground= IMG_Load("imgbackground.png");

    b->posbackground.x=0;
    b->posbackground.y=0;
}
/*void initperso(perso *p)
{
    p->poshero.x = 20;
    p->poshero.y = 500;
    p->poshero.w = 170;
    p->poshero.h = 250;
    p->imageh= IMG_Load("djapa.png");
}
void afficherperso(perso p,SDL_Surface *ecran)
{
    SDL_BlitSurface(p.imageh, NULL, ecran, &p.poshero);
}
void afficherback(back b,SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
}
*/
void afficherEnnemi(Ennemi e,SDL_Surface *ecran,int multijoueur)
{  

   if(multijoueur==0)
   {
    switch(e.State)
     {
      case WAITING:
      SDL_BlitSurface(e.sprite1,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case FOLLOWING :
      
      SDL_BlitSurface(e.sprite1,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case ATTACKING:
      SDL_BlitSurface(e.sprite2,&e.posSprite2,ecran, &e.posEnnemi);
      break;
 
    }
    }
       if(multijoueur==1)
   {
    switch(e.State)
     {
      case WAITING:
      SDL_BlitSurface(e.sprite3,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case FOLLOWING :
      
      SDL_BlitSurface(e.sprite3,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case ATTACKING:
      SDL_BlitSurface(e.sprite4,&e.posSprite2,ecran, &e.posEnnemi);
      break;
    
    }
    }
}

void animerEnnemi(Ennemi *e,int multijoueur)
{

    
    if(multijoueur==0)
    {
    switch (e->State)
    {
    case WAITING:
    if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case FOLLOWING :
   if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case ATTACKING:
  if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite2.h;
  if(e->posSprite2.x==534-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite2.y=e->direction * e->posSprite2.h;
   if(e->posSprite2.x==534-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
 break; 
 }
 }
 if(multijoueur==1)
 {
   switch (e->State)
    {
    case WAITING:
    if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case FOLLOWING :
   if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case ATTACKING:
  if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite2.h;
  if(e->posSprite2.x==270-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite2.y=e->direction * e->posSprite2.h;
   if(e->posSprite2.x==270-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
 break; 
 }
 }
}

void deplacer(Ennemi *e)
{
   if((e->direction==0))//droite
    {

        if((e->posEnnemi.x<e->posMax.x)&&(e->posEnnemi.x>=e->posMin.x))
        {
            e->posEnnemi.x+=5;
        }
        else if((e->posEnnemi.x==e->posMax.x))
        {
            e->direction=1;
        }
    }
   else if(e->direction==1)//gauche
    {

        if((e->posEnnemi.x<=e->posMax.x)&&(e->posEnnemi.x>e->posMin.x))
        {
            e->posEnnemi.x-=5;
        }
        else if((e->posEnnemi.x==e->posMin.x))
        {
            e->direction=0;

        }
    }
   
}
   

int collisionBB(perso p,Ennemi e,int collision)
{
    if((p.poshero.x + p.poshero.w<e.posEnnemi.x)||(p.poshero.x>e.posEnnemi.x+e.posEnnemi.w)||(p.poshero.y+p.poshero.h<e.posEnnemi.y)||(p.poshero.y>e.posEnnemi.y+e.posEnnemi.h))
    {
        collision=0;
    }
    else
    {
        collision=1;
    }
    return collision;
}
void deplacerIA(Ennemi *e,perso p)
{
	if (p.poshero.x<e->posEnnemi.x) //hero à gauche de l'ennemi
	{
		e->direction=1;
		deplacer(e);
	}

	if (p.poshero.x>e->posEnnemi.x) // hero a droite
	{
		e->direction=0;
		deplacer(e);
	}
}
void update_ennemi(Ennemi* e, perso p)
{
	int distEH,multijoueur;
	if(e->posEnnemi.x>=p.poshero.x)
         distEH=e->posEnnemi.x-(p.poshero.x + p.poshero.w);
       else
         distEH=(p.poshero.x + p.poshero.w)-e->posEnnemi.x;
	//printf("Mabin l Ennemi w el hero  = %d\t E->State = %d\n", distEH,E->State);
    	switch(e->State)
    	{
        	case WAITING :
        	{
            		animerEnnemi(e,multijoueur);
            		deplacer(e);
            		break;
        	}

        	case FOLLOWING :
        	{
            		animerEnnemi(e,multijoueur);
            		deplacerIA(e,p);
            		//deplacer(e);
            		break;
        	}

        	case ATTACKING :
        	{
		    	animerEnnemi(e,multijoueur);
		    	//deplacerIA(e,p);
			//deplacer(e);
			break;
        	}       
    	}

	updateEnnemiState(e, distEH);	
}
void updateEnnemiState(Ennemi* e, int distEH)
{
     printf("distance=%d\n",distEH);
	if (distEH>160)
	{
		e->State=0;

	}

	if (distEH>100 && distEH<=150)
	{
		e->State=1;
	}

	if (distEH>0 && distEH<=50 )
	{
		e->State=2;
	}
}

