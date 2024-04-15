#ifndef _PIOCHE_
#define _PIOCHE_
#include "Vect.h"

enum idPioche {nop, pierre, fer, diamond};


/**
 * @class Pioche
 * Modélise les données relatives à la pioche : la vitesse de minage et les dégats infligés aux ennemis.
*/
class Pioche
{
public:
    
    /**
     * @param id : idPioche
    */
    idPioche id;

    /**
     * @param dmg : entier
     * 
    */
    int dmg; 
    
    /**
     * @brief Constructeur par défaut
    */
    Pioche();

    /**
     * @brief Constructeur qui utilise la valeur passée en paramètre pour identifiant
     * @param idp : idPioche
    */
    Pioche(idPioche idp);
    
    /**
     * @brief Accesseur qui renvoie l'identifiant de la pioche
     * @return idPioche
    */
    idPioche get_idPioche()const;

    /**
     * @brief Accesseur qui renvoie la valeur d'attaque de la pioche
     * @return entier
    */
    int get_dmgPioche()const;
};







#endif