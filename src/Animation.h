#ifndef _ANIMATION_
#define _ANIMATION_


#include <chrono>
using namespace std;
using namespace std::chrono;



enum direction {haut=2, gauche=1, bas=0, droite=0, autre=3};


/**
 * @class Animation
 * Gère les animations des sprites du joueur
*/
class Animation
{

private:

    
    /**
     * @param chrono : high_resolution_clock::time_point
    */
    high_resolution_clock::time_point chrono;

    /**
     * @param interval : entier
    */
    int interval;

    /**
     * @param frameActuelle : entier positif
    */
    unsigned int frameActuelle;

    /**
     * @param nbframe : entier positif
    */
    unsigned int nbframe = 1;

    /**
     * @param direc : direction
    */
    direction direc;
    

public:

    /**
     * @brief Constructeur par défaut
    */
    Animation();    

    /**
     * @brief Fonction qui gère l'animation du joueur lorsque celui-ci se déplace
     * @param dir : direction
     * @param act : entier positif
    */
    void animer_mouvement_joueur(direction dir, unsigned int act);

    /**
     * @brief Fonction qui gère l'animation du joueur lorsqu'il est immobile
    */
    void repos_joueur();

    /**
     * @brief Accesseur qui renvoie la frame actuelle de l'animation du joueur
     * @return entier positif
    */
    unsigned int get_frame_actuelle()const;

    /**
     * @brief Accesseur qui renvoie la direction dans laquelle le personnage regarde
     * @return direction
    */
    direction get_direction_actuelle()const;

};















#endif