#include "Joueur.h"

Joueur::Joueur()
{
    id = joueur;
    pos.x = 0;
    pos.y = 0;
    
}

Joueur::Joueur(entier posx, entier posy) : Personnage(15, 15,  posx, posy)
{
    id = joueur;
    actJoueur = Marcher;
}

void Joueur::changer_vitesse(){
    if (actJoueur == Marcher){
        vitesse.x = 10;
        vitesse.y = 10;
    }
    else{
        vitesse.x = 1;
        vitesse.y = 1;
    }
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


action Joueur::get_action()const{
    return actJoueur;
}


void Joueur::changer_action(){
    actJoueur = (action)(2-actJoueur);
    changer_vitesse();
}


