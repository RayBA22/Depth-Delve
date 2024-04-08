#include "Etage.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Etage::Etage(unsigned int prof)
{
    srand((unsigned)time(NULL));
    id = type_Etage(rand()%3) ;
    tailleEtage.x = (rand()%(maxtaille-500))+500;
    tailleEtage.y = (rand()%(maxtaille-500))+500;
    cout << tailleEtage.x << " et  " << tailleEtage.y<< endl;
    unsigned int profondeur = prof;
    nbMinerai = (rand()%(maxMinerai-5))+5;
    initEtage();
    
}


type_Etage Etage::get_typeEtage() const{
    return id;
}



type_Minerai Etage::randomiseurMinerai() const
{
    
    int r = rand() % 1000;

    if (r >= 0 && r <= 5)
        return Diamant;
    else
    {
        if (r >= 20 && r <= 40 )
            return Or;

        else
        {
            if (r >= 70 && r <= 110)
                return Argent;

            else
            {
                if (r >= 200 && r <= 300)
                    return Fer;
                else
                {
                    if (r >= 500 && r <= 600)
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

    for (int i = 0; i < nbMinerai; i++)
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

unsigned int Etage::get_nbMinerai()const {
    return nbMinerai;
}


unsigned int Etage::get_profondeur()const{

    return profondeur;
}

entier Etage::get_MineraiHP(int i)const{
    return tabMinerai[i].getHP();
}


void Etage::se_detruit(entier deg, coord i){
    tabMinerai[i].se_detruit(deg);
}