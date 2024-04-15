#include "Inventaire.h"

Inventaire::Inventaire(){
    reset();
    
}

void Inventaire::reset(){
    nbmission = 0;
    nbEnnemimort = 0;
    reset_Minerai();
    reset_Mission();
    
    statut = false;
}


void Inventaire::ajouter_Minerai(type_Minerai minerai){

    tabnbMinerai[ (int) minerai] ++;
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
    valider_mission();
    
    info_mission = "Mission: \nPierre: " + to_string(tabmission[0]) + "\nFer: " + to_string(tabmission[1])+ 
    "\nCuivre: " + to_string(tabmission[2]) + "\nArgent: "+ to_string(tabmission[3]) + 
    "\nOr: " + to_string(tabmission[4]) + "\nDiamant: " + to_string(tabmission[5]);
    return info_mission;
}


int Inventaire::get_nbMinerai(int indice)const{
    return tabnbMinerai[indice];
}

int Inventaire::get_nbmort()const{
    return nbEnnemimort;
}


bool Inventaire::get_statut()const{
    return statut;
}


void Inventaire::changer_statut(){
    statut = !statut;
}


int Inventaire::get_nbmission_accomplie()const{
    return nbmission;
}


void Inventaire::sauver(int HP){

    ofstream fichier("../assets/sauvegarde/sauvegarde.txt", ios::trunc);

    if (!fichier)
        cout << "pas chargé" << endl;

    for (int i=0; i < 6; i++){
        fichier << tabnbMinerai[i] << " ";
        fichier << tabmission[i] << " ";
    }
    fichier << nbmission << " " << nbEnnemimort << " " << HP;

    fichier.close();
}



int Inventaire::charger(){

    ifstream fichier("../assets/sauvegarde/sauvegarde.txt");


    for (int i=0; i < 6; i++){
        fichier >> tabnbMinerai[i];
        fichier >> tabmission[i];
    }       

    fichier >> nbmission  >> nbEnnemimort;


    int HP;
    fichier >> HP;
    
    fichier.close();

    return HP;
    
}