#include "Etage.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Etage::Etage(type_Etage type, entier xt, entier yt)
{
    id = type;
    xtaille = xt;
    ytaille = yt;
    unsigned int profondeur;
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
        Minerai minerai(randomiseurMinerai(), rand()%xtaille, rand()%ytaille);
        tabMinerai[i] = minerai;
        cout << tabMinerai[i].pos.x << " " << tabMinerai[i].pos.y << endl;
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