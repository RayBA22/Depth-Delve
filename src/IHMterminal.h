
#ifndef _IHMTERMINAL_
#define _IHMTERMINAL_

#include <iostream>

#include <string>
using namespace std;

#include "Jeu.h"

const int xMax=200,  yMax=200;


/**
 * @class IHMterminal
 * Permet d'afficher le jeu dans un terminal
*/

class IHMterminal
{
    
private:

    /**
     * @param skin_caractere : tableau de chaînes de caractères
    */
    string skin_caractere[6] = {"🪨", "⬛", "🟧", "⬜", "🟨", "🔷"};

    /**
     * @param grille : tableau 2D de chaînes de caractères
    */
    string grille[xMax][yMax];

    /**
     * @param jeu : Jeu
    */
    Jeu jeu;


    /**
     * @brief Fonction permettant d'afficher l'état du jeu dans le terminal
    */
    void afficher_terminal();

    /**
     * @brief Fonction permettant d'effacer le tableau modélisant l'espace 2D du jeu
    */
    void effacer_grille();
    

    /**
     * @brief Fonction permettant de mettre à jour la grille modélisant l'étage
    */
    void maj_grille_Etage();

    /**
     * @brief Fonction permettant de mettre à jour la grille en y ajoutant le joueur selon sa position
    */
    void maj_grille_Joueur();

    /**
     * @brief Fonction appelle les deux fonctions précédentes pour mettre à jour le tableau 2D modélisant l'espace du jeu
    */
    void maj_grille();

    /**
     * @brief Fonction indiquant au joueur comment se déplacer et qui gère le déplacement
    */
    void action_Joueur();


    
    
    //renvoie l'indice du minerai dans l'étage actuel
   
   
public:
    /**
     * @brief Fonction qui gère la boucle du jeu
    */
    void boucleJeu();
    

    
    
};



#endif