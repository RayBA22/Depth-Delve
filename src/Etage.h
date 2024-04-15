#ifndef _ETAGE_
#define _ETAGE_

#include "Vect.h"
#include "Minerai.h"
#include "Ennemi.h"



enum type_Etage {grotte, mine_gelee, pronfondeur_volcanique};




/**
 * @class Etage
 * Modélise un étage du jeu
*/

class Etage
{

private:

    /**
     * @param id : type_Etage
    */
    type_Etage id;

    /**
     * @param tailleEtage : Vect
    */
    Vect tailleEtage;

    /**
     * @param tabMinerai : tableau de Minerais
    */
    Minerai tabMinerai[150];

    /**
     * @param tabEnnemi : tableau d'Ennemis
    */
    Ennemi tabEnnemi[30];

    /**
     * @param nbMinerai, profondeur, nbEnnemi : entiers
    */
    int nbMinerai, profondeur, nbEnnemi;


    /**
     * @brief Fonction qui initialise l'étage en y plaçant les minerais et ennemis qu'il contient
    */
    void initEtage();


    /**
     * @brief Fonction qui renvoie un type de minerai aléatoire
     * @return type_Minerai
    */
    type_Minerai randomiseurMinerai()const;


    /**
     * @brief Fonction qui renvoie un type d'ennemi aléatoire
     * @return type_Ennemi
    */
    type_Ennemi randomiseurEnnemi();

    
public:
    /**
     * @brief Constructeur qui prend en paramètre la profondeur de l'étage
     * @param prof : entier
    */
    Etage(int prof);

    
    

    /**
     * @brief Fonction qui renvoie le type du minerai d'indice entré en paramètre
     * @param i : entier
     * @return type_Minerai
    */
    type_Minerai get_idMinerai(int i)const;

    /**
     * @brief Accesseur booléen qui renvoie vrai si le minerai d'indice entré en paramètre est détruit, faux sinon
     * @param i : entier
     * @return booléen
    */
    bool est_detruit(int i)const;

    

    /**
     * @brief Accesseur qui renvoie la position du minerai d'indice entré en paramètre sous forme d'objet de la classe Vect
     * @param i : entier
     * @return Vect
    */
    Vect get_posMinerai(int i)const;

    /**
     * @brief Accesseur qui renvoie les points de vie restants d'un minerai d'indice entré en paramètre
     * @param i : entier
     * @return entier
    */
    int get_MineraiHP(int i)const;

    /**
     * @brief Fonction qui renvoie le nombre de minerai présents dans l'étage dans lequel se trouve le joueur
     * @return entier
    */
    int get_nbMinerai()const;


    
    /**
     * @brief Accesseur qui renvoie le type d'un ennemi d'indice passé en paramètre
     * @param i : entier
     * @return type_Ennemi
    */
    type_Ennemi get_idEnnemi(int i)const;

    /**
     * @brief Fonction booléenne qui renvoie vrai si l'ennemi d'indice entré en paramètre a été vaincu, faux sinon
     * @param i : entier
     * @return booléen
    */
    bool est_mort(int i)const;

    /**
     * @brief Accesseur qui renvoie la position d'un ennemi d'indice entré en paramètre
     * @param i : entier
     * @return Vect
    */
    Vect get_posEnnemi(int i)const;

    /**
     * @brief Fonction qui renvoie les points de vie de l'ennemi d'indice entré en paramètre
     * @param i : entier
     * @return entier
    */
    int get_EnnemiHP(int i)const;

    /**
     * @brief Fonction qui renvoie le nombre d'ennemis dans l'étage
     * @return entier
    */
    int get_nbEnnemi()const;

    /**
     * @brief Fonction qui retire des points de vie à un certain ennemi selon les valeurs entrées en paramètre
     * @param dmg, i : entiers
    */
    void prenddmg( int dmg, int i);

    /**
     * @brief Fonction booléenne qui renvoie vrai si l'ennemi d'indice entré en paramètre est suffisament proche du joueur pour le suivre
     * @param i : entier
     * @param position : Vect
     * @return booléen
    */
    bool detecter(int i, Vect position);

    /**
     * @brief Fonction qui indique à un ennemi suffisamment proche du joueur de le suivre selon des valeurs entrées en paramètre
     * @param i : entier
     * @param position : Vect
    */
    void suivre(int i, Vect position);

    /**
     * @brief Fonction qui renvoie vrai si l'ennemi d'indice entré en paramètre est en contact avec le joueur, faux sinon
     * @param i : entier
     * @param position : Vect
     * @return booléen
    */
    bool toucher(int i, Vect position);


    /**
     * @brief Accesseur qui renvoie la taille de l'étage sous forme d'un objet de classe Vect
     * @return Vect
    */
    Vect get_tailleEtage()const;

    /**
     * @brief Accesseur qui renvoie la profondeur de l'étage
     * @return entier
    */
    int get_profondeur()const;

    /**
     * @brief Accesseur qui renvoie le type de l'étage
     * @return type_Etage
    */
    type_Etage get_typeEtage()const;

    /**
     * @brief Fonction qui n'est pas dans le .cpp
    */
    void se_detruit(int deg, int i);
    

    /**
     * @brief Fonction qui renvoie vrai si tous les ennemis de l'étage ont été vaincus, faux sinon
     * @return booléen
    */
    bool tous_mort();
};





#endif