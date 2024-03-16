#include "Personnage.h"

Personnage::Personnage(){
    
}
Personnage::Personnage(entier x_init, entier y_init): Obj(x_init, y_init){
}




void Personnage::deplacement_gauche(){

    pos.x = pos.x - vitesse.x;
}
void Personnage::deplacement_droite(){

    pos.x = pos.x + vitesse.x;
}
void Personnage::deplacement_haut(){

    pos.y = pos.y - vitesse.y;
}
void Personnage::deplacement_bas(){


    pos.y = pos.y + vitesse.y;
}