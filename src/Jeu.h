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
    bool start, quitter;
    
    
    


    Jeu();
    void creer_etage();
    bool get_start()const;

    type_Minerai get_idMinerai(int i)const;
    entier get_MineraiHP_actuel(int i = 0)const;
    unsigned int get_nbMinerai_actuel()const ;
    type_Minerai miner(int indice);

    
    
    Vect get_posMinerai_actuel(int i)const;
    void se_detruit_Minerai(entier deg, coord i);
    bool est_detruit_Minerai(int i)const;
    int get_nbMineraidispos()const;

    Vect get_tailleEtagact()const;
    Vect get_Joueurpos()const; 
    type_Etage get_typeEtage_actuel()const;

    unsigned int get_frame_Joueur()const;
    direction get_direction_Joueur()const;
    action get_action_Joueur()const;




    void repos_joueur();


    
    void Joueur_posinit();
    void mouvement_Joueur(int mouv);
    int get_JoueurHP()const;


    orientation detecterpassage()const;
    void changerEtage();
    
    
    void ajouter_Minerai_Inventaire(type_Minerai type);


    Vect get_posEnnemi_actuel(int i)const;
    bool est_mort(int i) const;
    unsigned int get_nbEnnemi_actuel()const;
    type_Ennemi get_idEnnemi(int i)const;
    bool tous_mort();
    
    void piocher(bool(Personnage::*fonc)(Vect));


    void mouvementEnnemi();
    
    bool joueur_estmort();


    bool get_statut_Inventaire()const;
    int get_nbminerai_Inventaire(int i)const;
    int nbmort_Inventaire()const;
    int get_nbmission_accomplie()const;
    string formuler_mission();
    
    void sauver();
    void charger();
    
    void gestion_sauvegarde();
    void reset();
    bool Quitter()const;


};








#endif