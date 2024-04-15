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

public:

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

    //peut etre l'argent 
    //interface dans l'inventaire pour les échanges et les achats

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
     * @brief Fonction qui remet le nombre de minerais de chaque type à 0
    */
    void reset_Minerai();
    void reset_Mission();
    int get_nbMinerai(int indice)const;
    int get_nbmort()const;
    bool est_accomplie();
    void valider_mission();
    string formuler_mission();
    bool get_statut()const;
    void changer_statut();
    int get_nbmission_accomplie()const;
    
    void sauver(int HP);
    int charger();
    void reset();

    
};





#endif