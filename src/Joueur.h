#ifndef _JOUEUR_
#define _JOUEUR_

#include "Personnage.h"
#include "Pioche.h"
#include "Inventaire.h"

enum action{Marcher=0, Respirer, Piocher=2};


/**
 * @class Joueur
 * Modélise le Joueur en utilisant la classe Personnage
*/

class Joueur: public Personnage
{
public:

    /**
     * @param faim : entier
    */
    int faim;

    /**
     * @param pioche : Pioche
    */
    Pioche pioche;

    /**
     * @param actJoueur : action
    */
    action actJoueur;
    
    //Inventaire inventaire;

    /**
     * @brief Constructeur par défaut
    */
    Joueur();

    /**
     * @brief Constructeur qui initialise les composantes avec les valeurs passées en paramètre
     * @param posx, posy : entiers
    */
    Joueur(int posx, int posy);

    /**
     * @brief Fonction permettant de changer la vitesse du joueur selon si celui-ci tient la pioche
    */
    void changer_vitesse();

    /**
     * @brief Fonction permettant de modifier la position du joueur avec les coordonnées entrées en paramètre
     * @param posx, posy : entiers
    */
    void set_posJoueur(int posx, int posy);

    /**
     * @brief Fonction permettant de modifier la quantité de points de vie du joueur selon une quantité entrée en paramètre
     * @param HPs : entier
    */
    void set_HPJoueur(int HPs);

    /**
     * @brief Accesseur qui renvoie les dégâts infligés par le joueur lorsque celui-ci attaque un ennemi ou un minerai
     * @return entier
    */
    int get_dmgJoueur()const;

    /**
     * @brief Accesseur qui renvoie la valeur de satiété du joueur
     * @return entier
    */
    int get_faimJoueur()const;

    /**
     * @brief Accesseur qui renvoie l'identifiant de la pioche que le joueur a en sa possession
     * @return idPioche
    */
    idPioche get_idPioche()const;

    /**
     * @brief Accesseur qui renvoie l'action que le joueur est en train d'effectuer (Marcher, Piocher ou simplement Respirer)
     * @return action
    */
    action get_action()const;

    /**
     * @brief Fonction permettant de modifier l'action que le joueur est en train d'effectuer
    */
    void changer_action();

    /**
     * @brief Fonction permettant de réduire la quantité de points de vie du joueur lorsqu'il est attaqué selon une quantité entrée en paramètre
     * @param dmg : entier
    */
    void prenddmg(int dmg);

    /**
     * @brief Accesseur booléen qui renvoie vrai si le joueur n'a plus de points de vie, faux sinon
     * @return booléen
    */
    bool joueur_mort()const;

    /**
     * @brief Fonction permettant de remettre les composantes liées au joueur à leur valeur initiale
    */
    void reset();





    
    
    
    
};








#endif