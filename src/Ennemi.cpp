#include "Ennemi.h"

Ennemi::Ennemi(){
    id = ennemi;
}

Ennemi::Ennemi(entier vitessex, entier vitessy, entier posx, entier posy):Personnage(vitessex, vitessy, posx, posy) {
    id = ennemi;
}