#ifndef _ETAGE_
#define _ETAGE_

#include "Vect.h"
#include "Minerai.h"

const int maxMinerai=7, maxtaille=1000  ;

enum type_Etage {grotte, mine_gelee, pronfondeur_volcanique};

class Etage
{

public:
    type_Etage id;
    Vect tailleEtage;
    Minerai tabMinerai[maxMinerai]; 
    unsigned int nbMinerai, profondeur;
    

    Etage(unsigned int prof);
    void initEtage();
    type_Minerai get_idMinerai(int i)const;
    bool est_detruit(int i)const;
    type_Minerai randomiseurMinerai()const;
    Vect get_posMinerai(int i)const;
    entier get_MineraiHP(int i)const;
    
    Vect get_tailleEtage()const;
    unsigned int get_profondeur()const;
    type_Etage get_typeEtage()const;
    void se_detruit(entier deg, coord i);
    unsigned int get_nbMinerai()const;
    
};




#endif