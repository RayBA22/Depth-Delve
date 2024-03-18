#include "Jeu.h"



Jeu::Jeu(): joueur(1, 1, 0, 0){
    etagact = 0;
    hauteur = -1;
    creer_etage();
}


void Jeu::creer_etage(){
    hauteur++;
    tab_etage[hauteur] = new Etage(20, 25, grotte, hauteur);//identifiant a changer

}

type_Minerai Jeu::get_idMinerai(int i)const{

    return tab_etage[etagact]->get_idMinerai(i);
}

bool Jeu::est_detruit(int i)const{
    return tab_etage[etagact]->est_detruit(i);

}
Vect Jeu::get_posMinerai(int i)const{
    return tab_etage[etagact]->get_posMinerai(i);
}

Vect Jeu::get_tailleEtagact()const{

    return tab_etage[etagact]->get_tailleEtage();
}

Vect Jeu::get_Joueurpos()const{
    return joueur.get_position();
}


void Jeu::Joueur_gauche(){
    joueur.deplacement_gauche();
}

void Jeu::Joueur_droite(){
    joueur.deplacement_droite();
}

void Jeu::Joueur_haut(){
    joueur.deplacement_haut();
}

void Jeu::Joueur_bas(){
    joueur.deplacement_bas();
}

void Jeu::Joueur_posinit(){
    Vect v = get_tailleEtagact();
    joueur.set_posJoueur(v.x/2, v.y+1);
}

//si on veut passer à l'étage suivant on met 1 sinon(à l'etage preced) 0;
void Jeu::changerEtage(bool suivant ){
    Vect v = get_tailleEtagact();
    if (suivant){
        etagact ++;
        joueur.set_posJoueur(v.x/2, 1);
        if (etagact == hauteur+1)

            creer_etage();
        
    }

    else {
        if (etagact > 0){
            etagact --;
            joueur.set_posJoueur(v.x/2, v.y-2);
        }
    }
}