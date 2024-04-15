#include <iostream>
#include <string>
using namespace std;

#include "IHMterminal.h"
#include "IHM.h"


int main()
{

    bool graphique;
    cout << "tapez sur 0 pour afficher la version terminal ou un touche quelconque pour la version graphique: " << endl;
    cin >> graphique;
    if (graphique) {
        IHM ihm(1080, 1080);
        ihm.boucleJeu();
    }
    else{
        IHMterminal ihm;
        ihm.boucleJeu();
    }


    return 0;
}