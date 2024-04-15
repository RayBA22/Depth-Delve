
#ifndef _ENNEMI_
#define _ENNEMI_

#include "Personnage.h"

enum type_Ennemi{pierro, ferro, argento=3};


class Ennemi: public Personnage
{
private:

    /**
     * @param id : type_Ennemi
    */
    type_Ennemi id;

    /**
     * @param dmg : entier positif
    */
    unsigned int dmg;

    /**
     * @param mort : booléen
    */
    bool mort;
    
public:
    /**
     * @brief Constructeur par défaut
    */
    Ennemi();

    /**
     * @brief Constructeur qui prend pour paramètre le type de l'ennemi, et ses coordonnées
     * @param ide : type_Ennemi
     * @param posx, posy : entiers
    */
    Ennemi(type_Ennemi ide, int posx, int posy);
    

    /**
     * @brief Accesseur qui renvoie le type de l'ennemi
     * @return type_Ennemi
    */
    type_Ennemi get_idEnnemi()const;

    /**
     * @brief Fonction qui retire des points de vie à l'ennemi lorsqu'il est attaqué
     * @param dmg : entier
    */
    void prenddmg( int dmg);


    /**
     * @brief Accesseur booléen qui renvoie vrai si l'ennemi n'a plus de points de vie, faux sinon
     * @return booléen
    */
    bool est_mort()const;
    

    /**
     * @brief Fonction booléenne qui renvoie vrai si le joueur est suffisamment proche pour que l'ennemi le suive, faux sinon
     * @return booléen
    */
    bool detecter(Vect position);

    /**
     * @brief Fonction qui fait avancer l'ennemi vers le joueur
     * @param position, tailleEtage : Vect
    */
    void suivre(Vect position, Vect tailleEtage);

    /**
     * @brief Fonction booléenne qui renvoie vrai si le joueur est en contact avec l'ennemi, faux sinon
     * @return booléen
    */
    bool toucher(Vect position);

    
    
};





#endif