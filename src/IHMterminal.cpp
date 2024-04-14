#include "IHMterminal.h"

void IHMterminal::afficher_terminal()
{
    Vect v = jeu.get_tailleEtagact();
   
    for (int i = 0; i < v.y/20; i++)
    {
        cout << "|";
        for (int j = 0; j < v.x/20; j++)
        {
            cout << grille[i][j];
        }
        cout << "|" << endl;
    }
    
}

void IHMterminal::effacer_grille()
{
    Vect v = jeu.get_tailleEtagact();
    for (int i = 0; i < v.y/20; i++)
    {
        for (int j = 0; j < v.x/20; j++)
        {
            grille[i][j] = "  ";
        }
    }
}



void IHMterminal::maj_grille_Etage()
{
    Vect v;
    for (int i = 0; i < jeu.get_nbMinerai_actuel(); i++)
    {
        v = jeu.get_posMinerai_actuel(i);
        
        grille[v.x/20][v.y/20] = skin_caractere[jeu.get_idMinerai(i)];
    }
}

void IHMterminal::maj_grille_Joueur()
{
    Vect v = jeu.get_Joueurpos();
    cout << v.x << " " << v.y << endl;
    if (grille[v.y/20][v.x/20] == "  ")
        grille[v.y/20][v.x/20] = "🧍";
    else
        grille[v.y/20][v.x/20] = "🙌";
}


void IHMterminal::maj_grille()
{
    maj_grille_Etage();
    maj_grille_Joueur();
}

void IHMterminal::action_Joueur()
{
    char touche;
    bool re = false;
    cout << "     ⇑ \n     z\n ⇐  qsd  ⇒    f pour miner et x pour sortir\n\n     ⇓" << endl;
    cout << "taper une des touches pour vous déplacer" << endl;
    cin >> touche;
    int k = int(touche) - 97;
    jeu.mouvement_Joueur(k);

}











void IHMterminal::boucleJeu()
{
    
    bool rester = true;
    
    while (!jeu.Quitter())
    {   
        effacer_grille();
        
        
        maj_grille();
        action_Joueur();
        afficher_terminal();
        
    }
}