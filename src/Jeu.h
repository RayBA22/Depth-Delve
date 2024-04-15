#ifndef _JEU_
#define _JEU_
#include "Joueur.h"
#include "ArbreEtage.h"

#include <iostream>
using namespace std;
#include "Animation.h"



/**
 * @class Jeu
 * Modélise tout le fonctionnement du jeu
*/
class Jeu
{

private:

    /**
     * @param joueur : Joueur
    */
    Joueur joueur;

    /**
     * @param mine : ArbreEtage
    */
    ArbreEtage mine;

    /**
     * @param inventaire : Inventaire
    */
    Inventaire inventaire;

    /**
     * @param animJoueur : Animation
    */
    Animation animJoueur;

    /**
     * @param start, quitter : booléens
    */
    bool start, quitter;
    
    
    //Minerais privé

    /**
     * @brief Fonction qui inflige des dégats à un minerai d'indice entré en paramètre selon une quantité de dégats entrés en paramètre
     * @param deg, i : entiers
    */
    void se_detruit_Minerai(int deg, int i);

    /**
     * 
    */
    void ajouter_Minerai_Inventaire(type_Minerai type);
    

    //Etage privé

    void changerEtage();


    //Joueur privé:

    orientation detecterpassage()const;


    



    //gestion du jeu privé:
    void sauver();
    void charger();
    
    void gestion_sauvegarde();
    void reset();
    

    
    



public:
    /**
     * @brief Constructeur par défaut qui crée un joueur
    */
    Jeu();

    //Minerai publique:

    /**
     * @brief Accesseur qui renvoie l'identifiant d'un minerai d'indice entré en paramètre
     * @param i : entier
     * @return type_Minerai
    */
    type_Minerai get_idMinerai(int i)const;

    /**
     * @brief Accesseur qui renvoie la quantité de points de vie d'un minerai
     * @param i : entier
     * @return entier
    */
    int get_MineraiHP_actuel(int i = 0)const;
    /**
     * @brief Accesseur qui retourne le nombre de minerai
     * @return entier positif
    */
    unsigned int get_nbMinerai_actuel()const ;

    
    /**
     * @brief Accesseur qui renvoie la position d'un minerai
     * @param i : entier
     * @return Vect
    */
    Vect get_posMinerai_actuel(int i)const;

    

    /**
     * @brief Accesseur booléen qui renvoie vrai si un minerai d'indice entré en paramètre est détruit, faux sinon
     * @param i : entier
     * @return booléen
    */
    bool est_detruit_Minerai(int i)const;

    /**
     * @brief Accesseur qui renvoie le nombre de minerais disponibles
     * @return entier
    */
    int get_nbMineraidispos()const;


    /**
     * 
     * 
    */
    int get_nbminerai_Inventaire(int i)const;


    //Ennemi publique:
     /**
     * @brief Accesseur qui renvoie la position d'un minerai
     * @param i : entier
     * @return Vect
    */
    Vect get_posEnnemi_actuel(int i)const;

    /**
     * @brief Fonction booléenne qui renvoie vrai si les points de vie de l'ennemi d'indice entré en paramètre valent zéro
     * @param i : entier
     * @return booléen
    */
    bool est_mort(int i) const;


    /**
     * @brief Fonction qui renvoie le nombre total d'ennemis dans l'étage où se situe le joueur
     * @return entier positif
    */
    unsigned int get_nbEnnemi_actuel()const;


    /**
     * @brief Fonction qui renvoie le type de l'ennemi d'indice entré en paramètre
     * @param i : entier
     * @return type_Ennemi
    */
    type_Ennemi get_idEnnemi(int i)const;


    /**
     * @brief Fonction booléenne qui renvoie vrai si tous les ennemis de l'étage ont été vaincus, faux sinon
     * @return booléen
    */
    bool tous_mort();

     /**
     * @brief Fonction qui modélise l'utilisation de la pioche par le joueur
     * @param  fonc unr fonction du personnage qui permet la detection à partir d'un vecteur
    */
    void piocher(bool(Personnage::*fonc)(Vect));

     /**
     * @brief Fonction qui fait avancer les ennemis vers le joueur lorsque celui-ci est suffisamment proche
    */
    void mouvementEnnemi();


    



    //Inventaire publique:

    /**
     * @brief Fonction booléenne qui renvoie vrai si l'inventaire est ouvert, faux sinon
     * @return booléen
    */
    bool get_statut_Inventaire()const;
    

    /**
     * @brief Fonction qui renvoie le nombre d'ennemis que le joueur a vaincus lors de la partie
     * @return entier
    */
    int nbmort_Inventaire()const;


    /**
     * @brief Fonction qui renvoie le nombre de missions accomplies par le joueur
     * @return entier
    */
    int get_nbmission_accomplie()const;


    /**
     * @brief Fonction qui renvoie le texte affiché dans l'inventaire indiquant les objectifs de la mission
     * @return chaîne de caractères
    */
    string formuler_mission();



    //Etage publique

    /**
     * @brief Accesseur qui renvoie le type d'étage de l'étage actuel
     * @return type_Etage
    */
    type_Etage get_typeEtage_actuel()const;

    /**
     * @brief Accesseur qui renvoie la taille de l'étage dans lequel se trouve le Joueur
     * @return Vect
    */
    Vect get_tailleEtagact()const;



    //Joueur publique:

     /**
     * @brief Accesseur qui renvoie la position du joueur dans l'étage
     * @return Vect
    */
    Vect get_Joueurpos()const;

    
    /**
     * @brief Accesseur qui renvoie l'indice du sprite actuel du joueur
     * @return entier positif
    */
    unsigned int get_frame_Joueur()const;

    /**
     * @brief Accesseur qui renvoie la direction dans laquelle le joueur est tourné
     * @return direction
    */
    direction get_direction_Joueur()const;

    /**
     * @brief Accesseur qui renvoie l'action que le joueur est en train d'effectuer
     * @return action
    */
    action get_action_Joueur()const;


    /**
     * @brief Fonction pour mettre le joueur en repos lorsqu'il est immobile
    */
    void repos_joueur();

    /**
     * @brief Fonction qui choisit les sprites du joueur à montrer selon son la direction dans laquelle il se déplace
     * @param mouv : entier
    */
    void mouvement_Joueur(int mouv);

    /**
     * @brief Accesseur qui renvoie la quantité de points de vie du joueur
     * @return entier
    */
    int get_JoueurHP()const;

    /**
     * @brief Fonction booléenne qui renvoie vrai si les points de vie du joueur valent zéro, faux sinon
     * @return booléen
    */
    bool joueur_estmort();

    
    
    //gestion du jeu publique:
    /**
     * @brief Accesseur booléen qui renvoie vrai si le jeu a commencé, faux sinon
     * @return booléen
    */
    bool get_start()const;

    /**
     * @brief Accesseur booléen qui renvoie vrai si le jeu doit etre fermé, faux sinon
     * @return booléen
    */
    bool Quitter()const;
    
   
    


};





#endif