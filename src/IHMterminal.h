#ifndef _IHMTERMINAL_
#define _IHMTERMINAL_

#include <iostream>

#include <string>
using namespace std;

#include "Jeu.h"



class IHMterminal
{
    
private:

    string skin_caractere[6] = {"🪨", "⬛", "🟧", "⬜", "🟨", "🔷"};
    string grille[300][300];
    Jeu jeu;


    void afficher_terminal();
    void effacer_grille();
    
    void maj_grille_Etage();
    void maj_grille_Joueur();
    void maj_grille();
    void action_Joueur();


public: 
   
    void boucleJeu();
    

    
    
};



#endif