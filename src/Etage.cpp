#include "Etage.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Etage::Etage( int prof)
{
    srand((unsigned)time(NULL));
    id = type_Etage(rand() % 3);
    tailleEtage.x = 1000;
    tailleEtage.y = (rand() % (maxtaille - 500)) + 500;
    profondeur = prof;
    nbMinerai = (rand() % (maxMinerai - 5)) + 5;
    nbEnnemi = profondeur;
    initEtage();
    
    
}

type_Etage Etage::get_typeEtage() const
{
    return id;
}

type_Minerai Etage::randomiseurMinerai() const
{

    int r = rand() % 1000;

    if (r >= 0 && r <= 5)
        return Diamant;
    else
    {
        if (r >= 20 && r <= 40)
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
        Minerai minerai(randomiseurMinerai(), rand() % tailleEtage.x, rand() % tailleEtage.y);
        tabMinerai[i] = minerai;
    }

    for (int i = 0; i < nbEnnemi; i++)
    {

        Ennemi ennemi(green, rand() % tailleEtage.x, rand() % tailleEtage.y);
        tabEnnemi[i] = ennemi;
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

Vect Etage::get_tailleEtage() const
{

    return tailleEtage;
}

int Etage::get_nbMinerai() const
{
    return nbMinerai;
}

int Etage::get_profondeur() const
{
   
    return profondeur;
}

entier Etage::get_MineraiHP(int i) const
{
    return tabMinerai[i].get_HP();
}

void Etage::se_detruit(entier deg, coord i)
{
    tabMinerai[i].se_detruit(deg);
}

type_Ennemi Etage::randomiseurEnnemi()
{
    int r = rand() % 10;

    if (r >= 0 && r <= 5)
        return red;
    else
    {
        if (r >= 6 && r <= 9)
            return blue;

        else
            return green;
    }
}

type_Ennemi Etage::get_idEnnemi(int i) const
{
    return tabEnnemi[i].get_idEnnemi();
}
bool Etage::est_mort(int i) const
{
    return tabEnnemi[i].est_mort();
}
Vect Etage::get_posEnnemi(int i) const
{
    return tabEnnemi[i].get_position();
}
entier Etage::get_EnnemiHP(int i) const
{
    return tabEnnemi[i].get_HP();
}

 int Etage::get_nbEnnemi() const
{
    return nbEnnemi;
}


void Etage::prenddmg( int dmg, int i){
    return tabEnnemi[i].prenddmg(dmg);
}

bool Etage::detecter(int i, Vect position){
    return tabEnnemi[i].detecter(position);
}

void Etage::suivre(int i, Vect position)
{
    tabEnnemi[i].suivre(position, tailleEtage);
}

bool Etage::toucher(int i, Vect position)
{
    return tabEnnemi[i].toucher(position);
}

