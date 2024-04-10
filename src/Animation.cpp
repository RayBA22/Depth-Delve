#include  "Animation.h"
#include <iostream>
using namespace std;


Animation::Animation()
{
    

}


void Animation::animer_mouvement_joueur(direction dir, unsigned int act){

    if (direc != dir)
    {
        frameActuelle = 0;
        chrono = high_resolution_clock::now();
    }
    direc = dir;
    nbframe = 4;
    
    if (act == 2)  interval = 35; else interval = 100;
    

    if (high_resolution_clock::now()-chrono >= milliseconds(interval))
    {
        
        chrono = high_resolution_clock::now();

        frameActuelle = (frameActuelle + 1) % nbframe;
    }



}

void Animation::repos_joueur(){

    
    frameActuelle = 0;
    chrono = high_resolution_clock::now();
    interval = 200;
    nbframe = 7;
    
    if (high_resolution_clock::now()-chrono >= milliseconds(interval))
    {
        chrono = high_resolution_clock::now();
        
        frameActuelle = (frameActuelle + 1) % nbframe;
    }

}
    


unsigned int Animation::get_frame_actuelle()const{
    return frameActuelle;
}
direction Animation::get_direction_actuelle()const{
    return direc;
}

