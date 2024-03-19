#include <iostream>
#include <string>
using namespace std;

#include "IHMterminal.h"
#include "IHM.h"

int main()
{
    
    
    bool graphique;
    cout << "tapez 0 pour afficher la version terminal:" << endl;

    cin >> graphique;
    if (graphique){
        IHM ihm;
        ihm.boucleJeu();
    }
    else{ 
        IHMterminal terminal;
        terminal.boucleJeu();
    }
    return 0;
}