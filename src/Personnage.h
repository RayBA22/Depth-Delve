#ifndef _PERSONNAGE_
#define _PERSONNAGE_

#include "Obj.h"

enum type_perso{joueur, pnj, ennemi};


class Personnage: public Obj
{

public:
    type_perso id;
    Vect vitesse;
    
    Personnage();
    Personnage(entier x_v, entier y_v, entier x_init, entier y_init);
    void deplacement_gauche();
    void deplacement_droite();
    void deplacement_haut();
    void deplacement_bas();
    type_perso get_id()const;

};




#endif