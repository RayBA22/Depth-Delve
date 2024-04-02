#include "Jeu.h"



Jeu::Jeu():joueur(1, 1, 0, 0){
   
    creer_etage();
}


void Jeu::creer_etage(){
    

}

type_Minerai Jeu::get_idMinerai(int i)const{

    return Or;
}

bool Jeu::est_detruit(int i)const{
    return 0;

}
Vect Jeu::get_posMinerai(int i)const{
    Vect j;
    
    return j;
}

Vect Jeu::get_tailleEtagact()const{

    return mine.get_tailleEtage_actuel();
}


Vect Jeu::get_Joueurpos()const{
    return joueur.get_position();
}


void Jeu::Joueur_gauche(){
    joueur.deplacement_gauche();
}

void Jeu::Joueur_droite(){
    joueur.deplacement_droite(get_tailleEtagact().y);
}

void Jeu::Joueur_haut(){
    joueur.deplacement_haut();
}

void Jeu::Joueur_bas(){
    joueur.deplacement_bas(get_tailleEtagact().x);
}

void Jeu::Joueur_posinit(){
    Vect v = get_tailleEtagact();
    joueur.set_posJoueur(v.x/2, v.y+1);
}

void Jeu::ajouter_Minerai_Inventaire(type_Minerai type){
    inventaire.ajouter_Minerai(type);
}

orientation Jeu::detecterpassage()const{
    Vect posj = get_Joueurpos(), taille = get_tailleEtagact();
    if ((posj.x < 10) && (posj.y > taille.y-10)){
        return EST;
    }
    if ((posj.x > taille.x-10) && (posj.y > taille.y-10)){
        return OUEST;
    }
    if (((posj.x - taille.x/2)*(posj.x - taille.x/2) < 100) && (posj.y<10)) {
        return PRECED;
    }
    return NONE;
}






void Jeu::changerEtage(){
    orientation ori = detecterpassage();
    
    switch (ori)
    {
    case EST:
        mine.allerEst();
        break;
    case OUEST:
        mine.allerOuest();
        break;
    
    case PRECED:
        mine.allerPrecedent();
        break;
    
    default:
        break;
    }

    
}


type_Minerai Jeu::miner(coord i){
    return Or;
}


direction Jeu::mouvement_Joueur(int mouv){
    
    switch (mouv)
    {
    case 25: 
        joueur.deplacement_haut();
        return haut;

    case 16 : 
        joueur.deplacement_gauche();
        return gauche;

    case 18: 
        joueur.deplacement_bas(get_tailleEtagact().x);
        return bas;

    case 3: 
        joueur.deplacement_droite(get_tailleEtagact().y);
        return droite;
    
    case 0:
        return autre;


    default:
        return autre;
    }
}