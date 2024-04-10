#ifndef _JOUEUR_
#define _JOUEUR_

#include "Personnage.h"
#include "Pioche.h"
#include "Inventaire.h"

enum action{Marcher=0, Respirer, Piocher=2};
class Joueur: public Personnage
{
public:
    entier faim;
    Pioche pioche;
    action actJoueur;
    
    //Inventaire inventaire;

    Joueur();
    Joueur(entier posx, entier posy);
    void changer_vitesse();
    void set_posJoueur(entier posx, entier posy);
    float get_dmgJoueur()const;
    entier get_faimJoueur()const;
    idPioche get_ifPioche()const;
    action get_action()const;
    void changer_action();

        
    
    
};








#endif