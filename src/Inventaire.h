#ifndef _INVENTAIRE_
#define _INVENTAIRE_

#include "Minerai.h"
#include <string>

class Inventaire
{

public:
    int tabnbMinerai[6], tabmission[6];
    int nbmission;
    string info_mission;
    int nbEnnemimort;
    //peut etre l'argent 
    //interface dans l'inventaire pour les échanges et les achats
    Inventaire();
    void ajouter_Minerai(type_Minerai minerai);
    void ajouter_Ennemi();
    void reset_Minerai();
    void reset_Mission();
    int get_nbMinerai(int indice)const;
    bool est_accomplie();
    void valider_mission();
    string formuler_mission();
    
};





#endif