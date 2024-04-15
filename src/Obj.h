#ifndef _OBJET_
#define _OBJET_

#include "Vect.h"




class Obj
{

public: //mettre en privé
    
    Vect pos;
    int HP;

    Obj();
    Obj(int x_init, int y_init);
    
    Vect get_position()const;

    int get_HP()const;
    
};







#endif