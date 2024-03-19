#include "IHM.h"


IHM::IHM(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(450, 450, 0, &window, &renderer);

}


IHM::~IHM(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool IHM::action_Joueur()
{   
    
    SDL_Event event;
    
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT) {
                return false;
            }
        switch (event.key.keysym.sym)
            {
            case SDLK_z:
                jeu.Joueur_haut();
                break;
            case SDLK_q:
                jeu.Joueur_gauche();
                break;

            case SDLK_s:
                jeu.Joueur_bas();
                break;

            case SDLK_d:
                jeu.Joueur_droite();
                break;
                
            
            case SDLK_ESCAPE:
                return false;
                
                

            default:
                
                break;
            }
    }
    return true;
}

void IHM::dessiner_Joueur(){
    Vect pos = jeu.get_Joueurpos();
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect rect = {10*pos.y, 10*pos.x, 8, 15};
    SDL_RenderFillRect(renderer, &rect);
   

}


void IHM::dessiner_Etage(){
    Vect taille = jeu.get_tailleEtagact();
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = {0, 0, 10*taille.y, 10*taille.x, };
    SDL_RenderFillRect(renderer, &rect);

}

void IHM::boucleJeu(){

    bool rester = true;
    while (rester)
    {
        rester = action_Joueur();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        dessiner_Etage();
        dessiner_Joueur();
        
        SDL_RenderPresent(renderer);

    }
    

}