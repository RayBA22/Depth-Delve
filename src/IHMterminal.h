#ifndef _IHMTERMINAL_
#define _IHMTERMINAL_

#include <iostream>
#include <string>
using namespace std;

#include "Jeu.h"

const int xMax=100,  yMax=100;

class IHMterminal
{
    
public:

    string skin_caractere[6] = {"🪨", "⬛", "🟧", "⬜", "🟨", "🔷"};
    string grille[xMax][yMax];
    Jeu jeu;


    void afficher_terminal();
    void effacer_grille();
    void lignesep();
    void maj_grille_Etage();
    void maj_grille_Joueur();
    void maj_grille();
    bool action_Joueur();


    void changerEtage();
    
    //renvoie l'indice du minerai dans l'étage actuel
    int collisionMinerai();
    void miner();

    void boucleJeu();
    

    
    
};



#endif