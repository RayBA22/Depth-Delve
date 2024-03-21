#include "IHM.h"

IHM::IHM() : window(VideoMode(640, 400), "DepthDelve", Style::Default)
{

    window.setFramerateLimit(60);

    Texture jr;

    if (!texJoueur.loadFromFile("./../assets/Joueur.png"))
        cout << "erreur de chargement " << endl;
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
    Sprite spriteJoueur;

    spriteJoueur.setTexture(texJoueur);

    spriteJoueur.setTextureRect(IntRect(i * 64, direc * 64, 64, 64));

    spriteJoueur.setPosition(coef * jeu.get_Joueurpos().x, coef * jeu.get_Joueurpos().y);

    window.draw(spriteJoueur);
}

void IHM::boucleJeu()
{
    Event event;
    unsigned int i = 0;
    direction direc=autre;

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
        
        afficherJoueur(direc, i);
        

        window.display();
    }
}
