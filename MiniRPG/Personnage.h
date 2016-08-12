#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Fonction.h"

class Personnage
{
    public :
        Personnage(std::string nom, bool estMasculin);
        Personnage(std::string nom,int attaque, std::string nomArme, int degatArme, int energieArme, bool armeEstMasculin,int exp, int argent, bool estMasculin,int effet = -1,int degatEffet = 0);
        Personnage(std::string nom,int pv,int energie,int attaque,int defense, std::string nomArme, int degatArme, int energieArme, bool armeEstMasculin, int exp, int argent, bool estMasculin,int effet = -1,int degatEffet = 0);
        void attaque(Personnage &cible,bool estJoueur = false);
        void recoitDegat(int degat);
        std::string getNom() const;
        int  getAttaque() const;
        int  getDefense() const;
        int  getEnergie() const;
        bool estMasculin() const;
        bool estVivant() const;
        void dit(std::string phrase) const;
        int  getPv() const;
        int  getPvMax() const;
        int  getEnergieMax() const;
        std::string getNomArme() const;
        int  getDegatArme() const;
        int  getEffortArme() const;
        int  getDegatEffet() const;
        int  getEffet() const;
        int  getExp() const;
        int  getArgent() const;

    protected :
        std::string m_nom;
        bool m_estMasculin;
        int  m_pvMax;
        int  m_pv;
        int  m_energieMax;
        int  m_energie;
        int  m_attaque;
        int  m_defense;
        int  m_exp;
        int  m_argent;
        Arme m_arme;
};

#endif
