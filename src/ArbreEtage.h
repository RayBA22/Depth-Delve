#ifndef _ARBREETAGE_
#define _ARBREETAGE_

#include "Etage.h"

enum orientation
{
    PRECED,
    EST,
    OUEST,
    NONE
};

class NoeudEtage
{

public:
    NoeudEtage *preced, *ouest, *est; // respectivement le pere, le fils gauche, le fils droit du noeud courant
    Etage etage;

    NoeudEtage(int prof);

    void detruireArbre();
    
};

class ArbreEtage
{

private:
    NoeudEtage *noeudActuel;
    int hauteur;

    void revenirRacine();


public:
    ArbreEtage();
    ~ArbreEtage();
    
    void changerHauteur(int prof);
    void allerPrecedent();
    void allerOuest();
    void allerEst();

    int get_nbMinerai_actuel() const;
    type_Minerai get_idMinerai_actuel(int i) const;

    int get_mineraiHP_actuel(int i) const;
    Vect get_posMinerai_actuel(int i) const;

    int get_nbEnnemi_actuel() const;
    type_Ennemi get_idEnnemi_actuel(int i) const;
    int get_EnnemiHP_actuel(int i) const;
    Vect get_posEnnemi_actuel(int i) const;
    bool est_mort(int i) const;
    bool tous_mort();

    bool detecter(int i, Vect position);
    void suivre(int i, Vect position);
    bool toucher(int i, Vect position);

    type_Etage get_typeEtage_actuel() const;
    Vect get_tailleEtage_actuel() const;

    void prenddmg(int dmg, int i);
    void se_detruit_Minerai(int deg, int i);
    bool est_detruit_Minerai(int i) const;

    
    void resetArbre();
};

#endif