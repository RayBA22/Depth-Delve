#ifndef _MINERAI_
#define _MINERAI_

#include "Obj.h"
enum type_Minerai {Pierre=0 ,Cuivre=2, Fer=1, Argent=3, Or=4, Diamant=5};

class Minerai: public Obj
{

public:
    
    type_Minerai id;
    bool detruit;

    Minerai();
    Minerai(type_Minerai idm,  int x_init, int y_init);
    type_Minerai get_idMinerai()const;

    void se_detruit(int deg);
    bool est_detruit()const;

};






#endif