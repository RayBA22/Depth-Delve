#include "IHM.h"

IHM::IHM() : window(VideoMode(1080, 720), "DepthDelve", Style::Default)
{

    window.setFramerateLimit(60);

    if (!texJoueur.loadFromFile("./../assets/Joueur.png"))
        cout << "erreur de chargement " << endl;

    if (!texBG[0].loadFromFile("./../assets/untitled.png"))
        cout << "lazagna mamia" << endl;

    sprJoueur.setTexture(texJoueur);
}

unsigned int IHM::incrementer(unsigned int i, unsigned int n)
{
    i += 1;

    if (i >= n)
        i = 0;
    return i;
}

void IHM::afficherJoueur(direction direc, unsigned int i)
{

    sprJoueur.setTextureRect(IntRect(i * 64, direc * 64, 64, 64));

    sprJoueur.setPosition(coef * jeu.get_Joueurpos().x, coef * jeu.get_Joueurpos().y);

    window.draw(sprJoueur);
}

void IHM::afficherBG()
{
    sprBG.setTexture(texBG[0]);
    window.draw(sprBG);
}

void IHM::boucleJeu()
{
    Event event;
    unsigned int i = 0;
    direction direc = autre;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else
            {
                if (event.type == Event::KeyPressed)
                {

                    direc = jeu.mouvement_Joueur(event.key.code);
                    i = incrementer(i, 7);
                }
            }
        }

        window.clear(Color::Black);
        afficherBG();
        afficherJoueur(direc, i);
        

        window.display();
    }
}
