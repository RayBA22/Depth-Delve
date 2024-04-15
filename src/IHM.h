#ifndef _IHM_
#define _IHM_

#include "Jeu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;




/**
 * @class IHM
 * @brief Permet d'afficher le jeu avec touts ses fonctionnalités dans une fenêtre
*/
class IHM
{

private:
    /**
     * @param window : RenderWindow
    */
    RenderWindow window;

    /**
     * @param resolution : Vect
    */
    Vect resolution;

    /**
     * @param jeu : Jeu
    */
    Jeu jeu;

    /**
     * @param texJoueur, texBG, texdecoration : tableaux de Textures
     * @param texMinerai, texEnnemi : Textures
    */
    Texture texJoueur[3], texMinerai, texEnnemi, texBG[4], texdecoration[5];

    /**
     * @param sprJoueur, sprMinerai, sprEnnemi, sprBG, sprdeco : Sprites
    */
    Sprite sprJoueur, sprMinerai, sprEnnemi, sprBG, sprdeco;

    /**
     * @param font : Police d'écriture
    */
    Font font;

    /**
     * @param texte : Text
    */
    Text texte;
    
    
    /**
    * @brief Fonction qui affiche le joueur aux coordonnées correspondantes
    */
    void afficherJoueur();

    /**
    * @brief Fonction qui affiche l'arrière plan
    */
    void afficherBG();

    /**
     * @brief Fonction permettant d'afficher un minerai de type, position et état (détruit ou non) entrés en paramètre
     * @param typ : type_Minerai
     * @param pos : Vect
     * @param detruit : booléen
    */
    void afficherMinerai(type_Minerai typ, Vect pos, bool detruit);


    /**
     * @brief Fonction permettant d'afficher les minerais présents dans l'étage dans lequel se trouve le joueur
    */
    void afficherMinerais();


    /**
     * @brief Fonction permettant d'afficher un ennemi de type et de position entrés en paramètre
     * @param typ : type_Ennemi
     * @param pos : Vect
    */
    void afficherEnnemi(type_Ennemi typ, Vect pos);


    /**
     * @brief Fonction permettant d'afficher les ennemis présents dans l'étage dans lequel se trouve le joueur
    */
    void afficherEnnemis();


    /**
     * @brief Fonction permettant d'afficher les décorations
    */
    void afficherdeco();



    /**
     * @brief Fonction permettant d'afficher l'inventaire
    */
    void afficherInventaire();


    /**
     * @brief Fonction permettant d'afficher le menu du jeu
    */
    void afficherdemarrage();





public:

    /**
    * @brief Fonction qui ouvre la fenêtre selon la taille entrée en paramètre et lance le jeu
    * @param x, y : entiers
    */
    IHM(int x, int y);


    /**
    * @brief Fonction qui gère la boucle du jeu
    */
    void boucleJeu();
    

    /**
    * @brief Fonction permettant de centrer l'affichage de l'étage selon sa taille
    * @return Vect
    */
    Vect centrer() const;
};

#endif