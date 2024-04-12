#ifndef _JEU_
#define _JEU_
#include "Joueur.h"
#include "ArbreEtage.h"

#include <iostream>
using namespace std;
#include "Animation.h"

class Jeu
{

public:

    Joueur joueur;
    ArbreEtage mine;
    Inventaire inventaire;
    Animation animJoueur;
    
    


    Jeu();
    void creer_etage();
    type_Minerai get_idMinerai(int i)const;
    entier get_MineraiHP_actuel(int i = 0)const;
    unsigned int get_nbMinerai_actuel()const ;
    type_Minerai miner(int indice);

    
    Vect get_posMinerai_actuel(int i)const;
    void se_detruit_Minerai(entier deg, coord i);
    bool est_detruit_Minerai(int i)const;

    Vect get_tailleEtagact()const;
    Vect get_Joueurpos()const; 
    type_Etage get_typeEtage_actuel()const;

    unsigned int get_frame_Joueur()const;
    direction get_direction_Joueur()const;
    action get_action_Joueur()const;




    void repos_joueur();


    void Joueur_gauche();
    void Joueur_droite();
    void Joueur_haut();
    void Joueur_bas();
    void Joueur_posinit();
    void mouvement_Joueur(int mouv);


    orientation detecterpassage()const;
    void changerEtage();
    
    void piocher();
    void ajouter_Minerai_Inventaire(type_Minerai type);


    Vect get_posEnnemi_actuel(int i)const;
    bool est_mort(int i) const;
    unsigned int get_nbEnnemi_actuel()const;
    type_Ennemi get_idEnnemi(int i)const;
    void mouvementEnnemi();
    
    void piocher_gauche();
    void piocher_droite();
    void piocher_haut();
    void piocher_bas();


    
    

        
};








#endif