#ifndef _INVENTAIRE_
#define _INVENTAIRE_

#include "Minerai.h"
#include <string>
#include <fstream>
using namespace std;


/**
 * @class Inventaire
 * Modélise l'inventaire du joueur durant la partie
*/

class Inventaire
{

private:

    /**
     * @param tabnbMinerai, tabmission : tableaux d'entiers
    */
    int tabnbMinerai[6], tabmission[6];

    /**
     * @param nbmission : entier
    */
    int nbmission;

    /**
     * @param info_mission : chaîne de caractères
    */
    string info_mission;

    /**
     * @param nbEnnemimort : entier
    */
    int nbEnnemimort;

    /**
     * @param statut : booléen
    */
    bool statut;


    /**
     * @brief Fonction qui remet à zéro la mission lorqu'une mission est réussie
    */
    void valider_mission();

    /**
     * @brief Fonction qui remet le nombre de minerais de chaque type à 0
    */
    void reset_Minerai();

    /**
     * @brief Fonction qui relance une mission
    */
    void reset_Mission();

    /**
     * @brief Fonction booléenne qui renvoie vrai si tous les objectifs de la mission en cours sont remplis, faux sinon
     * @return booléen
    */
    bool est_accomplie();

public:
    /**
    * @brief Constructeur par défaut
    */
    Inventaire();

    /**
    * @brief Fonction qui ajoute un minerai du type entré en paramètre à l'inventaire
    * @param minerai : type_Minerai
    */
    void ajouter_Minerai(type_Minerai minerai);

    /**
    * @brief Fonction qui incrémente de 1 le nombre d'ennemis vaincus
    */
    void ajouter_Ennemi();

    

    /**
    * @brief Accesseur qui renvoie le nombre de minerais d'indice entré en paramètre présent dans l'inventaire
    * @param indice : entier
    * @return entier
    */
    int get_nbMinerai(int indice)const;

    /**
     * @brief Accesseur qui renvoie le nombre d'ennemis que le joueur a vaincus
     * @return entier
    */
    int get_nbmort()const;


    /**
     * @brief Fonction qui renvoie le texte affiché dans l'inventaire indiquant les objectifs de la mission
     * @return chaîne de caractères
    */
    string formuler_mission();

    /**
    * @brief Fonction booléenne qui renvoie vrai si l'inventaire est ouvert, faux sinon
    * @result booléen
    */
    bool get_statut()const;
    
    
    /**
    * @brief Fonction qui ouvre l'inventaire s'il est fermé et qui le ferme s'il est ouvert
    */
    void changer_statut();


    /**
    * @brief Fonction qui renvoie le nombre de missions accomplies
    * @return entier
    */
    int get_nbmission_accomplie()const;

    
    /**
    * @brief Fonction qui permet de sauvegarder la partie en prenant en paramètre les points de vie du joueur
    * @param HP entier
    */
    void sauver(int HP);

    /**
    * @brief Fonction qui permet de charger une partie sauvegardée
    */
    int charger();
    
    /**
    * @brief Fonction qui réinitialise l'inventaire si le joueur meurt
    */
    void reset();


    
};





#endif