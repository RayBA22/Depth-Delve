#include "Personnage.h"



Personnage::Personnage(){
    
}
Personnage::Personnage(int x_v, int y_v, int x_init, int y_init):Obj(x_init, y_init){

    vitesse.x = x_v;
    vitesse.y = y_v;
}




void Personnage::deplacement_gauche(){
    int temp = pos.x - vitesse.x;
    if (temp>=0)
        pos.x = temp;
}
void Personnage::deplacement_droite(int x){
    int temp = pos.x + vitesse.x;
    if (temp < x){
        pos.x = temp;
       
        }
}
void Personnage::deplacement_haut(){
    int temp = pos.y - vitesse.y;
        if (temp>=0)
            pos.y = temp;
}
void Personnage::deplacement_bas(int y){

    int temp = pos.y + vitesse.y;
    if (temp < y){
        pos.y =  temp;
     
        }
}


    
bool Personnage::detect_gauche(Vect posm){
    return (posm.x < pos.x-8 && posm.x > pos.x - 80 && (unsigned int)(posm.y-pos.y) < 60);
}


bool Personnage::detect_droite(Vect posm){
    return (posm.x > pos.x+8 && posm.x < pos.x + 80 && (unsigned int)(posm.y - pos.y) < 60);
}
bool Personnage::detect_haut(Vect posm){
    return (posm.y < pos.y+8 && posm.y > pos.y - 50 && (unsigned int)(posm.x - pos.x) < 100);
}
bool Personnage::detect_bas(Vect posm){
    return (posm.y > pos.y-8 && posm.y < pos.y + 50 && (unsigned int)(posm.x - pos.x) < 100);
}