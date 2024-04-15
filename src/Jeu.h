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

public:

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
    
    
    

    /**
     * @brief Constructeur par défaut qui crée un joueur
    */
    Jeu();

    /**
     * @brief Fonction qui crée la modélisation d'un étage
    */
    void creer_etage();

    /**
     * @brief Accesseur booléen qui renvoie vrai si le jeu a commencé, faux sinon
     * @return booléen
    */
    bool get_start()const;

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
     * @brief Fonction qui marche meme pas
    */
    type_Minerai miner(int indice);

    
    /**
     * @brief Accesseur qui renvoie la position d'un minerai
     * @param i : entier
     * @return Vect
    */
    Vect get_posMinerai_actuel(int i)const;

    /**
     * @brief Fonction qui inflige des dégats à un minerai d'indice entré en paramètre selon une quantité de dégats entrés en paramètre
     * @param deg, i : entiers
    */
    void se_detruit_Minerai(int deg, int i);

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
     * @brief Accesseur qui renvoie la taille de l'étage dans lequel se trouve le Joueur
     * @return Vect
    */
    Vect get_tailleEtagact()const;

    /**
     * @brief Accesseur qui renvoie la position du joueur dans l'étage
     * @return Vect
    */
    Vect get_Joueurpos()const;

    /**
     * @brief Accesseur qui renvoie le type d'étage de l'étage actuel
     * @return type_Etage
    */
    type_Etage get_typeEtage_actuel()const;

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





    void repos_joueur();


    
    void Joueur_posinit();
    void mouvement_Joueur(int mouv);
    int get_JoueurHP()const;


    orientation detecterpassage()const;
    void changerEtage();
    
    
    void ajouter_Minerai_Inventaire(type_Minerai type);


    Vect get_posEnnemi_actuel(int i)const;
    bool est_mort(int i) const;
    unsigned int get_nbEnnemi_actuel()const;
    type_Ennemi get_idEnnemi(int i)const;
    bool tous_mort();
    
    void piocher(bool(Personnage::*fonc)(Vect));


    void mouvementEnnemi();
    
    bool joueur_estmort();


    bool get_statut_Inventaire()const;
    int get_nbminerai_Inventaire(int i)const;
    int nbmort_Inventaire()const;
    int get_nbmission_accomplie()const;
    string formuler_mission();
    
    void sauver();
    void charger();
    
    void gestion_sauvegarde();
    void reset();
    bool Quitter()const;


};








#endif