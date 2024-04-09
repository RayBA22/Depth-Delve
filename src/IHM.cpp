#include "IHM.h"

IHM::IHM(int x, int y) : window(VideoMode(x, y), "DepthDelve", Style::Default)
{

    resolution.x = x;
    resolution.y = y;
    window.setFramerateLimit(60);

    if (!texJoueur[0].loadFromFile("./../assets/Human/Walk.png"))
        cout << "erreur de chargement des mouvements " << endl;
    if (!texJoueur[1].loadFromFile("./../assets/Human/Idle.png"))
        cout << "erreur de chargement de repos" << endl;
    if (!texJoueur[2].loadFromFile("./../assets/Human/Attack.png"))
        cout << "erreur de chargement de attack" << endl;


    if (!texBG[0].loadFromFile("./../assets/mine.png"))
        cout << "erreur de chargement du BG 1" << endl;
    if (!texBG[1].loadFromFile("./../assets/mine_volcanique.png"))
        cout << "erreur de chargement du BG 2" << endl;
    if (!texBG[2].loadFromFile("./../assets/mine_gelée.png"))
        cout << "erreur de chargement du BG 3" << endl;
    if (!texBG[3].loadFromFile("./../assets/map.png"))
        cout << "erreur de chargement du BG 4" << endl;

    if (!texMinerai.loadFromFile("./../assets/minerai/minerai.png"))
        cout << "erreur de chargement des minerais" << endl;

    if (!texdecoration[0].loadFromFile("./../assets/rocks.png"))
        cout << "erreur de chargement de la deco 1" << endl;

    if (!texdecoration[1].loadFromFile("./../assets/echelle.png"))
        cout << "erreur de chargement de la deco 2" << endl;



    sprJoueur.setScale(5.0f, 5.0f);
    sprJoueur.setOrigin(16, 16);
    

    sprMinerai.setTexture(texMinerai);
    sprMinerai.setScale(4.5f, 4.5f);
    sprMinerai.setOrigin(4, 4);


    sprdeco.setOrigin(8, 8);
    sprdeco.setScale(5.0f, 5.0f);
    repos();
}


Vect IHM::centrer()const{

    Vect milieu;
    milieu.x =  (resolution.x - jeu.get_tailleEtagact().x)/2;
    milieu.y =  (resolution.y - jeu.get_tailleEtagact().y)/2;

    return milieu;
}



void IHM::mouvement(direction dir)
{

    sprJoueur.setTexture(texJoueur[animJoueur.act]);

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
    //animJoueur.direc = direction(animJoueur.direc % 2);
    animJoueur.interval = 0.6f;
    animJoueur.nbframe = 10;
}

void IHM::piocher(){

    hitboxj.setFillColor(Color::Black);
    hitboxj.setPosition(jeu.get_Joueurpos().x, jeu.get_Joueurpos().y);
    sprJoueur.setTexture(texJoueur[2]);
    

    animJoueur.frameActuelle = 0;
    animJoueur.chrono.restart();
    animJoueur.interval = 0.6f;
    animJoueur.nbframe = 4;


}

void IHM::afficherJoueur()
{

    if (animJoueur.chrono.getElapsedTime().asSeconds() >= animJoueur.interval)
    {

        animJoueur.chrono.restart();

        animJoueur.frameActuelle = (animJoueur.frameActuelle + 1) % animJoueur.nbframe;
    }

    sprJoueur.setTextureRect(IntRect(animJoueur.frameActuelle * 32, animJoueur.direc * 32, 32, 32));

    sprJoueur.setPosition(centrer().x + jeu.get_Joueurpos().x, centrer().y + jeu.get_Joueurpos().y);
    cout << jeu.get_Joueurpos().x << "  " <<  jeu.get_Joueurpos().y << "  |  " << jeu.get_tailleEtagact().x << "   " << jeu.get_tailleEtagact().y <<  endl;
    window.draw(sprJoueur);
}

void IHM::afficherMinerai(type_Minerai typ, Vect pos)   
{
    // jeu.get_MineraiHP_actuel(i) changer de sprite en fonction des hp
    sprMinerai.setTextureRect(IntRect(typ*8, 0, 8, 8));
    sprMinerai.setPosition(centrer().x +  pos.x, centrer().y + pos.y);
    window.draw(sprMinerai);
}

void IHM::afficherMinerais()
{

    int i, n = jeu.get_nbMinerai_actuel();
    for (i = 0; i < n; i++)
    {
        afficherMinerai(jeu.get_idMinerai(i), jeu.get_posMinerai_actuel(i));
        
    }
}

void IHM::afficherBG()
{   
    sprBG.setTexture(texBG[3]);
    sprBG.setTextureRect(IntRect(0, 0, resolution.x, resolution.y));
    sprBG.setPosition(0, 0);
    window.draw(sprBG);

    Vect tailleEtage = jeu.get_tailleEtagact();
    sprBG.setTexture(texBG[jeu.get_typeEtage_actuel()]);
    sprBG.setTextureRect(IntRect(0, 0, tailleEtage.x, tailleEtage.y));
    sprBG.setPosition(centrer().x, centrer().y);
    //cout << tailleEtage.x << "   " << tailleEtage.y << endl;
    window.draw(sprBG); 

    //afficher le cadre
    sprdeco.setTexture(texdecoration[0]);
    
}

void IHM::afficherechelle(){
    Vect tailleEtage = jeu.get_tailleEtagact();
    
    sprdeco.setTexture(texdecoration[1]);
    sprdeco.setTextureRect(IntRect(0, 0, 16, 16));


    //precedent
    sprdeco.setPosition(centrer().x + tailleEtage.x/2, centrer().y+20);
    window.draw(sprdeco);

    
    sprdeco.setTextureRect(IntRect(16, 0, 16, 16));
    //ouest
    sprdeco.setPosition(centrer().x+50, centrer().y+tailleEtage.y-50);
    window.draw(sprdeco);
    //est
    sprdeco.setPosition(centrer().x+tailleEtage.x-50, centrer().y+tailleEtage.y-50);
    window.draw(sprdeco);
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

        window.clear(Color::Black);
        afficherBG();
        afficherechelle();
        afficherMinerais();
        afficherJoueur();
        

        window.display();
    }
}
