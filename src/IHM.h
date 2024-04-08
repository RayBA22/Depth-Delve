#ifndef _IHM_
#define _IHM_

#include "Jeu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

struct Animation
{
    Clock chrono;
    float interval;
    unsigned int frameActuelle;
    unsigned int nbframe = 1;
    direction direc;
};

class IHM
{

public:
    RenderWindow window;
    Vect resolution;
    Jeu jeu;
    Texture texJoueur[3], texMinerai, texBG[4], texdecoration[5];
    Sprite sprJoueur, sprMinerai, sprBG, sprdeco;
    Animation animJoueur;

    IHM(int x, int y);
    void boucleJeu();

    void mouvement(direction dir);
    void attaque();
    void repos();
   
    void afficherJoueur();
    void afficherBG();

    Vect centrer() const;
    void afficherMinerai(type_Minerai typ, Vect pos);
    void afficherMinerais();
    void afficherechelle();
    void afficherelement();
    void afficherdeco();

};

#endif