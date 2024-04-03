#ifndef _IHM_
#define _IHM_

#include "Jeu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

const int coef = 10;


struct Animation
{
    Clock chrono;
    float interval; 
    unsigned int frameActuelle;
    unsigned int nbframe=1;
    direction direc;
};


class IHM
{

public:
    RenderWindow window;
    Jeu jeu;
    Texture texJoueur[3], texBG[3];
    Sprite sprJoueur, sprBG;
    Animation animJoueur;


    IHM();
    void boucleJeu();


    void mouvement(direction dir);
    void attaque();
    void repos();

    void afficherJoueur();
    void afficherBG();

    unsigned int incrementer(unsigned int i, unsigned int n);
};

#endif