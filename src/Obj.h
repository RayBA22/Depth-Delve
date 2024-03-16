#ifndef _OBJET_
#define _OBJET_

#include "Vect.h"

enum type_perso{joueur, pnj, ennemi};


class Obj
{

public: //mettre en privé
    type_perso id;
    Vect pos;
    entier HP;

    Obj();
    Obj(entier x_init, entier y_init);
    type_perso get_id()const;
    Vect get_position()const;
    
};







#endif