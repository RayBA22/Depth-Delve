#include "Joueur.h"

Joueur::Joueur()
{
    id = joueur;
    pos.x = 0;
    pos.y = 0;
}

Joueur::Joueur(entier vitessex, entier vitessy, entier posx, entier posy) : Personnage(vitessex, vitessy, posx, posy)
{
    id = joueur;
}

void Joueur::set_posJoueur(entier posx, entier posy)
{ // faudrait la changer ou utiliser friend avec Jeu
    pos.x = posx;
    pos.y = posy;
}


float Joueur::get_dmgJoueur()const{
    return pioche.get_idPioche();
}
entier Joueur::get_faimJoueur()const{
    return HP;
}
idPioche Joueur::get_ifPioche()const{
    return pioche.get_idPioche();
}
