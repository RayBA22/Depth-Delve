#ifndef _PNJ_
#define _PNJ_

#include "Personnage.h"

/**
 * @class Pnj
 * Classe utilisant la classe Personnage 
*/

class Pnj: public Personnage
{
public:

    /**
     * @brief Constructeur par défaut
    */
    Pnj();

    /**
     * @brief Constructeur qui initialise les composantes avec les valeurs passées en parametres
     * @param vitessex, vitessey, posx, posy : entiers
    */
    Pnj(int vitessex, int vitessy, int posx, int posy);
};





#endif