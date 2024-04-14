#include "Ennemi.h"



Ennemi::Ennemi(){
    
    
}


Ennemi::Ennemi( type_Ennemi ide, entier posx, entier posy):Personnage(1, 1, posx, posy) {
    id = ide;
    HP = 1;
    mort = false;
}


type_Ennemi Ennemi::get_idEnnemi()const{

    return id;
}

void Ennemi::prenddmg( int dmg){
    HP -= dmg;
    if (HP <= 0) mort = true;
}


bool Ennemi::est_mort()const{
    return mort;
}

bool Ennemi::detecter(Vect position){

    return (((position.x-pos.x)*(position.x-pos.x) + (position.y-pos.y)*(position.y-pos.y))  <= (id+1)*10000 );
    
}

void Ennemi::suivre(Vect position, Vect tailleEtage){
    if (detecter(position) && !mort){
        if (pos.x < position.x)
            deplacement_droite(tailleEtage.x);
        if (pos.x > position.x)
            deplacement_gauche();
        if (pos.y < position.y)
            deplacement_bas(tailleEtage.y);
        if (pos.y > position.y)
            deplacement_haut();
        
    }
}

bool Ennemi::toucher(Vect position){

    return ((((position.x-pos.x)*(position.x-pos.x) + (position.y-pos.y)*(position.y-pos.y))  <= 10 ) && !mort);
}


