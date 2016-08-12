#include "Arme.h"

using namespace std;

///Constructeur pour sans arme
Arme::Arme() : m_nom("Aucune"), m_degat(0), m_effort(0), m_effet(-1),m_degatEffet(0)
{

}

///Constructeur des armes
Arme::Arme(string nom,int degat,int effort, bool estMasculin, int effet, int degatEffet) : m_nom(nom), m_estMasculin(estMasculin), m_degat(degat), m_effort(effort), m_effet(effet), m_degatEffet(degatEffet)
{

}

///Récupère le nom de l'arme
string Arme::getNom() const
{
    return m_nom;
}

///Récupère le genre de l'arme
bool Arme::estMasculin() const
{
    return m_estMasculin;
}

///Récupère les dégâts de l'arme
int Arme::getDegat() const
{
    return m_degat;
}

///Récupère l'énergie nécessaire pour utiliser l'arme
int Arme::getEffort() const
{
    return m_effort;
}

///Récupère l'effet de l'arme
int Arme::getEffet() const
{
    return m_effet;
}

///Récupère les dégâts de l'effet de l'arme
int Arme::getDegatEffet() const
{
    return m_degatEffet;
}

///Modifie le nom de l'arme
void Arme::setNom(string nom)
{
    m_nom = nom;
}

///Modifie les dégâts de l'arme
void Arme::setDegat(int degat)
{
    m_degat = degat;
}

///Modifie l'énergie nécessaire pour utiliser l'arme
void Arme::setEffort(int effort)
{
    m_effort = effort;
}

///Modifie le genre de l'arme
void Arme::setGenre(bool estMasculin)
{
    m_estMasculin = estMasculin;
}

///Modifie l'effet de l'arme
void Arme::setEffet(int effet)
{
    m_effet = effet;
}

///Modifie les dégâts de l'effet de l'arme
void Arme::setDegatEffet(int degatEffet)
{
    m_degatEffet = degatEffet;
}
