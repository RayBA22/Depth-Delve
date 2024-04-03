#ifndef _ARBREETAGE_
#define _ARBREETAGE_

#include "Etage.h"

enum orientation  {PRECED, EST, OUEST, NONE};

class NoeudEtage{

public:
    NoeudEtage* preced, *ouest, *est; //respectivement le pere, le fils gauche, le fils droit du noeud courant
    Etage etage;
    

    NoeudEtage(unsigned int prof);

};


class ArbreEtage
{

public:
    
    NoeudEtage* noeudActuel;
    unsigned int hauteur, etagact;



    ArbreEtage();
    void changerHauteur(unsigned int prof);
    void allerPrecedent();
    void allerOuest();
    void allerEst();

    unsigned int get_nbMinerai_actuel()const;
    type_Minerai get_idMinerai_actuel(unsigned int i)const;
    Vect get_tailleEtage_actuel()const;
    type_Etage get_typeEtage_actuel()const;
    
};







#endif