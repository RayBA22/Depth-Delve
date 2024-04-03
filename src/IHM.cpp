#include "IHM.h"

IHM::IHM() : window(VideoMode(1080, 720), "DepthDelve", Style::Default)
{

    window.setFramerateLimit(60);

    if (!texJoueur[0].loadFromFile("./../assets/Human/Walk.png"))
        cout << "erreur de chargement 0 " << endl;
    if (!texJoueur[1].loadFromFile("./../assets/Human/Idle.png"))
        cout << "erreur de chargement 1" << endl;
    if (!texJoueur[2].loadFromFile("./../assets/Human/Attack.png"))
        cout << "erreur de chargement 2" << endl;

    if (!texBG[0].loadFromFile("./../assets/untitled.png"))
        cout << "lazagna mamia" << endl;

    sprJoueur.setScale(5.0f, 5.0f);

    repos();
}


void IHM::mouvement(direction dir)
{

    sprJoueur.setTexture(texJoueur[0]);

    if (animJoueur.direc != dir)
    {
        animJoueur.frameActuelle = 0;
        animJoueur.chrono.restart();
    }
    animJoueur.direc = dir;
    animJoueur.interval = 0.1f;
    animJoueur.nbframe = 4;
}

void IHM::repos()
{

    sprJoueur.setTexture(texJoueur[1]);
    animJoueur.frameActuelle = 0;
    animJoueur.chrono.restart();
    animJoueur.direc = direction(animJoueur.direc % 2);
    animJoueur.interval = 0.6f;
    animJoueur.nbframe = 10;
}

void IHM::afficherJoueur()
{

    if (animJoueur.chrono.getElapsedTime().asSeconds() >= animJoueur.interval)
    {

        animJoueur.chrono.restart();

        animJoueur.frameActuelle = (animJoueur.frameActuelle + 1) % animJoueur.nbframe;
    }

    sprJoueur.setTextureRect(IntRect(animJoueur.frameActuelle * 32, animJoueur.direc * 32, 32, 32));

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

    // a ameliorer : demander au prof comment faire les deplacements !!
    Event event;
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

                    mouvement(jeu.mouvement_Joueur(event.key.code));
                }
                else
                {
                    if (event.type == Event::KeyReleased)
                    {

                        repos();
                    }
                }
            }
        }

        window.clear(Color::Black);
        afficherBG();

        afficherJoueur();

        window.display();
    }
}
