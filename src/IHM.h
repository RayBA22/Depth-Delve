#include <SDL2/SDL.h>
#include "Jeu.h"

class IHM
{

public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Jeu jeu;

    IHM();
    ~IHM();
    bool action_Joueur();

    
};




