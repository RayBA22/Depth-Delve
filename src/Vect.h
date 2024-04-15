#ifndef _VECT_
#define _VECT_


#include <iostream> 
using namespace std;

/**
 * @class Vect
 * Un vecteur stockant deux composantes (x, y) pour positionner les différents éléments
*/

class Vect
{

public:
    
    /**
     * @param x, y: entiers
     * représentent les composantes
     * 
    */
    int x, y;

    /**
     * @brief Constructeur qui met les composantes à zéro
    */
    Vect();

    /**
     * @brief Constructeur qui initialise les composantes avec les vals passées en parametres
     * @param xi, yi: entier
     * @return 
     * 
    */
    Vect(int xi, int yi);
    
    
    
  
    
};



#endif