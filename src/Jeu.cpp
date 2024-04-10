#include "Jeu.h"

Jeu::Jeu() : joueur(500, 500)
{
    
    
}


type_Minerai Jeu::get_idMinerai(int i) const
{

    return mine.get_idMinerai_actuel(i);
}

bool Jeu::est_detruit_Minerai(int i) const
{
    return mine.est_detruit_Minerai(i);
}
Vect Jeu::get_posMinerai_actuel(int i) const
{

    return mine.get_posMinerai_actuel(i);
}

entier Jeu::get_MineraiHP_actuel(int i) const
{

    return mine.get_mineraiHP_actuel(i);
}

void Jeu::se_detruit_Minerai(entier deg, coord i){

    mine.se_detruit_Minerai(deg,  i);
}

Vect Jeu::get_tailleEtagact() const
{

    return mine.get_tailleEtage_actuel();
}

unsigned int Jeu::get_nbMinerai_actuel() const
{
    return mine.get_nbMinerai_actuel();
}

type_Etage Jeu::get_typeEtage_actuel()const{

    return mine.get_typeEtage_actuel();
}

Vect Jeu::get_Joueurpos() const
{
    return joueur.get_position();
}

void Jeu::Joueur_gauche()
{
    joueur.deplacement_gauche();
}

void Jeu::Joueur_droite()
{
    joueur.deplacement_droite(1);
}

void Jeu::Joueur_haut()
{
    joueur.deplacement_haut();
}

void Jeu::Joueur_bas()
{
    joueur.deplacement_bas(1);
}

type_Minerai  Jeu::miner(int indice){
    return Or;
}

void Jeu::Joueur_posinit()
{
    Vect v = get_tailleEtagact();
    orientation  ori = detecterpassage();
    switch (ori)
    {
    case EST:
        joueur.set_posJoueur(v.x / 2, v.y + 1);
        joueur.set_posJoueur(v.x-50, v.y-50);
        joueur.set_posJoueur(50, v.y-50);
        break;
    
    default:
        break;
    }
    
    
}

void Jeu::ajouter_Minerai_Inventaire(type_Minerai type)
{
    inventaire.ajouter_Minerai(type);
}

orientation Jeu::detecterpassage() const
{

    // corriger ce truc
    Vect posj = get_Joueurpos(), taille = get_tailleEtagact();
    if ((posj.x < 100) && (posj.y > taille.y - 100))
    {
        return EST;
    }
    if ((posj.x > taille.x - 100) && (posj.y > taille.y - 100))
    {
        return OUEST;
    }
    if (((posj.x - taille.x / 2) * (posj.x - taille.x / 2) < 10000) && (posj.y < 100))
    {
        return PRECED;
    }
    return NONE;
}

void Jeu::changerEtage()
{
    
    orientation ori = detecterpassage();

    switch (ori)
    {
    case EST:
        mine.allerEst();
        joueur.set_posJoueur(50, get_tailleEtagact().y-50);
        
        break;
    case OUEST:
        mine.allerOuest();
        joueur.set_posJoueur(get_tailleEtagact().x-50, get_tailleEtagact().y-50);
        break;

    case PRECED:
        mine.allerPrecedent();
        joueur.set_posJoueur(get_tailleEtagact().x / 2, 0);
        break;

    default:
        break;
    }
}



type_Minerai Jeu::piocher(coord i)
{
    return Or;
}

unsigned int Jeu::get_frame_Joueur()const{
    return animJoueur.get_frame_actuelle();
}

direction Jeu::get_direction_Joueur()const{
    return animJoueur.get_direction_actuelle();
}

action Jeu::get_action_Joueur()const{

    return joueur.get_action();
}

void Jeu::repos_joueur(){
        
        animJoueur.repos_joueur();
        
    }



void Jeu::piocher_gauche(){
    Vect posj = get_Joueurpos();
    int i, n = get_nbMinerai_actuel();
    for (i = 0; i < n; i++){
        Vect posm = get_posMinerai_actuel(i);
        if (posm.x < posj.x-32 && posm.x > posj.x - 50 && (unsigned int)(posm.y-posj.y) < 10 ){
            mine.se_detruit_Minerai(joueur.get_dmgJoueur(), i);
            

        }
    }
}

void Jeu::piocher_droite() {
    Vect posj = get_Joueurpos();
    int i, n = get_nbMinerai_actuel();
    for (i = 0; i < n; i++) {
        Vect posm = get_posMinerai_actuel(i);
        if (posm.x > posj.x+32 && posm.x < posj.x + 50 && (unsigned int)(posm.y - posj.y) < 10) {
            mine.se_detruit_Minerai(joueur.get_dmgJoueur(), i);
        }
    }
}

void Jeu::piocher_haut() {
    Vect posj = get_Joueurpos();
    int i, n = get_nbMinerai_actuel();
    for (i = 0; i < n; i++) {
        Vect posm = get_posMinerai_actuel(i);
        if (posm.y < posj.y-32 && posm.y > posj.y - 50 && (unsigned int)(posm.x - posj.x) < 10) {
            mine.se_detruit_Minerai(joueur.get_dmgJoueur(), i);
        }
    }
}

void Jeu::piocher_bas() {
    Vect posj = get_Joueurpos();
    int i, n = get_nbMinerai_actuel();
    for (i = 0; i < n; i++) {
        Vect posm = get_posMinerai_actuel(i);
        if (posm.y > posj.y+32 && posm.y < posj.y + 50 && (unsigned int)(posm.x - posj.x) < 10) {
            mine.se_detruit_Minerai(joueur.get_dmgJoueur(), i);
            
        }
    }
}
    


void Jeu::mouvement_Joueur(int mouv)
{
    action actJoueur = get_action_Joueur();

    switch (mouv)
    {
    
    case 25:
        joueur.deplacement_haut();
        animJoueur.animer_mouvement_joueur(haut, actJoueur);
        if (actJoueur==Piocher) piocher_haut();
        break;
        

    case 16:
        joueur.deplacement_gauche();
        animJoueur.animer_mouvement_joueur(gauche, actJoueur);
        if (actJoueur==Piocher) piocher_gauche();
        break;

    case 18:
        joueur.deplacement_bas(get_tailleEtagact().y);
        animJoueur.animer_mouvement_joueur(bas, actJoueur);
        if (actJoueur==Piocher) piocher_bas();
        break;
    case 3:
        joueur.deplacement_droite(get_tailleEtagact().x);
        animJoueur.animer_mouvement_joueur(droite, actJoueur);
        if (actJoueur==Piocher) piocher_droite();
        break;


    case 57:
        joueur.changer_action();
        break;
    

    case 4:
        changerEtage();

        break;

     
    default:
        
        
        break;

    
    }
}


