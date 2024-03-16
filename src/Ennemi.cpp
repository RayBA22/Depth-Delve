#include "Ennemi.h"

Ennemi::Ennemi(){
    id = ennemi;
}

Ennemi::Ennemi(entier x_init, entier y_init): Personnage( x_init, y_init) {
    id = ennemi;
}