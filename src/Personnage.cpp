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

void Personnage::deplacement_gauche(){
    int temp = pos.x - vitesse.x;
    if (temp>=0)
        pos.x = temp;
}
void Personnage::deplacement_droite(coord x){
    int temp = pos.x + vitesse.x;
    if (temp < x){
        pos.x =  temp;
       
        }
}
void Personnage::deplacement_haut(){
    int temp = pos.y - vitesse.y;
        if (temp>=0)
            pos.y = temp;
}
void Personnage::deplacement_bas(coord y){

    int temp = pos.y + vitesse.y;
    if (temp < y){
        pos.y =  temp;
     
        }
}