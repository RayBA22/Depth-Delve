#ifndef _ANIMATION_
#define _ANIMATION_


#include <chrono>
using namespace std;
using namespace std::chrono;



enum direction {haut=2, gauche=1, bas=0, droite=0, autre=3};


class Animation
{

public:
    
    high_resolution_clock::time_point chrono;
    int interval;
    unsigned int frameActuelle;
    unsigned int nbframe = 1;
    direction direc;
    


    Animation();    
    void animer_mouvement_joueur(direction dir, unsigned int act);
    void repos_joueur();
    unsigned int get_frame_actuelle()const;
    direction get_direction_actuelle()const;
    unsigned int get_action_actuelle()const;

};















#endif