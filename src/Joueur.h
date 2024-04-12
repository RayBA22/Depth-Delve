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
    int get_dmgJoueur()const;
    int get_HPJoueur()const;
    entier get_faimJoueur()const;
    idPioche get_idPioche()const;
    action get_action()const;

    void changer_action();
    void prenddmg(int dmg);
    bool joueur_mort()const;

        
    
    
};








#endif