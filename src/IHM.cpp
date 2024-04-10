#include "IHM.h"

IHM::IHM(int x, int y) : window(VideoMode(x, y), "DepthDelve", Style::Default)
{
    resolution.x = x;
    resolution.y = y;

    jeu.repos_joueur();

    window.setFramerateLimit(60);

    if (!texJoueur[0].loadFromFile("./../assets/Marcher.png"))
        cout << "erreur de chargement des mouvements " << endl;
    if (!texJoueur[1].loadFromFile("./../assets/Idle.png"))
        cout << "erreur de chargement de repos" << endl;
    if (!texJoueur[2].loadFromFile("./../assets/Attack.png"))
        cout << "erreur de chargement de attack" << endl;


    if (!texBG[0].loadFromFile("./../assets/mine.png"))
        cout << "erreur de chargement du BG 1" << endl;
    if (!texBG[1].loadFromFile("./../assets/mine_volcanique.png"))
        cout << "erreur de chargement du BG 2" << endl;
    if (!texBG[2].loadFromFile("./../assets/mine_gelée.png"))
        cout << "erreur de chargement du BG 3" << endl;
    if (!texBG[3].loadFromFile("./../assets/map.png"))
        cout << "erreur de chargement du BG 4" << endl;

    if (!texMinerai.loadFromFile("./../assets/Ores.png"))
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
    
}


Vect IHM::centrer()const{

    Vect milieu;
    milieu.x =  (resolution.x - jeu.get_tailleEtagact().x)/2;
    milieu.y =  (resolution.y - jeu.get_tailleEtagact().y)/2;

    return milieu;
}




void IHM::afficherJoueur()
{

    sprJoueur.setTexture(texJoueur[jeu.get_action_Joueur()]);
    sprJoueur.setTextureRect(IntRect(jeu.get_frame_Joueur() * 32, jeu.get_direction_Joueur() * 32, 32, 32));

    sprJoueur.setPosition(centrer().x + jeu.get_Joueurpos().x, centrer().y + jeu.get_Joueurpos().y);
    //cout << jeu.get_frame_Joueur() << "  " <<  jeu.get_direction_Joueur() << "  |  " << jeu.get_tailleEtagact().x << "   " << jeu.get_tailleEtagact().y <<  endl;
    window.draw(sprJoueur);
}

void IHM::afficherMinerai(type_Minerai typ, Vect pos, bool detruit)   
{
    // jeu.get_MineraiHP_actuel(i) changer de sprite en fonction des hp
    sprMinerai.setTextureRect(IntRect(typ*8, 8*detruit, 8, 8));
    sprMinerai.setPosition(centrer().x +  pos.x, centrer().y + pos.y);
    window.draw(sprMinerai);
}

void IHM::afficherMinerais()
{

    int i, n = jeu.get_nbMinerai_actuel();
    for (i = 0; i < n; i++)
    {   
        afficherMinerai(jeu.get_idMinerai(i), jeu.get_posMinerai_actuel(i), jeu.est_detruit_Minerai(i));
        
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

                    jeu.mouvement_Joueur(event.key.code);
                    
                }
                else
                {
                    if (event.type == Event::KeyReleased)
                        {
                            jeu.repos_joueur();
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
