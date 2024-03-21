#ifndef _IHM_
#define _IHM_

#include "Jeu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

const int coef = 5;

class IHM
{

public:
    RenderWindow window;
    Jeu jeu;
    Texture texJoueur;


    IHM();
    void boucleJeu();
    
    void afficherJoueur(direction direc, unsigned int i);

    unsigned int incrementer(unsigned int i, unsigned int n);

};

#endif