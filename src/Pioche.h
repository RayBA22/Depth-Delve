#ifndef _PIOCHE_
#define _PIOCHE_
#include "Vect.h"

enum idPioche {nop, pierre, fer, diamond};

class Pioche
{
public:
    
    idPioche id;
    int dmg; 
    
    Pioche();
    Pioche(idPioche idp);
    

    idPioche get_idPioche()const;
    int get_dmgPioche()const;
};







#endif