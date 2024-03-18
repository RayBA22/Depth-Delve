#include "Inventaire.h"

Inventaire::Inventaire(){
    for (int i=0; i<6; i++)
        tabMinerai[i] = 0;
}
void Inventaire::ajouter_Minerai(type_Minerai minerai){

    tabMinerai[minerai] ++;
}