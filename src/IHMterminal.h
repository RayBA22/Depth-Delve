#ifndef _IHMTERMINAL_
#define _IHMTERMINAL_

#include <iostream>

#include <string>
using namespace std;

#include "Jeu.h"

const int xMax=200,  yMax=200;

class IHMterminal
{
    
public:

    string skin_caractere[6] = {"🪨", "⬛", "🟧", "⬜", "🟨", "🔷"};
    string grille[xMax][yMax];
    Jeu jeu;


    void afficher_terminal();
    void effacer_grille();
    
    void maj_grille_Etage();
    void maj_grille_Joueur();
    void maj_grille();
    void action_Joueur();


    
    
    //renvoie l'indice du minerai dans l'étage actuel
   
   

    void boucleJeu();
    

    
    
};



#endif