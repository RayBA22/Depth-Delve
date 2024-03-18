#include "IHMterminal.h"

void IHMterminal::afficher_terminal()
{
    Vect v = jeu.get_tailleEtagact();
    lignesep();
    for (int i = 0; i < v.x; ++i)
    {
        cout << " |";
        for (int j = 0; j < v.y; ++j)
        {
            if (grille[i][j] == " ")
                cout << "  ";
            else
                cout << grille[i][j];
        }
        cout << "|" << endl;
    }
    lignesep();
}

void IHMterminal::effacer_grille()
{
    Vect v = jeu.get_tailleEtagact();
    for (int i = 0; i < v.x; ++i)
    {
        for (int j = 0; j < v.y; ++j)
        {
            grille[i][j] = " ";
        }
    }
}

void IHMterminal::lignesep()
{
    cout << "  ";
    Vect v = jeu.get_tailleEtagact();
    for (int i = 0; i < v.y; i++)
        cout << "――";
    cout << endl;
}

void IHMterminal::maj_grille_Etage()
{
    Vect v;
    for (int i = 0; i < 5; i++)
    {
        v = jeu.get_posMinerai(i);
        if (jeu.est_detruit(i))
            grille[v.x][v.y] = "🕳";
        else
            grille[v.x][v.y] = skin_caractere[jeu.get_idMinerai(i)];
    }
}

void IHMterminal::maj_grille_Joueur()
{
    Vect v = jeu.get_Joueurpos();
    cout << v.x << " " << v.y << endl;
    if (grille[v.x][v.y] == " ")
        grille[v.x][v.y] = "🧍";
    else
        grille[v.x][v.y] = "🙌";
}

void IHMterminal::maj_grille()
{
    maj_grille_Etage();
    maj_grille_Joueur();
}

bool IHMterminal::action_Joueur()
{
    char touche;
    bool re = false;
    cout << "     ⇑ \n     z\n ⇐  qsd  ⇒\n\n     ⇓" << endl;
    cout << "taper une des touches pour vous déplacer" << endl;
    do
    {
        cin >> touche;
        switch (touche)
        {
        case 'z':
            jeu.Joueur_haut();
            return true;
        case 'q':
            jeu.Joueur_gauche();
            return true;

        case 's':
            jeu.Joueur_bas();
            return true;

        case 'd':
            jeu.Joueur_droite();
            return true;

        case 'x':
            jeu.Joueur_droite();
            return false;
            

        default:
            re = true;
            break;
        }
    } while (re);
    return true;
}


void IHMterminal::changerEtage(){
    Vect v = jeu.get_tailleEtagact(), pos = jeu.get_Joueurpos();
    grille[v.x/2][v.y-1]= "🪜";
    grille[v.x/2][0] = "🪜";
    if (pos.x == v.x/2){
        if (pos.y==v.y-1) jeu.changerEtage(1);
        else{
            if (pos.y==0) jeu.changerEtage(0);
        }
    }



}




void IHMterminal::boucleJeu()
{
    
    bool rester = true;
    
    while (rester)
    {   
        effacer_grille();
        changerEtage();
        maj_grille();
        afficher_terminal();
        rester = action_Joueur();
    }
}