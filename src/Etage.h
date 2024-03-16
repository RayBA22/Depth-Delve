#ifndef _ETAGE_
#define _ETAGE_

#include "Vect.h"
#include "Minerai.h"


enum type_Etage {grotte, mine_gelee, pronfondeur_volcanique};

class Etage
{

public:
    type_Etage id;
    entier xtaille, ytaille;
    Minerai tabMinerai[5]; 
    unsigned int profondeur;
    

    Etage(type_Etage type, entier xt, entier yt);
    void initEtage();
    type_Minerai get_idMinerai(int i)const;
    bool est_detruit(int i)const;
    type_Minerai randomiseurMinerai()const;
    Vect get_posMinerai(int i)const;
    
    
};




#endif