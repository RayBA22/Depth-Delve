#ifndef _OBJET_
#define _OBJET_

#include "Vect.h"




class Obj
{

public: //mettre en privé
    
    Vect pos;
    entier HP=5;

    Obj();
    Obj(entier x_init, entier y_init);
    
    Vect get_position()const;
    
};







#endif