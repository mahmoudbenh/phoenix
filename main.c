#include "enemi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

int main()
{

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();


int go=1,multijoueur ; 

enemi e;

background b ; 

SDL_Event event ;
 

SDL_Surface *ecran=NULL ;

screen=SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);



initEnnemi(&e);
	

b=initback(&b);

SDL_BlitSurface(b.imgbackground, NULL, ecran, &(b.posbackground));


SDL_Flip(ecran);




afficherEnnemi(e,&ecran,multijoueur);
SDL_Flip(ecran);
while(go)
{   

SDL_PollEvent(&event);

switch(event.type)
        {

	case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            	{	
		case SDLK_RIGHT:
			e.direction=1;	
		break;

		case SDLK_LEFT: 
			e.direction=0;
		break;	
               
		case SDLK_ESCAPE:
			
			go=0;
			
		break;	
		}
	}
SDL_BlitSurface(b.img, NULL, ecran, &(b.posbackground));




deplacer(&e);

animerEnnemi(e,multijoueur);
collisionBB(p,e,collision);
deplacerIA(&e,p);
update_ennemi(&e,p);

afficherEnnemi(e,&ecran,multijoueur);

	
	
SDL_Flip(ecran);
e.direction=-1;
}

SDL_FreeSurface(b.imgbackground);

SDL_Quit();

return EXIT_SUCCESS;
}
