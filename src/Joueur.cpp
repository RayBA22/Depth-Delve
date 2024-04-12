#include "Joueur.h"

Joueur::Joueur()
{
    
    pos.x = 0;
    pos.y = 0;
    
}

Joueur::Joueur(entier posx, entier posy) : Personnage(15, 15,  posx, posy), pioche(pierre)
{
    
    actJoueur = Marcher;
    HP = 10;
}

void Joueur::changer_vitesse(){
    if (actJoueur == Marcher){
        vitesse.x = 7;
        vitesse.y = 7;
    }
    else{
        vitesse.x = 4;
        vitesse.y = 4;
    }
}



void Joueur::set_posJoueur(entier posx, entier posy)
{ // faudrait la changer ou utiliser friend avec Jeu
    pos.x = posx;
    pos.y = posy;
}


int Joueur::get_dmgJoueur()const{
    return  pioche.get_dmgPioche();
}


entier Joueur::get_faimJoueur()const{
    return HP;
}


idPioche Joueur::get_idPioche()const{
    return pioche.get_idPioche();
}


action Joueur::get_action()const{
    return actJoueur;
}


void Joueur::changer_action(){
    actJoueur = (action)(2-actJoueur);
    changer_vitesse();
}


void Joueur::prenddmg(int dmg){
    HP = HP - dmg;
}


bool Joueur::joueur_mort()const{
    return HP <= 0;
}

