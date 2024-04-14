#ifndef _IHM_
#define _IHM_

#include "Jeu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;





class IHM
{

public:
    RenderWindow window;
    Vect resolution;
    Jeu jeu;
    Texture texJoueur[3], texMinerai, texEnnemi, texBG[4], texdecoration[5];
    Sprite sprJoueur, sprMinerai, sprEnnemi, sprBG, sprdeco;
    Font font;
    Text texte;
    
    
    

    IHM(int x, int y);
    void boucleJeu();

   
   
    void afficherJoueur();
    void afficherBG();

    Vect centrer() const;
    void afficherMinerai(type_Minerai typ, Vect pos, bool detruit);
    void afficherMinerais();
    void afficherEnnemi(type_Ennemi typ, Vect pos);
    void afficherEnnemis();
    void afficherechelle();
    void afficherelement();
    void afficherdeco();
    void afficherInventaire();
    void afficherdemarrage();

    
    
};

#endif