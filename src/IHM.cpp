#include "IHM.h"

IHM::IHM() : window(VideoMode(1080, 720), "DepthDelve", Style::Default)
{

    window.setFramerateLimit(60);

    if (!texJoueur[0].loadFromFile("./../assets/Human/Walk.png"))
        cout << "erreur de chargement des mouvements " << endl;
    if (!texJoueur[1].loadFromFile("./../assets/Human/Idle.png"))
        cout << "erreur de chargement de repos" << endl;
    if (!texJoueur[2].loadFromFile("./../assets/Human/Attack.png"))
        cout << "erreur de chargement de attack" << endl;

    if (!texBG[0].loadFromFile("./../assets/untitled.png"))
        cout << "erreur de chargement du BG 1" << endl;

    if (!texMinerai.loadFromFile("./../assets/ore.png"))
        cout << "erreur de chargement des minerais" << endl;

    sprJoueur.setScale(5.0f, 5.0f);
    sprMinerai.setTexture(texMinerai);
    sprMinerai.setScale(1.0f, 1.0f);

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

void IHM::afficherMinerai(type_Minerai typ, Vect pos)
{
    // jeu.get_MineraiHP_actuel(i) changer de sprite en fonction des hp
    sprMinerai.setTextureRect(IntRect(typ*32, 7*32, 32, 32));
    sprMinerai.setPosition(coef * pos.x, coef * pos.y);
    window.draw(sprMinerai);
}

void IHM::afficherMinerais()
{

    int i, n = jeu.get_nbMinerai_actuel();
    for (i = 0; i < n; i++)
    {
        afficherMinerai(jeu.get_idMinerai(i), jeu.get_posMinerai_actuel(i));
        cout << jeu.get_idMinerai(i) << endl;
    }
}

void IHM::afficherBG()
{
    sprBG.setTexture(texBG[0]);
    window.draw(sprBG);
}

void IHM::boucleJeu()
{
    

   
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

        window.clear(Color(128, 128, 128));
        //afficherBG();
        afficherMinerais();
        afficherJoueur();

        window.display();
    }
}
