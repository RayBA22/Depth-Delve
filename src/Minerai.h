#ifndef _MINERAI_
#define _MINERAI_

#include "Obj.h"
enum type_Minerai {Pierre ,Cuivre, Fer, Argent, Or, Diamant};

class Minerai: public Obj
{

public:
    
    type_Minerai id;
    bool detruit;

    Minerai();
    Minerai(type_Minerai idm,  entier x_init, entier y_init);
    type_Minerai get_idMinerai()const;

    void se_detruit(entier deg);
    bool est_detruit()const;

};






#endif