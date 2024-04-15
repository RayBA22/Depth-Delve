#include "Jeu.h"

Jeu::Jeu() : joueur(500, 500)
{
    start = false;
    quitter = false;
}

bool Jeu::get_start() const
{
    return start;
}

type_Minerai Jeu::get_idMinerai(int i) const
{

    return mine.get_idMinerai_actuel(i);
}

bool Jeu::est_detruit_Minerai(int i) const
{
    return mine.est_detruit_Minerai(i);
}
Vect Jeu::get_posMinerai_actuel(int i) const
{

    return mine.get_posMinerai_actuel(i);
}

int Jeu::get_MineraiHP_actuel(int i) const
{

    return mine.get_mineraiHP_actuel(i);
}

void Jeu::se_detruit_Minerai(int deg, int i)
{

    mine.se_detruit_Minerai(deg, i);
}

int Jeu::get_nbMineraidispos() const
{
    return 6;
}

Vect Jeu::get_tailleEtagact() const
{

    return mine.get_tailleEtage_actuel();
}

unsigned int Jeu::get_nbMinerai_actuel() const
{
    return mine.get_nbMinerai_actuel();
}

type_Etage Jeu::get_typeEtage_actuel() const
{

    return mine.get_typeEtage_actuel();
}

Vect Jeu::get_Joueurpos() const
{
    return joueur.get_position();
}



int Jeu::get_JoueurHP() const
{
    return joueur.get_HP();
}




void Jeu::ajouter_Minerai_Inventaire(type_Minerai type)
{
    inventaire.ajouter_Minerai(type);
}

string Jeu::formuler_mission()
{
    return inventaire.formuler_mission();
}

bool Jeu::tous_mort(){
    return mine.tous_mort();    
}


orientation Jeu::detecterpassage() const
{

    // corriger ce truc
    Vect posj = get_Joueurpos(), taille = get_tailleEtagact();
    if ((posj.x < 100) && (posj.y > taille.y - 100))
    {
        return EST;
    }
    if ((posj.x > taille.x - 100) && (posj.y > taille.y - 100))
    {
        return OUEST;
    }
    if (((posj.x - taille.x / 2) * (posj.x - taille.x / 2) < 10000) && (posj.y < 100))
    {
        return PRECED;
    }
    return NONE;
}

void Jeu::changerEtage()
{
    if (mine.tous_mort())
    {
        orientation ori = detecterpassage();

        switch (ori)
        {
        case EST:
            mine.allerEst();
            joueur.set_posJoueur(50, get_tailleEtagact().y - 50);

            break;
        case OUEST:
            mine.allerOuest();
            joueur.set_posJoueur(get_tailleEtagact().x - 50, get_tailleEtagact().y - 50);
            break;

        case PRECED:
            mine.allerPrecedent();
            joueur.set_posJoueur(get_tailleEtagact().x / 2, 0);
            break;

        default:
            break;
        }
    }
}

bool Jeu::get_statut_Inventaire() const
{
    return inventaire.get_statut();
}
int Jeu::get_nbminerai_Inventaire(int i) const
{
    return inventaire.get_nbMinerai(i);
}
int Jeu::nbmort_Inventaire() const
{
    return inventaire.get_nbmort();
}

unsigned int Jeu::get_frame_Joueur() const
{
    return animJoueur.get_frame_actuelle();
}

direction Jeu::get_direction_Joueur() const
{
    return animJoueur.get_direction_actuelle();
}

action Jeu::get_action_Joueur() const
{

    return joueur.get_action();
}

bool Jeu::joueur_estmort(){
    return joueur.joueur_mort();
}


void Jeu::repos_joueur()
{

    animJoueur.repos_joueur();
}

void Jeu::piocher(bool (Personnage::*fonc)(Vect))
{
    if ((get_action_Joueur() == Piocher))
    {
        Vect posj = get_Joueurpos();
        int i, n = get_nbMinerai_actuel();
        for (i = 0; i < n; i++)
        {
            Vect posm = get_posMinerai_actuel(i);
            if ((joueur.*fonc)(posm) && !mine.est_detruit_Minerai(i))
            {

                mine.se_detruit_Minerai(joueur.get_dmgJoueur(), i);
                if (mine.est_detruit_Minerai(i))
                    inventaire.ajouter_Minerai(mine.get_idMinerai_actuel(i));
            }
        }
        n = get_nbEnnemi_actuel();
        for (i = 0; i < n; i++)
        {
            Vect pose = get_posEnnemi_actuel(i);
            if ((joueur.*fonc)(pose) && !mine.est_mort(i))
            {

                mine.prenddmg(joueur.get_dmgJoueur(), i);
                if (mine.est_mort(i))
                    inventaire.ajouter_Ennemi();
            }
        }
    }
}

void Jeu::mouvement_Joueur(int mouv)
{

    action actJoueur = get_action_Joueur();

    switch (mouv)
    {

    case 25:
        joueur.deplacement_haut();
        animJoueur.animer_mouvement_joueur(haut, actJoueur);
        piocher(&Personnage::detect_haut);
        break;

    case 16:
        joueur.deplacement_gauche();
        animJoueur.animer_mouvement_joueur(gauche, actJoueur);

        piocher(&Personnage::detect_gauche);
        break;

    case 18:
        joueur.deplacement_bas(get_tailleEtagact().y);
        animJoueur.animer_mouvement_joueur(bas, actJoueur);

        piocher(&Personnage::detect_bas);
        break;
    case 3:
        joueur.deplacement_droite(get_tailleEtagact().x);
        animJoueur.animer_mouvement_joueur(droite, actJoueur);
        piocher(&Personnage::detect_droite);
        break;

    case 37:
        joueur.changer_action();
        break;

    case 4:
        changerEtage();
        // cout << mine.noeudActuel->etage.get_profondeur() << endl;
        break;

    case 36:
        inventaire.changer_statut();

    case 58:

        start = true;
        break;

    case 2:
        gestion_sauvegarde();
        break;
    
    case 10:
        quitter = true;
        break;

    default:

        break;
    }
}

Vect Jeu::get_posEnnemi_actuel(int i) const
{
    return mine.get_posEnnemi_actuel(i);
}
unsigned int Jeu::get_nbEnnemi_actuel() const
{
    return mine.get_nbEnnemi_actuel();
}

type_Ennemi Jeu::get_idEnnemi(int i) const
{
    return mine.get_idEnnemi_actuel(i);
}

bool Jeu::est_mort(int i) const
{
    return mine.est_mort(i);
}

void Jeu::mouvementEnnemi()
{
    Vect posj = get_Joueurpos();
    int i, n = get_nbEnnemi_actuel();
    for (i = 0; i < n; i++)
    {
        mine.suivre(i, posj);
        // cout << mine.detecter(1, posj) << " / "<< posj.x << "  " << posj.y << "  |  "   << mine.get_posEnnemi_actuel(i).x << "   " << mine.get_posEnnemi_actuel(i).y << endl;
        if (mine.toucher(i, posj))
        {
            joueur.prenddmg(1);
            reset();
            //cout << joueur.get_HP() << endl;
        }
    }
}

int Jeu::get_nbmission_accomplie() const
{
    return inventaire.get_nbmission_accomplie();
}

void Jeu::sauver()
{

    inventaire.sauver(joueur.get_HP());
}

void Jeu::charger()
{

    joueur.set_HPJoueur(inventaire.charger());
}

void Jeu::gestion_sauvegarde()
{
    if (start)
        sauver();
    else
        charger();
}

void Jeu::reset()
{
    if (joueur.joueur_mort())
    {
        joueur.reset();
        mine.resetArbre();
        inventaire.reset();
        inventaire.sauver(0);
    }
}


bool Jeu::Quitter()const{
    return quitter;
}