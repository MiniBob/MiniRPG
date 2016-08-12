#include "Ennemi.h"

using namespace std;

///Constructeur des ennemis de l'intro
Ennemi::Ennemi(string nom,int attaque, string nomArme, int degatArme, int effortArme, int exp, int argent, bool armeEstMasculin, bool estMasculin, int effet, int degatEffet, string nomDropArme, int degatDropArme, int effortDropArme, bool dropArmeEstMasculin, int effetDrop, int degatEffetDrop, int dropRate) : Personnage(nom,attaque, nomArme , degatArme, effortArme, armeEstMasculin, exp, argent, estMasculin, effet, degatEffet), m_dropArme(nomDropArme, degatDropArme, effortDropArme, dropArmeEstMasculin, effetDrop, degatEffetDrop), m_dropRate(dropRate)
{

}

///Constructeur des ennemis
Ennemi::Ennemi(string nom,int pv,int energie,int attaque,int defense, string nomArme, int degatArme, int effortArme, int exp, int argent, bool armeEstMasculin, bool estMasculin, int effet, int degatEffet, string nomDropArme, int degatDropArme, int effortDropArme, bool dropArmeEstMasculin, int effetDrop, int degatEffetDrop, int dropRate) : Personnage(nom, pv, energie, attaque, defense, nomArme , degatArme, effortArme, armeEstMasculin, exp , argent, estMasculin, effet, degatEffet), m_dropArme(nomDropArme, degatDropArme, effortDropArme, dropArmeEstMasculin, effetDrop, degatEffetDrop), m_dropRate(dropRate)
{

}

///Récupère les dégâts de l'ennemi
void Ennemi::attaque(Personnage &cible)
{
    cout << endl;

    if(m_energie < m_arme.getEffort())
    {
        phrase(accorde("Le ","La ",m_estMasculin) + m_nom + " est tellement fatigu\x82" + accorde("","e",m_estMasculin) + " qu'" + accorde("il","elle",m_estMasculin) + " n'arrive pas \x85 utiliser " + accorde("son ","sa ",m_arme.estMasculin()) + m_arme.getNom() + ".");
    }
    else
    {
        phrase(accorde("Le ","La ",m_estMasculin) + m_nom + " attaque " + cible.getNom());

        if(m_arme.getNom() != "Aucune")
        {
            phrase(" avec " + accorde("son ","sa ",m_arme.estMasculin()) + m_arme.getNom());
        }

        phrase(".");

        Personnage::attaque(cible,true);
    }

    finLigne(300);

    if(!cible.estVivant())
    {
        cout << endl;
        phrase(cible.getNom() + " est mort" + accorde("","e",cible.estMasculin()) + "...");
        finLigne(500);
    }
}

///L'ennemi récupère de la santé et de l'énergie
void Ennemi::medite()
{
    m_energie += m_energieMax/3;
    m_pv += m_pvMax/4;

    if(m_energie > m_energieMax)
    {
        m_energie = m_energieMax;
    }

    if(m_pv > m_pvMax)
    {
        m_pv = m_pvMax;
    }

    cout << endl;
    phrase(accorde("Le ","La ",m_estMasculin) + m_nom + " se repose et r\x82\acup\x8Are de la vie et de l'\x82nergie.");
    finLigne(500);
}

///Récupère l'arme que l'ennemi laisse
Arme Ennemi::dropArme() const
{
    return m_dropArme;
}

///Renvoie le pourcentage de réussite du drop
int Ennemi::getDropRate() const
{
    return m_dropRate;
}
