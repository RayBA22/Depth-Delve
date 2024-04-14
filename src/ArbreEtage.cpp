#include "ArbreEtage.h"




NoeudEtage::NoeudEtage(int prof):etage(prof){

    preced = nullptr;
    ouest = nullptr;
    est = nullptr;
    
    
    
}

void NoeudEtage::detruireArbre(){

    cout <<  "that" << (ouest == nullptr) << endl;
    if (ouest != nullptr) {
        ouest->detruireArbre();
        delete ouest;
        ouest = nullptr; 
        cout << "destruction ouest"<< endl;
    }
    if (est != nullptr) {
        est->detruireArbre();
        delete est;
        est = nullptr;
        cout << "destruction est"<< endl;
    
    }
}


ArbreEtage::ArbreEtage(){
    hauteur = 0;
    noeudActuel = new NoeudEtage(0);
    
}

ArbreEtage::~ArbreEtage(){
    noeudActuel->detruireArbre();
    delete noeudActuel ;
}


void ArbreEtage::changerHauteur(int prof){
        if (hauteur < prof)
            hauteur = prof;
}

void ArbreEtage::allerPrecedent(){
    if (noeudActuel->preced != nullptr){

        noeudActuel = noeudActuel->preced;
    }
}

void ArbreEtage::allerOuest(){
    if (noeudActuel->ouest == nullptr){
        int prof =  noeudActuel->etage.get_profondeur();
        noeudActuel->ouest = new NoeudEtage(prof + 1);
        cout << prof << endl;
        changerHauteur(prof);
        
    }
    
    noeudActuel->ouest->preced = noeudActuel;
    noeudActuel = noeudActuel->ouest;
}
    

void ArbreEtage::allerEst(){
    if (noeudActuel->est == nullptr){
        int prof = noeudActuel->etage.get_profondeur();
        noeudActuel->est = new NoeudEtage(prof + 1);
        changerHauteur(prof);
    }
    
    noeudActuel->est->preced = noeudActuel;
    noeudActuel = noeudActuel->est;
}







type_Minerai ArbreEtage::get_idMinerai_actuel( int i) const{
    return noeudActuel->etage.get_idMinerai(i);
}

entier ArbreEtage::get_mineraiHP_actuel(int i)const{

    return noeudActuel->etage.get_MineraiHP(i);
}


Vect ArbreEtage::get_tailleEtage_actuel()const{
        return noeudActuel->etage.get_tailleEtage();
    }



type_Etage ArbreEtage::get_typeEtage_actuel()const{
    return noeudActuel->etage.get_typeEtage();
}


 int ArbreEtage::get_nbMinerai_actuel()const{
    return noeudActuel->etage.get_nbMinerai();
}


Vect ArbreEtage::get_posMinerai_actuel(int i)const{
    return noeudActuel->etage.get_posMinerai(i);
}


void ArbreEtage::se_detruit_Minerai(entier deg, coord i){
    noeudActuel->etage.se_detruit(deg, i);
}

bool ArbreEtage::est_detruit_Minerai(int i)const{
    return noeudActuel->etage.est_detruit(i);
}



 int ArbreEtage::get_nbEnnemi_actuel()const{
    return noeudActuel->etage.get_nbEnnemi();
}
type_Ennemi ArbreEtage::get_idEnnemi_actuel( int i)const{
    return noeudActuel->etage.get_idEnnemi(i);
} 

bool ArbreEtage::est_mort(int i)const{
    return noeudActuel->etage.est_mort(i);
}

bool ArbreEtage::tous_mort(){
    return noeudActuel->etage.tous_mort();
}

entier ArbreEtage::get_EnnemiHP_actuel(int i)const{
    return noeudActuel->etage.get_EnnemiHP(i);
}
Vect ArbreEtage::get_posEnnemi_actuel(int i)const{
    return noeudActuel->etage.get_posEnnemi(i);
}


void ArbreEtage::prenddmg( int dmg, int i){
    noeudActuel->etage.prenddmg(dmg, i);
}

bool ArbreEtage::detecter(int i, Vect position){
     return noeudActuel->etage.detecter(i, position);
}

void ArbreEtage::suivre(int i, Vect position){
    noeudActuel->etage.suivre(i, position);
}
bool ArbreEtage::toucher(int i, Vect position){
   return  noeudActuel->etage.toucher(i, position);
}


void ArbreEtage::revenirRacine(){

    while (noeudActuel->preced != nullptr){
        allerPrecedent();
    }
}


void ArbreEtage::resetArbre(){
    revenirRacine();
    noeudActuel->detruireArbre();
    hauteur = 0;
    delete noeudActuel;
    noeudActuel = new NoeudEtage(0);


}