#include "Etage.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Etage::Etage( entier xt, entier yt, type_Etage type, unsigned int prof)
{
    id = type;
    tailleEtage.x = xt;
    tailleEtage.y = yt;
    unsigned int profondeur = prof;
    initEtage();
}
type_Minerai Etage::randomiseurMinerai() const
{
    
    int r = rand() % 1000;

    if (r >= 0 && r <= 5 + profondeur)
        return Diamant;
    else
    {
        if (r >= 20 && r <= 40 + 2 * profondeur)
            return Or;

        else
        {
            if (r >= 70 && r <= 110 + profondeur)
                return Argent;

            else
            {
                if (r >= 200 && r <= 300 + profondeur)
                    return Fer;
                else
                {
                    if (r >= 500 && r <= 600 + profondeur)
                        return Cuivre;

                    else
                        return Pierre;
                }
            }
        }
    }
}

void Etage::initEtage()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        Minerai minerai(randomiseurMinerai(), rand()%tailleEtage.x, rand()%tailleEtage.y);
        tabMinerai[i] = minerai;
        
        // même processus pour les pnjs et les ennemis 
    }
}

type_Minerai Etage::get_idMinerai(int i) const
{
    return tabMinerai[i].get_idMinerai();
}

bool Etage::est_detruit(int i) const
{

    return tabMinerai[i].est_detruit();
}

Vect Etage::get_posMinerai(int i) const
{

    return tabMinerai[i].get_position();
}

Vect Etage::get_tailleEtage()const{

    return tailleEtage;
}

void Etage::se_detruit(entier deg, coord i){
    tabMinerai[i].se_detruit(deg);
}