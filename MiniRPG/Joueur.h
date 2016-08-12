#ifndef JOUEUR_H
#define JOUEUR_H

#include "Ennemi.h"

class Joueur : public Personnage
{
    public:
        Joueur(std::string nom, bool estMasculin);
        void attaque(Ennemi &cible);
        void recoitRecompense(int exp,int argent,Arme dropArme,int dropRate);
        void medite();
        int  getLvl() const;
        void afficheStat() const;
        void afficheArme() const;
        void nouvelleArme(std::string nom,int degat,int energie,bool estMasculin,int effet = -1,int degatEffet = 0);
        void setArme(std::string nom,int degat,int energie,bool estMasculin,int effet = -1,int degatEffet = 0);
        void setArgent(int argent);
        void setEnergie(int energie,bool recue);
        void setPv(int pv);
        void setLvl(int lvl);
        void returnVanilla();

    private :
        int m_lvl;
};

#endif
