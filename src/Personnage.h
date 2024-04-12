#ifndef _PERSONNAGE_
#define _PERSONNAGE_

#include "Obj.h"




class Personnage: public Obj
{

public:
    
    Vect vitesse;
    
    Personnage();
    Personnage(entier x_v, entier y_v, entier x_init, entier y_init);
    void deplacement_gauche();
    void deplacement_droite(coord x);
    void deplacement_haut();
    void deplacement_bas(coord y);
    
    bool detect_gauche(Vect posm);
    bool detect_droite(Vect posm);
    bool detect_haut(Vect posm);
    bool detect_bas(Vect posm);

};




#endif