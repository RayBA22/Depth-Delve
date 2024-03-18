#ifndef _INVENTAIRE_
#define _INVENTAIRE_

#include "Minerai.h"

class Inventaire
{

public:
    unsigned int tabMinerai[6];
    //peut etre l'argent 
    //interface dans l'inventaire pour les échanges et les achats
    Inventaire();
    void ajouter_Minerai(type_Minerai minerai);
    
    
};





#endif