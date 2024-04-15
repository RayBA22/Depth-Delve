#ifndef _PERSONNAGE_
#define _PERSONNAGE_

#include "Obj.h"


/**
 * @class Personnage
 * Modélise certaines données nécessaires pour les classes Joueur, Pnj, et Ennemi, en utilisant la classe Obj
*/

class Personnage: public Obj
{


protected:
    /**
     * @param vitesse : Vect
    */
    Vect vitesse;

public:
    /**
     * @brief Constructeur par défaut 
    */
    Personnage();

    /**
     * @brief Constructeur qui initialise les composantes avec les valeurs passées en paramètre
     * @param x_v, y_v, x_init, y_init : entiers
    */
    Personnage(int x_v, int y_v, int x_init, int y_init);

    /**
     * @brief Fonction permettant au personnage de se déplacer vers la gauche sauf si le bord se trouve à gauche
    */
    void deplacement_gauche();

    /**
     * @brief Fonction permettant au personnage de se déplacer vers la droite sauf si le bord entré en paramètre se trouve à droite
     * @param x : entier
    */
    void deplacement_droite(int x);

    /**
     * @brief Fonction permettant au personnage de se déplacer vers le haut si le bord ne se trouve pas en haut
    */
    void deplacement_haut();

    /**
     * @brief Fonction permettant au personnage de se déplacer vers le bas si le bord entré en paramètre ne se trouve pas en bas
     * @param y : entier
    */
    void deplacement_bas(int y);
    
    /**
     * @brief Fonction qui détecte la présence d'un Objet à gauche du personnage selon un vecteur pris en paramètre
     * @return booléen
    */
    bool detect_gauche(Vect posm);

    /**
     * @brief Fonction qui détecte la présence d'un Objet à droite du personnage selon un vecteur pris en paramètre
     * @return booléen
    */
    bool detect_droite(Vect posm);

    /**
     * @brief Fonction qui détecte la présence d'un Objet au-dessus du personnage selon un vecteur pris en paramètre
     * @return booléen
    */
    bool detect_haut(Vect posm);

    /**
     * @brief Fonction qui détecte la présence d'un Objet en dessous du personnage selon un vecteur pris en paramètre
     * @return booléen
    */
    bool detect_bas(Vect posm);

};




#endif