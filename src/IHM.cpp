#include "IHM.h"


IHM::IHM(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(200, 200, 0, &window, &renderer);

}


IHM::~IHM(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool IHM::action_Joueur()
{   
    bool re;
    SDL_Event event;
    do
    {
        
        switch (event.key.keysym.sym)
        {
        case SDLK_z:
            jeu.Joueur_haut();
            return true;
        case SDLK_q:
            jeu.Joueur_gauche();
            return true;

        case SDLK_s:
            jeu.Joueur_bas();
            return true;

        case SDLK_d:
            jeu.Joueur_droite();
            return true;
            
        
        case 'x':
            jeu.Joueur_droite();
            return false;
            

        default:
            re = true;
            break;
        }
    } while (re);
    return true;
}