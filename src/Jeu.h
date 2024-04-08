#ifndef _JEU_
#define _JEU_
#include "Joueur.h"
#include "ArbreEtage.h"


enum direction {haut=2, gauche=1, bas=0, droite=0, autre=3};

class Jeu
{

public:

    Joueur joueur;
    ArbreEtage mine;
    Inventaire inventaire;
    


    Jeu();
    void creer_etage();
    type_Minerai get_idMinerai(int i)const;
    entier get_MineraiHP_actuel(int i = 0)const;
    unsigned int get_nbMinerai_actuel()const ;

    bool est_detruit(int i)const;
    Vect get_posMinerai_actuel(int i)const;
    Vect get_tailleEtagact()const;
    Vect get_Joueurpos()const; 
    type_Etage get_typeEtage_actuel()const;




    void Joueur_gauche();
    void Joueur_droite();
    void Joueur_haut();
    void Joueur_bas();
    void Joueur_posinit();
    direction mouvement_Joueur(int mouv);


    orientation detecterpassage()const;
    void changerEtage();
    
    type_Minerai miner(coord i);
    void ajouter_Minerai_Inventaire(type_Minerai type);
    

        
};








#endif