#ifndef _OBJET_
#define _OBJET_

#include "Vect.h"


/**
 * @class Obj
 * Modélise tout objet dans le jeu qui possède une position et une quantité de points de vie
*/

class Obj
{

public: //mettre en privé
    
    /**
     * @param pos : Vect
    */
    Vect pos;

    /**
     * @param HP : entier
    */
    int HP;

    /**
     * @brief Constructeur par défaut
    */
    Obj();

    /**
     * @brief Constructeur qui initialise les composantes avec les valeurs passées en paramètre
    */
    Obj(int x_init, int y_init);
    
    /**
     * @brief Accesseur qui renvoie la position de l'objet sous forme d'un objet de la classe Vect (un vecteur)
     * @return Vect
    */
    Vect get_position()const;

    /**
     * @brief Accesseur qui renvoie la quantité de points de vie restants de l'objet
     * @return entier
    */
    int get_HP()const;
    
};







#endif