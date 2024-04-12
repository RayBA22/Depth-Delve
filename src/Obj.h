#ifndef _OBJET_
#define _OBJET_

#include "Vect.h"




class Obj
{

public: //mettre en privé
    
    Vect pos;
    entier HP;

    Obj();
    Obj(entier x_init, entier y_init);
    
    Vect get_position()const;

    entier get_HP()const;
    
};







#endif