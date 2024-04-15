#ifndef _ENNEMI_
#define _ENNEMI_

#include "Personnage.h"

enum type_Ennemi{pierro, ferro, argento=3};


class Ennemi: public Personnage
{
public:
    type_Ennemi id;
    unsigned int dmg;
    bool mort;
    
    Ennemi();
    Ennemi(type_Ennemi ide, int posx, int posy);
    
    type_Ennemi get_idEnnemi()const;
    void prenddmg( int dmg);

    bool est_mort()const;
    
    bool detecter(Vect position);
    void suivre(Vect position, Vect tailleEtage);
    bool toucher(Vect position);

    
    
};





#endif