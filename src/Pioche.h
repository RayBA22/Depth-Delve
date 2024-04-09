#ifndef _PIOCHE_
#define _PIOCHE_
#include "Vect.h"

enum idPioche {pierre, fer, diamond};

class Pioche
{
public:
    
    idPioche id;
    float dmg; 
    
    Pioche();
    Pioche(idPioche idp);
    

    idPioche get_idPioche()const;
    float get_dmgPioche()const;
};







#endif