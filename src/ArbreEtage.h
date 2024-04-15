#ifndef _ARBREETAGE_
#define _ARBREETAGE_

#include "Etage.h"

enum orientation
{
    PRECED,
    EST,
    OUEST,
    NONE
};


/**
 * @class NoeudEtage
 * Modéliste chaque étage par un noeud
*/
class NoeudEtage
{

public:

    /**
     * @param preced, ouest, est : pointeurs sur NoeudEtage
    */
    NoeudEtage *preced, *ouest, *est; // respectivement le pere, le fils gauche, le fils droit du noeud courant

    /**
     * @param etage : Etage
    */
    Etage etage;

    
    /**
     * @brief Constructeur
     * @param prof : entier
    */
    NoeudEtage(int prof);


    /**
     * @brief Remplace les fils gauche et droit du noeud par des pointeurs nuls
    */
    void detruireArbre();
    
};


/**
 * @class ArbreEtage
 * Modélise l'ensemble d'étages par un arbre
*/
class ArbreEtage
{

private:

    /**
     * @param noeudActuel : pointeur sur NoeudEtage
    */
    NoeudEtage *noeudActuel;

    /**
     * @param hauteur : entier
    */
    int hauteur;


    /**
     * @brief Fonction qui fait désigner la racine de l'arbre au pointeur
    */
    void revenirRacine();


public:


    /**
     * @brief Constructeur
    */
    ArbreEtage();

    /**
     * @brief Destructeur
    */
    ~ArbreEtage();
    

    /**
     * @brief Fonction qui remplace la hauteur par la profondeur entrée en paramètre si celle-ci est supérieure à la hauteur
     * @param prof : entier
    */
    void changerHauteur(int prof);

    /**
     * @brief Fonction qui fait désigner au pointeur le noeud père du noeud actuel
    */
    void allerPrecedent();

    /**
     * @brief Fonction qui fait désigner au pointeur le fils gauche du noeud actuel
    */
    void allerOuest();

    /**
     * @brief Fonction qui fait désigner au pointeur le fils droit du noeud actuel
    */
    void allerEst();


    /**
     * @brief Fonction qui renvoie le nombre de minerai de l'étage désigné par le pointeur
    */
    int get_nbMinerai_actuel() const;

    /**
     * @brief Accesseur qui renvoie le type du minerai d'indice entré en paramètre
     * @param i : entier
     * @return type_Minerai
    */
    type_Minerai get_idMinerai_actuel(int i) const;


    /**
     * @brief Accesseur qui renvoie la quantité de points de vie du minerai d'indice entré en paramètre
     * @param i : entier
     * @return entier
    */
    int get_mineraiHP_actuel(int i) const;

    /**
     * @brief Accesseur qui renvoie la position du minerai d'indice entré en paramètre sous forme d'un vecteur
     * @param i : entier
     * @return Vect
    */
    Vect get_posMinerai_actuel(int i) const;


    /**
     * @brief Accesseur qui renvoie le nombre d'ennemis présents dans l'étage désigné par le pointeur
     * @return entier
    */
    int get_nbEnnemi_actuel() const;

    /**
     * @brief Accesseur qui renvoie le type de l'ennemi d'indice entré en paramètre
     * @param i : entier
     * @return type_Ennemi
    */
    type_Ennemi get_idEnnemi_actuel(int i) const;

    /**
     * @brief Accesseur qui renvoie la quantité de points de vie de l'ennemi d'indice entré en paramètre
     * @param i : entier
     * @return entier
    */
    int get_EnnemiHP_actuel(int i) const;

    /**
     * @brief Accesseur qui renvoie la position de l'ennemi d'indice entré en paramètre sous forme de vecteur
     * @param i : entier
     * @return Vect
    */
    Vect get_posEnnemi_actuel(int i) const;

    /**
     * @brief Accesseur booléen qui renvoie vrai si l'ennemi d'indice entré en paramètre a été vaincu, faux sinon
     * @param i : entier
     * @return booléen
    */
    bool est_mort(int i) const;

    /**
     * @brief Fonction booléenne qui renvoie vrai si tous les ennemis de l'étage ont été vaincus, faux sinon
     * @return booléen
    */
    bool tous_mort();


    /**
     * @brief Fonction booléenne qui renvoie vrai si le joueur est assez proche de l'ennemi aux données
     * entrées en paramètre pour que celui-ci suive le joueur, faux sinon
     * @param i : entier
     * @param position : Vect
     * @return booléen
    */
    bool detecter(int i, Vect position);

    /**
     * @brief Fonction qui permet à l'ennemi aux données entrées en paramètre de suivre le joueur lorsque celui-ci est assez proche
     * @param i : entier
     * @param position : Vect
    */
    void suivre(int i, Vect position);

    /**
     * @brief Fonction booléenne qui renvoie vrai si l'ennemi aux données entrées en paramètre est en contact avec le joueur, faux sinon
     * @param i : entier
     * @param position : Vect
     * @return booléen
    */
    bool toucher(int i, Vect position);


    /**
     * @brief Accesseur qui renvoie le type de l'étage désigné par le pointeur
     * @return type_Etage
    */
    type_Etage get_typeEtage_actuel() const;

    /**
     * @brief Accesseur qui renvoie la taille de l'étage désigné par le pointeur sous forme d'un vecteur
     * @return Vect
    */
    Vect get_tailleEtage_actuel() const;


    /**
     * @brief Fonction qui retire des points de vie à l'ennemi d'indice entré en paramètre selon les dégats entrés en paramètre
     * @param dmg, i : entiers
    */
    void prenddmg(int dmg, int i);

    /**
     * @brief Fonction qui retire des points de vie au minerai d'indice entré en paramètre selon les dégats entrés en paramètre
     * @param deg, i : entiers
    */
    void se_detruit_Minerai(int deg, int i);

    /**
     * @brief Fonction booléenne qui renvoie vrai si le minerai d'indice entré en paramètre n'a plus de points de vie, faux sinon
     * @param i : entier
     * @return booléen
    */
    bool est_detruit_Minerai(int i) const;

    
    /**
     * @brief Fonction qui revient à la racine de l'arbre, détruit tous les noeuds sauf la racine et remet la hauteur à zéro
    */
    void resetArbre();
};

#endif