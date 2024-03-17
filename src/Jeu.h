#ifndef _JEU_
#define _JEU_
#include "Joueur.h"
#include "Etage.h"


class Jeu
{


public:

    Joueur joueur;
    Etage* tab_etage[15]; //peut etre un tableau dynamique
    int hauteur;
    unsigned int etagact;


    Jeu();
    void creer_etage();
    type_Minerai get_idMinerai(int i)const;
    bool est_detruit(int i)const;
    Vect get_posMinerai(int i)const;
    Vect get_tailleEtagact()const;
    Vect get_Joueurpos()const;   
    void Joueur_gauche();
    void Joueur_droite();
    void Joueur_haut();
    void Joueur_bas();

    
    
    
    
};








#endif