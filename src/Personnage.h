#ifndef _PERSONNAGE_
#define _PERSONNAGE_

#include "Obj.h"


class Personnage: public Obj
{

public:
    Vect vitesse;
    
    Personnage();
    Personnage(entier x_init, entier y_init);
    void deplacement_gauche();
    void deplacement_droite();
    void deplacement_haut();
    void deplacement_bas();

};




#endif