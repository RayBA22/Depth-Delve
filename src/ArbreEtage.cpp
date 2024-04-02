#include "ArbreEtage.h"




NoeudEtage::NoeudEtage(unsigned int prof):etage(prof){

    preced = nullptr;
    ouest = nullptr;
    est = nullptr;
}



ArbreEtage::ArbreEtage(){
    noeudActuel = new NoeudEtage(0);


}

void ArbreEtage::changerHauteur(unsigned int prof){
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
        unsigned int prof = noeudActuel->etage.get_profondeur()+1;
        changerHauteur(prof);
        noeudActuel->ouest = new NoeudEtage(prof);
    }
    
    noeudActuel->ouest->preced = noeudActuel;
    noeudActuel = noeudActuel->ouest;
}
    

void ArbreEtage::allerEst(){
    if (noeudActuel->est == nullptr){
        unsigned int prof = noeudActuel->etage.get_profondeur()+1;
        changerHauteur(prof);
        noeudActuel->est = new NoeudEtage(noeudActuel->etage.get_profondeur()+1);
    }
    
    noeudActuel->est->preced = noeudActuel;
    noeudActuel = noeudActuel->est;
}





Vect ArbreEtage::get_tailleEtage_actuel()const{
        return noeudActuel->etage.get_tailleEtage();
    }

type_Etage ArbreEtage::get_typeEtage_actuel()const{
    return noeudActuel->etage.get_typeEtage();
}