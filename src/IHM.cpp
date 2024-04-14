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

    if (!texEnnemi.loadFromFile("./../assets/insect1.png"))
        cout << "erreur de chargement des Ennmis" << endl;

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

    if (!texdecoration[2].loadFromFile("./../assets/crane.png"))
        cout << "erreur de chargement de la deco 3" << endl;

    if (!texdecoration[3].loadFromFile("./../assets/coeur.png"))
        cout << "erreur de chargement de la deco 4" << endl;

    if (!font.loadFromFile("./../assets/font.ttf"))
        cout << "erreur de chargement de la police" << endl;

    sprJoueur.setScale(5.0f, 5.0f);
    sprJoueur.setOrigin(16, 16);

    sprMinerai.setTexture(texMinerai);
    sprMinerai.setScale(4.5f, 4.5f);
    sprMinerai.setOrigin(4, 4);

    sprEnnemi.setTexture(texEnnemi);
    sprEnnemi.setScale(4.0f, 4.0f);
    sprEnnemi.setOrigin(8, 8);

    sprdeco.setOrigin(8, 8);

    texte.setFont(font);
}

Vect IHM::centrer() const
{

    Vect milieu;
    milieu.x = (resolution.x - jeu.get_tailleEtagact().x) / 2;
    milieu.y = (resolution.y - jeu.get_tailleEtagact().y) / 2;

    return milieu;
}

void IHM::afficherJoueur()
{

    sprJoueur.setTexture(texJoueur[jeu.get_action_Joueur()]);
    sprJoueur.setTextureRect(IntRect(jeu.get_frame_Joueur() * 32, jeu.get_direction_Joueur() * 32, 32, 32));

    sprJoueur.setPosition(centrer().x + jeu.get_Joueurpos().x, centrer().y + jeu.get_Joueurpos().y);
    // cout << jeu.get_frame_Joueur() << "  " <<  jeu.get_direction_Joueur() << "  |  " << jeu.get_tailleEtagact().x << "   " << jeu.get_tailleEtagact().y <<  endl;
    window.draw(sprJoueur);
}

void IHM::afficherMinerai(type_Minerai typ, Vect pos, bool detruit)
{
    // jeu.get_MineraiHP_actuel(i) changer de sprite en fonction des hp
    sprMinerai.setTextureRect(IntRect(typ * 8, 8 * detruit, 8, 8));
    sprMinerai.setPosition(centrer().x + pos.x, centrer().y + pos.y);
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

void IHM::afficherEnnemi(type_Ennemi typ, Vect pos)
{
    sprEnnemi.setTextureRect(IntRect(typ * 16, 0, 16, 16));
    sprEnnemi.setPosition(centrer().x + pos.x, centrer().y + pos.y);
    window.draw(sprEnnemi);
}

void IHM::afficherEnnemis()
{

    int i, n = jeu.get_nbEnnemi_actuel();
    for (i = 0; i < n; i++)
    {
        if (!jeu.est_mort(i))
            afficherEnnemi(jeu.get_idEnnemi(i), jeu.get_posEnnemi_actuel(i));
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
    // cout << tailleEtage.x << "   " << tailleEtage.y << endl;
    window.draw(sprBG);

    // afficher le cadre
    sprdeco.setTexture(texdecoration[0]);
}

void IHM::afficherdeco()
{
    if (jeu.tous_mort())
    {
        Vect tailleEtage = jeu.get_tailleEtagact();
        sprdeco.setScale(5.0f, 5.0f);

        sprdeco.setTexture(texdecoration[1]);
        sprdeco.setTextureRect(IntRect(0, 0, 16, 16));

        // precedent
        sprdeco.setPosition(centrer().x + tailleEtage.x / 2, centrer().y + 20);
        window.draw(sprdeco);

        sprdeco.setTextureRect(IntRect(16, 0, 16, 16));
        // ouest
        sprdeco.setPosition(centrer().x + 50, centrer().y + tailleEtage.y - 50);
        window.draw(sprdeco);
        // est
        sprdeco.setPosition(centrer().x + tailleEtage.x - 50, centrer().y + tailleEtage.y - 50);
        window.draw(sprdeco);
    }

    // affichage des HP du joueur:
    sprdeco.setTexture(texdecoration[3]);
    sprdeco.setTextureRect(IntRect(0, 0, 64, 64));
    sprdeco.setScale(1.5f, 1.5f);
    int i, n = (jeu.get_JoueurHP()) / 100 + 1;
    for (i = 0; i < n; i++)
    {
        sprdeco.setPosition(30 * (i + 1), 30);
        window.draw(sprdeco);
    }
}

void IHM::afficherInventaire()
{
    if (jeu.get_statut_Inventaire())
    {
        Vect taille(600, 350);
        Vect centre((resolution.x) / 2 - taille.x / 2, (resolution.y) / 2 - taille.y / 2);

        texte.setCharacterSize(30);

        RectangleShape cadre(Vector2f(taille.x, taille.y));
        cadre.setOrigin(0, 0);
        cadre.setPosition(centre.x, centre.y);
        cadre.setFillColor(Color(128, 128, 128));
        cadre.setOutlineThickness(10);
        cadre.setOutlineColor(Color(128, 128, 128));
        window.draw(cadre);
        texte.setCharacterSize(30);

        // affichage du nombre de minerais colleté pour une mission
        texte.setCharacterSize(30);
        texte.setFillColor(Color::White);
        int i, n = jeu.get_nbMineraidispos();
        for (i = 0; i < n; i++)
        {
            Vect posm(centre.x + 50 * (i + 1) - centrer().x, centre.y - centrer().y + 50);
            texte.setPosition(centre.x + 50 * (i + 1), centre.y + 40);
            texte.setString(to_string(jeu.get_nbminerai_Inventaire((type_Minerai)i)));
            afficherMinerai((type_Minerai)i, posm, 0);
            window.draw(texte);
        }

        // afficher le nb d'ennemis mort
        texte.setCharacterSize(60);
        texte.setFillColor(Color::Black);
        sprdeco.setScale(4.0f, 4.0f);
        sprdeco.setTexture(texdecoration[2]);
        sprdeco.setTextureRect(IntRect(0, 0, 16, 16));
        sprdeco.setPosition(centre.x + 50 * 9, centre.y + 50);
        window.draw(sprdeco);
        texte.setPosition(centre.x + 475, centre.y + 30);
        texte.setString(to_string(jeu.nbmort_Inventaire()));
        window.draw(texte);

        texte.setCharacterSize(30);
        texte.setPosition(centre.x + 30, centre.y + 100);
        texte.setString(jeu.formuler_mission());
        window.draw(texte);

        // le nb de missions accomplies

        texte.setCharacterSize(100);
        texte.setFillColor(Color::Black);
        texte.setPosition(centre.x + 475, centre.y + 150);
        texte.setString(to_string(jeu.get_nbmission_accomplie()));
        window.draw(texte);
    }
}

void IHM::afficherdemarrage()
{
    if (!jeu.get_start())
    {

        window.clear(sf::Color(50, 50, 50));

        texte.setFillColor(sf::Color(0, 255, 255));
        texte.setCharacterSize(100);
        texte.setString("Depth Delve");

        texte.setPosition(window.getSize().x / 2.0f - texte.getLocalBounds().width / 2.0f,
                          100);

        sf::RectangleShape borduretitre(sf::Vector2f(texte.getLocalBounds().width + 20, texte.getLocalBounds().height + 20));
        borduretitre.setFillColor(sf::Color::Transparent);
        borduretitre.setOutlineThickness(5);
        borduretitre.setOutlineColor(sf::Color::White);
        borduretitre.setPosition(texte.getPosition().x - 10, texte.getPosition().y - 10);

        window.draw(borduretitre);
        window.draw(texte);

        texte.setFillColor(Color::Red);
        texte.setCharacterSize(40);
        texte.setString("Appuyez sur la touche Entrée pour jouer");

        texte.setPosition(window.getSize().x / 2.0f - texte.getLocalBounds().width / 2.0f,
                          300);

        RectangleShape bordure(Vector2f(texte.getLocalBounds().width + 20, texte.getLocalBounds().height + 20));
        bordure.setFillColor(Color::Transparent);
        bordure.setOutlineThickness(5);
        bordure.setOutlineColor(Color::White);
        bordure.setPosition(texte.getPosition().x - 10, texte.getPosition().y - 10);

        window.draw(bordure);
        window.draw(texte);

        texte.setFillColor(Color::Green);
        texte.setCharacterSize(30);
        texte.setString("Appuyez sur la touche C pour charger la dernière partie");

        texte.setPosition(window.getSize().x / 2.0f - texte.getLocalBounds().width / 2.0f,
                          400);

        RectangleShape bordure2(Vector2f(texte.getLocalBounds().width + 20, texte.getLocalBounds().height + 20));
        bordure2.setFillColor(Color::Transparent);
        bordure2.setOutlineThickness(5);
        bordure2.setOutlineColor(Color::White);
        bordure2.setPosition(texte.getPosition().x - 10, texte.getPosition().y - 10);

        window.draw(bordure2);
        window.draw(texte);

        sf::RectangleShape line(sf::Vector2f(window.getSize().x - 100, 3));
        line.setFillColor(Color::White);
        line.setPosition(50, 250);
        window.draw(line);

        line.setPosition(50, 350);
        window.draw(line);

        window.display();
    }
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

        jeu.mouvementEnnemi();

        window.clear(Color::Black);
        afficherBG();
        afficherdeco();
        afficherMinerais();
        afficherEnnemis();
        afficherJoueur();
        afficherInventaire();
        afficherdemarrage();

        window.display();
    }
}
