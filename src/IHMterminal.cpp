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
        v = jeu.get_posMinerai_actuel(i);
        if (jeu.est_detruit_Minerai(i))
            grille[v.x][v.y] = "🕳 ";
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
    cout << "     ⇑ \n     z\n ⇐  qsd  ⇒    f pour miner et x pour sortir\n\n     ⇓" << endl;
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
            
        case 'f':
            miner();
            return true;
        case 'x':
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
        if (pos.y==v.y-1) jeu.changerEtage();
        else{
            if (pos.y==0) jeu.changerEtage();
        }
    }

}


int IHMterminal::collisionMinerai(){
    Vect posJoueur = jeu.get_Joueurpos(), posMinerai;
    for(int i=0; i<5; i++){
        posMinerai = jeu.get_posMinerai_actuel(i);
        if (posJoueur.x==posMinerai.x && posJoueur.y==posMinerai.y && !jeu.est_detruit_Minerai(i)){
            return i;
        }
    }
    return -1;
}


void IHMterminal::miner(){
    int indice = collisionMinerai();
    type_Minerai type;
    if (indice != -1)
        type = jeu.miner(indice);
        if (jeu.est_detruit_Minerai(indice))
            jeu.ajouter_Minerai_Inventaire(type);
 
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