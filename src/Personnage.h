#ifndef _PERSONNAGE_
#define _PERSONNAGE_

#include "Obj.h"




class Personnage: public Obj
{

public:
    
    Vect vitesse;
    
    Personnage();
    Personnage(int x_v, int y_v, int x_init, int y_init);
    void deplacement_gauche();
    void deplacement_droite(int x);
    void deplacement_haut();
    void deplacement_bas(int y);
    
    bool detect_gauche(Vect posm);
    bool detect_droite(Vect posm);
    bool detect_haut(Vect posm);
    bool detect_bas(Vect posm);

};




#endif