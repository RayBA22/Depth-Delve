#include "Pnj.h"


Pnj::Pnj(){
    id = pnj;
}
Pnj::Pnj(entier vitessex, entier vitessy, entier posx, entier posy):Personnage(vitessex, vitessy, posx, posy){
    id = pnj;
}