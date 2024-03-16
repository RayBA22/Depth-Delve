#include <iostream>
#include <string>
using namespace std;

#include "Etage.h"
#include "Personnage.h"
string skin_caractere[6] = {"🪨", "⬛", "🟧", "⬜", "🟨", "🔷"};
void afficher(string tab[20][25])
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 25; ++j)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}
void init_terminal(string tab[20][25])
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 25; ++j)
        {
            tab[i][j] = " ";
        }
    }
}

void update_terminal(string tab[20][25], Etage etage)
{
    Vect v;
    for (int i = 0; i < 5; i++)
    {
        v = etage.get_posMinerai(i);
        if (etage.est_detruit(i))
            tab[v.x][v.y] = "🕳";
        else
            tab[v.x][v.y] = skin_caractere[etage.get_idMinerai(i)];
    }
}

int main()
{
    string tab[20][25];
    Etage etage(grotte, 20, 25);
    Personnage personnage;

    init_terminal(tab);
    etage.initEtage();
    update_terminal(tab, etage);
    afficher(tab);
    

    return 0;
}