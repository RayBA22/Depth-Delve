#ifndef _ETAGE_
#define _ETAGE_

#include "Vect.h"
#include "Minerai.h"
#include "Ennemi.h"

const int maxMinerai=25,maxEnnemi=15, maxtaille=1000  ;

enum type_Etage {grotte, mine_gelee, pronfondeur_volcanique};

class Etage
{

public:
    type_Etage id;
    Vect tailleEtage;
    Minerai tabMinerai[150]; 
    Ennemi tabEnnemi[30];
    int nbMinerai, profondeur, nbEnnemi;
    
    
    Etage(int prof);
    void initEtage();
    

    type_Minerai get_idMinerai(int i)const;
    bool est_detruit(int i)const;
    type_Minerai randomiseurMinerai()const;
    Vect get_posMinerai(int i)const;
    entier get_MineraiHP(int i)const;
     int get_nbMinerai()const;

    type_Ennemi randomiseurEnnemi();
    type_Ennemi get_idEnnemi(int i)const;
    bool est_mort(int i)const;
    Vect get_posEnnemi(int i)const;
    entier get_EnnemiHP(int i)const;
     int get_nbEnnemi()const;
    
    void prenddmg( int dmg, int i);
    bool detecter(int i, Vect position);
    void suivre(int i, Vect position);
    bool toucher(int i, Vect position);



    Vect get_tailleEtage()const;    
     int get_profondeur()const;
    type_Etage get_typeEtage()const;
    void se_detruit(entier deg, coord i);
    
    bool tous_mort();
};





#endif