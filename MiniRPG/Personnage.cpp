#include "Personnage.h"

using namespace std;

///Constructeur utilisé pour le joueur
Personnage::Personnage(string nom, bool estMasculin) : m_nom(nom), m_estMasculin(estMasculin), m_pvMax(100), m_pv(100), m_energieMax(100),
    m_energie(100), m_attaque(15), m_defense(5), m_exp(0), m_argent(0)
{

}

///Constructeur utilisé pour les adversaires de l'introduction
Personnage::Personnage(string nom,int attaque, string nomArme, int degatArme, int effortArme, bool armeEstMasculin, int exp, int argent, bool estMasculin, int effet, int degatEffet) : m_nom(nom), m_estMasculin(estMasculin), m_pvMax(100), m_pv(100),
    m_energieMax(100), m_energie(100), m_attaque(attaque), m_defense(5), m_arme(nomArme,degatArme,effortArme,armeEstMasculin, effet, degatEffet), m_exp(exp), m_argent(argent)
{

}

///Constructeur utilisé pour les ennemis
Personnage::Personnage(string nom,int pv,int energie,int attaque,int defense, string nomArme, int degatArme, int effortArme, bool armeEstMasculin, int exp, int argent, bool estMasculin, int effet, int degatEffet) : m_nom(nom), m_estMasculin(estMasculin), m_pvMax(pv), m_pv(pv),
    m_energieMax(energie), m_energie(energie), m_attaque(attaque), m_defense(defense), m_arme(nomArme,degatArme,effortArme,armeEstMasculin, effet, degatEffet), m_exp(exp), m_argent(argent)
{

}

///Récupère les informations de dégât de l'attaquant ainsi que les possibles effets
void Personnage::attaque(Personnage &cible,bool estJoueur)
{
    int degats = m_attaque + m_arme.getDegat();

    finLigne(500);

    degats += ajouteEffet(m_arme);

    if(!estJoueur)
    {
        phrase(accorde("Le ","La ",cible.estMasculin()));
    }

    cible.recoitDegat(degats);

    m_energie -= 10 + m_arme.getEffort();

    // Bloque l'energie négative
    if(m_energie < 0)
    {
        m_energie = 0;
    }
}

///Actualise la santé en fonction des dégâts reçus
void Personnage::recoitDegat(int degat)
{
    srand(time(0));

    int variationDegat;

    if(degat != 0)
    {
        variationDegat = rand() % (degat/5);

        variationDegat -= degat/10;

        degat += variationDegat;
    }

    degat -= m_defense;

    if(degat <= 0)
    {
        phrase(m_nom + " ne s'appercoit pas qu'" + accorde("il","elle",m_estMasculin) + " a \x82t\x82 attaqu\x82" + accorde("","e",m_estMasculin) + ".");

        finLigne(500);
    }
    else
    {
        m_pv -= degat;

        phrase(m_nom);
        phrase(" recoit ");
        nombre(degat);
        phrase(" points de d\x82g\x83t.");
        finLigne(500);

        // Bloque les pv négatifs
        if(m_pv < 0)
        {
            m_pv = 0;
        }
    }
}

///Récupère le nom du personnage
string Personnage::getNom() const
{
    return m_nom;
}

///Récupère l'attaque du personnage
int Personnage::getAttaque() const
{
    return m_attaque;
}

///Récupère la défense du personnage
int Personnage::getDefense() const
{
    return m_defense;
}

///Récupère l'énergie du personnage
int Personnage::getEnergie() const
{
    return m_energie;
}

///Récupère le sexe du personnage
bool Personnage::estMasculin() const
{
    return m_estMasculin;
}

///Renvoie 'faux' si le personnage a 0 de santé ou moins
bool Personnage::estVivant() const
{
    return m_pv > 0;
}

///Affiche le nom du personnage avant la phrase qu'il dit
void Personnage::dit(string mots) const
{
    phrase(m_nom + " : ");
    finLigne(250);
    phrase(mots);
}

///Récupère la santé actuelle du personnage
int Personnage::getPv() const
{
    return m_pv;
}

///Récupère la santé maximum du personnage
int Personnage::getPvMax() const
{
    return m_pvMax;
}

///Récupère l'énergie actuelle du personnage
int Personnage::getEnergieMax() const
{
    return m_energieMax;
}

///Récupère l'énergie maximum du personnage
string Personnage::getNomArme() const
{
    return m_arme.getNom();
}

///Récupère les dégâts de l'arme du personnage
int Personnage::getDegatArme() const
{
    return m_arme.getDegat();
}

///Récupère l'énergie nécéssaire à l'utilisation de l'arme du personnage
int Personnage::getEffortArme() const
{
    return m_arme.getEffort();
}

///Récupère les dégâts suplémentaire de l'effet de l'arme du personnage
int Personnage::getDegatEffet() const
{
    return m_arme.getDegatEffet();
}

///Récupère l'effet de l'arme du personnage
int Personnage::getEffet() const
{
    return m_arme.getEffet();
}

///Récupère l'expérience du personnage
int Personnage::getExp() const
{
    return m_exp;
}

///Récupère l'argent du personnage
int Personnage::getArgent() const
{
    return m_argent;
}
