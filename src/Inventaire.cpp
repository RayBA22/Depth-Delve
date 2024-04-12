#include "Inventaire.h"

Inventaire::Inventaire(){
    reset_Minerai();
    reset_Mission();
    nbmission = 0;
    nbEnnemimort = 0;
}
void Inventaire::ajouter_Minerai(type_Minerai minerai){

    tabnbMinerai[minerai] ++;
}

void Inventaire::ajouter_Ennemi(){
    nbEnnemimort ++;
}


void Inventaire::reset_Minerai(){
    for (int i=0; i<6; i++)
        tabnbMinerai[i] = 0;
}

void Inventaire::reset_Mission(){
    for (int i=0; i<6; i++)
        tabmission[i] = nbmission*(6-i);
}

bool Inventaire::est_accomplie(){
    
    for (int i=0; i<6; i++)
        if (tabnbMinerai[i] < tabmission[i])
            return false;
    return true;
}


void Inventaire::valider_mission(){
    if (est_accomplie()){
        reset_Minerai();
        reset_Mission();
        nbmission ++;
    }
}


string Inventaire::formuler_mission(){

    
    info_mission = "Mission: Pierre: " + to_string(tabmission[0]) + "\nCuivre: " + to_string(tabmission[1])+ 
    "\nFer" + to_string(tabmission[2]) + "\nArgent: "+ to_string(tabmission[3]) + 
    "\nOr" + to_string(tabmission[4]) + "\nDiamant" + to_string(tabmission[5]);
    return info_mission;
}


int Inventaire::get_nbMinerai(int indice)const{
    return tabnbMinerai[indice];
}




