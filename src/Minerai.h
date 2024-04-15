#ifndef _MINERAI_
#define _MINERAI_

#include "Obj.h"

enum type_Minerai {Pierre=0 ,Cuivre=2, Fer=1, Argent=3, Or=4, Diamant=5};


/**
 * @class Minerai
 * Modélise les minerais récoltables par le joueur
*/

class Minerai: public Obj
{

public:
    
    /**
     * @param id : type_Minerai
    */
    type_Minerai id;

    /**
     * @param detruit : booléen
    */
    bool detruit;

    /**
     * @brief Constructeur par défaut
    */
    Minerai();

    /**
     * @brief Constructeur qui initialise les composantes avec les valeurs passées en paramètre
     * @param idm : type_Minerai
     * @param x_init, y_init : entiers
    */
    Minerai(type_Minerai idm,  int x_init, int y_init);

    /**
     * @brief Accesseur qui renvoie le type du minerai
     * @return type_Minerai
    */
    type_Minerai get_idMinerai()const;

    /**
     * @brief Fonction qui réduit les points de vie du minerai lorsque celui-ci est miné selon les dégats infligés entrés en paramètre
     * @param deg : entier
    */
    void se_detruit(int deg);

    /**
     * @brief Accesseur booléen qui retourne vrai si le minerai a été détruit, c'est à dire si ses points de vie sont à 0, et faux sinon
     * @return booléen
    */
    bool est_detruit()const;

};






#endif