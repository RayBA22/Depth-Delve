#include "Jeu.h"

Jeu::Jeu() : joueur(10, 10, 0, 0)
{

    creer_etage();
}

void Jeu::creer_etage()
{
}

type_Minerai Jeu::get_idMinerai(int i) const
{

    return mine.get_idMinerai_actuel(i);
}

bool Jeu::est_detruit(int i) const
{
    return 0;
}
Vect Jeu::get_posMinerai_actuel(int i) const
{

    return mine.get_posMinerai_actuel(i);
}

entier Jeu::get_MineraiHP_actuel(int i) const
{

    return mine.get_mineraiHP_actuel(i);
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

direction Jeu::mouvement_Joueur(int mouv)
{

    switch (mouv)
    {
    case 25:
        joueur.deplacement_haut();
        return haut;

    case 16:
        joueur.deplacement_gauche();
        return gauche;

    case 18:
        joueur.deplacement_bas(get_tailleEtagact().y);
        return bas;

    case 3:
        joueur.deplacement_droite(get_tailleEtagact().x);
        return droite;

    case 4:
        changerEtage();
        return autre;

    default:
        return autre;
    }
}