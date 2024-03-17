#include "Personnage.h"

Personnage::Personnage(){
    
}
Personnage::Personnage(entier x_v, entier y_v, entier x_init, entier y_init):Obj(x_init, y_init){

    vitesse.x = x_v;
    vitesse.y = y_v;
}


type_perso Personnage::get_id()const{
    return id;
}

void Personnage::deplacement_haut(){

    pos.x = pos.x - vitesse.x;
}
void Personnage::deplacement_bas(){

    pos.x = pos.x + vitesse.x;
}
void Personnage::deplacement_gauche(){

    pos.y = pos.y - vitesse.y;
}
void Personnage::deplacement_droite(){

    pos.y = pos.y + vitesse.y;
}