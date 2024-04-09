#ifndef _JOUEUR_
#define _JOUEUR_

#include "Personnage.h"
#include "Pioche.h"
#include "Inventaire.h"


class Joueur: public Personnage
{
public:
    entier faim;
    Pioche pioche;
    
    //Inventaire inventaire;

    Joueur();
    Joueur(entier vitessex, entier vitessy, entier posx, entier posy);
    void set_posJoueur(entier posx, entier posy);
    float get_dmgJoueur()const;
    entier get_faimJoueur()const;
    idPioche get_ifPioche()const;
    
    
    
};








#endif